#ifndef EFF71_H
#define EFF71_H

#include "structs.h"
#include "types.h"

extern const s16 eff71_time_tbl[8];

void effect_71_move(WORK_Other *ewk);
s32 effect_71_init();

#endif
