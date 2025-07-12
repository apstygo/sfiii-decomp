#include "sf33rd/Source/Game/PLCNT.h"
#include "common.h"

// bss
PLW plw[2];
ComboType combo_type[2];
ZanzouTableEntry zanzou_table[2][48];
ComboType remake_power[2];

// sbss
s16 pcon_rno[4];
s16 appear_type;
u8 round_slow_flag;
u8 pcon_dp_flag;
u8 win_sp_flag;
char dead_voice_flag;
PLCNT_SUPERART super_arts[2];
PIYORI_TYPE piyori_type[2];
RAMBOD rambod[2];
RAMHAN ramhan[2];
u32 omop_spmv_ng_table[2];
u32 omop_spmv_ng_table2[2];
u16 vital_inc_timer;
u16 vital_dec_timer;
char cmd_sel[2];
s8 vib_sel[2];
s16 sag_inc_timer[2];
char no_sa[2];

void plcnt_init();
void plcnt_move();
void plcnt_die();

void (*const player_main_process[3])() = { plcnt_init, plcnt_move, plcnt_die };

void init_app_10000();
void init_app_20000();
void init_app_30000();

void (*const appear_initalize[4])() = { init_app_10000, init_app_10000, init_app_20000, init_app_30000 };

void settle_type_00000();
void settle_type_10000();
void settle_type_20000();
void settle_type_30000();
void settle_type_40000();

void (*const settle_process[5])() = {
    settle_type_00000, settle_type_10000, settle_type_20000, settle_type_30000, settle_type_40000
};

const s8 plid_data[20] = { 6, 3, 5, 1, 2, 9, 7, 4, 10, 8, 12, 13, 14, 15, 16, 18, 19, 20, 21, 22 };

const s8 weight_lv_table[20] = { 2, 2, 1, 0, 1, 2, 3, 0, 1, 0, 0, 1, 1, 2, 1, 1, 1, 3, 2, 1 };

const s16 quake_table[64] = { 0, -1, 0, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -2, 1, -2, 1, -2, 1, -2, 1, -2,
                              1, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -2, 2, -3, 2, -3,
                              2, -3, 2, -3, 2, -3, 2, -3, 2, -3, 2, -3, 2, -3, 2, -3, 3, -3, 3, -3 };

const s16 kage_base[20][2] = { { 0, 21 },  { 0, 30 },  { 0, 21 },  { -4, 16 }, { 4, 21 }, { 6, 20 }, { -4, 26 },
                               { -4, 20 }, { 0, 25 },  { -3, 22 }, { -4, 16 }, { 0, 21 }, { 0, 21 }, { 0, 21 },
                               { 0, 21 },  { -8, 21 }, { 0, 23 },  { 0, 24 },  { 6, 25 }, { -6, 21 } };

// TODO: rename to super_arts_data
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", _super_arts_data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", super_arts_DATA);

const s16 pl_piyo_tbl[20] = { 72, 72, 64, 64, 72, 64, 72, 64, 64, 72, 64, 64, 64, 64, 56, 64, 64, 72, 64, 56 };

const s32 pl_nr_piyo_tbl[20] = { 3276, 2849, 2978, 2730, 2978, 2849, 3120, 2730, 2978, 2730,
                                 2730, 2978, 2849, 3120, 2849, 2978, 3276, 2978, 2849, 3120 };

const s16 tsuujyou_dageki_00[16] = { 150, 150, 130, 130, 130, 110, 110, 110, 110, 110, 90, 90, 90, 90, 90, 90 };
const s16 tsuujyou_dageki_01[16] = { 150, 150, 150, 150, 130, 130, 130, 130, 110, 110, 110, 110, 90, 90, 90, 90 };
const s16 tsuujyou_dageki_02[16] = { 150, 150, 150, 150, 150, 150, 130, 130, 130, 130, 130, 110, 110, 110, 90, 90 };

const s16 *tsuujyou_dageki[4] = { tsuujyou_dageki_00, tsuujyou_dageki_01, tsuujyou_dageki_02, tsuujyou_dageki_02 };

const s16 hissatsu_dageki_00[16] = { 210, 210, 190, 190, 190, 170, 170, 170, 170, 170, 150, 150, 150, 150, 150, 150 };
const s16 hissatsu_dageki_01[16] = { 210, 210, 210, 210, 190, 190, 190, 190, 170, 170, 170, 170, 150, 150, 150, 150 };
const s16 hissatsu_dageki_02[16] = { 210, 210, 210, 210, 210, 210, 190, 190, 190, 190, 190, 170, 170, 170, 150, 150 };

const s16 *hissatsu_dageki[4] = {
    hissatsu_dageki_00,
    hissatsu_dageki_01,
    hissatsu_dageki_02,
    hissatsu_dageki_02,
};

