#ifndef BG_DATA_H
#define BG_DATA_H

#include "structs.h"
#include "types.h"

extern const u8 stage_bgw_number[22][3]; // size: 0x42, address: 0x4E6FD0

extern s16 scrn_adgjust_y; // size: 0x2, address: 0x578C50
extern s16 scrn_adgjust_x; // size: 0x2, address: 0x578C54
extern u16 zoom_add;       // size: 0x2, address: 0x578C58
extern s8 bg_app;          // size: 0x1, address: 0x578C60
extern s8 sa_pa_flag;      // size: 0x1, address: 0x578C64
extern s8 aku_flag;        // size: 0x1, address: 0x578C68
extern s8 seraph_flag;     // size: 0x1, address: 0x578C6C
extern s8 akebono_flag;    // size: 0x1, address: 0x578C70
extern MVXY bg_mvxy;       // size: 0x18, address: 0x578C80
extern BGW *bgw_ptr;       // size: 0x4, address: 0x578CB8
extern s8 bg_app_stop;     // size: 0x1, address: 0x578CBC
extern s16 bg_stop;        // size: 0x2, address: 0x578CC0
extern s16 base_y_pos;     // size: 0x2, address: 0x578CC4

#endif
