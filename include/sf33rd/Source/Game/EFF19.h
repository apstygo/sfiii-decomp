#ifndef EFF19_H
#define EFF19_H

#include "structs.h"
#include "types.h"

extern const s16 eff19_data_tbl[14];
extern const s8 eff19_wait_tbl[16];
extern const s8 effect_19_s_tbl[16];
extern const s8 effect_19_m_tbl[16];
extern const s8 effect_19_l_tbl[16];

void effect_19_move(WORK_Other *ewk);
void eff19_quake_sub(WORK_Other *ewk);
s32 effect_19_init();

#endif
