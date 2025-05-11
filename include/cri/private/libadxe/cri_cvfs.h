#ifndef CRI_CVFS_H
#define CRI_CVFS_H

#include <cri/cri_xpts.h>

Sint32 cvFsOpen(Char8 *, void *, Sint32);
void cvFsClose(Sint32);
void cvFsSeek(Sint32, Sint32, Sint32);
Sint32 cvFsTell(Sint32);
Sint32 cvFsGetStat(Sint32);
Sint32 cvFsReqRd(Sint32, Sint32, Sint32);

#endif
