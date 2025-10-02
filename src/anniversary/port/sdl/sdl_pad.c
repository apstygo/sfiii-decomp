#include "port/sdl/sdl_pad.h"
#include "port/sdl/sdl_config.h"

#include <SDL3/SDL.h>

#define INPUT_SOURCES_MAX 2

typedef enum SDLPad_InputType { SDLPAD_INPUT_NONE = 0, SDLPAD_INPUT_GAMEPAD } SDLPad_InputType;

typedef struct SDLPad_GamepadInputSource {
    SDLPad_InputType type;
    SDL_Gamepad* gamepad;
} SDLPad_GamepadInputSource;

static SDLPad_GamepadInputSource input_sources[INPUT_SOURCES_MAX] = { 0 };
static SDLPad_ButtonState gamepad_button_state[INPUT_SOURCES_MAX] = { 0 };
static SDLPad_ButtonState keyboard_button_state[INPUT_SOURCES_MAX] = { 0 };

static int input_source_index_from_joystick_id(SDL_JoystickID id) {
    for (int i = 0; i < INPUT_SOURCES_MAX; i++) {
        const SDLPad_GamepadInputSource* input_source = &input_sources[i];

        if (input_source->type != SDLPAD_INPUT_GAMEPAD) {
            continue;
        }

        const SDL_JoystickID this_id = SDL_GetGamepadID(input_source->gamepad);

        if (this_id == id) {
            return i;
        }
    }

    return -1;
}

static void handle_gamepad_added_event(SDL_GamepadDeviceEvent* event) {
    int target_index = -1;
    for (int i = 0; i < INPUT_SOURCES_MAX; i++) {
        if (input_sources[i].type == SDLPAD_INPUT_NONE) {
            target_index = i;
            break;
        }
    }

    if (target_index == -1) {
        return;
    }

    SDL_Gamepad* gamepad = SDL_OpenGamepad(event->which);
    if (gamepad == NULL) {
        return;
    }

    SDLPad_GamepadInputSource* input_source = &input_sources[target_index];
    input_source->type = SDLPAD_INPUT_GAMEPAD;
    input_source->gamepad = gamepad;
    memset(&gamepad_button_state[target_index], 0, sizeof(SDLPad_ButtonState));
}

static void handle_gamepad_removed_event(SDL_GamepadDeviceEvent* event) {
    const int index = input_source_index_from_joystick_id(event->which);

    if (index < 0) {
        return;
    }

    SDLPad_GamepadInputSource* input_source = &input_sources[index];
    SDL_CloseGamepad(input_source->gamepad);
    input_source->type = SDLPAD_INPUT_NONE;
    memset(&gamepad_button_state[index], 0, sizeof(SDLPad_ButtonState));
}

void SDLPad_Init() {
    memset(input_sources, 0, sizeof(input_sources));
    memset(gamepad_button_state, 0, sizeof(gamepad_button_state));
    memset(keyboard_button_state, 0, sizeof(keyboard_button_state));
}

void SDLPad_HandleGamepadDeviceEvent(SDL_GamepadDeviceEvent* event) {
    switch (event->type) {
    case SDL_EVENT_GAMEPAD_ADDED:
        handle_gamepad_added_event(event);
        break;

    case SDL_EVENT_GAMEPAD_REMOVED:
        handle_gamepad_removed_event(event);
        break;

    default:
        // Do nothing
        break;
    }
}

void SDLPad_HandleGamepadButtonEvent(SDL_GamepadButtonEvent* event) {
    const int index = input_source_index_from_joystick_id(event->which);

    if (index < 0) {
        return;
    }

    SDLPad_ButtonState* state = &gamepad_button_state[index];
    const SDLConfig_GamepadMapping* mapping = &SDLConfig_Get()->player[index].gamepad;
    int button = event->button;

    if (button == SDL_GAMEPAD_BUTTON_DPAD_UP) state->dpad_up = event->down;
    if (button == SDL_GAMEPAD_BUTTON_DPAD_DOWN) state->dpad_down = event->down;
    if (button == SDL_GAMEPAD_BUTTON_DPAD_LEFT) state->dpad_left = event->down;
    if (button == SDL_GAMEPAD_BUTTON_DPAD_RIGHT) state->dpad_right = event->down;
    if (button == SDL_GAMEPAD_BUTTON_START) state->start = event->down;
    if (button == SDL_GAMEPAD_BUTTON_BACK) state->back = event->down;
    if (button == SDL_GAMEPAD_BUTTON_LEFT_STICK) state->left_stick = event->down;
    if (button == SDL_GAMEPAD_BUTTON_RIGHT_STICK) state->right_stick = event->down;

    if (mapping->low_punch == button) state->west = event->down;
    if (mapping->medium_punch == button) state->north = event->down;
    if (mapping->hard_punch == button) state->left_shoulder = event->down;
    if (mapping->low_kick == button) state->south = event->down;
    if (mapping->medium_kick == button) state->east = event->down;
    if (mapping->hard_kick == button) state->right_shoulder = event->down;
}

