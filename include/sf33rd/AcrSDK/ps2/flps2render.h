#ifndef FLPS2RENDER_H
#define FLPS2RENDER_H

#include "structs.h"
#include "types.h"

s32 flBeginRender();
s32 flEndRender();
s32 flPS2InitRenderState();
s32 flSetRenderState(enum _FLSETRENDERSTATE func, u32 value);
void flAdjustScreen(s32 x, s32 y);

#endif
