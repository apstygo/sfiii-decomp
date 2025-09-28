#ifndef LSC_H
#define LSC_H

#include <cri/private/libadxe/structs.h>

#include <cri/private/libadxe/adx_stmc.h>
#include <cri/sj.h>

LSC LSC_Create(SJ sj);
void LSC_Destroy(LSC lsc);
Sint32 LSC_EntryFileRange(LSC lsc, const Char8* fname, void* dir, Sint32 ofst, Sint32 fnsct);
void LSC_Stop(LSC lsc);
void LSC_SetStmHndl(LSC lsc, ADXSTM);
void LSC_ExecServer();
Sint32 LSC_EntryFname(LSC lsc);

#endif
