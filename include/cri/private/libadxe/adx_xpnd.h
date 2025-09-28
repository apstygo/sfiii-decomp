#ifndef ADX_XPND_H
#define ADX_XPND_H

#include <cri/private/libadxe/structs.h>

void ADXPD_Init();
void ADXPD_Finish();
ADXPD ADXPD_Create();
void ADXPD_Destroy(ADXPD);
void ADXPD_Stop(ADXPD);
void ADXPD_SetCoef(ADXPD, Sint32, Sint16*);
void ADXPD_SetDly(ADXPD, Sint16*, Sint16*);
void ADXPD_SetExtPrm(ADXPD, Sint16, Sint16, Sint16);
void ADXPD_Reset(ADXPD);
Sint32 ADXPD_EntrySte(ADXPD, Sint32, Sint32, Sint32, Sint32);
void ADXPD_Start(ADXPD);
void ADXPD_ExecHndl(ADXPD);
Sint32 ADXPD_GetStat(ADXPD);

#endif // ADX_XPND_H
