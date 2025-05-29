#include "common.h"
#include <cri/private/libadxe/dvci_sub.h>

// Also used in dvCiSetRootDir
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", D_0055D280);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", D_0055D288);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", dvci_conv_fname);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", conv_cmp_003DC578);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", dvci_charicmp);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", dvci_stricmp);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", analysis_flist_003DC6A0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", D_0055D290);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", load_flist);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", D_0055D298);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", D_0055D2B0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", D_0055D2C8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", D_0055D2E0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", search_fstate);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", get_fp_from_fname);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", dvci_init_flist);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", D_0055D310);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", D_0055D318);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", dvci_get_fstate);

#if defined(TARGET_PS2)
// Also used in dvCiSetFcache
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", D_0055D340);
// Also used in dvCiSetFcache
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", D_0055D370);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", D_0055D3A0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", D_0055D3C8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", dvCiLoadFcache);
#else
Sint32 dvCiLoadFcache(Sint8 *, Sint8 *, Sint32, Sint32) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", dvCiSetFcache);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", dvCiIsExistFcache);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", dvCiSetRdMode);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", dvCiSetRootDir);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", dvCiGetRootDir);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci_sub", dvCiSetSeekPos);
