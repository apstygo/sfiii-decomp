#ifndef EFF21_H
#define EFF21_H

#include "types.h"

extern const s16 eff21_num[1];
extern const s32 eff21_sp_tbl[1][2];
extern const s16 eff21_data_tbl_00[27];
extern const s16 *eff21_data_adrs[1];

s32 effect_21_init(s16 sync_index);

#endif
