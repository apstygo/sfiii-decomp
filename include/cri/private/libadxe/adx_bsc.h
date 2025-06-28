#ifndef ADX_BSC_H
#define ADX_BSC_H

#include "types.h"

#include <cri/cri_xpts.h>
#include <cri/private/libadxe/structs.h>

void ADXB_Init();
ADXB ADXB_Create(Sint32 arg0, void *arg1, Sint32 arg2, Sint32 arg3);
void ADXB_Destroy(ADXB);
void ADXB_Stop(ADXB);
Sint32 ADXB_GetSfreq(ADXB adxb);
Sint32 ADXB_GetNumChan(ADXB adxb);
Sint32 ADXB_GetOutBps(ADXB adxb);
Sint32 ADXB_GetTotalNumSmpl(ADXB adxb);
Sint32 ADXB_GetAinfLen(ADXB adxb);
Sint16 ADXB_GetDefOutVol(ADXB adxb);
void *ADXB_GetPcmBuf(ADXB adxb);
void ADXB_EntryGetWrFunc(ADXB adxb, void *(*get_wr)(void *, ptrdiff_t *, Sint32 *, Sint32 *), void *object);
Sint32 ADXB_GetFormat(ADXB adxb);
Sint32 ADXB_DecodeHeader(ADXB adxb, void *header, Sint32 len);

#endif // ADX_BSC_H
