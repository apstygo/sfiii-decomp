#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active09", Computer09);

void Pattern09_0000(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x47, 0x47, 0x46, 0x46, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0001(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0002(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FC0, -1, 5, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0003(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -1, 5, 1, -1);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0004(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 1, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0005(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0006(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0x1E);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0007(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x60, 1, -1);
        break;

    case 1:
        Pierce_On(wk);
        break;

    case 2:
        Command_Attack(wk, 8, 1, 0xB, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0008(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F90, -0x7FC0, 0, 0x200, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0009(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FC0, -1, 5, 1, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0010(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -1, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0011(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -1, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0012(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -1, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0013(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F98, -1, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0014(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC8, 8, 0x200, 2, -0x7F80, -1, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0015(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0016(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x30, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0017(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, 0x58, -1, 5, 2, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0018(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 1);
        break;

    case 1:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0019(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F98, -1, 0, 2, 5);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0020(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Lever_On(wk, 1, 2);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x41, 0x42, 0x43, 0x44, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0021(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F10, -1, 5, 2, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0022(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F98, -0x7FA8, 8, 0x40, 0, -0x7F90, -1, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0023(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0024(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0025(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 1, 0x60, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0026(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 1:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0027(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0028(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0029(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -1, 5, 1, -1);
        break;

    case 1:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0030(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB0, -1, 5, 1, -1);
        break;

    case 1:
        Adjust_Attack(wk, 9, 0x100);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0031(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x400, 0, -0x7F68, -1, 0x200);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0032(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0033(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Adjust_Attack(wk, 9, 0x10);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0034(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0, 0x100);
        break;

    case 1:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0035(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -1, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0036(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F60, -1, 5, 2, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0037(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 1, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0038(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x10);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0039(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0040(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0041(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -1, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0042(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x12);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0043(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F98, -0x7FA8, 8, 0x40, 0, -1, 0x30, 0x401F);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0044(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FB0, 8, 0x40, 0, -1, 0x30, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0045(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, 8, 0x400, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0046(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Walk(wk, 0, 0x15, 0);
        break;

    case 1:
        Walk(wk, 1, 0x13, 0);
        break;

    case 2:
        Walk(wk, 0, 0x10, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0047(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1F, 0xA, -1, -0x7FA0, 0x30, 0, -1, 0x30, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0048(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, -0x5FF7, 0x400, 0, -0x7FB0, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x22);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0049(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F98, -0x7FA8, 9, 0x40, 0, -0x7FB0, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x200);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1D, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0050(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack(wk, 8, 0xA, 0x400, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0051(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Attack_Term(wk, -1, 0x30, 8, 0x40, 0, -1, -1, 0xFFFF);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0052(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Hi_Jump_Command_Attack_Term(wk, 8, 0x1F, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0053(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x39, 0x39, 0x3D, 0x3D, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0054(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0055(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0056(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0057(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8018, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0058(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x39, 0x39, 0x3C, 0x3C, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0059(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7F90, -1, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0060(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0061(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0062(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0xFFFF, 0x64, 0xFFFF, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0063(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7F90, -0x7FC0, 8, 0x200, 0, -0x7F68, -1, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0064(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FA8, 9, 0x40, 0, -0x7FB0, -1, 0x400);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1E, 0xA, -1);
        break;

    case 3:
        Wait(wk, 5);
        break;

    case 4:
        SA_Term(wk, 0x35, 0x64, 0x3A, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0065(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0066(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0067(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0068(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1E, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0069(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 9, -1, -1, -0x7FC0, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0070(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0071(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;

    case 1:
        Look(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0072(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FA0, -0x7FF0, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0073(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FC0, -0x7FF0, 5, 1, -1);
        break;

    case 1:
        Adjust_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0074(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        EM_Term(wk, -0x7FB8, -0x7FF0, 5, 1, -1);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0075(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC8, 8, 0x40, 0, -0x7FA0, -1, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0076(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 8, 0x200, 0, -0x7FA0, -1, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0077(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FC0, -0x5FF7, 0x400, 0, -0x7FA0, -1, 0x40);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x22);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1C, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active09", Pattern09_0078);

void Pattern09_0079(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0xFFFF, 0xFFFF, 0x9F);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0x64, 0x3A, 0);
        break;

    case 2:
        Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0080(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 1, 2);
        break;

    case 1:
        Command_Attack(wk, 8, 0, 0xB, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0081(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FA0, -0x7FD0, 0x2008, 0x200, 0, -0x7FA0, -1, 0x20);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0082(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 5, 2, 0);
        break;

    case 1:
        Provoke(wk, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0083(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 0, 0x30, 1, -1, -0x7FA0, 0x400, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0084(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Attack_Term(wk, -0x7FD0, 0x10, 8, 0x110, 0, -0x7FA0, -1, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0085(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 2, 0x40, 1, -1, -1, 0xFFFF, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0086(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 0, 0x50, 1, -1, -1, 0xFFFF, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0087(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 1, 0x40, 2, -1, -1, 0xFFFF, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0088(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 1, 0x40, 1, -1, -1, 0xFFFF, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0089(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x55, 0x56, 0x57, 0x58, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0090(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 0, 0x50, 0, -1, -1, 0xFFFF, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0091(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 0, 0x50, 2, -1, -1, 0xFFFF, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0092(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 2, 0x40, 0, -1, -1, 0xFFFF, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0093(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JA_Term(wk, 8, 1, 0x50, 0, -1, -1, 0xFFFF, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0094(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x5A, 0x5B, 0x5C, 0x5D, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0095(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JCA_Term(wk, 8, 0, 0x40, 1, -1, -0x7FB0, 0x2F, 0xA, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0096(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_JCA_Term(wk, 8, 0, 0x40, 0, -0x7FA0, -1, 0x2F, 0xA, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0097(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_HJCA_Term(wk, 8, 0, 0x40, 0, -0x7FA0, -1, 0x2F, 0xA, -1, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0098(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ORO_HJA_Term(wk, 8, 1, 0x50, 0, -1, -1, 0xFFFF, -0x7FB0, -0x7FD0, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0099(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        SA_Term(wk, 0x35, 0xFFFF, 0xFFFF, 0x9F);
        break;

    case 1:
        SA_Term(wk, 0xFFFF, 0xFFFF, 0x3A, 0);
        break;

    case 2:
        Command_Attack(wk, 8, 0x8015, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0100(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x36, 0x37, 0x38, 0x39, 1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern09_0101(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_On(wk, 0xFFFF, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/active09", Pattern09_Tbl);
