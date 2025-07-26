#include "sf33rd/Source/Game/effe3.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe3", effect_E3_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe3", effect_E3_init);
#else
s32 effect_E3_init(PLW *wk) {
    not_implemented(__func__);
}
#endif
