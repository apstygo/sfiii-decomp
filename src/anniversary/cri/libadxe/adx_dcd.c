#include "common.h"
#include <cri/private/libadxe/adx_dcd.h>

#include <cri/ee/cri_xpt.h>

// data
Sint32 adx_decode_output_mono_flag = 0;

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_GetCoefficient);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_ScanInfoCode);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", D_0055A1F0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_IsAdxFmt);

Sint32 ADX_DecodeInfo(Uint8 *arg0, Sint32 arg1, Sint16 *arg2, Sint8 *arg3, Sint8 *arg4, Sint8 *arg5, Sint8 *arg6,
                      Sint32 *arg7, Sint32 *arg8, Sint32 *arg9) {
    Sint8 temp_t0;

    if (arg1 < 16) {
        return -1;
    }

    if ((arg0[1] | (arg0[0] << 8)) != 0x8000) {
        return -2;
    }

    *arg2 = ((arg0[2] << 8) | arg0[3]) + 4;
    *arg3 = arg0[4];
    *arg5 = arg0[5];
    *arg4 = arg0[6];
    *arg6 = arg0[7];
    *arg7 = (arg0[8] << 24) | (arg0[9] << 16) | (arg0[10] << 8) | arg0[11];
    *arg8 = (arg0[12] << 24) | (arg0[13] << 16) | (arg0[14] << 8) | arg0[15];

    temp_t0 = *arg4;

    if (temp_t0 == 0) {
        *arg9 = 0;
    } else {
        *arg9 = ((*arg5 * 8) - 16) / temp_t0;
    }

    return 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoExADPCM2);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoExVer);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoExIdly);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoExLoop);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoAinf);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeFooter);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_CalcHdrInfoLen);
