#ifndef SE_H
#define SE_H

#include "types.h"

extern u8 gSeqStatus[1]; // size: 0x1, address: 0x579850

void Sound_SE(s16 Code);
void BGM_Request(s16 Code);
void BGM_Request_Code_Check(u16 Code);
void BGM_Stop();
void SE_All_Off();
void Disp_Sound_Code();
void Store_Sound_Code(u16 code, SoundPatchConfig *rmc);

#endif
