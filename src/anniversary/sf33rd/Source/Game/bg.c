#include "sf33rd/Source/Game/bg.h"
#include "common.h"
#include "sf33rd/Source/Common/PPGFile.h"
#include "sf33rd/Source/Common/PPGWork.h"
#include "sf33rd/Source/Game/DC_Ghost.h"
#include "sf33rd/Source/Game/MTRANS.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/bg_data.h"
#include "sf33rd/Source/Game/color3rd.h"
#include "sf33rd/Source/Game/end_data.h"
#include "structs.h"

// sbss
Vertex scrDrawPos[4];
Polygon bgpoly[4];
u8 bg_priority[4];
u16 Screen_Switch;
u16 Screen_Switch_Buffer;
u8 rw_num;
u8 rw_bg_flag[4];
u8 tokusyu_stage;
s32 rw_gbix[13];
s8 stage_flash;
s8 stage_ftimer;
s32 yang_ix_plus;
s8 yang_ix;
s8 yang_timer;
u8 ending_flag;
BackgroundParameters end_prm[8];
u8 gouki_end_gbix[16];
u32 *rw3col_ptr;
u8 bg_disp_off;
s32 bgPalCodeOffset[8];

// bss
BG bg_w;
RW_DATA rw_dat[20];

static void bgRWWorkUpdate();
static void bgDrawOneScreen(s32 bgnum, s32 gixbase, s32 *xx, s32 *yy, s32 /* unused */, s32 ofsPal,
                            PPGDataList *curDataList);
static void bgDrawOneChip(s32 x, s32 y, s32 xs, s32 ys, s32 gbix, u32 vtxCol, s32 ofsPal);
static void bgAkebonoDraw();
static void ppgCalScrPosition(s32 x, s32 y, s32 xs, s32 ys);

void Bg_TexInit() {
    s32 i = 0;

    while (i < 3) {
        ppgBgList[i].tex = &ppgBgTex[i];
        ppgBgList[i].pal = palGetChunkGhostCP3();
        i++;
    }

    ppgRwBgList.tex = &ppgRwBgTex;
    ppgRwBgList.pal = palGetChunkGhostCP3();
    ppgAkeList.tex = &ppgAkeTex;
    ppgAkeList.pal = &ppgAkePal;
    ppgAkaneList.tex = &ppgAkaneTex;
    ppgAkaneList.pal = &ppgAkanePal;
}

