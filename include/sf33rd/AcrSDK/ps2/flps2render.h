#ifndef FLPS2RENDER_H
#define FLPS2RENDER_H

#include "structs.h"
#include "types.h"

s32 flBeginRender();
s32 flEndRender();
s32 flPS2InitRenderState();
s32 flSetRenderState(enum _FLSETRENDERSTATE func, u32 value);
void flAdjustScreen(s32 x, s32 y);
u32 flPS2ConvColor(u32 c, s32 type);
f32 flPS2ConvScreenFX(f32 x);
f32 flPS2ConvScreenFY(f32 y);
f32 flPS2ConvScreenFZ(f32 z);
s32 flPS2SendRenderState_SCISSOR(s32 dx, s32 dy, s32 dw, s32 dh, u32 flag);

#endif
