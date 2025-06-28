#ifndef TA_SUB_H
#define TA_SUB_H

#include "structs.h"
#include "types.h"

extern s16 eff_hit_flag[11];

void sync_fam_set3(s16 my_fam);
void win_lose_work_clear();
s32 obr_no_disp_check();
void disp_pos_trans_entry(WORK_Other *ewk);
void add_y_sub(WORK_Other *ewk);
void disp_pos_trans_entry5(WORK_Other *ewk);
void disp_pos_trans_entry_r(WORK_Other *ewk);
void disp_pos_trans_entry_s(WORK_Other *ewk);
void disp_pos_trans_entry_rs(WORK_Other *ewk);
void add_x_sub(WORK_Other *ewk);
s32 compel_dead_check(WORK_Other *ewk);
s32 range_x_check(WORK_Other *ewk);
s16 eff_hit_check(WORK_Other *ewk, s16 type);
s16 eff_hit_check2(WORK_Other *ewk, s16 type, s16 where_type);
s32 range_x_check3(WORK_Other *ewk, s16 optional_range);

#endif
