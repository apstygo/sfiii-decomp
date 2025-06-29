#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM5", effect_M5_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM5", effect_M5_init);
#else
s32 effect_M5_init(PLW *oya) {
    not_implemented(__func__);
}
#endif
