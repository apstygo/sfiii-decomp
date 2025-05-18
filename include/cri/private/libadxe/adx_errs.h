#ifndef ADX_ERRS_H
#define ADX_ERRS_H

#include "types.h"

void ADXERR_Init();
void ADXERR_Finish();
void ADXERR_CallErrFunc1(s8 *);
void ADXERR_CallErrFunc2(s8 *, s8 *);
void ADXERR_ItoA2(s32, s32, s8 *, s32);

#endif // ADX_ERRS_H
