#include "sf33rd/Source/Game/HITCHECK.h"
#include "common.h"

// sbss
s16 grdb[2][2][2];
s16 grdb2[2][2];
s16 *dmdat_adrs[16];
WORK *q_hit_push[32];
s16 mkm_wk[32];
s16 hpq_in;
s8 ca_check_flag;

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", make_red_blocking_time);
#else
void make_red_blocking_time(s16 id, s16 ix, s16 num) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", hit_check_main_process);
#else
void hit_check_main_process() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", set_judge_result);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", check_result_extra);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", set_caught_status);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", check_pat_status);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", check_blocking_flag);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", setup_catch_atthit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", set_catch_hit_mark_pos);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", set_struck_status);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", cal_hit_mark_pos);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", Dsas_dir_table);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", plef_at_vs_player_damage_union);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", dm_reaction_init_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", set_guard_status);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", sel_sp_ch_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", sel_hs_add_tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", set_paring_status);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", check_normal_attack);
#else
s32 check_normal_attack(u8 waza) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", hit_pattern_extdat_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", check_dm_att_guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", check_dm_att_blocking);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", set_damage_and_piyo);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", remake_score_index);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", same_dm_stop);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", defense_sky);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", blocking_point_count_up);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", defense_ground);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", setup_dm_rl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", dm_status_copy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", add_combo_work);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", nise_combo_work);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", cal_combo_waribiki);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", cal_combo_waribiki2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", catch_hit_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", attack_hit_check);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", hit_check_subroutine);
#else
s16 hit_check_subroutine(WORK *wk1, WORK *wk2, const s16 *hd1, s16 *hd2) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", hit_check_x_only);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", cal_hit_mark_position);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", get_target_att_position);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", get_att_head_position);
#else
s16 get_att_head_position(WORK_Other *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", hit_push_request);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", clear_hit_queue);
#else
void clear_hit_queue() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", change_damage_attribute);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", get_sky_nm_damage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", get_sky_sp_damage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", get_kagami_damage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", get_grd_hand_damage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", check_head_damage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", check_trunk_damage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", check_ttk_damage_request);

const u16 chain_normal_ground_table[8] = { 0x760, 0x660, 0x640, 0x440, 0x400, 0x0, 0x0, 0x0 };
const u16 chain_hidou_nm_ground_table[8] = { 0x770, 0x770, 0x740, 0x470, 0x600, 0x60, 0x0, 0x0 };
const u16 chain_normal_air_table[8] = { 0x660, 0x660, 0x440, 0x440, 0x0, 0x0, 0x0, 0x0 };
const u16 chain_hidou_nm_air_table[8] = { 0x320, 0x220, 0x640, 0x440, 0x510, 0x110, 0x0, 0x0 };
const u8 plpat_rno_filter[16] = { 1, 9, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", rsix_r_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", attr_flame_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", attr_thunder_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", attr_freeze_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", sky_nm_damage_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", sky_sp_damage_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", kagami_damage_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", grd_hand_damage_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", hddm_damage_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", trdm_damage_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", ttk_damage_req_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", parisucc_pts);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/HITCHECK", dm_oiuchi_catch);
