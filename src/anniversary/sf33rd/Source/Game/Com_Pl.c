#include "sf33rd/Source/Game/Com_Pl.h"
#include "common.h"
#include "sf33rd/AcrSDK/ps2/flps2debug.h"
#include "sf33rd/Source/Game/CMD_MAIN.h"
#include "sf33rd/Source/Game/Ck_Pass.h"
#include "sf33rd/Source/Game/Com_Data.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/Getup.h"
#include "sf33rd/Source/Game/PLCNT.h"
// #include "sf33rd/Source/Game/PLMAIN.h"
#include "sf33rd/Source/Game/ACTIVE00.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SYS_sub.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/active01.h"
#include "sf33rd/Source/Game/active02.h"
#include "sf33rd/Source/Game/active03.h"
#include "sf33rd/Source/Game/active04.h"
#include "sf33rd/Source/Game/active05.h"
#include "sf33rd/Source/Game/active06.h"
#include "sf33rd/Source/Game/active07.h"
#include "sf33rd/Source/Game/active08.h"
#include "sf33rd/Source/Game/active09.h"
#include "sf33rd/Source/Game/active10.h"
#include "sf33rd/Source/Game/active11.h"
#include "sf33rd/Source/Game/active12.h"
#include "sf33rd/Source/Game/active13.h"
#include "sf33rd/Source/Game/active14.h"
#include "sf33rd/Source/Game/active15.h"
#include "sf33rd/Source/Game/active16.h"
#include "sf33rd/Source/Game/active17.h"
#include "sf33rd/Source/Game/active18.h"
#include "sf33rd/Source/Game/active19.h"
#include "sf33rd/Source/Game/cmd_data.h"
#include "sf33rd/Source/Game/debug/Debug.h"
#include "sf33rd/Source/Game/workuser.h"

u16 cpu_algorithm(PLW *wk);
static u16 CPU_Sub(PLW *wk);
void Main_Program(PLW *wk);
void Com_Initialize(PLW *wk);
void Com_Free(PLW *wk);
void Com_Before_Follow(PLW *wk);
void Com_Before_Passive(PLW *wk);
void Com_Guard(PLW *wk);
static s32 Check_Counter_Attack(PLW *wk);
static s16 Check_Hamari(PLW *wk);
void Com_Guard_VS_Shell(PLW *wk);
static s32 Check_No12_Shell_Guard(PLW *wk, WORK_Other *tmw);
static s32 Ck_Exit_Guard(PLW *wk, WORK *em);
static s32 Ck_Exit_Guard_Sub(PLW *wk, WORK *em);
void Com_Active(PLW *wk);
void Com_Follow(PLW *wk);
void Com_Passive(PLW *wk);
void Com_VS_Shell(PLW *wk);
void Com_Damage(PLW *wk);
void Damage_1st(PLW *wk);
void Damage_2nd(PLW *wk);
void Damage_3rd(PLW * /* unused */);
void Damage_4th(PLW * /* unused */);
void Damage_5th(PLW *wk);
void Damage_6th(PLW *wk);
void Damage_7th(PLW *wk);
void Damage_8th(PLW *wk);
void Exit_Damage_Sub(PLW *wk);
static s32 Check_Damage(PLW *wk);
void Com_Float(PLW *wk);
void Float_2nd(PLW *wk);
void Float_3rd(PLW *wk);
void Float_4th(PLW *wk);
void Com_Flip(PLW *wk);
void Flip_Zero(PLW *wk);
void Flip_1st(PLW *wk);
void Flip_2nd(PLW *wk);
void Flip_3rd(PLW *wk);
void Flip_4th(PLW *wk);
static s32 Check_Shell_Flip(PLW *wk);
s32 Check_Flip(PLW *wk);
static s32 Check_Flip_Attack(PLW *wk);
void Com_Caught(PLW *wk);
static s16 Decide_Exit_Catch(PLW *wk);
s32 Com_Rapid_Sub(PLW *wk, s16 Shot, u8 dir_step);
static s32 Check_Caught(PLW *wk);
void Com_Catch(PLW *wk);
void Com_Wait_Lie(PLW *wk);
s32 Command_Attack_SP(PLW *wk, s8 Pl_Number, s16 Tech_Number, s16 Power_Level);
void Next_Be_Float(PLW *wk);
void Clear_Com_Flag(PLW *wk);
void Check_At_Count(PLW *wk);
void Shift_Resume_Lv(PLW *wk);
void Check_Store_Lv(PLW *wk);
void Store_LR_Sub(PLW *wk);
void Setup_Bullet_Counter(PLW *wk);
void Pattern_Insurance(PLW *wk, s16 Kind_Of_Insurance, s16 Forced_Number);

