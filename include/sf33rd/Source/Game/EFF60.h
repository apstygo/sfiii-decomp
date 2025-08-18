#ifndef EFF60_H
#define EFF60_H

#include "structs.h"
#include "types.h"

extern const s16 flash_0000[10];
extern const s16 flash_0001[10];
extern const s16 flash_0002[10];
extern const s16 *flash_obj_data61[3];

void effect_60_move(WORK_Other *ewk);
s32 effect_60_init(s16 type);

#endif
