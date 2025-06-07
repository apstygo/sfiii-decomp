#include "common.h"
#include <cri/private/libadxe/htci_sub.h>

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htci_is_inc_colon);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htci_is_bgn_host);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htci_conv_fname);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", conv_cmp_003DE220);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htci_charicmp);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htci_stricmp);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", analysis_flist_003DE328);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htci_load_flist);
#else
Sint32 htci_load_flist(Char8 *flist, Sint8 *buf) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", open_file_all);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", close_file_all);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", get_fstate);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htci_init_flist);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htci_get_finf);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htCiLoadFcache);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htCiIsExistFcache);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htCiSetOpenMode);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htCiSetRootDir);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htCiGetRootDir);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htCiSetAccessName);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htCiGetAccessName);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htci_get_opmode);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htCiSetOutputDebugLevel);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", htCiGetOutputDebugLevel);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", D_0055D758);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", D_0055D760);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", D_0055D768);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", D_0055D790);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", D_0055D7B0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", D_0055D7C8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", D_0055D7F8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", D_0055D820);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", D_0055D840);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", D_0055D858);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", D_0055D888);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", D_0055D8B8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", D_0055D8E0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/htci_sub", D_0055D910);
