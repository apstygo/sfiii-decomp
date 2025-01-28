#include "sf33rd/Source/Game/Entry.h"
#include "common.h"
#include "sf33rd/Source/Game/Reset.h"
#include "unknown.h"

u8 letter_stack[40];
u8 letter_counter;
u8 *letter_ptr;

const u8 Coin_Message_Data[7][2] = {
    { 5, 30 },
    { 2, 27 },
    { 7, 32 },
    { 17, 37 },
    { 6, 31 },
    { 5, 42 },
    { 0, 0 }
};

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

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_01_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Exit_Title_Sub_Entry);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_02);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_03);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_03_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_03_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_04);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_04_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_04_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_06);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_06_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_06_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_07);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_07_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_07_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_08);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_08_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_08_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_10);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_10_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_10_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_Main_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Naming_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Naming_Cut_Sub_1P);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Naming_Cut_Sub_2P);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Name_In_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Name_In_Sub0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Entry_Common_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Entry", Loser_Scene_Sub);

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
