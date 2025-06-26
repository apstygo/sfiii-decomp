#include "sf33rd/Source/Game/cmb_win.h"
#include "common.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/workuser.h"

s16 old_cmb_flag[2];
s8 cmb_stock[2];
s8 first_attack;
s8 rever_attack[2];
s8 paring_attack[2];
s8 bonus_pts[2];
s16 hit_num;
u8 sa_kind;
u8 end_flag[2];
s16 calc_hit[2][10];
s16 score_calc[2][12];
s8 cmb_all_stock;
s8 sarts_finish_flag[2];
s8 last_hit_time;
s8 cmb_calc_now[2];
u8 cst_read[2];
u8 cst_write[2];

const u8 cmb_pos_tbl[2][21] = { { 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27 },
                                { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 } };

const u8 cmb_window_move_tbl[7] = { 12, 16, 20, 16, 12, 10, 12 };

const u8 cmb_window_time_tbl[7] = { 28, 40, 60, 60, 50, 50, 24 };

const u16 combo_score_tbl[12][2] = { { 300, 200 },   { 500, 400 },   { 1000, 600 },  { 1000, 600 },
                                     { 2000, 800 },  { 3000, 600 },  { 4000, 800 },  { 5000, 1000 },
                                     { 6000, 2000 }, { 8000, 2000 }, { 9000, 3000 }, { 10000, 4000 } };

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_cont_init);
#else
void combo_cont_init() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_cont_main);
#else
void combo_cont_main() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_control);

void check_and_set_combo(s8 PL) {
    s8 PLS;

    if (PL == 0)
        PLS = 1;
    else
        PLS = 0;

    hit_num = plw[PL].cb->total;

    if (hit_num > 99)
        hit_num = 99;

    training_disp_data_set(PL, hit_num);

    if (first_attack == 1 || first_attack == 2)
        first_attack_pts_check(PL);

    if (rever_attack[PLS] == 1)
        reversal_attack_pts_check(PL);

    hit_combo_check(PL);
    combo_hensuu_clear(PL);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_hensuu_clear);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_rp_clear_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", super_arts_finish_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", super_arts_last_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", first_attack_pts_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", reversal_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", reversal_continue_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", reversal_attack_pts_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", paring_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", hit_combo_check);

s32 arts_finish_check(s8 PL) {
    if (Conclusion_Flag && Conclusion_Type == 0 && Loser_id == PL && sarts_finish_flag[PL])
        return 1;

    return 0;
}

s32 arts_finish_check2(u8 PL) {
    if (Conclusion_Flag && Conclusion_Type == 0 && Loser_id == PL && (plw[PL].cb->new_dm & 0x3F) >= 32)
        return 1;

    return 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", SCORE_CALCULATION);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", SCORE_PLUS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_window_push);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", combo_window_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/cmb_win", training_disp_data_set);
