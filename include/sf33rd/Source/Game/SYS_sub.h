#ifndef SYS_SUB_H
#define SYS_SUB_H

#include "structs.h"
#include "types.h"

extern const struct _SAVE_W Game_Default_Data; // size: 0x208, address: 0x5544C0

void Switch_Screen_Init(s32 /* unused */);         // Range: 0x3A1C50 -> 0x3A1C98
s32 Switch_Screen(u8 Wipe_Type);                   // Range: 0x3A1CA0 -> 0x3A1D08
s32 Switch_Screen_Revival(u8 Wipe_Type);           // Range: 0x3A1D10 -> 0x3A1D78
u16 Convert_User_Setting(s16 PL_id);               // Range: 0x3A1D80 -> 0x3A21B4
void Clear_Personal_Data(s16 PL_id);               // Range: 0x3A21C0 -> 0x3A2744
s16 Check_Count_Cut(s16 PL_id, s16 Limit);         // Range: 0x3A2750 -> 0x3A2850
void Disp_Personal_Count(s16 PL_id, s8 counter);   // Range: 0x3A2850 -> 0x3A28B8
void Setup_Play_Type();                            // Range: 0x3A28C0 -> 0x3A2910
void Clear_Flash_No();                             // Range: 0x3A2910 -> 0x3A2954
s32 Cut_Cut_Cut();                                 // Range: 0x3A2960 -> 0x3A29F0
void Score_Sub();                                  // Range: 0x3A29F0 -> 0x3A2D8C
void Disp_Win_Record();                            // Range: 0x3A2D90 -> 0x3A2F68
void Disp_Win_Record_Sub(u16 win_record, s16 zz);  // Range: 0x3A2F70 -> 0x3A31B8
s32 Button_Cut_EX(s16 *Timer, s16 Limit_Time);     // Range: 0x3A31C0 -> 0x3A32B0
s32 Setup_Target_PL();                             // Range: 0x3A32B0 -> 0x3A3320
void Setup_Final_Grade();                          // Range: 0x3A3320 -> 0x3A33D8
void Clear_Win_Type();                             // Range: 0x3A33E0 -> 0x3A34A4
void Clear_Disp_Ranking(s16 PL_id);                // Range: 0x3A34B0 -> 0x3A3554
void Meltw(u16 *s, u16 *d, s32 file_ptr);          // Range: 0x3A3560 -> 0x3A36F8
void Setup_ID();                                   // Range: 0x3A3700 -> 0x3A3740
void Game_Data_Init();                             // Range: 0x3A3740 -> 0x3A380C
void Setup_IO_ConvDataDefault(s32 id);             // Range: 0x3A3810 -> 0x3A388C
void Save_Game_Data();                             // Range: 0x3A3890 -> 0x3A3B80
void Copy_Save_w();                                // Range: 0x3A3B80 -> 0x3A3E3C
void Copy_Check_w();                               // Range: 0x3A3E40 -> 0x3A3FA8
void Setup_Default_Game_Option();                  // Range: 0x3A3FB0 -> 0x3A407F
s32 Check_Change_Contents();                       // Range: 0x3A4080 -> 0x3A4410
void cpRevivalTask();                              // Range: 0x3A4410 -> 0x3A4488
s32 Check_Menu_Task();                             // Range: 0x3A4490 -> 0x3A4550
void Setup_Limit_Time();                           // Range: 0x3A4550 -> 0x3A4618
void Setup_Training_Difficulty();                  // Range: 0x3A4620 -> 0x3A4720
void Setup_BG(s16 BG_INDEX, s16 X, s16 Y);         // Range: 0x3A4720 -> 0x3A48C4
void Setup_Virtual_BG(s16 BG_INDEX, s16 X, s16 Y); // Range: 0x3A48D0 -> 0x3A4A58
void BG_move();                                    // Range: 0x3A4A60 -> 0x3A4AF0
void BG_move_Ex(u8 ix);                            // Range: 0x3A4AF0 -> 0x3A4B18
void Basic_Sub();                                  // Range: 0x3A4B20 -> 0x3A4B90
void Basic_Sub_Ex();                               // Range: 0x3A4B90 -> 0x3A4BF0
s32 Check_PL_Load();                               // Range: 0x3A4BF0 -> 0x3A4C48
void BG_Draw_System();                             // Range: 0x3A4C50 -> 0x3A4E00
u16 Check_Demo_Data(s16 PL_id);                    // Range: 0x3A4E00 -> 0x3A4F18
void System_all_clear_Level_B();                   // Range: 0x3A4F20 -> 0x3A4F48
s16 Cut_Cut_C_Timer();                             // Range: 0x3A4F50 -> 0x3A4FA0
void Switch_Priority_76();                         // Range: 0x3A4FA0 -> 0x3A4FC0
s32 Cut_Cut_Sub(s16 xx);                           // Range: 0x3A4FC0 -> 0x3A506C
s32 Cut_Cut_Loser();                               // Range: 0x3A5070 -> 0x3A50E0
void njWaitVSync_with_N();                         // Range: 0x3A50E0 -> 0x3A50FC
void Soft_Reset_Sub();                             // Range: 0x3A5100 -> 0x3A5258
void Check_Replay();                               // Range: 0x3A52A0 -> 0x3A555C
void Check_Replay_Status(s16 PL_id, u8 Status);    // Range: 0x3A58D0 -> 0x3A5A30
s16 Check_SysDir_Page();                           // Range: 0x3A6060 -> 0x3A6174
void Clear_Flash_Init(s16 level);                  // Range: 0x3A6180 -> 0x3A61A4
s16 Clear_Flash_Sub();                             // Range: 0x3A61B0 -> 0x3A625C
void Copy_Key_Disp_Work();                         // Range: 0x3A6260 -> 0x3A631C
s32 Check_Extra_Setting();                         // Range: 0x3A6320 -> 0x3A64EC
void All_Clear_Random_ix();                        // Range: 0x3A64F0 -> 0x3A6508
void All_Clear_Timer();                            // Range: 0x3A6510 -> 0x3A6524
void All_Clear_ETC();                              // Range: 0x3A6530 -> 0x3A6548
void Setup_Net_Random_ix();                        // Range: 0x3A6550 -> 0x3A658C
s32 Request_Fade(u16 fade_code);                   // Range: 0x3A6590 -> 0x3A6600
s32 Check_Fade_Complete_SP();                      // Range: 0x3A6600 -> 0x3A6630
s32 Check_Fade_Complete();                         // Range: 0x3A6630 -> 0x3A6678
s32 Check_Ranking(s16 PL_id);                      // Range: 0x3A6680 -> 0x3A6CA0
void Disp_Digit16x24(u32 Score_Buff, s16 Disp_X, s16 Disp_Y, s16 Color);
void Disp_Copyright();                   // Range: 0x3A7AA0 -> 0x3A7B74
void Initialize_EM_Candidate(s16 PL_id); // Range: 0x3A7B80 -> 0x3A7E38
void Check_Same_CPU(s16 PL_id);          // Range: 0x3A8330 -> 0x3A85C0
void All_Clear_Suicide();                // Range: 0x3A85C0 -> 0x3A865C
void Clear_Break_Com(s16 PL_id);         // Range: 0x3A8660 -> 0x3A86DC
void Check_Off_Vib();                    // Range: 0x3A86E0 -> 0x3A86E8
void njWaitVSync_with_N();
void Meltw(u16 *s, u16 *d, s32 file_ptr);
void cpRevivalTask();
s32 Flash_Violent(WORK_Other * /* unused */, s32 /* unused */);

#endif
