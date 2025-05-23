#include "sf33rd/Source/Game/EFFJ2.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ2", bbbs_nando_large);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ2", effect_J2_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ2", effJ2_trans);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ2", effect_J2_init);
#else
s32 effect_J2_init(s16 delay) {
    not_implemented(__func__);
}
#endif
