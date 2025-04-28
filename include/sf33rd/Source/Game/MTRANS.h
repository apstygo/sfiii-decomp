#ifndef MTRANS_H
#define MTRANS_H

#include "structs.h"
#include "types.h"

extern f32 PrioBase[128]; // size: 0x200, address: 0x5E3F50

void appSetupBasePriority();
void appSetupTempPriority();
void seqsInitialize(void *adrs);
void seqsBeforeProcess();
void seqsAfterProcess();
u32 seqsGetUseMemorySize();
void mlt_obj_melt2(MultiTexture *mt, u16 cg_number);
void mlt_obj_trans_init(MultiTexture *mt, s32 mode, u8 *adrs);

#endif
