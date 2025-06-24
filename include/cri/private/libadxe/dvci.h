#ifndef DVCI_H
#define DVCI_H

#include <cri/private/libadxe/structs.h>

#include <cri/ee/cri_xpt.h>

#include <libcdvd.h>

void dvci_call_errfn(void *obj, const Char8 *msg);
Sint32 dvCiCdSearchFile(sceCdlFILE *fp, const Char8 *fname);
void dvci_to_large_to_yen(Char8 *path);
CVFSDevice *dvCiGetInterface();

#endif