const u16 Correct_Lv_Data[16] = { 0, 1, 2, 2, 4, 5, 6, 5, 8, 9, 10, 9, 8, 5, 10, 0 };

u16 cpu_algorithm(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    u16 sw = CPU_Sub(wk);

    if (Play_Mode == 1 && Replay_Status[wk->wu.id] != 99) {
        if (wk->wu.id) {
            p2sw_0 = sw;
        } else {
            p1sw_0 = sw;
        }

        if (CPU_Time_Lag[wk->wu.id]) {
            CPU_Rec[wk->wu.id] = 1;
            return sw;
        }

        CPU_Rec[wk->wu.id] = 1;

        if (Debug_w[0x21]) {
            flPrintColor(0xFFFFFFFF);
            flPrintL(16, 9, "CPU REC!");
        }

        Check_Replay_Status(wk->wu.id, 1);
    }

    return sw;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", CPU_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Main_Program);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Initialize);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Free);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Before_Follow);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Before_Passive);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Guard);

s32 Check_Counter_Attack(PLW *wk) {
    s16 xx;
    WORK *em;

    if (Area_Number[wk->wu.id] >= 3) {
        return 0;
    }

    em = (WORK *)wk->wu.target_adrs;
    xx = Type_of_Attack[wk->wu.id] & 0xF8;

    if (xx == 8) {
        VS_Tech[wk->wu.id] = 28;
        return 1;
    }

    if (xx == 24) {
        VS_Tech[wk->wu.id] = 14;
        return 1;
    }

    if (xx == 32) {
        VS_Tech[wk->wu.id] = 14;
        return 1;
    }

    if (xx == 48) {
        VS_Tech[wk->wu.id] = 14;
        return 1;
    }

    return Check_Hamari(wk);
}

s16 Check_Hamari(PLW *wk) {
    u8 tech;
    s16 Rnd;
    s16 limit;
    s16 xx;

    if (Area_Number[wk->wu.id] >= 2) {
        return 0;
    }

    tech = Attack_Count_Buff[wk->wu.id][0];
    Rnd = random_32_com() & 1;
    limit = Rnd + 3;

    if (((PLW *)wk->wu.target_adrs)->player_number == 4 && tech == 3) {
        limit--;
    } else if (tech != 0 && tech != 1) {
        return 0;
    }

    for (xx = 1; xx < limit; xx++) {
        if (tech != Attack_Count_Buff[wk->wu.id][xx]) {
            return 0;
        }
    }

    return VS_Tech[wk->wu.id] = 32;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Guard_VS_Shell);

s32 Check_No12_Shell_Guard(PLW *wk, WORK_Other *tmw) {
    s16 pos_x;

    if (wk->wu.rl_flag) {
        pos_x = wk->wu.xyz[0].disp.pos - 48;

        if (tmw->wu.xyz[0].disp.pos < pos_x) {
            return 1;
        }
    } else {
        pos_x = wk->wu.xyz[0].disp.pos + 48;

        if (tmw->wu.xyz[0].disp.pos > pos_x) {
            return 1;
        }
    }

    return 0;
}

void Check_Guard_Type(PLW *wk, WORK *em) {
    Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 1);

    switch (Guard_Type[wk->wu.id]) {
    case 0:
        if (em->pat_status >= 0xE && em->pat_status <= 0x1E) {
            break;
        }

        if (em->att.guard & 16 || !(em->att.guard & 8)) {
            break;
        }

        Lever_Buff[wk->wu.id] |= 2;
        break;

    case 1:
        break;

    case 2:
        Lever_Buff[wk->wu.id] |= 2;
        break;
    }
}

