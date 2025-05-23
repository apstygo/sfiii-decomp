#include "sf33rd/Source/Game/EFF75.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF75", EFF75_Jmp_Tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF75", effect_75_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF75", EFF75_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF75", EFF75_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF75", EFF75_CHAR_CHANGE);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF75", EFF75_SUDDENLY);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF75", effect_75_init);
#else
s32 effect_75_init(s16 dir_old, s16 ID, s16 Target_BG) {
    not_implemented(__func__);
}
#endif
