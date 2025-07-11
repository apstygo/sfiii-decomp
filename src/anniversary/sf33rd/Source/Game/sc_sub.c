#include "sf33rd/Source/Game/sc_sub.h"
#include "common.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "sf33rd/Source/Common/PPGFile.h"
#include "sf33rd/Source/Common/PPGWork.h"
#include "sf33rd/Source/Game/AcrUtil.h"
#include "sf33rd/Source/Game/DC_Ghost.h"
#include "sf33rd/Source/Game/GD3rd.h"
#include "sf33rd/Source/Game/MTRANS.h"
#include "sf33rd/Source/Game/RAMCNT.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/sc_data.h"
#include "sf33rd/Source/Game/workuser.h"
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
    loadSize = load_it_use_any_key2(10, &loadAdrs, &key, 2, 0);

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

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", Sa_frame_Clear2);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", Sa_frame_Write);
#else
void Sa_frame_Write() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", SSPutStrTexInput);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", SSPutStrTexInput2);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", SSPutStr);
#else
void SSPutStr(u16 x, u16 y, u8 atr, s8 *str) {
    not_implemented(__func__);
}
#endif

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

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", SSPutStr2);
#else
void SSPutStr2(u16 x, u16 y, u8 atr, s8 *str) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", SSPutStrTexInputB);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", SSPutStrTexInputB2);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", SSPutStr_Bigger);
#else
void SSPutStr_Bigger(u16 x, u16 y, u8 atr, s8 *str, f32 sc, u8 gr, u16 priority) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", SSPutDec);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", SSPutDec3);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", scfont_put);
#else
void scfont_put(u16 x, u16 y, u8 atr, u8 page, u8 cx, u8 cy, u16 priority) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", scfont_put2);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", scfont_sqput);
#else
void scfont_sqput(u16 x, u16 y, u8 atr, u8 page, u8 cx1, u8 cy1, u8 cx2, u8 cy2, u16 priority) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", scfont_sqput2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", scfont_sqput3);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", sc_clear);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", vital_put);
#else
void vital_put(u8 Pl_Num, s8 atr, s16 vital, u8 kind, u16 priority) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", silver_vital_put);
#else
void silver_vital_put(u8 Pl_Num) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", vital_base_put);
#else
void vital_base_put(u8 Pl_Num) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", spgauge_base_put);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", stun_put);
#else
void stun_put(u8 Pl_Num, u8 stun) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", stun_base_put);
#else
void stun_base_put(u8 Pl_Num, s16 len) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", WipeInit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", WipeOut);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", WipeIn);

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
        Alpha = ((u32)FadeLimit * (u32)step) << 24;
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
        Alpha = (255 - (u32)FadeLimit * (u32)step) << 24;
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

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", player_name);
#else
void player_name() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", stun_mark_write);
#else
void stun_mark_write(u8 Pl_Num, s16 len) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", max_mark_write);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", SF3_logo);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", player_face_init);
#else
void player_face_init() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", scfont_sqput_face);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", player_face);
#else
void player_face() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", face_base_put);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", hnc_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", hnc_wipeinit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", hnc_wipeout);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", ci_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", nw_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", score8x16_put);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", score16x24_put);

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

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", combo_pts_set);
#else
void combo_pts_set(u8 pl, u8 x, u8 num, s8 *pts, s8 digit) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", naming_set);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", stun_gauge_waku_write);
#else
void stun_gauge_waku_write(s16 p1len, s16 p2len) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", silver_stun_put);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", overwrite_panel);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", sa_stock_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", sa_fullstock_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", sa_number_write);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", sc_ram_to_vram);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", sc_ram_to_vram_opc);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", sq_paint_chenge);

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

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", Akaobi);
#else
void Akaobi() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", Training_Disp_Work_Clear);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", Training_Damage_Set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", Training_Data_Disp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", dispButtonImage);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", dispButtonImage2);
#else
void dispButtonImage2(s32 px, s32 py, s32 pz, s32 sx, s32 sy, s32 cl, s32 ix) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/sc_sub", dispSaveLoadTitle);

const s8 scrnAddTex1UV[9][4] = { { 96, 0, 32, 32 },  { 63, 0, 32, 32 },  { 0, 96, 32, 32 },
                                 { 0, 64, 32, 32 },  { 0, 0, 32, 32 },   { 31, 0, 32, 32 },
                                 { 32, 96, 32, 32 }, { 32, 64, 32, 32 }, { -128, 0, 96, -128 } };
