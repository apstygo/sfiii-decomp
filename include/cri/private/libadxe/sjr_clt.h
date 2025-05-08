#ifndef SJR_CLT_H
#define SJR_CLT_H

#include <cri/cri_xpts.h>

void SJRMT_Init();
Sint32 SJUNI_CreateRmt(Sint32, Sint8 *, Sint32); // Probably returns a pointer
void SJRMT_Destroy(Sint32);
void SJRMT_Finish();

#endif
