#include "sf33rd/Source/Game/EffD8.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffD8", effect_D8_move);
#else
void effect_D8_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffD8", effect_D8_init);
#else
s32 effect_D8_init(s16 PL_id, s16 Type) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffD8", Setup_EffD8_Pos);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffD8", Setup_Face_Offset_X);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EffD8", D8_Priority_Data);
