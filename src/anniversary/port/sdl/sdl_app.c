#include "port/sdl/sdl_app.h"
#include "common.h"
#include "port/sdk_threads.h"
#include "port/sdl/sdl_game_renderer.h"
#include "port/sdl/sdl_message_renderer.h"
#include "port/sdl/sdl_pad.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "sf33rd/Source/Game/main.h"

#include <SDL3/SDL.h>
#include <math.h>

#define FRAME_TIMES_MAX 120

// We can't include cri_mw.h because it leads to conflicts
// with SDL types
int ADXPS2_ExecVint(int mode);

static const char *app_name = "Street Fighter III: 3rd Strike";
static const float display_target_ratio = 4.0 / 3.0;
static const int window_default_width = 640;
static const int window_default_height = (int)(window_default_width / display_target_ratio);
static const int target_fps = 60;
static const float target_frame_time_ns = 1000000000.0 / target_fps;

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

static Uint64 frame_start = 0;
static Uint64 frame_times[FRAME_TIMES_MAX];
static int frame_times_index = 0;
static Uint64 frame_time_remainder = 0;
static double fps = 0;
static Uint64 frame_counter = 0;
static Uint64 display_refresh_period = 0;

int SDLApp_Init() {
    SDL_SetAppMetadata(app_name, "0.1", NULL);
    SDL_SetHint(SDL_HINT_VIDEO_WAYLAND_PREFER_LIBDECOR, "1");

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

    // Initialize message renderer
    SDLMessageRenderer_Initialize(renderer);

    // Initialize game renderer
    SDLGameRenderer_Init(renderer);

    // Query display
    const SDL_DisplayID display_id = SDL_GetDisplayForWindow(window);
    const SDL_DisplayMode *display_mode = SDL_GetCurrentDisplayMode(display_id);

    if (display_mode->refresh_rate == 0) {
        SDL_Log("Displays with unspecified refresh rate are not supported yet");
        return 1;
    }

    display_refresh_period = 1000000000.0 / display_mode->refresh_rate;

    // Initialize pads
    SDLPad_Init();

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

        case SDL_EVENT_KEY_DOWN:
        case SDL_EVENT_KEY_UP:
            SDLPad_HandleKeyboardEvent(&event.key);
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

    // Clear window
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderClear(renderer);

    SDLMessageRenderer_BeginFrame();
    SDLGameRenderer_BeginFrame();
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
    SDLGameRenderer_RenderFrame();

    SDL_SetRenderTarget(renderer, NULL);

    // Render window background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black bars
    SDL_RenderClear(renderer);

    int win_w, win_h;
    SDL_GetWindowSize(window, &win_w, &win_h);
    const SDL_FRect dst_rect = get_letterbox_rect(win_w, win_h);

    // Render game canvas
    SDL_RenderTexture(renderer, cps3_canvas, NULL, &dst_rect);

    // Render message canvas
    SDL_RenderTexture(renderer, message_canvas, NULL, &dst_rect);

    // Render FPS
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDebugTextFormat(renderer, 8, 8, "FPS: %f", fps);

    const Uint64 frame_time_budget = (Uint64)fmaxf(0.0f, target_frame_time_ns + (float)frame_time_remainder);
    Uint64 frame_time = SDL_GetTicksNS() - frame_start;

    if (frame_time < frame_time_budget) {
        Uint64 sleep_time = (frame_time_budget - frame_time) / display_refresh_period * display_refresh_period;
        SDL_DelayNS(sleep_time);
    }

    SDL_RenderPresent(renderer);

    // Measure
    frame_counter += 1;
    frame_time = SDL_GetTicksNS() - frame_start;
    frame_time_remainder = (Uint64)fmaxf(0.0f, target_frame_time_ns - (float)frame_time);
    add_frame_time(frame_time);
    update_fps();

    // Cleanup
    SDLGameRenderer_EndFrame();

    begin_interrupt();
    ADXPS2_ExecVint(0);
    end_interrupt();
}
