#include "sf33rd/Source/Game/DEMO00.h"
#include "common.h"
#include "sf33rd/Source/Game/AcrUtil.h"
#include "sf33rd/Source/Game/op_sub.h"
#include "unknown.h"

s32 Warning() {
    setTexAdrsMode(0);
    setFilterMode(1);
    Next_Demo = 0;

    switch (D_No[1]) {
    case 0:
        D_No[1] = 5;
        D_No[1] = 9;
        D_Timer = 120;
        FadeInit();
        Next_Demo = 0;
        break;

    case 5:
        Put_Warning(1);
        Next_Demo = 0;

        if (FadeIn(1, 8, 8) != 0) {
            D_No[1] += 1;
            D_Timer = 120;
        }

        break;

    case 6:
        if ((Usage == 7) && (((p1sw_0 & 0x4FF0) | (p2sw_0 & 0x4FF0)) != 0)) {
            D_Timer = 2;
            D_No[1] = 7;
            FadeInit();
        }

        Put_Warning(1);
        Next_Demo = 0;

        if (!--D_Timer) {
            D_No[1] += 1;
            D_Timer = 180;
        }

        break;

    case 7:
        if (((p1sw_0 & 0x4FF0) | (p2sw_0 & 0x4FF0)) != 0) {
            D_Timer = 1;
        }

        if (!--D_Timer) {
            D_No[1] += 1;
            FadeInit();
        }

        Put_Warning(1);
        Next_Demo = 0;
        break;

    case 8:
        Put_Warning(1);
        Next_Demo = 0;

        if (FadeOut(1, 8, 8) != 0) {
            D_No[1] += 1;
        }

        break;

    default:
        D_No[1] = 0;
        TexRelease(0x24E);
        Next_Demo = 1;
        break;
    }

    return Next_Demo;
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", caplogo00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", caplogo01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", CAPCOM_Logo);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", CAPLOGO_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", CAPLOGO_Move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", Put_char);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", Warning_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", Put_Warning);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", Pal_Cursor_Put);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", literal_253_00504ED0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", literal_254_00504EE0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", literal_315_00504F10);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", literal_316_00504F20);
