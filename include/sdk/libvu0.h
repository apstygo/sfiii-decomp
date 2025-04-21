#ifndef _LIB_VU0_H_
#define _LIB_VU0_H_

#include "common.h"

typedef float sceVu0FMATRIX[4][4] ATTR_ALIGNED(16);

void sceVu0UnitMatrix(sceVu0FMATRIX m);
void sceVpu0Reset();

#endif
