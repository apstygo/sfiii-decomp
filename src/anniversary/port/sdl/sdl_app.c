#include "port/sdl/sdl_app.h"
#include "common.h"
#include "ini.h"
#include "port/float_clamp.h"
#include "port/sdk_threads.h"
#include "port/sdl/sdl_config.h"
#include "port/sdl/sdl_game_renderer.h"
#include "port/sdl/sdl_message_renderer.h"
#include "port/sdl/sdl_pad.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "sf33rd/Source/Game/main.h"

#include <SDL3/SDL.h>
#include <SDL3/SDL_filesystem.h>

#define FRAME_END_TIMES_MAX 120

// We can't include cri_mw.h because it leads to conflicts
// with SDL types
int ADXPS2_ExecVint(int mode);

static const char* app_name = "Street Fighter III: 3rd Strike";
static const float display_target_ratio = 4.0 / 3.0;
static const int window_default_width = 640;
static const int window_default_height = (int)(window_default_width / display_target_ratio);
static const int target_fps = 60;
static const Uint64 target_frame_time_ns = 1000000000.0 / target_fps;

static SDL_Window* window = NULL;
static SDL_Renderer* renderer = NULL;
static SDL_Texture* screen_texture = NULL;

static Uint64 frame_start = 0;
static Uint64 frame_deadline = 0;
static Uint64 frame_end_times[FRAME_END_TIMES_MAX];
static int frame_end_times_index = 0;
static bool frame_end_times_filled = false;
static double fps = 0;
static Uint64 frame_counter = 0;

static int opening_index = -1;
static bool should_save_screenshot = false;

static SDLConfig_Configuration configuration;

static SDL_Keycode keycode_from_string(const char* s) {
    return SDL_GetKeyFromName(s);
}

static SDLConfig_GamepadButton gamepad_button_from_string(const char* s) {
    if (strcmp(s, "south") == 0) return GAMEPAD_BUTTON_SOUTH;
    if (strcmp(s, "east") == 0) return GAMEPAD_BUTTON_EAST;
    if (strcmp(s, "west") == 0) return GAMEPAD_BUTTON_WEST;
    if (strcmp(s, "north") == 0) return GAMEPAD_BUTTON_NORTH;
    if (strcmp(s, "back") == 0) return GAMEPAD_BUTTON_BACK;
    if (strcmp(s, "start") == 0) return GAMEPAD_BUTTON_START;
    if (strcmp(s, "left_stick") == 0) return GAMEPAD_BUTTON_LEFT_STICK;
    if (strcmp(s, "right_stick") == 0) return GAMEPAD_BUTTON_RIGHT_STICK;
    if (strcmp(s, "left_shoulder") == 0) return GAMEPAD_BUTTON_LEFT_SHOULDER;
    if (strcmp(s, "right_shoulder") == 0) return GAMEPAD_BUTTON_RIGHT_SHOULDER;
    if (strcmp(s, "dpad_up") == 0) return GAMEPAD_BUTTON_DPAD_UP;
    if (strcmp(s, "dpad_down") == 0) return GAMEPAD_BUTTON_DPAD_DOWN;
    if (strcmp(s, "dpad_left") == 0) return GAMEPAD_BUTTON_DPAD_LEFT;
    if (strcmp(s, "dpad_right") == 0) return GAMEPAD_BUTTON_DPAD_RIGHT;
    if (strcmp(s, "left_trigger") == 0) return GAMEPAD_AXIS_LEFT_TRIGGER;
    if (strcmp(s, "right_trigger") == 0) return GAMEPAD_AXIS_RIGHT_TRIGGER;
    return GAMEPAD_BUTTON_INVALID;
}

const char* string_from_keycode(SDL_Keycode keycode) {
    return SDL_GetKeyName(keycode);
}

