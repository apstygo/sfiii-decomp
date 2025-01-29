#include "sf33rd/Source/Game/Entry.h"
#include "common.h"
#include "sf33rd/Source/Game/GD3rd.h"
#include "sf33rd/Source/Game/Reset.h"
#include "sf33rd/Source/Game/end_data.h"
#include "sf33rd/Source/Game/main.h"
#include "sf33rd/Source/Game/n_input.h"
#include "unknown.h"

u8 letter_stack[40];
u8 letter_counter;
u8 *letter_ptr;

const u8 Coin_Message_Data[7][2] = { { 5, 30 }, { 2, 27 }, { 7, 32 }, { 17, 37 }, { 6, 31 }, { 5, 42 }, { 0, 0 } };

void Entry_00();
void Entry_01();
void Entry_02();
void Entry_03();
void Entry_04();
void Entry_06();
void Entry_07();
void Entry_08();
void Entry_10();

void Disp_00_0();
void Entry_01_Sub(s16 PL_id);
void Exit_Title_Sub_Entry();
void Entry_Main_Sub(s16 PL_id, s16 Jump_Index);
void Entry_03_1st();
void Entry_03_2nd();
void Entry_04_1st();
void Entry_04_2nd();
void Correct_BI_Data();
void Entry_06_1st();
void Entry_06_2nd();
void Entry_07_1st();
void Entry_07_2nd();
void Entry_08_1st();
void Entry_08_2nd();
void Entry_10_1st();
void Entry_10_2nd();
void Break_Into_Sub(s16 PL_id, s16 Jump_Index);
void Entry_Common_Sub(s16 PL_id, s16 Jump_Index);
void Entry_Continue_Sub(s16 PL_id);
void In_Game_Sub(s16 PL_id);
void In_Over_Sub(s16 PL_id);
void Loser_Scene_Sub(s16 PL_id, s16 Jump_Index);
void Name_In_Sub(s16 PL_id);
void Name_In_Sub0(s16 PL_id, s16 xx);
s32 Credit_Continue_1P();
s32 Credit_Continue_2P();
void Naming_Cut_Sub_1P();
void Naming_Cut_Sub_2P();
void Naming_Init(s16 PL_id);
s32 Ck_Break_Into_SP(u16 Sw_0, u16 Sw_1, s16 PL_id);
s32 Credit_Sub_1P();
s32 Credit_Sub_2P();
s32 Loser_Sub_1P();
s32 Loser_Sub_2P();

void Entry_Task(struct _TASK * /* unused */) {
    s16 ix;
    s16 ff;

    void (*Main_Jmp_Tbl[11])() = { Entry_00, Entry_01, Entry_02, Entry_03, Entry_04, Entry_03,
                                   Entry_06, Entry_07, Entry_08, Entry_03, Entry_10 };

    if (Pause || nowSoftReset()) {
        return;
    }

    ff = 1;

    if ((Usage == 7) && !Turbo) {
        ff = sysFF;
    }

    for (ix = 0; ix < ff; ix++) {
        if (ix == (ff - 1)) {
            No_Trans = 0;
        } else {
            No_Trans = 1;
        }

        letter_counter = 0;
        letter_ptr = letter_stack;
        Main_Jmp_Tbl[E_No[0]]();
    }
}

void Entry_00() {
    switch (E_No[1]) {
    case 0:
        break;

    case 1:
        E_No[1] += 1;
        E_Timer = 50;
        Disp_00_0();
        break;

    case 2:
        if (--E_Timer == 0) {
            E_No[1] += 1;
            E_Timer = 30;
            break;
        }

        Disp_00_0();
        break;

    case 3:
        if (!--E_Timer) {
            E_No[1] -= 1;
            E_Timer = 50;
            Disp_00_0();
            break;
        }

        break;
    }
}

