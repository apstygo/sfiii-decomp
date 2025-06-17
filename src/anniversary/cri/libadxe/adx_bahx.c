#include "common.h"
#include <cri/private/libadxe/adx_bsc.h>

#include <cri/sj.h>

void (*ac3setsjifunc)(Sint32, SJ) = NULL;
void (*ac3termsupplyfunc)(Sint32) = NULL;
Sint32 ac3execfunc = 0;
Sint32 padding = 0; // This padding was added manually
void (*ahxsetsjifunc)(Sint32, SJ) = NULL;
void (*ahxsetdecsmplfunc)(Sint32, Sint32) = NULL;
void (*ahxtermsupplyfunc)(Sint32) = NULL;
Sint32 ahxexecfunc = 0;

void ADXB_SetAc3InSj(ADXB adxb, SJ sj) {
    Sint32 unkBC = adxb->unkBC;

    if (unkBC != 0) {
        ac3setsjifunc(unkBC, sj);
    }
}

void ADXB_SetAc3DecSmpl(ADXB adxb, Sint32 arg1) {
    adxb->unkC0 = arg1;
    adxb->unkC4 = arg1 / 1536;
}

void ADXB_Ac3TermSupply(ADXB adxb) {
    if (adxb->unkBC != 0) {
        ac3termsupplyfunc(adxb->unkBC);
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_ExecOneAc3);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_DecodeHeaderAc3);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_CheckAc3);

void ADXB_SetAhxInSj(ADXB adxb, SJ sj) {
    if (adxb->unkB0 != 0) {
        ahxsetsjifunc(adxb->unkB0, sj);
    }
}

void ADXB_SetAhxDecSmpl(ADXB adxb, Sint32 arg1) {
    if (adxb->unkB0 != 0) {
        ahxsetdecsmplfunc(adxb->unkB0, arg1);
    }

    adxb->unkB4 = arg1;
    adxb->unkB8 = arg1 / 96;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_bahx", ADXB_ExecOneAhx);

void ADXB_AhxTermSupply(ADXB adxb) {
    if (adxb->unkB0 != 0) {
        ahxtermsupplyfunc(adxb->unkB0);
    }
}
