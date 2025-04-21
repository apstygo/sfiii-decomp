#ifndef ADX_XPND_H
#define ADX_XPND_H

typedef struct {
    char pad0[0x3C];
} ADXPD_OBJ;

typedef ADXPD_OBJ *ADXPD;

ADXPD ADXPD_Create();
void ADXPD_Destroy(ADXPD);
void ADXPD_Stop(ADXPD);

#endif // ADX_XPND_H
