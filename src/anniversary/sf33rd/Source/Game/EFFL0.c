#include "sf33rd/Source/Game/EFFL0.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL0", effect_L0_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFL0", effect_L0_init);
#else
s32 effect_L0_init(WORK *wk, s16 data) {
    not_implemented(__func__);
}
#endif
