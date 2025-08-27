#include "sf33rd/Source/Game/EFFA7.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFA7", effect_A7_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFA7", effect_A7_init);
#else
s32 effect_A7_init(PLW *wk) {
    not_implemented(__func__);
}
#endif
