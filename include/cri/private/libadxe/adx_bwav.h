#ifndef ADX_BWAV_H
#define ADX_BWAV_H

#include <cri/private/libadxe/structs.h>

#include <cri/ee/cri_xpt.h>

Sint32 ADXB_CheckWav(void *);
Sint32 ADXB_DecodeHeaderWav(ADXB, void *, Sint32);
void ADXB_ExecOneWav(ADXB adxb);

#endif
