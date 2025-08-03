#include "sf33rd/Source/Game/EFFF2.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFF2", effect_F2_move);
#else
void effect_F2_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFF2", effect_F2_init);
#else
s32 effect_F2_init() {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFF2", efff2_data_tbl1);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFF2", efff2_sp_tbl1);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFF2", efff2_timer_tbl);
