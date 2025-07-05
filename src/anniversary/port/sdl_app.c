#include "port/sdl_app.h"
#include "common.h"
#include "port/sdk_threads.h"
#include "port/sdl_pad.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "sf33rd/Source/Game/main.h"

#include <libgraph.h>

#include <SDL3/SDL.h>

#define FRAME_TIMES_MAX 120

// We can't include cri_mw.h because it leads to conflicts
// with SDL types
int ADXPS2_ExecVint(int mode);

static const char *app_name = "Street Fighter III: 3rd Strike";
static const int canvas_width = 512;
static const int canvas_height = 448;
static const float display_target_ratio = 4.0 / 3.0;
static const int window_default_width = 640;
static const int window_default_height = (int)(window_default_width / display_target_ratio);
static const int target_fps = 60;
static const float target_frame_time_ns = 1000000000.0 / target_fps;

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static SDL_Texture *canvas = NULL;

static Uint64 frame_start = 0;
static Uint64 frame_times[FRAME_TIMES_MAX];
static int frame_times_index = 0;
static Uint64 frame_time_remainder = 0;
static double fps = 0;
static Uint64 frame_counter = 0;
static Uint64 display_refresh_period = 0;

static const SDL_Color knjsub_palette_colors[4] = {
    { .r = 255, .g = 255, .b = 255, .a = 0 },
    { .r = 255, .g = 255, .b = 255, .a = 0 },
    { .r = 255, .g = 255, .b = 255, .a = 0 },
    { .r = 255, .g = 255, .b = 255, .a = 255 },
};

static SDL_Texture *knjsub_texture = NULL;
static SDL_Palette *knjsub_palette = NULL;
static int knjsub_palette_count = 0;

int SDLApp_Init() {
    SDL_SetAppMetadata(app_name, "0.1", NULL);

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return 1;
    }

    if (!SDL_CreateWindowAndRenderer(
            app_name, window_default_width, window_default_height, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return 1;
    }

    if (!SDL_SetRenderVSync(renderer, 1)) {
        SDL_Log("Couldn't enable VSync: %s", SDL_GetError());
        return 1;
    }

    // Initialize canvas
    canvas =
        SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, canvas_width, canvas_height);
    SDL_SetTextureScaleMode(canvas, SDL_SCALEMODE_NEAREST);

    // Initialize knjsub palette
    knjsub_palette = SDL_CreatePalette(4);
    SDL_SetPaletteColors(knjsub_palette, knjsub_palette_colors, 0, 4);

    // // Query display
    const SDL_DisplayID display_id = SDL_GetDisplayForWindow(window);
    const SDL_DisplayMode *display_mode = SDL_GetCurrentDisplayMode(display_id);

    if ((display_mode->refresh_rate == 0)) {
        SDL_Log("Displays with unspecified refresh rate are not supported yet");
        return 1;
    }

    display_refresh_period = 1000000000.0 / display_mode->refresh_rate;

    return 0;
}

void SDLApp_Quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int SDLApp_PollEvents() {
    SDL_Event event;
    int continue_running = 1;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_EVENT_GAMEPAD_ADDED:
        case SDL_EVENT_GAMEPAD_REMOVED:
            SDLPad_HandleGamepadDeviceEvent(&event.gdevice);
            break;

        case SDL_EVENT_GAMEPAD_BUTTON_DOWN:
        case SDL_EVENT_GAMEPAD_BUTTON_UP:
            SDLPad_HandleGamepadButtonEvent(&event.gbutton);
            break;

        case SDL_EVENT_GAMEPAD_AXIS_MOTION:
            SDLPad_HandleGamepadAxisMotionEvent(&event.gaxis);
            break;

        case SDL_EVENT_QUIT:
            continue_running = 0;
            break;
        }
    }

    return continue_running;
}

void SDLApp_BeginFrame() {
    frame_start = SDL_GetTicksNS();

    SDL_SetRenderTarget(renderer, canvas);

    const Uint8 a = flPs2State.FrameClearColor >> 24;
    const Uint8 r = (flPs2State.FrameClearColor >> 16) & 0xFF;
    const Uint8 g = (flPs2State.FrameClearColor >> 8) & 0xFF;
    const Uint8 b = flPs2State.FrameClearColor & 0xFF;
    SDL_SetRenderDrawColor(renderer, r, g, b, a);

    SDL_RenderClear(renderer);
}