void Bg_Kakikae_Set() {
    u8 i;
    const u32 *rwtbl_ptr;
    s8 rw;

    switch (bg_w.stage) {
    case 3:
        tokusyu_stage = 1;
        stage_flash = 0;
        stage_ftimer = 0;
        rw_dat->rwd_ptr = rw_dat->brw_ptr = (s16 *)rw30;
        rw_dat->rw_cnt = 2;
        i = 0;

        while (i < 13) {
            rw_gbix[i] = stage03rw_data_tbl[i];
            i++;
        }

        rw3col_ptr = (u32 *)rw30col;
        i = 0;

        while (i < 4) {
            rw = bgrw_on[bg_w.stage][i];
            rwtbl_ptr = &bgrw_data_tbl[rw][0];
            rw_dat[i + 1].bg_num = *rwtbl_ptr++;
            rw_dat[i + 1].rwgbix = *rwtbl_ptr++;
            rw_dat[i + 1].rwd_ptr = rw_dat[i + 1].brw_ptr = (s16 *)rwtbl_ptr[0];
            rw_dat[i + 1].rw_cnt = *rw_dat[i + 1].rwd_ptr++;
            rw_dat[i + 1].gbix = *rw_dat[i + 1].rwd_ptr++;
            i++;
        }
        break;

    case 10:
        tokusyu_stage = 2;
        yang_ix = 0;
        yang_ix_plus = 0;
        yang_timer = 4;
        break;

    case 19:
        tokusyu_stage = 3;
        stage_flash = 0;
        stage_ftimer = 2;
        rw_dat->rwd_ptr = rw_dat->brw_ptr = (s16 *)rw190;
        rw_dat->rw_cnt = 2;
        i = 0;

        while (i < 4) {
            rw_gbix[i] = stage19rw_data_tbl[i];
            i++;
        }

        rw = bgrw_on[bg_w.stage][0];
        rwtbl_ptr = &bgrw_data_tbl[rw][0];
        rw_dat[1].bg_num = *rwtbl_ptr++;
        rw_dat[1].rwgbix = *rwtbl_ptr++;
        rw_dat[1].rwd_ptr = rw_dat[1].brw_ptr = (s16 *)rwtbl_ptr[0];
        rw_dat[1].rw_cnt = *rw_dat[1].rwd_ptr++;
        rw_dat[1].gbix = *rw_dat[1].rwd_ptr++;
        break;

    default:
        if (bg_w.stage == 7) {
            tokusyu_stage = 4;
        } else {
            tokusyu_stage = 0;
        }

        rw_num = 0;
        i = 0;

        while (i < 4) {
            rw_bg_flag[i] = 0;
            i++;
        }

        i = 0;

        while (i < 8) {
            rw = bgrw_on[bg_w.stage][i];
            if (rw == -1)
                return;
            rw_num++;
            rwtbl_ptr = &bgrw_data_tbl[rw][0];
            rw_dat[i].bg_num = *rwtbl_ptr++;
            rw_bg_flag[rw_dat[i].bg_num] = 1;
            rw_dat[i].rwgbix = *rwtbl_ptr++;
            rw_dat[i].rwd_ptr = rw_dat[i].brw_ptr = (s16 *)rwtbl_ptr[0];
            rw_dat[i].rw_cnt = *rw_dat[i].rwd_ptr++;
            rw_dat[i].gbix = *rw_dat[i].rwd_ptr++;

            i++;
        }
        break;
    }
}

// INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Ed_Kakikae_Set);

void Ed_Kakikae_Set(s16 type) {
    u8 i;
    const u32 *rwtbl_ptr;
    s8 rw;

    rw_num = 0;
    i = 0;

    while (i < 4) {
        rw_bg_flag[i] = 0;
        i++;
    }

    switch (type) {
    case 14:
        i = 0;
        while (i < 0x14) {
            rwtbl_ptr = &gedrw_data_tbl[i][0];
            rw_dat[i].rwgbix = *rwtbl_ptr++;
            rw_dat[i].rwd_ptr = rw_dat[i].brw_ptr = (s16 *)rwtbl_ptr[0];
            i++;
        }
        break;

    case 15:
        i = 0;
        while (i < 0x10) {
            rwtbl_ptr = &cedrw_data_tbl[i][0];
            rw_dat[i].rwgbix = *rwtbl_ptr++;
            rw_dat[i].rwd_ptr = rw_dat[i].brw_ptr = (s16 *)rwtbl_ptr[0];
            i++;
        }
        break;

    default:
        if (edrw_num[type][0] != -1) {
            rw = edrw_num[type][0];
            i = 0;

            while (i < edrw_num[type][1]) {
                rw_num += 1;
                rwtbl_ptr = &edrw_data_tbl[rw + i][0];
                rw_dat[i].bg_num = *rwtbl_ptr++;
                rw_bg_flag[rw_dat[i].bg_num] = 1;
                rw_dat[i].rwgbix = *rwtbl_ptr++;
                rw_dat[i].rwd_ptr = rw_dat[i].brw_ptr = (s16 *)rwtbl_ptr[0];
                rw_dat[i].rw_cnt = *rw_dat[i].rwd_ptr++;
                rw_dat[i].gbix = *rw_dat[i].rwd_ptr++;
                i++;
            }
        }
        break;
    }
}

