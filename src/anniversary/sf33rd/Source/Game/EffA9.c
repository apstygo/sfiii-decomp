#include "sf33rd/Source/Game/EffA9.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffA9", effect_A9_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffA9", effect_A9_init);
#else
s32 effect_A9_init(s16 Char_Index, s16 Option, s16 Pos_Index, s16 Option2) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffA9", Setup_A9);
