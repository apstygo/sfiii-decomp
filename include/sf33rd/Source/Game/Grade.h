#ifndef GRADE_H
#define GRADE_H

#include "structs.h"
#include "types.h"

extern GradeData judge_item[2][2];

s16 grade_get_my_grade(s16 ix);
void grade_check_work_1st_init(s32 ix, s32 ix2);
void grade_final_grade_bonus();
void grade_add_att_renew(WORK_Other *wk);

#endif
