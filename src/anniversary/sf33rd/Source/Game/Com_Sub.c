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

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Turn_Over_On);
#else
void Turn_Over_On(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Only_Shot);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Lever_On);
#else
void Lever_On(PLW *wk, u16 LR_Lever, u16 UD_Lever) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Lever_Off);
#else
void Lever_Off(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Pierce_On);
#else
void Pierce_On(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_DENJIN_LEVEL);
#else
void Setup_DENJIN_LEVEL(PLW *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Push_Shot);
#else
void Push_Shot(PLW *wk, s16 Power_Level) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Exit_DENJIN);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Keep_Away);
#else
void Keep_Away(PLW *wk, s16 Target_Pos, s16 Option) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_KA_Jump);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_KA_Walk);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Search_Back_Term);
#else
void Search_Back_Term(PLW *wk, s16 Move_Value, s16 Next_Action, s16 Next_Menu) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Approach_Walk);
#else
void Approach_Walk(PLW *wk, s16 Target_Pos, s16 Option) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Arrival);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Walk);
#else
void Walk(PLW *wk, u16 Lever, s16 Time, s16 unused) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Forced_Guard);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Provoke);
#else
void Provoke(PLW *wk, s16 Lever) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Normal_Attack);
#else
void Normal_Attack(PLW *wk, s16 Reaction, u16 Lever_Data) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Small_Jump_Measure);


#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Normal_Attack_SP);
#else
void Normal_Attack_SP(PLW *wk, s16 Reaction, u16 Lever_Data, s16 Time) {
    not_implemented(__func__);
}
#endif


#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Adjust_Attack);
#else
void Adjust_Attack(PLW *wk, s16 Reaction, u16 Lever_Data) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Squat);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Start_Normal_Attack);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Lever_Attack);
#else
void Lever_Attack(PLW *wk, s16 Reaction, u16 Lever, u16 Lever_Data) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Lever_Attack_SP);
#else
void Lever_Attack_SP(PLW *wk, s16 Reaction, u16 Lever, u16 Lever_Data, s16 Time) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Guard_Lever);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Start_Lever_Attack);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", SA_Term);
#else
void SA_Term(PLW *wk, u16 SA0, u16 SA1, u16 SA2, u16 Term_No) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", DENJIN_Check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", YAGYOU_Check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", SA_Range_Check);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_SA);
#else
void Check_SA(PLW *wk, s16 Next_Action, s16 Next_Menu) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_EX);
#else
void Check_EX(PLW *wk, s16 Next_Action, s16 Next_Menu) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_SA_Full);
#else
void Check_SA_Full(PLW *wk, s16 Next_Action, s16 Next_Menu) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Branch_Unit_Area);
#else
void Branch_Unit_Area(PLW *wk, s16 Next_Action, s16 Menu, s16 Menu_01, s16 Menu_02, s16 Menu_03) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Com_Random_Select);
#else
void Com_Random_Select(PLW *wk, s16 Next_Action, s16 Menu_00, s16 Menu_01, s16 Menu_02, s16 Menu_03, s16 Rnd_Type) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Branch_Wait_Area);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Wait);
#else
void Wait(PLW *wk, s16 Time) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Look);
#else
void Look(PLW *wk, s16 Time) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Keep_Status);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", VS_Jump_Guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Wait_Lie);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Wait_Get_Up);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Wait_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Wait_Attack_Complete);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Exit_Guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Short_Range_Attack);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", EM_Term);
#else
void EM_Term(PLW *wk, s16 Range_X, s16 Range_Y, s16 Exit_Number, s16 Next_Action, s16 Next_Menu) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", SHELL_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Term_Sub_Air);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Term_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Correct_Unit_PL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Term_Sub_Y);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Jump);
#else
void Jump(PLW *wk, s16 Time) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Hi_Jump);
#else
void Hi_Jump(PLW *wk, s16 Pl_Number, s16 Jump_Dir) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Start_Hi_Jump);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Air_Guard);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Jump_Attack);
#else
void Jump_Attack(PLW *wk, s16 Reaction, s16 Time_Data, u16 Lever_Data, s16 Jump_Dir) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Jump_Attack_Term);
#else
void Jump_Attack_Term(PLW *wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX, s16 Range_JY, s16 J_Lever_Data) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_SP_Jump_Attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_VS_Air_Attack);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Hi_Jump_Attack);
#else
void Hi_Jump_Attack(PLW *wk, s16 Reaction, s16 Time_Data, u16 Lever_Data, s16 Jump_Dir) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Hi_Jump_Attack_Term);
#else
void Hi_Jump_Attack_Term(PLW *wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX, s16 Range_JY, u16 J_Lever_Data) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Term_ABS_Distance);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Com_Add_Y);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ORO_JA_Term);
#else
void ORO_JA_Term(PLW *wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Lever_Data, s16 RJX, s16 RJY, u16 JLD) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ORO_HJA_Term);
#else
void ORO_HJA_Term(PLW *wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Lever_Data, s16 RJX, s16 RJY, u16 JLD) {
    not_implemented(__func__);
}
#endif


#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Command_Attack);
#else
void Command_Attack(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Hadou_Check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Resume_Lever);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", J_Command_Attack);
#else
void J_Command_Attack(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Rapid_Command_Attack);
#else
void Rapid_Command_Attack(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Shot, u16 Time) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Rapid);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Rapid_End_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Setup_Rapid_Time);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Rapid_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Rapid_End);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Check_Start_Command_Attack);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ORO_JCA_Term);
#else
void ORO_JCA_Term(PLW *wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RJX, s16 RJY, u16 JLD) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ORO_HJCA_Term);
#else
void ORO_HJCA_Term(PLW *wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RJX, s16 RJY, u16 JLD) {
    not_implemented(__func__);
}
#endif


#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Jump_Command_Attack_Term);
#else
void Jump_Command_Attack_Term(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RX, s16 RY, s16 Jump_Dir, s16 JRX, s16 JRY, u16 JLD) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Hi_Jump_Command_Attack_Term);
#else
void Hi_Jump_Command_Attack_Term(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RX, s16 RY, s16 Jump_Dir, s16 JRX, s16 JRY, u16 JLD) {
    not_implemented(__func__);
}
#endif

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

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", Next_Another_Menu);
#else
void Next_Another_Menu(PLW *wk, s16 Next_Action, u16 Next_Menu) {
    not_implemented(__func__);
}
#endif

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

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Sub", ETC_Term);
#else
void ETC_Term(PLW *wk, s16 Exit_No, u32 Next_Action, u16 Next_Menu) {
    not_implemented(__func__);
}
#endif

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
