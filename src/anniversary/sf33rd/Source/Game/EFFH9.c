#include "sf33rd/Source/Game/EFFH9.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFH9", effect_H9_move);
#else
void effect_H9_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFH9", effH9_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFH9", nokori_ball_effH9);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFH9", effect_H9_init);
#else
s32 effect_H9_init(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFH9", bbbs_ball);
