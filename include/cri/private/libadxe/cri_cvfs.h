#ifndef CRI_CVFS_H
#define CRI_CVFS_H

#include <cri/private/libadxe/structs.h>

#include <cri/cri_xpts.h>

void *cvFsOpen(const Char8 *fname, void *arg1, Sint32 arg2);
void cvFsClose(Sint32);
void cvFsSeek(Sint32, Sint32, Sint32);
Sint32 cvFsTell(Sint32);
Sint32 cvFsGetStat(Sint32);
Sint32 cvFsReqRd(Sint32, Sint32, Sint32);
void cvFsExecServer();
void cvFsAddDev(const Char8 *device_name, CVFSDevice *(*device_provider)(), Sint32 arg2);
void cvFsEntryErrFunc(void (*function)(void *, const Char8 *), void *object);
void cvFsSetDefDev(const Char8 *device_name);

#endif
