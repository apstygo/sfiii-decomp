#include "common.h"
#include "sf33rd/Source/Game/DEMO00.h"
#include "sf33rd/Source/Game/DEMO01.h"
#include "sf33rd/Source/Game/GD3rd.h"
#include "sf33rd/Source/Game/OPENING.h"
#include "sf33rd/Source/Game/Reset.h"
#include "sf33rd/Source/Game/SYS_sub.h"
#include "sf33rd/Source/Game/debug/Debug.h"
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

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game0_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Check_Back_Demo);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game12);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game12_0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game12_1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game12_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game02);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game2_0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game2_1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game2_2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game2_3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game2_4);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game2_5);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game2_6);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game2_7);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game01_Sub);

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
