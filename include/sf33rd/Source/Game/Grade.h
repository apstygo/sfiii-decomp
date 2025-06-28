#ifndef GRADE_H
#define GRADE_H

#include "structs.h"
#include "types.h"

extern GradeFinalData judge_final[2][2]; // size: 0x2B0, address: 0x5E3070
extern GradeData judge_item[2][2];       // size: 0x130, address: 0x5E3320

s16 grade_get_my_grade(s16 ix);
void grade_check_work_1st_init(s32 ix, s32 ix2);
void grade_final_grade_bonus();
void grade_add_att_renew(WORK_Other *wk);
void grade_add_reversal(s16 ix);

#endif
