#include "sf33rd/Source/Game/efff5.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff5", effect_F5_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff5", efff5_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff5", efff5_1000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff5", efff5_2000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff5", efff5_3000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff5", efff5_4000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff5", efff5_5000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff5", efff5_6000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff5", efff5_7000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff5", efff5_8000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff5", efff5_9000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff5", efff5_A000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff5", efff5_B000);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/efff5", effect_F5_init);
#else
s32 effect_F5_init(s16 /* unused */) {
    not_implemented(__func__);
}
#endif
