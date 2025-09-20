#include "sf33rd/Source/Game/Eff76.h"
#include "common.h"
#include "sf33rd/Source/Game/CHARSET.h"
#include "sf33rd/Source/Game/EFF57.h"
#include "sf33rd/Source/Game/EFFA6.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/Grade.h"
#include "sf33rd/Source/Game/RANKING.h"
#include "sf33rd/Source/Game/SYS_sub.h"
#include "sf33rd/Source/Game/Sel_Data.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/bg_data.h"
#include "sf33rd/Source/Game/bg_sub.h"
#include "sf33rd/Source/Game/char_table.h"
#include "sf33rd/Source/Game/debug/Debug.h"
#include "sf33rd/Source/Game/texcash.h"
#include "sf33rd/Source/Game/workuser.h"

void effect_76_move(WORK_Other *ewk);
void EFF76_WAIT(WORK_Other *ewk);
void EFF76_WAIT_BREAK_INTO(WORK_Other *ewk);
void EFF76_SLIDE_IN(WORK_Other *ewk);
void EFF76_SLIDE_OUT(WORK_Other * /* unused */);
void EFF76_SUDDENLY(WORK_Other *ewk);
void EFF76_BEFORE(WORK_Other *ewk);
void EFF76_SHIFT(WORK_Other *ewk);
void Setup_Pos_76(WORK_Other *ewk);
void Setup_Char_76(WORK_Other *ewk);
s16 Check_Range_Out(WORK_Other *ewk);
void Setup_Color_76(WORK_Other *ewk);
void Setup_Color_L1(WORK_Other *ewk);

void (*const EFF76_Jmp_Tbl[8])() = { EFF76_WAIT, EFF76_SLIDE_IN, EFF76_SLIDE_OUT,       EFF76_SUDDENLY,
                                     EFF57_KILL, EFF76_SHIFT,    EFF76_WAIT_BREAK_INTO, EFF76_BEFORE };

void effect_76_move(WORK_Other *ewk) {
    EFF76_Jmp_Tbl[ewk->wu.routine_no[0]](ewk);

    if (ewk->wu.be_flag == 0) {
        return;
    }

    ewk->wu.position_x = ewk->wu.xyz[0].disp.pos;
    ewk->wu.position_y = ewk->wu.xyz[1].disp.pos;

    switch (ewk->wu.dir_old) {
    case 0x38:
    case 0x42:
        sort_push_requestA(&ewk->wu);
        break;

    case 0x30:
        Check_Pos_OBJ(ewk);
        /* fallthrough */

    default:
        sort_push_request4(&ewk->wu);
        break;
    }
}

void EFF76_WAIT(WORK_Other *ewk) {
    if (Check_Range_Out(ewk)) {
        Order[ewk->wu.dir_old] = 4;
        ewk->wu.routine_no[0] = 4;
        ewk->wu.routine_no[1] = 0;
        Order_Timer[ewk->wu.dir_old] = 1;
    } else if (Suicide[ewk->wu.direction] != 0) {
        Order[ewk->wu.dir_old] = 4;
        ewk->wu.routine_no[0] = 4;
        ewk->wu.routine_no[1] = 1;
        Order_Timer[ewk->wu.dir_old] = 1;
        ewk->wu.disp_flag = 0;
    } else if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }
}

void EFF76_WAIT_BREAK_INTO(WORK_Other *ewk) {
    if (Suicide[ewk->wu.direction] != 0) {
        Order[ewk->wu.dir_old] = 4;
        ewk->wu.routine_no[0] = 4;
        ewk->wu.routine_no[1] = 1;
        Order_Timer[ewk->wu.dir_old] = 1;
        ewk->wu.disp_flag = 0;
    } else if ((ewk->wu.routine_no[0] = Order[ewk->wu.dir_old])) {
        ewk->wu.routine_no[1] = 0;
    }
}

void EFF76_SLIDE_IN(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init2(WORK * wk, s32 koc, s32 index, s32 ip, s32 scf);
#endif

    if (Order[ewk->wu.dir_old] != 1) {
        ewk->wu.routine_no[0] = Order[ewk->wu.dir_old];
        ewk->wu.routine_no[1] = 0;
        return;
    }

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (!--Order_Timer[ewk->wu.dir_old]) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 1;
            set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        }

        break;

    default:
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (0 < ewk->wu.mvxy.a[0].sp) {
            if (ewk->wu.hit_quake <= ewk->wu.xyz[0].disp.pos) {
                if (Order[ewk->wu.dir_old] == ewk->wu.routine_no[0]) {
                    Order[ewk->wu.dir_old] = 0;
                }

                ewk->wu.routine_no[0] = 0;
                ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
            }
        } else if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            if (Order[ewk->wu.dir_old] == ewk->wu.routine_no[0]) {
                Order[ewk->wu.dir_old] = 0;
            }

            ewk->wu.routine_no[0] = 0;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }

        break;
    }
}

void EFF76_SLIDE_OUT(WORK_Other * /* unused */) {
    // Do nothing
}

