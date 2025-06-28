#include "common.h"
#include <cri/private/libadxe/adx_dcd.h>
#include <cri/private/libadxe/adx_dcd3.h>

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd5", ADX_DecodeMono4);
#else
Sint32 ADX_DecodeMono4(Sint32, Sint32, Sint32, Sint16 *, Sint16, Sint16, Sint16 *, Sint16, Sint16) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd5", ADX_DecodeSte4AsMono);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd5", ADX_DecodeSte4AsSte);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd5", ADX_DecodeSte4);
#else
Sint32 ADX_DecodeSte4(Sint32, Sint32, Sint32, Sint16 *, Sint32, Sint16 *, Sint16, Sint16, Sint16 *, Sint16, Sint16) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd5", AdxQtbl);