void SDLApp_CreateKnjsubTexture(int width, int height, void *pixels, int format) {
    if (knjsub_texture != NULL) {
        SDL_DestroyTexture(knjsub_texture);
    }

    SDL_Surface *surface = SDL_CreateSurfaceFrom(width, height, SDL_PIXELFORMAT_INDEX4LSB, pixels, width / 2);
    SDL_SetSurfacePalette(surface, knjsub_palette);
    knjsub_texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);

    SDL_SetTextureScaleMode(knjsub_texture, SDL_SCALEMODE_NEAREST);
    SDL_SetTextureBlendMode(knjsub_texture, SDL_BLENDMODE_BLEND);
}

static int adjust_coordinate(int coordinate, bool is_x, bool is_uv) {
    coordinate >>= 4;

    if (!is_uv) {
        const int display_size = is_x ? canvas_width : canvas_height;
        coordinate -= (4096 - display_size) / 2;
    }

    return coordinate;
}

static Uint8 scale_color_value(Uint8 value) {
    int temp = value;
    temp *= 2;

    if (temp > 0xFF) {
        temp = 0xFF;
    }

    return (Uint8)temp;
}

void SDLApp_DrawKnjsubTexture(int x0, int y0, int x1, int y1, int u0, int v0, int u1, int v1, unsigned int color) {
    x0 = adjust_coordinate(x0, true, false);
    y0 = adjust_coordinate(y0, false, false);
    x1 = adjust_coordinate(x1, true, false);
    y1 = adjust_coordinate(y1, false, false);

    u0 = adjust_coordinate(u0, true, true);
    v0 = adjust_coordinate(v0, false, true);
    u1 = adjust_coordinate(u1, true, true);
    v1 = adjust_coordinate(v1, false, true);

    SDL_FRect src_rect;
    src_rect.x = u0;
    src_rect.y = v0;
    src_rect.w = u1 - u0;
    src_rect.h = v1 - v0;

    SDL_FRect dst_rect;
    dst_rect.x = x0;
    dst_rect.y = y0;
    dst_rect.w = x1 - x0;
    dst_rect.h = y1 - y0;

    const Uint8 r = scale_color_value(color & 0xFF);
    const Uint8 g = scale_color_value((color >> 8) & 0xFF);
    const Uint8 b = scale_color_value((color >> 16) & 0xFF);
    const Uint8 a = scale_color_value(color >> 24);

    SDL_SetTextureColorMod(knjsub_texture, r, g, b);
    SDL_SetTextureAlphaMod(knjsub_texture, a);
    SDL_RenderTexture(renderer, knjsub_texture, &src_rect, &dst_rect);
}

static SDL_FRect get_letterbox_rect(int win_w, int win_h) {
    float out_w = win_w;
    float out_h = win_w / display_target_ratio;

    if (out_h > win_h) {
        out_h = win_h;
        out_w = win_h * display_target_ratio;
    }

    SDL_FRect rect;
    rect.w = out_w;
    rect.h = out_h;
    rect.x = (win_w - out_w) / 2;
    rect.y = (win_h - out_h) / 2;

    return rect;
}

static void add_frame_time(Uint64 frame_time) {
    frame_times[frame_times_index] = frame_time;
    frame_times_index += 1;
    frame_times_index %= FRAME_TIMES_MAX;
}

static void update_fps() {
    Uint64 total_frame_time = 0;

    for (int i = 0; i < FRAME_TIMES_MAX; i++) {
        total_frame_time += frame_times[i];
    }

    double average_frame_time = (double)total_frame_time / FRAME_TIMES_MAX;
    fps = 1000000000.0 / average_frame_time;
}

void SDLApp_EndFrame() {
    SDL_SetRenderTarget(renderer, NULL);

    // Render window background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black bars
    SDL_RenderClear(renderer);

    // Render game
    int win_w, win_h;
    SDL_GetWindowSize(window, &win_w, &win_h);
    const SDL_FRect dst_rect = get_letterbox_rect(win_w, win_h);
    SDL_RenderTexture(renderer, canvas, NULL, &dst_rect);

    // Render FPS
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDebugTextFormat(renderer, 8, 8, "FPS: %f", fps);

    const Uint64 frame_time_budget = target_frame_time_ns + frame_time_remainder;
    Uint64 frame_time = SDL_GetTicksNS() - frame_start;

    if (frame_time < frame_time_budget) {
        Uint64 sleep_time = (frame_time_budget - frame_time) / display_refresh_period * display_refresh_period;
        SDL_DelayNS(sleep_time);
    }

    SDL_RenderPresent(renderer);

    // Measure
    frame_counter += 1;
    frame_time = SDL_GetTicksNS() - frame_start;
    frame_time_remainder = target_frame_time_ns - frame_time;
    add_frame_time(frame_time);
    update_fps();

    begin_interrupt();
    ADXPS2_ExecVint(0);
    end_interrupt();
}
