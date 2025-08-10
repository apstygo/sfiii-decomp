#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff14", effect_14_move);
#else
void effect_14_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff14", effect_14_init);
#else
s32 effect_14_init(s16 id, s16 x, s16 y, s16 atr) {
    not_implemented(__func__);
}
#endif
