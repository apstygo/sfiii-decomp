#ifndef COM_SUB_H
#define COM_SUB_H

#include "structs.h"
#include "types.h"

void End_Pattern(PLW *wk);
void Next_Be_Passive(PLW *wk, s32);
void Turn_Over_On(PLW *wk);
void Only_Shot(PLW *wk, s16 Lever_Data);
void Lever_On(PLW *wk, u16 LR_Lever, u16 UD_Lever);
void Lever_Off(PLW *wk);
void Pierce_On(PLW *wk);
void Setup_DENJIN_LEVEL(PLW *wk);
void Push_Shot(PLW *wk, s16 Power_Level);
s32 Check_Exit_DENJIN(PLW *wk);
void Keep_Away(PLW *wk, s16 Target_Pos, s16 Option);
void Setup_KA_Jump(PLW *wk);
void Setup_KA_Walk(PLW *wk);
void Search_Back_Term(PLW *wk, s16 Move_Value, s16 Next_Action, s16 Next_Menu);
void Approach_Walk(PLW *wk, s16 Target_Pos, s16 Option);
s32 Check_Arrival(PLW *wk, s16 Target_Pos, s16 Option);
void Walk(PLW *wk, u16 Lever, s16 Time, s16 unused);
void Forced_Guard(PLW *wk, s16 Guard_Type);
void Provoke(PLW *wk, s16 Lever);
void Normal_Attack(PLW *wk, s16 Reaction, u16 Lever_Data);
s32 Small_Jump_Measure(PLW *wk);
void Normal_Attack_SP(PLW *wk, s16 Reaction, u16 Lever_Data, s16 Time);
void Adjust_Attack(PLW *wk, s16 Reaction, u16 Lever_Data);
s32 Check_Squat(PLW *wk);
s32 Check_Start_Normal_Attack(PLW *wk, s16 Reaction, u16 Lever_Data); // extra arg unused
void Lever_Attack(PLW *wk, s16 Reaction, u16 Lever, u16 Lever_Data);
void Lever_Attack_SP(PLW *wk, s16 Reaction, u16 Lever, u16 Lever_Data, s16 Time);
s32 Setup_Guard_Lever(PLW *wk, u16 Lever);
s32 Check_Start_Lever_Attack(PLW *wk, u16 Lever, u16 Lever_Data); // extra args
void SA_Term(PLW *wk, u16 SA0, u16 SA1, u16 SA2, u16 Term_No);
s32 DENJIN_Check(PLW *wk, u16 SA2, u16 *xx, u16 Term_No);
s32 YAGYOU_Check(PLW *wk, s16 *xx, u16 Term_No);
s32 SA_Range_Check(PLW *wk, s16 SA_No, u16 Range);
void Check_SA(PLW *wk, s16 Next_Action, s16 Next_Menu);
void Check_EX(PLW *wk, s16 Next_Action, s16 Next_Menu);
void Check_SA_Full(PLW *wk, s16 Next_Action, s16 Next_Menu);
void Branch_Unit_Area(PLW *wk, s16 Next_Action, s16 Menu, s16 Menu_01, s16 Menu_02, s16 Menu_03);
void Com_Random_Select(PLW *wk, s16 Next_Action, s16 Menu_00, s16 Menu_01, s16 Menu_02, s16 Menu_03, s16 Rnd_Type);
void Branch_Wait_Area(PLW *wk, s16 Time_00, s16 Time_01, s16 Time_02, s16 Time_03);
void Wait(PLW *wk, s16 Time);
void Look(PLW *wk, s16 Time);
void Keep_Status(PLW *wk, u16 Lever_Data, s16 Option_Data);
void VS_Jump_Guard(PLW *wk);
void Wait_Lie(PLW *wk, u16 Lever_Data);
void Wait_Get_Up(PLW *wk, u16 Lever_Data, s16 Option);
s32 Check_Wait_Term(PLW *wk, s16 Option);
void Wait_Attack_Complete(PLW *wk, u16 Lever_Data, s16 Option);
s32 Check_Exit_Guard(PLW *wk, s16 Option);
void Short_Range_Attack(PLW *wk, s16 Reaction, u16 Lever_Data, s16 Next_Action, s16 Next_Menu);
void EM_Term(PLW *wk, s16 Range_X, s16 Range_Y, s16 Exit_Number, s16 Next_Action, s16 Next_Menu);
void SHELL_Term(PLW *wk, s16 Next_Command, s16 Exit_Number, s16 Next_Action, s16 Next_Menu, s16 unused); // unused arg
s32 Check_Term_Sub_Air(PLW *wk, s16 Distance, s16 Range);
s32 Check_Term_Sub(PLW *wk, s16 Distance, s16 Range);
s32 Correct_Unit_PL(PLW *wk);
s32 Check_Term_Sub_Y(PLW *wk, s16 Distance, s16 Range);
void Jump(PLW *wk, s16 Time);
void Hi_Jump(PLW *wk, s16 Pl_Number, s16 Jump_Dir);
s32 Check_Start_Hi_Jump(PLW *wk);
s32 Check_Air_Guard(PLW *wk);
void Jump_Attack(PLW *wk, s16 Reaction, s16 Time_Data, u16 Lever_Data, s16 Jump_Dir);
void Jump_Attack_Term(PLW *wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX,
                      s16 Range_JY, s16 J_Lever_Data);
