#include "sf33rd/Source/Game/sc_sub.h"
#include "common.h"
#include "sf33rd/AcrSDK/ps2/flps2render.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "sf33rd/Source/Common/PPGFile.h"
#include "sf33rd/Source/Common/PPGWork.h"
#include "sf33rd/Source/Game/AcrUtil.h"
#include "sf33rd/Source/Game/DC_Ghost.h"
#include "sf33rd/Source/Game/Eff76.h"
#include "sf33rd/Source/Game/GD3rd.h"
#include "sf33rd/Source/Game/MTRANS.h"
#include "sf33rd/Source/Game/RAMCNT.h"
#include "sf33rd/Source/Game/SysDir.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/bg_data.h"
#include "sf33rd/Source/Game/sc_data.h"
#include "sf33rd/Source/Game/workuser.h"
#include "sf33rd/Source/PS2/ps2Quad.h"
#include "structs.h"

typedef struct {
    // total size: 0x6
    s16 fade;      // offset 0x0, size 0x2
    s16 fade_kind; // offset 0x2, size 0x2
    u8 fade_prio;  // offset 0x4, size 0x1
} FadeData;

typedef struct {
    // total size: 0x4
    u8 atr;  // offset 0x0, size 0x1
    u8 page; // offset 0x1, size 0x1
    u8 cx;   // offset 0x2, size 0x1
    u8 cy;   // offset 0x3, size 0x1
} SAFrame;

// sdata
u8 ascProData[128] = { 0, 18, 0, 0, 0,  0, 0,  0,  0,  0, 0,  0, 0, 0,  0,  0,  0, 0, 0,  0,  0,  0,  0, 0,  0, 0,
                       0, 0,  0, 0, 0,  0, 34, 19, 18, 0, 0,  0, 0, 34, 34, 34, 1, 1, 34, 1,  34, 0,  0, 18, 0, 0,
                       0, 0,  0, 0, 0,  0, 34, 34, 17, 0, 17, 0, 0, 0,  0,  0,  0, 0, 0,  0,  0,  34, 0, 0,  0, 0,
                       0, 0,  0, 0, 0,  0, 0,  0,  0,  0, 0,  0, 0, 17, 0,  17, 1, 0, 34, 0,  0,  0,  0, 0,  0, 0,
                       0, 34, 2, 0, 34, 0, 0,  0,  0,  0, 16, 0, 0, 0,  0,  0,  0, 0, 0,  18, 35, 33, 0, 33 };

// bss
SAFrame sa_frame[3][48];

// sbss
Polygon scrscrntex[4];
u8 WipeLimit;
u8 FadeLimit;
s16 Hnc_Num;
FadeData fd_dat;

// forward decls
s32 SSGetDrawSizePro(const s8 *str);
s16 SSPutStrTexInputPro(u16 x, u16 y, u16 ix);
void face_base_put();
void silver_stun_put(u8 Pl_Num, s16 len);

void Scrscreen_Init() {
    void *loadAdrs;
    u32 loadSize;
    s16 i;
    s16 key;

    ppgScrList.tex = ppgScrListFace.tex = ppgScrListShot.tex = ppgScrListOpt.tex = &ppgScrTex;
    ppgScrList.pal = &ppgScrPal;
    ppgScrListFace.pal = &ppgScrPalFace;
    ppgScrListShot.pal = &ppgScrPalShot;
    ppgScrListOpt.pal = &ppgScrPalOpt;
    ppgSetupCurrentDataList(&ppgScrList);
    loadSize = load_it_use_any_key2(10, &loadAdrs, &key, 2, 0); // scrscrn.ppg

    if (loadSize == 0) {
        // Could not load texture for score screen.\n
        flLogOut("スコアスクリーン用のテクスチャが読み込めませんでした。\n");
        while (1) {
            // Do nothing
        }
    }

    ppgSetupPalChunk(&ppgScrPalOpt, (u8 *)loadAdrs, loadSize, 0, 3, 1);
    ppgSetupPalChunk(&ppgScrPalShot, (u8 *)loadAdrs, loadSize, 0, 2, 1);
    ppgSetupPalChunk(&ppgScrPalFace, (u8 *)loadAdrs, loadSize, 0, 1, 1);
    ppgSetupPalChunk(NULL, (u8 *)loadAdrs, loadSize, 0, 0, 1);
    ppgSetupTexChunk_1st(NULL, (u8 *)loadAdrs, loadSize, 0, 6, 0, 0);

    for (i = 0; i < 3; i++) {
        ppgSetupTexChunk_2nd(NULL, i);
        ppgSetupTexChunk_3rd(NULL, i, 1);
    }

    for (i = 3; i < ppgScrTex.textures; i++) {
        ppgSetupTexChunk_2nd(NULL, i);
        ppgSetupTexChunk_3rd(NULL, i, 1);
    }

    Push_ramcnt_key(key);
    ppgSourceDataReleased(NULL);
    Sa_frame_Clear();
}

void Sa_frame_Clear() {
    u8 i;
    u8 j;

    for (j = 0; j < 3; j++) {
        for (i = 0; i < 48; i++) {
            sa_frame[j][i].atr = 0;
            sa_frame[j][i].page = 0;
            sa_frame[j][i].cx = 0;
            sa_frame[j][i].cy = 0;
        }
    }
}

void Sa_frame_Clear2(u8 pl) {
    u8 i;
    u8 j;

    for (j = 0; j < 3; j++) {
        for (i = pl * 24; i < (pl * 24) + 24; i++) {
            sa_frame[j][i].atr = 0;
            sa_frame[j][i].page = 0;
            sa_frame[j][i].cx = 0;
            sa_frame[j][i].cy = 0;
        }
    }
}

void Sa_frame_Write() {
    u8 i;
    u8 j;

    if (omop_cockpit == 0) {
        return;
    }

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);

    if (omop_sa_bar_disp[0]) {
        for (j = 0; j < 3; j++) {
            for (i = 0; i < 24; i++) {
                if (sa_frame[j][i].atr != 0) {
                    scfont_put(
                        i, j + 25, sa_frame[j][i].atr, sa_frame[j][i].page, sa_frame[j][i].cx, sa_frame[j][i].cy, 2);
                }
            }
        }
    }

    if (omop_sa_bar_disp[1]) {
        for (j = 0; j < 3; j++) {
            for (i = 24; i < 48; i++) {
                if (sa_frame[j][i].atr != 0) {
                    scfont_put(
                        i, j + 25, sa_frame[j][i].atr, sa_frame[j][i].page, sa_frame[j][i].cx, sa_frame[j][i].cy, 2);
                }
            }
        }
    }
}

void SSPutStrTexInput(u16 x, u16 y, const s8 *str) {
    s32 u = ((*str & 0xF) * 8) + 0x80;
    s32 v = ((*str & 0xF0) >> 4) * 8;

    scrscrntex[0].u = (u + 0.5f) / 256.0f;
    scrscrntex[3].u = ((u + 8) + 0.5f) / 256.0f;
    scrscrntex[0].v = (v + 0.5f) / 256.0f;
    scrscrntex[3].v = ((v + 8) + 0.5f) / 256.0f;
    scrscrntex[0].x = x * Frame_Zoom_X;
    scrscrntex[3].x = (x + 8) * Frame_Zoom_X;
    scrscrntex[0].y = y * Frame_Zoom_Y;
    scrscrntex[3].y = (y + 8) * Frame_Zoom_Y;
}

void SSPutStrTexInput2(u16 x, u16 y, u8 str) {
    s32 u;

    u = (str * 8) + 128;
    scrscrntex[0].u = (0.5f + u) / 256.0f;
    scrscrntex[3].u = (0.5f + (u + 8)) / 256.0f;
    scrscrntex[0].v = 0.001953125f;
    scrscrntex[3].v = 0.033203125f;
    scrscrntex[0].x = x * Frame_Zoom_X;
    scrscrntex[3].x = (x + 8) * Frame_Zoom_X;
    scrscrntex[0].y = y * Frame_Zoom_Y;
    scrscrntex[3].y = (y + 8) * Frame_Zoom_Y;
}

void SSPutStr(u16 x, u16 y, u8 atr, const s8 *str) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = 0xFFFFFFFF;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[2];
    njSetPaletteBankNumG(1, atr & 0x3F);
    x = x * 8;
    y = y * 8;

    while (*str != '\0') {
        if (*str != ',') {
            SSPutStrTexInput(x, y, str);
        } else {
            SSPutStrTexInput(x, y + 2, str);
        }

        njDrawSprite(scrscrntex, 4, 1, 1);
        x += 8;
        str++;
    }
}

