#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", effect_M0_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", animal_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", animal_control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", animal_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", animal_0001);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", animal_0002);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", animal_0004);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", animal_0005);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", mouse_run_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", mouse_stand_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", cat_run_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", cat_run_set2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", cat_walk_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", don_run_set);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", effect_M0_init);
#else
s32 effect_M0_init(u8 pl_rl, u8 animal_type) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM0", animal_0005_tbl);
