#include "sf33rd/Source/Game/EFF02.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF02", effect_02_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF02", urian_guard_se_check);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF02", effect_02_init);
#else
s32 effect_02_init(WORK *wk, s8 dmgp, s8 mkst, s8 dmrl) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF02", hit_mark_dir_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF02", hmdt);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF02", hcct);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF02", gqdt);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF02", explem);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF02", explem2);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF02", hit_mark_hosei_table);
