#include "sf33rd/Source/Game/Eff39.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff39", EFF39_Jmp_Tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff39", effect_39_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff39", EFF39_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff39", EFF39_SUDDENLY);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff39", EFF39_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff39", EFF39_SLIDE_OUT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff39", EFF39_KILL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff39", EFF39_MOVE);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff39", effect_39_init);
#else
s32 effect_39_init(s16 PL_id, s16 dir_old, s16 Your_Char, s16 Target_BG, s16 Option) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff39", Get_Pos39);
