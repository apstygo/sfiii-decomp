#ifndef DC_GHOST_H
#define DC_GHOST_H

#include "types.h"
#include "unknown.h"

void njUnitMatrix(MTX *mtx);
void njGetMatrix(MTX *m);
void njSetMatrix(MTX *md, MTX *ms);
void njScale(MTX *mtx, f32 x, f32 y, f32 z);
void njTranslate(MTX *mtx, f32 x, f32 y, f32 z);
void njSetBackColor(u32 c0, u32 c1, u32 c2);
void njColorBlendingMode(s32 target, s32 mode);
void njDrawTexture(Polygon *polygon, s32 /* unused */, s32 tex, s32 /* unused */);
void njdp2d_init();
void njdp2d_draw();
void njdp2d_sort(f32 *pos, f32 pri, u32 col, s32 flag);
void njDrawPolygon2D(PAL_CURSOR *p, s32 /* unused */, f32 pri, u32 attr);
void njSetPaletteBankNumG(u32 globalIndex, s32 bank);

#endif // DC_GHOST_H
