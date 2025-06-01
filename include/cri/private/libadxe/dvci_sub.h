#ifndef DVCI_SUB_H
#define DVCI_SUB_H

#include <cri/ee/cri_xpt.h>

void dvci_conv_fname(const Char8 *fname, Char8 *path);
Sint32 dvCiLoadFcache(Sint8 *, Sint8 *, Sint32, Sint32);

#endif