s32 Ck_Exit_Guard(PLW *wk, WORK *em) {
    s16 Lv;

    if (Timer_00[wk->wu.id] -= 1) {
        return 1;
    }

    Timer_00[wk->wu.id] = 1;

    if (Ck_Exit_Guard_Sub(wk, em)) {
        if (Guard_Counter[wk->wu.id] == Attack_Counter[wk->wu.id]) {
            return 1;
        }

        Guard_Counter[wk->wu.id] = Attack_Counter[wk->wu.id];
        Lv = Setup_Lv10(0);

        if (Break_Into_CPU == 2) {
            Lv = 10;
        }

        if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
            Lv = 2;
        }

        Lv += CC_Value[0];
        Lv = emLevelRemake(Lv, 11, 1);

        if (EM_Rank != 0) {
            Guard_Type[wk->wu.id] = Guard_Data[17][Lv][random_16_com()];
        } else {
            Guard_Type[wk->wu.id] = Guard_Data[wk->player_number][Lv][random_16_com()];
        }

        return 1;
    }

    return 0;
}

s32 Ck_Exit_Guard_Sub(PLW *wk, WORK *em) {
    if (Attack_Flag[wk->wu.id] == 0) {
        return 0;
    }

    if (wk->wu.routine_no[1] == 1) {
        if (wk->wu.routine_no[3] == 0) {
            return 1;
        }

        if (wk->wu.routine_no[2] >= 4 && wk->wu.routine_no[2] < 8 && wk->wu.cmwk[0xE] == 0 &&
            Attack_Flag[wk->wu.id] == 0) {
            return 0;
        }

        return 1;
    }

    if (em->routine_no[1] != 4) {
        return 0;
    }

    if (Attack_Flag[wk->wu.id] == 0) {
        return 0;
    }

    return 1;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Active);

// void Com_Active(PLW *wk) {
//     void (*const Char_Jmp_Tbl[20])(PLW *) = { Computer00, Computer01, Computer02, Computer03, Computer04,
//                                               Computer05, Computer06, Computer07, Computer08, Computer09,
//                                               Computer10, Computer11, Computer12, Computer13, Computer14,
//                                               Computer15, Computer16, Computer17, Computer18, Computer19 };

//     if (Check_Damage(wk)) {
//         return;
//     }

//     if (Check_Caught(wk)) {
//         return;
//     }

//     if (Check_Flip(wk)) {
//         return;
//     }

//     Pattern_Insurance(wk, 0, 0);
//     Char_Jmp_Tbl[wk->player_number](wk);
// }

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Follow);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Passive);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_VS_Shell);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Damage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_5th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_6th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_7th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Damage_8th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Exit_Damage_Sub);

s32 Check_Damage(PLW *wk) {
    if (Counter_Attack[wk->wu.id] & 2) {
        return 0;
    }

    if (wk->wu.routine_no[1] == 1 && CP_No[wk->wu.id][0] != 7 && CP_No[wk->wu.id][0] != 9 &&
        Guard_Flag[wk->wu.id] == 0) {
        CP_No[wk->wu.id][0] = 10;
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        CP_No[wk->wu.id][3] = 0;
        Receive_Flag[wk->wu.id] = 0;
        Lever_Buff[wk->wu.id] = 2;
        Clear_Com_Flag(wk);
        return 1;
    }

    return 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Float);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Float_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Float_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Float_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Flip);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Flip_Zero);

s32 Check_Flip_GO(PLW *wk, s16 xx) {
    WORK *em = (WORK *)wk->wu.target_adrs;

    if (em->att_hit_ok || xx) {
        if (em->pat_status == 0x21 || em->pat_status == 0x20) {
            Lever_Buff[wk->wu.id] = 2;
        } else {
            Lever_Buff[wk->wu.id] = Setup_Guard_Lever(wk, 0);
        }

        if (xx == 0 && Resume_Lever[wk->wu.id][0] == Lever_Buff[wk->wu.id]) {
            Next_Be_Guard(wk, em, 0);
            Flip_Counter[wk->wu.id] = 0xFF;
            return 0;
        }

        Flip_Counter[wk->wu.id]++;
        return 1;
    }

    return 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Flip_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Flip_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Flip_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Flip_4th);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", SetShellFlipLever);
