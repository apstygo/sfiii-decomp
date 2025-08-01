#include "sf33rd/Source/Game/effe9.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe9", effect_E9_move);
#else
void effect_E9_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe9", effect_E9_init);
#else
s32 effect_E9_init() {
    not_implemented(__func__);
}
#endif
