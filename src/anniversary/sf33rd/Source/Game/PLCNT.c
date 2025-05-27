#include "sf33rd/Source/Game/PLCNT.h"
#include "common.h"

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

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", player_main_process);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", appear_initalize);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", settle_process);

const s8 plid_data[20] = { 6, 3, 5, 1, 2, 9, 7, 4, 10, 8, 12, 13, 14, 15, 16, 18, 19, 20, 21, 22 };

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", weight_lv_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", quake_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", kage_base);

// TODO: rename to super_arts_data
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", _super_arts_data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", super_arts_DATA);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", pl_piyo_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", pl_nr_piyo_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", tsuujyou_dageki_00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", tsuujyou_dageki_01);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", tsuujyou_dageki_02);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", hissatsu_dageki_00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", hissatsu_dageki_01);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", hissatsu_dageki_02);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", tsuujyou_nage_00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", tsuujyou_nage_01);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", tsuujyou_nage_02);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", hissatsu_nage_00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", hissatsu_nage_01);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", hissatsu_nage_02);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", super_arts_dageki_00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", super_arts_dageki_01);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", super_arts_dageki_02);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", super_arts_nage_00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", super_arts_nage_01);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", super_arts_nage_02);

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

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", set_player_shadow);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", setup_other_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", clear_chainex_check);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", set_kizetsu_status);
#else
void set_kizetsu_status(s16 ix) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", clear_kizetsu_point);

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

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", clear_super_arts_point);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", check_combo_end);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT", set_scrrrl);
