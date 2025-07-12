#ifndef PLS01_H
#define PLS01_H

#include "structs.h"
#include "types.h"

s32 sa_stop_check();
void check_em_tk_power_off(PLW *wk, PLW *tk);
s16 check_ukemi_flag(PLW *wk);
s16 check_rl_on_car(PLW *wk);
void check_extra_jump_timer(PLW *wk);
void jumping_union_process(WORK *wk, s16 num);

#endif
