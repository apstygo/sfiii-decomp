#include "sf33rd/Source/Game/eff35.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff35", eff35_data_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff35", eff35_03_b);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff35", eff35_03_s);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff35", effect_35_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff35", eff35_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff35", eff35_0001);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff35", eff35_0002);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff35", eff35_0003);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff35", eff35_0004);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff35", eff35_0005);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff35", eff35_0006);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/eff35", effect_35_init);
#else
s32 effect_35_init(s16 wait_timer, s16 c_type) {
    not_implemented(__func__);
}
#endif
