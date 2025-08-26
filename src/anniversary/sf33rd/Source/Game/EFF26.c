#include "sf33rd/Source/Game/EFF26.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF26", effect_26_move);
#else
void effect_26_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF26", eff26_00);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF26", eff26_01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF26", eff26_02);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF26", eff26_03);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF26", eff26_04);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF26", eff26_num);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF26", eff26_data_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF26", eff26_05);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF26", effect_26_init);
#else
s32 effect_26_init(WORK_Other *oya, s16 type26) {
    not_implemented(__func__);
}
#endif
