#include "sf33rd/Source/Game/eff08.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff08", effect_08_move);
#else
void effect_08_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff08", effect_08_init);
#else
s32 effect_08_init(s8 sc_num, s8 x, s8 y, u16 atr, s16 color_type) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff08", Rewrite_Color_Data_08);
