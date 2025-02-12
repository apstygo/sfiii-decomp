#ifndef _LIB_VU0_H_
#define _LIB_VU0_H_

typedef float sceVu0FMATRIX[4][4] __attribute__((aligned(16)));

void sceVu0UnitMatrix(sceVu0FMATRIX m);
void sceVpu0Reset();

#endif
