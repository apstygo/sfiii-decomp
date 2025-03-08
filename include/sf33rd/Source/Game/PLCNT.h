#ifndef PLCNT_H
#define PLCNT_H

#include "structs.h"
#include "types.h"

extern const s8 plid_data[20]; // size: 0x14, address: 0x54B230

extern u8 pcon_dp_flag; // size: 0x1, address: 0x5795C0
extern s16 appear_type; // size: 0x2, address: 0x5795C8
extern s16 pcon_rno[4]; // size: 0x8, address: 0x5795D0

extern PLW plw[2]; // size: 0x8D8, address: 0x5E4D20

void Player_control();
void reqPlayerDraw();
void erase_extra_plef_work();
void set_kizetsu_status(s16 ix);
void set_super_arts_status(s16 ix);

#endif
