#include "sf33rd/Source/Game/EFF10.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", Contents_Check_Data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_216_00507158);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_217_00507168);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_218_00507178);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_219_00507180);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_220_00507190);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_221_005071A0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_222_005071B8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_223_005071C8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_224_005071D0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_225_005071D8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_226_005071E0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_227_005071E8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_228_005071F0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_229_005071F8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_230_00507200);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_231_00507208);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_232_00507210);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_233_00507218);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_234_00507220);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_235_00507228);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_236_00507230);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_237_00507238);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_238_00507248);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_239_00507260);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_240_00507270);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_241_00507278);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_242_00507280);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_243_00507288);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_244_00507290);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_245_00507298);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_246_005072A0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_247_005072A8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_248_005072B0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_249_005072C0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", literal_250_005072D0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", effect_10_move);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/EFF10", effect_10_init);
#else
s32 effect_10_init(s16 id, u8 Type, u8 Type_in_Type, u8 dir_step, u8 Death_Type, s16 pos_x, s16 pos_y) {
    not_implemented(__func__);
}
#endif
