#ifndef CSE_H
#define CSE_H

#include "structs.h"
#include "types.h"

s32 cseInitSndDrv();
s32 cseExecServer();
s32 cseTsbRequest(u16 bank, u16 code, s32 NumArgSets, s32 /* unused */, s32 /* unused */, s32 /* unused */,
                  s32 /* unused */);
s32 cseCheckVTransStatus(u32 vtrans_check_type);

// Defined in color3rd.c
s32 cseTsbSetBankAddr(u32 bank, SoundEvent *addr);
s32 cseMemMapSetPhdAddr(u32 bank, void *addr);

// Defined in Sound3rd.c
s32 cseSeStopAll();
s32 cseSysSetMasterVolume(s32 vol);

#endif