#else
s32 SetShellFlipLever(PLW *wk) {
    not_implemented(__func__);
}
#endif

s32 Check_Shell_Flip(PLW *wk) {
    WORK *shell;
    s32 Rnd;
    s32 Lv;
    s32 xx;
    s32 res;

    res = 0;
    Flip_Counter[wk->wu.id]++;

    if (Timer_01[wk->wu.id] != 8) {
        return 0;
    }

    shell = (WORK *)wk->wu.dmg_adrs;

    if (shell == NULL) {
        res = 1;
    } else if (shell->be_flag != 0 && shell->id == 13) {
        // do nothing
    } else {
        res = 1;
    }

    if (res || shell->vital_new < 256) {
        if ((xx = Check_Shell_Another_in_Flip(wk)) == 0) {
            if (res) {
                return -1;
            }

            return 0;
        }

        if (xx > 16) {
            return 0;
        }

        res = 1;
        shell = (WORK *)Shell_Address[wk->wu.id];
        wk->wu.dmg_adrs = (u32 *)shell;
    }

    Rnd = random_32_com();
    Rnd -= Flip_Term_Correct(wk);
    Lv = emLevelRemake(Setup_Lv08(0), 8, 0);

    if (Rnd >= Shell_Renzoku_Flip_Data[wk->player_number][Lv]) {
        return 2;
    }

    if (Flip_Counter[wk->wu.id] < emGetMaxBlocking()) {
        if (res == 0) {
            return 1;
        }

        xx -= 8;

        if (xx > 0) {
            Timer_00[wk->wu.id] = xx;
            return 3;
        }
    }

    return 0;
}

s32 Check_Flip(PLW *wk) {
    if (Flip_Flag[wk->wu.id]) {
        return 0;
    }

    if (wk->wu.routine_no[1] != 0) {
        return 0;
    }

    if (PL_Damage_Data[wk->wu.routine_no[2]] == 0) {
        return 0;
    }

    if (Flip_Counter[wk->wu.id] == 0xFF) {
        return 0;
    }

    CP_No[wk->wu.id][0] = 12;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Timer_00[wk->wu.id] = 15;

    if (Timer_01[wk->wu.id] == 8) {
        CP_No[wk->wu.id][1] = 3;
    } else {
        CP_No[wk->wu.id][1] = 2;
    }

    if (wk->wu.xyz[1].disp.pos > 0) {
        CP_No[wk->wu.id][1] = 1;
    }

    return 1;
}

s32 Check_Flip_Attack(PLW *wk) {
    s16 Lv = Setup_Lv08(0);
    s16 Rnd;
    s16 xx;

    if (Break_Into_CPU == 2) {
        Lv = 7;
    }

    if (Demo_Flag == 0 && Weak_PL == wk->wu.id) {
        Lv = 0;
    }

    Rnd = random_32_com();
    Rnd -= Flip_Term_Correct(wk);
    xx = Setup_EM_Rank_Index(wk);

    if (Rnd >= Flip_Attack_Data[xx][emLevelRemake(Lv, 8, 0)]) {
        return 0;
    }

    Flip_Flag[wk->wu.id] = 0;
    VS_Tech[wk->wu.id] = 13;
    Counter_Attack[wk->wu.id] = 1;
    return 1;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Caught);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Decide_Exit_Catch);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Rapid_Sub);

s32 Check_Caught(PLW *wk) {
    if (wk->wu.routine_no[1] == 3) {
        CP_No[wk->wu.id][0] = 13;
        CP_No[wk->wu.id][1] = 0;
        CP_No[wk->wu.id][2] = 0;
        CP_No[wk->wu.id][3] = 0;
        Clear_Com_Flag(wk);
        return 1;
    }

    return 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Catch);

void Be_Catch(PLW *wk) {
    CP_No[wk->wu.id][0] = 15;
    CP_No[wk->wu.id][1] = 0;
    CP_No[wk->wu.id][2] = 0;
    CP_No[wk->wu.id][3] = 0;
    Clear_Com_Flag(wk);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Com_Wait_Lie);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Command_Attack_SP);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Next_Be_Free);
