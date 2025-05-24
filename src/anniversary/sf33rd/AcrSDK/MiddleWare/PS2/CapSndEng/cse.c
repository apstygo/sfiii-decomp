#include "sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse", cseInitSndDrv);
#else
s32 cseInitSndDrv() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
// Also used in cseCheckVTransStatus
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse", literal_251_005605F8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse", literal_252_00560600);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse", literal_253_00560610);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse", cseExecServer);
#else
s32 cseExecServer() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse", cseTsbRequest);
#else
s32 cseTsbRequest(u16 bank, u16 code, s32 NumArgSets, s32 /* unused */, s32 /* unused */, s32 /* unused */,
                  s32 /* unused */) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse", literal_307_00560630);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse", literal_308_00560640);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse", literal_309_00560678);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse", literal_310_00560680);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse", cseCheckVTransStatus);
#else
s32 cseCheckVTransStatus(u32 vtrans_check_type) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse", cseSendBd2SpuWithId);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse", cseGetIdStoredBd);
