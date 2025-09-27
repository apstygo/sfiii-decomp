#pragma once

#include <stdbool.h>
#include <SDL3/SDL.h>

typedef struct Config_Display {
    int width;
    int height;
    bool fullscreen;
    bool borderless;
    bool stretched;
} Config_Display;

typedef struct Config_KeyboardMapping {
    SDL_Keycode dpad_up;
    SDL_Keycode dpad_down;
    SDL_Keycode dpad_left;
    SDL_Keycode dpad_right;
    SDL_Keycode north;
    SDL_Keycode west;
    SDL_Keycode south;
    SDL_Keycode east;
    SDL_Keycode left_shoulder;
    SDL_Keycode right_shoulder;
    SDL_Keycode left_trigger;
    SDL_Keycode right_trigger;
    SDL_Keycode left_stick;
    SDL_Keycode right_stick;
    SDL_Keycode back;
    SDL_Keycode start;
} Config_KeyboardMapping;

typedef struct Config_GamepadMapping {
    SDL_GamepadButton south;
    SDL_GamepadButton east;
    SDL_GamepadButton west;
    SDL_GamepadButton north;
    SDL_GamepadButton back;
    SDL_GamepadButton start;
    SDL_GamepadButton left_stick;
    SDL_GamepadButton right_stick;
    SDL_GamepadButton left_shoulder;
    SDL_GamepadButton right_shoulder;
    SDL_GamepadButton dpad_up;
    SDL_GamepadButton dpad_down;
    SDL_GamepadButton dpad_left;
    SDL_GamepadButton dpad_right;
} Config_GamepadMapping;

typedef struct Config {
    Config_Display display;
    Config_KeyboardMapping keyboard_mapping;
    Config_GamepadMapping gamepad_mapping;
} Config;

extern Config config;

void Config_Load();
void Config_Save();