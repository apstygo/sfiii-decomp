#ifndef UNKNOWN_H
#define UNKNOWN_H

#include "sf33rd/AcrSDK/common/memmgr.h"
#include "sf33rd/AcrSDK/common/plcommon.h"
#include "structs.h"
#include "types.h"

// .rodata

extern const u8 stage_bgw_number[22][3];       // size: 0x42, address: 0x4E6FD0
extern const u8 Dir_Menu_Max_Data[10][7];      // size: 0x46, address: 0x504FB0
extern const SystemDir Dir_Default_Data;       // size: 0x48, address: 0x505000
extern const u8 Page_Data[10];                 // size: 0xA, address: 0x505048
extern const Permission Permission_PL_Data;    // size: 0x18, address: 0x5224C0
extern const s8 plid_data[20];                 // size: 0x14, address: 0x54B230
extern const u8 PL_Color_Data[20];             // size: 0x14, address: 0x552050
extern const struct _SAVE_W Game_Default_Data; // size: 0x208, address: 0x5544C0
extern const FLPAD_CONFIG fltpad_config_basic; // size: 0x2C, address: 0x55F530
extern const u32 flpad_io_map[25];             // size: 0x64, address: 0x55F560

// .sbss

extern MessageTable *msgSysDirTbl[];      // size: 0x4, address: 0x575620
extern MessageTable *msgExtraTbl[];       // size: 0x4, address: 0x575624
extern s32 bgPalCodeOffset[8];            // size: 0x20, address: 0x578AA0
extern s8 seraph_flag;                    // size: 0x1, address: 0x578C6C
extern MVXY bg_mvxy;                      // size: 0x18, address: 0x578C80
extern s16 base_y_pos;                    // size: 0x2, address: 0x578CC4
extern UNK_Data *parabora_own_table[20];  // size: 0x50, address: 0x578CD0
extern MessageData Message_Data[4];       // size: 0x30, address: 0x578ED0
extern s8 ca_check_flag;                  // size: 0x1, address: 0x5790F4
extern IO io_w;                           // size: 0x6C, address: 0x579230
extern u8 r_no_plus;                      // size: 0x1, address: 0x5792B8
extern UNK_14 rank_name_w[2];             // size: 0x8, address: 0x5792E8
extern s16 Name_00[2];                    // size: 0x4, address: 0x579374
extern NAME_WK name_wk[2];                // size: 0x64, address: 0x579390
extern s16 title_tex_flag;                // size: 0x2, address: 0x579464
extern s16 op_timer0;                     // size: 0x2, address: 0x579468
extern s16 appear_type;                   // size: 0x2, address: 0x5795C8
extern s16 pcon_rno[4];                   // size: 0x8, address: 0x5795D0
extern PPWORK ppwork[2];                  // size: 0x68, address: 0x579610
extern s16 EXE_flag;                      // size: 0x2, address: 0x579870
extern s16 bgm_level;                     // size: 0x2, address: 0x5798D0
extern s16 se_level;                      // size: 0x2, address: 0x5798D4
extern TPU *tpu_free;                     // size: 0x4, address: 0x579A8C
extern u8 *texcash_melt_buffer;           // size: 0x4, address: 0x579A90
extern s32 Zoom_Base_Position_Z;          // size: 0x4, address: 0x579AC4
extern s32 Zoom_Base_Position_Y;          // size: 0x4, address: 0x579AC8
extern s32 Zoom_Base_Position_X;          // size: 0x4, address: 0x579ACC
extern f32 Frame_Zoom_Y;                  // size: 0x4, address: 0x579AD0
extern f32 Frame_Zoom_X;                  // size: 0x4, address: 0x579AD4
extern f32 SA_Zoom_Y;                     // size: 0x4, address: 0x579AD8
extern f32 SA_Zoom_X;                     // size: 0x4, address: 0x579ADC
extern f32 Screen_Zoom_Y;                 // size: 0x4, address: 0x579AE0
extern f32 Screen_Zoom_X;                 // size: 0x4, address: 0x579AE4
extern u8 Screen_PAL;                     // size: 0x1, address: 0x579C20
extern u16 PLsw[2][2];                    // size: 0x8, address: 0x579C28
extern u32 Interrupt_Timer;               // size: 0x4, address: 0x579C34
extern u16 p4sw_buff;                     // size: 0x2, address: 0x579C38
extern u16 p3sw_buff;                     // size: 0x2, address: 0x579C3C
extern u16 p2sw_buff;                     // size: 0x2, address: 0x579C40
extern u16 p1sw_buff;                     // size: 0x2, address: 0x579C44
extern u8 Interrupt_Flag;                 // size: 0x1, address: 0x579C48
extern s16 Correct_Y[4];                  // size: 0x8, address: 0x579C50
extern s16 Correct_X[4];                  // size: 0x8, address: 0x579C58
extern u8 Turbo_Timer;                    // size: 0x1, address: 0x579C60
extern u8 Turbo;                          // size: 0x1, address: 0x579C64
extern u8 No_Trans;                       // size: 0x1, address: 0x579C68
extern u8 Disp_Size_V;                    // size: 0x1, address: 0x579C6C
extern u8 Disp_Size_H;                    // size: 0x1, address: 0x579C70
extern s32 Y_Adjust_Buff[3];              // size: 0xC, address: 0x579C78
extern s32 X_Adjust_Buff[3];              // size: 0xC, address: 0x579C88
extern s32 Y_Adjust;                      // size: 0x4, address: 0x579C94
extern s32 X_Adjust;                      // size: 0x4, address: 0x579C98
extern u8 Interface_Type[2];              // size: 0x2, address: 0x579C9C
extern u32 system_timer;                  // size: 0x4, address: 0x579CA0
extern u8 Process_Counter;                // size: 0x1, address: 0x579CA4
extern u16 p4sw_1;                        // size: 0x2, address: 0x579CA8
extern u16 p4sw_0;                        // size: 0x2, address: 0x579CAC
extern u16 p3sw_1;                        // size: 0x2, address: 0x579CB0
extern u16 p3sw_0;                        // size: 0x2, address: 0x579CB4
extern u16 p2sw_1;                        // size: 0x2, address: 0x579CB8
extern u16 p2sw_0;                        // size: 0x2, address: 0x579CBC
extern u16 p1sw_1;                        // size: 0x2, address: 0x579CC0
extern u16 p1sw_0;                        // size: 0x2, address: 0x579CC4
extern struct _VM_W vm_w;                 // size: 0x6C, address: 0x579D20
extern struct _SYSTEM_W sys_w;            // size: 0x1C, address: 0x579D90
extern u32 current_task_num;              // size: 0x4, address: 0x579DAC
extern u8 plsw_01[2];                     // size: 0x4, address: 0x579DD0
extern u8 plsw_00[2];                     // size: 0x4, address: 0x579DD4
extern u16 VS_Win_Record[2];              // size: 0x4, address: 0x579DD8
extern u16 IO_Result;                     // size: 0x2, address: 0x579DDC
extern u16 Keep_Grade[2];                 // size: 0x4, address: 0x579DE0
extern s16 Cont_Timer;                    // size: 0x2, address: 0x579E18
extern u16 Result_Timer[2];               // size: 0x4, address: 0x579E30
extern s16 Offset_BG_X[6];                // size: 0xC, address: 0x579E38
extern s16 Target_BG_X[6];                // size: 0xC, address: 0x579E48
extern u16 WGJ_Win;                       // size: 0x2, address: 0x579E54
extern u16 Win_Record[2];                 // size: 0x4, address: 0x579E5C
extern s16 Stock_Com_Color[2];            // size: 0x4, address: 0x579E78
extern s16 Bonus_Game_ex_result;          // size: 0x2, address: 0x579E7C
extern s16 Bonus_Game_result;             // size: 0x2, address: 0x579E9C
extern s16 Bonus_Game_Work;               // size: 0x2, address: 0x579EA0
extern s16 Bonus_Game_Flag;               // size: 0x2, address: 0x579EA4
extern s16 Max_vitality;                  // size: 0x2, address: 0x579EA8
extern s16 DE_X[2];                       // size: 0x4, address: 0x579EB0
extern s16 Random_ix32_ex;                // size: 0x2, address: 0x579EB4
extern s16 Limit_Time;                    // size: 0x2, address: 0x579EC0
extern s16 Insert_Y;                      // size: 0x2, address: 0x579F90
extern s16 M_Timer;                       // size: 0x2, address: 0x579FBC
extern s16 Random_ix32;                   // size: 0x2, address: 0x579FC0
extern s16 Random_ix16;                   // size: 0x2, address: 0x579FC4
extern s16 Unit_Of_Timer;                 // size: 0x2, address: 0x579FEC
extern s16 Sel_Arts_Complete[2];          // size: 0x4, address: 0x57A000
extern s16 ENTRY_X;                       // size: 0x2, address: 0x57A014
extern s16 F_Timer[2];                    // size: 0x4, address: 0x57A018
extern s16 E_Timer;                       // size: 0x2, address: 0x57A01C
extern s16 D_Timer;                       // size: 0x2, address: 0x57A028
extern s16 G_Timer;                       // size: 0x2, address: 0x57A02C
extern s16 Round_Level;                   // size: 0x2, address: 0x57A038
extern s16 Time_in_Time;                  // size: 0x2, address: 0x57A03C
extern s16 Control_Time;                  // size: 0x2, address: 0x57A040
extern u16 Game_timer;                    // size: 0x2, address: 0x57A044
extern u8 Pause_Type;                     // size: 0x1, address: 0x57A048
extern u8 CPU_Rec[2];                     // size: 0x2, address: 0x57A04C
extern u8 Forbid_Reset;                   // size: 0x1, address: 0x57A050
extern u8 CPU_Time_Lag[2];                // size: 0x2, address: 0x57A054
extern u8 Decide_ID;                      // size: 0x1, address: 0x57A064
extern u8 Reset_Bootrom;                  // size: 0x1, address: 0x57A068
extern s8 Menu_Page_Buff;                 // size: 0x1, address: 0x57A06C
extern u8 End_Training;                   // size: 0x1, address: 0x57A070
extern u8 Disp_Attack_Data;               // size: 0x1, address: 0x57A078
extern u8 Training_ID;                    // size: 0x1, address: 0x57A07C
extern u8 Pause_Down;                     // size: 0x1, address: 0x57A080
extern s8 Vital_Handicap[6][2];           // size: 0xC, address: 0x57A090
extern u8 Direction_Working[6];           // size: 0x6, address: 0x57A0A0
extern u8 Page_Max;                       // size: 0x1, address: 0x57A0A8
extern u8 Play_Mode;                      // size: 0x1, address: 0x57A0AC
extern u8 Present_Mode;                   // size: 0x1, address: 0x57A0B0
extern s8 VS_Stage;                       // size: 0x1, address: 0x57A0B4
extern u8 reset_NG_flag;                  // size: 0x1, address: 0x57A0B8
extern s8 Menu_Max;                       // size: 0x1, address: 0x57A0BC
extern s8 Menu_Page;                      // size: 0x1, address: 0x57A0C0
extern u8 Mode_Type;                      // size: 0x1, address: 0x57A0C4
extern s8 Menu_Cursor_Move;               // size: 0x1, address: 0x57A0D8
extern u8 Play_Game;                      // size: 0x1, address: 0x57A0DC
extern u8 Disappear_LOGO;                 // size: 0x1, address: 0x57A0E4
extern u8 Replay_Status[2];               // size: 0x2, address: 0x57A0E8
extern s8 Menu_Cursor_Y[2];               // size: 0x2, address: 0x57A0EC
extern s8 Menu_Cursor_X[2];               // size: 0x2, address: 0x57A0F0
extern u8 Unsubstantial_BG[4];            // size: 0x4, address: 0x57A0F4
extern s8 Convert_Buff[4][2][12];         // size: 0x60, address: 0x57A100
extern u8 F_No3[2];                       // size: 0x2, address: 0x57A1CC
extern u8 F_No2[2];                       // size: 0x2, address: 0x57A1D0
extern u8 F_No1[2];                       // size: 0x2, address: 0x57A1D4
extern u8 F_No0[2];                       // size: 0x2, address: 0x57A1D8
extern u8 PL_Wins[2];                     // size: 0x2, address: 0x57A1F4
extern u8 Cont_No[4];                     // size: 0x4, address: 0x57A1F8
extern u8 ixbfw_cut;                      // size: 0x1, address: 0x57A1FC
extern u8 test_flag;                      // size: 0x1, address: 0x57A200
extern u8 Stop_Update_Score;              // size: 0x1, address: 0x57A204
extern u8 Lamp_No;                        // size: 0x1, address: 0x57A210
extern u8 Disp_Cockpit;                   // size: 0x1, address: 0x57A218
extern u8 Conclusion_Flag;                // size: 0x1, address: 0x57A248
extern u8 Exit_Menu;                      // size: 0x1, address: 0x57A24C
extern u8 Play_Type;                      // size: 0x1, address: 0x57A250
extern u8 Pause_ID;                       // size: 0x1, address: 0x57A254
extern u8 Pause;                          // size: 0x1, address: 0x57A258
extern u8 Game_difficulty;                // size: 0x1, address: 0x57A25C
extern u8 Game_pause;                     // size: 0x1, address: 0x57A260
extern u8 Menu_Suicide[4];                // size: 0x4, address: 0x57A264
extern u8 Connect_Status;                 // size: 0x1, address: 0x57A268
extern s8 Cursor_Y_Pos[2][4];             // size: 0x8, address: 0x57A278
extern u8 M_No[4];                        // size: 0x4, address: 0x57A29C
extern u8 D_No[4];                        // size: 0x4, address: 0x57A2A0
extern u8 G_No[4];                        // size: 0x4, address: 0x57A2A4
extern u8 S_No[4];                        // size: 0x4, address: 0x57A2A8
extern u8 C_No[4];                        // size: 0x4, address: 0x57A2AC
extern u8 E_No[4];                        // size: 0x4, address: 0x57A2B0
extern u8 E_Number[2][4];                 // size: 0x8, address: 0x57A2B8
extern s8 Request_Disp_Rank[2][4];        // size: 0x8, address: 0x57A2E0
extern s8 Rank_In[2][4];                  // size: 0x8, address: 0x57A2E8
extern s8 Suicide[8];                     // size: 0x8, address: 0x57A2F8
extern u8 Continue_Cut[2];                // size: 0x2, address: 0x57A304
extern s8 Last_Selected_EM[2];            // size: 0x2, address: 0x57A30C
extern u8 WGJ_Target;                     // size: 0x1, address: 0x57A338
extern u8 Continue_Count_Down[2];         // size: 0x2, address: 0x57A33C
extern u8 GO_No[4];                       // size: 0x4, address: 0x57A344
extern u8 Scene_Cut;                      // size: 0x1, address: 0x57A348
extern u8 Battle_Q[2];                    // size: 0x2, address: 0x57A364
extern u8 SC_No[4];                       // size: 0x4, address: 0x57A388
extern u8 Bonus_Type;                     // size: 0x1, address: 0x57A3B4
extern s8 Stock_Com_Arts[2];              // size: 0x2, address: 0x57A3C4
extern u8 End_PL;                         // size: 0x1, address: 0x57A3C8
extern s8 Stage_Cheap_Finish[2];          // size: 0x2, address: 0x57A3D0
extern s8 Stage_Perfect_Finish[2];        // size: 0x2, address: 0x57A3D4
extern s8 Stage_Lost_Round[2];            // size: 0x2, address: 0x57A3D8
extern u8 Extra_Break;                    // size: 0x1, address: 0x57A3E0
extern u8 Combo_Demo_Flag;                // size: 0x1, address: 0x57A3EC
extern u8 Get_Demo_Index;                 // size: 0x1, address: 0x57A3F0
extern s8 Bonus_Game_Complete;            // size: 0x1, address: 0x57A3F4
extern s8 Cheap_Finish[2];                // size: 0x2, address: 0x57A400
extern s8 Perfect_Finish[2];              // size: 0x2, address: 0x57A404
extern s8 Stage_SA_Finish[2];             // size: 0x2, address: 0x57A408
extern s8 Super_Arts_Finish[2];           // size: 0x2, address: 0x57A40C
extern s8 Lost_Round[2];                  // size: 0x2, address: 0x57A410
extern s8 Deley_Shot_Timer[2];            // size: 0x2, address: 0x57A414
extern s8 Deley_Shot_No[2];               // size: 0x2, address: 0x57A418
extern u8 Final_Result_id;                // size: 0x1, address: 0x57A480
extern u8 Weak_PL;                        // size: 0x1, address: 0x57A48C
extern u8 CC_Value[2];                    // size: 0x2, address: 0x57A494
extern u8 paring_bonus_r[2];              // size: 0x2, address: 0x57A4B0
extern u8 paring_counter[2];              // size: 0x2, address: 0x57A4B4
extern s8 Break_Com[2][20];               // size: 0x28, address: 0x57A4C0
extern s8 No_Death;                       // size: 0x1, address: 0x57A51C
extern s8 PB_Music_Off;                   // size: 0x1, address: 0x57A520
extern s8 Round_Operator[2];              // size: 0x2, address: 0x57A54C
extern s8 Operator_Status[2];             // size: 0x2, address: 0x57A550
extern s8 Stop_SG;                        // size: 0x1, address: 0x57A554
extern u8 Usage;                          // size: 0x1, address: 0x57A55C
extern s8 Player_Color[2];                // size: 0x2, address: 0x57A578
extern s8 Naming_Cut[2];                  // size: 0x2, address: 0x57A580
extern s8 Ignore_Entry[2];                // size: 0x2, address: 0x57A58C
extern u8 Continue_Coin[2];               // size: 0x2, address: 0x57A590
extern s8 Stop_Combo;                     // size: 0x1, address: 0x57A59C
extern s8 Exec_Wipe;                      // size: 0x1, address: 0x57A5D8
extern s8 Demo_Time_Stop;                 // size: 0x1, address: 0x57A5E0
extern u8 Country;                        // size: 0x1, address: 0x57A5E4
extern s8 Select_Demo_Index;              // size: 0x1, address: 0x57A5E8
extern s8 COM_id;                         // size: 0x1, address: 0x57A5F4
extern s8 Player_Number;                  // size: 0x1, address: 0x57A604
extern s8 Last_Player_id;                 // size: 0x1, address: 0x57A608
extern s8 Player_id;                      // size: 0x1, address: 0x57A60C
extern s8 Select_Timer;                   // size: 0x1, address: 0x57A618
extern s8 Demo_Stage_Index;               // size: 0x1, address: 0x57A628
extern s8 Demo_PL_Index;                  // size: 0x1, address: 0x57A62C
extern s32 Next_Demo;                     // size: 0x4, address: 0x57A630
extern s8 Demo_Flag;                      // size: 0x1, address: 0x57A634
extern s8 E_07_Flag[2];                   // size: 0x2, address: 0x57A63C
extern s8 Rank_Type;                      // size: 0x1, address: 0x57A658
extern s8 Demo_Type;                      // size: 0x1, address: 0x57A65C
extern u8 Present_Rank[2];                // size: 0x2, address: 0x57A668
extern s8 Request_G_No;                   // size: 0x1, address: 0x57A66C
extern s8 Request_E_No;                   // size: 0x1, address: 0x57A670
extern s8 Personal_Timer[2];              // size: 0x2, address: 0x57A674
extern s8 Cover_Timer;                    // size: 0x1, address: 0x57A678
extern s8 Switch_Type;                    // size: 0x1, address: 0x57A67C
extern s8 Next_Step;                      // size: 0x1, address: 0x57A680
extern s8 Champion;                       // size: 0x1, address: 0x57A690
extern s8 New_Challenger;                 // size: 0x1, address: 0x57A694
extern s8 LOSER;                          // size: 0x1, address: 0x57A698
extern s8 WINNER;                         // size: 0x1, address: 0x57A69C
extern s8 judge_flag;                     // size: 0x1, address: 0x57A6A0
extern s8 Continue_Count[2];              // size: 0x2, address: 0x57A6B4
extern s8 Request_Break[2];               // size: 0x2, address: 0x57A6B8
extern s8 Forbid_Break;                   // size: 0x1, address: 0x57A6BC
extern s8 Super_Arts[2];                  // size: 0x2, address: 0x57A6C0
extern s8 Fade_Flag;                      // size: 0x1, address: 0x57A6C4
extern u8 Round_num;                      // size: 0x1, address: 0x57A6CC
extern u8 Allow_a_battle_f;               // size: 0x1, address: 0x57A6D0
extern u8 My_char[2];                     // size: 0x2, address: 0x57A6D4
extern s8 Break_Into;                     // size: 0x1, address: 0x57A6D8
extern s8 Loser_id;                       // size: 0x1, address: 0x57A6E4
extern s8 Winner_id;                      // size: 0x1, address: 0x57A6E8
extern u32 WGJ_Score;                     // size: 0x4, address: 0x57A70C
extern u32 Stage_Stock_Score[2];          // size: 0x8, address: 0x57A728
extern u32 Score[2][3];                   // size: 0x18, address: 0x57A760
extern u32 Record_Timer;                  // size: 0x4, address: 0x57A810
extern u8 check_screen_L;                 // size: 0x1, address: 0x57A828
extern u8 check_screen_S;                 // size: 0x1, address: 0x57A82C
extern s8 Slow_Timer;                     // size: 0x1, address: 0x57A830
extern u8 sysSLOW;                        // size: 0x1, address: 0x57A834
extern u8 sysFF;                          // size: 0x1, address: 0x57A838
extern s8 Debug_w[72];                    // size: 0x48, address: 0x57A860
extern s16 *dctex_linear;                 // size: 0x4, address: 0x57A950
extern MPP mpp_w;                         // size: 0x4C, address: 0x57A9F0
extern s32 system_init_level;             // size: 0x4, address: 0x57AA3C
extern u32 flDebugTrueTime[4];            // size: 0x10, address: 0x57AB50
extern s32 flPS2FlipCancelFlag;           // size: 0x4, address: 0x57AB78
extern u32 flPs2FBA;                      // size: 0x4, address: 0x57AB84
extern s32 flClayNum;                     // size: 0x4, address: 0x57AB88
extern s32 flPTNum;                       // size: 0x4, address: 0x57AE38
extern FLPS2VIF1Control flPs2VIF1Control; // size: 0x3C, address: 0x57AE50
extern FL_FMS flFMS;                      // size: 0x18, address: 0x57AEB0
extern u32 flSystemRenderOperation;       // size: 0x4, address: 0x57AEC8
extern u32 flSystemRenderState;           // size: 0x4, address: 0x57AECC
extern u32 flLoadCount;                   // size: 0x4, address: 0x57AED8
extern plContext flFrameBuf;              // size: 0x48, address: 0x57AEF0
extern s32 flFrame;                       // size: 0x4, address: 0x57AF38
extern s32 flHeight;                      // size: 0x4, address: 0x57AF3C
extern s32 flWidth;                       // size: 0x4, address: 0x57AF40
extern s32 flCTNum;                       // size: 0x4, address: 0x57AF44
extern TARPAD tarpad_root[2];             // size: 0x68, address: 0x57B040
extern PPGDataList ppgCapLogoList;        // size: 0x8, address: 0x57B308
extern Palette ppgCapLogoPal;             // size: 0x14, address: 0x57B310
extern Texture ppgCapLogoTex;             // size: 0x20, address: 0x57B330
extern PPGDataList ppgAdxList;            // size: 0x8, address: 0x57B350
extern PPGDataList ppgWarList;            // size: 0x8, address: 0x57B358
extern Palette ppgAdxPal;                 // size: 0x14, address: 0x57B360
extern Palette ppgWarPal;                 // size: 0x14, address: 0x57B380
extern Texture ppgWarTex;                 // size: 0x20, address: 0x57B3A0

