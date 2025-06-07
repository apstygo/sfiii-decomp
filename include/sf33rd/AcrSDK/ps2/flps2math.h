#ifndef FLPS2MATH_H
#define FLPS2MATH_H

#include "structs.h"
#include "types.h"

void flmatrMakeViewport(s32 mdst, s32 dwx, s32 dwy, s32 dwWidth, s32 dwHeight, f32 dvMinz, f32 dvMaxz);
void flmatMakeViewport(MTX *lpmat, s32 dwx, s32 dwy, s32 dwWidth, s32 dwHeight, f32 dvMinz, f32 dvMaxz);
void flvecNormalize(Vec3 *lpvec);
void flmatMul(MTX *lpdst, const MTX *lpsrc1, const MTX *lpsrc2);

#endif
