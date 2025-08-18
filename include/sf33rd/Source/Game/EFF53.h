#ifndef EFF53_H
#define EFF53_H

#include "structs.h"
#include "types.h"

extern const s16 eff53_vanish_time[8];

void effect_53_move(WORK_Other *ewk);
s32 effect_53_init();

#endif
