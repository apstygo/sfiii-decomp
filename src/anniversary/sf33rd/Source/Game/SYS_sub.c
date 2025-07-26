#include "sf33rd/Source/Game/SYS_sub.h"
#include "common.h"
#include "sf33rd/AcrSDK/common/mlPAD.h"
#include "sf33rd/AcrSDK/ps2/flps2debug.h"
#include "sf33rd/Source/Game/COM_DATU.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/RANKING.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/debug/Debug.h"
#include "sf33rd/Source/Game/main.h"
#include "sf33rd/Source/Game/sc_sub.h"
#include "sf33rd/Source/Game/workuser.h"

u8 Candidate_Buff[16];

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

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Convert_User_Setting);
#else
u16 Convert_User_Setting(s16 PL_id) {
    not_implemented(__func__);
}
#endif

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

void Game_Data_Init() {
    s32 ix;

    Setup_Default_Game_Option();
    mpp_w.cutAnalogStickData = 0;

    if ((flpad_adr[0][0].sw & 0x330) == 0x330) {
        mpp_w.cutAnalogStickData = 1;
    } else if ((flpad_adr[0][1].sw & 0x330) == 0x330) {
        mpp_w.cutAnalogStickData = 1;
    }

    if (mpp_w.cutAnalogStickData) {
        for (ix = 0; ix < 6; ix++) {
            save_w[ix].AnalogStick = 0;
        }
    }

    Ranking_Init();
    Copy_Save_w();
}

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

void Copy_Save_w() {
    s16 ix;

    Convert_Buff[0][0][0] = save_w[1].Difficulty;
    Convert_Buff[0][0][2] = save_w[1].Battle_Number[0];
    Convert_Buff[0][0][3] = save_w[1].Battle_Number[1];
    Convert_Buff[0][0][4] = save_w[1].Damage_Level;
    Convert_Buff[0][0][5] = save_w[1].GuardCheck;
    Convert_Buff[0][0][6] = save_w[1].AnalogStick;
    Convert_Buff[0][0][7] = save_w[1].Handicap;
    Convert_Buff[0][0][8] = save_w[1].Partner_Type[0];
    Convert_Buff[0][0][9] = save_w[1].Partner_Type[1];
    mpp_w.useAnalogStickData = save_w[1].AnalogStick;

    switch (save_w[1].Time_Limit) {
    case 30:
        Convert_Buff[0][0][1] = 0;
        break;
    case 60:
        Convert_Buff[0][0][1] = 1;
        break;
    case 99:
        Convert_Buff[0][0][1] = 2;
        break;
    default:
        Convert_Buff[0][0][1] = 3;
        break;
    }

    for (ix = 0; ix < 8; ix++) {
        Convert_Buff[1][0][ix] = save_w[1].Pad_Infor[0].Shot[ix];
        Convert_Buff[1][1][ix] = save_w[1].Pad_Infor[1].Shot[ix];
    }

    Convert_Buff[1][0][8] = save_w[1].Pad_Infor[0].Vibration;
    Convert_Buff[1][1][8] = save_w[1].Pad_Infor[1].Vibration;
    Convert_Buff[2][0][0] = save_w[1].Adjust_X;
    Convert_Buff[2][0][1] = save_w[1].Adjust_Y;
    Convert_Buff[2][0][2] = save_w[1].Screen_Size;
    Convert_Buff[2][0][3] = save_w[1].Screen_Mode;
    sys_w.screen_mode = save_w[1].Screen_Mode;
    Convert_Buff[3][0][2] = save_w[1].Auto_Save;
    Convert_Buff[3][1][0] = save_w[1].SoundMode;
    Convert_Buff[3][1][1] = save_w[1].BGM_Level;
    Convert_Buff[3][1][2] = save_w[1].SE_Level;
    Convert_Buff[3][1][3] = save_w[1].BgmType;
    for (ix = 0; ix < 20; ix++) {
        Ranking_Data[ix] = save_w[1].Ranking[ix];
    }
}

void Copy_Check_w() {
    s16 ix;
    s16 ix2;

    for (ix = 0; ix < 4; ix++) {
        for (ix2 = 0; ix2 < 12; ix2++) {
            Check_Buff[ix][0][ix2] = Convert_Buff[ix][0][ix2];
            Check_Buff[ix][1][ix2] = Convert_Buff[ix][1][ix2];
        }
    }

    ck_ex_option = save_w[1].extra_option;
}

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

void Setup_Default_Game_Option() {
    s16 ix;

    for (ix = 0; ix < 6; ix++) {
        save_w[ix] = Game_Default_Data;
        save_w[ix].sum = 0;
    }
}

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

void Setup_Limit_Time() {
    s16 limit;

    limit = Level_18_Data[save_w[Present_Mode].Difficulty][16];
    limit += 20;
    if (Country == 1) {
        Limit_Time = 1241;
    } else {
        Limit_Time = 1061;
    }

    if (limit > Limit_Time) {
        Limit_Time = limit;
    }
}

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

void Basic_Sub() {
    bg_w.bgw[0].old_pos_x = bg_w.bgw[0].xy[0].disp.pos;
    move_effect_work(0);
    move_effect_work(1);
    move_effect_work(2);
    move_effect_work(3);
    move_effect_work(4);
    move_effect_work(5);
}

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

void Check_Off_Vib() {
    // Do nothing
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SYS_sub", Flash_Violent);
