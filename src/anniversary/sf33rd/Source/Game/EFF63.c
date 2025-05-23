#include "sf33rd/Source/Game/EFF63.h"
#include "common.h"

// Letter_Data_63
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_285_0050B798);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_286_0050B7A0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_287_0050B7A8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_288_0050B7B0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_289_0050B7B8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_290_0050B7C0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_291_0050B7C8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_292_0050B7D0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_293_0050B7D8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_294_0050B7E0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_295_0050B7E8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_296_0050B7F0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_297_0050B7F8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_298_0050B800);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_299_0050B808);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_300_0050B810);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_301_0050B818);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_302_0050B820);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_303_0050B828);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_304_0050B830);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_305_0050B838);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_306_0050B840);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_307_0050B848);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_308_0050B850);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_309_0050B858);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_310_0050B860);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", literal_311_0050B868);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", EFF63_Jmp_Tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", effect_63_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", EFF63_WAIT);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", EFF63_SLIDE_IN);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", EFF63_CHAR_CHANGE);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", EFF63_SUDDENLY);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", effect_63_init);
#else
s32 effect_63_init(u8 dir_old, s16 sync_bg, s16 master_player, s16 letter_type, s16 cursor_index) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", Disp_63_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF63", Setup_Letter_63);
