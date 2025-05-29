#include "common.h"
#include <cri/private/libadxe/adx_xpnd.h>

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_Init);
#else
void ADXPD_Init() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_Finish);
#else
void ADXPD_Finish() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_Create);
#else
ADXPD ADXPD_Create() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_SetCoef);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_SetDly);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_GetDly);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_SetExtPrm);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_GetExtPrm);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_Destroy);
#else
void ADXPD_Destroy(ADXPD) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_SetMode);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_GetStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_EntryMono);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_EntrySte);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_EntryPl2);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_Start);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_Stop);
#else
void ADXPD_Stop(ADXPD) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_Reset);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_GetNumBlk);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", adxpd_error);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_ExecHndl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_ExecServer);
