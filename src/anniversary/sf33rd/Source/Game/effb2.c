#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effb2", effect_B2_move);
#else
void effect_B2_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effb2", b3_Break_Into_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effb2", fight_col_chg_sub);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effb2", effect_B2_init);
#else
s32 effect_B2_init() {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/effb2", effb2_sound_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/effb2", fight_col_move_tbl);
