#include "sf33rd/Source/Game/EFF01.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF01", effect_01_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF01", get_new_parts_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF01", set_parts_disp_flag);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF01", effect_01_init);
#else
s32 effect_01_init(WORK *wk, u8 koolc) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF01", parts_colmd_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF01", parts_colcd_table);