s32 Check_SP_Jump_Attack(PLW *wk, s16 Lever_Data);
s32 Check_VS_Air_Attack(PLW *wk, s16 Range_JX, s16 Range_JY, s16 J_Lever_Data);
void Hi_Jump_Attack(PLW *wk, s16 Reaction, s16 Time_Data, u16 Lever_Data, s16 Jump_Dir);
void Hi_Jump_Attack_Term(PLW *wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX,
                         s16 Range_JY, u16 J_Lever_Data);
s32 Check_Term_ABS_Distance(PLW *wk);
s32 Check_Com_Add_Y(PLW *wk, s16 Pos_Y, s16 Range);
void ORO_JA_Term(PLW *wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Lever_Data, s16 RJX,
                 s16 RJY, u16 JLD);
void ORO_HJA_Term(PLW *wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Lever_Data, s16 RJX,
                  s16 RJY, u16 JLD);
void Command_Attack(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
s32 Hadou_Check(PLW *wk, u16 Tech_Number);
s32 Check_Resume_Lever(PLW *wk);
void J_Command_Attack(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
void Rapid_Command_Attack(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Shot, u16 Time);
void Check_Rapid(PLW *wk, u16 Tech_Number);
void Setup_Rapid_End_Term(PLW *wk, s16 Tech_Number);
s32 Setup_Rapid_Time(PLW *wk, u16 Tech_Number); // unused all args
void Rapid_Sub(PLW *wk);
s32 Check_Rapid_End(PLW *wk);
s32 Check_Start_Command_Attack(PLW *wk, s16 Reaction, u16 Tech_Number);
void ORO_JCA_Term(PLW *wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Tech_Number,
                  s16 Power_Level, s16 Ex_Shot, s16 RJX, s16 RJY, u16 JLD);
void ORO_HJCA_Term(PLW *wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Tech_Number,
                   s16 Power_Level, s16 Ex_Shot, s16 RJX, s16 RJY, u16 JLD);
void Jump_Command_Attack_Term(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RX, s16 RY,
                              s16 Jump_Dir, s16 JRX, s16 JRY, u16 JLD);
void Hi_Jump_Command_Attack_Term(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RX, s16 RY,
                                 s16 Jump_Dir, s16 JRX, s16 JRY, u16 JLD);
s32 Check_Landed(PLW *wk, s16 Reaction);
s32 Check_Dash_Hit(PLW *wk, u16 Tech_Number);
s32 Setup_Front_or_Back(PLW *wk, s16 xx);
s32 Check_Hit_Shell(PLW *wk, WORK_Other *tmw, u16 Tech_Number);
void Jump_Init(PLW *wk, s16 Jump_Dir);
s32 Command_Type_00(PLW *wk, s16 Power_Level, u16 Tech_Number, s16 Ex_Shot);
s32 Command_Type_06(PLW *wk, s16 Power_Level, u16 Tech_Number, s16 Ex_Shot); // unused last arg
s32 Command_Type_01(PLW *wk, s16 Power_Level, s16 Ex_Shot);                  // unused args
void Setup_Command_01(PLW *wk);
void Check_Store_Lever(PLW *wk, u16 Tech_Number, s16 Next_Action, s16 Next_Menu);
s32 Check_Store_Direction(PLW *wk, u16 lever, s16 time);
s32 Select_Combo_Speed(PLW *wk);
s32 Select_Reflection_Time(PLW *wk);
s32 Setup_Lv04(s16 xx);
s32 Setup_Lv08(s16 xx);
s32 Setup_Lv10(s16 xx);
s32 Setup_Lv18(s16 xx);
s32 Setup_VS_Catch_Data(PLW *wk);
s32 Setup_LP_Data(PLW *wk);
s32 Setup_WT_Data(PLW *wk);
void Ck_Distance(PLW *wk);
s32 Ck_Distance_Height(PLW *wk);
s32 Ck_Area(PLW *wk);
s32 Ck_Area_Shell(PLW *wk);
void Ck_Distance_Lv(PLW *wk);
void Ck_Distance_LvJ(PLW *wk);
void Next_End(PLW *wk);
void Next_Another_Menu(PLW *wk, s16 Next_Action, u16 Next_Menu);
void Reaction_Sub(PLW *wk, s16 Reaction, s16 Power_Level);
s32 Check_Meoshi_Attack(PLW *wk, s16 Reaction, s16 Power_Level); // unused last 2 args
s32 Get_Meoshi_Data(PLW *wk);
void Reaction_Exit_Sub(PLW *wk);
void Check_First_Menu(PLW *wk);
void Select_Active(PLW *wk);
s32 Check_SA_Active(PLW *wk, s16 *pl_id);
void Setup_Follow(PLW *wk, s16 Follow_Type);
void Decide_Follow_Menu(PLW *wk);
s32 Select_Passive(PLW *wk);
void Devide_Level(s16 xx);
void Setup_Random(PLW *wk);
s32 Check_Dramatic(PLW *wk, s16 PL_id);
s32 Check_Passive(PLW *wk);
s32 Check_Guard(PLW *wk);
s32 Check_Makoto(PLW *wk);
s32 Check_Flip_Term(PLW *wk, WORK *tmw);
s32 Setup_EM_Rank_Index(PLW *wk);
s32 Flip_Term_Correct(PLW *wk);
void Next_Be_Guard(PLW *wk, WORK *em, s16 Type_Of_Guard);
s32 Check_Flip_Tech(WORK *em);
void Next_Be_Flip(PLW *wk, s16 xx);
s32 Check_Diagonal_Shell(PLW *wk);
s32 Check_Ignore_Shell2(WORK_Other *tmw);
s32 Check_Shell(PLW *wk);
s32 Check_Shell_Another_in_Flip(PLW *wk);
s32 Check_Ignore_Shell(WORK_Other *tmw);
s32 Compute_Hit_Time(PLW *wk, WORK_Other *tmw);
s32 Decide_Shell_Guard(PLW *wk, WORK_Other *tmw); // unused second arg
void Guard_or_Jump_VS_Shell(PLW *wk, WORK_Other *tmw, s16 xx);
void Setup_Shell_Disposal(PLW *wk, WORK_Other *tmw);
void Next_Be_Shell_Guard(PLW *wk, WORK *tmw);
s32 Decide_Shell_Reaction(PLW *wk, WORK_Other *tmw, u16 dir_step); // unused second arg
s32 Ck_Distance_XX(s16 x1, s16 x2);
s32 Check_Behind(PLW *wk, WORK_Other *tmw);
void Setup_Lever_LR(PLW *wk, s16 PL_id, s16 Lever);
s32 Check_Exit_Term(PLW *wk, WORK *em, s16 Exit_No);
s32 VS_Jump_Term(PLW *wk, WORK *em, s16 *xx);
s32 Exit_Term_0000(PLW *wk, WORK *em);
s32 Exit_Term_0001(PLW *wk, WORK *em);
s32 Exit_Term_0002(PLW *wk, WORK *em);
s32 Exit_Term_0003(PLW *wk, WORK *em);
s32 Exit_Term_0004(PLW *wk, WORK *em);
s32 Exit_Term_0005(PLW *wk, WORK *em);
s32 Exit_Term_0006(PLW *wk, WORK *em);
s32 Exit_Term_0007(PLW *wk, WORK *em);
s32 Exit_Term_0008(PLW *wk, WORK *em);
s32 Check_Drop_Term(WORK *em, s16 Y);
s32 Check_SHINRYU(PLW *wk);
void Check_BOSS(PLW *wk, u32 Next_Action, u16 Next_Menu);
void Check_BOSS_EX(PLW *wk, u32 Next_Action, u16 Next_Menu);
void ETC_Term(PLW *wk, s16 Exit_No, u32 Next_Action, u16 Next_Menu);
s32 ETC_Term_0000(PLW *wk, WORK *em);
s32 ETC_Term_0001(PLW *wk, WORK *em);
s32 ETC_Term_0002(PLW *wk, WORK *em);
s32 ETC_Term_0003(PLW *wk, WORK *em);
s32 ETC_Term_0004(PLW *wk, WORK *em);
s32 ETC_Term_0005(PLW *wk, WORK *em);
s32 ETC_Term_0006(PLW *wk, WORK *em);
s32 ETC_Term_0007(PLW *wk, WORK *em);
s32 ETC_Term_0008(PLW *wk, WORK *em);
s32 ETC_Term_0009(PLW *wk, WORK *em);
s32 emLevelRemake(s32 now, s32 max, s32 exd);
s32 emGetMaxBlocking();

#endif
