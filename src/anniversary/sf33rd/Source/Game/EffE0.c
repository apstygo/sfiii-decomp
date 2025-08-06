#include "sf33rd/Source/Game/EffE0.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffE0", effect_E0_move);
#else
void effect_E0_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffE0", Setup_Char_E0);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffE0", effect_E0_init);
#else
s32 effect_E0_init(s16 Direction, s16 dm_vital, s16 Pos_Type) {
    not_implemented(__func__);
}
#endif
