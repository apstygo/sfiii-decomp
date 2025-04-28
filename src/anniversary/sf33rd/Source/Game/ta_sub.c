#include "sf33rd/Source/Game/ta_sub.h"
#include "common.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg_data.h"
#include "structs.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", sync_fam_set3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", range_x_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", range_x_check3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", range_y_check);

void add_x_sub(WORK_Other *ewk) {
    ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
    ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", add_x_sub2);

void add_y_sub(WORK_Other *ewk) {
    ewk->wu.xyz[1].cal += ewk->wu.mvxy.a[1].sp;
    ewk->wu.mvxy.a[1].sp += ewk->wu.mvxy.d[1].sp;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", add_y_sub2);

s32 obr_no_disp_check() {
    if (aku_flag | akebono_flag | sa_pa_flag | seraph_flag) {
        return 1;
    }

    return 0;
}

void disp_pos_trans_entry(WORK_Other *ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    sort_push_request4(&ewk->wu);
}

void disp_pos_trans_entry5(WORK_Other *ewk) {
    if (obr_no_disp_check()) {
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos & 0xFFFF;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos & 0xFFFF;
    sort_push_request4(&ewk->wu);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", disp_pos_trans_entry_r);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", disp_pos_trans_entry_r4);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", disp_pos_trans_entry_s);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", disp_pos_trans_entry_rs);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", pl_eff_trans_entry);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", eff_hit_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", eff_hit_check_sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", eff_hit_check2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", eff_hit_check_sub2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", hit_check_subroutine_yu);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", eff_hit_flag_clear);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", compel_dead_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", win_lose_work_clear);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", cal_bg_speed_data_x);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", cal_bg_speed_data_y);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/ta_sub", pl_hit_eff);