const char* string_from_gamepad_button(SDLConfig_GamepadButton button) {
    switch (button) {
        case GAMEPAD_BUTTON_SOUTH: return "south";
        case GAMEPAD_BUTTON_EAST: return "east";
        case GAMEPAD_BUTTON_WEST: return "west";
        case GAMEPAD_BUTTON_NORTH: return "north";
        case GAMEPAD_BUTTON_BACK: return "back";
        case GAMEPAD_BUTTON_START: return "start";
        case GAMEPAD_BUTTON_LEFT_STICK: return "left_stick";
        case GAMEPAD_BUTTON_RIGHT_STICK: return "right_stick";
        case GAMEPAD_BUTTON_LEFT_SHOULDER: return "left_shoulder";
        case GAMEPAD_BUTTON_RIGHT_SHOULDER: return "right_shoulder";
        case GAMEPAD_BUTTON_DPAD_UP: return "dpad_up";
        case GAMEPAD_BUTTON_DPAD_DOWN: return "dpad_down";
        case GAMEPAD_BUTTON_DPAD_LEFT: return "dpad_left";
        case GAMEPAD_BUTTON_DPAD_RIGHT: return "dpad_right";
        case GAMEPAD_AXIS_LEFT_TRIGGER: return "left_trigger";
        case GAMEPAD_AXIS_RIGHT_TRIGGER: return "right_trigger";
        default: return "invalid";
    }
}

void SDLConfig_Save(const SDLConfig_Configuration* config, const char* path) {
    FILE* file = fopen(path, "w");
    if (!file) {
        SDL_Log("Couldn't open %s for writing.", path);
        return;
    }

    fprintf(file, "[keyboard_p1]\n");
    fprintf(file, "up = %s\n", string_from_keycode(config->player[0].keyboard.up));
    fprintf(file, "down = %s\n", string_from_keycode(config->player[0].keyboard.down));
    fprintf(file, "left = %s\n", string_from_keycode(config->player[0].keyboard.left));
    fprintf(file, "right = %s\n", string_from_keycode(config->player[0].keyboard.right));
    fprintf(file, "low_punch = %s\n", string_from_keycode(config->player[0].keyboard.low_punch));
    fprintf(file, "medium_punch = %s\n", string_from_keycode(config->player[0].keyboard.medium_punch));
    fprintf(file, "hard_punch = %s\n", string_from_keycode(config->player[0].keyboard.hard_punch));
    fprintf(file, "low_kick = %s\n", string_from_keycode(config->player[0].keyboard.low_kick));
    fprintf(file, "medium_kick = %s\n", string_from_keycode(config->player[0].keyboard.medium_kick));
    fprintf(file, "hard_kick = %s\n", string_from_keycode(config->player[0].keyboard.hard_kick));
    fprintf(file, "start = %s\n", string_from_keycode(config->player[0].keyboard.start));
    fprintf(file, "select = %s\n", string_from_keycode(config->player[0].keyboard.select));
    fprintf(file, "\n");

    fprintf(file, "[keyboard_p2]\n");
    fprintf(file, "up = %s\n", string_from_keycode(config->player[1].keyboard.up));
    fprintf(file, "down = %s\n", string_from_keycode(config->player[1].keyboard.down));
    fprintf(file, "left = %s\n", string_from_keycode(config->player[1].keyboard.left));
    fprintf(file, "right = %s\n", string_from_keycode(config->player[1].keyboard.right));
    fprintf(file, "low_punch = %s\n", string_from_keycode(config->player[1].keyboard.low_punch));
    fprintf(file, "medium_punch = %s\n", string_from_keycode(config->player[1].keyboard.medium_punch));
    fprintf(file, "hard_punch = %s\n", string_from_keycode(config->player[1].keyboard.hard_punch));
    fprintf(file, "low_kick = %s\n", string_from_keycode(config->player[1].keyboard.low_kick));
    fprintf(file, "medium_kick = %s\n", string_from_keycode(config->player[1].keyboard.medium_kick));
    fprintf(file, "hard_kick = %s\n", string_from_keycode(config->player[1].keyboard.hard_kick));
    fprintf(file, "start = %s\n", string_from_keycode(config->player[1].keyboard.start));
    fprintf(file, "select = %s\n", string_from_keycode(config->player[1].keyboard.select));
    fprintf(file, "\n");

    fprintf(file, "[gamepad_p1]\n");
    fprintf(file, "low_punch = %s\n", string_from_gamepad_button(config->player[0].gamepad.low_punch));
    fprintf(file, "medium_punch = %s\n", string_from_gamepad_button(config->player[0].gamepad.medium_punch));
    fprintf(file, "hard_punch = %s\n", string_from_gamepad_button(config->player[0].gamepad.hard_punch));
    fprintf(file, "low_kick = %s\n", string_from_gamepad_button(config->player[0].gamepad.low_kick));
    fprintf(file, "medium_kick = %s\n", string_from_gamepad_button(config->player[0].gamepad.medium_kick));
    fprintf(file, "hard_kick = %s\n", string_from_gamepad_button(config->player[0].gamepad.hard_kick));
    fprintf(file, "start = %s\n", string_from_gamepad_button(config->player[0].gamepad.start));
    fprintf(file, "select = %s\n", string_from_gamepad_button(config->player[0].gamepad.select));
    fprintf(file, "\n");

    fprintf(file, "[gamepad_p2]\n");
    fprintf(file, "low_punch = %s\n", string_from_gamepad_button(config->player[1].gamepad.low_punch));
    fprintf(file, "medium_punch = %s\n", string_from_gamepad_button(config->player[1].gamepad.medium_punch));
    fprintf(file, "hard_punch = %s\n", string_from_gamepad_button(config->player[1].gamepad.hard_punch));
    fprintf(file, "low_kick = %s\n", string_from_gamepad_button(config->player[1].gamepad.low_kick));
    fprintf(file, "medium_kick = %s\n", string_from_gamepad_button(config->player[1].gamepad.medium_kick));
    fprintf(file, "hard_kick = %s\n", string_from_gamepad_button(config->player[1].gamepad.hard_kick));
    fprintf(file, "start = %s\n", string_from_gamepad_button(config->player[1].gamepad.start));
    fprintf(file, "select = %s\n", string_from_gamepad_button(config->player[1].gamepad.select));

    fclose(file);
}

