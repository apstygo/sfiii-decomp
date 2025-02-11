#include "sf33rd/Source/Game/DEMO01.h"
#include "common.h"
#include "sf33rd/Source/Game/GD3rd.h"
#include "sf33rd/Source/Game/OPENING.h"
#include "sf33rd/Source/Game/SYS_sub.h"
#include "sf33rd/Source/Game/op_sub.h"
#include "unknown.h"

s16 Title() {
    s16 xx = 0;

    njSetBackColor(0, 0, 0);

    switch (D_No[1]) {
    case 0:
        if (Check_LDREQ_Clear() != 0) {
            Standby_BGM(0x34);
            D_No[1] += 1;
            D_Timer = 20;
        }

        break;

    case 1:
        if (D_Timer != 0) {
            D_Timer -= 1;
        } else if (opening_demo()) {
            D_No[1] += 1;
            D_Timer = 40;
        }

        break;

    case 2:
        opening_demo();

        if (--D_Timer == 0) {
            D_No[1] += 1;
            Switch_Screen_Init(1);
        }

        break;

    case 3:
        opening_demo();

        if (Switch_Screen(1) != 0) {
            D_No[1] += 1;
            Cover_Timer = 20;
        }

        break;

    case 4:
        Switch_Screen(1);
        D_No[1] += 1;
        D_Timer = 2;
        break;

    default:
        Switch_Screen(1);

        if (--D_Timer == 0) {
            TexRelease(0x259);
            xx = 1;
        }

        break;
    }

    return xx;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO01", Title_At_a_Dash);
