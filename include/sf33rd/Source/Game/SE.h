#ifndef SE_H
#define SE_H

#include "structs.h"
#include "types.h"

extern u8 gSeqStatus[1]; // size: 0x1, address: 0x579850

void Sound_SE(s16 Code);
void BGM_Request(s16 Code);
void BGM_Request_Code_Check(u16 Code);
void BGM_Stop();
void SE_All_Off();
void Disp_Sound_Code();
void Store_Sound_Code(u16 code, SoundPatchConfig *rmc);
void Se_Dummy(WORK_Other *ewk, u16 Code);
void Se_Shock(WORK_Other *ewk, u16 Code);
void Se_Myself(WORK_Other *ewk, u16 Code);
void Se_Myself_Die(WORK_Other *ewk, u16 Code);
void Se_Let(WORK_Other *ewk, u16 Code);
void Se_Let_SP(WORK_Other *ewk, u16 Code);
void Call_Se(WORK_Other *ewk, u16 Code);
void Se_Term(WORK_Other *ewk, u16 Code);

#endif