void Bg_Close() {
    u32 i;

    tokusyu_stage = 0;
    rw_num = 0;
    i = 0;

    while (i < 3) {
        ppgReleaseTextureHandle(&ppgBgTex[i], -1);
        i += 1;
    }

    ppgReleaseTextureHandle(&ppgRwBgTex, -1);
    ppgReleaseTextureHandle(&ppgAkeTex, -1);
    ppgReleasePaletteHandle(&ppgAkePal, -1);
    ppgReleaseTextureHandle(&ppgAkaneTex, -1);
    ppgReleasePaletteHandle(&ppgAkanePal, -1);
    Screen_Switch = 0;
    Screen_Switch_Buffer = 0;
    bg_disp_off = 0;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_Texture_Load_EX);
#else
void Bg_Texture_Load_EX() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_Texture_Load2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Bg_Texture_Load_Ending);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", literal_380_004E6EC8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", literal_423_004E6ED8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", literal_424_004E6EF0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", literal_502_004E6F20);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", scr_trans);

void bgRWWorkUpdate() {
    s32 i = 0;

    while (i < rw_num) {
        rw_dat[i].rw_cnt--;

        if (rw_dat[i].rw_cnt == 0) {
            if (*rw_dat[i].rwd_ptr == -1) {
                rw_dat[i].rwd_ptr = rw_dat[i].brw_ptr;
                rw_dat[i].rw_cnt = *rw_dat[i].rwd_ptr++;
                rw_dat[i].gbix = *rw_dat[i].rwd_ptr++;
            } else {
                rw_dat[i].rw_cnt = *rw_dat[i].rwd_ptr++;
                rw_dat[i].gbix = *rw_dat[i].rwd_ptr++;
            }
        }

        i++;
    }
}

void bgDrawOneScreen(s32 bgnum, s32 gixbase, s32 *xx, s32 *yy, s32 /* unused */, s32 ofsPal, PPGDataList *curDataList) {
    s32 i, x, y, gbix;

    y = yy[0];
    while (y < yy[1]) {
        x = xx[0];
        while (x < xx[1]) {
            gbix = ((y >> 7) << 3) + (x >> 7) + gixbase;

            if (rw_bg_flag[bgnum] && rw_num) {
                for (i = 0; i < rw_num; i++) {
                    if (bgnum == rw_dat[i].bg_num && gbix == rw_dat[i].rwgbix) {
                        gbix = rw_dat[i].gbix;
                        if (!(ppgCheckTextureNumber(0, gbix))) {
                            ppgSetupCurrentDataList(&ppgRwBgList);
                        }
                        break;
                    }
                }
            }

            bgDrawOneChip(x, y, 128, 128, gbix, -1, ofsPal);
            ppgSetupCurrentDataList(curDataList);
            x += 128;
        }
        y += 128;
    }
}

void bgDrawOneChip(s32 x, s32 y, s32 xs, s32 ys, s32 gbix, u32 vtxCol, s32 ofsPal) {
    s32 i;

    if (No_Trans == 0 && ppgCheckTextureNumber(0, gbix)) {
        ppgCalScrPosition(x, y, xs, ys);
        if (!(scrDrawPos->x < 384.0f && !(scrDrawPos[3].x < 0.0f) && (scrDrawPos->y < 224.0f) &&
              !(scrDrawPos[3].y < 0.0f))) {
            return;
        } else {
            ppgWriteQuadUseTrans(scrDrawPos, vtxCol, 0, gbix, 0, 0, ofsPal);
        }
    }
}

void bgAkebonoDraw() {
    s32 i;

    scrDrawPos->x = 0.0f;
    scrDrawPos->y = 0.0f;
    scrDrawPos[3].x = 128.0f;
    scrDrawPos[3].y = 224.0f;
    scrDrawPos->z = scrDrawPos[3].z = *(&PrioBase[bg_priority[3]]);
    scrDrawPos->s = scrDrawPos->t = 0.0f;
    scrDrawPos[3].s = 1.0f;
    scrDrawPos[3].t = 0.875f;
    i = 0;

    while (i < 3) {
        ppgWriteQuadUseTrans(scrDrawPos, -1U, NULL, i, i, 0, 0);
        scrDrawPos->x += 128.0f;
        scrDrawPos[3].x += 128.0f;
        i++;
    }
}

