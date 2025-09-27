#include "port/sdl/sdl_pad.h"
#include "port/config.h"

#include <SDL3/SDL.h>

#define INPUT_SOURCES_MAX 2

typedef enum SDLPad_InputType { SDLPAD_INPUT_NONE = 0, SDLPAD_INPUT_GAMEPAD, SDLPAD_INPUT_KEYBOARD } SDLPad_InputType;

typedef struct SDLPad_GamepadInputSource {
    Uint32 type;
    SDL_Gamepad *gamepad;
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
        const SDLPad_InputSource *input_source = &input_sources[i];

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

static void handle_gamepad_added_event(SDL_GamepadDeviceEvent *event) {
    if (connected_input_sources >= INPUT_SOURCES_MAX) {
        return;
    }

    const SDL_Gamepad *gamepad = SDL_OpenGamepad(event->which);

    for (int i = 0; i < INPUT_SOURCES_MAX; i++) {
        SDLPad_InputSource *input_source = &input_sources[i];

        if (input_source->type != SDLPAD_INPUT_NONE) {
            continue;
        }

        input_source->type = SDLPAD_INPUT_GAMEPAD;
        input_source->gamepad.gamepad = gamepad;
        break;
    }

    connected_input_sources += 1;
}

static void handle_gamepad_removed_event(SDL_GamepadDeviceEvent *event) {
    const int index = input_source_index_from_joystick_id(event->which);

    if (index < 0) {
        return;
    }

    SDLPad_InputSource *input_source = &input_sources[index];
    SDL_CloseGamepad(input_source->gamepad.gamepad);
    input_source->type = SDLPAD_INPUT_NONE;
    memset(&button_state[index], 0, sizeof(SDLPad_ButtonState));
    connected_input_sources -= 1;
}

void SDLPad_Init() {
    input_sources[0].type = SDLPAD_INPUT_KEYBOARD;
    connected_input_sources += 1;
}

void SDLPad_HandleGamepadDeviceEvent(SDL_GamepadDeviceEvent *event) {
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

void SDLPad_HandleGamepadButtonEvent(SDL_GamepadButtonEvent *event) {
    const int index = input_source_index_from_joystick_id(event->which);

    if (index < 0) {
        return;
    }

    SDLPad_ButtonState *state = &button_state[index];
    const Config_GamepadMapping* mapping = &config.gamepad_mapping;

    if (event->button == mapping->south) { state->south = event->down; }
    else if (event->button == mapping->east) { state->east = event->down; }
    else if (event->button == mapping->west) { state->west = event->down; }
    else if (event->button == mapping->north) { state->north = event->down; }
    else if (event->button == mapping->back) { state->back = event->down; }
    else if (event->button == mapping->start) { state->start = event->down; }
    else if (event->button == mapping->left_stick) { state->left_stick = event->down; }
    else if (event->button == mapping->right_stick) { state->right_stick = event->down; }
    else if (event->button == mapping->left_shoulder) { state->left_shoulder = event->down; }
    else if (event->button == mapping->right_shoulder) { state->right_shoulder = event->down; }
    else if (event->button == mapping->dpad_up) { state->dpad_up = event->down; }
    else if (event->button == mapping->dpad_down) { state->dpad_down = event->down; }
    else if (event->button == mapping->dpad_left) { state->dpad_left = event->down; }
    else if (event->button == mapping->dpad_right) { state->dpad_right = event->down; }
}

void SDLPad_HandleGamepadAxisMotionEvent(SDL_GamepadAxisEvent *event) {
    const int index = input_source_index_from_joystick_id(event->which);

    if (index < 0) {
        return;
    }

    SDLPad_ButtonState *state = &button_state[index];

    switch (event->axis) {
    case SDL_GAMEPAD_AXIS_LEFTX:
        state->left_stick_x = event->value;
        break;

    case SDL_GAMEPAD_AXIS_LEFTY:
        state->left_stick_y = event->value;
        break;

    case SDL_GAMEPAD_AXIS_LEFT_TRIGGER:
        state->left_trigger = event->value;
        break;

    case SDL_GAMEPAD_AXIS_RIGHT_TRIGGER:
        state->right_trigger = event->value;
        break;
    }
}

void SDLPad_HandleKeyboardEvent(SDL_KeyboardEvent *event) {
    SDLPad_ButtonState *state = &button_state[0];
    const Config_KeyboardMapping* mapping = &config.keyboard_mapping;

    if (event->key == mapping->dpad_up) { state->dpad_up = event->down; }
    else if (event->key == mapping->dpad_left) { state->dpad_left = event->down; }
    else if (event->key == mapping->dpad_down) { state->dpad_down = event->down; }
    else if (event->key == mapping->dpad_right) { state->dpad_right = event->down; }
    else if (event->key == mapping->north) { state->north = event->down; }
    else if (event->key == mapping->west) { state->west = event->down; }
    else if (event->key == mapping->south) { state->south = event->down; }
    else if (event->key == mapping->east) { state->east = event->down; }
    else if (event->key == mapping->left_shoulder) { state->left_shoulder = event->down; }
    else if (event->key == mapping->right_shoulder) { state->right_shoulder = event->down; }
    else if (event->key == mapping->left_trigger) { state->left_trigger = event->down ? SDL_MAX_SINT16 : 0; }
    else if (event->key == mapping->right_trigger) { state->right_trigger = event->down ? SDL_MAX_SINT16 : 0; }
    else if (event->key == mapping->left_stick) { state->left_stick = event->down; }
    else if (event->key == mapping->right_stick) { state->right_stick = event->down; }
    else if (event->key == mapping->back) { state->back = event->down; }
    else if (event->key == mapping->start) { state->start = event->down; }
}

bool SDLPad_IsGamepadConnected(int id) {
    return input_sources[id].type != SDLPAD_INPUT_NONE;
}

void SDLPad_GetButtonState(int id, SDLPad_ButtonState *state) {
    memcpy(state, &button_state[id], sizeof(SDLPad_ButtonState));
}

void SDLPad_Rumble(int id, float strength, int duration_ms) {
    if (input_sources[id].type != SDLPAD_INPUT_GAMEPAD) {
        return;
    }

    const Uint16 low_frequency_rumble = strength * 0xFFFF;
    const Uint16 high_frequency_rumble = strength * 0xFFFF;

    SDL_RumbleGamepad(input_sources[id].gamepad.gamepad, low_frequency_rumble, high_frequency_rumble, duration_ms);
}
