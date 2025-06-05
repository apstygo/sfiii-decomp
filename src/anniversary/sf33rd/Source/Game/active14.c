#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Computer14);

void Pattern14_0000(PLW *wk) {
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

void Pattern14_0001(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Wait(wk, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0002(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0003(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0004(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0005(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x100);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0006(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0007(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0008(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x12);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0009(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x22);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0010(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x42);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0011(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0012(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0013(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0014(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0015(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0016(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0017(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1F, 8, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0018(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0019(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0020(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0021(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x20, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0022(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 9, 0x20, 8, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0023(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 9, 0x20, 9, -1);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0024(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0x7F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0025(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Keep_Away(wk, 0xBF, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0026);

void Pattern14_0027(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Lever_Attack(wk, 8, 0, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0028(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;

    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x30, 0, -0x7F80, -1, 0x400);
        break;

    case 2:
        Lever_Attack(wk, 8, 0, 0x20);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0029(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC8, 0xB, 0x400, 0, -0x7F80, -1, 0x400);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 3:
        Command_Attack(wk, 0xC, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0030);

void Pattern14_0031(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC8, 0xB, 0x400, 0, -0x7F80, -1, 0x400);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 3:
        Command_Attack(wk, 0xC, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0032);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0033);

void Pattern14_0034(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 2:
        Jump_Command_Attack_Term(wk, 0xB, 0x2F, 0xA, -1, -1, 0x30, 0, -1, -1, -1);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0035(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;

    case 1:
        Hi_Jump_Attack_Term(wk, -1, 0x61, 8, 0x202, 0, -0x7F80, -1, 0x400);
        break;

    case 2:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0036);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0037);

void Pattern14_0038(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0039(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0040(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;

    case 1:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0041(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;

    case 1:
        J_Command_Attack(wk, 0xB, 0x20, 8, -1);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0042(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 2:
        Command_Attack(wk, 0xC, 0x1F, 0xA, -1);
        break;

    case 3:
        Wait(wk, 1);
        break;

    case 4:
        SA_Term(wk, 0x2F, 0x30, 0x31, 0x7F);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0043(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        ETC_Term(wk, 3, 2, 0);
        break;

    case 1:
        Normal_Attack(wk, 0xB, 0x202);
        break;

    case 2:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0044(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x71, 0x71, 0x72, 0x73, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0045(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x74, 0x74, 0x75, 0x76, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0046(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0047(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8014, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0048(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8015, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0049(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        J_Command_Attack(wk, 8, 0x8016, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0050(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Branch_Unit_Area(wk, 2, 0x37, 0x37, 0x36, 0x35);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0051(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8016, 0xA, -1, -0x7FB0, -0x7FC0, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0052);

void Pattern14_0053(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8014, 8, -1, -1, 0x20, 0, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0054(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8014, 8, -1, -1, 0x20, 2, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0055(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Jump_Command_Attack_Term(wk, 8, 0x8014, 8, -1, -1, 0x20, 1, -1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0056(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 1:
        SA_Term(wk, 0x32, 0xFFFF, 0xFFFF, 0xBF);
        break;

    case 2:
        Com_Random_Select(wk, 6, 0x74, 0x74, 0x75, 0x76, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0057(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0x84, 0x84, 0x85, 0x86, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0058(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC8, 9, 0x400, 0, -0x7F80, -1, 0x400);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x220);
        break;

    case 3:
        Normal_Attack(wk, 0xC, 0x202);
        break;

    case 4:
        Command_Attack(wk, 0xC, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0059);

void Pattern14_0060(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC8, 9, 0x400, 0, -0x7F80, -1, 0x400);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x220);
        break;

    case 3:
        SA_Term(wk, 0x32, 0xFFFF, 0xFFFF, 0xBF);
        break;

    case 4:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0061);

void Pattern14_0062(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 1:
        Jump_Attack_Term(wk, -0x7FA8, -0x7FC8, 9, 0x400, 0, -0x7F80, -1, 0x400);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x220);
        break;

    case 3:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;

    case 4:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0063);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0064);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0065);

void Pattern14_0066(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2E, 8, -1, -1, 0x34, 0, -0x7F80, -1, 0x400);
        break;

    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;

    case 3:
        Com_Random_Select(wk, 6, 0x77, 0x77, 0x78, 0x79, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0067(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Pierce_On(wk);
        break;

    case 1:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 2:
        Jump_Command_Attack_Term(wk, 0xB, 0x2F, 0xA, -1, -1, 0x40, 0, -1, -1, -1);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0068(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0069(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0xB2, 0xB3, 0xB4, 0xB6, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0070(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0xB9, 0xBB, 0xBC, 0xBD, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0071(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;

    case 1:
        Com_Random_Select(wk, 6, 0xB5, 0xB7, 0xBF, 0xC0, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0072(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB2, 0xB3, 0xB4, 0xB6, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0073(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB9, 0xBB, 0xBC, 0xBD, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0074(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 6, 0xB5, 0xB7, 0xBF, 0xC0, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0075(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x7F, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0076(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;

    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0077(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0078(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x200);
        break;

    case 3:
        Command_Attack(wk, 8, 0x1F, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0079(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 2:
        J_Command_Attack(wk, 8, 0x20, 8, -1);
        break;

    case 3:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 4:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0080(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0081(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 2:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0082(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 0xD, 0x20);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x102);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0083);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0084);

void Pattern14_0085(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x220);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x202);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x40);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0086(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x12);
        break;

    case 1:
        Normal_Attack(wk, 9, 0x220);
        break;

    case 2:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 3:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0087);

void Pattern14_0088(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x102);
        break;

    case 1:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;

    case 2:
        Approach_Walk(wk, 0x10, 2);
        break;

    case 3:
        Lever_Attack(wk, 8, 0, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0089(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Normal_Attack(wk, 9, 0x100);
        break;

    case 1:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x7F);
        break;

    case 2:
        Approach_Walk(wk, 0x10, 2);
        break;

    case 3:
        Lever_Attack(wk, 8, 1, 0x110);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0090);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0091);

void Pattern14_0092(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;

    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x202, 0, -0x7F80, -1, 0x40);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0093(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;

    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x202, 0, -0x7F80, -1, 0x40);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0094(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;

    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x202, 0, -0x7F80, -1, 0x40);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0095(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;

    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x202, 0, -0x7F80, -1, 0x40);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0096(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0097(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0098(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0099(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0, -1, -1);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0100(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;

    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 0xA, -1, -0x7F60, 0x50, 0, -0x7F80, -1, 0x400);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0101(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;

    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 0xA, -1, -0x7F60, 0x50, 0, -0x7F80, -1, 0x400);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0102(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;

    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 0xA, -1, -0x7F60, 0x50, 0, -0x7F80, -1, 0x400);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0103(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 3);
        break;

    case 1:
        Jump_Command_Attack_Term(wk, 8, 0x2F, 0xA, -1, -0x7F60, 0x50, 0, -0x7F80, -1, 0x400);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0104(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0105(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0106(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0107(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0108(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    case 1:
        Turn_Over_On(wk);
        break;

    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x202, 0, -0x7F80, -1, 0x40);
        break;

    case 3:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0109(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    case 1:
        Turn_Over_On(wk);
        break;

    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x202, 0, -0x7F80, -1, 0x40);
        break;

    case 3:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0110(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    case 1:
        Turn_Over_On(wk);
        break;

    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x202, 0, -0x7F80, -1, 0x40);
        break;

    case 3:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0111(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    case 1:
        Turn_Over_On(wk);
        break;

    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x202, 0, -0x7F80, -1, 0x40);
        break;

    case 3:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0112(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 1, -1, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0113(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x22, 8, -1);
        break;

    case 1:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;

    case 2:
        EM_Term(wk, -0x7FB0, -1, 5, 6, 1);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0114(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x300, 2, 0x76);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;

    case 3:
        EM_Term(wk, -0x7FB0, -1, 5, 6, 1);
        break;

    case 4:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0115(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x80, 2, 0x76);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 0xA, -1);
        break;

    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;

    case 3:
        EM_Term(wk, -0x7FB0, -1, 5, 6, 1);
        break;

    case 4:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0116(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x200, 2, 0x77);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;

    case 3:
        EM_Term(wk, -0x7FB0, -1, 5, 6, 1);
        break;

    case 4:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0117(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Search_Back_Term(wk, 0x100, 2, 0x77);
        break;

    case 1:
        Command_Attack(wk, 8, 0x1D, 8, -1);
        break;

    case 2:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;

    case 3:
        EM_Term(wk, -0x7FB0, -1, 5, 6, 1);
        break;

    case 4:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0118(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 0xA, -1);
        break;

    case 1:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;

    case 2:
        EM_Term(wk, -0x7FB0, -1, 5, 6, 1);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0119(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x1C, 8, -1);
        break;

    case 1:
        SA_Term(wk, 0x34, 0x34, 0x34, 0x47);
        break;

    case 2:
        EM_Term(wk, -0x7FB0, -1, 5, 6, 1);
        break;

    case 3:
        J_Command_Attack(wk, 8, 0x1E, 8, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0120(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 1:
        Look(wk, 2);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0121(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x72, 2);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0122(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x72, 2);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0123(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x72, 2);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0124(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x72, 2);
        break;

    case 1:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0125(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x21, 0x3F, 0x40, 0x41, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0126(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x23, 0x24, 0x25, 0x3D, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0127(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x22, 0x43, 0x3C, 0x3E, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0128(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0xBF, 2);
        break;

    case 1:
        Look(wk, 2);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0129(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x72, 2);
        break;

    case 1:
        Look(wk, 2);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0130(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x71, 0x72, 0x71, 0x72, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0131(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x1A, 0x1C, 0x1D, 0x1E, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0132(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x78, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x202);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0133(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x86, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x402);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0134(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x77, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x200);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0135(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x84, 2);
        break;

    case 1:
        Normal_Attack(wk, 8, 0x400);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0136(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x84, 0x85, 0x86, 0x87, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0137);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0138);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0139);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_0140);

void Pattern14_0141(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x89, 0x8A, 0x8B, 0x8C, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0142(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x57, 3);
        break;

    case 1:
        Turn_Over_On(wk);
        break;

    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x202, 0, -0x7F80, -1, 0x40);
        break;

    case 3:
        Com_Random_Select(wk, 2, 0x89, 0x8A, 0x8B, 0x8C, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0143(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Turn_Over_On(wk);
        break;

    case 1:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x202, 0, -0x7F80, -1, 0x40);
        break;

    case 2:
        Com_Random_Select(wk, 2, 0x89, 0x8A, 0x8B, 0x8C, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0144(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Com_Random_Select(wk, 2, 0x26, 0x27, 0x28, 0x29, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0145(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x57, 3);
        break;

    case 1:
        Turn_Over_On(wk);
        break;

    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x202, 0, -0x7F80, -1, 0x40);
        break;

    case 3:
        Com_Random_Select(wk, 2, 0x4C, 0x4D, 0x4E, 0x4F, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0146(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x57, 3);
        break;

    case 1:
        Turn_Over_On(wk);
        break;

    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x202, 0, -0x7F80, -1, 0x40);
        break;

    case 3:
        Com_Random_Select(wk, 2, 0x50, 0x51, 0x52, 0x53, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0147(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x57, 3);
        break;

    case 1:
        Turn_Over_On(wk);
        break;

    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x202, 0, -0x7F80, -1, 0x40);
        break;

    case 3:
        Com_Random_Select(wk, 2, 0x54, 0x55, 0x56, 0x57, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0148(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Approach_Walk(wk, 0x57, 3);
        break;

    case 1:
        Turn_Over_On(wk);
        break;

    case 2:
        Jump_Attack_Term(wk, -1, 0x49, 9, 0x202, 0, -0x7F80, -1, 0x40);
        break;

    case 3:
        Com_Random_Select(wk, 2, 0x58, 0x59, 0x5A, 0x5B, 0);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0149(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Command_Attack(wk, 8, 0x8019, 0xA, -1);
        break;

    case 1:
        J_Command_Attack(wk, 0xB, 0x20, 9, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

void Pattern14_0150(PLW *wk) {
    switch (CP_Index[wk->wu.id][0]) {
    case 0:
        Check_SA_Full(wk, 6, 0x7C);
        break;

    case 1:
        EM_Term(wk, -0x7F30, -1, 5, 2, 0);
        break;

    case 2:
        Command_Attack(wk, 8, 0x8019, 0xA, -1);
        break;

    default:
        End_Pattern(wk);
        break;
    }
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/active14", Pattern14_Tbl);
