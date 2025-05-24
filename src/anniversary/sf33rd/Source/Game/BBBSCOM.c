#include "sf33rd/Source/Game/BBBSCOM.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", bbbs_com_execute);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", bbbs_com_initialize);
#else
void bbbs_com_initialize() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", makeup_bonus_game_level);
#else
void makeup_bonus_game_level(s16 ix) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", set_bonus_game_difficulty);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", set_bonus_game_nando);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", katteni_bonus_nando);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", bbbs_jump_level);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", bbbs_level_00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", bbbs_level_01);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", bbbs_level_02);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", bbbs_level_03);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", bbbs_level_04);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", bbbs_level_05);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", bbbs_level_06);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", bbbs_level_07);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", bbbs_level_08);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/BBBSCOM", bbbs_level_09);
