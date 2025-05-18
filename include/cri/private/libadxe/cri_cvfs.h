#ifndef CRI_CVFS_H
#define CRI_CVFS_H

#include <cri/cri_xpts.h>

void *cvFsOpen(const Char8 *fname, void *arg1, Sint32 arg2);
void cvFsClose(Sint32);
void cvFsSeek(Sint32, Sint32, Sint32);
Sint32 cvFsTell(Sint32);
Sint32 cvFsGetStat(Sint32);
Sint32 cvFsReqRd(Sint32, Sint32, Sint32);
void cvFsExecServer();

#endif
