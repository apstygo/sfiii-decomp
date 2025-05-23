#include "sf33rd/Source/Game/EffK6.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffK6", EFFK6_Jmp_Tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffK6", effect_K6_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffK6", EFFK6_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffK6", EFFK6_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffK6", EFFK6_SLIDE_OUT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffK6", EFFK6_SUDDENLY);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffK6", EFFK6_KILL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffK6", EFFK6_MOVE);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffK6", effect_K6_init);
#else
s32 effect_K6_init(s16 PL_id, s16 dir_old, s16 dm_vital, s16 Target_BG) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffK6", Setup_1st_PosK6);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffK6", Get_PosK6);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffK6", Setup_CharK6);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffK6", Setup_K6_Index);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffK6", chkNameSuv);
