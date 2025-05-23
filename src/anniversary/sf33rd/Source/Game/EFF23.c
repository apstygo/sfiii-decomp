#include "sf33rd/Source/Game/EFF23.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_289_00509750);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_290_00509758);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_291_00509760);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_292_00509768);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_293_00509770);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_294_00509778);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_295_00509780);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_296_00509788);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_297_00509790);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_298_00509798);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_299_005097A0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_300_005097A8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_301_005097B0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_302_005097B8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_303_005097C0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_304_005097C8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_305_005097E0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_306_005097F0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_307_005097F8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", literal_308_00509808);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", EFF23_Jmp_Tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", effect_23_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", EFF23_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", EFF23_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", EFF23_CHAR_CHANGE);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", EFF23_SUDDENLY);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", effect_23_init);
#else
s32 effect_23_init(s16 id, u8 dir_old, s16 sync_bg, s16 master_player, s16 letter_type, s16 cursor_index,
                   u16 char_offset, s16 pos_index, s16 type) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", Setup_23_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF23", Setup_Letter_23);
