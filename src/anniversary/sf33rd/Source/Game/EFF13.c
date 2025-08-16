#include "sf33rd/Source/Game/EFF13.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", effect_13_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", tama_display);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", screen_x_range_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", screen_range_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", tama15_screen_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", set_tengu_init_pos);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_00000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_01000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_02000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", set_tengu_my_home);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", check_tengu_attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", make_speed_xy_att);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", make_speed_xy_back);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_03000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_04000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_05000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_06000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_07000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_08000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_09000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_10000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_11000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_12000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_13000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_14000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_15000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_16000);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", effect_13_init);
#else
s32 effect_13_init(WORK *wk, const u8 data) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kotp_07_dm_vital);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", tama_data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", tcct);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kind_of_tama_process);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", kage_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", homing_empos_hos);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", enemy_pos_hos);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF13", X_F_L_A_T_pos_hos);
