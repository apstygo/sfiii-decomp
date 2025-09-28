#ifndef PLAPX_H
#define PLAPX_H

#include "sf33rd/AcrSDK/common/plcommon.h"
#include "types.h"

s32 plAPXGetMipmapTextureNum(void* lpbas);                        // Range: 0x118CF0 -> 0x118D2C
s32 plAPXGetPaletteNum(void* lpbas);                              // Range: 0x118D30 -> 0x118D6C
s32 plAPXSetContextFromImage(plContext* dst, void* lpbas);        // Range: 0x118D70 -> 0x119224
s32 plAPXSetPaletteContextFromImage(plContext* dst, void* lpbas); // Range: 0x119230 -> 0x1195B4
u8* plAPXGetPixelAddressFromImage(void* lpbas, s32 Mipmap);       // Range: 0x1195C0 -> 0x1195F0
u8* plAPXGetPaletteAddressFromImage(void* lpbas, s32 index);      // Range: 0x1195F0 -> 0x119620

#endif
