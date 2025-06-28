#ifndef ADX_FS_H
#define ADX_FS_H

#include "types.h"

#include <cri/ee/cri_xpt.h>
#include <cri_adxf.h>

void adxf_SetCmdHstry(Sint32 ncall, Sint32 fg, intptr_t ptid, intptr_t flid, intptr_t type);
ADXF adxf_CreateAdxFs();
Sint32 adxf_SetAfsFileInfo(ADXF adxf, Sint32 ptid, Sint32 flid);
void ADXF_Close(ADXF adxf);
Char8 *ADXF_GetFnameFromPt(Sint32);

#endif // ADX_FS_H
