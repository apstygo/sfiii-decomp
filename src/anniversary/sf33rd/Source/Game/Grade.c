#include "sf33rd/Source/Game/Grade.h"
#include "common.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/workuser.h"

// bss
GradeData judge_item[2][2];
GradeFinalData judge_final[2][2];
u8 ji_sat[2][384];

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", ji_grd_init_data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_meichuuritsu2);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_meichuuritsu3);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_em_stun);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_max_combo);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_bougyoritsu2);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_bougyoritsu3);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_nokori_vital);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_def_nmlblock);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_def_rpdblock);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_def_grdblock);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_first_attack);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_leap_attack);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_target_combo);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_nml_nage);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_grap_def);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_quick_stand);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_personal_act);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_reversal);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_command_waza);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_sa_stock_3);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_sa_stock_2);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_sa_stock_1);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_tairyokusa);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_app_nmlblock);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_app_rpdblock);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_app_grdblock);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_renshou);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_em_renshou);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_straight);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_round_result);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_onaji_waza);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_f_stage);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_f_all);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_f_continue);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_f_gradeup);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_f_bss_car);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_f_bss_ball);

const s16 grade_t_table[32][2] = { { 0x0000, 0x0014 }, { 0x004B, 0x0014 }, { 0x0096, 0x0014 }, { 0x00E1, 0x0028 },
                                   { 0x012C, 0x0028 }, { 0x0177, 0x0028 }, { 0x01C2, 0x003C }, { 0x020D, 0x003C },
                                   { 0x0258, 0x003C }, { 0x02A3, 0x0050 }, { 0x02EE, 0x0050 }, { 0x0339, 0x0050 },
                                   { 0x0384, 0x0064 }, { 0x03CF, 0x0064 }, { 0x041A, 0x0064 }, { 0x0465, 0x0096 },
                                   { 0x04B0, 0x00C8 }, { 0x04FB, 0x012C }, { 0x0546, 0x0190 }, { 0x0591, 0x0258 },
                                   { 0x05DC, 0x0320 }, { 0x060E, 0x03E8 }, { 0x0640, 0x0514 }, { 0x0672, 0x0640 },
                                   { 0x06A4, 0x07D0 }, { 0x06D6, 0x0BB8 }, { 0x0708, 0x0FA0 }, { 0x073A, 0x1388 },
                                   { 0x076C, 0x1770 }, { 0x0794, 0x1F40 }, { 0x07BC, 0x2710 }, { 0x07E4, 0x4E20 } };

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_check_work_1st_init);
#else
void grade_check_work_1st_init(s32 ix, s32 ix2) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_check_work_stage_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_check_work_round_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_makeup_final_parameter);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", renew_judge_final_work);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", makeup_final_grade);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_final_grade_bonus);
#else
void grade_final_grade_bonus() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", makeup_spp_frdat);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_makeup_round_parameter);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", backup_RO_PT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_makeup_round_para_dko);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_makeup_judgement_gals);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_makeup_stage_parameter);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", rannyuu_Q_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_makeup_stage_para_com);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_makeup_bonus_parameter);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", get_offence_total);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", get_defence_total);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", get_tech_pts_total);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", get_ex_point_total);

void grade_add_clean_hits(WORK_Other *wk) {
    WORK *mwk;
    s16 ix;

    if (pcon_rno[0] != 0) {
        ix = wk->wu.id;

        if (wk->wu.work_id != 1) {
            mwk = (WORK *)(wk->my_master);

            if (mwk->work_id != 1) {
                return;
            }
            ix = mwk->id;
        }
        judge_item[ix][Play_Type].clean_hits += 1;
    }
}

void grade_add_att_renew(WORK_Other *wk) {
    WORK *mwk;
    s16 ix;

    if (pcon_rno[0] != 0) {
        ix = wk->wu.id;

        if (wk->wu.work_id != 1) {
            mwk = (WORK *)(wk->my_master);

            if (mwk->work_id != 1) {
                return;
            }
            ix = mwk->id;
        }
        judge_item[ix][Play_Type].att_renew += 1;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_guard_success);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_em_stun);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_max_combo_check);

void grade_add_leap_attack(s16 ix) {
    judge_item[ix][Play_Type].leap_attack += 1;

    if (judge_item[ix][Play_Type].leap_attack > 12) {
        judge_item[ix][Play_Type].leap_attack = 12;
    }
}

void grade_add_grap_def(s16 ix) {
    judge_item[ix][Play_Type].grap_def += 1;

    if (judge_item[ix][Play_Type].grap_def > 16) {
        judge_item[ix][Play_Type].grap_def = 16;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_quick_stand);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_nml_nage);

void grade_add_reversal(s16 ix) {
    judge_item[ix][Play_Type].reversal += 1;

    if (judge_item[ix][Play_Type].reversal > 10) {
        judge_item[ix][Play_Type].reversal = 10;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_target_combo);

void grade_add_command_waza(s16 ix) {
    judge_item[ix][Play_Type].comwaza += 1;

    if (judge_item[ix][Play_Type].comwaza > 36) {
        judge_item[ix][Play_Type].comwaza = 36;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_super_arts);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_store_vitality);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_blocking);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_get_first_attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_set_round_result);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_personal_action);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_check_tairyokusa);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_onaji_waza);

s16 grade_get_my_grade(s16 ix) {
    return judge_item[ix][Play_Type].grade;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_get_my_point_percentage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_get_cm_point_percentage);

s16 get_grade_ix(s16 pts) {
    s16 i;

    for (i = 0; i < 31; i++) {
        if (pts < grade_t_table[i + 1][0]) {
            break;
        }
    }

    return i;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", check_guard_miss);
