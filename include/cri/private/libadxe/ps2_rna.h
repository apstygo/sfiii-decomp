#ifndef PS2_RNA_H
#define PS2_RNA_H

#include <cri/private/libadxe/structs.h>

#include <cri/cri_xpts.h>
#include <cri/sj.h>

void PS2RNA_Init();
void PS2RNA_Finish();
ADXRNA PS2RNA_Create(SJ *sjo, Sint32 maxnch);
void PS2RNA_Destroy(ADXRNA rna);
void PS2RNA_SetPlaySw(ADXRNA rna, Sint32 sw);
void PS2RNA_SetTransSw(ADXRNA rna, Sint32 sw);
void PS2RNA_SetDiscardSw(ADXRNA rna, Sint32 sw);
Sint32 PS2RNA_GetNumData(ADXRNA rna);
void PS2RNA_SetOutVol(ADXRNA rna, Sint32 vol);

#endif
