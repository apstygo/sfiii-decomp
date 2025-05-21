#include "sf33rd/Source/Game/end_main.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", Ending_init);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", Ending_main);
#else
s8 Ending_main(s16 pl_num) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", normal_ending);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", end_main_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", fadeout_to_staff_roll);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", common_end_init00);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", common_end_init01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", end_fam_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", end_fam_set2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", end_bg_pos_hosei);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", end_bg_pos_hosei2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", end_scn_pos_set2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", end_reset_etc);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", end_X_com01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", end_fade_bgm);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", end_fade_complete);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/end_main", Cut_Cut_Cut_t);
