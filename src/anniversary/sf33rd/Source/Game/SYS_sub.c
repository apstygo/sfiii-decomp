#include "sf33rd/Source/Game/SYS_sub.h"
#include "common.h"
#include "sf33rd/AcrSDK/ps2/flps2debug.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/debug/Debug.h"
#include "sf33rd/Source/Game/sc_sub.h"
#include "sf33rd/Source/Game/workuser.h"

// forward decls
void Get_Replay(s16 PL_id);
void Replay(s16 PL_id);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Convert_Data);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Switch_Screen_Init);
#else
void Switch_Screen_Init(s32 unused) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Switch_Screen);
#else
s32 Switch_Screen(u8 Wipe_Type) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Switch_Screen_Revival);
#else
s32 Switch_Screen_Revival(u8 Wipe_Type) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Convert_User_Setting);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Clear_Personal_Data);
#else
void Clear_Personal_Data(s16 PL_id) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Count_Cut);
#else
s16 Check_Count_Cut(s16 PL_id, s16 Limit) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Disp_Personal_Count);
#else
void Disp_Personal_Count(s16 PL_id, s8 counter) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Setup_Play_Type);
#else
void Setup_Play_Type() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Clear_Flash_No);
#else
void Clear_Flash_No() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Cut_Cut_Cut);
#else
s32 Cut_Cut_Cut() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Score_Sub);
#else
void Score_Sub() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", literal_401_00554498);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", literal_402_005544A0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Disp_Win_Record);
#else
void Disp_Win_Record() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Disp_Win_Record_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Button_Cut_EX);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Setup_Target_PL);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Setup_Final_Grade);
#else
void Setup_Final_Grade() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Clear_Win_Type);
#else
void Clear_Win_Type() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Clear_Disp_Ranking);
#else
void Clear_Disp_Ranking(s16 PL_id) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Meltw);
#else
void Meltw(u16 *s, u16 *d, s32 file_ptr) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Setup_ID);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Game_Data_Init);
#else
void Game_Data_Init() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Setup_IO_ConvDataDefault);
#else
void Setup_IO_ConvDataDefault(s32 id) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Time_Limit_Data);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Battle_Number_Data);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Save_Game_Data);
#else
void Save_Game_Data() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Copy_Save_w);
#else
void Copy_Save_w() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Copy_Check_w);
#else
void Copy_Check_w() {
    not_implemented(__func__);
}
#endif

const struct _SAVE_W Game_Default_Data = {
    { { { 0, 1, 2, 11, 3, 4, 5, 11 }, 0, { 0, 0, 0 } }, { { 0, 1, 2, 11, 3, 4, 5, 11 }, 0, { 0, 0, 0 } } },
    2,
    99,
    { 1, 1 },
    1,
    1,
    { 0, 0 },
    0,
    0,
    0,
    1,
    0,
    0,
    1,
    0,
    0,
    15,
    15,
    0,
    { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { { { 1, 3, 3, 0, 0, 1, 0, 0 },
        { 0, 0, 2, 2, 8, 8, 2, 0 },
        { 2, 2, 2, 2, 0, 0, 0, 0 },
        { 1, 1, 1, 1, 1, 1, 0, 0 } } },
    { { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 }, { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 }, { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 },
      { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 }, { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 }, { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 },
      { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 }, { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 }, { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 },
      { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 }, { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 }, { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 },
      { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 }, { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 }, { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 },
      { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 }, { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 }, { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 },
      { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 }, { { 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0 } },
    0
};

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Setup_Default_Game_Option);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Change_Contents);
#else
s32 Check_Change_Contents() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", cpRevivalTask);
#else
void cpRevivalTask() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Menu_Task);
#else
s32 Check_Menu_Task() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Setup_Limit_Time);
#else
void Setup_Limit_Time() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Setup_Training_Difficulty);
#else
void Setup_Training_Difficulty() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Setup_BG);
#else
void Setup_BG(s16 BG_INDEX, s16 X, s16 Y) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Setup_Virtual_BG);
#else
void Setup_Virtual_BG(s16 BG_INDEX, s16 X, s16 Y) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", BG_move);
#else
void BG_move() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", BG_move_Ex);
#else
void BG_move_Ex(u8 ix) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Basic_Sub);
#else
void Basic_Sub() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Basic_Sub_Ex);
#else
void Basic_Sub_Ex() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_PL_Load);
#else
s32 Check_PL_Load() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", BG_Draw_System);
#else
void BG_Draw_System() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Demo_Data);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", System_all_clear_Level_B);
#else
void System_all_clear_Level_B() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Cut_Cut_C_Timer);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Switch_Priority_76);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Cut_Cut_Sub);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Cut_Cut_Loser);
#else
s32 Cut_Cut_Loser() {
    not_implemented(__func__);
}
#endif

