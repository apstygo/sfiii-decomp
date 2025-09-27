#include "port/config.h"
#include "port/ini.h"
#include <stdio.h>
#include <string.h>

Config config;

static const char* CONFIG_FILE = "config.ini";

static void set_default_keyboard_mapping() {
    config.keyboard_mapping.dpad_up = SDLK_W;
    config.keyboard_mapping.dpad_down = SDLK_S;
    config.keyboard_mapping.dpad_left = SDLK_A;
    config.keyboard_mapping.dpad_right = SDLK_D;
    config.keyboard_mapping.north = SDLK_I;
    config.keyboard_mapping.west = SDLK_J;
    config.keyboard_mapping.south = SDLK_K;
    config.keyboard_mapping.east = SDLK_L;
    config.keyboard_mapping.left_shoulder = SDLK_Q;
    config.keyboard_mapping.right_shoulder = SDLK_E;
    config.keyboard_mapping.left_trigger = SDLK_1;
    config.keyboard_mapping.right_trigger = SDLK_3;
    config.keyboard_mapping.left_stick = SDLK_2;
    config.keyboard_mapping.right_stick = SDLK_4;
    config.keyboard_mapping.back = SDLK_BACKSPACE;
    config.keyboard_mapping.start = SDLK_RETURN;
}

static void set_default_gamepad_mapping() {
    config.gamepad_mapping.south = SDL_GAMEPAD_BUTTON_SOUTH;
    config.gamepad_mapping.east = SDL_GAMEPAD_BUTTON_EAST;
    config.gamepad_mapping.west = SDL_GAMEPAD_BUTTON_WEST;
    config.gamepad_mapping.north = SDL_GAMEPAD_BUTTON_NORTH;
    config.gamepad_mapping.back = SDL_GAMEPAD_BUTTON_BACK;
    config.gamepad_mapping.start = SDL_GAMEPAD_BUTTON_START;
    config.gamepad_mapping.left_stick = SDL_GAMEPAD_BUTTON_LEFT_STICK;
    config.gamepad_mapping.right_stick = SDL_GAMEPAD_BUTTON_RIGHT_STICK;
    config.gamepad_mapping.left_shoulder = SDL_GAMEPAD_BUTTON_LEFT_SHOULDER;
    config.gamepad_mapping.right_shoulder = SDL_GAMEPAD_BUTTON_RIGHT_SHOULDER;
    config.gamepad_mapping.dpad_up = SDL_GAMEPAD_BUTTON_DPAD_UP;
    config.gamepad_mapping.dpad_down = SDL_GAMEPAD_BUTTON_DPAD_DOWN;
    config.gamepad_mapping.dpad_left = SDL_GAMEPAD_BUTTON_DPAD_LEFT;
    config.gamepad_mapping.dpad_right = SDL_GAMEPAD_BUTTON_DPAD_RIGHT;
}

static void set_default_config() {
    set_default_keyboard_mapping();
    set_default_gamepad_mapping();
}

static int handler(void* user, const char* section, const char* name, const char* value) {
    Config* pconfig = (Config*)user;

    #define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0

    if (MATCH("Keyboard", "dpad_up")) { pconfig->keyboard_mapping.dpad_up = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "dpad_down")) { pconfig->keyboard_mapping.dpad_down = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "dpad_left")) { pconfig->keyboard_mapping.dpad_left = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "dpad_right")) { pconfig->keyboard_mapping.dpad_right = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "north")) { pconfig->keyboard_mapping.north = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "west")) { pconfig->keyboard_mapping.west = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "south")) { pconfig->keyboard_mapping.south = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "east")) { pconfig->keyboard_mapping.east = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "left_shoulder")) { pconfig->keyboard_mapping.left_shoulder = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "right_shoulder")) { pconfig->keyboard_mapping.right_shoulder = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "left_trigger")) { pconfig->keyboard_mapping.left_trigger = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "right_trigger")) { pconfig->keyboard_mapping.right_trigger = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "left_stick")) { pconfig->keyboard_mapping.left_stick = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "right_stick")) { pconfig->keyboard_mapping.right_stick = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "back")) { pconfig->keyboard_mapping.back = SDL_GetKeyFromName(value); }
    else if (MATCH("Keyboard", "start")) { pconfig->keyboard_mapping.start = SDL_GetKeyFromName(value); }
    else if (MATCH("Gamepad", "south")) { pconfig->gamepad_mapping.south = SDL_GetGamepadButtonFromString(value); }
    else if (MATCH("Gamepad", "east")) { pconfig->gamepad_mapping.east = SDL_GetGamepadButtonFromString(value); }
    else if (MATCH("Gamepad", "west")) { pconfig->gamepad_mapping.west = SDL_GetGamepadButtonFromString(value); }
    else if (MATCH("Gamepad", "north")) { pconfig->gamepad_mapping.north = SDL_GetGamepadButtonFromString(value); }
    else if (MATCH("Gamepad", "back")) { pconfig->gamepad_mapping.back = SDL_GetGamepadButtonFromString(value); }
    else if (MATCH("Gamepad", "start")) { pconfig->gamepad_mapping.start = SDL_GetGamepadButtonFromString(value); }
    else if (MATCH("Gamepad", "left_stick")) { pconfig->gamepad_mapping.left_stick = SDL_GetGamepadButtonFromString(value); }
    else if (MATCH("Gamepad", "right_stick")) { pconfig->gamepad_mapping.right_stick = SDL_GetGamepadButtonFromString(value); }
    else if (MATCH("Gamepad", "left_shoulder")) { pconfig->gamepad_mapping.left_shoulder = SDL_GetGamepadButtonFromString(value); }
    else if (MATCH("Gamepad", "right_shoulder")) { pconfig->gamepad_mapping.right_shoulder = SDL_GetGamepadButtonFromString(value); }
    else if (MATCH("Gamepad", "dpad_up")) { pconfig->gamepad_mapping.dpad_up = SDL_GetGamepadButtonFromString(value); }
    else if (MATCH("Gamepad", "dpad_down")) { pconfig->gamepad_mapping.dpad_down = SDL_GetGamepadButtonFromString(value); }
    else if (MATCH("Gamepad", "dpad_left")) { pconfig->gamepad_mapping.dpad_left = SDL_GetGamepadButtonFromString(value); }
    else if (MATCH("Gamepad", "dpad_right")) { pconfig->gamepad_mapping.dpad_right = SDL_GetGamepadButtonFromString(value); }
    else { return 0; /* unknown section/name, error */ }

    return 1;
}

