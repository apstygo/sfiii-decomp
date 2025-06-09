#ifndef COM_SUB_H
#define COM_SUB_H

#include "structs.h"
#include "types.h"

void End_Pattern(PLW *wk);
void Turn_Over_On(PLW *wk);
void Only_Shot(PLW *wk, s16 Lever_Data);
void Lever_On(PLW *wk, u16 LR_Lever, u16 UD_Lever);
void Lever_Off(PLW *wk);
void Pierce_On(PLW *wk);
void Setup_DENJIN_LEVEL(PLW *wk);
void Push_Shot(PLW *wk, s16 Power_Level);
void Keep_Away(PLW *wk, s16 Target_Pos, s16 Option);
void Search_Back_Term(PLW *wk, s16 Move_Value, s16 Next_Action, s16 Next_Menu);
void Approach_Walk(PLW *wk, s16 Target_Pos, s16 Option);
void Walk(PLW *wk, u16 Lever, s16 Time, s16 unused);
void Provoke(PLW *wk, s16 Lever);
void Normal_Attack(PLW *wk, s16 Reaction, u16 Lever_Data);
void Normal_Attack_SP(PLW *wk, s16 Reaction, u16 Lever_Data, s16 Time);
void Adjust_Attack(PLW *wk, s16 Reaction, u16 Lever_Data);
void Lever_Attack(PLW *wk, s16 Reaction, u16 Lever, u16 Lever_Data);
void Lever_Attack_SP(PLW *wk, s16 Reaction, u16 Lever, u16 Lever_Data, s16 Time);
void SA_Term(PLW *wk, u16 SA0, u16 SA1, u16 SA2, u16 Term_No);
void Check_SA(PLW *wk, s16 Next_Action, s16 Next_Menu);
void Check_EX(PLW *wk, s16 Next_Action, s16 Next_Menu);
void Check_SA_Full(PLW *wk, s16 Next_Action, s16 Next_Menu);
void Branch_Unit_Area(PLW *wk, s16 Next_Action, s16 Menu, s16 Menu_01, s16 Menu_02, s16 Menu_03);
void Com_Random_Select(PLW *wk, s16 Next_Action, s16 Menu_00, s16 Menu_01, s16 Menu_02, s16 Menu_03, s16 Rnd_Type);
void Wait(PLW *wk, s16 Time);
void Look(PLW *wk, s16 Time);
void EM_Term(PLW *wk, s16 Range_X, s16 Range_Y, s16 Exit_Number, s16 Next_Action, s16 Next_Menu);
void Jump(PLW *wk, s16 Time);
void Hi_Jump(PLW *wk, s16 Pl_Number, s16 Jump_Dir);
void Jump_Attack(PLW *wk, s16 Reaction, s16 Time_Data, u16 Lever_Data, s16 Jump_Dir);
void Jump_Attack_Term(PLW *wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX, s16 Range_JY, s16 J_Lever_Data);
void Hi_Jump_Attack(PLW *wk, s16 Reaction, s16 Time_Data, u16 Lever_Data, s16 Jump_Dir);
void Hi_Jump_Attack_Term(PLW *wk, s16 Range_X, s16 Range_Y, s16 Reaction, u16 Lever_Data, s16 Jump_Dir, s16 Range_JX, s16 Range_JY, u16 J_Lever_Data);
void ORO_JA_Term(PLW *wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Lever_Data, s16 RJX, s16 RJY, u16 JLD);
void ORO_HJA_Term(PLW *wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Lever_Data, s16 RJX, s16 RJY, u16 JLD);
void Command_Attack(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
void ORO_JCA_Term(PLW *wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RJX, s16 RJY, u16 JLD);
void ORO_HJCA_Term(PLW *wk, s16 Reaction, s16 Jump_Dir, s16 JY, s16 Jump_Dir2, s16 RX, s16 RY, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RJX, s16 RJY, u16 JLD);
void J_Command_Attack(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot);
void Rapid_Command_Attack(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Shot, u16 Time);
void Jump_Command_Attack_Term(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RX, s16 RY, s16 Jump_Dir, s16 JRX, s16 JRY, u16 JLD);
void Hi_Jump_Command_Attack_Term(PLW *wk, s16 Reaction, u16 Tech_Number, s16 Power_Level, s16 Ex_Shot, s16 RX, s16 RY, s16 Jump_Dir, s16 JRX, s16 JRY, u16 JLD);
void Next_Another_Menu(PLW *wk, s16 Next_Action, u16 Next_Menu);
void ETC_Term(PLW *wk, s16 Exit_No, u32 Next_Action, u16 Next_Menu);

#endif
