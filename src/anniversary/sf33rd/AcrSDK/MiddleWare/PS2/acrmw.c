#include "sf33rd/AcrSDK/MiddleWare/PS2/acrmw.h"
#include "common.h"
#include "sf33rd/AcrSDK/MiddleWare/PS2/ADX/flADX.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"

void flmwVSyncCallback() {
    flAdxControll(0);
}

static void flmwFlipSub() {
    if (flPS2FlipCancelFlag > 0) {
        flPS2FlipCancelFlag -= 1;
        return;
    }

    flPs2State.Db_change_enable = 1;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/acrmw", flmwFlip);
