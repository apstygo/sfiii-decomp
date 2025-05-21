#include "sf33rd/Source/Game/bg_sub.h"
#include "common.h"
#include "structs.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", check_cg_zoom);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", bg_chase_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", chase_start_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", chase_xy_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", Bg_mv_tw);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", x_right_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", x_left_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", scr_x_dummy);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", scr_10_20);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", scr_10_21);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", scr_10_22);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", scr_11_20);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", scr_11_21);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", scr_11_22);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", scr_12_20);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", scr_12_21);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", scr_12_22);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", bg_base_x_move_sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", bg_base_x_move_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", remake_x_mvstep);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", Bg_Y_Sitei);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", bg_base_y_move_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", bg_x_move_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", bg_y_move_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", zoom_ud_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", suzi_offset_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", suzi_offset_set_sub);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", suzi_sync_pos_set);
#else
void suzi_sync_pos_set(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", Bg_Family_Set);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", Bg_Family_Set_appoint);
#else
void Bg_Family_Set_appoint(s32 num_of_bg) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", Bg_Family_Set_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", Bg_Family_Set_2_appoint);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", ake_Family_Set2);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", bg_pos_hosei_sub2);
#else
void bg_pos_hosei_sub2(s16 bg_no) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", bg_pos_hosei_sub3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", bg_pos_hosei2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", get_center_position);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", get_height_position);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", bg_work_clear);
#else
void bg_work_clear() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", compel_bg_init_position);
#else
void compel_bg_init_position() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", bg_base_move_common);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", bg_move_common);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", bg_initialize);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", akebono_initialize);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", bg_etc_write);
#else
void bg_etc_write(s16 type) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg_sub", Ck_Range_Out_S);
