#include "sf33rd/Source/Game/EFFD7.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFD7", effect_D7_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFD7", effD7_main_process);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFD7", cal_speeds_to_me);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFD7", cal_speeds_to_em);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFD7", cal_speeds_effD7);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFD7", ball_init_position_effD7);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFD7", screen_range_check_effD7);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFD7", effect_D7_init);
#else
s32 effect_D7_init(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFD7", my_ball_live_check);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFFD7", effD7_hit_box);
