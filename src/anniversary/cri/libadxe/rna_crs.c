#include "common.h"
#include <cri/private/libadxe/rna_crs.h>

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/rna_crs", RNACRS_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/rna_crs", RNACRS_Finish);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/rna_crs", RNACRS_Lock);
#else
void RNACRS_Lock() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/rna_crs", RNACRS_Unlock);
#else
void RNACRS_Unlock() {
    not_implemented(__func__);
}
#endif
