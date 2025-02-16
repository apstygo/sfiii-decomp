#ifndef BG_DATA_H
#define BG_DATA_H

#include "structs.h"
#include "types.h"

extern const u8 stage_bgw_number[22][3]; // size: 0x42, address: 0x4E6FD0

extern s8 seraph_flag; // size: 0x1, address: 0x578C6C
extern MVXY bg_mvxy;   // size: 0x18, address: 0x578C80
extern s16 base_y_pos; // size: 0x2, address: 0x578CC4

#endif
