#include "port/sdl/sdl_pad.h"
#include "port/sdl/sdl_config.h"

#include <SDL3/SDL.h>

#define INPUT_SOURCES_MAX 2

typedef enum SDLPad_InputType { SDLPAD_INPUT_NONE = 0, SDLPAD_INPUT_GAMEPAD, SDLPAD_INPUT_KEYBOARD } SDLPad_InputType;

typedef struct SDLPad_GamepadInputSource {
    Uint32 type;
    SDL_Gamepad* gamepad;
} SDLPad_GamepadInputSource;

typedef struct SDLPad_KeyboardInputSource {
    Uint32 type;
} SDLPad_KeyboardInputSource;

typedef union SDLPad_InputSource {
    Uint32 type;
    SDLPad_GamepadInputSource gamepad;
    SDLPad_KeyboardInputSource keyboard;
} SDLPad_InputSource;

static SDLPad_InputSource input_sources[INPUT_SOURCES_MAX] = { 0 };
static int connected_input_sources = 0;
static SDLPad_ButtonState button_state[INPUT_SOURCES_MAX] = { 0 };

static int input_source_index_from_joystick_id(SDL_JoystickID id) {
    for (int i = 0; i < INPUT_SOURCES_MAX; i++) {
        const SDLPad_InputSource* input_source = &input_sources[i];

        if (input_source->type != SDLPAD_INPUT_GAMEPAD) {
            continue;
        }

        const SDL_JoystickID this_id = SDL_GetGamepadID(input_source->gamepad.gamepad);

        if (this_id == id) {
            return i;
        }
    }

    return -1;
}

static void handle_gamepad_added_event(SDL_GamepadDeviceEvent* event) {
    int target_index = -1;
    for (int i = 0; i < INPUT_SOURCES_MAX; i++) {
        if (input_sources[i].type != SDLPAD_INPUT_GAMEPAD) {
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

    SDLPad_InputSource* input_source = &input_sources[target_index];

    if (input_source->type == SDLPAD_INPUT_NONE) {
        connected_input_sources++;
    }

    input_source->type = SDLPAD_INPUT_GAMEPAD;
    input_source->gamepad.gamepad = gamepad;
    memset(&button_state[target_index], 0, sizeof(SDLPad_ButtonState));
}

static void handle_gamepad_removed_event(SDL_GamepadDeviceEvent* event) {
    const int index = input_source_index_from_joystick_id(event->which);

    if (index < 0) {
        return;
    }

    SDLPad_InputSource* input_source = &input_sources[index];
    SDL_CloseGamepad(input_source->gamepad.gamepad);
    input_source->type = SDLPAD_INPUT_NONE;
    memset(&button_state[index], 0, sizeof(SDLPad_ButtonState));
    connected_input_sources -= 1;
}

void SDLPad_Init() {
    memset(input_sources, 0, sizeof(input_sources));
    memset(button_state, 0, sizeof(button_state));
    connected_input_sources = 0;
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

    SDLPad_ButtonState* state = &button_state[index];
    const SDLConfig_GamepadMapping* mapping = &SDLConfig_Get()->player[index].gamepad;
    int button = event->button;

    if (button == SDL_GAMEPAD_BUTTON_DPAD_UP) state->dpad_up = event->down;
    if (button == SDL_GAMEPAD_BUTTON_DPAD_DOWN) state->dpad_down = event->down;
    if (button == SDL_GAMEPAD_BUTTON_DPAD_LEFT) state->dpad_left = event->down;
    if (button == SDL_GAMEPAD_BUTTON_DPAD_RIGHT) state->dpad_right = event->down;

    if (mapping->start == button) state->start = event->down;
    if (mapping->select == button) state->back = event->down;
    if (mapping->low_punch == button) state->low_punch = event->down;
    if (mapping->medium_punch == button) state->medium_punch = event->down;
    if (mapping->hard_punch == button) state->hard_punch = event->down;
    if (mapping->low_kick == button) state->low_kick = event->down;
    if (mapping->medium_kick == button) state->medium_kick = event->down;
    if (mapping->hard_kick == button) state->hard_kick = event->down;
}

void SDLPad_HandleGamepadAxisMotionEvent(SDL_GamepadAxisEvent* event) {
    const int index = input_source_index_from_joystick_id(event->which);

    if (index < 0) {
        return;
    }

    SDLPad_ButtonState* state = &button_state[index];
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
            state->hard_punch = event->value > dead_zone;
        }
        break;

    case SDL_GAMEPAD_AXIS_RIGHT_TRIGGER:
        state->right_trigger = event->value;
        if (mapping->hard_kick == GAMEPAD_AXIS_RIGHT_TRIGGER) {
            state->hard_kick = event->value > dead_zone;
        }
        break;
    }
}

void SDLPad_HandleKeyboardEvent(SDL_KeyboardEvent* event) {
    int target_index = -1;
    for (int i = 0; i < INPUT_SOURCES_MAX; i++) {
        if (input_sources[i].type != SDLPAD_INPUT_GAMEPAD) {
            target_index = i;
            break;
        }
    }

    if (target_index == -1) {
        return;
    }

    SDLPad_InputSource* input_source = &input_sources[target_index];
    if (input_source->type == SDLPAD_INPUT_NONE) {
        input_source->type = SDLPAD_INPUT_KEYBOARD;
        connected_input_sources++;
    }

    SDLPad_ButtonState* state = &button_state[target_index];
    const SDLConfig_KeyboardMapping* mapping = &SDLConfig_Get()->player[target_index].keyboard;
    SDL_Keycode key = event->key;

    if (key == mapping->up) state->dpad_up = event->down;
    if (key == mapping->down) state->dpad_down = event->down;
    if (key == mapping->left) state->dpad_left = event->down;
    if (key == mapping->right) state->dpad_right = event->down;
    if (key == mapping->start) state->start = event->down;
    if (key == mapping->select) state->back = event->down;
    if (key == mapping->low_punch) state->low_punch = event->down;
    if (key == mapping->medium_punch) state->medium_punch = event->down;
    if (key == mapping->hard_punch) state->hard_punch = event->down;
    if (key == mapping->low_kick) state->low_kick = event->down;
    if (key == mapping->medium_kick) state->medium_kick = event->down;
    if (key == mapping->hard_kick) state->hard_kick = event->down;
}

bool SDLPad_IsGamepadConnected(int id) {
    return input_sources[id].type != SDLPAD_INPUT_NONE;
}

void SDLPad_GetButtonState(int id, SDLPad_ButtonState* state) {
    memcpy(state, &button_state[id], sizeof(SDLPad_ButtonState));
}

void SDLPad_RumblePad(int id, bool low_freq_enabled, Uint8 high_freq_rumble) {
    const SDLPad_InputSource* input_source = &input_sources[id];

    if (input_source->type != SDLPAD_INPUT_GAMEPAD) {
        return;
    }

    const Uint16 low_freq_rumble = low_freq_enabled ? UINT16_MAX : 0;
    const Uint16 high_freq_rumble_adjusted = ((float)high_freq_rumble / UINT8_MAX) * UINT16_MAX;
    const Uint32 duration = high_freq_rumble_adjusted > 0 ? 500 : 200;

    SDL_RumbleGamepad(input_source->gamepad.gamepad, low_freq_rumble, high_freq_rumble_adjusted, duration);
}