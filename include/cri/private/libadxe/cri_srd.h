#ifndef CRI_SRD_H
#define CRI_SRD_H

#include <cri/private/libadxe/structs.h>

#include <cri/ee/cri_xpt.h>

#include <libcdvd.h>

SRD SRD_Create();
void SRD_Destroy(SRD srd);
Sint32 SRD_GetStat(SRD srd);
void SRD_ExecServer();
void SRD_WaitForExecServer();
void SRD_WaitComplete(SRD srd);
void SRD_SetHistory(Sint32 arg0);
void SRD_Break(SRD srd);
Sint32 SRD_ReqRdDvd(SRD srd, Sint32, Sint32, void *, sceCdRMode *);

#endif
