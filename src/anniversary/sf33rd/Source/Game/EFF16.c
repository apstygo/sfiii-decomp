#include "sf33rd/Source/Game/EFF16.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF16", effect_16_move);
#else
void effect_16_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF16", eff16_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF16", score_bunkai_eff16);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF16", effect_16_init);
#else
s32 effect_16_init(PLW *wk, s16 flag) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF16", bunkai_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF16", bunkai_numobj);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF16", bbbs_score);