void Disp_00_0() {
    if (save_w[1].extra_option.contents[3][5] == 0) {
        return;
    }

    SSPutStr(15, Insert_Y, 9, "PRESS START BUTTON");

    if (!(G_No[1] == 3 || G_No[1] == 5)) {
        return;
    }

    SSPutStr(5, 0, 9, "PRESS 1P START");
    SSPutStr(30, 0, 9, "PRESS 2P START");
}

void Entry_01() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        E_No[1] = 1;
        Break_Into = 0;
        break;

    case 1:
        Entry_00();

        if (~p1sw_1 & p1sw_0 & 0x4000) {
            Entry_01_Sub(0);
            return;
        }

        if (~p2sw_1 & p2sw_0 & 0x4000) {
            Entry_01_Sub(1);
            return;
        }

        break;

    case 2:
        if (Request_E_No) {
            E_No[2] += 1;
            return;
        }

        break;

    default:
        Exit_Title_Sub_Entry();
        break;
    }
}

void Entry_01_Sub(s16 PL_id) {
    E_No[2] += 1;
    Request_G_No = 1;
    plw[PL_id].wu.operator= 1;
    Operator_Status[PL_id] = 1;
    Champion = PL_id;
    plw[PL_id ^ 1].wu.operator= 0;
    Operator_Status[PL_id ^ 1] = 0;
    Ignore_Entry[0] = 0;
    Ignore_Entry[1] = 0;

    if (Continue_Coin[PL_id] == 0) {
        grade_check_work_1st_init(PL_id, 0);
    }
}

void Exit_Title_Sub_Entry() {
    s16 i;
    s16 j;

    E_No[0] = 2;
    E_No[1] = 0;
    E_No[2] = 0;
    E_No[3] = 0;
    F_No1[0] = F_No2[0] = F_No3[0] = 0;
    F_No1[1] = F_No2[1] = F_No3[1] = 0;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            E_Number[i][j] = 0;
        }
    }
}

void Entry_02() {
    switch (E_No[1]) {
    case 0:
        E_No[1] += 1;
        break;
    }

    Entry_Main_Sub(0, 2);
    Entry_Main_Sub(1, 2);
}

void Entry_03() {
    switch (E_No[1]) {
    case 0:
        Entry_03_1st();
        break;

    default:
        Entry_03_2nd();
        break;
    }
}

void Entry_03_1st() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        break;
    }

    Entry_Main_Sub(0, 4);
    Entry_Main_Sub(1, 4);
}

void Entry_03_2nd() {
    switch (E_No[2]) {
    case 0:
        if (--E_Timer == 0) {
            if (Check_LDREQ_Break() == 0) {
                E_No[2] += 1;
                Switch_Screen_Init(1);
                return;
            }

            E_Timer = 1;
            return;
        }

        break;

    case 1:
        if (Switch_Screen(1) != 0) {
            Cover_Timer = 23;
            G_No[1] = 1;
            G_No[2] = 0;
            G_No[3] = 0;
            E_No[0] = 2;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;
            plw[New_Challenger].wu.operator= 1;
            Operator_Status[New_Challenger] = 1;
            Sel_Arts_Complete[Champion] = -1;

            if (Continue_Coin[New_Challenger] == 0) {
                grade_check_work_1st_init(New_Challenger, 0);
            }
        }

        break;
    }
}

void Entry_04() {
    switch (E_No[1]) {
    case 0:
        Entry_04_1st();
        break;

    default:
        Entry_04_2nd();
        break;
    }
}

void Entry_04_1st() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        break;
    }

    if (Game_pause != 0x81) {
        Entry_Main_Sub(0, 5);
        Entry_Main_Sub(1, 5);
    }
}