void SDLConfig_Init(SDLConfig_Configuration* config) {
    // Player 1 Keyboard
    config->player[0].keyboard.up = SDLK_W;
    config->player[0].keyboard.down = SDLK_S;
    config->player[0].keyboard.left = SDLK_A;
    config->player[0].keyboard.right = SDLK_D;
    config->player[0].keyboard.low_punch = SDLK_J;
    config->player[0].keyboard.medium_punch = SDLK_K;
    config->player[0].keyboard.hard_punch = SDLK_L;
    config->player[0].keyboard.low_kick = SDLK_U;
    config->player[0].keyboard.medium_kick = SDLK_I;
    config->player[0].keyboard.hard_kick = SDLK_O;
    config->player[0].keyboard.start = SDLK_RETURN;
    config->player[0].keyboard.select = SDLK_BACKSPACE;

    // Player 2 Keyboard
    config->player[1].keyboard.up = SDLK_UP;
    config->player[1].keyboard.down = SDLK_DOWN;
    config->player[1].keyboard.left = SDLK_LEFT;
    config->player[1].keyboard.right = SDLK_RIGHT;
    config->player[1].keyboard.low_punch = SDLK_KP_4;
    config->player[1].keyboard.medium_punch = SDLK_KP_5;
    config->player[1].keyboard.hard_punch = SDLK_KP_6;
    config->player[1].keyboard.low_kick = SDLK_KP_1;
    config->player[1].keyboard.medium_kick = SDLK_KP_2;
    config->player[1].keyboard.hard_kick = SDLK_KP_3;
    config->player[1].keyboard.start = SDLK_KP_ENTER;
    config->player[1].keyboard.select = SDLK_KP_0;

    // Player 1 Gamepad
    config->player[0].gamepad.low_punch = GAMEPAD_BUTTON_WEST;
    config->player[0].gamepad.medium_punch = GAMEPAD_BUTTON_NORTH;
    config->player[0].gamepad.hard_punch = GAMEPAD_BUTTON_LEFT_SHOULDER;
    config->player[0].gamepad.low_kick = GAMEPAD_BUTTON_SOUTH;
    config->player[0].gamepad.medium_kick = GAMEPAD_BUTTON_EAST;
    config->player[0].gamepad.hard_kick = GAMEPAD_BUTTON_RIGHT_SHOULDER;
    config->player[0].gamepad.start = GAMEPAD_BUTTON_START;
    config->player[0].gamepad.select = GAMEPAD_BUTTON_BACK;

    // Player 2 Gamepad
    config->player[1].gamepad.low_punch = GAMEPAD_BUTTON_WEST;
    config->player[1].gamepad.medium_punch = GAMEPAD_BUTTON_NORTH;
    config->player[1].gamepad.hard_punch = GAMEPAD_BUTTON_LEFT_SHOULDER;
    config->player[1].gamepad.low_kick = GAMEPAD_BUTTON_SOUTH;
    config->player[1].gamepad.medium_kick = GAMEPAD_BUTTON_EAST;
    config->player[1].gamepad.hard_kick = GAMEPAD_BUTTON_RIGHT_SHOULDER;
    config->player[1].gamepad.start = GAMEPAD_BUTTON_START;
    config->player[1].gamepad.select = GAMEPAD_BUTTON_BACK;
}

