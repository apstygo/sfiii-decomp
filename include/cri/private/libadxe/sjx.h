#ifndef SJX_H
#define SJX_H

#include "types.h"

#include <cri/private/libadxe/structs.h>

#include <cri/cri_xpts.h>
#include <cri/sj.h>

void SJX_Init();
SJX SJX_Create(SJ, void*, Sint32);
void SJX_Destroy(SJX);
void SJX_Finish();
void SJX_ExecServer();

#endif
