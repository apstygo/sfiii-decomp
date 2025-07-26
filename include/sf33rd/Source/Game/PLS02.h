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
void setup_vitality(WORK *wk, s16 pno);
void add_sp_arts_gauge_init(PLW *wk);
void add_sp_arts_gauge_maxbit(PLW *wk);
void add_super_arts_gauge(SA_WORK *wk, s16 ix, s16 asag, u8 mf);
void add_to_mvxy_data(WORK *wk, u16 ix);
void setup_mvxy_data(WORK *wk, u16 ix);
void cal_mvxy_speed(WORK *wk);
void add_mvxy_speed(WORK *wk);
s32 set_field_hosei_flag(PLW *pl, s16 pos, s16 ix);
s16 check_work_position(WORK *p1, WORK *p2);
void setup_lvdir_after_autodir(PLW *wk);
void reset_mvxy_data(WORK *wk);
void remake_mvxy_PoSB(WORK *wk);
void check_body_touch();
void check_body_touch2();
s32 check_be_car_object();
s16 get_sel_hosei_tbl_ix(s16 plnum);
s16 check_work_position_bonus(WORK *hm, s16 tx);
void set_hit_stop_hit_quake(WORK *wk);
void add_sp_arts_gauge_paring(PLW *wk);
void add_sp_arts_gauge_nagenuke(PLW *wk);
void add_sp_arts_gauge_ukemi(PLW *wk);
s8 get_weight_point(WORK *wk);
void setup_butt_own_data(WORK *wk);
void add_mvxy_speed_direct(WORK *wk, s16 sx, s16 sy);
s16 check_buttobi_type(PLW *wk);
s16 check_buttobi_type2(PLW *wk);
void add_sp_arts_gauge_hit_dm(PLW *wk);
void add_sp_arts_gauge_tokushu(PLW *wk);

#endif