void ppgCalScrPosition(s32 x, s32 y, s32 xs, s32 ys) {
    Vec3 point[2];

    point[0].x = (f32)x;
    point[0].y = (f32)y;
    point[1].x = (f32)(x + xs);
    point[1].y = (f32)(y + ys);
    point[0].z = point[1].z = 0;
    njCalcPoints(0, &point[0], &point[0], 2);
    scrDrawPos[0].x = scrDrawPos[2].x = point[0].x;
    scrDrawPos[0].y = scrDrawPos[1].y = point[0].y;
    scrDrawPos[1].x = scrDrawPos[3].x = point[1].x;
    scrDrawPos[2].y = scrDrawPos[3].y = point[1].y;
    scrDrawPos[0].z = scrDrawPos[1].z = scrDrawPos[2].z = scrDrawPos[3].z = point[0].z;
    scrDrawPos[0].s = (0.5f + (f32)(x & 0x7F)) / 128.0f;
    scrDrawPos[0].t = (0.5f + (f32)(y & 0x7F)) / 128.0f;
    scrDrawPos[3].s = (0.5f + (f32)((x & 0x7F) + xs)) / 128.0f;
    scrDrawPos[3].t = (0.5f + (f32)((y & 0x7F) + ys)) / 128.0f;
    scrDrawPos[1].s = scrDrawPos[3].s;
    scrDrawPos[2].s = scrDrawPos[0].s;
    scrDrawPos[1].t = scrDrawPos[0].t;
    scrDrawPos[2].t = scrDrawPos[3].t;
}

void scr_trans_sub2(s32 x, s32 y, s32 suzi) {
    Vec3 point[2];
    Vec3 spoint[2];

    point[0].x = (f32)x;
    spoint[0].x = (f32)(x + suzi);
    point[0].y = spoint[0].y = (f32)(y + 0x200);
    point[1].x = (f32)(x + 0x100);
    spoint[1].x = (f32)(x + suzi + 0x100);
    point[1].y = spoint[1].y = (f32)(y + 0x300);
    point[0].z = point[1].z = spoint[0].z = spoint[1].z = 0;
    njCalcPoints(NULL, &point[0], &point[0], 2);
    njCalcPoints(NULL, &spoint[0], &spoint[0], 2);
    bgpoly[0].x = spoint[0].x;
    bgpoly[0].y = point[0].y;
    bgpoly[0].z = point[0].z;
    bgpoly[0].u = 0.0f;
    bgpoly[0].v = 0.0f;
    bgpoly[0].col = -1;
    bgpoly[1].x = spoint[1].x;
    bgpoly[1].y = point[0].y;
    bgpoly[1].z = point[0].z;
    bgpoly[1].u = 1.0f;
    bgpoly[1].v = 0.0f;
    bgpoly[1].col = -1;
    bgpoly[2].x = point[0].x;
    bgpoly[2].y = point[1].y;
    bgpoly[2].z = point[1].z;
    bgpoly[2].u = 0.0f;
    bgpoly[2].v = 1.0f;
    bgpoly[2].col = -1;
    bgpoly[3].x = point[1].x;
    bgpoly[3].y = point[1].y;
    bgpoly[3].z = point[1].z;
    bgpoly[3].u = 1.0f;
    bgpoly[3].v = 1.0f;
    bgpoly[3].col = -1;
}

