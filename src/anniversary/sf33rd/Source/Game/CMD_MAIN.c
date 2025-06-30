#include "sf33rd/Source/Game/CMD_MAIN.h"
#include "common.h"
#include "sf33rd/Source/Game/HITCHECK.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/cmd_data.h"

// omop_b_block_ix
// blok_b_omake

// check_rl_on_car - PLS01

void (*chk_move_jp[28])() = { check_init, check_0,  check_1,  check_2,  check_3,  check_4,  check_5,
                              check_6,    check_7,  check_7,  check_9,  check_10, check_11, check_12,
                              check_13,   check_14, check_15, check_16, check_16, check_18, check_19,
                              check_20,   check_21, check_22, check_23, check_24, check_25, check_26 };

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
