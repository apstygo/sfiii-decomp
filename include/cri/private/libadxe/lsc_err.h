#ifndef LSC_ERR_H
#define LSC_ERR_H

#include <cri/cri_xpts.h>

void LSC_EntryErrFunc(void (*)(void *, Char8 *), void *);
void LSC_CallErrFunc(const Char8 *format, ...);

#endif
