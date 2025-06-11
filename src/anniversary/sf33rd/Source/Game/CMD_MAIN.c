#include "sf33rd/Source/Game/CMD_MAIN.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", waza_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", key_thru);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", cmd_data_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", cmd_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", cmd_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_next);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_4);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_5);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_6);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_7);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_9);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", paring_miss_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_10);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_11);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_12);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_13);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_14);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_15);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_16);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_18);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_19);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_20);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_21);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_22);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_23);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_24);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_25);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", check_26);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", command_ok);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", command_ok_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", dead_lvr_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", pl_lvr_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", sw_pick_up);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", dash_flag_clear);
#else
void dash_flag_clear(s16 pl_id) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", hi_jump_flag_clear);
#else
void hi_jump_flag_clear(s16 pl_id) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", waza_flag_clear_only_1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", waza_compel_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", waza_compel_all_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", waza_compel_all_init2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CMD_MAIN", processed_lvbt);
