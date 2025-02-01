#include "common.h"
#include "sf33rd/Source/Common/PPGWork.h"
#include "sf33rd/Source/Game/DEMO00.h"
#include "sf33rd/Source/Game/DEMO01.h"
#include "sf33rd/Source/Game/Flash_LP.h"
#include "sf33rd/Source/Game/GD3rd.h"
#include "sf33rd/Source/Game/Grade.h"
#include "sf33rd/Source/Game/HITCHECK.h"
#include "sf33rd/Source/Game/Manage.h"
#include "sf33rd/Source/Game/OPENING.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/Reset.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/SYS_sub.h"
#include "sf33rd/Source/Game/SYS_sub2.h"
#include "sf33rd/Source/Game/SysDir.h"
#include "sf33rd/Source/Game/TATE00.h"
#include "sf33rd/Source/Game/VITAL.h"
#include "sf33rd/Source/Game/bg_sub.h"
#include "sf33rd/Source/Game/cmb_win.h"
#include "sf33rd/Source/Game/count.h"
#include "sf33rd/Source/Game/debug/Debug.h"
#include "sf33rd/Source/Game/main.h"
#include "sf33rd/Source/Game/menu.h"
#include "sf33rd/Source/Game/op_sub.h"
#include "sf33rd/Source/Game/sel_pl.h"
#include "sf33rd/Source/Game/spgauge.h"
#include "sf33rd/Source/Game/stun.h"
#include "sf33rd/Source/Game/ta_sub.h"
#include "unknown.h"

void Wait_Auto_Load();
void Loop_Demo();
void Game();
void Game00();
void Game01();
void Game02();
void Game03();
void Game04();
void Game05();
void Game06();
void Game07();
void Game08();
void Game09();
void Game10();
void Game11();
void Game12();
void Check_Back_Demo();
void Game0_0();
void Game0_1();
void Game0_2();
void Next_Demo_Loop();
void Game12_0();
void Game12_1();
void Game12_2();
void Game2_0();
void Game2_1();
void Game2_2();
void Game2_3();
void Game2_4();
void Game2_5();
void Game2_6();
void Game2_7();
void Time_Control();

void Game_Task(struct _TASK *task_ptr) {
    s16 ix;
    s16 ff;

    void (*Main_Jmp_Tbl[3])() = { Wait_Auto_Load, Loop_Demo, Game };

    init_color_trans_req();
    ff = Process_Counter;

    if ((Usage == 7) && !Turbo) {
        ff = sysFF;
    }

    for (ix = 0; ix < ff; ix++) {
        if (ix == ff - 1) {
            No_Trans = 0;

            if (Turbo != 0 && (Process_Counter > 1) && (Turbo_Timer != 5)) {
                Play_Game = 0;
                break;
            }
        } else {
            No_Trans = 1;
        }

        Play_Game = 0;

        if (Game_pause != 0x81) {
            system_timer += 1;
        }

        init_texcash_before_process();
        seqsBeforeProcess();

        if (nowSoftReset() == 0) {
            Main_Jmp_Tbl[G_No[0]](task_ptr);
        }

        seqsAfterProcess();
        texture_cash_update();
        move_pulpul_work();
        Check_Off_Vib();
        Check_LDREQ_Queue();
    }

    Check_Check_Screen();
    Check_Pos_BG();
    Disp_Sound_Code();
}

void Game() {
    void (*Game_Jmp_Tbl[13])() = { Game00, Game01, Game02, Game03, Game04, Game05, Game06,
                                   Game07, Game08, Game09, Game10, Game11, Game12 };

    if (G_No[1] == 2 || G_No[1] == 9) {
        Play_Game = 1;
    } else if (G_No[1] == 8) {
        Play_Game = 2;
    }

    Game_Jmp_Tbl[G_No[1]]();
}

void Game00() {
    void (*Game00_Jmp_Tbl[3])() = { Game0_0, Game0_1, Game0_2 };

    Game00_Jmp_Tbl[G_No[2]]();
    njSetBackColor(0, 0, 0);
    BG_Draw_System();
    Basic_Sub();
    Check_Back_Demo();
}

void Game0_0() {
    if (Title_At_a_Dash() != 0) {
        G_No[2] += 1;
    }
}

