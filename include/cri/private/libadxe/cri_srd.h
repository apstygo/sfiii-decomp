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
Sint32 SRD_ReqRdDvd(SRD srd, Sint32, Sint32, void*, sceCdRMode*);
Sint32 SRD_SceOpen(const Char8* filename, Sint32 flag);
Sint32 SRD_SceClose(Sint32 fd);
Sint64 SRD_SceLseek(Sint32 fd, Sint64 offset, Sint32 whence);
Sint32 SRD_SceRead(Sint32 fd, void* buf, Sint32 nbyte);

#endif
