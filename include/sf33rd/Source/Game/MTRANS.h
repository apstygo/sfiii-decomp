#ifndef MTRANS_H
#define MTRANS_H

#include "types.h"

extern f32 PrioBase[128]; // size: 0x200, address: 0x5E3F50

void appSetupBasePriority();
void appSetupTempPriority();
void seqsInitialize(void *adrs);
void seqsBeforeProcess();
void seqsAfterProcess();

#endif
