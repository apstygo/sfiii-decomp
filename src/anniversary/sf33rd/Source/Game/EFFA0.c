#include "sf33rd/Source/Game/EFFA0.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFA0", effect_A0_move);
#else
void effect_A0_move(WORK_Other_CONN *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFA0", effect_A0_init);
#else
s32 effect_A0_init(s16 type, u16 disp_target, s16 pos_index, s16 old_rno, s16 zero, s16 target_bg, s16 master_player) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFA0", Setup_A0_Sub);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFA0", Pos_Data_A0);
