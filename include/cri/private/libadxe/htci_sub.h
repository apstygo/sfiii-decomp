#ifndef HTCI_SUB_H
#define HTCI_SUB_H

#include <cri/ee/cri_xpt.h>

Sint32 htci_load_flist(const Char8* flist, Sint8* buf);
int htCiLoadFcache();
int htCiSetOpenMode(int mode);
int htCiSetRootDir(char* root);

#endif