void Game0_1() {
    Disp_Copyright();
    TITLE_Move(1);

    if (Request_G_No) {
        G_No[2] += 1;
    }
}

void Game0_2() {
    switch (G_No[3]) {
    case 0:
        Disp_Copyright();
        TITLE_Move(1);
        G_No[3] += 1;
        Switch_Screen_Init(1);
        break;

    case 1:
        if (Switch_Screen(1) != 0) {
            G_No[3] += 1;
            Cover_Timer = 23;
            return;
        }

        TITLE_Move(1);
        Disp_Copyright();
        break;

    case 2:
        FadeOut(1, 0xFF, 8);
        G_No[3] += 1;
        break;

    case 3:
        FadeOut(1, 0xFF, 8);
        G_No[3] += 1;
        TexRelease(601);
        title_tex_flag = 0;
        break;

    case 4:
        FadeOut(1, 0xFF, 8);
        G_No[3] += 1;
        Purge_mmtm_area(2);
        Make_texcash_of_list(2);
        break;

    case 5:
        FadeOut(1, 0xFF, 8);
        BGM_Request(65);
        G_No[1] = 0xC;
        G_No[2] = 0;
        G_No[3] = 0;
        cpReadyTask(MENU_TASK_NUM, Menu_Task);
        break;
    }
}

void Check_Back_Demo() {
    if (++G_Timer < 1800) {
        return;
    }

    if (G_No[1] == 12 || (G_No[2] == 2 && G_No[3] >= 2)) {
        return;
    }

    TexRelease(0x259);
    title_tex_flag = 0;
    Next_Demo_Loop();
    effect_work_init();
}

void Game12() {
    void (*Game12_Jmp_Tbl[3])() = { Game12_0, Game12_1, Game12_2 };

    Game12_Jmp_Tbl[G_No[2]]();
    BG_Draw_System();
    Basic_Sub();
    bg_pos_hosei_sub2(0);
    bg_pos_hosei_sub2(1);
    bg_pos_hosei_sub2(2);
    Bg_Family_Set_appoint(0);
    Bg_Family_Set_appoint(1);
    Bg_Family_Set_appoint(2);
    BG_move_Ex(0);
}

void Game12_0() {
    // Do nothing
}

void Game12_1() {
    G_No[2] += 1;
    Switch_Screen_Init(1);
    SsBgmFadeOut(0x1000);
}

void Game12_2() {
    if (Switch_Screen(1) != 0) {
        G_No[1] = 1;
        G_No[2] = 0;
        G_No[3] = 0;
        Control_Time = 481;
        Cover_Timer = 23;
        effect_work_init();
        cpExitTask(3);
    }
}

void Game01() {
    BG_Draw_System();
    Basic_Sub();
    Setup_Play_Type();

    switch (G_No[2]) {
    case 0:
        Switch_Screen(1);
        G_No[2] += 1;
        S_No[0] = 0;
        S_No[1] = 0;
        S_No[2] = 0;
        S_No[3] = 0;
        SsBgmHalfVolume(0);

        if (Mode_Type == 0) {
            BGM_Request(53);
        } else {
            BGM_Request(66);
        }

        Break_Into = 0;
        Stop_Combo = 0;

        if (Mode_Type != 2) {
            Random_ix32 = Interrupt_Timer;
            Random_ix32_ex = Interrupt_Timer;
        } else {
            Setup_Net_Random_ix();
            All_Clear_Timer();
        }

        init_slow_flag();
        System_all_clear_Level_B();
        pulpul_stop();
        init_pulpul_work();
        break;

    case 1:
        Switch_Screen(1);
        G_No[2] += 1;
        break;

    case 2:
        if (Select_Player()) {
            G_No[2] += 1;
            Bonus_Game_Flag = 0;
            Switch_Screen_Init(0);
        }

        break;

    default:
        Select_Player();

        if (Switch_Screen(0) != 0) {
            Game01_Sub();
            Cover_Timer = 5;
            appear_type = 1;
            set_hitmark_color();

            if (Debug_w[0x1D]) {
                My_char[0] = Debug_w[0x1D] - 1;
            }

            if (Debug_w[0x1E]) {
                My_char[1] = Debug_w[0x1E] - 1;
            }

            Purge_texcash_of_list(3);
            Make_texcash_of_list(3);

            if (Demo_Flag) {
                G_No[1] = 2;
                G_No[2] = 0;
                G_No[3] = 0;
                E_No[0] = 4;
                E_No[1] = 0;
                E_No[2] = 0;
                E_No[3] = 0;
            } else {
                Demo_Time_Stop = 1;
                plw[0].wu.operator= 0;
                Operator_Status[0] = 0;
                plw[1].wu.operator= 0;
                Operator_Status[1] = 0;
            }

            if (plw[0].wu.operator!= 0) {
                Sel_Arts_Complete[0] = -1;
            }

            if (plw[1].wu.operator!= 0) {
                Sel_Arts_Complete[1] = -1;
            }

            if ((plw[0].wu.operator!= 0) && (plw[1].wu.operator!= 0)) {
                Play_Type = 1;
            } else {
                Play_Type = 0;
            }
        }

        break;
    }

    BG_move();
}

