#include "port/sdl/sdl_sound.h"
#include "common.h"
#include "sf33rd/Source/Game/GD3rd.h"

#include <SDL3/SDL.h>

#include <libavcodec/avcodec.h>
#include <libavutil/avutil.h>
#include <libavutil/frame.h>
#include <libswresample/swresample.h>

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SAMPLE_RATE 48000
#define N_CHANNELS 2
#define BYTES_PER_SAMPLE 2
#define MIN_QUEUED_DATA_MS 200
#define MIN_QUEUED_DATA (int)((float)SAMPLE_RATE * MIN_QUEUED_DATA_MS / 1000 * N_CHANNELS * BYTES_PER_SAMPLE)
#define TRACKS_MAX 10

typedef struct ADXDecoderPipeline {
    AVCodecContext* context;
    AVCodecParserContext* parser_context;
    SwrContext* swr;
    AVPacket* packet;
    AVFrame* frame;
} ADXDecoderPipeline;

typedef struct ADXTrack {
    int size;
    uint8_t* data;
    bool should_free_data_after_use;
    int used_bytes;
    ADXDecoderPipeline pipeline;
} ADXTrack;

static SDL_AudioStream* stream = NULL;
static ADXTrack tracks[TRACKS_MAX] = { 0 };
static int num_tracks = 0;
static int first_track_index = 0;
static bool has_tracks = false;

static bool stream_needs_data() {
    return SDL_GetAudioStreamQueued(stream) < MIN_QUEUED_DATA;
}

static bool stream_is_empty() {
    return SDL_GetAudioStreamQueued(stream) <= 0;
}

static void pipeline_init(ADXDecoderPipeline* pipeline) {
    const AVCodec* codec = avcodec_find_decoder(AV_CODEC_ID_ADPCM_ADX);
    pipeline->context = avcodec_alloc_context3(codec);
    avcodec_open2(pipeline->context, codec, NULL);
    pipeline->parser_context = av_parser_init(codec->id);

    const AVChannelLayout ch_layout = AV_CHANNEL_LAYOUT_STEREO;
    swr_alloc_set_opts2(&pipeline->swr,
                        &ch_layout,
                        AV_SAMPLE_FMT_S16,
                        SAMPLE_RATE,
                        &ch_layout,
                        AV_SAMPLE_FMT_S16P,
                        SAMPLE_RATE,
                        0,
                        NULL);
    swr_init(pipeline->swr);

    pipeline->packet = av_packet_alloc();
    pipeline->frame = av_frame_alloc();
}

static void pipeline_destroy(ADXDecoderPipeline* pipeline) {
    av_packet_free(&pipeline->packet);
    av_frame_free(&pipeline->frame);
    swr_free(&pipeline->swr);
    avcodec_free_context(&pipeline->context);
    av_parser_close(pipeline->parser_context);
}

static void* load_file(int file_id, int* size) {
    const unsigned int file_size = fsGetFileSize(file_id);
    // ADXF requires buff to be aligned to 64
    const size_t alignment = 64;
    // aligned_alloc requires size to be a multiple of alignment
    const size_t buff_size = (file_size + alignment - 1) / alignment * alignment;
    void* buff = aligned_alloc(alignment, buff_size);
    REQ req;
    req.fnum = file_id;
    fsOpen(&req);
    req.size = fsGetFileSize(req.fnum);
    *size = req.size;
    req.sect = fsCalSectorSize(req.size);
    fsFileReadSync(&req, req.sect, buff);
    return buff;
}

static void print_av_error(int errnum) {
    char errbuf[AV_ERROR_MAX_STRING_SIZE] = { 0 };
    av_strerror(errnum, errbuf, sizeof(errbuf));
    fprintf(stderr, "FFmpeg error: %s\n", errbuf);
}

static bool track_reached_eof(ADXTrack* track) {
    return (track->size - track->used_bytes) <= 0;
}

static void process_track(ADXTrack* track) {
    ADXDecoderPipeline* pipeline = &track->pipeline;

    while (stream_needs_data() && !track_reached_eof(track)) {
        int ret = av_parser_parse2(pipeline->parser_context,
                                   pipeline->context,
                                   &pipeline->packet->data,
                                   &pipeline->packet->size,
                                   track->data + track->used_bytes,
                                   track->size - track->used_bytes,
                                   AV_NOPTS_VALUE,
                                   AV_NOPTS_VALUE,
                                   0);

        if (ret < 0) {
            print_av_error(ret);
            break;
        }

        track->used_bytes += ret;

        if (pipeline->packet->size > 0) {
            // Send parsed packet to decoder
            ret = avcodec_send_packet(pipeline->context, pipeline->packet);

            if (ret < 0) {
                print_av_error(ret);
                break;
            }

            // Receive all available frames
            while (ret >= 0) {
                ret = avcodec_receive_frame(pipeline->context, pipeline->frame);

                if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
                    break;
                else if (ret < 0) {
                    print_av_error(ret);
                    // goto cleanup;
                }

                int out_channels = pipeline->frame->ch_layout.nb_channels;
                int out_samples = pipeline->frame->nb_samples;

                // Allocate buffer for interleaved samples
                uint8_t* out_buf = NULL;
                int out_linesize = 0;

                av_samples_alloc(&out_buf, &out_linesize, out_channels, out_samples, AV_SAMPLE_FMT_S16, 0);

                // Convert planar → interleaved
                int samples_converted = swr_convert(pipeline->swr,
                                                    &out_buf,
                                                    out_samples, // dst
                                                    (const uint8_t**)pipeline->frame->data,
                                                    out_samples); // src

                int out_size =
                    av_samples_get_buffer_size(&out_linesize, out_channels, samples_converted, AV_SAMPLE_FMT_S16, 1);

                SDL_PutAudioStreamData(stream, out_buf, out_size);
                av_freep(&out_buf);
            }
        }
    }
}

