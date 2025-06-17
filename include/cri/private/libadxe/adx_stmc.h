#ifndef ADX_STMC_H
#define ADX_STMC_H

#include <cri/private/libadxe/structs.h>

#include <cri/cri_xpts.h>
#include <cri/sj.h>

Sint32 ADXSTM_Init();
void ADXSTM_Finish();
ADXSTM ADXSTM_Create(SJ, Sint32);
Sint32 ADXSTM_GetFileSct(ADXSTM stm);
void ADXSTM_OpenCvfs(ADXSTM stm);
Sint32 ADXSTM_GetStat(ADXSTM stm);
void ADXSTM_BindFile(ADXSTM stm, const Char8 *fname, void *dir, Sint32 arg3, Sint32 arg4);
void ADXSTM_ReleaseFile(ADXSTM stm);
void ADXSTM_SetSj(ADXSTM stm, SJ sj);
Sint32 ADXSTM_Start(ADXSTM stm);
void ADXSTM_Stop(ADXSTM stm);
void ADXSTM_StopNw(ADXSTM stm);
void ADXSTM_Destroy(ADXSTM stm);
void ADXSTM_ExecServer();
void ADXSTM_SetEos(ADXSTM stm, Sint32 eos);
Sint32 ADXSTM_SetReqRdSize(ADXSTM stm, Sint32 size);
void ADXSTM_SetPause(ADXSTM stm, Sint8 sw);
Sint32 ADXSTM_Seek(ADXSTM stm, Sint32 offset);
Sint32 ADXSTM_Start2(ADXSTM stm, Sint32 arg1);
Sint32 ADXSTM_Tell(ADXSTM stm);
void ADXSTM_EntryEosFunc(ADXSTM stm, void (*func)(void *), void *context);
void ADXSTM_ReleaseFileNw(ADXSTM stm);
Sint32 ADXSTM_GetFileLen(ADXSTM stm);
Sint32 ADXSTM_SetBufSize(ADXSTM stm, Sint32 arg1, Sint32 arg2);
void ADXSTM_BindFileNw(ADXSTM stm, const Char8 *fname, void *dir, Sint32 arg3, Sint32 file_sct);

#endif
