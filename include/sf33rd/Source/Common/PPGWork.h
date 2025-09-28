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
extern PPGDataList ppgTitleList;   // size: 0x8, address: 0x57B3C0
extern Texture ppgTitleTex;        // size: 0x20, address: 0x57B3D0
extern PPGDataList ppgOpnBgList;   // size: 0x8, address: 0x57B3F0
extern Texture ppgOpnBgTex;        // size: 0x20, address: 0x57B400
extern PPGDataList ppgScrListOpt;  // size: 0x8, address: 0x57B420
extern PPGDataList ppgScrListShot; // size: 0x8, address: 0x57B428
extern PPGDataList ppgScrListFace; // size: 0x8, address: 0x57B430
extern PPGDataList ppgScrList;     // size: 0x8, address: 0x57B438
extern Palette ppgScrPalOpt;       // size: 0x14, address: 0x57B440
extern Palette ppgScrPalShot;      // size: 0x14, address: 0x57B460
extern Palette ppgScrPalFace;      // size: 0x14, address: 0x57B480
extern Palette ppgScrPal;          // size: 0x14, address: 0x57B4A0
extern Texture ppgScrTex;          // size: 0x20, address: 0x57B4C0
extern PPGDataList ppgAkaneList;   // size: 0x8, address: 0x57B4E0
extern Palette ppgAkanePal;        // size: 0x14, address: 0x57B4F0
extern Texture ppgAkaneTex;        // size: 0x20, address: 0x57B510
extern PPGDataList ppgAkeList;     // size: 0x8, address: 0x57B530
extern Palette ppgAkePal;          // size: 0x14, address: 0x57B540
extern Texture ppgAkeTex;          // size: 0x20, address: 0x57B560
extern PPGDataList ppgRwBgList;    // size: 0x8, address: 0x57B580
extern Texture ppgRwBgTex;         // size: 0x20, address: 0x57B590
extern PPGDataList ppgBgList[4];   // size: 0x20, address: 0x57B5B0
extern Texture ppgBgTex[4];        // size: 0x80, address: 0x57B5D0

void ppgWorkInitializeApprication();
void ppgPurgeFromVRAM(s32 type);
void ppgPurgePaletteFromVRAM(Palette* pal);
void ppgPurgeTextureFromVRAM(Texture* tex);

#endif
