#ifndef EML_MEM_MAP_H
#define EML_MEM_MAP_H

#include "types.h"

extern void * PhdAddr[16];

s32 mlMemMapInit(void *pSpuMemMap);
u32 mlMemMapGetBankAddr(u32 bank);
s32 mlMemMapSetPhdAddr(u32 bank ,void *addr);
void * mlMemMapGetPhdAddr(u32 bank);

#endif
