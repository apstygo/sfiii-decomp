#include "sf33rd/Source/Game/EFF45.h"
#include "common.h"

// sbss
MessageData Message_Data[4];

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF45", EFF45_Jmp_Tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF45", effect_45_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF45", EFF45_DISP);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF45", EFF45_SUSPEND);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF45", EFF45_CHANGE);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF45", effect_45_init);
#else
s32 effect_45_init(u8 id, s16 sync_bg, s16 master_player) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF45", Setup_Message);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF45", Centering_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF45", Check_Pig_Pig);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF45", Convert_16_10_2);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF45", Convert_16_10_3);
#else
void Convert_16_10_3(WORK_Other_CONN *ewk, u16 target) {
    not_implemented(__func__);
}
#endif