void Config_Load() {
    set_default_config();
    if (ini_parse(CONFIG_FILE, handler, &config) < 0) {
        printf("Can't load 'config.ini', creating default\n");
        Config_Save();
    }
}

void Config_Save() {
    FILE* fp = fopen(CONFIG_FILE, "w");
    if (!fp) {
        fprintf(stderr, "Could not open config.ini for writing\n");
        return;
    }

    fprintf(fp, "[Keyboard]\n");
    fprintf(fp, "dpad_up = %s\n", SDL_GetKeyName(config.keyboard_mapping.dpad_up));
    fprintf(fp, "dpad_down = %s\n", SDL_GetKeyName(config.keyboard_mapping.dpad_down));
    fprintf(fp, "dpad_left = %s\n", SDL_GetKeyName(config.keyboard_mapping.dpad_left));
    fprintf(fp, "dpad_right = %s\n", SDL_GetKeyName(config.keyboard_mapping.dpad_right));
    fprintf(fp, "north = %s\n", SDL_GetKeyName(config.keyboard_mapping.north));
    fprintf(fp, "west = %s\n", SDL_GetKeyName(config.keyboard_mapping.west));
    fprintf(fp, "south = %s\n", SDL_GetKeyName(config.keyboard_mapping.south));
    fprintf(fp, "east = %s\n", SDL_GetKeyName(config.keyboard_mapping.east));
    fprintf(fp, "left_shoulder = %s\n", SDL_GetKeyName(config.keyboard_mapping.left_shoulder));
    fprintf(fp, "right_shoulder = %s\n", SDL_GetKeyName(config.keyboard_mapping.right_shoulder));
    fprintf(fp, "left_trigger = %s\n", SDL_GetKeyName(config.keyboard_mapping.left_trigger));
    fprintf(fp, "right_trigger = %s\n", SDL_GetKeyName(config.keyboard_mapping.right_trigger));
    fprintf(fp, "left_stick = %s\n", SDL_GetKeyName(config.keyboard_mapping.left_stick));
    fprintf(fp, "right_stick = %s\n", SDL_GetKeyName(config.keyboard_mapping.right_stick));
    fprintf(fp, "back = %s\n", SDL_GetKeyName(config.keyboard_mapping.back));
    fprintf(fp, "start = %s\n", SDL_GetKeyName(config.keyboard_mapping.start));

    fprintf(fp, "\n[Gamepad]\n");
    fprintf(fp, "south = %s\n", SDL_GetGamepadStringForButton(config.gamepad_mapping.south));
    fprintf(fp, "east = %s\n", SDL_GetGamepadStringForButton(config.gamepad_mapping.east));
    fprintf(fp, "west = %s\n", SDL_GetGamepadStringForButton(config.gamepad_mapping.west));
    fprintf(fp, "north = %s\n", SDL_GetGamepadStringForButton(config.gamepad_mapping.north));
    fprintf(fp, "back = %s\n", SDL_GetGamepadStringForButton(config.gamepad_mapping.back));
    fprintf(fp, "start = %s\n", SDL_GetGamepadStringForButton(config.gamepad_mapping.start));
    fprintf(fp, "left_stick = %s\n", SDL_GetGamepadStringForButton(config.gamepad_mapping.left_stick));
    fprintf(fp, "right_stick = %s\n", SDL_GetGamepadStringForButton(config.gamepad_mapping.right_stick));
    fprintf(fp, "left_shoulder = %s\n", SDL_GetGamepadStringForButton(config.gamepad_mapping.left_shoulder));
    fprintf(fp, "right_shoulder = %s\n", SDL_GetGamepadStringForButton(config.gamepad_mapping.right_shoulder));
    fprintf(fp, "dpad_up = %s\n", SDL_GetGamepadStringForButton(config.gamepad_mapping.dpad_up));
    fprintf(fp, "dpad_down = %s\n", SDL_GetGamepadStringForButton(config.gamepad_mapping.dpad_down));
    fprintf(fp, "dpad_left = %s\n", SDL_GetGamepadStringForButton(config.gamepad_mapping.dpad_left));
    fprintf(fp, "dpad_right = %s\n", SDL_GetGamepadStringForButton(config.gamepad_mapping.dpad_right));

    fclose(fp);
}