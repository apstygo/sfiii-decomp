#ifndef CSE_H
#define CSE_H

#include "types.h"

s32 cseExecServer();
s32 cseTsbRequest(u16 bank, u16 code, s32 NumArgSets, s32 /* unused */, s32 /* unused */, s32 /* unused */,
                  s32 /* unused */);

#endif