void scr_calc(u8 bgnm) {
    njUnitMatrix(NULL);
    njScale(NULL, Frame_Zoom_X, Frame_Zoom_Y, 1.0f);
    njScale(NULL, scr_sc, scr_sc, 1.0f);
    njTranslate(NULL, 0.0f, 224.0f, 0.0f);
    njScale(NULL, 1.0f, -1.0f, 1.0f);
    njTranslate(NULL, (s16)-bg_prm[bgnm].bg_h_shift, (s16)-bg_prm[bgnm].bg_v_shift, 0.0f);
    njGetMatrix(&BgMATRIX[bgnm + 1]);
}

void scr_calc2(u8 bgnm) {
    njUnitMatrix(NULL);
    njScale(NULL, Frame_Zoom_X, Frame_Zoom_Y, 1.0f);
    njScale(NULL, scr_sc, scr_sc, 1.0f);
    njTranslate(NULL, 0.0f, 224.0f, 0.0f);
    njScale(NULL, 1.0f, -1.0f, 1.0f);
    njTranslate(NULL, (s16)-end_prm[bgnm + 1].bg_h_shift, (s16)-end_prm[bgnm + 1].bg_v_shift, 0.0f);
    njGetMatrix(&BgMATRIX[bgnm + 1]);
}

void Pause_Family_On() {
    njUnitMatrix(0);
    njScale(0, Frame_Zoom_X, Frame_Zoom_Y, 1);
    njTranslate(0, 0, 224, 0);
    njScale(0, 1, -1, 1);
    njGetMatrix(&BgMATRIX[8]);
}

void Zoomf_Init() {
    zoom_add = 64;
    scr_sc = 1.0f;
    sca_x = 0;
    sca_y = 1023;
    scrn_adgjust_x = 0;
    scrn_adgjust_y = 0;
}

void Zoom_Value_Set(u16 zadd) {
    f32 work;
    u16 add;

    if (zadd < 0x40) {
        scr_sc = 64.0f / zadd;
        return;
    }

    if (zadd == 0x40) {
        scr_sc = 1.0f;
        return;
    }

    add = zadd & 0x3F;
    work = 1.0f / (64.0f / add);
    add = zadd & 0xFFC0;
    add >>= 6;
    scr_sc = 1.0f / (add + work);
}

void Frame_Up(u16 x, u16 y, u16 add) {
#if defined(TARGET_PS2)
    void Frame_Adgjust(u32 pos_x, u32 pos_y);
#endif

    if (zoom_add < 2) {
        scr_sc = 64.0f;
        return;
    }

    zoom_add -= add;
    Zoom_Value_Set(zoom_add);
    Frame_Adgjust(x, y);
}

void Frame_Down(u16 x, u16 y, u16 add) {
#if defined(TARGET_PS2)
    void Frame_Adgjust(u32 pos_x, u32 pos_y);
#endif

    if (zoom_add >= 0xFFC0) {
        scr_sc = 0.0009775171f;
        return;
    }

    zoom_add += add;
    Zoom_Value_Set(zoom_add);
    Frame_Adgjust(x, y);
}

void Frame_Adgjust(u16 pos_x, u16 pos_y) {
    u16 buff;

    if (zoom_add >= 0x40) {
        buff = zoom_add;
        buff -= 0x40;
        buff *= pos_x;
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_x = -buff;
    } else {
        buff = 0x40;
        buff -= zoom_add;
        buff *= pos_x;
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_x = buff;
    }

    if (zoom_add >= 0x40) {
        buff = zoom_add;
        buff -= 0x40;
        buff *= pos_y + 0x15;
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_y = -buff;

        if (scrn_adgjust_y == -0x14) {
            scrn_adgjust_y += 1;
        }
    } else {
        buff = 0x40;
        buff -= zoom_add;
        buff *= pos_y + 0x15;
        buff >>= 6;
        buff &= 0x1FF;
        scrn_adgjust_y = buff;

        if (scrn_adgjust_y == -0x14) {
            scrn_adgjust_y += 1;
        }
    }
}

