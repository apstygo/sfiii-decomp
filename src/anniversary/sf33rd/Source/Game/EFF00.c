#include "sf33rd/Source/Game/EFF00.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF00", effect_00_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF00", get_dip_modoki);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF00", get_dip_modoki2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF00", renewal_table_address);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF00", renewal_table_data);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF00", effect_00_init);
#else
s32 effect_00_init(WORK *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF00", jdb);
