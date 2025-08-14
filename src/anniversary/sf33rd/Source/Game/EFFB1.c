#include "sf33rd/Source/Game/EFFB1.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFB1", effect_B1_move);
#else
void effect_B1_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFB1", effB1_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFB1", effB1_mark_change);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFB1", effB1_mark_exchange);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFB1", effect_B1_init);
#else
s32 effect_B1_init(PLW *wk, s16 flag) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFB1", effB1_wait_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFB1", effB1_wait_tbl_2);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFB1", bbbs_clear);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFB1", bbbs_blocking);
