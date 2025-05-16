#ifndef ADX_STMC_H
#define ADX_STMC_H

#include <cri/private/libadxe/structs.h>

#include <cri/cri_xpts.h>
#include <cri/sj.h>

ADXSTM ADXSTM_Create(SJ, Sint32);
Sint32 ADXSTM_GetFileSct(ADXSTM stm);
void ADXSTM_OpenCvfs(ADXSTM stm);
Sint32 ADXSTM_GetStat(ADXSTM stm);
void ADXSTM_BindFile(ADXSTM stm, const Char8 *fname, void *dir, Sint32 arg3, Sint32 arg4);
void ADXSTM_ReleaseFile(ADXSTM stm);
void ADXSTM_SetSj(ADXSTM stm, SJ sj);
Sint32 ADXSTM_Start(ADXSTM stm);
void ADXSTM_Stop(ADXSTM stm);
void ADXSTM_Destroy(ADXSTM stm);

#endif
