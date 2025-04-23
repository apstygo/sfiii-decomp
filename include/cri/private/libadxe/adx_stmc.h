#ifndef ADX_STMC_H
#define ADX_STMC_H

#include "types.h"

ADXSTM ADXSTM_Create(Sint32, Sint32);
Sint32 ADXSTM_GetFileSct(ADXSTM stm);
Sint32 ADXSTM_OpenCvfs(ADXSTM stm);
Sint32 ADXSTM_GetStat(ADXSTM stm);
Sint32 ADXSTM_ReleaseFile(ADXSTM stm);
Sint32 ADXSTM_BindFile(ADXSTM, Char8 *, void *, Sint32, Sint32);
void ADXSTM_SetSj(ADXSTM stm, SJ sj);                            
void ADXSTM_Start(ADXSTM stm);                              
void ADXSTM_Stop(ADXSTM stm); 
void ADXSTM_Destroy(ADXSTM stm);

#endif
