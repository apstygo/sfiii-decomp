#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff52", effect_52_move);
#else
void effect_52_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff52", EFF52_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff52", EFF52_SUDDENLY);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff52", EFF52_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff52", EFF52_SLIDE_OUT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff52", EFF52_KILL);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff52", effect_52_init);
#else
s32 effect_52_init(s16 PL_id, s16 dir_old) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff52", Setup_Char_52);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff52", Setup_Pos_52);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff52", EFF52_Jmp_Tbl);
