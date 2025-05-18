#ifndef ADX_XPND_H
#define ADX_XPND_H

#include <cri/private/libadxe/structs.h>

void ADXPD_Init();
void ADXPD_Finish();
ADXPD ADXPD_Create();
void ADXPD_Destroy(ADXPD);
void ADXPD_Stop(ADXPD);

#endif // ADX_XPND_H