s32 SSPutStrPro(u16 flag, u16 x, u16 y, u8 atr, u32 vtxcol, s8 *str) {
    s32 usex;
    s16 step;

    if (No_Trans) {
        return x;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = vtxcol;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[2];
    njSetPaletteBankNumG(1, atr & 0x3F);

    if (flag) {
        x = (x - SSGetDrawSizePro(str)) / 2;
    }

    usex = x;

    while (*str != 0) {
        if (*str != ',') {
            step = SSPutStrTexInputPro(x, y, *str);
        } else {
            step = SSPutStrTexInputPro(x, y + 2, *str);
        }

        str += 1;
        x += step;
        njDrawSprite(scrscrntex, 4, 1, 1);
    }

    return usex;
}

s16 SSPutStrTexInputPro(u16 x, u16 y, u16 ix) {
    s16 slide;
    s16 sideL;
    s16 sideR;
    s32 u;
    s32 v;

    u = (ix & 0xF) * 8 + 0x80;
    v = ((ix & 0xF0) >> 4) * 8;

    sideL = (ascProData[ix] >> 4) & 0xF;
    sideR = ascProData[ix] & 0xF;
    scrscrntex[0].u = (u + sideL + 0.5f) / 256.0f;
    scrscrntex[3].u = (u + 8 - sideR + 0.5f) / 256.0f;
    scrscrntex[0].v = (v + 0.5f) / 256.0f;
    scrscrntex[3].v = (v + 8 + 0.5f) / 256.0f;
    slide = (8 - sideL) - sideR;
    scrscrntex[0].x = x * Frame_Zoom_X;
    scrscrntex[3].x = Frame_Zoom_X * (x + slide);
    scrscrntex[0].y = y * Frame_Zoom_Y;
    scrscrntex[3].y = (y + 8) * Frame_Zoom_Y;
    return slide;
}

s32 SSGetDrawSizePro(const s8 *str) {
    s32 ix;
    s32 size = 0;

    while (*str != '\0') {
        ix = *str++;
        ix &= 0x7F;
        size += 8 - ((ascProData[ix] >> 4) & 0xF) - (ascProData[ix] & 0xF);
    }

    return size;
}

void SSPutStr2(u16 x, u16 y, u8 atr, const s8 *str) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[1];
    njSetPaletteBankNumG(1, atr & 0x3F);
    x = x * 8;
    y = y * 8;

    while (*str != '\0') {
        SSPutStrTexInput(x, y, str);
        njDrawSprite(scrscrntex, 4, 1, 1);
        x += 8;
        str++;
    }
}

void SSPutStrTexInputB(f32 x, f32 y, s8 *str, f32 sc) {
    s32 u = ((*str & 0xF) * 8) + 0x80;
    s32 v = ((*str & 0xF0) >> 4) * 8;

    scrscrntex[0].u = scrscrntex[1].u = (0.5f + u) / 256.0f;
    scrscrntex[2].u = scrscrntex[3].u = (0.5f + (u + 8)) / 256.0f;
    scrscrntex[0].v = scrscrntex[2].v = (0.5f + v) / 256.0f;
    scrscrntex[1].v = scrscrntex[3].v = (0.5f + (v + 8)) / 256.0f;
    scrscrntex[0].x = scrscrntex[1].x = x * Frame_Zoom_X;
    scrscrntex[2].x = scrscrntex[3].x = Frame_Zoom_X * (x + (8.0f * sc));
    scrscrntex[0].y = scrscrntex[2].y = y * Frame_Zoom_Y;
    scrscrntex[1].y = scrscrntex[3].y = Frame_Zoom_Y * (y + (8.0f * sc));
}

void SSPutStrTexInputB2(f32 x, f32 y, s8 str) {
    s32 u = str * 11;

    scrscrntex[0].u = scrscrntex[1].u = (0.5f + u) / 256.0f;
    scrscrntex[2].u = scrscrntex[3].u = (0.5f + (u + 11)) / 256.0f;
    scrscrntex[0].v = scrscrntex[2].v = 0.7832031f;
    scrscrntex[1].v = scrscrntex[3].v = 0.8144531f;
    scrscrntex[0].x = scrscrntex[1].x = x * Frame_Zoom_X;
    scrscrntex[2].x = scrscrntex[3].x = (11.0f + x) * Frame_Zoom_X;
    scrscrntex[0].y = scrscrntex[2].y = y * Frame_Zoom_Y;
    scrscrntex[1].y = scrscrntex[3].y = (8.0f + y) * Frame_Zoom_Y;
}

void SSPutStr_Bigger(u16 x, u16 y, u8 atr, s8 *str, f32 sc, u8 gr, u16 priority) {
    f32 xx;
    f32 yy;
    u8 i;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);

    for (i = 0; i < 4; i++) {
        scrscrntex[i].col = bigger_col_tbl[gr][i];
    }

    scrscrntex[0].z = scrscrntex[1].z = scrscrntex[2].z = scrscrntex[3].z = PrioBase[priority];
    njSetPaletteBankNumG(1, atr & 0x3F);
    xx = x;
    yy = y;

    while (*str != '\0') {
        if (*str == '$') {
            str++;
            xx += 4.0f * sc;
            continue;
        }

        SSPutStrTexInputB(xx, yy, str, sc);
        njDrawTexture(scrscrntex, 4, 1, 1);
        xx += 8.0f * sc;
        str++;
    }
}

void SSPutDec(u16 x, u16 y, u8 atr, u8 dec, u8 size) {
    s8 str[3];
    u8 work;
    u8 num;
    u8 i;
    u8 zero_sw;

    if (No_Trans) {
        return;
    }

    if (size == 0) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[2];
    njSetPaletteBankNumG(1, atr & 0x3F);
    x = x * 8;
    y = y * 8;
    zero_sw = 0;
    work = 100;

    for (i = 0; i < 3; i++) {
        for (num = 0; dec + 1 > work; dec = dec - work, num++) {}

        str[i] = num;
        work = work / 10;
    }

    SSPutStrTexInput2(x, y, str[2]);
    njDrawSprite(scrscrntex, 4, 1, 1);

    if (size == 0) {
        return;
    }

    x -= 16;

    if (size == 3 && str[0] != 0) {
        SSPutStrTexInput2(x, y, str[0]);
        njDrawSprite(scrscrntex, 4, 1, 1);
        zero_sw = 1;
    }

    x += 8;

    if (zero_sw == 1) {
        SSPutStrTexInput2(x, y, str[1]);
        njDrawSprite(scrscrntex, 4, 1, 1);
    } else if (size > 1 && str[1] != 0) {
        SSPutStrTexInput2(x, y, str[1]);
        njDrawSprite(scrscrntex, 4, 1, 1);
    }
}

void SSPutDec3(u16 x, u16 y, u8 atr, s16 dec, u8 size, u8 gr, u16 priority) {
    s8 str[3];
    s16 work;
    u8 num;
    u8 i;
    u8 zero_sw;
    f32 xx;
    f32 yy;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);

    for (i = 0; i < 4; i++) {
        scrscrntex[i].col = bigger_col_tbl[gr][i];
    }

    scrscrntex[0].z = scrscrntex[1].z = scrscrntex[2].z = scrscrntex[3].z = PrioBase[priority];
    njSetPaletteBankNumG(1, atr & 0x3F);

    xx = x;
    yy = y;
    zero_sw = 0;
    work = 100;

    for (i = 0; i < 3; i++) {
        for (num = 0; dec + 1 > work; dec = dec - work, num++) {}

        str[i] = num;
        work = work / 10;
    }

    SSPutStrTexInputB2(xx, yy, str[2]);
    njDrawTexture(scrscrntex, 4, 4, 1);

    if (size == 0) {
        return;
    }

    xx -= 22.0f;

    if (size == 3 && str[0] != 0) {
        SSPutStrTexInputB2(xx, yy, str[0]);
        njDrawSprite(scrscrntex, 4, 4, 1);
        zero_sw = 1;
    }

    xx += 11.0f;

    if (zero_sw == 1) {
        SSPutStrTexInputB2(xx, yy, str[1]);
        njDrawSprite(scrscrntex, 4, 4, 1);
    } else if (size > 1 && str[1] != 0) {
        SSPutStrTexInputB2(xx, yy, str[1]);
        njDrawSprite(scrscrntex, 4, 4, 1);
    }
}

void scfont_put(u16 x, u16 y, u8 atr, u8 page, u8 cx, u8 cy, u16 priority) {
    s32 u;
    s32 v;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[priority];
    njSetPaletteBankNumG(page, atr & 0x3F);
    x = x * 8;
    y = y * 8;
    u = cx * 8;
    v = cy * 8;

    if (atr & 0x80) {
        scrscrntex[3].u = (u - 0.5f) / 256.0f;
        scrscrntex[0].u = ((u + 8) - 0.5f) / 256.0f;
    } else {
        scrscrntex[0].u = (0.5f + u) / 256.0f;
        scrscrntex[3].u = (0.5f + (u + 8)) / 256.0f;
    }

    if (atr & 0x40) {
        scrscrntex[3].v = (v - 0.5f) / 256.0f;
        scrscrntex[0].v = ((v + 8) - 0.5f) / 256.0f;
    } else {
        scrscrntex[0].v = (0.5f + v) / 256.0f;
        scrscrntex[3].v = (0.5f + (v + 8)) / 256.0f;
    }

    scrscrntex[0].x = x * Frame_Zoom_X;
    scrscrntex[3].x = (x + 8) * Frame_Zoom_X;
    scrscrntex[0].y = y * Frame_Zoom_Y;
    scrscrntex[3].y = (y + 8) * Frame_Zoom_Y;
    njDrawSprite(scrscrntex, 4, page, 1);
}