#else
void Next_Be_Free(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Next_Be_Float);

void Clear_Com_Flag(PLW *wk) {
    Passive_Flag[wk->wu.id] = 0;
    Flip_Flag[wk->wu.id] = 0;
    Counter_Attack[wk->wu.id] = 0;
    Limited_Flag[wk->wu.id] = 0;
    Guard_Flag[wk->wu.id] = 0;
    Before_Jump[wk->wu.id] = 0;
    Shell_Ignore_Timer[wk->wu.id] = 0;
    Pierce_Menu[wk->wu.id] = 0;
    Continue_Menu[wk->wu.id] = 0;
    Standing_Timer[wk->wu.id] = 0;
    Before_Look[wk->wu.id] = 0;
    Attack_Count_No0[wk->wu.id] = 0;
    Turn_Over[wk->wu.id] = 0;
    Jump_Pass_Timer[wk->wu.id][0] = 0;
    Jump_Pass_Timer[wk->wu.id][1] = 0;
    Jump_Pass_Timer[wk->wu.id][2] = 0;
    Jump_Pass_Timer[wk->wu.id][3] = 0;
    Last_Eftype[wk->wu.id] = 0;
}

void Check_At_Count(PLW *wk) {
    WORK *em = (WORK *)wk->wu.target_adrs;
    s16 ix;

    if (Attack_Count_No0[wk->wu.id] == 0) {
        if (Attack_Flag[wk->wu.id]) {
            Attack_Counter[wk->wu.id]++;
            Attack_Count_No0[wk->wu.id] = 1;
            Type_of_Attack[wk->wu.id] = em->kind_of_waza;
            Attack_Count_Buff[wk->wu.id][Attack_Count_Index[wk->wu.id]] = em->kind_of_waza;
            Attack_Count_Index[wk->wu.id]++;
            Attack_Count_Index[wk->wu.id] &= 3;
        }
    } else if (Attack_Flag[wk->wu.id] == 0) {
        Attack_Count_No0[wk->wu.id] = 0;
    }

    if (Attack_Flag[wk->wu.id]) {
        Reset_Timer[wk->wu.id] = 120;
        return;
    }

    if ((Reset_Timer[wk->wu.id] -= 1) == 0) {
        for (ix = 0; ix < 4; ix++) {
            Attack_Count_Buff[wk->wu.id][ix] = ix;
        }
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Shift_Resume_Lv);

void Check_Store_Lv(PLW *wk) {
    s16 xx = Lever_Buff[wk->wu.id] & 0xF;

    switch (xx) {
    case 2:
        Lever_Store[wk->wu.id][0]++;
        break;

    case 6:
    case 10:
        Store_LR_Sub(wk);
        Lever_Store[wk->wu.id][0]++;
        break;

    case 4:
    case 8:
        Store_LR_Sub(wk);
        break;

    default:
        Lever_Store[wk->wu.id][0] = 0;
        Lever_Store[wk->wu.id][1] = 0;
        Lever_Store[wk->wu.id][2] = 0;
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Store_LR_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Setup_Bullet_Counter);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Com_Pl", Pattern_Insurance);

const u8 Rapid_Lever_Data[2] = { 8, 4 };

const u8 Pattern_Insurance_Data[20][4] = {
    { 67, 157, 10, 3 }, { 69, 175, 9, 3 },  { 74, 132, 10, 3 }, { 71, 135, 10, 3 },  { 67, 141, 11, 3 },
    { 66, 101, 10, 3 }, { 63, 146, 10, 3 }, { 75, 213, 11, 3 }, { 70, 213, 10, 3 },  { 100, 131, 10, 3 },
    { 69, 137, 10, 3 }, { 89, 254, 13, 3 }, { 85, 230, 10, 3 }, { 80, 167, 11, 3 },  { 150, 252, 12, 3 },
    { 68, 163, 13, 3 }, { 69, 166, 13, 3 }, { 82, 181, 13, 3 }, { 108, 203, 13, 3 }, { 78, 175, 13, 3 }
};
