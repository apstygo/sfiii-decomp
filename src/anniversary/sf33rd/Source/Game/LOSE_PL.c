#include "sf33rd/Source/Game/LOSE_PL.h"
#include "common.h"

s16 lose_rno[3];
s16 lose_free[2];

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/LOSE_PL", loser_type_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/LOSE_PL", meta_lose_tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/LOSE_PL", lose_player);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/LOSE_PL", Lose_00000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/LOSE_PL", Lose_10000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/LOSE_PL", Lose_20000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/LOSE_PL", Lose_30000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/LOSE_PL", Normal_normal_Loser);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/LOSE_PL", Judge_normal_loser);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/LOSE_PL", meta_lose_pause);
