#ifndef PLS02_H
#define PLS02_H

#include "structs.h"
#include "types.h"

s32 random_16();
s16 cal_attdir(WORK *wk);
void add_sp_arts_gauge_init(PLW *wk);
void add_super_arts_gauge(SA_WORK *wk, s32 ix, s32 asag, u16 mf);

#endif