void scfont_put2(u16 x, u16 y, u8 atr, u8 page, u8 cx, u8 cy) {
    sa_frame[y - 25][x].atr = atr;
    sa_frame[y - 25][x].page = page;
    sa_frame[y - 25][x].cx = cx;
    sa_frame[y - 25][x].cy = cy;
}

void scfont_sqput(u16 x, u16 y, u8 atr, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2, u16 priority) {
    s32 u1;
    s32 u2;
    s32 v1;
    s32 v2;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);

    scrscrntex[0].col = scrscrntex[3].col = -1;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[priority];
    njSetPaletteBankNumG(page, atr & 0x3F);
    x = x * 8;
    y = y * 8;
    u1 = cx1 * 8;
    u2 = u1 + (cx2 * 8);
    v1 = cy1 * 8;
    v2 = v1 + (cy2 * 8);

    if (atr & 0x80) {
        scrscrntex[3].u = (u1 - 0.5f) / 256.0f;
        scrscrntex[0].u = (u2 - 0.5f) / 256.0f;
    } else {
        scrscrntex[0].u = (0.5f + u1) / 256.0f;
        scrscrntex[3].u = (0.5f + u2) / 256.0f;
    }

    if (atr & 0x40) {
        scrscrntex[3].v = (v1 - 0.5f) / 256.0f;
        scrscrntex[0].v = (v2 - 0.5f) / 256.0f;
    } else {
        scrscrntex[0].v = (0.5f + v1) / 256.0f;
        scrscrntex[3].v = (0.5f + v2) / 256.0f;
    }

    scrscrntex[0].x = x * Frame_Zoom_X;
    scrscrntex[3].x = Frame_Zoom_X * ((x) + (u2 - u1));
    scrscrntex[0].y = y * Frame_Zoom_Y;
    scrscrntex[3].y = Frame_Zoom_Y * ((y) + (v2 - v1));
    njDrawSprite(scrscrntex, 4, page, 1);
}

void scfont_sqput2(u16 x, u16 y, u8 atr, u8 inverse, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2) {
    u8 i;
    u8 j;

    if (inverse == 0) {
        for (j = 0; j < cy2; j++) {
            for (i = 0; i < cx2; i++) {
                sa_frame[y - 25 + j][x + i].atr = atr;
                sa_frame[y - 25 + j][x + i].page = page;
                sa_frame[y - 25 + j][x + i].cx = cx1 + i;
                sa_frame[y - 25 + j][x + i].cy = cy1 + j;
            }
        }
    } else {
        for (j = 0; j < cy2; j++) {
            for (i = 0; i < cx2; i++) {
                sa_frame[y - 25 + j][x + i].atr = atr;
                sa_frame[y - 25 + j][x + i].page = page;
                sa_frame[y - 25 + j][x + i].cx = (cx1 + (cx2 - 1)) - i;
                sa_frame[y - 25 + j][x + i].cy = cy1 + j;
            }
        }
    }
}

void scfont_sqput3(u16 x, u16 y, u8 atr, u8 page, u16 cx1, u16 cy1, u16 cx2, u16 cy2, u8 gr, u16 priority) {
    s32 u1;
    s32 u2;
    s32 v1;
    s32 v2;
    u8 i;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);

    for (i = 0; i < 4; i++) {
        scrscrntex[i].col = bigger_col_tbl[gr][i];
    }

    scrscrntex[0].z = scrscrntex[1].z = scrscrntex[2].z = scrscrntex[3].z = PrioBase[priority];
    njSetPaletteBankNumG(page, atr & 0x3F);
    u1 = cx1;
    u2 = u1 + cx2;
    v1 = cy1;
    v2 = v1 + cy2;
    scrscrntex[0].u = scrscrntex[1].u = (0.5f + u1) / 256.0f;
    scrscrntex[2].u = scrscrntex[3].u = (0.5f + u2) / 256.0f;
    scrscrntex[0].v = scrscrntex[2].v = (0.5f + v1) / 256.0f;
    scrscrntex[1].v = scrscrntex[3].v = (0.5f + v2) / 256.0f;
    scrscrntex[0].x = scrscrntex[1].x = x * Frame_Zoom_X;
    scrscrntex[2].x = scrscrntex[3].x = Frame_Zoom_X * (x + (u2 - u1));
    scrscrntex[0].y = scrscrntex[2].y = y * Frame_Zoom_Y;
    scrscrntex[1].y = scrscrntex[3].y = Frame_Zoom_Y * (y + (v2 - v1));
    njDrawTexture(scrscrntex, 4, page, 1);
}

void sc_clear(u16 sposx, u16 sposy, u16 eposx, u16 eposy) {
    u16 i;
    u16 j;

    for (j = 0; j < (eposy - sposy) + 1; j++) {
        for (i = 0; i < (eposx - sposx) + 1; i++) {
            sa_frame[sposy - 25 + j][sposx + i].atr = 0;
            sa_frame[sposy - 25 + j][sposx + i].page = 0;
            sa_frame[sposy - 25 + j][sposx + i].cx = 0;
            sa_frame[sposy - 25 + j][sposx + i].cy = 0;
        }
    }
}

void vital_put(u8 Pl_Num, s8 atr, s16 vital, u8 kind, u16 priority) {
    if (No_Trans) {
        return;
    }

    if (vital == 0) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);

    if (vital == -1) {
        vital = 0;
    }

    scrscrntex[0].z = scrscrntex[3].z = PrioBase[priority];
    njSetPaletteBankNumG(0U, atr & 0x3F);

    if (kind) {
        scrscrntex[0].u = 0.0f;
        scrscrntex[3].u = 0.03125f;
        scrscrntex[0].v = 0.25195312f;
        scrscrntex[3].v = 0.28320312f;
    } else {
        scrscrntex[0].u = 0.0f;
        scrscrntex[3].u = 0.03125f;
        scrscrntex[0].v = 0.28320312f;
        scrscrntex[3].v = 0.31445312f;
    }

    if (Pl_Num == 0) {
        scrscrntex[0].x = (168 - vital) * Frame_Zoom_X;
        scrscrntex[3].x = 168.0f * Frame_Zoom_X;
    } else {
        scrscrntex[0].x = 216.0f * Frame_Zoom_X;
        scrscrntex[3].x = (vital + 216) * Frame_Zoom_X;
    }

    scrscrntex[0].y = 16.0f * Frame_Zoom_Y;
    scrscrntex[3].y = 24.0f * Frame_Zoom_Y;
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    njDrawSprite(scrscrntex, 4, 0, 1);
}

void silver_vital_put(u8 Pl_Num) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[2];
    njSetPaletteBankNumG(0, 9);
    scrscrntex[0].u = 0.875f;
    scrscrntex[3].u = 0.90625f;
    scrscrntex[0].v = 0.6894531f;
    scrscrntex[3].v = 0.7207031f;

    if (Pl_Num == 0) {
        scrscrntex[0].x = 8.0f * Frame_Zoom_X;
        scrscrntex[3].x = 168.0f * Frame_Zoom_X;
    } else {
        scrscrntex[0].x = 216.0f * Frame_Zoom_X;
        scrscrntex[3].x = 376.0f * Frame_Zoom_X;
    }

    scrscrntex[0].y = 16.0f * Frame_Zoom_Y;
    scrscrntex[3].y = 24.0f * Frame_Zoom_Y;
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    njDrawSprite(scrscrntex, 4, 0, 1);
}

void vital_base_put(u8 Pl_Num) {
    PAL_CURSOR vtx;
    PAL_CURSOR_P pos[4];
    PAL_CURSOR_COL col;

    if (No_Trans || SA_shadow_on) {
        return;
    }

    njColorBlendingMode(0, 1);
    vtx.p = pos;
    vtx.col = &col;
    col.color = 0x40000000;

    if (Pl_Num == 0) {
        pos[0].x = 8.0f * Frame_Zoom_X;
        pos[3].x = 168.0f * Frame_Zoom_X;
    } else {
        pos[0].x = 216.0f * Frame_Zoom_X;
        pos[3].x = 376.0f * Frame_Zoom_X;
    }

    pos[0].y = 18.0f * Frame_Zoom_Y;
    pos[3].y = 23.0f * Frame_Zoom_Y;
    pos[1].x = pos[3].x;
    pos[1].y = pos[0].y;
    pos[2].x = pos[0].x;
    pos[2].y = pos[3].y;
    njDrawPolygon2D(&vtx, 4, PrioBase[4], 96);
}

