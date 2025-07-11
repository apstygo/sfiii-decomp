#include "common.h"
#include "sf33rd/Source/Game/PLPAT.h"
#include "sf33rd/Source/Game/PLPCA.h"
#include "sf33rd/Source/Game/PLPCU.h"
#include "sf33rd/Source/Game/PLPDM.h"
#include "sf33rd/Source/Game/PLPNM.h"

void player_mv_0000(PLW *wk);
void player_mv_1000(PLW *wk);
void player_mv_2000(PLW *wk);
void player_mv_3000(PLW *wk);
void player_mv_4000(PLW *wk);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", Player_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", check_illegal_lever_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", player_mv_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", player_mv_1000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", plmv_1010);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", plmv_1020);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", player_mv_2000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", player_mv_3000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", player_mv_4000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", check_hit_stop);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", select_hit_stop);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", look_after_timers);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", about_gauge_process);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", mpg_union);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", eag_union);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", sag_union);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", addSAAttribute);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", demo_set_sa_full);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", get_saikinnno_idouryou);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", clear_attack_num);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", clear_tk_flags);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", check_omop_vital);

// INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", plmain_lv_00);

void (*const plmain_lv_00[5])(PLW *wk) = {
    player_mv_0000, player_mv_1000, player_mv_2000, player_mv_3000, player_mv_4000
};

// INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", plmain_lv_02);

void (*const plmain_lv_02[5])(PLW *wk) = { Player_normal, Player_damage, Player_catch, Player_caught, Player_attack };

// INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", plpnm_mvkind);

const u8 plpnm_mvkind[59] = { 0, 3, 3, 3, 3, 1, 1, 3, 3, 3, 3, 0, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3,
                              3, 2, 2, 2, 2, 2, 3, 3, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", plpdm_mvkind);

const u8 plpdm_mvkind[32] = { 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };

// INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLMAIN", plpxx_kind);

const u8 plpxx_kind[5] = { 0, 1, 0, 1, 0 };
