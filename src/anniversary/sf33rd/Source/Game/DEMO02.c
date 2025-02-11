#include "common.h"
#include "sf33rd/Source/Game/Game.h"
#include "sf33rd/Source/Game/PLS02.h"
#include "sf33rd/Source/Game/SYS_sub.h"
#include "unknown.h"

void Demo00();
void Demo01();

s32 Play_Demo() {
    void (*main_jmp_tbl[2])() = { Demo00, Demo01 };

    Next_Demo = 0;
    main_jmp_tbl[D_No[0]]();
    return Next_Demo;
}

void Demo00() {
    Play_Game = 1;

    switch (D_No[1]) {
    case 0:
        Switch_Screen(1);
        Purge_texcash_of_list(3);
        Make_texcash_of_list(3);
        D_No[1] += 1;
        G_No[2] = 0;
        Game_pause = 0;
        Conclusion_Flag = 0;
        appear_type = 1;
        Control_Time = 0x800;
        Round_Level = 7;
        Weak_PL = random_16() & 1;
        break;

    case 1:
        Switch_Screen(1);
        Game02();

        if (--Cover_Timer == 0) {
            D_No[1] += 1;
            Switch_Screen_Init(0);
            return;
        }

        break;

    case 2:
        Game02();

        if (Switch_Screen_Revival(0) != 0) {
            D_No[1] += 1;
            D_Timer = 1800;
            Stop_SG = 0;
            return;
        }

        break;

    case 3:
        Game02();

        if (Debug_w[0x18] == 9) {
            D_Timer = 60;
        }

        if (--D_Timer == 1) {
            D_No[1] += 1;
            Stop_Combo = 1;
            return;
        }

        if (Conclusion_Flag) {
            D_No[1] += 1;
            Stop_Combo = 1;
            D_Timer = 90;
            return;
        }

        break;

    case 4:
        Game02();

        if (--D_Timer == 0) {
            D_No[1] += 1;
            Game_pause = 1;
            Disappear_LOGO = 1;
            D_Timer = 16;
            return;
        }

        break;

    case 5:
        Game02();

        if (--D_Timer == 0) {
            D_No[1] += 1;
            Switch_Screen_Init(0);
            SsBgmFadeOut(0x800);
            return;
        }

        break;

    case 6:
        Game02();

        if (Switch_Screen(0) != 0) {
            D_No[1] += 1;
            Demo_Flag = 0;
            Present_Mode = 0;
            Cover_Timer = 23;
            BGM_Stop();

            if (++Select_Demo_Index > 3) {
                Select_Demo_Index = 0;
                return;
            }
        }

        break;

    default:
        Switch_Screen(1);
        Next_Demo = 1;
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Demo01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Setup_Demo_PL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Setup_Demo_Arts);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Setup_Demo_Stage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Setup_Select_Demo_PL);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Demo_PL_Play_Data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Arts_Rnd_Demo_Data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Demo_Stage_Play_Data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO02", Demo_PL_Data);
