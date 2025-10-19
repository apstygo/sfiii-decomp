#ifndef ADX_SJD_H
#define ADX_SJD_H

#include <cri/cri_xpts.h>
#include <cri/private/libadxe/structs.h>
#include <cri/sj.h>

#define ADXSJD_MAX_OBJ 16

void ADXSJD_Init();
void ADXSJD_Finish();
ADXSJD ADXSJD_Create(SJ, Sint32, SJ*);
void ADXSJD_Destroy(ADXSJD sjd);
void ADXSJD_Start(ADXSJD);
void ADXSJD_Stop(ADXSJD);
Sint32 ADXSJD_GetDecNumSmpl(ADXSJD);
Sint32 ADXSJD_GetOutBps(ADXSJD);
Sint32 ADXSJD_GetSfreq(ADXSJD);
Sint32 ADXSJD_GetTotalNumSmpl(ADXSJD);
Sint32 ADXSJD_GetDefOutVol(ADXSJD);
void ADXSJD_SetLnkSw(ADXSJD sjd, Sint32 sw);
void ADXSJD_SetInSj(ADXSJD sjd, SJ sj);
void ADXSJD_ExecServer();
void ADXSJD_EntryTrapFunc(ADXSJD sjd, void (*func)(void*), void* obj);
Sint32 ADXSJD_GetBlkSmpl(ADXSJD sjd);
Sint32 ADXSJD_GetFormat(ADXSJD sjd);
Sint32 ADXSJD_GetNumChan(ADXSJD sjd);
Sint32 ADXSJD_GetNumLoop(ADXSJD sjd);
Sint8 ADXSJD_GetStat(ADXSJD sjd);
void ADXSJD_SetMaxDecSmpl(ADXSJD sjd, Sint32 max_samples);
void ADXSJD_SetTrapCnt(ADXSJD sjd, Sint32 cnt);
void ADXSJD_SetTrapDtLen(ADXSJD sjd, Sint32 dt_len);
void ADXSJD_SetTrapNumSmpl(ADXSJD sjd, Sint32 samples);
Sint32 ADXSJD_GetLpEndOfst(ADXSJD sjd);
Sint32 ADXSJD_GetLpStartPos(ADXSJD sjd);
Sint32 ADXSJD_GetLpEndPos(ADXSJD sjd);
Sint32 ADXSJD_GetSpsdInfo(ADXSJD sjd); // Might be returning a pointer
void ADXSJD_TermSupply(ADXSJD sjd);
Sint16 ADXSJD_GetDefPan(ADXSJD sjd, Sint32 arg1);
void ADXSJD_RestoreSnapshot(ADXSJD sjd);

#endif
