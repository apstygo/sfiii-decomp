#include "sf33rd/Source/Game/DC_Ghost.h"
#include "common.h"
#include "sf33rd/Source/Game/AcrUtil.h"
#include "unknown.h"
#include <libvu0.h>

#define NTH_BYTE(value, n) ((((value >> n * 8) & 0xFF) << n * 8))

typedef struct {
    Vertex v;
    u32 col;
} _Polygon;

typedef struct {
    // total size: 0x3C
    Point v[4]; // offset 0x0, size 0x30
    u32 col;    // offset 0x30, size 0x4
    u32 type;   // offset 0x34, size 0x4
    s32 next;   // offset 0x38, size 0x4
} NJDP2D_PRIM;

typedef struct {
    // total size: 0x1774
    s16 ix1st;             // offset 0x0, size 0x2
    s16 total;             // offset 0x2, size 0x2
    NJDP2D_PRIM prim[100]; // offset 0x4, size 0x1770
} NJDP2D_W;

extern NJDP2D_W njdp2d_w;
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

void njDrawSprite(Polygon *polygon, s32 /* unused */, s32 tex, s32 /* unused */) {
    Vertex vtx[4];

    if ((getCP3toFullScreenDrawFlag() != 0) &&
        ((polygon[0].x >= 384.0f) || (polygon[3].x < 0.0f) || (polygon[0].y >= 224.0f) || (polygon[3].y < 0.0f))) {
        return;
    }

    vtx[0] = ((_Polygon *)polygon)[0].v;
    vtx[3] = ((_Polygon *)polygon)[3].v;

    ppgWriteQuadWithST_B2(vtx, polygon[0].col, 0, tex, -1);
}

void njdp2d_init() {
    njdp2d_w.ix1st = -1;
    njdp2d_w.total = 0;
}

void njdp2d_draw() {
    Quad prm;
    s32 i;

    ps2SeqsRenderQuadInit_B();
    setZ_Operation(1);

    for (i = njdp2d_w.ix1st; i != -1; i = njdp2d_w.prim[i].next) {
        switch (njdp2d_w.prim[i].type) {
        case 0:
            prm.v[0] = njdp2d_w.prim[i].v[0];
            prm.v[1] = njdp2d_w.prim[i].v[1];
            prm.v[2] = njdp2d_w.prim[i].v[2];
            prm.v[3] = njdp2d_w.prim[i].v[3];

            ps2SeqsRenderQuad_B(&prm, njdp2d_w.prim[i].col);
            break;

        case 1:
            shadow_drawing((UNK_12 *)njdp2d_w.prim[i].col, njdp2d_w.prim[i].v[0].y); // Looks weird
            break;
        }
    }

    njdp2d_init();
    ps2SeqsRenderQuadEnd();
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njdp2d_sort);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njDrawPolygon2D);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njSetPaletteBankNumG);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njSetPaletteMode);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njSetPaletteData);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", njReLoadTexturePartNumG);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DC_Ghost", literal_477_00504BB0);
