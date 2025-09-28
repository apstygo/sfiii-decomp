#ifndef ADX_BSPS_H
#define ADX_BSPS_H

#include <cri/private/libadxe/structs.h>

#include <cri/ee/cri_xpt.h>

Sint32 ADXB_CheckSpsd(void*);
Sint32 ADXB_DecodeHeaderSpsd(ADXB, void*, Sint32);
void ADXB_ExecOneSpsd(ADXB adxb);

#endif