static int config_ini_handler(void* user, const char* section, const char* name, const char* value) {
    SDLConfig_Configuration* pconfig = (SDLConfig_Configuration*)user;

    #define MATCH(n) strcmp(name, n) == 0

    int player_idx = -1;
    if (strcmp(section, "keyboard_p1") == 0) player_idx = 0;
    else if (strcmp(section, "keyboard_p2") == 0) player_idx = 1;
    else if (strcmp(section, "gamepad_p1") == 0) player_idx = 0;
    else if (strcmp(section, "gamepad_p2") == 0) player_idx = 1;

    if (player_idx != -1) {
        if (strstr(section, "keyboard")) {
            SDLConfig_KeyboardMapping* kbd = &pconfig->player[player_idx].keyboard;
            SDL_Keycode key = keycode_from_string(value);
            if (key != SDLK_UNKNOWN) {
                if (MATCH("up")) kbd->up = key;
                else if (MATCH("down")) kbd->down = key;
                else if (MATCH("left")) kbd->left = key;
                else if (MATCH("right")) kbd->right = key;
                else if (MATCH("low_punch")) kbd->low_punch = key;
                else if (MATCH("medium_punch")) kbd->medium_punch = key;
                else if (MATCH("hard_punch")) kbd->hard_punch = key;
                else if (MATCH("low_kick")) kbd->low_kick = key;
                else if (MATCH("medium_kick")) kbd->medium_kick = key;
                else if (MATCH("hard_kick")) kbd->hard_kick = key;
                else if (MATCH("start")) kbd->start = key;
                else if (MATCH("select")) kbd->select = key;
            }
        } else if (strstr(section, "gamepad")) {
            SDLConfig_GamepadMapping* pad = &pconfig->player[player_idx].gamepad;
            SDLConfig_GamepadButton button = gamepad_button_from_string(value);
            if (button != GAMEPAD_BUTTON_INVALID) {
                if (MATCH("low_punch")) pad->low_punch = button;
                else if (MATCH("medium_punch")) pad->medium_punch = button;
                else if (MATCH("hard_punch")) pad->hard_punch = button;
                else if (MATCH("low_kick")) pad->low_kick = button;
                else if (MATCH("medium_kick")) pad->medium_kick = button;
                else if (MATCH("hard_kick")) pad->hard_kick = button;
                else if (MATCH("start")) pad->start = button;
                else if (MATCH("select")) pad->select = button;
            }
        }
    }

    return 1;
}

const SDLConfig_Configuration* SDLConfig_Get() {
    return &configuration;
}

static void create_screen_texture() {
    if (screen_texture != NULL) {
        SDL_DestroyTexture(screen_texture);
    }

    int target_width, target_height;
    SDL_GetRenderOutputSize(renderer, &target_width, &target_height);
    screen_texture = SDL_CreateTexture(
        renderer, SDL_PIXELFORMAT_ARGB32, SDL_TEXTUREACCESS_TARGET, target_width * 2, target_height * 2);
    SDL_SetTextureScaleMode(screen_texture, SDL_SCALEMODE_LINEAR);
}

int SDLApp_Init() {
    SDL_SetAppMetadata(app_name, "0.1", NULL);
    SDL_SetHint(SDL_HINT_VIDEO_WAYLAND_PREFER_LIBDECOR, "1");

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return 1;
    }

    if (!SDL_CreateWindowAndRenderer(app_name,
                                     window_default_width,
                                     window_default_height,
                                     SDL_WINDOW_RESIZABLE | SDL_WINDOW_HIGH_PIXEL_DENSITY,
                                     &window,
                                     &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return 1;
    }

    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    // Initialize message renderer
    SDLMessageRenderer_Initialize(renderer);

    // Initialize game renderer
    SDLGameRenderer_Init(renderer);

    // Initialize screen texture
    create_screen_texture();

    // Initialize pads
    SDLPad_Init();

    // Load config
    char* base_path = SDL_GetBasePath();
    char config_path[1024];
    snprintf(config_path, sizeof(config_path), "%s%s", base_path, "config.ini");
    SDL_free(base_path);

    SDLConfig_Init(&configuration);
    if (ini_parse(config_path, config_ini_handler, &configuration) != 0) {
        SDL_Log("Couldn't load config.ini or it contains errors, saving defaults");
        SDLConfig_Save(&configuration, config_path);
    }

    return 0;
}