void Scrn_Pos_Init() {
    u8 i;

    for (i = 0; i < 8; i++) {
        bg_pos[i].scr_x.long_pos = 0;
        bg_pos[i].scr_x_buff.long_pos = 0;
        bg_pos[i].scr_y.long_pos = 0;
        bg_pos[i].scr_y_buff.long_pos = 0;
        bg_prm[i].bg_h_shift = 0;
        bg_prm[i].bg_v_shift = 0;
        end_prm[i].bg_h_shift = 0;
        end_prm[i].bg_v_shift = 0;
    }
}

void Scrn_Move_Set(s8 bgnm, s16 x, s16 y) {
    bg_pos[bgnm].scr_x.word_pos.h = x;
    bg_pos[bgnm].scr_y.word_pos.h = y + 16;
}

void Family_Init() {
    u8 i;

    for (i = 0; i < 8; i++) {
        fm_pos[i].scr_x.long_pos = 0;
        fm_pos[i].scr_y.long_pos = 0;
        fm_pos[i].scr_x_buff.long_pos = 0;
        fm_pos[i].scr_y_buff.long_pos = 0;
    }
}

void Family_Set_R(s8 fmnm, s16 x, s16 y) {
    fm_pos[fmnm].scr_x.word_pos.h = x;
    fm_pos[fmnm].scr_y.word_pos.h = y;
    fm_pos[fmnm].scr_x_buff.word_pos.h = x;
    fm_pos[fmnm].scr_y_buff.word_pos.h = y;
}

void Family_Set_W(s8 fmnm, s16 x, s16 y) {
    fm_pos[fmnm].scr_x.word_pos.h = x;
    fm_pos[fmnm].scr_y.word_pos.h = y;
    fm_pos[fmnm].scr_x_buff.word_pos.h = x;
    fm_pos[fmnm].scr_y_buff.word_pos.h = y;
}

void Bg_On_R(u16 s_prm) {
    Screen_Switch |= s_prm;
    Screen_Switch_Buffer = Screen_Switch;
}

void Bg_On_W(u16 s_prm) {
    Screen_Switch |= s_prm;
    Screen_Switch_Buffer = Screen_Switch;
}

void Bg_Off_R(u16 s_prm) {
    s_prm = ~s_prm;
    Screen_Switch &= s_prm;
    Screen_Switch_Buffer = Screen_Switch;
}

void Bg_Off_W(u16 s_prm) {
    s_prm = ~s_prm;
    Screen_Switch &= s_prm;
    Screen_Switch_Buffer = Screen_Switch;
}

void Scrn_Renew() {
    Screen_Switch_Buffer = Screen_Switch;
}

void Irl_Family() {
    u8 i;

    for (i = 0; i < 8; i++) {
        fm_pos[i].scr_x_buff.long_pos = fm_pos[i].scr_x.long_pos;
        fm_pos[i].scr_y_buff.long_pos = fm_pos[i].scr_y.long_pos;
        bg_pos[i].scr_x_buff.long_pos = bg_pos[i].scr_x.long_pos;
        bg_pos[i].scr_y_buff.long_pos = bg_pos[i].scr_y.long_pos;
    }
}

void Irl_Scrn() {
    s8 i;

    for (i = 0; i < 8; i++) {
        bg_prm[i].bg_h_shift = scrn_adgjust_x + bg_pos[i].scr_x_buff.word_pos.h;
        bg_prm[i].bg_h_shift;
        end_prm[i].bg_h_shift = scrn_adgjust_x + fm_pos[i].scr_x_buff.word_pos.h;
        end_prm[i].bg_h_shift;
        bg_prm[i].bg_v_shift = bg_pos[i].scr_y_buff.word_pos.h - scrn_adgjust_y;
        bg_prm[i].bg_v_shift;
        end_prm[i].bg_v_shift = fm_pos[i].scr_y_buff.word_pos.h - scrn_adgjust_y;
        end_prm[i].bg_v_shift;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Family_Move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/bg", Ending_Family_Move);

void Bg_Disp_Switch(u8 on_off) {
    bg_disp_off = on_off;
}