// .bss

extern MEM_BLOCK sysmemblock[4096]; // size: 0x10000, address: 0x584C80

extern BG bg_w;                                   // size: 0x428, address: 0x595830
extern CharInitData char_init_data[23];           // size: 0x8FC, address: 0x595C60
extern f32 PrioBase[128];                         // size: 0x200, address: 0x5E3F50
extern PLW plw[2];                                // size: 0x8D8, address: 0x5E4D20
extern RCKeyWork rckey_work[64];                  // size: 0x300, address: 0x5E5600
extern RANK_DATA Ranking_Data[20];                // size: 0x190, address: 0x5E5900
extern struct _SAVE_W save_w[6];                  // size: 0xC30, address: 0x6B4E80
extern Permission permission_player[6];           // size: 0x90, address: 0x6B5AB0
extern SystemDir system_dir[6];                   // size: 0x1B0, address: 0x6B5B40
extern _REPLAY_W Replay_w;                        // size: 0x7448, address: 0x6B5CF0
extern struct _REP_GAME_INFOR Rep_Game_Infor[11]; // size: 0x18C, address: 0x6BD140
extern struct _TASK task[11];                     // size: 0xDC, address: 0x6BD2D0
extern u8 Order_Dir[148];                         // size: 0x94, address: 0x6BD5F0
extern u8 Order_Timer[148];                       // size: 0x94, address: 0x6BD690
extern u8 Order[148];                             // size: 0x94, address: 0x6BD730
extern FLTexture flPalette[1088];                 // size: 0xFF00, address: 0x6C56D0
extern FLTexture flTexture[256];                  // size: 0x3C00, address: 0x6D55D0
extern FLPS2DrawStart flPs2DrawStart;             // size: 0x140, address: 0x6E24D0
extern FLPS2DB flPs2Db[2];                        // size: 0x140, address: 0x6E2610
extern FLPS2State flPs2State;                     // size: 0x470, address: 0x6E2750

#endif
