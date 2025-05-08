#ifndef SJX_H
#define SJX_H

#include <cri/cri_xpts.h>
#include <cri/sj.h>

void SJX_Init();
Sint32 SJX_Create(SJ, Sint32, Sint32); // Probably returns a pointer
void SJX_Destroy(Sint32);
void SJX_Finish();

#endif