void Entry_04_2nd() {
    switch (E_No[2]) {
    case 0:
        if (--E_Timer == 0) {
            if (Check_LDREQ_Break() == 0) {
                E_No[2] += 1;
                Switch_Screen_Init(1);
                return;
            }

            E_Timer = 1;
            return;
        }

        break;

    case 1:
        if (Switch_Screen(0) != 0) {
            E_No[2] += 1;
            Cover_Timer = 23;
            G_No[1] = 1;
            G_No[2] = 0;
            G_No[3] = 0;

            if (E_No[3] == 0xFF) {
                E_Number[LOSER][0] = 1;
                E_Number[LOSER][1] = 0;
                E_Number[LOSER][2] = 0;
                E_Number[LOSER][3] = 0;
            } else {
                Correct_BI_Data();
            }

            E_No[0] = 2;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;
            Game_pause = 0;
            plw[New_Challenger].wu.operator= 1;
            Operator_Status[New_Challenger] = 1;

            if (Continue_Coin[New_Challenger] == 0) {
                grade_check_work_1st_init(New_Challenger, 0);
            }
        }

        break;
    }
}

void Entry_06() {
    switch (E_No[1]) {
    case 0:
        Entry_06_1st();
        break;

    default:
        Entry_06_2nd();
        break;
    }
}

void Entry_06_1st() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        break;
    }

    Entry_Main_Sub(0, 7);
    Entry_Main_Sub(1, 7);
}

void Entry_06_2nd() {
    if (E_07_Flag[0] == 0) {
        Entry_Main_Sub(0, 7);
    }

    if (E_07_Flag[1] == 0) {
        Entry_Main_Sub(1, 7);
    }

    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        Switch_Screen_Init(1);
        break;

    case 1:
        if (Switch_Screen(1) != 0) {
            E_No[2] += 1;
            Cover_Timer = 23;
            return;
        }

        break;

    default:
        Switch_Screen(1);
        G_No[1] = 1;
        G_No[2] = 0;
        G_No[3] = 0;
        E_No[0] = 2;
        E_No[1] = 0;
        E_No[2] = 0;
        E_No[3] = 0;
        Fade_Flag = 0;

        if (E_07_Flag[0]) {
            plw[0].wu.operator= 1;
            Operator_Status[0] = 1;

            if (Continue_Coin[0] == 0) {
                grade_check_work_1st_init(0, 0);
            }
        }

        if (E_07_Flag[1]) {
            plw[1].wu.operator= 1;
            Operator_Status[1] = 1;

            if (Continue_Coin[1] == 0) {
                grade_check_work_1st_init(1, 0);
            }
        }

        E_07_Flag[0] = 0;
        E_07_Flag[1] = 0;

        if (E_Number[LOSER][0] == 5) {
            E_Number[LOSER][0] = 1;
        }

        break;
    }
}

void Entry_07() {
    switch (E_No[1]) {
    case 0:
        Entry_07_1st();
        break;

    default:
        Entry_07_2nd();
        break;
    }
}

void Entry_07_1st() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        break;
    }

    Entry_Main_Sub(0, 8);
    Entry_Main_Sub(1, 8);
}

void Entry_07_2nd() {
    if (E_07_Flag[0] == 0) {
        Entry_Main_Sub(0, 8);
    }

    if (E_07_Flag[1] == 0) {
        Entry_Main_Sub(1, 8);
    }

    switch (E_No[2]) {
    case 0:
        if (!--E_Timer) {
            E_No[2] += 1;
            Switch_Screen_Init(1);
        }

        break;

    default:
        if (Switch_Screen(1) != 0) {
            Cover_Timer = 23;
            G_No[1] = 1;
            G_No[2] = 0;
            G_No[3] = 0;
            E_No[0] = 2;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;

            if (E_07_Flag[0]) {
                plw[0].wu.operator= 1;
                Operator_Status[0] = 1;

                if (Continue_Coin[0] == 0) {
                    grade_check_work_1st_init(0, 0);
                }
            }

            if (E_07_Flag[1]) {
                plw[1].wu.operator= 1;
                Operator_Status[1] = 1;

                if (Continue_Coin[1] == 0) {
                    grade_check_work_1st_init(1, 0);
                }
            }

            E_07_Flag[0] = 0;
            E_07_Flag[1] = 0;
        }

        break;
    }
}

