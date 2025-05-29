#include "sf33rd/Source/PS2/reboot.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/reboot", Reboot_Program);
#else
void Reboot_Program(s8 *args) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/reboot", literal_186_00561958);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/reboot", literal_187_00561968);
