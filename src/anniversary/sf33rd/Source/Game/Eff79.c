#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", Pos_Z_Data_79);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", effect_79_move);
#else
void effect_79_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", Check_Play_Status_79);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", Move_Move_79);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", Setup_Move_79);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", Move_79);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", Check_Priority);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", EFF79_Move_X);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", EFF79_Move_Y);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", Setup_Command_Name);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", Select_End_Sub_79);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", effect_79_init);
#else
s32 effect_79_init(s16 pl_id, s16 plate_id, s16 pos_id, s16 time, s16 Target_BG) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", Setup_Pos_79);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", Check_Speed_79);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", Move_X_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", Check_Depth_to_Before);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff79", Move_Y_Sub);
