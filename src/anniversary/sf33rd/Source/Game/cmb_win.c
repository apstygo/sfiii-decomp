#include "sf33rd/Source/Game/cmb_win.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", cmb_pos_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", cmb_window_move_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", cmb_window_time_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_score_tbl);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_cont_init);
#else
void combo_cont_init() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_cont_main);
#else
void combo_cont_main() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", check_and_set_combo);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_hensuu_clear);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_rp_clear_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", super_arts_finish_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", super_arts_last_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", first_attack_pts_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", reversal_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", reversal_continue_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", reversal_attack_pts_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", paring_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", hit_combo_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", arts_finish_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", arts_finish_check2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", SCORE_CALCULATION);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", SCORE_PLUS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_window_push);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_window_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", training_disp_data_set);
