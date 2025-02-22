#include "sf33rd/Source/Game/op_sub.h"
#include "common.h"
#include "sf33rd/Source/Common/PPGFile.h"
#include "sf33rd/Source/Common/PPGWork.h"
#include "sf33rd/Source/Game/OPENING.h"

void TexRelease(u32 G_Num) {
    if (G_Num == 0x259) {
        title_tex_flag = 0;
    }

    switch (G_Num) {
    case 0x24E:
        ppgReleaseTextureHandle(&ppgWarTex, -1);
        ppgReleasePaletteHandle(&ppgWarPal, -1);
        ppgReleasePaletteHandle(&ppgAdxPal, -1);
        break;

    case 0x258:
        ppgReleaseTextureHandle(&ppgCapLogoTex, -1);
        ppgReleasePaletteHandle(&ppgCapLogoPal, -1);
        break;

    case 0x259:
        ppgReleaseTextureHandle(&ppgTitleTex, -1);
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/op_sub", TexRelease_OP);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/op_sub", put_chr2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/op_sub", opbg_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/op_sub", COLOR_COPYn);
