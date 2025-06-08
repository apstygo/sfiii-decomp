#ifndef FLPS2RENDER_H
#define FLPS2RENDER_H

#include "structs.h"
#include "types.h"

#define MIP_TBP_SIZE 6
#define MIP_DBW_SIZE 6

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
s32 flPS2SendRenderState_ZBUF(u32 render_state, u32 flag);
s32 flPS2SendRenderState_TEST(u32 render_state, u32 flag);
s32 flPS2SendRenderState_ALPHA(u32 render_state, u32 flag);
s32 flPS2SendRenderState_FOGCOL(u32 fogcol);
s32 flPS2SendRenderState_TEX1(u32 render_state, u32 flag);
s32 flPS2SetTextureRegister(u32 th, u64 *texA, u64 *tex1, u64 *tex0, u64 *clamp, u64 *miptbp1, u64 *miptbp2,
                            u32 render_ope);
s16 flPS2ConvScreenX(s16 x);
s16 flPS2ConvScreenY(s16 y);

#endif
