#include "sf33rd/Source/Game/Grade.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_check_work_1st_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_check_work_stage_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_check_work_round_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_makeup_final_parameter);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", renew_judge_final_work);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", makeup_final_grade);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_final_grade_bonus);

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

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_clean_hits);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_att_renew);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_guard_success);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_em_stun);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_max_combo_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_leap_attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_grap_def);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_quick_stand);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_nml_nage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_reversal);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_target_combo);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_command_waza);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_super_arts);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_store_vitality);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_blocking);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_get_first_attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_set_round_result);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_personal_action);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_check_tairyokusa);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_add_onaji_waza);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_get_my_grade);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_get_my_point_percentage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_get_cm_point_percentage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", get_grade_ix);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", check_guard_miss);

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

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Grade", grade_t_table);
