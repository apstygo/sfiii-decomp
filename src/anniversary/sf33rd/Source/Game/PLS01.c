#include "sf33rd/Source/Game/PLS01.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", sa_stop_check);
#else
s32 sa_stop_check() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_my_tk_power_off);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_em_tk_power_off);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_ukemi_flag);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_rl_flag);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", set_rl_waza);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_rl_on_car);
#else
s16 check_rl_on_car(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", saishin_bs2_area_car);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", saishin_bs2_on_car);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_air_jump);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_sankaku_tobi);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_extra_jump_timer);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", remake_sankaku_tobi_mvxy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_F_R_dash);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_jump_ready);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_hijump_only);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_bend_myself);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_F_R_walk);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_turn_to_back);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_hurimuki);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_walking_lv_dir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_stand_up);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_defense_lever);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_em_catt);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_attbox_dir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_defense_kind);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", jumping_union_process);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_floor);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_ashimoto);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_floor_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", check_ashimoto_ex);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", about_rno);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", sel_hd_fg_hos);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", dir32_rl_conv);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", dir32_sel_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS01", chcgp_hos);