void SDLPad_HandleGamepadAxisMotionEvent(SDL_GamepadAxisEvent* event) {
    const int index = input_source_index_from_joystick_id(event->which);

    if (index < 0) {
        return;
    }

    SDLPad_ButtonState* state = &gamepad_button_state[index];
    const SDLConfig_GamepadMapping* mapping = &SDLConfig_Get()->player[index].gamepad;

    const Sint16 dead_zone = 8000;

    switch (event->axis) {
    case SDL_GAMEPAD_AXIS_LEFTX:
        if (event->value < -dead_zone) {
            state->dpad_left = true;
            state->dpad_right = false;
        } else if (event->value > dead_zone) {
            state->dpad_left = false;
            state->dpad_right = true;
        } else {
            state->dpad_left = false;
            state->dpad_right = false;
        }
        break;

    case SDL_GAMEPAD_AXIS_LEFTY:
        if (event->value < -dead_zone) {
            state->dpad_up = true;
            state->dpad_down = false;
        } else if (event->value > dead_zone) {
            state->dpad_up = false;
            state->dpad_down = true;
        } else {
            state->dpad_up = false;
            state->dpad_down = false;
        }
        break;

    case SDL_GAMEPAD_AXIS_LEFT_TRIGGER:
        state->left_trigger = event->value;
        if (mapping->hard_punch == GAMEPAD_AXIS_LEFT_TRIGGER) {
            state->left_shoulder = event->value > dead_zone;
        }
        break;

    case SDL_GAMEPAD_AXIS_RIGHT_TRIGGER:
        state->right_trigger = event->value;
        if (mapping->hard_kick == GAMEPAD_AXIS_RIGHT_TRIGGER) {
            state->right_shoulder = event->value > dead_zone;
        }
        break;
    }
}

void SDLPad_HandleKeyboardEvent(SDL_KeyboardEvent* event) {
    SDL_Keycode key = event->key;

    for (int i = 0; i < INPUT_SOURCES_MAX; i++) {
        SDLPad_ButtonState* state = &keyboard_button_state[i];
        const SDLConfig_KeyboardMapping* mapping = &SDLConfig_Get()->player[i].keyboard;

        if (key == mapping->up) state->dpad_up = event->down;
        if (key == mapping->down) state->dpad_down = event->down;
        if (key == mapping->left) state->dpad_left = event->down;
        if (key == mapping->right) state->dpad_right = event->down;
        if (key == mapping->start) state->start = event->down;
        if (key == mapping->select) state->back = event->down;
        if (key == mapping->low_punch) state->west = event->down;
        if (key == mapping->medium_punch) state->north = event->down;
        if (key == mapping->hard_punch) state->left_shoulder = event->down;
        if (key == mapping->low_kick) state->south = event->down;
        if (key == mapping->medium_kick) state->east = event->down;
        if (key == mapping->hard_kick) state->right_shoulder = event->down;
    }
}

bool SDLPad_IsGamepadConnected(int id) {
    return input_sources[id].type != SDLPAD_INPUT_NONE;
}

void SDLPad_GetButtonState(int id, SDLPad_ButtonState* state) {
    memcpy(state, &gamepad_button_state[id], sizeof(SDLPad_ButtonState));

    state->dpad_up |= keyboard_button_state[id].dpad_up;
    state->dpad_down |= keyboard_button_state[id].dpad_down;
    state->dpad_left |= keyboard_button_state[id].dpad_left;
    state->dpad_right |= keyboard_button_state[id].dpad_right;
    state->start |= keyboard_button_state[id].start;
    state->back |= keyboard_button_state[id].back;
    state->west |= keyboard_button_state[id].west;
    state->north |= keyboard_button_state[id].north;
    state->left_shoulder |= keyboard_button_state[id].left_shoulder;
    state->south |= keyboard_button_state[id].south;
    state->east |= keyboard_button_state[id].east;
    state->right_shoulder |= keyboard_button_state[id].right_shoulder;
    if (keyboard_button_state[id].left_trigger) {
        state->left_trigger = keyboard_button_state[id].left_trigger;
    }
    if (keyboard_button_state[id].right_trigger) {
        state->right_trigger = keyboard_button_state[id].right_trigger;
    }
}

void SDLPad_RumblePad(int id, bool low_freq_enabled, Uint8 high_freq_rumble) {
    const SDLPad_GamepadInputSource* input_source = &input_sources[id];

    if (input_source->type != SDLPAD_INPUT_GAMEPAD) {
        return;
    }

    const Uint16 low_freq_rumble = low_freq_enabled ? UINT16_MAX : 0;
    const Uint16 high_freq_rumble_adjusted = ((float)high_freq_rumble / UINT8_MAX) * UINT16_MAX;
    const Uint32 duration = high_freq_rumble_adjusted > 0 ? 500 : 200;

    SDL_RumbleGamepad(input_source->gamepad, low_freq_rumble, high_freq_rumble_adjusted, duration);
}