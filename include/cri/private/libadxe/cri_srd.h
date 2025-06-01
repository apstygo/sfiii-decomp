#ifndef CRI_SRD_H
#define CRI_SRD_H

#include <cri/private/libadxe/structs.h>

#include <cri/ee/cri_xpt.h>

void SRD_Destroy(SRD srd);
Sint32 SRD_GetStat(SRD srd);
void SRD_ExecServer();
void SRD_SetHistory(Sint32 arg0);

#endif
