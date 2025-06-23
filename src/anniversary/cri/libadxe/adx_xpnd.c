#include "common.h"
#include <cri/private/libadxe/adx_xpnd.h>

// working on this
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

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_SetCoef);
#else
void ADXPD_SetCoef(ADXPD, Sint32, Sint16) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_SetDly);
#else
void ADXPD_SetDly(ADXPD, Sint16 *, Sint16 *) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_GetDly);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_SetExtPrm);
#else
void ADXPD_SetExtPrm(ADXPD, Sint16, Sint16, Sint16) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_GetExtPrm);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_Destroy);
#else
void ADXPD_Destroy(ADXPD) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_SetMode);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_GetStat);
#else
Sint32 ADXPD_GetStat(ADXPD) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_EntryMono);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_EntrySte);
#else
void ADXPD_EntrySte(ADXPD, Sint32, Sint32, Sint32, Sint32) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_EntryPl2);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_Start);
#else
void ADXPD_Start(ADXPD) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_Stop);
#else
void ADXPD_Stop(ADXPD) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_Reset);
#else
void ADXPD_Reset(ADXPD) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_GetNumBlk);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", adxpd_error);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_ExecHndl);
#else
void ADXPD_ExecHndl(ADXPD) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_xpnd", ADXPD_ExecServer);
