#include "sf33rd/Source/Game/PLCNT3.h"
#include "common.h"
#include "sf33rd/Source/Game/HITCHECK.h"
#include "sf33rd/Source/Game/Manage.h"
#include "sf33rd/Source/Game/PLCNT.h"
#include "sf33rd/Source/Game/PLCNT2.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SLOWF.h"
#include "sf33rd/Source/Game/bg_sub.h"
#include "sf33rd/Source/Game/workuser.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLCNT3", Player_control_bonus2);
#else
s32 Player_control_bonus2() {
    not_implemented(__func__);
}
#endif

void plcnt_b2_move() {
    if (No_Death) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }

    if (Break_Into) {
        plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;
    }

    move_player_work_bonus();

    if (*Bonus_Stage_RNO == 2) {
        Time_Stop = 1;
        pcon_rno[0] = 2;
        pcon_rno[1] = 0;
        pcon_rno[2] = 0;
    }

    if (Time_Over) {
        pcon_rno[0] = 2;
        pcon_rno[1] = 0;
        pcon_rno[2] = 0;
    }
}

void plcnt_b2_die() {
    plw[0].wu.dm_vital = plw[1].wu.dm_vital = 0;

    switch (pcon_rno[2]) {
    case 0:
        plw[0].wkey_flag = plw[1].wkey_flag = 1;
        plw[0].image_setup_flag = plw[1].image_setup_flag = 0;
        pcon_rno[2]++;
        /* fallthrough */

    case 1:
        if (footwork_check_bns(0) && footwork_check_bns(1)) {
            pcon_rno[2]++;
        }

        break;

    case 2:
        complete_victory_pause();

        if (plw[0].wu.operator) {
            plw[0].wu.routine_no[1] = 0;
            plw[0].wu.routine_no[2] = 0x28;
            plw[0].wu.routine_no[3] = 0;
        } else {
            plw[0].wu.routine_no[3] = 9;
        }

        if (plw[1].wu.operator) {
            plw[1].wu.routine_no[1] = 0;
            plw[1].wu.routine_no[2] = 0x28;
            plw[1].wu.routine_no[3] = 0;
        } else {
            plw[1].wu.routine_no[3] = 9;
        }

        plw[0].wu.cg_type = plw[1].wu.cg_type = 0;
        pcon_rno[2] += 1;
        break;

    case 3:
        if ((plw[0].wu.routine_no[3] == 9) && (plw[1].wu.routine_no[3] == 9)) {
            pcon_rno[2]++;
        }

        break;
    }

    move_player_work_bonus();
}

void (*const player_bonus2_process[3])() = { plcnt_b_init, plcnt_b2_move, plcnt_b2_die };
