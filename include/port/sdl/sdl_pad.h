#ifndef SDL_PAD_H
#define SDL_PAD_H

#include <SDL3/SDL.h>
#include <stdbool.h>

typedef struct SDLPad_ButtonState {
    bool dpad_up;
    bool dpad_down;
    bool dpad_left;
    bool dpad_right;
    bool start;
    bool back;
    bool low_punch;
    bool medium_punch;
    bool hard_punch;
    bool low_kick;
    bool medium_kick;
    bool hard_kick;
    Sint16 left_trigger;
    Sint16 right_trigger;
} SDLPad_ButtonState;

void SDLPad_Init();
void SDLPad_HandleGamepadDeviceEvent(SDL_GamepadDeviceEvent* event);
void SDLPad_HandleGamepadButtonEvent(SDL_GamepadButtonEvent* event);
void SDLPad_HandleGamepadAxisMotionEvent(SDL_GamepadAxisEvent* event);
void SDLPad_HandleKeyboardEvent(SDL_KeyboardEvent* event);
bool SDLPad_IsGamepadConnected(int id);
void SDLPad_GetButtonState(int id, SDLPad_ButtonState* state);
void SDLPad_RumblePad(int id, bool low_freq_enabled, Uint8 high_freq_rumble);

#endif