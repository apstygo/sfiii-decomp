#include "sf33rd/Source/Game/EFFL1.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", bunkai_table_l1);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_item_init);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_base_data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_score);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_wins);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_grade);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_bar);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_f_stage_p);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_f_stage_r);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_f_mk_spp);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_f_mk_spp_Q);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_f_mk_all);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_f_kz_cont);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_f_kz_spp);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_f_score);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_loser);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_loser_face);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", gj_bar2);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effect_L1_move);
#else
void effect_L1_move(WORK_Other_CONN *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", grade_data_disp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_w_win_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_w_grade_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_k_grade_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_w_score_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_w_graph_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_k_graph_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_f_stage_p_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_f_stage_r_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_f_grade_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_f_mk_spp_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_f_mk_all_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_f_kz_cont_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_f_kz_spp_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_f_score_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effL1_suuchi_bunkai_sub);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL1", effect_L1_init);
#else
s32 effect_L1_init(s16 flag) {
    not_implemented(__func__);
}
#endif
