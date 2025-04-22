#ifndef ADX_STMC_H
#define ADX_STMC_H

#include "types.h"

ADXSTM ADXSTM_Create(s32, s32);
s32 ADXSTM_GetFileSct(void *);
s32 ADXSTM_GetStat(void *);
s32 ADXSTM_OpenCvfs(void *);

#endif