void spgauge_base_put(u8 Pl_Num, s16 len) {
    PAL_CURSOR vtx;
    PAL_CURSOR_P pos[4];
    PAL_CURSOR_COL col;

    if (omop_cockpit == 0) {
        return;
    }

    if (omop_sa_bar_disp[Pl_Num] == 0) {
        return;
    }

    if (No_Trans || SA_shadow_on) {
        return;
    }

    njColorBlendingMode(0, 1);
    vtx.p = pos;
    vtx.col = &col;
    col.color = 0x80000000;

    if (Pl_Num == 0) {
        pos[0].x = 48.0f * Frame_Zoom_X;
        pos[3].x = Frame_Zoom_X * ((len * 8) + 48);
    } else {
        pos[0].x = 336.0f * Frame_Zoom_X;
        pos[3].x = Frame_Zoom_X * (336 - (len * 8));
    }

    pos[0].y = 210.0f * Frame_Zoom_Y;
    pos[3].y = 217.0f * Frame_Zoom_Y;
    pos[1].x = pos[3].x;
    pos[1].y = pos[0].y;
    pos[2].x = pos[0].x;
    pos[2].y = pos[3].y;
    njDrawPolygon2D(&vtx, 4, PrioBase[4], 96);
}

void stun_put(u8 Pl_Num, u8 stun) {
    if (No_Trans) {
        return;
    }

    if (stun == 0) {
        return;
    }

    if (omop_st_bar_disp[Pl_Num] == 0) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[4];
    njSetPaletteBankNumG(0, 10);
    scrscrntex[0].u = 0.0f;
    scrscrntex[3].u = 0.03125f;
    scrscrntex[0].v = 0.37695312f;
    scrscrntex[3].v = 0.40820312f;

    if (Pl_Num == 0) {
        scrscrntex[0].x = (168 - stun) * Frame_Zoom_X;
        scrscrntex[3].x = 168.0f * Frame_Zoom_X;
    } else {
        scrscrntex[0].x = 216.0f * Frame_Zoom_X;
        scrscrntex[3].x = (stun + 216) * Frame_Zoom_X;
    }

    scrscrntex[0].y = 24.0f * Frame_Zoom_Y;
    scrscrntex[3].y = 32.0f * Frame_Zoom_Y;
    scrscrntex[0].col = scrscrntex[3].col = -1;
    njDrawSprite(scrscrntex, 4, 0, 0);
}

