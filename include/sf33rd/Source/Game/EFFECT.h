#ifndef EFFECT_H
#define EFFECT_H

#include "structs.h"
#include "types.h"

extern u32 frw[128][448];

void move_effect_work(s16 index);
void disp_effect_work();
void effect_work_init();
void effect_work_quick_init();
void effect_work_kill_mod_plcol();
void push_effect_work(WORK *wkhd);
s16 pull_effect_work(s16 index);

#endif
