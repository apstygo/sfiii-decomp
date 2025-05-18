#ifndef ADX_BSC_H
#define ADX_BSC_H

#include <cri/cri_xpts.h>
#include <cri/private/libadxe/structs.h>

void ADXB_Init();
ADXB ADXB_Create(Sint32 arg0, Sint32 arg1, Sint32 arg2, Sint32 arg3);
void ADXB_Destroy(ADXB);
void ADXB_Stop(ADXB);
Sint32 ADXB_GetSfreq(ADXB adxb);
Sint32 ADXB_GetNumChan(ADXB adxb);
Sint32 ADXB_GetOutBps(ADXB adxb);
Sint32 ADXB_GetTotalNumSmpl(ADXB adxb);
Sint32 ADXB_GetAinfLen(ADXB adxb);
Sint16 ADXB_GetDefOutVol(ADXB adxb);
Sint32 ADXB_GetPcmBuf(ADXB adxb); // Returns a void*?
void ADXB_EntryGetWrFunc(ADXB adxb, Sint32 (*get_wr)(void *, Sint32 *, Sint32 *, Sint32 *), void *object);

#endif // ADX_BSC_H
