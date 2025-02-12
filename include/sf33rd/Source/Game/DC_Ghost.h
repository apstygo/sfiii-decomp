#ifndef DC_GHOST_H
#define DC_GHOST_H

#include "types.h"
#include "unknown.h"

void njUnitMatrix(MTX *mtx);
void njSetBackColor(u32 c0, u32 c1, u32 c2);                                       // Range: 0x1BFF30 -> 0x1BFFBC
void njDrawTexture(Polygon *polygon, s32 /* unused */, s32 tex, s32 /* unused */); // Range: 0x1C0130 -> 0x1C01E8
void njdp2d_init();                                                                // Range: 0x1C0330 -> 0x1C034C
void njdp2d_draw();                                                                // Range: 0x1C0350 -> 0x1C0568
void njdp2d_sort(f32 *pos, f32 pri, u32 col, s32 flag);                            // Range: 0x1C0570 -> 0x1C0A0C
void njDrawPolygon2D(PAL_CURSOR *p, s32 /* unused */, f32 pri, u32 attr);          // Range: 0x1C0A10 -> 0x1C0A68
void njSetPaletteBankNumG(u32 globalIndex, s32 bank);                              // Range: 0x1C0A70 -> 0x1C0AA8

#endif // DC_GHOST_H
