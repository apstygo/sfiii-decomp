#include "sf33rd/Source/Game/EFFG6.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFG6", effect_G6_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFG6", effect_G6_init);
#else
s32 effect_G6_init(WORK *wk, u8 dat) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFG6", effg6_data);
