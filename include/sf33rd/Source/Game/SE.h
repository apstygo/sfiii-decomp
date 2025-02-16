#ifndef SE_H
#define SE_H

#include "types.h"

void Sound_SE(s16 Code);
void BGM_Request(s16 Code);
void BGM_Request_Code_Check(u16 Code);
void BGM_Stop();
void SE_All_Off();
void Disp_Sound_Code();

#endif
