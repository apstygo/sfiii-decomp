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

void njScale(MTX *mtx, f32 x, f32 y, f32 z) {
    f32 v0[4];

    v0[0] = x;
    v0[1] = y;
    v0[2] = z;
    v0[3] = 1.0f;

    if (mtx == NULL) {
        mtx = &cmtx;
    }

    __asm__ __volatile__("lqc2       vf8,  0x0(%0) \n"
                         "lqc2       $vf4, 0x0(%1) \n"
                         "lqc2       $vf5, 0x10(%1) \n"
                         "lqc2       $vf6, 0x20(%1) \n"
                         "lqc2       $vf7, 0x30(%1) \n"
                         "vmulx.xyzw $vf4, $vf4, $vf8x \n"
                         "vmuly.xyzw $vf5, $vf5, $vf8y \n"
                         "vmulz.xyzw $vf6, $vf6, $vf8z \n"
                         "sqc2       $vf4, 0x0(%1) \n"
                         "sqc2       $vf5, 0x10(%1) \n"
                         "sqc2       $vf6, 0x20(%1) \n"
                         "sqc2       $vf7, 0x30(%1) \n"
                         :
                         : "r"(v0), "r"(mtx)
                         : "memory");
}

void njTranslate(MTX *mtx, f32 x, f32 y, f32 z) {
    if (mtx == NULL) {
        mtx = &cmtx;
    }

    __asm__ __volatile__("mfc1       $t0, %1 \n"
                         "mfc1       $t1, %3 \n"
                         "pextlw     $t0, $t1, $t0 \n"

                         "mfc1       $t1, %2 \n"
                         "pextlw     $t0, $t1, $t0 \n"

                         "qmtc2      $t0, $vf8 \n"
                         "vmove.w    $vf8, $vf0 \n"

                         "lqc2       $vf4, 0x0(%0) \n"
                         "lqc2       $vf5, 0x10(%0) \n"
                         "lqc2       $vf6, 0x20(%0) \n"
                         "lqc2       $vf7, 0x30(%0) \n"
                         "vmulax.xyzw $ACC, $vf4, $vf8x \n"
                         "vmadday.xyzw $ACC, $vf5, $vf8y \n"
                         "vmaddaz.xyzw $ACC, $vf6, $vf8z \n"
                         "vmaddw.xyzw $vf9, $vf7, $vf8w \n"
                         "sqc2       $vf9, 0x30(%0) \n"
                         :
                         : "r"(mtx), "f"(x), "f"(y), "f"(z)
                         : "t0", "t1", "memory");
}

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
