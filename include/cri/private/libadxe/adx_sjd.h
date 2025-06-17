#ifndef ADX_SJD_H
#define ADX_SJD_H

#include <cri/cri_xpts.h>
#include <cri/private/libadxe/structs.h>
#include <cri/sj.h>

#define ADXSJD_MAX_OBJ 16

void ADXSJD_Init();
void ADXSJD_Finish();
ADXSJD ADXSJD_Create(SJ, Sint32, SJ *);
void ADXSJD_Destroy(ADXSJD sjd);
void ADXSJD_Start(ADXSJD);
void ADXSJD_Stop(ADXSJD);
Sint32 ADXSJD_GetDecNumSmpl(ADXSJD);
Sint32 ADXSJD_GetOutBps(ADXSJD);
Sint32 ADXSJD_GetSfreq(ADXSJD);
Sint32 ADXSJD_GetTotalNumSmpl(ADXSJD);
Sint32 ADXSJD_GetOutBps(ADXSJD);
Sint32 ADXSJD_GetSfreq(ADXSJD);
Sint32 ADXSJD_GetTotalNumSmpl(ADXSJD);
Sint32 ADXSJD_GetDefOutVol(ADXSJD);
void ADXSJD_SetLnkSw(ADXSJD sjd, Sint32 sw);
void ADXSJD_SetInSj(ADXSJD sjd, SJ sj);
void ADXSJD_ExecServer();

#endif
