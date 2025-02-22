#ifndef PPGWORK_H
#define PPGWORK_H

#include "structs.h"
#include "types.h"

extern PPGDataList ppgCapLogoList; // size: 0x8, address: 0x57B308
extern Palette ppgCapLogoPal;      // size: 0x14, address: 0x57B310
extern Texture ppgCapLogoTex;      // size: 0x20, address: 0x57B330
extern PPGDataList ppgAdxList;     // size: 0x8, address: 0x57B350
extern PPGDataList ppgWarList;     // size: 0x8, address: 0x57B358
extern Palette ppgAdxPal;          // size: 0x14, address: 0x57B360
extern Palette ppgWarPal;          // size: 0x14, address: 0x57B380
extern Texture ppgWarTex;          // size: 0x20, address: 0x57B3A0
extern Texture ppgTitleTex;        // size: 0x20, address: 0x57B3D0

void ppgWorkInitializeApprication();
void ppgPurgeFromVRAM(s32 type);

#endif
