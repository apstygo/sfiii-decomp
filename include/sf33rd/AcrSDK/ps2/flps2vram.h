#ifndef FLPS2VRAM_H
#define FLPS2VRAM_H

#include "sf33rd/AcrSDK/common/plcommon.h"
#include "types.h"

s32 flPS2Conv4_8_32(s32 width, s32 height, u8 *p_input, u8 *p_output, s32 n_bit);
s32 flPS2ConvertContext(plContext *lpSrc, plContext *lpDst, u32 direction, u32 type);
u32 flPS2GetPaletteHandle();
s32 flPS2CreatePaletteHandle(u32 ph, u32 flag);
s32 flPS2GetPaletteInfoFromContext(plContext *bits, u32 ph, u32 flag);
u32 flPS2GetTextureHandle();
s32 flPS2CreateTextureHandle(u32 th, u32 flag);
s32 flPS2GetTextureInfoFromContext(plContext *bits, s32 bnum, u32 th, u32 flag);

#endif