void SDLApp_Quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

static void set_screenshot_flag_if_needed(SDL_KeyboardEvent* event) {
    if ((event->key == SDLK_GRAVE) && event->down && !event->repeat) {
        should_save_screenshot = true;
    }
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
            set_screenshot_flag_if_needed(&event.key);
            SDLPad_HandleKeyboardEvent(&event.key);
            break;

        case SDL_EVENT_WINDOW_RESIZED:
            create_screen_texture();
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

    if (frame_deadline == 0) {
        frame_deadline = frame_start + target_frame_time_ns;
    }

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

static void note_frame_end_time() {
    frame_end_times[frame_end_times_index] = SDL_GetTicksNS();
    frame_end_times_index += 1;
    frame_end_times_index %= FRAME_END_TIMES_MAX;

    if (frame_end_times_index == 0) {
        frame_end_times_filled = true;
    }
}

static void update_fps() {
    if (!frame_end_times_filled) {
        return;
    }

    double total_frame_time_ms = 0;

    for (int i = 0; i < FRAME_END_TIMES_MAX - 1; i++) {
        const int cur = frame_end_times_index;
        const int next = (cur + 1) % FRAME_END_TIMES_MAX;
        total_frame_time_ms += (double)(frame_end_times[next] - frame_end_times[cur]) / 1000000;
    }

    double average_frame_time_ms = total_frame_time_ms / FRAME_END_TIMES_MAX;
    fps = 1000 / average_frame_time_ms;
}

static void save_texture(SDL_Texture* texture, const char* filename) {
    SDL_SetRenderTarget(renderer, texture);
    const SDL_Surface* rendered_surface = SDL_RenderReadPixels(renderer, NULL);
    SDL_SaveBMP(rendered_surface, filename);
    SDL_DestroySurface(rendered_surface);
}

void SDLApp_EndFrame() {
    // Run PS2 interrupts. Necessary for CRI to run its logic
    begin_interrupt();
    ADXPS2_ExecVint(0);
    end_interrupt();

    // Render

    SDLGameRenderer_RenderFrame();

    if (should_save_screenshot) {
        save_texture(cps3_canvas, "screenshot_cps3.bmp");
    }

    SDL_SetRenderTarget(renderer, screen_texture);

    // Render window background
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black bars
    SDL_RenderClear(renderer);

    // Render content
    const SDL_FRect dst_rect = get_letterbox_rect(screen_texture->w, screen_texture->h);
    SDL_RenderTexture(renderer, cps3_canvas, NULL, &dst_rect);
    SDL_RenderTexture(renderer, message_canvas, NULL, &dst_rect);

    // Render screen texture to screen
    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderTexture(renderer, screen_texture, NULL, NULL);

    if (should_save_screenshot) {
        save_texture(screen_texture, "screenshot_screen.bmp");
    }

    // Render metrics
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_SetRenderScale(renderer, 2, 2);
    SDL_RenderDebugTextFormat(renderer, 8, 8, "FPS: %f", fps);
    SDL_RenderDebugTextFormat(renderer, 8, 20, "Render tasks: %d", SDLGameRenderer_GetRenderTaskCount());

    if (opening_index >= 0) {
        SDL_RenderDebugTextFormat(renderer, 8, 32, "Opening index: %d", opening_index);
    }

    SDL_SetRenderScale(renderer, 1, 1);

    SDL_RenderPresent(renderer);

    const Uint64 current_time = SDL_GetTicksNS();

    if (current_time < frame_deadline) {
        const Uint64 sleep_time = frame_deadline - current_time;
        SDL_DelayNS(sleep_time);
        frame_deadline += target_frame_time_ns;
    } else {
        frame_deadline = current_time + target_frame_time_ns;
    }

    // Measure
    frame_counter += 1;
    note_frame_end_time();
    update_fps();

    // Cleanup
    SDLGameRenderer_EndFrame();
    should_save_screenshot = false;
}

void SDLApp_SetOpeningIndex(int index) {
    opening_index = index;
}