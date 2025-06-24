#ifndef ADX_BAIF_H
#define ADX_BAIF_H

#include <cri/private/libadxe/structs.h>

#include <cri/ee/cri_xpt.h>

Sint32 ADXB_CheckAiff(void *);
Sint32 ADXB_DecodeHeaderAiff(ADXB, void *, Sint32);
void ADXB_ExecOneAiff(ADXB adxb);

#endif
