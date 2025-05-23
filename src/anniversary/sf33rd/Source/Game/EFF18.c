#include "sf33rd/Source/Game/EFF18.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF18", effect_18_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF18", effect_18_init);
#else
s32 effect_18_init(s32 disp_index, s32 cursor_id, s16 sync_bg, s16 master_player) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF18", Setup_Pos_18);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF18", Check_TenTen);
