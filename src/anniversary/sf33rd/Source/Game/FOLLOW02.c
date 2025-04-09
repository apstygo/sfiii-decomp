#include "common.h"
#include "sf33rd/Source/Game/Com_Sub.h"
#include "sf33rd/Source/Game/workuser.h"
#include "structs.h"

void Follow02(PLW *wk);
void Follow02_0000(PLW *wk);
void Follow02_0001(PLW *wk);
void Follow02_0002(PLW *wk);
void Follow02_0003(PLW *wk);

typedef void (*FOLLOW02_TBL)(PLW *wk);

const FOLLOW02_TBL Follow02_Tbl[4] = {
    Follow02_0000,
    Follow02_0001,
    Follow02_0002,
    Follow02_0003,
};

void Follow02(PLW *wk) {
    Follow02_Tbl[(s16)Pattern_Index[(s32)wk->wu.id]](wk);
}

void Follow02_0000(PLW *wk) {
    switch (*CP_Index[wk->wu.id]) {
    case 0:
        Normal_Attack(wk, 8, 0x10);
        return;
    case 1:
        Normal_Attack(wk, 8, 0x20);
        return;
    case 2:
        Normal_Attack(wk, 8, 0x200);
        return;
    default:
        End_Pattern(wk);
        return;
    }
}

void Follow02_0001(PLW *wk) {

    switch (*CP_Index[wk->wu.id]) {
    case 0:
        Normal_Attack(wk, 8, 0x20);
        return;
    case 1:
        Command_Attack(wk, 2, 8U, 0x1C, 8);
        return;
    default:
        End_Pattern(wk);
        return;
    }
}

void Follow02_0002(PLW *wk) {
    switch (*CP_Index[wk->wu.id]) {
    case 0:
        Normal_Attack(wk, 8, 0x10U);
        return;
    case 1:
        Normal_Attack(wk, 8, 0x20U);
        return;
    case 2:
        Normal_Attack(wk, 8, 0x200U);
        return;
    default:
        End_Pattern(wk);
        return;
    }
}

void Follow02_0003(PLW *wk) {

    switch (*CP_Index[wk->wu.id]) {
    case 0:
        Normal_Attack(wk, 8, 0x20U);
        return;
    case 1:
        Command_Attack(wk, 2, 8U, 0x1C, 8);
        return;
    default:
        End_Pattern(wk);
        return;
    }
}
