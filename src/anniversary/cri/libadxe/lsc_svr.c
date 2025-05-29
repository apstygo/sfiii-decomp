#include "common.h"
#include <cri/private/libadxe/lsc_svr.h>

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc_svr", lsc_StatWait);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc_svr", lsc_StatRead);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc_svr", lsc_StatEnd);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc_svr", lsc_ExecHndl);
#else
void lsc_ExecHndl(LSC lsc) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc_svr", D_0055DA68);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc_svr", D_0055DAA8);
