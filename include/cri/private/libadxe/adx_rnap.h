#ifndef ADX_RNAP_H
#define ADX_RNAP_H

#include <cri/cri_adxt.h>
#include <cri/cri_xpts.h>
#include <cri/sj.h>

void ADXRNA_Init();
void ADXRNA_Finish();
ADXRNA ADXRNA_Create(SJ*, Sint32);
void ADXRNA_Destroy(ADXRNA rna);
void ADXRNA_EntryErrFunc(void (*)(void*, Char8*), void*);
Sint32 ADXRNA_GetNumData(ADXRNA);
void ADXRNA_SetOutVol(ADXRNA, Sint32);
void ADXRNA_SetPlaySw(ADXRNA, Sint32);
void ADXRNA_SetTransSw(ADXRNA rna, Sint32 sw);
void ADXRNA_ExecServer();
void ADXRNA_SetBitPerSmpl(ADXRNA rna, Sint32 bps);
void ADXRNA_SetNumChan(ADXRNA rna, Sint32 num_chan);
void ADXRNA_SetSfreq(ADXRNA rna, Sint32 sfreq);
void ADXRNA_SetStmHdInfo(ADXRNA rna, Sint32); // Might be setting a pointer
void ADXRNA_SetTotalNumSmpl(ADXRNA rna, Sint32 samples);
void ADXRNA_SetOutPan(ADXRNA rna, Sint32 channel, Sint32 pan);
Sint32 ADXRNA_GetNumRoom(ADXRNA rna);

#endif
