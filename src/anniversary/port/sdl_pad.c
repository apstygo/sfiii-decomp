#include "port/sdl_pad.h"

#include <SDL3/SDL.h>

#define GAMEPADS_MAX 2

static SDL_Gamepad *gamepads[GAMEPADS_MAX] = { NULL, NULL };
static int connected_gamepads = 0;
static SDLPad_ButtonState button_state[GAMEPADS_MAX] = { 0 };

static int gamepad_index_from_joystick_id(SDL_JoystickID id) {
    for (int i = 0; i < GAMEPADS_MAX; i++) {
        SDL_Gamepad *gamepad = gamepads[i];

        if (gamepad == NULL) {
            continue;
        }

        SDL_JoystickID this_id = SDL_GetGamepadID(gamepad);

        if (this_id == id) {
            return i;
        }
    }

    return -1;
}

static void handle_gamepad_added_event(SDL_GamepadDeviceEvent *event) {
    if (connected_gamepads >= GAMEPADS_MAX) {
        return;
    }

    SDL_Gamepad *gamepad = SDL_OpenGamepad(event->which);

    for (int i = 0; i < GAMEPADS_MAX; i++) {
        if (gamepads[i] == NULL) {
            gamepads[i] = gamepad;
            break;
        }
    }

    connected_gamepads += 1;
}

static void handle_gamepad_removed_event(SDL_GamepadDeviceEvent *event) {
    const int index = gamepad_index_from_joystick_id(event->which);

    if (index < 0) {
        return;
    }

    SDL_CloseGamepad(gamepads[index]);
    gamepads[index] = NULL;
    connected_gamepads -= 1;
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
    const int index = gamepad_index_from_joystick_id(event->which);

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
    const int index = gamepad_index_from_joystick_id(event->which);

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

bool SDLPad_IsGamepadConnected(int id) {
    return gamepads[id] != NULL;
}

void SDLPad_GetButtonState(int id, SDLPad_ButtonState *state) {
    memcpy(state, &button_state[id], sizeof(SDLPad_ButtonState));
}