void stun_base_put(u8 Pl_Num, s16 len) {
    PAL_CURSOR vtx;
    PAL_CURSOR_P pos[4];
    PAL_CURSOR_COL col;

    if (No_Trans || SA_shadow_on) {
        return;
    }

    njColorBlendingMode(0, 1);
    vtx.p = pos;
    vtx.col = &col;
    col.color = 0x90000000;

    if (Pl_Num == 0) {
        pos[0].x = Frame_Zoom_X * (168 - (len * 8));
        pos[3].x = 168.0f * Frame_Zoom_X;
    } else {
        pos[0].x = 216.0f * Frame_Zoom_X;
        pos[3].x = Frame_Zoom_X * ((len * 8) + 216);
    }

    pos[0].y = 25.0f * Frame_Zoom_Y;
    pos[3].y = 31.0f * Frame_Zoom_Y;
    pos[1].x = pos[3].x;
    pos[1].y = pos[0].y;
    pos[2].x = pos[0].x;
    pos[2].y = pos[3].y;
    njDrawPolygon2D(&vtx, 4, PrioBase[4], 96);
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", WipeInit);
#else
void WipeInit() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", WipeOut);
#else
s32 WipeOut(u8 type) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", WipeIn);
#else
s32 WipeIn(u8 type) {
    not_implemented(__func__);
}
#endif

void FadeInit() {
    FadeLimit = 1;
}

s32 FadeOut(u8 type, u8 step, u8 priority) {
    PAL_CURSOR fade_pc;
    PAL_CURSOR_P fade_p[4];
    PAL_CURSOR_COL fade_col[4];
    u32 Alpha;
    u8 i;
    u8 flag;

    Alpha = 0xFF000000;
    flag = 0;

    if (No_Trans) {
        return 0;
    }

    njColorBlendingMode(0, 1);
    fade_pc.p = fade_p;
    fade_pc.col = fade_col;
    fade_pc.num = 4;

    if ((FadeLimit * step) < 255) {
        Alpha = (FadeLimit * step) << 24;
    } else {
        flag = 1;
    }

    if (type == 0) {
        Alpha |= 0x00FFFFFF;
    }

    for (i = 0; i < 4; i++) {
        fade_p[i].x = Fade_Pos_tbl[i * 2];
        fade_p[i].y = Fade_Pos_tbl[i * 2 + 1];
        fade_col[i].color = Alpha;
    }

    njDrawPolygon2D(&fade_pc, 4, PrioBase[priority], 0x60);

    if (flag) {
        return 1;
    }

    FadeLimit += 1;
    return 0;
}

s32 FadeIn(u8 type, u8 step, u8 priority) {
    PAL_CURSOR fade_pc;
    PAL_CURSOR_P fade_p[4];
    PAL_CURSOR_COL fade_col[4];
    u32 Alpha;
    u8 i;
    u8 flag;

    Alpha = 0;
    flag = 0;

    if (No_Trans) {
        return 0;
    }

    njColorBlendingMode(0, 1);
    fade_pc.p = fade_p;
    fade_pc.col = fade_col;
    fade_pc.num = 4;

    if (FadeLimit * step < 255) {
        Alpha = (255 - FadeLimit * step) << 24;
    } else {
        flag = 1;
    }

    if (type == 0) {
        Alpha |= 0x00FFFFFF;
    }

    for (i = 0; i < 4; i++) {
        fade_p[i].x = Fade_Pos_tbl[i * 2];
        fade_p[i].y = Fade_Pos_tbl[i * 2 + 1];
        fade_col[i].color = Alpha;
    }

    njDrawPolygon2D(&fade_pc, 4, PrioBase[priority], 0x60);

    if (flag) {
        return 1;
    }

    FadeLimit += 1;
    return 0;
}

void ToneDown(u8 tone, u8 priority) {
    PAL_CURSOR tone_pc;
    PAL_CURSOR_P tone_p[4];
    PAL_CURSOR_COL tone_col[4];
    u8 i;

    if (No_Trans) {
        return;
    }

    njColorBlendingMode(0, 1);
    tone_pc.p = tone_p;
    tone_pc.col = tone_col;
    tone_pc.num = 4;

    for (i = 0; i < 4; i++) {
        tone_p[i].x = Fade_Pos_tbl[i * 2];
        tone_p[i].y = Fade_Pos_tbl[i * 2 + 1];
        tone_col[i].color = tone << 24;
    }

    njDrawPolygon2D(&tone_pc, 4, PrioBase[priority], 0x60);
}

void player_name() {
    u8 pl1;
    u8 pl2;

    if (omop_cockpit == 0) {
        return;
    }

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    pl1 = My_char[0];
    pl2 = My_char[1];
    pl1 += chkNameAkuma(pl1, 6);
    pl2 += chkNameAkuma(pl2, 6);
    scfont_sqput(6, 3, 1, 1, Player_Name_Pos_TBL[pl1][0], Player_Name_Pos_TBL[pl1][1], 5, 1, 2);
    scfont_sqput(37, 3, 1, 1, Player_Name_Pos_TBL[pl2][0], Player_Name_Pos_TBL[pl2][1], 5, 1, 2);
}

void stun_mark_write(u8 Pl_Num, s16 Len) {
    s16 tlen;

    if (No_Trans) {
        return;
    }

    if (omop_st_bar_disp[Pl_Num] == 0) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    tlen = Len - 7;
    scfont_sqput(
        smark_pos_tbl[tlen][Pl_Num], 3, 10, 0, (smark_kind_tbl[tlen] * 4) + 1, 2, smark_kind_tbl[tlen] + 4, 1, 2);
}

void max_mark_write(s8 Pl_Num, u8 Gauge_Len, u8 Mchar, u8 Mass_Len) {
    if (Pl_Num == 0) {
        scfont_sqput2(Mass_Len + 6, 26, 17, 0, 0, Max_Pos_TBL[Mchar - 5][0], Max_Pos_TBL[Mchar - 5][1], Mchar, 1);
    } else {
        scfont_sqput2(
            42 - Gauge_Len + Mass_Len, 26, 17, 0, 0, Max_Pos_TBL[Mchar - 5][0], Max_Pos_TBL[Mchar - 5][1], Mchar, 1);
    }
}

void SF3_logo(u8 step) {
    s32 i;
    Vertex pos[4];

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    njColorBlendingMode(0, 1);
    njSetPaletteBankNumG(0, 29);
    pos[0].z = pos[1].z = pos[2].z = pos[3].z = PrioBase[2];

    if (step < 9) {
        pos[0].x = pos[1].x = 128.0f;
        pos[2].y = pos[3].y = 128.0f;
        pos[0].s = pos[1].s = (0.5f + pos[0].x) / 256.0f;
        pos[2].t = pos[3].t = 0.9394531f;

        for (i = 48; i > 0; i -= 8) {
            pos[0].y = i + 80;
            pos[1].y = pos[0].y - step;
            pos[2].x = 176 - i;
            pos[3].x = pos[2].x + step;
            pos[0].t = (0.5f + (i + 192)) / 256.0f;
            pos[1].t = (0.5f + ((i + 192) - step)) / 256.0f;
            pos[2].s = (0.5f + (176 - i)) / 256.0f;
            pos[3].s = (0.5f + ((176 - i) + step)) / 256.0f;
            ppgWriteQuadWithST_B(pos, -1, NULL, 0, -1);
        }

        pos[0].y = pos[1].y = 80.0f;
        pos[2].y = pos[3].y = 128.0f;
        pos[0].t = pos[1].t = 0.7519531f;
        pos[2].t = pos[3].t = 0.9394531f;

        for (i = 128; i < 208; i += 8) {
            pos[0].x = i;
            pos[1].x = i + step;
            pos[2].x = 48.0f + pos[0].x;
            pos[3].x = 48.0f + pos[1].x;
            pos[0].s = (0.5f + pos[0].x) / 256.0f;
            pos[1].s = (0.5f + pos[1].x) / 256.0f;
            pos[2].s = (0.5f + pos[2].x) / 256.0f;
            pos[3].s = (0.5f + pos[3].x) / 256.0f;
            ppgWriteQuadWithST_B(pos, -1, NULL, 0, -1);
        }

        pos[0].y = pos[1].y = 80.0f;
        pos[2].x = pos[3].x = 256.0f;
        pos[0].t = pos[1].t = 0.7519531f;
        pos[2].s = pos[3].s = 1.0019531f;

        for (i = 0; i < 48; i += 8) {
            pos[0].x = i + 208;
            pos[1].x = pos[0].x + step;
            pos[2].y = 128 - i;
            pos[3].y = pos[2].y - step;
            pos[0].s = (0.5f + pos[0].x) / 256.0f;
            pos[1].s = (0.5f + pos[1].x) / 256.0f;
            pos[2].t = (0.5f + (240 - i)) / 256.0f;
            pos[3].t = (0.5f + ((240 - i) - step)) / 256.0f;
            ppgWriteQuadWithST_B(pos, -1, NULL, 0, -1);
        }
    } else {
        step -= 8;
        pos[0].x = pos[1].x = 128.0f;
        pos[2].y = pos[3].y = 128.0f;
        pos[0].s = pos[1].s = (0.5f + pos[0].x) / 256.0f;
        pos[2].t = pos[3].t = 0.9394531f;

        for (i = 40; i >= 0; i -= 8) {
            pos[1].y = i + 80;
            pos[0].y = (8.0f + pos[1].y) - step;
            pos[3].x = (176 - i);
            pos[2].x = (pos[3].x - 8.0f) + step;
            pos[0].t = (0.5f + ((i + 200) - step)) / 256.0f;
            pos[1].t = (0.5f + (i + 192)) / 256.0f;
            pos[2].s = (0.5f + ((168 - i) + step)) / 256.0f;
            pos[3].s = (0.5f + (176 - i)) / 256.0f;
            ppgWriteQuadWithST_B(pos, -1, NULL, 0, -1);
        }

        pos[0].y = pos[1].y = 80.0f;
        pos[2].y = pos[3].y = 128.0f;
        pos[0].t = pos[1].t = 0.7519531f;
        pos[2].t = pos[3].t = 0.9394531f;

        for (i = 128; i < 208; i += 8) {
            pos[0].x = (i + step);
            pos[1].x = (i + 8);
            pos[2].x = 48.0f + pos[0].x;
            pos[3].x = 48.0f + pos[1].x;
            pos[0].s = (0.5f + pos[0].x) / 256.0f;
            pos[1].s = (0.5f + pos[1].x) / 256.0f;
            pos[2].s = (0.5f + pos[2].x) / 256.0f;
            pos[3].s = (0.5f + pos[3].x) / 256.0f;
            ppgWriteQuadWithST_B(pos, -1, NULL, 0, -1);
        }

        pos[0].y = pos[1].y = 80.0f;
        pos[2].x = pos[3].x = 256.0f;
        pos[0].t = pos[1].t = 0.7519531f;
        pos[2].s = pos[3].s = 1.0019531f;

        for (i = 0; i < 48; i += 8) {
            pos[0].x = i + 208 + step;
            pos[1].x = i + 216;
            pos[2].y = 128 - i - step;
            pos[3].y = 120 - i;
            pos[0].s = (0.5f + pos[0].x) / 256.0f;
            pos[1].s = (0.5f + pos[1].x) / 256.0f;
            pos[2].t = (0.5f + (240 - i - step)) / 256.0f;
            pos[3].t = (0.5f + (232 - i)) / 256.0f;
            ppgWriteQuadWithST_B(pos, -1, NULL, 0, -1);
        }
    }
}

void player_face_init() {}

void scfont_sqput_face(u16 x, u16 y, u16 atr, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2, u16 priority) {
    s32 u1;
    s32 u2;
    s32 v1;
    s32 v2;

    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[priority];
    njSetPaletteBankNumG(0, atr & 0x3FFF);
    x = x * 8;
    y = y * 8;
    u1 = cx1 * 8;
    u2 = u1 + (cx2 * 8);
    v1 = cy1 * 8;
    v2 = v1 + (cy2 * 8);

    if (atr & 0x8000) {
        scrscrntex[3].u = (u1 - 0.5f) / 256.0f;
        scrscrntex[0].u = (u2 - 0.5f) / 256.0f;
    } else {
        scrscrntex[0].u = (0.5f + u1) / 256.0f;
        scrscrntex[3].u = (0.5f + u2) / 256.0f;
    }

    if (atr & 0x4000) {
        scrscrntex[3].v = (v1 - 0.5f) / 256.0f;
        scrscrntex[0].v = (v2 - 0.5f) / 256.0f;
    } else {
        scrscrntex[0].v = (0.5f + v1) / 256.0f;
        scrscrntex[3].v = (0.5f + v2) / 256.0f;
    }

    scrscrntex[0].x = x * Frame_Zoom_X;
    scrscrntex[3].x = Frame_Zoom_X * (x + (u2 - u1));
    scrscrntex[0].y = y * Frame_Zoom_Y;
    scrscrntex[3].y = Frame_Zoom_Y * (y + (v2 - v1));
    njDrawSprite(scrscrntex, 4, page, 1);
}

void player_face() {
    u8 grade_tmp;

    if (omop_cockpit == 0) {
        return;
    }

    if (No_Trans) {
        return;
    }

    face_base_put();
    ppgSetupCurrentDataList(&ppgScrListFace);
    scfont_sqput_face(0,
                      3,
                      Player_Color[0] + (My_char[0] * 13),
                      0,
                      Face_Pos_TBL[My_char[0]][0],
                      Face_Pos_TBL[My_char[0]][1],
                      5,
                      3,
                      2);

    if (My_char[1] == 0) {
        scfont_sqput_face(0x2B,
                          3,
                          (Player_Color[1] + (My_char[1] * 13)) | 0x8000,
                          0,
                          Face_Pos_TBL[20][0],
                          Face_Pos_TBL[20][1],
                          5,
                          3,
                          2);
    } else {
        scfont_sqput_face(0x2B,
                          3,
                          (Player_Color[1] + (My_char[1] * 13)) | 0x8000,
                          0,
                          Face_Pos_TBL[My_char[1]][0],
                          Face_Pos_TBL[My_char[1]][1],
                          5,
                          3,
                          2);
    }

    ppgSetupCurrentDataList(&ppgScrList);
    scfont_put(5, 3, 1, 0, 0, 19, 2);
    scfont_put(5, 4, 1, 0, 0, 20, 2);
    scfont_put(42, 3, 129, 0, 0, 19, 2);
    scfont_put(42, 4, 129, 0, 0, 20, 2);

    if (Play_Type == 0) {
        return;
    }

    if (Keep_Grade[Champion] == 0) {
        return;
    }

    grade_tmp = Keep_Grade[Champion] - 1;

    if (grade_tmp < 0x18) {
        scfont_sqput((Champion * 41) + 1, 1, 27, 2, Grade_Pos_TBL[grade_tmp][0], Grade_Pos_TBL[grade_tmp][1], 5, 1, 2);
    } else {
        scfont_sqput((Champion * 41) + 1, 1, 28, 2, Grade_Pos_TBL[grade_tmp][0], Grade_Pos_TBL[grade_tmp][1], 5, 1, 2);
    }
}

void face_base_put() {
    PAL_CURSOR vtx;
    PAL_CURSOR_P pos[4];
    PAL_CURSOR_COL col;

    if (No_Trans || SA_shadow_on) {
        return;
    }

    njColorBlendingMode(0, 1);
    vtx.p = pos;
    vtx.col = &col;
    col.color = 0x50000000;
    pos[0].x = 5.6f * Frame_Zoom_X;
    pos[3].x = 34.4f * Frame_Zoom_X;
    pos[0].y = 25.0f * Frame_Zoom_Y;
    pos[3].y = 45.0f * Frame_Zoom_Y;
    pos[1].x = pos[3].x;
    pos[1].y = pos[0].y;
    pos[2].x = pos[0].x;
    pos[2].y = pos[3].y;
    njDrawPolygon2D(&vtx, 4, PrioBase[4], 0x60);
    pos[0].x = 348.8f * Frame_Zoom_X;
    pos[3].x = 377.6f * Frame_Zoom_X;
    pos[1].x = pos[3].x;
    pos[2].x = pos[0].x;
    njDrawPolygon2D(&vtx, 4, PrioBase[4], 0x60);
}

void hnc_set(u8 num, u8 atr) {
    u8 i;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[2];
    njSetPaletteBankNumG(1, atr & 0x3F);
    njColorBlendingMode(0, 1);

    for (i = 0; i < 2; i++) {
        if (i) {
            scrscrntex[0].u = 0.001953125f;
            scrscrntex[3].u = (0.5f + (num * 8)) / 256.0f;
            scrscrntex[0].v = 0.37695312f;
            scrscrntex[3].v = 0.47070312f;
            scrscrntex[0].x = 184.0f * Frame_Zoom_X;
            scrscrntex[3].x = Frame_Zoom_X * ((num + 0x17) * 8);
        } else {
            scrscrntex[0].u = (0.5f + ((0x17 - num) * 8)) / 256.0f;
            scrscrntex[3].u = 0.7207031f;
            scrscrntex[0].v = 0.28320312f;
            scrscrntex[3].v = 0.37695312f;
            scrscrntex[0].x = Frame_Zoom_X * ((0x17 - num) * 8);
            scrscrntex[3].x = 184.0f * Frame_Zoom_X;
        }

        scrscrntex[0].y = 88.0f * Frame_Zoom_Y;
        scrscrntex[3].y = 112.0f * Frame_Zoom_Y;
        scrscrntex[0].col = scrscrntex[3].col = -1;
        njDrawSprite(scrscrntex, 4, 1, 1);
    }
}

void hnc_wipeinit(u8 atr) {
    Polygon dmyvtx[4];
    u8 i;
    u8 j;
    u8 k;

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    Hnc_Num = 0;
    scrscrntex[0].z = scrscrntex[1].z = scrscrntex[2].z = scrscrntex[3].z = PrioBase[2];
    njSetPaletteBankNumG(1, atr & 0x3F);
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[1].col = scrscrntex[2].col = scrscrntex[3].col = -1;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 26; j++) {
            for (k = 0; k < 4; k++) {
                scrscrntex[k].u = hnc_wipe_tbl1[j][k * 2] / 256.0f;
                scrscrntex[k].v = ((i * 0x18) + hnc_wipe_tbl1[j][(k * 2) + 1]) / 256.0f;
                scrscrntex[k].x = Frame_Zoom_X * ((i * 0xB8) + hnc_wipe_tbl1[j][k * 2]);
                scrscrntex[k].y = Frame_Zoom_Y * (hnc_wipe_tbl1[j][(k * 2) + 1] + 0x10);
                dmyvtx[k] = scrscrntex[k];
            }

            if (!No_Trans) {
                njDrawTexture(dmyvtx, 4, 1, 1);
            }
        }
    }
}

