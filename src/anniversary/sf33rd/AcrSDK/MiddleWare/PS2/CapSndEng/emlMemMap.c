#include "sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlMemMap.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlMemMap", mlMemMapInit);
#else
s32 mlMemMapInit(void *pSpuMemMap) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlMemMap", mlMemMapGetBankAddr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlMemMap", mlMemMapSetPhdAddr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlMemMap", mlMemMapGetPhdAddr);