void Entry_08() {
    switch (E_No[1]) {
    case 0:
        Entry_08_1st();
        break;

    default:
        Entry_08_2nd();
        break;
    }
}

void Entry_08_1st() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        /* fallthrough */

    case 1:
        Entry_Main_Sub(0, 9);
        Entry_Main_Sub(1, 9);
        break;
    }
}

void Entry_08_2nd() {
    if (E_07_Flag[0] == 0) {
        Entry_Main_Sub(0, 9);
    }

    if (E_07_Flag[1] == 0) {
        Entry_Main_Sub(1, 9);
    }

    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;

        if ((E_Number[LOSER][0] == 8) && (E_Number[LOSER][1] == 1)) {
            Clear_Personal_Data(LOSER);
        }

        Switch_Screen_Init(1);
        break;

    default:
        if (Switch_Screen(1) != 0) {
            Cover_Timer = 23;
            G_No[1] = 1;
            G_No[2] = 0;
            G_No[3] = 0;
            E_No[0] = 2;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;

            if (E_07_Flag[0]) {
                plw[0].wu.operator= 1;
                Operator_Status[0] = 1;

                if (Continue_Coin[0] == 0) {
                    grade_check_work_1st_init(0, 0);
                }
            }

            if (E_07_Flag[1]) {
                plw[1].wu.operator= 1;
                Operator_Status[1] = 1;

                if (Continue_Coin[1] == 0) {
                    grade_check_work_1st_init(1, 0);
                }
            }

            E_07_Flag[0] = 0;
            E_07_Flag[1] = 0;
            Request_Disp_Rank[0][0] = -1;
            Request_Disp_Rank[0][1] = -1;
            Request_Disp_Rank[1][0] = -1;
            Request_Disp_Rank[1][1] = -1;
        }

        break;
    }
}

void Entry_10() {
    if ((E_Number[0][0] == 0x63) && (E_Number[1][0] == 0x63)) {
        cpExitTask(1);
        return;
    }

    switch (E_No[1]) {
    case 0:
        Entry_10_1st();
        break;

    default:
        Entry_10_2nd();
        break;
    }
}

void Entry_10_1st() {
    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;
        break;

    case 1:
        E_No[2] += 1;
        Setup_Final_Grade();

        if (Check_Ranking(WINNER) != 0) {
            E_Number[WINNER][0] = 2;
            E_Number[WINNER][1] = 0;
            E_Number[WINNER][2] = 0;
            E_Number[WINNER][3] = 0;
            Request_Disp_Rank[WINNER][0] = Rank_In[WINNER][0];
            Request_Disp_Rank[WINNER][1] = Rank_In[WINNER][1];
            Request_Disp_Rank[WINNER][2] = Rank_In[WINNER][2];
            Request_Disp_Rank[WINNER][3] = Rank_In[WINNER][3];
        } else {
            E_Number[WINNER][0] = 8;
            E_Number[WINNER][1] = 0;
        }

        /* fallthrough */

    default:
        Entry_Main_Sub(0, 10);
        Entry_Main_Sub(1, 10);
        break;
    }
}

