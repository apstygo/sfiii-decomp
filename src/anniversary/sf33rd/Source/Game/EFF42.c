#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF42", effect_42_move);
#else
void effect_42_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF42", EFF42_SUDDENLY);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF42", EFF42_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF42", EFF42_SLIDE_OUT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF42", EFF42_KILL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF42", EFF42_MOVE);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF42", Setup_Char_Index);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF42", effect_42_init);
#else
s32 effect_42_init(s16 Type) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF42", EFF42_Jmp_Tbl);
