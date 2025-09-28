#include "common.h"

#include <cri/ee/adx_ps2.h>
#include <cri/ee/cri_xpt.h>

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_suht", adxps2_err_host);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_suht", ADXPS2_SetupHostFs);
#else
void ADXPS2_SetupHostFs(ADXPS2_SPRM_HOST* sprmh) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_suht", ADXPS2_LoadFcacheHost);
#else
Sint32 ADXPS2_LoadFcacheHost(ADXPS2_FCPRM* fcprm) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_suht", ADXPS2_IsExistFcacheHost);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_suht", ADXPS2_SetRdModeHost);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_suht", D_0055B458);