void EFF76_SUDDENLY(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init2(WORK * wk, s32 koc, s32 index, s32 ip, s32 scf);
#endif

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.disp_flag = 0;
        }

        /* fallthrough */

    case 1:
        if (Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.dm_vital)) {
            break;
        }

        ewk->wu.disp_flag = 1;

        switch (ewk->wu.dir_old) {
        case 0x3D:
            ewk->wu.routine_no[1] = 2;
            break;

        case 0x42:
            ewk->wu.routine_no[1] = 3;
            break;

        default:
            ewk->wu.routine_no[0] = 0;
            Order[ewk->wu.dir_old] = 0;
            break;
        }

        set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
        break;

    case 2:
        if (Next_Step) {
            ewk->wu.my_family = 1;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[0].wxy[0].disp.pos;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[0].wxy[1].disp.pos + Pos_Cont_Data_76[ewk->wu.dir_old - 59][1];
            ewk->wu.routine_no[0] = 0;
            Order[ewk->wu.dir_old] = 0;
        }

        break;

    case 3:
        if (Next_Step) {
            ewk->wu.my_family = 4;
            ewk->wu.xyz[0].disp.pos = bg_w.bgw[3].wxy[0].disp.pos - 8;
            ewk->wu.xyz[1].disp.pos = bg_w.bgw[3].wxy[1].disp.pos + Pos_Data_76[ewk->wu.dir_old - 43][1];
            ewk->wu.routine_no[0] = 0;
            Order[ewk->wu.dir_old] = 0;
        }

        break;
    }
}

void EFF76_BEFORE(WORK_Other *ewk) {
#if defined(TARGET_PS2)
    void set_char_move_init2(WORK * wk, s32 koc, s32 index, s32 ip, s32 scf);
#endif

    if (--Order_Timer[ewk->wu.dir_old] != 0) {
        return;
    }

    ewk->wu.routine_no[1]++;
    ewk->wu.disp_flag = 1;
    ewk->wu.position_z = 8;
    ewk->wu.routine_no[0] = 0;
    ewk->wu.routine_no[1] = 0;
    Order[ewk->wu.dir_old] = 0;
    set_char_move_init2(&ewk->wu, 0, ewk->wu.char_index, ewk->wu.dir_step + 1, 0);
}

void EFF76_SHIFT(WORK_Other *ewk) {
    s16 cut;

    switch (ewk->wu.routine_no[1]) {
    case 0:
        if (--Order_Timer[ewk->wu.dir_old] == 0) {
            ewk->wu.routine_no[1]++;
            ewk->wu.hit_quake = ewk->wu.xyz[0].disp.pos - 160;
            ewk->wu.mvxy.a[0].sp = -0x60000;
            ewk->wu.mvxy.d[0].sp = -0x4000;
        }

        break;

    case 1:
        cut = Cut_Cut_Sub(3);
        ewk->wu.xyz[0].cal += ewk->wu.mvxy.a[0].sp * cut;
        ewk->wu.mvxy.a[0].sp += ewk->wu.mvxy.d[0].sp;

        if (ewk->wu.hit_quake >= ewk->wu.xyz[0].disp.pos) {
            ewk->wu.routine_no[0] = 0;
            Order[ewk->wu.dir_old] = 0;
            ewk->wu.xyz[0].disp.pos = ewk->wu.hit_quake;
        }

        break;
    }
}

s32 effect_76_init(s16 dir_old) {
#if defined(TARGET_PS2)
    s16 get_my_trans_mode(s32 curr);
#endif

    WORK_Other *ewk;
    s16 ix;

    if ((ix = pull_effect_work(4)) == -1) {
        return -1;
    }

    ewk = (WORK_Other *)frw[ix];
    ewk->wu.be_flag = 1;
    ewk->wu.id = 76;
    ewk->wu.work_id = 16;
    ewk->wu.my_col_code = 0x2090;
    ewk->wu.my_family = 3;
    *ewk->wu.char_table = _sel_pl_char_table;
    ewk->wu.my_mts = 13;
    ewk->wu.my_trans_mode = get_my_trans_mode(ewk->wu.my_mts);
    ewk->wu.dir_old = dir_old;
    ewk->wu.direction = 2;
    ewk->wu.dm_vital = Width_Data_76[dir_old - 43];
    Setup_Char_76(ewk);
    Setup_Pos_76(ewk);
    return 0;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", Setup_Pos_76);
#else
void Setup_Pos_76(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff76", Setup_Char_76);
#else
void Setup_Char_76(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

s16 Check_Range_Out(WORK_Other *ewk) {
    if (ewk->wu.disp_flag == 0) {
        return 0;
    }

    return Ck_Range_Out_S(ewk, ewk->wu.my_family - 1, ewk->wu.dm_vital);
}

void Setup_Color_76(WORK_Other *ewk) {
    ewk->wu.my_col_code = Victory_Color_Data[My_char[Winner_id]] + 0x2000;
    ewk->wu.my_col_code = Victory_Color_Data[My_char[Winner_id]] + 0x2090;
}

void Setup_Color_L1(WORK_Other *ewk) {
    ewk->wu.my_col_code = Victory_Color_Data[My_char[Winner_id]];
    ewk->wu.my_col_code = Victory_Color_Data[My_char[Winner_id]] + 0x90;
}

s32 chkNameAkuma(s32 plnum, s32 rnum) {
    if ((plnum == 14) && ((Country == 4) || (Country == 2) || (Country == 3))) {
        return rnum;
    }

    return 0;
}
