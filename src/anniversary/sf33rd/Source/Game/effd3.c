#include "sf33rd/Source/Game/effd3.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effd3", effect_D3_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effd3", akebono_finish);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effd3", syungoku_finish);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effd3", effect_D3_init);
#else
s32 effect_D3_init(u8 ake_type) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/effd3", ake_timer_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/effd3", ake_color);
