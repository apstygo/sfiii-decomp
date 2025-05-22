#ifndef PULPUL_H
#define PULPUL_H

#include "structs.h"
#include "types.h"

extern PPWORK ppwork[2]; // size: 0x68, address: 0x579610

void init_pulpul_work();
void pulpul_stop();
void pulpul_stop2(s32 ix);
void pp_vib_on(s32 id);
void pp_operator_check_flag(u8 fl);
void move_pulpul_work();
void pp_screen_quake(s16 ix);  

#endif