void njWaitVSync_with_N() {
    while (1) {}
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Soft_Reset_Sub);
#else
void Soft_Reset_Sub() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Reset_Sub0);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Replay);
#else
void Check_Replay() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Setup_Replay_Header);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Get_Replay_Header);

void Check_Replay_Status(s16 PL_id, u8 Status) {
    if (Demo_Flag == 0) {
        return;
    }

    switch (Status) {
    case 1:
        Get_Replay(PL_id);

        if ((Game_pause != 0x81) && Debug_w[0x21]) {
            flPrintColor(0xFFFFFFFF);
            flPrintL(16, 8, "HUMAN REC!");
            break;
        }

        break;

    case 3:
        Replay(PL_id);
        break;

    case 2:
        if (PL_id) {
            p2sw_0 = 0;
            break;
        }

        p1sw_0 = 0;
        break;

    case 99:
        flPrintColor(0xFFFFFF00);
        flPrintL(12, 20, "[REPLAY AREA FULL!!]");
        Disp_Rec_Time(PL_id, Rec_Time[PL_id]);
        break;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Get_Replay);
#else
void Get_Replay(s16 PL_id) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Setup_Replay_Buff);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Replay);
#else
void Replay(s16 PL_id) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_SysDir_Page);
#else
s16 Check_SysDir_Page() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Clear_Flash_Init);
#else
void Clear_Flash_Init(s16 level) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Clear_Flash_Sub);
#else
s16 Clear_Flash_Sub() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Copy_Key_Disp_Work);
#else
void Copy_Key_Disp_Work() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Extra_Setting);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", All_Clear_Random_ix);
#else
void All_Clear_Random_ix() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", All_Clear_Timer);
#else
void All_Clear_Timer() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", All_Clear_ETC);
#else
void All_Clear_ETC() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Setup_Net_Random_ix);
#else
void Setup_Net_Random_ix() {
    not_implemented(__func__);
}
#endif

s32 Request_Fade(u16 fade_code) {
    if (Fade_Flag == 0) {
        Fade_Flag = 1;
        Fade_R_No0 = Fade_R_No1 = 0;
        Fade_Number = fade_code;
        Forbid_Break = 1;
        fade_cont_init();
        return 1;
    }

    return 0;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Fade_Complete_SP);
#else
s32 Check_Fade_Complete_SP() {
    not_implemented(__func__);
}
#endif

s32 Check_Fade_Complete() {
    if (Fade_Flag) {
        fade_cont_main();
        return 0;
    }

    Forbid_Break = 1;
    return 1;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Ranking);
#else
s32 Check_Ranking(s16 PL_id) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Partners_Rank);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Sort_Score);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Sort_Wins);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Sort_CPU_Grade);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Sort_Grade);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_CPU_Grade_Score);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Grade_Score);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Disp_Digit16x24);

void Disp_Copyright() {
    s32 xres;

    switch (Country) {
    case 1:
    case 2:
    case 3:
    case 7:
    case 8:
        SSPutStrPro(1, 386, 208, 9, -1, "@CAPCOM CO., LTD. 1999, 2004 ALL RIGHTS RESERVED.");
        break;

    case 4:
    case 5:
    case 6:
        xres = SSPutStrPro(1, 386, 212, 9, -1, "@CAPCOM U.S.A., INC. 1999, 2004 ALL RIGHTS RESERVED.");
        SSPutStrPro(0, xres, 202, 9, -1, "@CAPCOM CO., LTD. 1999, 2004,");
        break;

    default:
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Initialize_EM_Candidate);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Setup_Candidate_Buff);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_EM_Buff);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_EM_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Same_CPU);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", All_Clear_Suicide);
#else
void All_Clear_Suicide() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Clear_Break_Com);
#else
void Clear_Break_Com(s16 PL_id) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Check_Off_Vib);
#else
void Check_Off_Vib() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Flash_Violent);
