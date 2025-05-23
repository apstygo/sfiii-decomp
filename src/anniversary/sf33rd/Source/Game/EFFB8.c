#include "sf33rd/Source/Game/EFFB8.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFB8", effect_B8_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFB8", effect_B8_init);
#else
s32 effect_B8_init(s16 WIN_PL_NO, s16 timer) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFB8", effb8_normal_or_senyou);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFB8", effb8_sel_1_by_8);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFB8", wk_set);
