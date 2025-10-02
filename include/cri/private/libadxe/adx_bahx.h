#ifndef ADX_BAHX_H
#define ADX_BAHX_H

#include <cri/private/libadxe/structs.h>

#include <cri/sj.h>

void ADXB_SetAc3InSj(ADXB adxb, SJ sj);
void ADXB_SetAhxInSj(ADXB adxb, SJ sj);
Sint32 ADXB_CheckAc3(void*);
Sint32 ADXB_DecodeHeaderAc3(ADXB, void*, Sint32);
void ADXB_ExecOneAc3(ADXB adxb);
void ADXB_ExecOneAhx(ADXB adxb);
void ADXB_SetAc3DecSmpl(ADXB adxb, Sint32 samples);
void ADXB_SetAhxDecSmpl(ADXB adxb, Sint32 samples);
void ADXB_Ac3TermSupply(ADXB adxb);
void ADXB_AhxTermSupply(ADXB adxb);

#endif
