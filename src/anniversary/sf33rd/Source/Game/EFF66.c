#include "sf33rd/Source/Game/EFF66.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF66", Flash_Data_66);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF66", EFF66_Half_OBJ_Data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF66", EFF66_Jmp_Tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF66", effect_66_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF66", EFF66_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF66", EFF66_SUSPEND);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF66", EFF66_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF66", EFF66_BOWAN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF66", EFF66_FLASH);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF66", EFF66_SUDDENLY);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF66", Setup_Pos_66);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF66", effect_66_init);
#else
s32 effect_66_init(s16 order_index, s16 id, s16 master_player, s16 target_bg, s16 char_ix, s16 char_ix2, s16 option) {
    not_implemented(__func__);
}
#endif
