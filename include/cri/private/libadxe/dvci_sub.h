#ifndef DVCI_SUB_H
#define DVCI_SUB_H

#include <cri/ee/cri_xpt.h>

#include <libcdvd.h>

extern Sint32 dvg_ci_dbg_out_lv;
extern sceCdRMode dvg_ci_cdrmode;
extern Sint32 dvg_ci_rdmode;

void dvCiSetRootDir(const Char8 *dir);
void dvci_conv_fname(const Char8 *fname, Char8 *path);
Sint32 dvci_get_fstate(const Char8 *fname, sceCdlFILE *fp);
Sint32 dvCiLoadFcache(Sint8 *, Sint8 *, Sint32, Sint32);

#endif