void Game02() {
    void (*Game02_Jmp_Tbl[8])() = { Game2_0, Game2_1, Game2_2, Game2_3, Game2_4, Game2_5, Game2_6, Game2_7 };

    Scene_Cut = Cut_Cut_Cut();
    Game02_Jmp_Tbl[G_No[2]]();
    BG_move_Ex(3);
}

void Game2_0() {
    s16 ix;

    BG_Draw_System();
    Switch_Screen(0);

    if (Check_LDREQ_Clear() == 0) {
        return;
    }

    System_all_clear_Level_B();

    switch (Mode_Type) {
    case 0:
        Play_Mode = 0;
        Replay_Status[0] = 0;
        Replay_Status[1] = 0;
        break;

    case 1:
        for (ix = 0; ix < 2; ix++) {
            if (save_w[1].Partner_Type[ix]) {
                plw[ix].wu.operator= 0;
                Operator_Status[ix] = 0;
            }
        }

        cpExitTask(1);
        /* fallthrough */

    case 2:
        Play_Mode = 1;
        All_Clear_Random_ix();
        All_Clear_Timer();
        All_Clear_ETC();
        break;

    case 5:
        Play_Mode = 3;
        All_Clear_Timer();
        break;
    }

    Check_Replay();

    if (Demo_Flag == 0) {
        Play_Mode = 0;
        Replay_Status[0] = 0;
        Replay_Status[1] = 0;
    }

    Game_difficulty = 15;
    Game_pause = 0;
    Demo_Time_Stop = 0;
    C_No[0] = 0;
    C_No[1] = 0;
    C_No[2] = 0;
    C_No[3] = 0;
    G_No[2] = 6;
    G_Timer = 10;
    Round_num = 0;
    Keep_Grade[0] = 0;
    Keep_Grade[1] = 0;

    if (Win_Record[0]) {
        Keep_Grade[0] = grade_get_my_grade(0) + 1;
    }

    if (Win_Record[1]) {
        Keep_Grade[1] = grade_get_my_grade(1) + 1;
    }

    Allow_a_battle_f = 0;
    Time_in_Time = 60;
    init_slow_flag();
    clear_hit_queue();
    pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
    ca_check_flag = 1;
    bg_work_clear();
    win_lose_work_clear();
    player_face_init();
    setup_pos_remake_key(3);
}

void Game2_1() {
    mpp_w.inGame = 1;

    if (Game_pause != 0x81) {
        Game_timer += 1;
    }

    set_EXE_flag();
    ppgPurgeFromVRAM(5);
    Player_control();
    TATE00();
    Game_Management();
    BG_Draw_System();
    ppgPurgeFromVRAM(4);
    reqPlayerDraw();
    Basic_Sub_Ex();

    if (Disp_Cockpit) {
        Time_Control();
        vital_cont_main();
        player_face();
        player_name();
        combo_cont_main();
        stngauge_cont_main();
        spgauge_cont_main();
        Sa_frame_Write();
        Score_Sub();
        Flash_Lamp();
        Disp_Win_Record();
    }

    ppgPurgeFromVRAM(0);
    hit_check_main_process();
}

