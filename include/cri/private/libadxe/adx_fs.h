#ifndef ADX_FS_H
#define ADX_FS_H

#include "types.h"
#include <cri_adxf.h>

void adxf_SetCmdHstry(s32 ncall, s32 fg, s32 ptid, s32 flid, s32 type);
ADXF adxf_CreateAdxFs();
s32 adxf_SetAfsFileInfo(ADXF adxf, s32 ptid, s32 flid);
void ADXF_Close(ADXF adxf);
s8 *ADXF_GetFnameFromPt(s32);

#endif // ADX_FS_H
