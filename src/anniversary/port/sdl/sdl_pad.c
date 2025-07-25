#include "port/sdl/sdl_pad.h"

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

    switch (event->button) {
    case SDL_GAMEPAD_BUTTON_SOUTH:
        state->south = event->down;
        break;

    case SDL_GAMEPAD_BUTTON_EAST:
        state->east = event->down;
        break;

    case SDL_GAMEPAD_BUTTON_WEST:
        state->west = event->down;
        break;

    case SDL_GAMEPAD_BUTTON_NORTH:
        state->north = event->down;
        break;

    case SDL_GAMEPAD_BUTTON_BACK:
        state->back = event->down;
        break;

    case SDL_GAMEPAD_BUTTON_START:
        state->start = event->down;
        break;

    case SDL_GAMEPAD_BUTTON_LEFT_STICK:
        state->left_stick = event->down;
        break;

    case SDL_GAMEPAD_BUTTON_RIGHT_STICK:
        state->right_stick = event->down;
        break;

    case SDL_GAMEPAD_BUTTON_LEFT_SHOULDER:
        state->left_shoulder = event->down;
        break;

    case SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER:
        state->right_shoulder = event->down;
        break;

    case SDL_GAMEPAD_BUTTON_DPAD_UP:
        state->dpad_up = event->down;
        break;

    case SDL_GAMEPAD_BUTTON_DPAD_DOWN:
        state->dpad_down = event->down;
        break;

    case SDL_GAMEPAD_BUTTON_DPAD_LEFT:
        state->dpad_left = event->down;
        break;

    case SDL_GAMEPAD_BUTTON_DPAD_RIGHT:
        state->dpad_right = event->down;
        break;
    }
}

void SDLPad_HandleGamepadAxisMotionEvent(SDL_GamepadAxisEvent *event) {
    const int index = input_source_index_from_joystick_id(event->which);

    if (index < 0) {
        return;
    }

    SDLPad_ButtonState *state = &button_state[index];

    switch (event->axis) {
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

    switch (event->key) {
    case SDLK_W:
        state->dpad_up = event->down;
        break;

    case SDLK_A:
        state->dpad_left = event->down;
        break;

    case SDLK_S:
        state->dpad_down = event->down;
        break;

    case SDLK_D:
        state->dpad_right = event->down;
        break;

    case SDLK_I:
        state->north = event->down;
        break;

    case SDLK_J:
        state->west = event->down;
        break;

    case SDLK_K:
        state->south = event->down;
        break;

    case SDLK_L:
        state->east = event->down;
        break;

    case SDLK_Q:
        state->left_shoulder = event->down;
        break;

    case SDLK_E:
        state->right_shoulder = event->down;
        break;

    case SDLK_1:
        state->left_trigger = event->down ? SDL_MAX_SINT16 : 0;
        break;

    case SDLK_3:
        state->right_trigger = event->down ? SDL_MAX_SINT16 : 0;
        break;

    case SDLK_2:
        state->left_stick = event->down;
        break;

    case SDLK_4:
        state->right_stick = event->down;
        break;

    case SDLK_BACKSPACE:
        state->back = event->down;
        break;

    case SDLK_RETURN:
        state->start = event->down;
        break;
    }
}

bool SDLPad_IsGamepadConnected(int id) {
    return input_sources[id].type != SDLPAD_INPUT_NONE;
}

void SDLPad_GetButtonState(int id, SDLPad_ButtonState *state) {
    memcpy(state, &button_state[id], sizeof(SDLPad_ButtonState));
}
