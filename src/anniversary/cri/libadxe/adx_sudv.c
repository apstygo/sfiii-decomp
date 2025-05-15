#include "common.h"
#include <cri/private/libadxe/dvci_sub.h>

#include <cri/ee/adx_ps2.h>

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sudv", adxps2_err_dvd);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_sudv", D_0055B450);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sudv", ADXPS2_SetupDvdFs);

Sint32 ADXPS2_LoadFcacheDvd(ADXPS2_FCPRM *fcprm) {
    Sint32 ret = 0;

    if (fcprm != NULL) {
        ret = dvCiLoadFcache(fcprm->flist, fcprm->fcbuf, fcprm->fcsize, fcprm->maxflen);
    } else {
        dvCiLoadFcache(NULL, NULL, 0, 0);
    }

    return ret;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sudv", ADXPS2_SetFcacheDvd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sudv", ADXPS2_SetRdModeDvd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sudv", ADXPS2_IsExistFcacheDvd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sudv", ADXPS2_SetDvdLayer);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sudv", ADXPS2_GetDvdLayer);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sudv", ADXPS2_SetDvdSeekPos);
