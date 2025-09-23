#include "sf33rd/Source/Game/EFF74.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF74", effect_74_move);
#else
void effect_74_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF74", EFF74_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF74", EFF74_SUDDENLY);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF74", EFF74_Pos_Data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF74", EFF74_Jmp_Tbl);
