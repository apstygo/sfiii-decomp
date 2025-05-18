#ifndef LSC_H
#define LSC_H

#include <cri/private/libadxe/adx_stmc.h>
#include <cri/sj.h>

typedef void *ADXLSC;

ADXLSC LSC_Create(SJ);
void LSC_Destroy(ADXLSC);
void LSC_Stop(ADXLSC);
void LSC_SetStmHndl(void *, ADXSTM);
void LSC_ExecServer();

#endif
