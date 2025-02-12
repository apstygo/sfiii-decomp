#include "sf33rd/Source/Game/DC_Ghost.h"
#include "common.h"
#include <libvu0.h>

MTX cmtx;

void njUnitMatrix(MTX *mtx) {
    if (mtx == NULL) {
        mtx = &cmtx;
    }

    sceVu0UnitMatrix(mtx->a);
}

void njGetMatrix(MTX *m) {
    *m = cmtx;
}

void njSetMatrix(MTX *md, MTX *ms) {
    if (md == NULL) {
        md = &cmtx;
    }

    *md = *ms;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njScale);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njTranslate);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njSetBackColor);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njColorBlendingMode);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njCalcPoint);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njCalcPoints);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njRotateZ);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njDrawTexture);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njDrawSprite);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njdp2d_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njdp2d_draw);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njdp2d_sort);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njDrawPolygon2D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njSetPaletteBankNumG);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njSetPaletteMode);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njSetPaletteData);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njReLoadTexturePartNumG);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", literal_477_00504BB0);
