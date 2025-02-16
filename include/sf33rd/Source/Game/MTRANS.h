#ifndef MTRANS_H
#define MTRANS_H

void appSetupBasePriority();
void appSetupTempPriority();
void seqsInitialize(void *adrs);
void seqsBeforeProcess();
void seqsAfterProcess();

#endif
