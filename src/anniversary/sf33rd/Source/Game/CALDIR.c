#include "sf33rd/Source/Game/CALDIR.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", rate_256_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", dir_sel_table);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", caldir_pos_256);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", caldir_pos_032);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", add_pos_dir_064);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cal_move_quantity2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cal_move_quantity3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cmsd_all_x_speed_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cmsd_all_y_speed_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cmsd_swx_0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cmsd_swy_0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cmsd_swx_1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cmsd_swy_1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cmsd_swx_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cmsd_swy_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cmsd_x_initial_speed);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cmsd_y_initial_speed);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cmsd_x_delta_speed);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cmsd_y_delta_speed);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cal_all_speed_data);
#else
void cal_all_speed_data(WORK *wk, s16 tm, s16 x1, s16 y1, s8 xsw, s8 ysw) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cal_initial_speed);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cal_initial_speed_y);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cal_delta_speed);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cal_top_of_position_y);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cal_time_of_sign_change);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", cal_move_dir_forecast);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CALDIR", remake_2_10);
