#include "sf33rd/Source/Common/PPGWork.h"
#include "common.h"

// sbss

Texture ppgBgTex[4];
PPGDataList ppgBgList[4];

Texture ppgRwBgTex;
PPGDataList ppgRwBgList;

Texture ppgAkeTex;
Palette ppgAkePal;
PPGDataList ppgAkeList;

Texture ppgAkaneTex;
Palette ppgAkanePal;
PPGDataList ppgAkaneList;

Texture ppgScrTex;
Palette ppgScrPal;
Palette ppgScrPalFace;
Palette ppgScrPalShot;
Palette ppgScrPalOpt;
PPGDataList ppgScrList;
PPGDataList ppgScrListFace;
PPGDataList ppgScrListShot;
PPGDataList ppgScrListOpt;

Texture ppgOpnBgTex;
PPGDataList ppgOpnBgList;

Texture ppgTitleTex;
PPGDataList ppgTitleList;

Texture ppgWarTex;
Palette ppgWarPal;
Palette ppgAdxPal;
PPGDataList ppgWarList;
PPGDataList ppgAdxList;

Texture ppgCapLogoTex;
Palette ppgCapLogoPal;
PPGDataList ppgCapLogoList;

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGWork", ppgWorkInitializeApprication);
#else
void ppgWorkInitializeApprication() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGWork", ppgPurgeFromVRAM);
#else
void ppgPurgeFromVRAM(s32 type) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGWork", ppgPurgeTextureFromVRAM);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGWork", ppgPurgePaletteFromVRAM);
