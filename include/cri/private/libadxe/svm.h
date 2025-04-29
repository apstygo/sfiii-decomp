#ifndef SVM_H
#define SVM_H

#include "types.h"
#include <cri/cri_xpts.h>

void SVM_Lock();
void SVM_Unlock();
void SVM_CallErr(const Char8 *format, ...);
void SVM_SetCbErr(void (*callback)(void *, Char8 *), void *object);

#endif
