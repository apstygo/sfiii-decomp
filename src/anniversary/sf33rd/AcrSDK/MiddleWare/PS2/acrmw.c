#include "sf33rd/AcrSDK/MiddleWare/PS2/acrmw.h"
#include "common.h"
#include "sf33rd/AcrSDK/MiddleWare/PS2/ADX/flADX.h"

void flmwVSyncCallback() {
    flAdxControll(0);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/acrmw", flmwFlipSub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/acrmw", flmwFlip);
