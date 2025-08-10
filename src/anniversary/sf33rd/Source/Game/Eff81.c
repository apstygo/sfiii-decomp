#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff81", effect_81_move);
#else
void effect_81_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff81", effect_81_init);
#else
s32 effect_81_init(s16 Time) {
    not_implemented(__func__);
}
#endif
