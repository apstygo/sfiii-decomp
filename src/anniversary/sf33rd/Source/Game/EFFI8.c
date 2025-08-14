#include "sf33rd/Source/Game/EFFI8.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI8", effect_I8_move);
#else
void effect_I8_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI8", effI8_main_process);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI8", cal_speeds_to_me_effI8);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI8", cal_speeds_to_em_effI8);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI8", check_ball_mizushibuki);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI8", effect_I8_init);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI8", setup_effI8);
#else
void setup_effI8(PLW *wk, const BBBSTable *dadr) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI8", effI8_hit_box);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI8", bbbs_emtall);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFI8", cbm_table);
