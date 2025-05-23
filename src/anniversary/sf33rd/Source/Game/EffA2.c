#include "sf33rd/Source/Game/EffA2.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffA2", hnc_color_tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffA2", effect_A2_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffA2", effect_A2_init);
#else
s32 effect_A2_init(s16 /* unused */) {
    not_implemented(__func__);
}
#endif
