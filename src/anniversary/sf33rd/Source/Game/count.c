#include "sf33rd/Source/Game/count.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/count", count_cont_init);
#else
void count_cont_init(u8 type) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/count", count_cont_main);
#else
void count_cont_main() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/count", counter_control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/count", counter_write);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/count", bcounter_write);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/count", counter_flash);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/count", bcount_cont_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/count", bcount_cont_main);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/count", bcounter_control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/count", bcounter_down);
