#include "sf33rd/Source/Game/EFF04.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF04", EFF04_Cursor_Data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF04", effect_04_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF04", effect_04_init);
#else
s32 effect_04_init(s16 Death_Type, s16 cg_type, s16 sync_bg, s16 priority) {
    not_implemented(__func__);
}
#endif
