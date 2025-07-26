#include "sf33rd/Source/Game/EFFJ7.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", effect_J7_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", check_new_color_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", get_new_color_data);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", effect_J7_init);
#else
s32 effect_J7_init(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_0_00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_0_01);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_0_02);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_0_03);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_0_04);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_0_05);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_0_06);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_0_07);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_0_08);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_0_09);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_0_10);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_0_11);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_0_00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_0_01);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_0_02);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_0_03);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_0_04);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_0_05);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_0_06);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_0_07);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_0_08);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_0_09);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_0_10);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_0_11);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_1_00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_1_01);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_1_02);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_1_03);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_1_04);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_1_05);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_1_06);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_1_07);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_1_08);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_1_09);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_1_10);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_1_11);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_1_00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_1_01);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_1_02);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_1_03);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_1_04);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_1_05);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_1_06);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_1_07);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_1_08);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_1_09);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_1_10);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_1_11);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_L_1);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFJ7", pl00_R_1);