s32 hnc_wipeout(u8 atr) {
    Polygon vtx[4];
    u8 i;
    u8 j;
    u8 k;
    s32 ipx;
    s32 ipy;
    s32 ipu;
    s32 ipv;
    s32 len;

    if (!No_Trans) {
        ppgSetupCurrentDataList(&ppgScrList);
        setFilterMode(0);
        njSetPaletteBankNumG(1, atr & 0x3F);
        njColorBlendingMode(0, 1);
        vtx[0].z = vtx[1].z = vtx[2].z = vtx[3].z = PrioBase[2];
        vtx[0].col = vtx[1].col = vtx[2].col = vtx[3].col = -1;
        ipx = 8;
        ipy = 88;
        ipu = 8;
        ipv = 72;
        len = 8 - Hnc_Num;

        for (i = 0; i < 2; i++) {
            for (j = 0; j < 23; j++) {
                vtx[0].x = ipx;
                vtx[1].x = vtx[0].x - len;
                vtx[2].x = 16.0f + vtx[0].x;
                vtx[3].x = vtx[2].x - len;
                vtx[0].y = vtx[1].y = ipy;
                vtx[2].y = vtx[3].y = ipy + 24;
                vtx[0].u = ipu;
                vtx[1].u = vtx[0].u - len;
                vtx[2].u = 16.0f + vtx[0].u;
                vtx[3].u = vtx[2].u - len;
                vtx[0].v = vtx[1].v = ipv;
                vtx[2].v = vtx[3].v = ipv + 24;

                for (k = 0; k < 4; k++) {
                    vtx[k].x *= Frame_Zoom_X;
                    vtx[k].y *= Frame_Zoom_Y;
                    vtx[k].u /= 256.0f;
                    vtx[k].v /= 256.0f;
                }

                njDrawTexture(vtx, 4, 1, 1);
                ipx += 8;
                ipu += 8;
            }

            ipu = 8;
            ipv += 24;
        }

        ipx = 184;
        ipu = 0;
        ipv -= 24;

        for (j = 0; j < 2; j++) {
            vtx[0].x = vtx[1].x = ipx;
            vtx[2].x = vtx[0].x + (16 - (j * 8));
            vtx[3].x = vtx[2].x - len;
            vtx[0].y = ipy;
            vtx[1].y = vtx[0].y + ((24.0f * len) / 16.0f);
            vtx[2].y = vtx[3].y = vtx[0].y + (0x18 - (j * 12));
            vtx[0].u = vtx[1].u = ipu;
            vtx[2].u = vtx[0].u + (16 - (j * 8));
            vtx[3].u = vtx[2].u - len;
            vtx[0].v = ipv;
            vtx[1].v = vtx[0].v + ((24.0f * len) / 16.0f);
            vtx[2].v = vtx[3].v = vtx[0].v + (24 - (j * 12));

            for (k = 0; k < 4; k++) {
                vtx[k].x *= Frame_Zoom_X;
                vtx[k].y *= Frame_Zoom_Y;
                vtx[k].u /= 256.0f;
                vtx[k].v /= 256.0f;
            }

            njDrawTexture(vtx, 4, 1, 1);
            ipy += 12;
            ipv += 12;
        }
    }

    Hnc_Num++;

    if (Hnc_Num == 8) {
        return 1;
    }

    return 0;
}

void ci_set(u8 type, u8 atr) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    scfont_sqput(ci_tbl[type][4],
                 ci_tbl[type][5],
                 atr,
                 cip_tbl[type],
                 ci_tbl[type][0],
                 ci_tbl[type][1],
                 ci_tbl[type][2],
                 ci_tbl[type][3],
                 2);
}

void nw_set(u8 PL_num, u8 atr) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    PL_num += chkNameAkuma(PL_num, 6);
    scfont_sqput(nwdata_tbl[PL_num][3],
                 9,
                 atr,
                 nwdata_tbl[PL_num][4],
                 nwdata_tbl[PL_num][0],
                 nwdata_tbl[PL_num][1],
                 nwdata_tbl[PL_num][2],
                 4,
                 2);
    scfont_sqput(nwdata_tbl[PL_num][5], 9, atr, 2, 17, 22, 13, 4, 2);
}

void score8x16_put(u16 x, u16 y, u8 atr, u8 chr) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    scfont_sqput(x, y, atr, 0, chr, 6, 1, 2, 2);
}

void score16x24_put(u16 x, u16 y, u8 atr, u8 chr) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    scfont_sqput(x, y, atr, 2, chr * 2, 6, 2, 3, 2);
}

