#include "sf33rd/Source/Game/EFF38.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", EFF38_Base_XY);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", EFF38_Jmp_Tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", effect_38_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", EFF38_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", EFF38_SUDDENLY);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", EFF38_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", Exit_Slide_in_38);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", EFF38_SLIDE_OUT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", EFF38_KILL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", EFF38_SHIFT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", Shift_38);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", Move_X_Sub_38);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", Move_Y_Sub_38);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", EFF38_MOVE);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF38", effect_38_init);
#else
s32 effect_38_init(s16 PL_id, s16 dir_old, s16 Your_Char, s16 Play_Status, s16 Target_BG) {
    not_implemented(__func__);
}
#endif
