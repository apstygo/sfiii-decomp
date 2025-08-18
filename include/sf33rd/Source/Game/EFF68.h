#ifndef EFF68_H
#define EFF68_H

#include "structs.h"
#include "types.h"

extern const s16 eff68_data_tbl[52];

void effect_68_move(WORK_Other *ewk);
s32 effect_68_init();

#endif
