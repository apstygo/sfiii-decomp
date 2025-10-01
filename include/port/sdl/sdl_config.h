#ifndef SRC_ANNIVERSARY_PORT_SDL_SDL_CONFIG_H_
#define SRC_ANNIVERSARY_PORT_SDL_SDL_CONFIG_H_

#include <SDL3/SDL.h>
#include "port/sdl/sdl_pad.h"

#define INPUT_SOURCES_MAX 2

// Enum for gamepad buttons for easier config mapping
typedef enum {
    GAMEPAD_BUTTON_INVALID = -1,
    GAMEPAD_BUTTON_SOUTH,
    GAMEPAD_BUTTON_EAST,
    GAMEPAD_BUTTON_WEST,
    GAMEPAD_BUTTON_NORTH,
    GAMEPAD_BUTTON_BACK,
    GAMEPAD_BUTTON_START,
    GAMEPAD_BUTTON_LEFT_STICK,
    GAMEPAD_BUTTON_RIGHT_STICK,
    GAMEPAD_BUTTON_LEFT_SHOULDER,
    GAMEPAD_BUTTON_RIGHT_SHOULDER,
    GAMEPAD_BUTTON_DPAD_UP,
    GAMEPAD_BUTTON_DPAD_DOWN,
    GAMEPAD_BUTTON_DPAD_LEFT,
    GAMEPAD_BUTTON_DPAD_RIGHT,
    GAMEPAD_AXIS_LEFT_TRIGGER,
    GAMEPAD_AXIS_RIGHT_TRIGGER,
} SDLConfig_GamepadButton;

// Struct to hold keyboard mappings
typedef struct {
    SDL_Keycode up;
    SDL_Keycode down;
    SDL_Keycode left;
    SDL_Keycode right;
    SDL_Keycode low_punch;
    SDL_Keycode medium_punch;
    SDL_Keycode hard_punch;
    SDL_Keycode low_kick;
    SDL_Keycode medium_kick;
    SDL_Keycode hard_kick;
    SDL_Keycode start;
    SDL_Keycode select;
} SDLConfig_KeyboardMapping;

// Struct to hold gamepad mappings
typedef struct {
    SDLConfig_GamepadButton low_punch;
    SDLConfig_GamepadButton medium_punch;
    SDLConfig_GamepadButton hard_punch;
    SDLConfig_GamepadButton low_kick;
    SDLConfig_GamepadButton medium_kick;
    SDLConfig_GamepadButton hard_kick;
    SDLConfig_GamepadButton start;
    SDLConfig_GamepadButton select;
} SDLConfig_GamepadMapping;

// Struct to hold all input configurations for one player
typedef struct {
    SDLConfig_KeyboardMapping keyboard;
    SDLConfig_GamepadMapping gamepad;
} SDLConfig_InputConfig;

// Top-level configuration struct
typedef struct {
    SDLConfig_InputConfig player[INPUT_SOURCES_MAX];
} SDLConfig_Configuration;

// Functions to be defined in sdl_app.c
void SDLConfig_Init(SDLConfig_Configuration* config);
void SDLConfig_Load(SDLConfig_Configuration* config, const char* path);
void SDLConfig_Save(const SDLConfig_Configuration* config, const char* path);
const SDLConfig_Configuration* SDLConfig_Get();

#endif  // SRC_ANNIVERSARY_PORT_SDL_SDL_CONFIG_H_