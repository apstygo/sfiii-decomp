#include "unknown.h"
#include "common.h"
#include "sf33rd/AcrSDK/common/mlPAD.h"

extern u32 ioconv_table[24][2];

void keyConvert(void) {
    typedef struct {
        u8 state;
        u8 anstate;
        u16 kind;
        u32 sw;
        u32 sw_old;
        u32 sw_new;
        u32 sw_off;
        u32 sw_chg;
        u32 sw_repeat;
        PAD_STICK stick[2];
    } IOPad;
    IOPad* pad;    
    u32 currSw;
    s32 i;
    s32 j;
    s32 repeat_on;

    repeat_on = 0;
    if ((Debug_w[0x2B]) && (mpp_w.inGame) && (Game_pause == 0)) {
        repeat_on = 1;
    }
    if ((save_w[Present_Mode].extra_option.contents[0][4]) && (mpp_w.inGame) && (Game_pause == 0)) {
        repeat_on = 1;
        if (((task[3].condition) == 1) && ((task[3].r_no[0]) != 0xA)) {
            repeat_on = 0;
        }
    }

    for (i = 0; i < 2; i++) {
        flPADSetRepeatSw(&(*flpad_adr)[i], 0xFF000FU, 0xFU, 3U);
        if (repeat_on) {
            flPADSetRepeatSw(&(*flpad_adr)[i], 0x3FF0U, 2U, 1U);
        } else {
            flPADSetRepeatSw(&(*flpad_adr)[i], 0x3FF0U, 0xAU, 2U);
        }
        pad = (IOPad *)&io_w.data[i];
        pad->state = (*flpad_adr)[i].state;
        pad->anstate = (*flpad_adr)[i].anstate;
        pad->kind = (*flpad_adr)[i].kind;
        pad->sw = (*flpad_adr)[i].sw;
        pad->sw_old = (*flpad_adr)[i].sw_old;
        pad->sw_new = (*flpad_adr)[i].sw_new;
        pad->sw_off = (*flpad_adr)[i].sw_off;
        pad->sw_chg = (*flpad_adr)[i].sw_chg;
        pad->sw_repeat = (*flpad_adr)[i].sw_repeat;
        pad->stick[0] = *(PAD_STICK*)(*flpad_adr)[i].stick;
        pad->stick[1] = *(PAD_STICK*)&(*flpad_adr)[i].stick[1];
        if (mpp_w.useAnalogStickData) {
            if (!((*flpad_adr)[i].sw & 0xF)) {
                pad->sw |= ((u32) pad->sw >> 0x10) & 0xF;
                pad->sw_old |= ((u32) pad->sw_old >> 0x10) & 0xF;
                pad->sw_new |= ((u32) pad->sw_new >> 0x10) & 0xF;
                pad->sw_off |= ((u32) pad->sw_off >> 0x10) & 0xF;
                pad->sw_chg |= ((u32) pad->sw_chg >> 0x10) & 0xF;
                pad->sw_repeat |= ((u32) pad->sw_repeat >> 0x10) & 0xF;
            }
            if (!((*flpad_adr)[i].sw & 0xF)) {
                pad->sw |= ((u32) pad->sw >> 0x14) & 0xF;
                pad->sw_old |= ((u32) pad->sw_old >> 0x14) & 0xF;
                pad->sw_new |= ((u32) pad->sw_new >> 0x14) & 0xF;
                pad->sw_off |= ((u32) pad->sw_off >> 0x14) & 0xF;
                pad->sw_chg |= ((u32) pad->sw_chg >> 0x14) & 0xF;
                pad->sw_repeat |= ((u32) pad->sw_repeat >> 0x14) & 0xF;
            }
        }
        if (pad->kind == 0 || pad->kind == 0x8000) {
            Interface_Type[i] = 0;
        } else {
            Interface_Type[i] = 2;
        }
        io_w.sw[i] = 0;
        currSw = pad->sw;
        
        for (j = 0; j < 4; j++) {
            if (currSw & ioconv_table[j][1]) {
                io_w.sw[i] |= ioconv_table[j][0];
            }
        }
        
        for (j = 0xC; j < 16; j++) {
            if (currSw & ioconv_table[j][1]) {
                io_w.sw[i] |= ioconv_table[j][0];
            }
        }
        
        if (repeat_on) {
            currSw = pad->sw_repeat;
        }
        
        for (j = 4; j < 12; j++) {
            if (currSw & ioconv_table[j][1]) {
                io_w.sw[i] |= ioconv_table[j][0];
            }
        }
    }
    p1sw_buff = io_w.sw[0];
    p2sw_buff = io_w.sw[1];
}