const s16 tsuujyou_nage_00[16] = { 180, 180, 160, 160, 160, 140, 140, 140, 140, 140, 120, 120, 120, 120, 120, 120 };
const s16 tsuujyou_nage_01[16] = { 180, 180, 180, 180, 160, 160, 160, 160, 140, 140, 140, 140, 120, 120, 120, 120 };
const s16 tsuujyou_nage_02[16] = { 180, 180, 180, 180, 180, 180, 160, 160, 160, 160, 160, 140, 140, 140, 120, 120 };

const s16 *tsuujyou_nage[4] = { tsuujyou_nage_00, tsuujyou_nage_01, tsuujyou_nage_02, tsuujyou_nage_02 };

const s16 hissatsu_nage_00[16] = { 240, 240, 200, 200, 200, 160, 160, 160, 160, 160, 120, 120, 120, 120, 120, 120 };
const s16 hissatsu_nage_01[16] = { 240, 240, 240, 240, 200, 200, 200, 200, 160, 160, 160, 160, 120, 120, 120, 120 };
const s16 hissatsu_nage_02[16] = { 240, 240, 240, 240, 240, 240, 200, 200, 200, 200, 200, 160, 160, 160, 120, 120 };

const s16 *hissatsu_nage[4] = { hissatsu_nage_00, hissatsu_nage_01, hissatsu_nage_02, hissatsu_nage_02 };

const s16 super_arts_dageki_00[16] = { 240, 240, 200, 200, 200, 160, 160, 160, 160, 160, 120, 120, 120, 120, 120, 120 };
const s16 super_arts_dageki_01[16] = { 240, 240, 240, 240, 200, 200, 200, 200, 160, 160, 160, 160, 120, 120, 120, 120 };
const s16 super_arts_dageki_02[16] = { 240, 240, 240, 240, 240, 240, 200, 200, 200, 200, 200, 160, 160, 160, 120, 120 };

const s16 *super_arts_dageki[4] = {
    super_arts_dageki_00, super_arts_dageki_01, super_arts_dageki_02, super_arts_dageki_02
};

const s16 super_arts_nage_00[16] = { 270, 270, 230, 230, 230, 190, 190, 190, 190, 190, 150, 150, 150, 150, 150, 150 };
const s16 super_arts_nage_01[16] = { 270, 270, 270, 270, 230, 230, 230, 230, 190, 190, 190, 190, 150, 150, 150, 150 };
const s16 super_arts_nage_02[16] = { 270, 270, 270, 270, 270, 270, 230, 230, 230, 230, 230, 190, 190, 190, 150, 150 };

const s16 *super_arts_nage[4] = { super_arts_nage_00, super_arts_nage_01, super_arts_nage_02, super_arts_nage_02 };

const s16 **kizetsu_timer_table[9] = { tsuujyou_dageki,   hissatsu_dageki,   tsuujyou_nage,
                                       hissatsu_nage,     super_arts_dageki, super_arts_nage,
                                       super_arts_dageki, super_arts_nage,   super_arts_dageki };

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", Player_control);
#else
void Player_control() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", reqPlayerDraw);
#else
void reqPlayerDraw() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", plcnt_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", init_app_10000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", init_app_20000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", init_app_30000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", pli_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", pli_1000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", pli_0002);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", plcnt_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", plcnt_die);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", settle_type_00000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", settle_type_10000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", settle_type_20000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", settle_type_30000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", settle_type_40000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", move_player_work);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", move_P1_move_P2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", move_P2_move_P1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", store_player_after_image_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", check_damage_hosei);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", check_damage_hosei_nage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", check_damage_hosei_dageki);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", time_over_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", will_die);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", setup_settle_rno);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", settle_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", check_sa_resurrection);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", check_sa_type_rebirth);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", nekorobi_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", footwork_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", set_quake);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", add_next_position);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", setup_gouki_wins);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", erase_extra_plef_work);
#else
void erase_extra_plef_work() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", setup_base_and_other_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", setup_any_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", set_base_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", set_base_data_metamorphose);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", set_base_data_tiny);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", set_player_shadow);
#else
void set_player_shadow(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", setup_other_data);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", clear_chainex_check);
#else
void clear_chainex_check(s16 ix) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", set_kizetsu_status);
#else
void set_kizetsu_status(s16 ix) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", clear_kizetsu_point);
#else
void clear_kizetsu_point(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", set_super_arts_status);
#else
void set_super_arts_status(s16 ix) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", remake_sa_store_max);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", remake_sa_gauge_len);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", set_super_arts_status_dc);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", clear_super_arts_point);
#else
void clear_super_arts_point(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", check_combo_end);
#else
s16 check_combo_end(s16 ix) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", set_scrrrl);
