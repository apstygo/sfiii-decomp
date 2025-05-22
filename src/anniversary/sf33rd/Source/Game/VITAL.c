#include "sf33rd/Source/Game/VITAL.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/VITAL", vital_cont_init);
#else
void vital_cont_init() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/VITAL", vital_cont_main);
#else
void vital_cont_main() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/VITAL", vital_control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/VITAL", vital_parts_allwrite);
