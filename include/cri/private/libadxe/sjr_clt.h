#ifndef SJR_CLT_H
#define SJR_CLT_H

#include <cri/cri_xpts.h>

void SJRMT_Init();
void *SJUNI_CreateRmt(Sint32, Sint8 *, Sint32);
void SJRMT_Destroy(void *);
void SJRMT_Finish();

#endif
