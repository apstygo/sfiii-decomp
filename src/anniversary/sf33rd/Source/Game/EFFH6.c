#include "sf33rd/Source/Game/EFFH6.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFH6", code_tab);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFH6", effect_H6_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFH6", effect_H6_init);
#else
s32 effect_H6_init(s16 timer, s8 *str, s16 X, s16 Y, s16 Original_Color, s32 /* unused */) {
    not_implemented(__func__);
}
#endif
