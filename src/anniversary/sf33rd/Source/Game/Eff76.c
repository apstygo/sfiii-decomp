#include "sf33rd/Source/Game/Eff76.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_Jmp_Tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", effect_76_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_WAIT_BREAK_INTO);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_SLIDE_OUT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_SUDDENLY);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_BEFORE);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", EFF76_SHIFT);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", effect_76_init);
#else
s32 effect_76_init(s16 dir_old) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", Setup_Pos_76);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", Setup_Char_76);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", Check_Range_Out);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", Setup_Color_76);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", Setup_Color_L1);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", chkNameAkuma);
#else
s32 chkNameAkuma(s32 plnum, s32 rnum) {
    not_implemented(__func__);
}
#endif
