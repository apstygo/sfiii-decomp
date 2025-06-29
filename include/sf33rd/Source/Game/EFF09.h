#ifndef EFF09_H
#define EFF09_H

#include "structs.h"
#include "types.h"

#include "common.h"

extern const s16 eff09_data[2][9];
extern const s16 eff09_data2[43][8];
extern const s32 eff09_2000_data[2][4];
extern const s32 eff09_add_tbl0[2][2];
extern const s32 eff09_add_tbl1[2][2];
extern const s32 eff09_add_tbl2[2][2];
extern const s16 sean_ball_hit[4];
extern const s32 eff09_13_tbl[3][4];
extern const s32 eff09_19000_tbl[3][4];

void effect_09_move(WORK_Other *ewk);
void eff09_0000(WORK_Other *ewk);
void eff09_1000(WORK_Other *ewk);
void eff09_2000(WORK_Other *ewk);
void sean_ball_move(WORK_Other *ewk);
void ball_bound_set(WORK_Other *ewk);
void eff09_3000(WORK_Other *ewk);
void eff09_4000(WORK_Other *ewk);
void eff09_5000(WORK_Other *ewk);
void eff09_6000(WORK_Other *ewk);
void eff09_7000(WORK_Other *ewk);
void eff09_8000(WORK_Other *ewk);
void eff09_9000(WORK_Other *ewk);
void eff09_10000(WORK_Other *ewk);
void eff09_11000(WORK_Other *ewk);
void eff09_12000(WORK_Other *ewk);
void eff09_13000(WORK_Other *ewk);
void eff09_14000(WORK_Other *ewk);
void eff09_15000(WORK_Other *ewk);
void eff09_16000(WORK_Other *ewk);
void eff09_17000(WORK_Other *ewk);
void eff09_18000(WORK_Other *ewk);
void eff09_19000(WORK_Other *ewk);
void eff09_20000(WORK_Other *ewk);
void eff09_21000(WORK_Other *ewk);
void eff09_22000(WORK_Other *ewk);
void eff09_23000(WORK_Other *ewk);
void eff09_24000(WORK_Other *ewk);
void eff09_25000(WORK_Other *ewk);
void eff09_26000(WORK_Other *ewk);
void jijii_win_tama_sub(WORK_Other *ewk);
void eff09_27000(WORK_Other *ewk);
s32 effect_09_init(WORK *wk, u8 data);
s32 effect_09_init2(WORK *wk, u8 data);

#endif