void combo_message_set(u8 pl, u8 kind, u8 x, u8 num, u8 hi, u8 low) {
    u8 xw;
    u8 xw2;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    if (num > combo_mtbl[kind][2]) {
        xw = combo_mtbl[kind][2];
    } else {
        xw = num;
    }

    if (num > combo_mtbl[kind][2]) {
        xw2 = (num - (combo_mtbl[kind][2]));
    } else {
        xw2 = 0;
    }

    switch (kind) {
    case 2:
    case 1:
    case 0:
        if (pl == 0) {
            if (hi != 0) {
                scfont_sqput(x, 7, 8, 0, hi, 6, 1, 2, 2);
            }

            if (num > 1) {
                scfont_sqput(x + 1, 7, 8, 0, low, 6, 1, 2, 2);
            }

            if (num > 3) {
                scfont_sqput(x + 3, 7, 8, 2, combo_mtbl[kind][0], combo_mtbl[kind][1], xw, 2, 2);
                return;
            }
        } else {
            scfont_sqput(xw2, 7, 8, 2, (combo_mtbl[kind][0] + combo_mtbl[kind][2]) - xw, combo_mtbl[kind][1], xw, 2, 2);
            if (xw2 > 1) {
                scfont_sqput(xw2 - 2, 7, 8, 0, low, 6, 1, 2, 2);
            }

            if ((xw2 > 2) && (hi != 0)) {
                scfont_sqput(xw2 - 3, 7, 8, 0, hi, 6, 1, 2, 2);
                return;
            }
        }
        break;

    case 3:
    case 4:
    case 5:
    case 6:
        if (pl == 0) {
            scfont_sqput(x, 7, 8, 2, combo_mtbl[kind][0], combo_mtbl[kind][1], xw, 2, 2);
        } else {
            scfont_sqput(xw2, 7, 8, 2, (combo_mtbl[kind][0] + combo_mtbl[kind][2]) - xw, combo_mtbl[kind][1], xw, 2, 2);
        }
    }
}

void combo_pts_set(u8 pl, u8 x, u8 num, s8 *pts, s8 digit) {
    s8 i;
    s8 j;

    s8 assign1;
    u8 assign2;
    u8 assign3;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);

    if (pl == 0) {
        for (i = digit, assign1 = j = 1; i >= 0; i--, j++, assign2 = x += 1) {
            score8x16_put(x, 10, 8, pts[i]);

            if (num - j == 0) {
                return;
            }
        }

        if (num < digit + 1) {
            return;
        }

        score8x16_put(x, 10, 8, 0);

        if (num < digit + 2) {
            return;
        }

        score8x16_put(x + 1, 10, 8, 0);

        if (num < digit + 3) {
            return;
        }

        scfont_put(x + 2, 11, 8, 0, 6, 13, 2);

        if (num < digit + 4) {
            return;
        }

        scfont_put(x + 3, 11, 8, 0, 7, 13, 2);

    } else {
        scfont_put(x, 11, 8, 0, 7, 13, 2);

        if (num > 1) {
            scfont_put(x - 1, 11, 8, 0, 6, 13, 2);
        }

        if (num > 2) {
            score8x16_put(x - 2, 10, 8, 0);
        }

        if (num > 3) {
            score8x16_put(x - 3, 10, 8, 0);
        }

        if (num > 4) {
            for (i = 0; i <= digit; i++, assign3 = x -= 1) {
                score8x16_put(x - 4, 10, 8, pts[i]);

                if (num - i == 0) {
                    break;
                }
            }
        }
    }
}

void naming_set(u8 pl, s16 place, u16 atr, u16 chr) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    scfont_put(place + 13 + (pl * 27), 0, atr, 0, rankname_pos_tbl[chr][0], rankname_pos_tbl[chr][1], 2);
}

void stun_gauge_waku_write(s16 p1len, s16 p2len) {
    if (omop_cockpit == 0) {
        return;
    }

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);

    if (omop_st_bar_disp[0]) {
        scfont_sqput(21 - p1len, 3, 10, 0, 12 - p1len, p1len + 1, p1len, 1, 3);
    } else {
        silver_stun_put(0, p1len);
    }

    scfont_sqput(11, 3, 1, 0, 2, p1len + 1, 10 - p1len, 1, 3);

    if (omop_st_bar_disp[1]) {
        scfont_sqput(27, 3, 10, 0, 2, p2len + 12, p2len, 1, 3);
    } else {
        silver_stun_put(1, p2len);
    }

    scfont_sqput(p2len + 27, 3, 1, 0, p2len + 2, p2len + 12, 10 - p2len, 1, 3);
}

