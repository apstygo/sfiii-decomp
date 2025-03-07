#include "sf33rd/Source/Game/PLS02.h"
#include "common.h"
#include "sf33rd/Source/Game/debug/Debug.h"
#include "sf33rd/Source/Game/workuser.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", asagh_zuru);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", sel_hosei_tbl_ix);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", satse);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_32);

const s16 random_tbl_16[64] = { 3,  8, 6,  9, 14, 13, 9,  5, 10, 14, 1,  7, 4,  15, 2,  0, 12, 15, 5, 13, 6,  3,
                                11, 8, 0,  3, 11, 10, 1,  7, 11, 4,  5,  4, 13, 2,  11, 9, 7,  10, 1, 6,  12, 9,
                                14, 0, 15, 2, 13, 1,  15, 8, 0,  6,  14, 3, 12, 8,  4,  5, 10, 2,  7, 12 };

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_32_ex);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_16_ex);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_32_com);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_16_com);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_32_ex_com);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_16_ex_com);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_tbl_16_bg);

const s16 dir16_rl_conv[16] = { 0, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_to_mvxy_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", setup_move_data_easy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", setup_mvxy_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", setup_butt_own_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", read_adrs_store_mvxy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", get_weight_point);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", cal_mvxy_speed);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_mvxy_speed);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_mvxy_speed_exp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_mvxy_speed_no_use_rl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_mvxy_speed_direct);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", reset_mvxy_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", remake_mvxy_PoSB);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", remake_mvxy_PoGR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", check_body_touch);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", meri_case_switch);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", check_body_touch2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", check_be_car_object);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", hoseishitemo_eenka);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", get_sel_hosei_tbl_ix);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", check_work_position_bonus);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", set_field_hosei_flag);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", check_work_position);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_32);

s32 random_16() {
    Random_ix16 += 1;

    if (Debug_w[0x3B] == 0xE0) {
        Random_ix16 = 0;
    }

    Random_ix16 &= 0x3F;
    return random_tbl_16[Random_ix16];
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_32_ex);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_16_ex);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_32_com);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_16_com);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_32_ex_com);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_16_ex_com);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", random_16_bg);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", get_guard_direction);

s16 cal_attdir(WORK *wk) {
    s16 resdir = wk->att.dir;

    if (wk->rl_flag) {
        resdir = dir16_rl_conv[resdir];
    }

    return resdir;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", cal_attdir_flip);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", get_kind_of_head_dm);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", get_kind_of_trunk_dm);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", setup_vitality);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", cal_dm_vital_gauge_hosei);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", set_hit_stop_hit_quake);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_hit_dm);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", cal_sa_gauge_waribiki);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_paring);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_tokushu);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_ukemi);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_nagenuke);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_sp_arts_gauge_maxbit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", add_super_arts_gauge);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", check_buttobi_type);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", check_buttobi_type2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", setup_saishin_lvdir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", setup_lvdir_after_autodir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", dead_voice_request);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", dead_voice_request2);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", dir16_hddm);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", dir16_trdm);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", konjyou_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", apagt_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", dir32_skydm);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", dir32_grddm);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", convert_saishin_lvdir);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS02", dead_voice_table);
