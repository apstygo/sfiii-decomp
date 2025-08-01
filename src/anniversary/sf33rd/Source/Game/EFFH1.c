#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFH1", effect_H1_move);
#else
void effect_H1_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFH1", eff_h1_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFH1", effect_H1_init);
#else
s32 effect_H1_init() {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFH1", effh1_wait_timer);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFH1", effh1_data_tbl);
