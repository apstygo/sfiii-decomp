#ifndef PS2QUAD_H
#define PS2QUAD_H

#include "structs.h"
#include "types.h"

void ps2SeqsRenderQuadInit_A();
void ps2SeqsRenderQuadInit_B();
void ps2SeqsRenderQuad_A(Sprite *spr, u32 col);
void ps2SeqsRenderQuad_A2(Sprite *spr, u32 col);
void ps2SeqsRenderQuad_B(Quad *spr, u32 col);
void ps2SeqsRenderQuadEnd();
s32 getCP3toFullScreenDrawFlag();
void CP3toPS2DrawOn();
void CP3toPS2DrawOff();
void CP3toPS2Draw();

#endif
