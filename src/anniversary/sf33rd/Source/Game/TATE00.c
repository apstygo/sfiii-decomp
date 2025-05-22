#include "sf33rd/Source/Game/TATE00.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/TATE00", TATE00);
#else
void TATE00() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/TATE00", ta0_init00);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/TATE00", ta0_init01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/TATE00", ta0_init02);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/TATE00", ta0_move);
