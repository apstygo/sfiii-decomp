#include "common.h"
#include "port/sdl/sdl_pad.h"

#include <libpad2.h>

#include <string.h>

int scePad2Init(int mode) {
    // Do nothing
    return 1;
}

int scePad2End(void) {
    not_implemented(__func__);
}

int scePad2GetState(int socket_number) {
    return SDLPad_IsGamepadConnected(socket_number) ? scePad2StateStable : scePad2StateNoLink;
}

int scePad2GetButtonProfile(int socket_number, unsigned char *profile) {
    // Profile for Digital controller
    // profile[0] = 0xF9;
    // profile[1] = 0xFF;
    // profile[2] = 0;
    // profile[3] = 0;

    // Profile for Dualshock 2
    profile[0] = 0xFF;
    profile[1] = 0xFF;
    profile[2] = 0xFF;
    profile[3] = 0xFF;

    return 4;
}

int scePad2Read(int socket_number, scePad2ButtonState *data) {
    memset(data, 0, sizeof(scePad2ButtonState));

    SDLPad_ButtonState button_state;
    SDLPad_GetButtonState(socket_number, &button_state);

    // sw0 and sw1 store the pressed state of each button as bits.
    // 0 = pressed, 1 = released

    data->sw0.byte = 0xFF;
    data->sw1.byte = 0xFF;

    data->sw0.bits.l3 = !button_state.left_stick;
    data->sw0.bits.r3 = !button_state.right_stick;
    data->sw0.bits.select = !button_state.back;
    data->sw0.bits.start = !button_state.start;
    data->sw0.bits.left = !button_state.dpad_left;
    data->sw0.bits.right = !button_state.dpad_right;
    data->sw0.bits.up = !button_state.dpad_up;
    data->sw0.bits.down = !button_state.dpad_down;

    data->sw1.bits.l1 = !button_state.left_shoulder;
    data->sw1.bits.r1 = !button_state.right_shoulder;
    data->sw1.bits.l2 = button_state.left_trigger == 0;
    data->sw1.bits.r2 = button_state.right_trigger == 0;
    data->sw1.bits.cross = !button_state.south;
    data->sw1.bits.circle = !button_state.east;
    data->sw1.bits.square = !button_state.west;
    data->sw1.bits.triangle = !button_state.north;

    // This sets stick positions
    // (Sticks are not supported yet, that's why we just set positions to neutral)

    data->lJoyH = 0x7F;
    data->lJoyV = 0x7F;
    data->rJoyH = 0x7F;
    data->rJoyV = 0x7F;

    // This sets button pressure

    data->crossP = button_state.south ? 0xFF : 0;
    data->circleP = button_state.east ? 0xFF : 0;
    data->squareP = button_state.west ? 0xFF : 0;
    data->triangleP = button_state.north ? 0xFF : 0;
    data->upP = button_state.dpad_up ? 0xFF : 0;
    data->downP = button_state.dpad_down ? 0xFF : 0;
    data->leftP = button_state.dpad_left ? 0xFF : 0;
    data->rightP = button_state.dpad_right ? 0xFF : 0;

    return sizeof(scePad2ButtonState);
}

int scePad2CreateSocket(scePad2SocketParam *socket, void *addr) {
    return socket->port;
}

int scePad2DeleteSocket(int) {
    not_implemented(__func__);
}

int sceVibGetProfile(int socket_number, unsigned char *profile) {
    profile[0] = 3; // Small and big motor
    return 1;
}

int sceVibSetActParam(int, int, unsigned char *, int, unsigned char *) {
    not_implemented(__func__);
}
