#include "sf33rd/Source/Game/DC_Ghost.h"
#include "common.h"
#include <libvu0.h>

#define NTH_BYTE(value, n) ((((value >> n * 8) & 0xFF) << n * 8))

typedef struct {
    Vertex v;
    u32 col;
} _Polygon;

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

void njSetBackColor(u32 c0, u32 c1, u32 c2) {
    c0 = c0 | c1 | c2;
    flSetRenderState(FLRENDER_BACKCOLOR, NTH_BYTE(c0, 3) | NTH_BYTE(c0, 2) | NTH_BYTE(c0, 1) | NTH_BYTE(c0, 0));
}

void njColorBlendingMode(s32 target, s32 mode) {
    target = target;
    mode = mode;
    flSetRenderState(FLRENDER_ALPHABLENDMODE, 0x32);
}

void njCalcPoint(MTX *mtx, Point *ps, Point *pd) {
    f32 v0[4];

    if (mtx == NULL) {
        mtx = &cmtx;
    }

    v0[0] = ps->x;
    v0[1] = ps->y;
    v0[2] = ps->z;
    v0[3] = 1.0f;

    __asm__ __volatile__("lqc2    $vf8, 0(%1) \n"
                         "lqc2    $vf4, 0(%0) \n"
                         "lqc2    $vf5, 0x10(%0) \n"
                         "lqc2    $vf6, 0x20(%0) \n"
                         "lqc2    $vf7, 0x30(%0) \n"
                         "vmulax.xyz $ACC, $vf4, $vf8x \n"
                         "vmadday.xyz $ACC, $vf5, $vf8y \n"
                         "vmaddaz.xyz $ACC, $vf6, $vf8z \n"
                         "vmaddw.xyz $vf9, $vf7, $vf8w \n"
                         "sqc2 $vf9, 0(%1) \n"
                         :
                         : "r"(mtx), "r"(v0), "f"(pd)
                         : "memory");

    pd->x = v0[0];
    pd->y = v0[1];
    pd->z = v0[2];
}

void njCalcPoints(MTX *mtx, Point *ps, Point *pd, s32 num) {
    s32 i;

    if (mtx == NULL) {
        mtx = &cmtx;
    }

    for (i = 0; i < num; i++) {
        njCalcPoint(mtx, ps++, pd++);
    }
}

void njRotateZ(s32 /* unused */, s32 /* unused */) {
    // Do nothing
}

void njDrawTexture(Polygon *polygon, s32 /* unused */, s32 tex, s32 /* unused */) {
    Vertex vtx[4];
    s32 i;

    Polygon *temp_v1;
    void *temp_v0;

    for (i = 0; i < 4; i++) {
        vtx[i] = ((_Polygon *)polygon)[i].v;
    }

    ppgWriteQuadWithST_B(vtx, polygon[0].col, NULL, tex, -1);
}

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
