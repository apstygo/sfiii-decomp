#include "sf33rd/Source/Game/effM7.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM7", effect_M7_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM7", effm7_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM7", effect_M7_init);
#else
s32 effect_M7_init(PLW* oya) {
    not_implemented(__func__);
}
#endif


INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/effM7", effm7_data_tbl);
