#include "sf33rd/Source/Game/EFF27.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", effect_27_move);
#else
void effect_27_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", eff27_00);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", eff27_02);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", eff27_03);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", eff27_04);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", eff27_05);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", eff27_06);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", eff27_07);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", eff27_08);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", eff27_09);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", set_second_hop);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", dead_check27);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", effect_27_init);
#else
s32 effect_27_init(WORK_Other *oya, s16 type) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", scr_obj_num27);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", piece_0000);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF27", piece_0001);
