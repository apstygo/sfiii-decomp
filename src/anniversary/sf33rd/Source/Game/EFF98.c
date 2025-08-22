#include "sf33rd/Source/Game/EFF98.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF98", effect_98_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF98", EFF98_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF98", EFF98_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF98", EFF98_SLIDE_OUT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF98", EFF98_SUDDENLY);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF98", EFF98_KILL);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF98", effect_98_init);
#else
s32 effect_98_init(s16 PL_id, s16 dir_old, s16 master_player, s16 Target_BG) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF98", EFF98_Jmp_Tbl);
