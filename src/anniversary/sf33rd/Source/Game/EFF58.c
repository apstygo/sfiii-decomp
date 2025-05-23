#include "sf33rd/Source/Game/EFF58.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF58", effect_58_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF58", effect_58_init);
#else
s32 effect_58_init(s16 id, s16 time0, s16 option) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF58", SF33rd_Logo);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF58", EFF58_Type_01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF58", Fade_In_58_Sub);
