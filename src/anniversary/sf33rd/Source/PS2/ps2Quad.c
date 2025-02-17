#include "common.h"

void ps2SeqsRenderQuadInit_A() {
    // Do nothing
}

void ps2SeqsRenderQuadInit_B() {
    // Do nothing
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/ps2Quad", ps2SeqsRenderQuad_Ax);

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