void Entry_10_2nd() {
    if (E_07_Flag[0] == 0) {
        Entry_Main_Sub(0, 10);
    }

    if (E_07_Flag[1] == 0) {
        Entry_Main_Sub(1, 10);
    }

    switch (E_No[2]) {
    case 0:
        E_No[2] += 1;

        if ((E_Number[LOSER][0] == 8) && (E_Number[LOSER][1] == 1)) {
            Clear_Personal_Data(LOSER);
        }

        Switch_Screen_Init(1);
        break;

    default:
        if (Switch_Screen(1) != 0) {
            Cover_Timer = 23;
            G_No[1] = 1;
            G_No[2] = 0;
            G_No[3] = 0;
            E_No[0] = 2;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;

            if (E_07_Flag[0]) {
                plw[0].wu.operator= 1;
                Operator_Status[0] = 1;

                if (Continue_Coin[0] == 0) {
                    grade_check_work_1st_init(0, 0);
                }
            }

            if (E_07_Flag[1]) {
                plw[1].wu.operator= 1;
                Operator_Status[1] = 1;

                if (Continue_Coin[1] == 0) {
                    grade_check_work_1st_init(1, 0);
                }
            }

            E_07_Flag[0] = 0;
            E_07_Flag[1] = 0;
            Request_Disp_Rank[0][0] = -1;
            Request_Disp_Rank[0][1] = -1;
            Request_Disp_Rank[1][0] = -1;
            Request_Disp_Rank[1][1] = -1;
        }

        break;
    }
}

void Entry_Main_Sub(s16 PL_id, s16 Jump_Index) {
    ENTRY_X = 0;

    switch (E_Number[PL_id][0]) {
    case 0:
        if (!Ignore_Entry[LOSER]) {
            if ((E_No[0] == 10) || (E_No[0] == 8)) {
                E_Number[PL_id][0] = 99;
                return;
            }

            if (plw[PL_id].wu.operator== 0) {
                Entry_Common_Sub(PL_id, Jump_Index);
                return;
            }
        }

        break;

    case 1:
        if (PL_id) {
            if (Credit_Continue_2P() != 0) {
                Break_Into_Sub(PL_id, Jump_Index);
            }
        } else if (Credit_Continue_1P() != 0) {
            Break_Into_Sub(PL_id, Jump_Index);
        }

        if (Request_Break[PL_id]) {
            E_Number[PL_id][0] = 0;
            E_Number[PL_id][1] = 0;
            E_Number[PL_id][2] = 0;
            E_Number[PL_id][3] = 0;
            return;
        }

        if ((E_Number[PL_id][0] == 1) && (E_07_Flag[PL_id ^ 1] == 0)) {
            Entry_Continue_Sub(PL_id);
            return;
        }

        break;

    case 2:
        switch (E_Number[PL_id][1]) {
        case 0:
            E_Number[PL_id][1] += 1;
            Personal_Timer[PL_id] = 30;
            break;

        case 1:
            if (!--Personal_Timer[PL_id]) {
                E_Number[PL_id][1] += 1;
                Naming_Init(PL_id);
                return;
            }

            break;

        case 2:
            if (Forbid_Break != 1) {
                if (PL_id == 0) {
                    Naming_Cut_Sub_1P();
                } else {
                    Naming_Cut_Sub_2P();
                }

                if (Name_Input(PL_id)) {
                    Name_In_Sub(PL_id);

                    if (Naming_Cut[PL_id]) {
                        Clear_Personal_Data(PL_id);
                        return;
                    }

                    E_Number[PL_id][2] = 0;
                    E_Number[PL_id][3] = 0;

                    if (E_No[0] == 8) {
                        E_Number[PL_id][0] = 8;
                        E_Number[PL_id][1] = 1;
                        return;
                    }

                    E_Number[PL_id][0] = 8;
                    E_Number[PL_id][1] = 0;
                    return;
                }
            }

            break;
        }

        break;

    case 3:
        switch (E_Number[PL_id][1]) {
        case 0:
            if ((E_No[0] == 8) || (E_No[0] == 2)) {
                E_Number[PL_id][0] = 2;
                E_Number[PL_id][1] = 2;
                E_Number[PL_id][2] = 0;
                E_Number[PL_id][3] = 0;
                Naming_Init(PL_id);
                return;
            }

            break;

        case 1:
            if ((E_No[0] == 8) || (E_No[0] == 2)) {
                E_Number[PL_id][0] = 8;
                E_Number[PL_id][1] = 1;
                E_Number[PL_id][2] = 0;
                E_Number[PL_id][3] = 0;

                if (E_No[0] == 2) {
                    E_Number[PL_id][1] = 0;
                    return;
                }
            }

            break;
        }

        break;

    case 8:
        switch (E_Number[PL_id][1]) {
        case 0:
            In_Game_Sub(PL_id);
            break;

        case 1:
            In_Over_Sub(PL_id);
            break;
        }

        break;

    case 5:
        Loser_Scene_Sub(PL_id, Jump_Index);
        break;
    }
}