void silver_stun_put(u8 Pl_Num, s16 len) {
    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    setFilterMode(0);
    scrscrntex[0].z = scrscrntex[3].z = PrioBase[3];
    njSetPaletteBankNumG(0, 1);
    scrscrntex[0].u = 0.9375f;
    scrscrntex[3].u = 0.96875f;
    scrscrntex[0].v = 0.6894531f;
    scrscrntex[3].v = 0.7207031f;

    if (Pl_Num == 0) {
        scrscrntex[0].x = Frame_Zoom_X * ((21 - len) * 8);
        scrscrntex[3].x = 168.0f * Frame_Zoom_X;
    } else {
        scrscrntex[0].x = 216.0f * Frame_Zoom_X;
        scrscrntex[3].x = Frame_Zoom_X * ((len + 27) * 8);
    }

    scrscrntex[0].y = 24.0f * Frame_Zoom_Y;
    scrscrntex[3].y = 32.0f * Frame_Zoom_Y;
    njColorBlendingMode(0, 1);
    scrscrntex[0].col = scrscrntex[3].col = -1;
    njDrawSprite(scrscrntex, 4, 0, 1);
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", overwrite_panel);
#else
void overwrite_panel(u32 color, u8 priority) {
    not_implemented(__func__);
}
#endif

void sa_stock_trans(s16 St_Num, s16 Spg_Col, s8 Stpl_Num) {
    if (Stpl_Num == 0) {
        scfont_put2(3, 25, sa_color_data_tbl[Spg_Col], 2, St_Num + 21, 4);
        scfont_put2(3, 26, sa_color_data_tbl[Spg_Col], 2, St_Num + 21, 5);
    } else {
        scfont_put2(44, 25, sa_color_data_tbl[Spg_Col], 2, St_Num + 21, 4);
        scfont_put2(44, 26, sa_color_data_tbl[Spg_Col], 2, St_Num + 21, 5);
    }
}

void sa_fullstock_trans(s16 St_Num, s16 Spg_Col, s8 Stpl_Num) {
    if (Stpl_Num == 0) {
        scfont_put2(1, 26, sa_color_data_tbl[Spg_Col], 2, St_Num + 21, 6);
    } else {
        scfont_put2(46, 26, sa_color_data_tbl[Spg_Col], 2, St_Num + 21, 7);
    }
}

void sa_number_write(s8 Stpl_Num, u16 x) {
    if (Stpl_Num == 0) {
        if (My_char[0] == 0) {
            scfont_sqput2(x, 26, 14, 0, 2, 27, 2, 2, 2);
        } else {
            scfont_sqput2(x, 26, 14, 0, 2, (Super_Arts[0] * 2) + 21, 2, 2, 2);
        }
    } else if (My_char[1] == 0) {
        scfont_sqput2(x, 26, 142, 1, 2, 27, 2, 2, 2);
    } else {
        scfont_sqput2(x, 26, 142, 1, 2, (Super_Arts[1] * 2) + 21, 2, 2, 2);
    }
}

void sc_ram_to_vram(s8 sc_num) {
    u32 *sc_tbl_ptr;
    u8 *sc_pos_ptr;
    u8 *sc_uv_ptr;
    u16 loop;
    u16 i;

    sc_tbl_ptr = (u32 *)sc_ram_vram_tbl[sc_num];
    sc_pos_ptr = (u8 *)*sc_tbl_ptr;
    *sc_tbl_ptr++;
    sc_uv_ptr = (u8 *)*sc_tbl_ptr;
    loop = *sc_uv_ptr++;

    for (i = 0; i < loop; i++) {
        sa_frame[sc_pos_ptr[1] - 25][sc_pos_ptr[0]].atr = sa_ram_vram_col[sc_num][0];
        sa_frame[sc_pos_ptr[1] - 25][sc_pos_ptr[0]].page = sa_ram_vram_col[sc_num][1];
        sa_frame[sc_pos_ptr[1] - 25][sc_pos_ptr[0]].cx = *sc_uv_ptr++;
        sa_frame[sc_pos_ptr[1] - 25][sc_pos_ptr[0]].cy = *sc_uv_ptr++;
        sc_pos_ptr += 2;
    }
}

void sc_ram_to_vram_opc(s8 sc_num, s8 x, s8 y, u16 atr) {
    u32 *sc_tbl_ptr;
    u8 *sc_pos_ptr;
    u8 *sc_uv_ptr;
    u16 loop;
    u16 i;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    sc_tbl_ptr = (u32 *)sc_ram_vram_tbl[sc_num];
    sc_pos_ptr = (u8 *)*sc_tbl_ptr;
    *sc_tbl_ptr++;
    sc_uv_ptr = (u8 *)*sc_tbl_ptr;
    loop = *sc_uv_ptr++;

    for (i = 0; i < loop; i++) {
        scfont_put(
            sc_pos_ptr[0] + x, sc_pos_ptr[1] + y, atr, sa_ram_vram_col[sc_num][1], sc_uv_ptr[0], sc_uv_ptr[1], 3);
        sc_uv_ptr += 2;
        sc_pos_ptr += 2;
    }
}

void sq_paint_chenge(u16 x, u16 y, u16 sx, u16 sy, u16 atr) {
    u16 i;
    u16 j;

    for (j = 0; j < sy; j++) {
        for (i = 0; i < sx; i++) {
            sa_frame[y - 25 + j][x + i].atr = atr;
        }
    }
}

void fade_cont_init() {
    FadeInit();
    fd_dat.fade_kind = fade_data_tbl[Fade_Number][0];
    fd_dat.fade = fade_data_tbl[Fade_Number][1];
    fd_dat.fade_prio = fade_data_tbl[Fade_Number][2];
}

void fade_cont_main() {
    u8 flag = 0;

    switch (fd_dat.fade_kind) {
    case 0:
        flag = FadeIn(1, fd_dat.fade, fd_dat.fade_prio);
        break;

    case 1:
        flag = FadeOut(1, fd_dat.fade, fd_dat.fade_prio);
        break;

    case 2:
        flag = FadeIn(0, fd_dat.fade, fd_dat.fade_prio);
        break;

    case 3:
        flag = FadeOut(0, fd_dat.fade, fd_dat.fade_prio);
        break;
    }

    if (flag == 1) {
        Fade_Flag = 0;
    }
}

void Akaobi() {
    PAL_CURSOR apc;
    PAL_CURSOR_P ap[4];
    PAL_CURSOR_COL acol[4];
    u8 i;

    if (No_Trans) {
        return;
    }

    ppgSetupCurrentDataList(&ppgScrList);
    njColorBlendingMode(0, 1);
    apc.p = ap;
    apc.col = acol;
    apc.num = 4;

    for (i = 0; i < 4; i++) {
        ap[i].x = Akaobi_Pos_tbl[i * 2];
        ap[i].y = Akaobi_Pos_tbl[(i * 2) + 1];
        acol[i].color = 0xA0D00000;
    }

    njDrawPolygon2D(&apc, 4, PrioBase[2], 0x60);
}

void Training_Disp_Work_Clear() {
    u8 i;

    for (i = 0; i < 2; i++) {
        tr_data[i].max_hitcombo = 0;
        tr_data[i].new_max_flag = 0;
        tr_data[i].frash_flag = 0;
        tr_data[i].frash_switch = 2;
        tr_data[i].damage = 0;
        tr_data[i].total_damage = 0;
        tr_data[i].disp_total_damage = 0;
    }
}

void Training_Damage_Set(s16 damage, s16 arg1, u8 kezuri) {
    u8 j;

    if (Training_ID == 0) {
        j = 1;
    } else {
        j = 0;
    }

    if (damage == 0) {
        return;
    }

    tr_data[j].damage = damage;

    if (tr_data[j].damage > 999) {
        tr_data[j].damage = 999;
    }

    if (kezuri) {
        tr_data[j].disp_total_damage = damage;
        tr_data[j].total_damage = 0;
    } else {
        tr_data[j].total_damage = damage + tr_data[j].total_damage;
        tr_data[j].disp_total_damage = tr_data[j].total_damage;
    }

    if (tr_data[j].disp_total_damage > 999) {
        tr_data[j].disp_total_damage = 999;
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", Training_Data_Disp);
#else
void Training_Data_Disp() {
    not_implemented(__func__);
}
#endif

const u8 scrnAddTex1UV[9][4] = { { 96, 0, 32, 32 },  { 63, 0, 32, 32 },  { 0, 96, 32, 32 },
                                 { 0, 64, 32, 32 },  { 0, 0, 32, 32 },   { 31, 0, 32, 32 },
                                 { 32, 96, 32, 32 }, { 32, 64, 32, 32 }, { 128, 0, 96, 128 } };

void dispButtonImage(s32 px, s32 py, s32 pz, s32 sx, s32 sy, s32 cl, s32 ix) {
    PAL_CURSOR_COL oricol;
    Sprite prm;

    if (No_Trans) {
        return;
    }

    setFilterMode(0);
    oricol.color = -1;
    oricol.argb.a = (0xFF - cl);
    prm.texCode = ppgGetUsingTextureHandle(&ppgScrTex, 5) | (ppgGetUsingPaletteHandle(&ppgScrPalShot, 0) << 0x10);
    prm.v[0].x = px;
    prm.v[0].y = py;
    prm.v[3].x = (px + sx);
    prm.v[3].y = (py - sy);
    njCalcPoint(NULL, &prm.v[0], &prm.v[0]);
    njCalcPoint(NULL, &prm.v[3], &prm.v[3]);
    prm.v[0].z = prm.v[3].z = PrioBase[pz];
    prm.t[0].s = scrnAddTex1UV[ix][0] / 256.0f;
    prm.t[3].s = (scrnAddTex1UV[ix][0] + scrnAddTex1UV[ix][2]) / 256.0f;
    prm.t[0].t = scrnAddTex1UV[ix][1] / 128.0f;
    prm.t[3].t = (scrnAddTex1UV[ix][1] + scrnAddTex1UV[ix][3]) / 128.0f;
    flSetRenderState(FLRENDER_TEXSTAGE0, prm.texCode);
    ps2SeqsRenderQuadInit_A();
    ps2SeqsRenderQuad_A2(&prm, oricol.color);
    ps2SeqsRenderQuadEnd();
}

void dispButtonImage2(s32 px, s32 py, s32 pz, s32 sx, s32 sy, s32 cl, s32 ix) {
    PAL_CURSOR_COL oricol;
    Sprite prm;

    if (No_Trans) {
        return;
    }

    setFilterMode(0);
    oricol.color = -1;
    oricol.argb.a = (0xFF - cl);
    prm.texCode = ppgGetUsingTextureHandle(&ppgScrTex, 5) | (ppgGetUsingPaletteHandle(&ppgScrPalShot, 0) << 0x10);
    prm.v[0].x = px * Frame_Zoom_X;
    prm.v[0].y = py * Frame_Zoom_Y;
    prm.v[3].x = Frame_Zoom_X * (px + sx);
    prm.v[3].y = Frame_Zoom_Y * (py + sy);
    prm.v[0].z = prm.v[3].z = PrioBase[pz];
    prm.t[0].s = scrnAddTex1UV[ix][0] / 256.0f;
    prm.t[3].s = (scrnAddTex1UV[ix][0] + scrnAddTex1UV[ix][2]) / 256.0f;
    prm.t[0].t = scrnAddTex1UV[ix][1] / 128.0f;
    prm.t[3].t = (scrnAddTex1UV[ix][1] + scrnAddTex1UV[ix][3]) / 128.0f;
    flSetRenderState(FLRENDER_TEXSTAGE0, prm.texCode);
    ps2SeqsRenderQuadInit_A();
    ps2SeqsRenderQuad_A2(&prm, oricol.color);
    ps2SeqsRenderQuadEnd();
}

void dispSaveLoadTitle(void *ewk) {
    WORK *wk;
    PAL_CURSOR_COL oricol;
    Sprite prm;
    FLVec3 pos[2];
    f32 step_t;
    s32 i;

    if (No_Trans) {
        return;
    }

    setFilterMode(0);
    wk = (WORK *)ewk;
    mlt_obj_matrix(wk, 0);
    oricol.color = -1;
    oricol.argb.a = (0xFF - wk->my_clear_level);
    prm.texCode = ppgGetUsingTextureHandle(&ppgScrTex, 6) | (ppgGetUsingPaletteHandle(&ppgScrPalOpt, 0) << 0x10);
    flSetRenderState(FLRENDER_TEXSTAGE0, prm.texCode);
    prm.t[0].s = 0.0f;
    prm.t[3].s = 1.0f;
    prm.t[0].t = 0.00390625f;
    prm.t[3].t = 0.28515625f;
    step_t = 36.5f;
    pos[0].x = -192.0f;
    pos[0].y = -12.0f;
    pos[1].x = -64.0f;
    pos[1].y = -48.0f;
    pos[0].z = pos[1].z = 0.0f;

    for (i = 0; i < 3; i++) {
        njCalcPoint(NULL, (Vec3 *)&pos[0], &prm.v[0]);
        njCalcPoint(NULL, (Vec3 *)&pos[1], &prm.v[3]);
        ps2SeqsRenderQuadInit_A();
        ps2SeqsRenderQuad_A2(&prm, oricol.color);
        ps2SeqsRenderQuadEnd();
        step_t += 36.0f;
        prm.t[0].t = prm.t[3].t;
        prm.t[3].t = step_t / 128.0f;
        pos[0].x += 128.0f;
        pos[1].x += 128.0f;
    }
}
