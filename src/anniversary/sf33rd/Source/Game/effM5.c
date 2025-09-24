#include "sf33rd/Source/Game/effM5.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM5", effect_M5_move);
#else
void effect_M5_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM5", effect_M5_init);
#else
s32 effect_M5_init(PLW *oya) {
    not_implemented(__func__);
}
#endif
