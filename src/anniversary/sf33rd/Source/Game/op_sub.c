#include "sf33rd/Source/Game/op_sub.h"
#include "common.h"
#include "sf33rd/Source/Common/PPGFile.h"
#include "sf33rd/Source/Common/PPGWork.h"
#include "sf33rd/Source/Game/MTRANS.h"
#include "sf33rd/Source/Game/OPENING.h"
#include "sf33rd/Source/Game/RAMCNT.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/texcash.h"

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

void TexRelease_OP() {
    Purge_memory_of_kind_of_key(0x1D);
    ppgSourceDataReleased(&ppgOpnBgList);
    ppgReleaseTextureHandle(&ppgOpnBgTex, -1);
    reset_dma_group(0x8C40);
    purge_texcash_work(9);
}

void put_chr2(OPTW *optw) {
    Vertex tex[4];

    if (!No_Trans) {
        tex[0].x = Frame_Zoom_X * ((s32)optw->off_x * optw->zx);
        tex[0].y = Frame_Zoom_Y * ((s32)optw->off_y * optw->zy);
        tex[3].x = Frame_Zoom_X * ((optw->off_x + 0x100) * optw->zx);
        tex[3].y = Frame_Zoom_Y * ((optw->off_y + 0x100) * optw->zy);
        tex[0].z = tex[3].z = PrioBase[optw->prio];
        ppgWriteQuadUseTrans(tex, optw->col.full, NULL, optw->g_no, -1, optw->hv, 0x12C);
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/op_sub", opbg_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/op_sub", COLOR_COPYn);
