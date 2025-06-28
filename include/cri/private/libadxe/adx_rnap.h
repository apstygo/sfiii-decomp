#ifndef ADX_RNAP_H
#define ADX_RNAP_H

#include <cri/cri_adxt.h>
#include <cri/cri_xpts.h>
#include <cri/sj.h>

void ADXRNA_Init();
void ADXRNA_Finish();
ADXRNA ADXRNA_Create(SJ *, Sint32);
void ADXRNA_Destroy(ADXRNA rna);
void ADXRNA_EntryErrFunc(void (*)(void *, Char8 *), void *);
Sint32 ADXRNA_GetNumData(ADXRNA);
void ADXRNA_SetOutVol(ADXRNA, Sint32);
void ADXRNA_SetPlaySw(ADXRNA, Sint32);
void ADXRNA_SetTransSw(ADXRNA rna, Sint32 sw);
void ADXRNA_ExecServer();

#endif
