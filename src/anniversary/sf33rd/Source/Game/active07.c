#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active07", Computer07);

void Pattern07_0000(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Off(wk);
        break;

    case 1:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0001(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0002(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 0xB, 0x1C, 8, -1);
        break;

    case 1:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0003(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x20);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x400);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0004(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0005(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x40);
        break;

    case 1:
        Lever_Attack(wk, 0xB, 0, 0x400);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0006(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0007(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0008(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F90, -0x7FC0, 8, 0x40, 0, -0x7F90, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0009(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0010(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F90, -0x7FC0, 8, 0x40, 0, -0x7F90, -1, 0x200);
        break;
    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;
    case 2:
        Lever_Attack(wk, 8, 0, 0x200);
        break;
    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0011(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    case 1:
        Lever_Attack(wk, 0xB, 0, 0x202);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0012(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0013(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x200);
        break;

    case 1:
        J_Command_Attack(wk, 9, 0x1E, 9, -1);
        break;

    case 2:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 3:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0014(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x200, 2, -0x7F80, -1, 0x200);
        break;

    case 1:
        Lever_Attack(wk, 9, 0, 0x200);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0015(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0016(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0017(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0018(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x50, 1, -1);
        break;

    case 1:
        Jump(wk, 1);
        break;

    case 2:
        Lever_Off(wk);
        break;

    case 3:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0019(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F9C, -0x7FC0, 8, 0x100, 0, -0x7F90, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0020(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0021(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F9C, -0x7FC0, 8, 0x20, 0, -0x7F90, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x400);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0022(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x40, 0, -0x7F90, -1, 0x100);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0023(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xC7, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0024(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0025(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0026(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xA, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    case 2:
        Lever_Off(wk);
        break;

    case 3:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active07", Pattern07_0027);

void Pattern07_0028(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x78, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0029(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0030(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 1:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0031(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 9, 0x200, 0, -0x7F68, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0032(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x10);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 2:
        Lever_Attack(wk, 0xB, 0, 0x100);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0033(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 0xB, 0x10);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0034(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x200);
        break;

    case 3:
        Lever_Off(wk);
        break;

    case 4:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0035(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0036(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0037(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    case 1:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0038(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0x36, 0x37, 0);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Adjust_Attack(wk, 0xB, 0x20);
        break;

    case 3:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 4:
        Lever_Attack(wk, 8, 0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0039(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xA, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0040(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0041(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xB, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x20);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0042(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0043(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x40, 0, -1, 0x30, 0x4020);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0044(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x40, 0, -1, 0x30, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0045(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x400, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0046(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0047(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x2E, 9, -1, -0x7FA0, 0x38, 0x0, -1, 0x30, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0048(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    case 1:
        Lever_Attack(wk, 8, 0, 0x100);
        break;

    case 2:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 0xA, -1, -1, 0x38, 1, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0049(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FC8, 8, 0x200, 0, -0x7FA8, -1, 0x200);
        break;

    case 1:
        Lever_Attack(wk, 9, 0, 0x100);
        break;

    case 2:
        Lever_Attack(wk, 9, 0, 0x100);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0050(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack(wk, 8, 0xA, 0x400, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0051(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, -0x7FC8, 8, 0x20, 0, -0x7FA8, -1, 0x200);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0052(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x8126, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0053(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x38, 0x3A, 0x3A, 0x3A);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0054(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0055(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0056(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8126, 9, -1, -1, 0x40, 1, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0057(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8126, 9, -1, -1, 0x40, 2, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0058(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8126, 0xA, -1, -1, 0x30, 2, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0059(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 9, -1);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x200);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0060(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x15, 0);
        break;

    case 1:
        Walk(wk, 1, 0x14, 0);
        break;

    case 2:
        Walk(wk, 0, 0x10, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0061(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x14, 0);
        break;

    case 1:
        Walk(wk, 0, 0x10, 0);
        break;

    case 2:
        Walk(wk, 1, 0x18, 0);
        break;

    case 3:
        Walk(wk, 0, 0x10, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0062(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x10, 0);
        break;

    case 1:
        Walk(wk, 1, 0x18, 0);
        break;

    case 2:
        Wait(wk, 0x10);
        break;

    case 3:
        Walk(wk, 0, 0x10, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0063(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F98, 0, 4, 2, 0);
        break;

    case 1:
        Command_Attack(wk, 8, 0, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0064(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0065(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0066(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0067(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x22, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0068(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x22, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0069(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x22, 0xA, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0070(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    case 1:
        EM_Term(wk, 0x50, -0x7FB0, 8, 1, -1);
        break;

    case 2:
        Command_Attack(wk, 8, 0x2E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0071(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    case 1:
        EM_Term(wk, 0x50, -0x7FB0, 8, 1, -1);
        break;

    case 2:
        SA_Term(wk, 0x48, 0xFFFF, 0xFFFF, 0);
        break;

    case 3:
        Command_Attack(wk, 8, 0x2E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0072(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x49, 0x49, 0x4A, 0x4B);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0073(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8126, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0074(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8126, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern07_0075(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8126, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/active07", Pattern07_Tbl);
