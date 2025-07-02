#include "sf33rd/Source/Game/EFFC1.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC1", effect_C1_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFC1", effect_C1_init);
#else
s32 effect_C1_init(WORK *wk) {
    not_implemented(__func__);
}
#endif
