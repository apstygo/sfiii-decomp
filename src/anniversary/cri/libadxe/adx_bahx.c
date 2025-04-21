#include "common.h"
#include <cri/private/libadxe/adx_bsc.h>

void (*ac3setsjifunc)(s32) = NULL;
s32 ac3termsupplyfunc = 0;
s32 ac3execfunc = 0;
s32 padding = 0; // This padding was added manually
void (*ahxsetsjifunc)() = NULL;
s32 ahxsetdecsmplfunc = 0;
s32 ahxtermsupplyfunc = 0;
s32 ahxexecfunc = 0;

void ADXB_SetAc3InSj(ADXB adxb) {
    s32 unkBC = adxb->unkBC;

    if (unkBC != 0) {
        ac3setsjifunc(unkBC);
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_SetAc3DecSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_Ac3TermSupply);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_ExecOneAc3);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_DecodeHeaderAc3);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_CheckAc3);

void ADXB_SetAhxInSj(ADXB adxb) {
    s32 unkB0 = adxb->unkB0;

    if (unkB0 != 0) {
        ahxsetsjifunc(unkB0);
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_SetAhxDecSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_ExecOneAhx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_AhxTermSupply);
