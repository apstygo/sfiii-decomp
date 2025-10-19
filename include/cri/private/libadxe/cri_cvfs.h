#ifndef CRI_CVFS_H
#define CRI_CVFS_H

#include <cri/private/libadxe/structs.h>

#include <cri/cri_xpts.h>

void* cvFsOpen(const Char8* fname, void* arg1, Sint32 arg2);
void cvFsClose(CVFSHandle*);
Sint32 cvFsSeek(CVFSHandle*, Sint32, Sint32);
Sint32 cvFsTell(CVFSHandle*);
Sint32 cvFsGetStat(CVFSHandle*);
Sint32 cvFsReqRd(CVFSHandle*, Sint32, void*);
void cvFsExecServer();
void cvFsAddDev(const Char8* device_name, CVFSDevice* (*device_provider)(), Sint32 arg2);
void cvFsEntryErrFunc(void (*function)(void*, const Char8*), void* object);
void cvFsSetDefDev(const Char8* device_name);

#endif
