#ifndef PLCNT_H
#define PLCNT_H

#include "structs.h"
#include "types.h"

typedef struct /* @anon19 */ {
    // total size: 0x2C
    s16 kind_of_arts; // offset 0x0, size 0x2
    u8 nmsa_g_ix;     // offset 0x2, size 0x1
    u8 exsa_g_ix;     // offset 0x3, size 0x1
    u8 exs2_g_ix;     // offset 0x4, size 0x1
    u8 nmsa_a_ix;     // offset 0x5, size 0x1
    u8 exsa_a_ix;     // offset 0x6, size 0x1
    u8 exs2_a_ix;     // offset 0x7, size 0x1
    char gauge_type;  // offset 0x8, size 0x1
    char mp;          // offset 0x9, size 0x1
    char ok;          // offset 0xA, size 0x1
    char ex;          // offset 0xB, size 0x1
    char ba;          // offset 0xC, size 0x1
    char dtm_mul;     // offset 0xD, size 0x1
    char mp_rno;      // offset 0xE, size 0x1
    char mp_rno2;     // offset 0xF, size 0x1
    char sa_rno;      // offset 0x10, size 0x1
    char sa_rno2;     // offset 0x11, size 0x1
    char ex_rno;      // offset 0x12, size 0x1
    char gt2;         // offset 0x13, size 0x1
    char saeff_ok;    // offset 0x14, size 0x1
    char saeff_mp;    // offset 0x15, size 0x1
    s16 gauge_len;    // offset 0x16, size 0x2
    union /* @anon44 */ {
        s32 i; // offset 0x0, size 0x4
        struct /* @anon45 */ {
            // total size: 0x4
            s16 l;   // offset 0x0, size 0x2
            s16 h;   // offset 0x2, size 0x2
        } s;         // offset 0x0, size 0x4
    } gauge;         // offset 0x18, size 0x4
    s32 dtm;         // offset 0x1C, size 0x4
    s16 store_max;   // offset 0x20, size 0x2
    s16 store;       // offset 0x22, size 0x2
    s16 id_arts;     // offset 0x24, size 0x2
    u8 ex4th_full;   // offset 0x26, size 0x1
    u8 ex4th_exec;   // offset 0x27, size 0x1
    s16 total_gauge; // offset 0x28, size 0x2
    s16 bacckup_g_h; // offset 0x2A, size 0x2
} PLCNT_SUPERART;

typedef struct /* @anon9 */ {
    // total size: 0x14
    char flag;  // offset 0x0, size 0x1
    s16 genkai; // offset 0x2, size 0x2
    s16 time;   // offset 0x4, size 0x2
    union /* @anon15 */ {
        s32 timer; // offset 0x0, size 0x4
        struct /* @anon16 */ {
            // total size: 0x4
            s16 l;  // offset 0x0, size 0x2
            s16 h;  // offset 0x2, size 0x2
        } quantity; // offset 0x0, size 0x4
    } now;          // offset 0x8, size 0x4
    s32 recover;    // offset 0xC, size 0x4
    s16 store;      // offset 0x10, size 0x2
    s16 again;      // offset 0x12, size 0x2
} PIYORI_TYPE;

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
extern PLCNT_SUPERART super_arts[2];
extern PIYORI_TYPE piyori_type[2];
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

#endif
