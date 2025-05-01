#ifndef ADX_SJD_H
#define ADX_SJD_H

#include <cri/cri_adxt.h>
#include <cri/cri_xpts.h>
#include <cri/sj.h>

ADXSJD ADXSJD_Create(SJ, Sint32, SJ *);
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

#endif
