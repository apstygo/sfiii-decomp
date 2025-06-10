#include "sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", mlSysSetMono);
#else
s32 mlSysSetMono(u32 mono_sw) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", mlSysSetMasterVolume);
#else
s32 mlSysSetMasterVolume(s32 vol) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", mlSysSetBankVolume);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", mlSeSetLfo);
#else
s32 mlSysSetMasterVolume(s32 vol) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", mlSeStop);
#else
s32 mlSysSetMasterVolume(s32 vol) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", mlSeKeyoff);
#else
s32 mlSysSetMasterVolume(s32 vol) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", mlSeStopAll);
#else
s32 mlSeStopAll() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", mlSeInitSndDrv);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", StartSound);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", PlaySe);
#else
s32 mlSysSetMasterVolume(s32 vol) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", CheckReqFlags);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", literal_289_005606E8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", literal_290_005606F0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", literal_291_00560700);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv", SendSeChange);
