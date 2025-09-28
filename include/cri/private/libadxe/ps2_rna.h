#ifndef PS2_RNA_H
#define PS2_RNA_H

#include <cri/private/libadxe/structs.h>

#include <cri/cri_xpts.h>
#include <cri/sj.h>

void PS2RNA_SetupVoice(Sint32 nste, Sint32 nmono);
void PS2RNA_Init();
void PS2RNA_Finish();
ADXRNA PS2RNA_Create(SJ* sjo, Sint32 maxnch);
void PS2RNA_Destroy(ADXRNA rna);
void PS2RNA_SetPlaySw(ADXRNA rna, Sint32 sw);
void PS2RNA_SetTransSw(ADXRNA rna, Sint32 sw);
void PS2RNA_SetDiscardSw(ADXRNA rna, Sint32 sw);
Sint32 PS2RNA_GetNumData(ADXRNA rna);
Sint32 PS2RNA_GetNumRoom(ADXRNA rna);
void PS2RNA_SetOutVol(ADXRNA rna, Sint32 vol);
void PS2RNA_SetNumChan(ADXRNA rna, Sint32 num_chan);
void PS2RNA_SetSfreq(ADXRNA rna, Sint32 sfreq);
void PS2RNA_SetOutPan(ADXRNA rna, Sint32 channel, Sint32 pan);
void PS2RNA_SetBitPerSmpl(ADXRNA rna, Sint32 bps);
void PS2RNA_ExecServer();

#endif
