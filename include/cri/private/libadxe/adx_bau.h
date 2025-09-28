#ifndef ADX_BAU_H
#define ADX_BAU_H

#include <cri/private/libadxe/structs.h>

#include <cri/ee/cri_xpt.h>

Sint32 ADXB_CheckAu(void*);
Sint32 ADXB_DecodeHeaderAu(ADXB, void*, Sint32);
void ADXB_ExecOneAu(ADXB adxb);

#endif
