#include "sf33rd/Source/Game/EFFE4.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFE4", effect_E4_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFE4", effect_E4_init);
#else
s32 effect_E4_init(PLW *wk) {
    not_implemented(__func__);
}
#endif
