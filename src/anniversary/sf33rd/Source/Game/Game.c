#include "common.h"
#include "sf33rd/Source/Game/GD3rd.h"
#include "sf33rd/Source/Game/Reset.h"
#include "sf33rd/Source/Game/SYS_sub.h"
#include "sf33rd/Source/Game/debug/Debug.h"
#include "unknown.h"

void Wait_Auto_Load();
void Loop_Demo();
void Game();

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

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game00);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game0_0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Game", Game0_1);

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
