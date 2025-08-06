#include "sf33rd/Source/Game/Eff99.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", effect_99_move);
#else
void effect_99_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", effect_99_init);
#else
s32 effect_99_init(s16 id, s16 type, s16 char_offset, s16 letter_index, s16 pos_index, s16 master_player) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", Setup_Letter_99);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", Pos_Data_99);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_241_0050C210);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_242_0050C220);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_243_0050C230);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_244_0050C240);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_245_0050C250);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_246_0050C260);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_247_0050C270);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_248_0050C280);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_249_0050C290);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_250_0050C2A0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_251_0050C2B0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_252_0050C2C0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_253_0050C2D0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_254_0050C2E0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_255_0050C2F0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_256_0050C300);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_257_0050C308);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_258_0050C310);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_259_0050C318);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_260_0050C328);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_261_0050C330);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_262_0050C338);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_263_0050C340);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_264_0050C348);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_265_0050C350);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_266_0050C358);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_267_0050C360);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_268_0050C368);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_269_0050C370);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_270_0050C378);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_271_0050C388);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_272_0050C3A0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_273_0050C3C0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_274_0050C3D8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_275_0050C3E8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_276_0050C3F0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_277_0050C400);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_278_0050C410);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_279_0050C418);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_280_0050C428);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_281_0050C438);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_282_0050C450);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_283_0050C470);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_284_0050C488);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_285_0050C498);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_286_0050C4A8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_287_0050C4B8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_288_0050C4C8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_289_0050C4D8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_290_0050C4E8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_291_0050C4F8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_292_0050C508);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_293_0050C518);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_294_0050C528);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_295_0050C538);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_296_0050C548);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_297_0050C558);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_298_0050C568);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_299_0050C578);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_300_0050C588);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_301_0050C598);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Eff99", literal_302_0050C5A8);
