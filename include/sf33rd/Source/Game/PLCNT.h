#ifndef PLCNT_H
#define PLCNT_H

#include "structs.h"
#include "types.h"

typedef struct /* @anon18 */ {
    // total size: 0x20
    s16 body_dm[4][4]; // offset 0x0, size 0x20
} RAMBOD;

typedef struct /* @anon20 */ {
    // total size: 0x20
    s16 hand_dm[4][4]; // offset 0x0, size 0x20
} RAMHAN;

extern const s8 plid_data[20]; // size: 0x14, address: 0x54B230

extern u8 pcon_dp_flag; // size: 0x1, address: 0x5795C0
extern s16 appear_type; // size: 0x2, address: 0x5795C8
extern s16 pcon_rno[4]; // size: 0x8, address: 0x5795D0

extern s16 pcon_rno[4];
extern s16 appear_type;
extern u8 round_slow_flag;
extern u8 pcon_dp_flag;
extern u8 win_sp_flag;
extern char dead_voice_flag;
extern SA_WORK super_arts[2];
extern PiyoriType piyori_type[2];
extern RAMBOD rambod[2];
extern RAMHAN ramhan[2];
extern u32 omop_spmv_ng_table[2];
extern u32 omop_spmv_ng_table2[2];
extern u16 vital_inc_timer;
extern u16 vital_dec_timer;
extern char cmd_sel[2];
extern s8 vib_sel[2]; // size: 0x2, address: 0x579488
extern s16 sag_inc_timer[2];
extern char no_sa[2];
extern ComboType combo_type[2];
extern ComboType remake_power[2];

extern PLW plw[2]; // size: 0x8D8, address: 0x5E4D20

extern const s16 **kizetsu_timer_table[];

void Player_control();
void reqPlayerDraw();
void erase_extra_plef_work();
void set_player_shadow(PLW *wk);
void clear_chainex_check(s16 ix);
void set_kizetsu_status(s16 ix);
void clear_kizetsu_point(PLW *wk);
void set_super_arts_status(s16 ix);
void clear_super_arts_point(PLW *wk);
s16 check_combo_end(s16 ix);
void set_quake(PLW *wk);
void add_next_position(PLW *wk);
void store_player_after_image_data();
void setup_base_and_other_data();
s32 check_sa_type_rebirth(PLW *wk);
void pli_0002();
void set_super_arts_status_dc(s16 ix);

#endif
