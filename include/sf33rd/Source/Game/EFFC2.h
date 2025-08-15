#ifndef EFFC2_H
#define EFFC2_H

#include "structs.h"
#include "types.h"

typedef struct {
    // total size: 0xC
    s16 dir_timer; // offset 0x0, size 0x2
    s16 chix;      // offset 0x2, size 0x2
    s16 vital;     // offset 0x4, size 0x2
    s16 color;     // offset 0x6, size 0x2
    s16 prio_hi;   // offset 0x8, size 0x2
    s16 prio_low;  // offset 0xA, size 0x2
} BS2;

void effect_C2_move(WORK_Other *ewk);
s32 effect_C2_init(WORK *wk, u8 data);

#endif
