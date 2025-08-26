#include "sf33rd/Source/Game/effJ6.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effJ6", effect_J6_move);
#else
s32 effect_J6_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effJ6", effect_j6_hit_sub);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effJ6", effect_J6_init);
#else
s32 effect_J6_init(WORK_Other *oya) {
    not_implemented(__func__);
}
#endif
