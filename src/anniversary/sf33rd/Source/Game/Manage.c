#include "sf33rd/Source/Game/Manage.h"
#include "common.h"

const u32 Comp_Bonus_Data[11] = { 30000,  40000,  50000,  60000,  70000, 80000,
                                  90000, 100000, 110000, 120000, 130000 };

const u8 BIC_SA_Data[2][4] = { { 3, 5, 7, 9 }, { 1, 1, 1, 1 } };

const u32 Ball_Perfect_PTS[2][5] = { { 20000, 30000, 50000, 80000, 120000 },
                                     { 10000, 20000, 40000, 80000, 160000 } };

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Management);
#else
s32 Game_Management() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Clear_1Stage_Work);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_2_0);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Wait_Seek_Time);
#else
s32 Wait_Seek_Time() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_2_1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_2_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_2_3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_2_4);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", setFinishType);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_5th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_5_0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_5_1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_5_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_5_3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_5_4);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_5_5);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_5_6);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_5_7);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_6th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_7th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_7_0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_7_1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_7_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Check_Disp_Combo);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_7_3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_7_4);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_7_5);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_7_6);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_7_7);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_7_8);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_7_9);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_8th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_8_0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_8_1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_81_0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_81_1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_81_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_81_3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_8_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_8_3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_9th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_10th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Check_Naming);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Check_Ending);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Check_Ending_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Additional_Bonus);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Setup_Comp_Bonus);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", request_center_message);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Setup_Win_Mark);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Check_Perfect);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Update_VS_Data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", BGM_Fade_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", BGM_Control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Setup_BGM_Fade_In);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Check_Stage_BGM);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Control_Music_Fade);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Check_Conclusion_Type);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", chkComWins);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Update_BI_Term);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Ck_Win_Record);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Update_Level_Control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Judge_Next_Disposal);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Quick_Entry);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Check_Entry_Again);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Loser_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Be_Continue);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Disp_Winner);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Pool_Score);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Check_Break_Into_CPU);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Judge_Winner);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Check_Disp_Winner);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Check_Fade_Out_BGM);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Check_BI_Grade);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_11th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_12th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_12_0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_12_1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_12_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_12_3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_12_4);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_12_5);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_12_7);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_12_8);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Check_Bonus_Perfect);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Disp_Bonus_Perfect);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Flash_Bonus_Perfect);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Setup_Final_Score);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Bonus_Cut_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Check_Time_Over);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", complete_victory_pause);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Manage", Game_Manage_13th);