void Game2_2() {
    s16 i;

    BG_Draw_System();
    Switch_Screen(0);

    if (Check_LDREQ_Clear() == 0) {
        return;
    }

    SsBgmHalfVolume(0);
    All_Clear_Timer();
    Check_Replay();
    Game_difficulty = 15;
    Game_timer = 0;
    Game_pause = 0;
    Demo_Time_Stop = 0;
    C_No[0] = 0;
    C_No[1] = 0;
    C_No[2] = 0;
    C_No[3] = 0;
    G_Timer = 10;
    Round_num = 0;
    Keep_Grade[0] = 0;
    Keep_Grade[1] = 0;

    if (Win_Record[0]) {
        Keep_Grade[0] = grade_get_my_grade(0) + 1;
    }

    if (Win_Record[1]) {
        Keep_Grade[1] = grade_get_my_grade(1) + 1;
    }

    Allow_a_battle_f = 0;
    Time_in_Time = 60;
    init_slow_flag();
    effect_work_quick_init();
    clear_hit_queue();
    pcon_rno[0] = pcon_rno[1] = pcon_rno[2] = pcon_rno[3] = 0;
    ca_check_flag = 1;
    bg_work_clear();
    win_lose_work_clear();
    player_face_init();
    Game01_Sub();
    appear_type = 1;
    TATE00();

    for (i = 0; i < 3; i++) {
        if (stage_bgw_number[bg_w.stage][i] > 0) {
            Bg_On_R(1 << i);
        }
    }

    if (bg_w.stage == 7) {
        Bg_On_R(4);
    }

    G_No[2] = 7;
}

void Game2_3() {
    Game2_1();

    if (--G_Timer == 0) {
        G_No[2] = 1;
        Clear_Flash_No();
    }
}

void Game2_4() {
    BG_Draw_System();
}

void Game2_5() {
    BG_Draw_System();

    switch (G_No[3]) {
    case 0:
        Switch_Screen(0);
        G_No[3] += 1;
        Stop_Update_Score = 0;
        vital_cont_init();
        count_cont_init(0);
        stngauge_cont_init();
        stngauge_work_clear();
        combo_cont_init();
        count_cont_init(1);
        Score[0][2] = 0;
        Score[1][2] = 0;
        Suicide[0] = 1;
        Game_pause = 0;
        pcon_rno[0] = 0;
        pcon_rno[1] = 0;
        pcon_rno[2] = 0;
        pcon_rno[3] = 0;
        appear_type = 0;
        erase_extra_plef_work();
        compel_bg_init_position();
        win_lose_work_clear();
        TATE00();
        break;

    default:
        Game2_1();

        if (--G_Timer == 0) {
            G_No[2] = 1;
            Clear_Flash_No();
        }

        break;
    }
}

void Game2_6() {
    BG_Draw_System();
    Switch_Screen(0);

    if (Wait_Seek_Time() != 0) {
        G_No[2] = 3;
        TATE00();
    }
}

void Game2_7() {
    BG_Draw_System();
    Switch_Screen(0);

    if (Wait_Seek_Time() != 0) {
        G_No[2] = 3;
    }
}

void Game01_Sub() {
    Disp_Cockpit = 0;
    Stop_Update_Score = 0;
    vital_cont_init();
    count_cont_init(0);
    Score[0][1] = 0;
    Score[0][2] = 0;
    Score[1][1] = 0;
    Score[1][2] = 0;
    PL_Wins[0] = 0;
    PL_Wins[1] = 0;
    combo_cont_init();
    Clear_Win_Type();
    Lamp_No = 0;
    set_kizetsu_status(0);
    set_kizetsu_status(1);
    set_super_arts_status(0);
    set_super_arts_status(1);

    if (Demo_Flag && (sag_ikinari_max() != 0)) {
        spgauge_cont_init();
    } else {
        spgauge_cont_demo_init();
    }

    stngauge_cont_init();
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game03);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game04);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game05);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game06);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Request_Break_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Check_Disp_Ranking);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Disp_Rank_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Disp_Ranking);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game07);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game08);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game09);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Bonus_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game10);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game11);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Loop_Demo);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Next_Demo_Loop);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Loop_Demo_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Next_Title_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Time_Control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Ck_Coin);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Before_Select_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Wait_Auto_Load);
