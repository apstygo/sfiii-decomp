#ifndef PLS02_H
#define PLS02_H

#include "structs.h"
#include "types.h"

extern const s16 satse[20];

s32 random_16();
s32 random_16_com();
s32 random_16_ex_com();
s32 random_32_com();
s32 random_32_ex_com();
s16 cal_attdir(WORK *wk);
void add_sp_arts_gauge_init(PLW *wk);
void add_super_arts_gauge(SA_WORK *wk, s16 ix, s16 asag, u8 mf);
void setup_mvxy_data(WORK *wk, u16 ix);
void cal_mvxy_speed(WORK *wk);
void add_mvxy_speed(WORK *wk);
s32 set_field_hosei_flag(PLW *pl, s16 pos, s16 ix);

#endif
