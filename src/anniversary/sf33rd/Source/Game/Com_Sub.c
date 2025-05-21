#include "sf33rd/Source/Game/Com_Sub.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", End_Pattern);
#else
void End_Pattern(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Next_Be_Passive);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Turn_Over_On);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Only_Shot);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Lever_On);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Lever_Off);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Pierce_On);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_DENJIN_LEVEL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Push_Shot);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Exit_DENJIN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Keep_Away);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_KA_Jump);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_KA_Walk);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Search_Back_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Approach_Walk);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Arrival);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Walk);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Forced_Guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Provoke);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Normal_Attack);
#else
void Normal_Attack(PLW *wk, s16 Reaction, u16 Lever_Data) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Small_Jump_Measure);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Normal_Attack_SP);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Adjust_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Squat);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Start_Normal_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Lever_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Lever_Attack_SP);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Guard_Lever);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Start_Lever_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", SA_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", DENJIN_Check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", YAGYOU_Check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", SA_Range_Check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_SA);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_EX);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_SA_Full);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Branch_Unit_Area);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Com_Random_Select);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Branch_Wait_Area);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Wait);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Look);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Keep_Status);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", VS_Jump_Guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Wait_Lie);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Wait_Get_Up);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Wait_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Wait_Attack_Complete);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Exit_Guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Short_Range_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", EM_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", SHELL_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Term_Sub_Air);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Term_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Correct_Unit_PL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Term_Sub_Y);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Jump);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Hi_Jump);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Start_Hi_Jump);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Air_Guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Jump_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Jump_Attack_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_SP_Jump_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_VS_Air_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Hi_Jump_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Hi_Jump_Attack_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Term_ABS_Distance);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Com_Add_Y);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ORO_JA_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ORO_HJA_Term);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Command_Attack);
#else
void Command_Attack(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Hadou_Check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Resume_Lever);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", J_Command_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Rapid_Command_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Rapid);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Rapid_End_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Rapid_Time);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Rapid_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Rapid_End);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Start_Command_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ORO_JCA_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ORO_HJCA_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Jump_Command_Attack_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Hi_Jump_Command_Attack_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Landed);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Dash_Hit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Front_or_Back);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Hit_Shell);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Jump_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Command_Type_00);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Command_Type_06);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Command_Type_01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Command_01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Store_Lever);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Store_Direction);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Select_Combo_Speed);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Select_Reflection_Time);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Lv04);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Lv08);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Lv10);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Lv18);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_VS_Catch_Data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_LP_Data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_WT_Data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Ck_Distance);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Ck_Distance_Height);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Ck_Area);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Ck_Area_Shell);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Ck_Distance_Lv);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Ck_Distance_LvJ);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Next_End);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Next_Another_Menu);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Reaction_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Meoshi_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Get_Meoshi_Data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Reaction_Exit_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_First_Menu);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Select_Active);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_SA_Active);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Follow);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Decide_Follow_Menu);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Select_Passive);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Devide_Level);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Random);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Dramatic);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Passive);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Makoto);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Flip_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_EM_Rank_Index);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Flip_Term_Correct);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Next_Be_Guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Flip_Tech);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Next_Be_Flip);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Diagonal_Shell);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Ignore_Shell2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Shell);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Shell_Another_in_Flip);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Ignore_Shell);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Compute_Hit_Time);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Decide_Shell_Guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Guard_or_Jump_VS_Shell);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Shell_Disposal);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Next_Be_Shell_Guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Decide_Shell_Reaction);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Ck_Distance_XX);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Behind);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Lever_LR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Exit_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", VS_Jump_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Exit_Term_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Exit_Term_0001);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Exit_Term_0002);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Exit_Term_0003);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Exit_Term_0004);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Exit_Term_0005);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Exit_Term_0006);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Exit_Term_0007);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Exit_Term_0008);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Drop_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_SHINRYU);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_BOSS);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_BOSS_EX);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ETC_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ETC_Term_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ETC_Term_0001);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ETC_Term_0002);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ETC_Term_0003);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ETC_Term_0004);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ETC_Term_0005);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ETC_Term_0006);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ETC_Term_0007);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ETC_Term_0008);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ETC_Term_0009);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", emLevelRemake);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", emGetMaxBlocking);
