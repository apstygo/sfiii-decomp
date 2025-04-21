#ifndef SVM_H
#define SVM_H

#include "types.h"

void SVM_Lock();
void SVM_Unlock();
void SVM_CallErr(s8 *);
void SVM_SetCbErr(void (*)(void *, s8 *), void *);

#endif // SVM_H