void Naming_Init(s16 PL_id) {
    Naming_Cut[PL_id] = 0;
    Name_00[PL_id] = 0;
    name_wk[PL_id].r_no_0 = 0;
    name_wk[PL_id].r_no_1 = 0;
    end_name_cut[PL_id] = 0;
}

void Naming_Cut_Sub_1P() {
    if (!Naming_Cut[0] && (Ck_Break_Into_SP(p1sw_0, p1sw_1, 0) != 0)) {
        Game_pause = 0;
        Naming_Cut[0] = 1;
        Request_Break[0] = 1;
    }
}

void Naming_Cut_Sub_2P() {
    if (!Naming_Cut[1] && (Ck_Break_Into_SP(p2sw_0, p2sw_1, 1) != 0)) {
        Game_pause = 0;
        Naming_Cut[1] = 1;
        Request_Break[1] = 1;
    }
}

void Name_In_Sub(s16 PL_id) {
    if (Rank_In[PL_id][0] >= 0) {
        Name_In_Sub0(PL_id, Rank_In[PL_id][0] + 0);
    }

    if (Rank_In[PL_id][1] >= 0) {
        Name_In_Sub0(PL_id, Rank_In[PL_id][1] + 5);
    }

    if (Rank_In[PL_id][2] >= 0) {
        Name_In_Sub0(PL_id, Rank_In[PL_id][2] + 10);
    }

    if (Rank_In[PL_id][3] >= 0) {
        Name_In_Sub0(PL_id, Rank_In[PL_id][3] + 15);
    }
}

void Name_In_Sub0(s16 PL_id, s16 xx) {
    Ranking_Data[xx].name[0] = rank_name_w[PL_id].code[0];
    Ranking_Data[xx].name[1] = rank_name_w[PL_id].code[1];
    Ranking_Data[xx].name[2] = rank_name_w[PL_id].code[2];
}

void Entry_Common_Sub(s16 PL_id, s16 Jump_Index) {
    if (PL_id) {
        if (Credit_Sub_2P() != 0) {
            Break_Into_Sub(PL_id, Jump_Index);
        }
    } else if (Credit_Sub_1P() != 0) {
        Break_Into_Sub(PL_id, Jump_Index);
    }
}

void Loser_Scene_Sub(s16 PL_id, s16 Jump_Index) {
    if (PL_id) {
        if (Loser_Sub_2P() != 0) {
            Break_Into_Sub(PL_id, Jump_Index);
        }
    } else if (Loser_Sub_1P() != 0) {
        Break_Into_Sub(PL_id, Jump_Index);
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Loser_Sub_1P);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Loser_Sub_2P);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Credit_Sub_1P);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Credit_Sub_2P);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Credit_Continue_1P);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Credit_Continue_2P);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_Continue_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Setup_Next_Step);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", In_Game_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", In_Over_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Flash_Start);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Flash_Please);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", literal_655_0051F218);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", literal_766_0051F228);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", literal_808_0051F240);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", literal_809_0051F260);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", literal_827_0051F280);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Break_Into_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Ck_Break_Into);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Ck_Break_Into_SP);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Break_Into_02);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Break_Into_04);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Break_Into_05);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Break_Into_07);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Break_Into_08);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Break_Into_09);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Break_Into_10);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Continue_Score_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Correct_BI_Data);
