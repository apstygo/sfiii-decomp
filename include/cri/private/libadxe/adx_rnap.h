#ifndef ADX_RNAP_H
#define ADX_RNAP_H

#include <cri/cri_adxt.h>
#include <cri/cri_xpts.h>
#include <cri/sj.h>

ADXRNA ADXRNA_Create(SJ *, Sint32);
void ADXRNA_EntryErrFunc(void (*)(void *, Char8 *), void *);
Sint32 ADXRNA_GetNumData(ADXRNA);
void ADXRNA_SetOutVol(ADXRNA, Sint32);
void ADXRNA_SetPlaySw(ADXRNA, Sint32);

#endif
