#ifndef ADX_AMP_H
#define ADX_AMP_H

#include <cri/cri_xpts.h>
#include <cri/private/libadxe/structs.h>

void ADXAMP_Start(ADXAMP);
void ADXAMP_Destroy(ADXAMP amp);
void ADXAMP_Stop(ADXAMP amp);
void ADXAMP_SetSfreq(ADXAMP amp, Sint32 sfreq);

#endif // ADX_AMP_H
