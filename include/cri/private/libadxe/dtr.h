#ifndef DTR_H
#define DTR_H

#include <cri/private/libadxe/structs.h>

#include <cri/cri_xpts.h>
#include <cri/sj.h>

DTR DTR_Create(SJ sj, Sint32 arg1);
void DTR_Destroy(DTR dtr);
void DTR_Start(DTR dtr);
void DTR_Stop(DTR dtr);
Sint32 DTR_GetStat(DTR dtr);
void DTR_ExecServer();

#endif
