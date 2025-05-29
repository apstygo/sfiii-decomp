#include "common.h"
#include <cri/private/libadxe/adx_dcd.h>

#include <cri/ee/cri_xpt.h>

// data
Sint32 adx_decode_output_mono_flag = 0;

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_GetCoefficient);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_ScanInfoCode);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", D_0055A1F0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_IsAdxFmt);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfo);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoExADPCM2);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoExVer);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoExIdly);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoExLoop);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoAinf);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeFooter);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_CalcHdrInfoLen);
