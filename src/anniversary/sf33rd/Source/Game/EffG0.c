#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffG0", effect_G0_move);
#else
void effect_G0_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffG0", Check_Die_G0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffG0", effG0_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffG0", Flash_G0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffG0", score_bunkai_G0);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffG0", effect_G0_init);
#else
s32 effect_G0_init(s16 Order, s16 Time, u32 Score, s16 Pos_Index) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffG0", bunkai_table_G0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffG0", bunkai_numobj_G0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffG0", Result_Score);