static void track_init(ADXTrack* track, int file_id, void* buf) {
    if (file_id == -1 && buf == NULL) {
        fatal_error("One of file_id or buf must be valid.");
    }

    if (file_id != -1) {
        track->data = load_file(file_id, &track->size);
        track->should_free_data_after_use = true;
    } else {
        track->data = buf;
        track->size = 391168; // TODO: remove this hardcode
        track->should_free_data_after_use = false;
    }

    track->used_bytes = 0;
    pipeline_init(&track->pipeline);
    process_track(track); // Feed first batch of data to the stream
}

static void track_destroy(ADXTrack* track) {
    pipeline_destroy(&track->pipeline);

    if (track->should_free_data_after_use) {
        free(track->data);
    }

    SDL_zerop(track);
}

static ADXTrack* alloc_track() {
    const int index = (first_track_index + num_tracks) % TRACKS_MAX;
    num_tracks += 1;
    has_tracks = true;
    return &tracks[index];
}

void SDLSound_ProcessTracks() {
    const int first_track_index_old = first_track_index;
    const int num_tracks_old = num_tracks;

    for (int i = 0; i < num_tracks_old; i++) {
        const int j = (first_track_index_old + i) % TRACKS_MAX;
        ADXTrack* track = &tracks[j];
        process_track(track);

        if (!track_reached_eof(track)) {
            // No need to continue if the current track is not exhausted yet
            break;
        }

        track_destroy(track);
        num_tracks -= 1;

        if (num_tracks > 0) {
            first_track_index += 1;
        } else {
            first_track_index = 0;
        }
    }
}

void SDLSound_Init() {
    const SDL_AudioSpec spec = { .format = SDL_AUDIO_S16, .channels = 2, .freq = SAMPLE_RATE };
    stream = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &spec, NULL, NULL);
}

void SDLSound_Exit() {
    not_implemented(__func__);
}

void SDLSound_Stop() {
    SDL_ClearAudioStream(stream);
    SDLSound_Pause(true);

    for (int i = 0; i < num_tracks; i++) {
        const int j = (first_track_index + i) % TRACKS_MAX;
        track_destroy(&tracks[j]);
    }

    num_tracks = 0;
    first_track_index = 0;
    has_tracks = false;
}

int SDLSound_IsPaused() {
    return SDL_AudioStreamDevicePaused(stream);
}

void SDLSound_Pause(int pause) {
    if (pause) {
        SDL_PauseAudioStreamDevice(stream);
    } else {
        SDL_ResumeAudioStreamDevice(stream);
    }
}

void SDLSound_StartMem(void* buf) {
    ADXTrack* track = alloc_track();
    track_init(track, -1, buf);
}

int SDLSound_GetNumFiles() {
    return num_tracks;
}

void SDLSound_EntryAfs(int file_id) {
    printf("🔴 entry afs %d\n", file_id);
    ADXTrack* track = alloc_track();
    track_init(track, file_id, NULL);
}

void SDLSound_StartSeamless() {
    SDLSound_Pause(false);
}

void SDLSound_ResetEntry() {
    // ResetEntry is always called after Stop, so we don't need to do anything here
}

void SDLSound_StartAfs(int file_id) {
    ADXTrack* track = alloc_track();
    track_init(track, file_id, NULL);
}

void SDLSound_SetOutVol(int volume) {
    // Convert volume (dB * 10) to linear gain
    const float gain = powf(10.0f, volume / 200.0f);
    SDL_SetAudioStreamGain(stream, gain);
}

int SDLSound_GetStat() {
    if (!has_tracks) {
        return 0; // ADXT_STAT_STOP
    }

    if (stream_is_empty()) {
        return 5; // ADXT_STAT_PLAYEND
    } else {
        if (SDLSound_IsPaused()) {
            return 0; // ADXT_STAT_STOP
        } else {
            return 3; // ADXT_STAT_PLAYING
        }
    }
}
