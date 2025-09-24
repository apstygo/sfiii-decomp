#include "sf33rd/Source/Game/EFFM1.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFM1", effect_M1_move);
#else
void effect_M1_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFM1", effm1_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFM1", effect_M1_init);
#else
s32 effect_M1_init(WORK *wk) {
    not_implemented(__func__);
}
#endif
