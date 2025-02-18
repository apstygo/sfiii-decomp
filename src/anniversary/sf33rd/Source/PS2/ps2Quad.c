#include "sf33rd/Source/PS2/ps2Quad.h"
#include "common.h"
#include "sf33rd/AcrSDK/ps2/flps2dma.h"
#include "sf33rd/AcrSDK/ps2/flps2etc.h"
#include "sf33rd/AcrSDK/ps2/flps2render.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "structs.h"
#include <eestruct.h>
#include <libgraph.h>

typedef struct {
    // total size: 0x8
    u32 s; // offset 0x0, size 0x4
    u32 t; // offset 0x4, size 0x4
} _TexCoord;

typedef struct {
    // total size: 0x34
    Point v[2];     // offset 0x0, size 0x18
    _TexCoord t[2]; // offset 0x18, size 0x10
    u32 vtxColor;   // offset 0x28, size 0x4
    u32 texCode;    // offset 0x2C, size 0x4
    u32 id;         // offset 0x30, size 0x4
} _Sprite2;

void ps2SeqsRenderQuadInit_A() {
    // Do nothing
}

void ps2SeqsRenderQuadInit_B() {
    // Do nothing
}

void ps2SeqsRenderQuad_Ax(Sprite2 *spr) {
    u32 data_ptr;
    u32 col;
    u64 rgbaq;
    u64 *p;
    s32 x;
    s32 y;
    s32 z;
    u8 cA;
    u8 cR;
    u8 cG;
    u8 cB;

    data_ptr = flPS2GetSystemTmpBuff(80, 16);
    p = (u64 *)data_ptr;

    *p++ = 0x80000000 | DMAend | 4;
    *((u32 *)p)++ = SCE_VIF1_SET_NOP(0);
    *((u32 *)p)++ = SCE_VIF1_SET_DIRECTHL(4, 0);

    *p++ = SCE_GIF_SET_TAG(1, SCE_GS_TRUE, SCE_GS_FALSE, 0, SCE_GIF_REGLIST, 6);
    *p++ = 0 | SCE_GS_PRIM << (4 * 0) | SCE_GS_RGBAQ << (4 * 1) | SCE_GS_ST << (4 * 2) | SCE_GS_XYZ2 << (4 * 3) |
           SCE_GS_ST << (4 * 4) | SCE_GS_XYZ2 << (4 * 5);

    col = flPS2ConvColor(spr->vtxColor, 0);
    cA = (col >> 24) & 0xFF;
    cR = (col >> 16) & 0xFF;
    cG = (col >> 8) & 0xFF;
    cB = col & 0xFF;
    rgbaq = SCE_GS_SET_RGBAQ(cR, cG, cB, cA, 0x3F800000);
    z = flPS2ConvScreenFZ(spr->v[0].z);

    *p++ = SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE,
                           /* Gourand */ SCE_GS_FALSE,
                           /* Textured */ SCE_GS_TRUE,
                           /* fog */ SCE_GS_FALSE,
                           /* Alpha blend */ SCE_GS_TRUE,
                           /* AA */ SCE_GS_FALSE,
                           /* UV */ SCE_GS_FALSE,
                           /* ctx2 */ SCE_GS_FALSE,
                           /* frag */ SCE_GS_FALSE);
    *p++ = rgbaq;

    *p++ = SCE_GS_SET_ST(((_Sprite2 *)spr)->t[0].s, ((_Sprite2 *)spr)->t[0].t);

    x = spr->v[0].x + 0.5f;
    y = spr->v[0].y + 0.5f;
    *p++ = SCE_GS_SET_XYZ((flPs2State.D2dOffsetX + x) << 4, (flPs2State.D2dOffsetY + y) << 4, (u32)z);

    *p++ = SCE_GS_SET_ST(((_Sprite2 *)spr)->t[1].s, ((_Sprite2 *)spr)->t[1].t);

    x = spr->v[1].x + 0.5f;
    y = spr->v[1].y + 0.5f;
    *p++ = SCE_GS_SET_XYZ((flPs2State.D2dOffsetX + x) << 4, (flPs2State.D2dOffsetY + y) << 4, (u32)z);

    flPS2DmaAddQueue2(0, DMArefs | (data_ptr & 0xFFFFFFF), data_ptr, &flPs2VIF1Control);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/ps2Quad", ps2SeqsRenderQuad_A2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/ps2Quad", ps2SeqsRenderQuad_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/ps2Quad", ps2QuadTexture);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/ps2Quad", ps2SeqsRenderQuad_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/ps2Quad", ps2QuadSolid);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/ps2Quad", ps2SeqsRenderQuadEnd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/ps2Quad", getCP3toFullScreenDrawFlag);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/ps2Quad", CP3toPS2DrawOn);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/ps2Quad", CP3toPS2DrawOff);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/ps2Quad", CP3toPS2Draw);
