#include "sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB", mlTsbInit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB", mlTsbExecServer);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB", mlTsbStopAll);
#else
s32 mlTsbStopAll() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB", mlTsbSetBankAddr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB", mlTsbGetDataAdrs);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB", mlTsbKeyOn);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB", mlTsbRequest);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB", mlTsbSetToReqp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB", mlTsbInitEchoWork);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB", mlTsbMoveEchoWork);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB", mlTsbPickupEchoWork);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB", mlTsbCreateEcho);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB", mlTsbStopEcho);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlTSB", mlTsbStopEchoAll);
