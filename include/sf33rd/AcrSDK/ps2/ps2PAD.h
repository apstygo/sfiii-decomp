#ifndef PS2PAD_H
#define PS2PAD_H

#include "types.h"

s32 flPS2PADModuleInit();
s32 tarPADInit();
void tarPADDestroy();
void flPADConfigSetACRtoXX(s32 padnum, s16 a, s16 b, s16 c);
void tarPADRead();

#endif
