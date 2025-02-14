#include "sf33rd/Source/Common/PPGFile.h"
#include "common.h"

typedef struct {
    // total size: 0x34
    PPGDataList *cur; // offset 0x0, size 0x4
    u16 hanPal;       // offset 0x4, size 0x2
    u16 hanTex;       // offset 0x6, size 0x2
    _MEMMAN_OBJ mm;   // offset 0x8, size 0x2C
} PPG_W;

typedef struct {
    Point v;
    TexCoord t;
} _Vertex;

const u8 pplColorModeWidth[4] = { 0xF, 0x3F, 0xFF, 0 };

PPG_W ppg_w;
s16 *dctex_linear;

s32 ppgCheckTextureDataBe(Texture *tch);
s32 ppgCheckPaletteDataBe(Palette *pch);
void ppgWriteQuadOnly(Vertex *pos, u32 col, u32 texCode);
void ppgWriteQuadOnly2(Vertex *pos, u32 col, u32 texCode);
void ps2SeqsRenderQuadInit_A();
void ps2SeqsRenderQuad_A(Sprite *spr, u32 col);
void ps2SeqsRenderQuad_A2(Sprite *spr, u32 col);

void ppg_Initialize(void *lcmAdrs, s32 lcmSize) {
    if (lcmAdrs == NULL) {
        while (1) {}
    }

    mmHeapInitialize(&ppg_w.mm, lcmAdrs, lcmSize, 0x10, "- for PPG -");
}

void *ppgMallocF(s32 size) {
    return mmAlloc(&ppg_w.mm, size, 0);
}

void *ppgMallocR(s32 size) {
    return mmAlloc(&ppg_w.mm, size, 1);
}

void ppgFree(void *adrs) {
    mmFree(&ppg_w.mm, adrs);
}

void *ppgPullDecBuff(s32 size) {
    return ppgMallocR(size);
}

void ppgPushDecBuff(void *adrs) {
    ppgFree(adrs);
}

void ppgTexSrcDataReleased(Texture *tex) {
    if (tex == NULL) {
        tex = ppg_w.cur->tex;
    }

    tex->srcAdrs = NULL;
    tex->srcSize = 0;
    ppgCheckTextureDataBe(tex);
}

void ppgPalSrcDataReleased(Palette *pal) {
    if (pal == NULL) {
        pal = ppg_w.cur->pal;
    }

    pal->srcAdrs = NULL;
    pal->srcSize = 0;
    ppgCheckPaletteDataBe(pal);
}

void ppgSourceDataReleased(PPGDataList *dlist) {
    if (dlist == NULL) {
        dlist = ppg_w.cur;
    }

    if (dlist->tex != NULL) {
        ppgTexSrcDataReleased(dlist->tex);
    }

    if (dlist->pal != NULL) {
        ppgPalSrcDataReleased(dlist->pal);
    }
}

void ppgSetupCurrentDataList(PPGDataList *dlist) {
    ppg_w.cur = dlist;
}

void ppgSetupCurrentPaletteNumber(Palette *pal, s32 num) {
    if (pal == NULL) {
        pal = ppg_w.cur->pal;

        if (pal == NULL) {
            return;
        }
    }

    if (num < pal->total) {
        ppg_w.hanPal = pal->handle[num];
    }
}

s32 ppgWriteQuadWithST_A(Vertex *pos, u32 col) {
    ppgWriteQuadOnly(pos, col, ppg_w.hanTex | (ppg_w.hanPal << 0x10));
    return 1;
}

s32 ppgWriteQuadWithST_A2(Vertex *pos, u32 col) {
    ppgWriteQuadOnly2(pos, col, ppg_w.hanTex | (ppg_w.hanPal << 0x10));
    return 1;
}

void ppgWriteQuadOnly(Vertex *pos, u32 col, u32 texCode) {
    Sprite prm;
    s32 i;

    flSetRenderState(FLRENDER_TEXSTAGE0, texCode);
    ps2SeqsRenderQuadInit_A();

    for (i = 0; i < 4; i++) {
        prm.v[i] = ((_Vertex *)pos)[i].v;
        prm.t[i] = ((_Vertex *)pos)[i].t;
    }

    ps2SeqsRenderQuad_A(&prm, col);
    ps2SeqsRenderQuadEnd();
}

void ppgWriteQuadOnly2(Vertex *pos, u32 col, u32 texCode) {
    Sprite prm;

    flSetRenderState(FLRENDER_TEXSTAGE0, texCode);
    ps2SeqsRenderQuadInit_A();

    prm.v[0] = ((_Vertex *)pos)[0].v;
    prm.t[0] = ((_Vertex *)pos)[0].t;
    prm.v[3] = ((_Vertex *)pos)[3].v;
    prm.t[3] = ((_Vertex *)pos)[3].t;

    ps2SeqsRenderQuad_A2(&prm, col);
    ps2SeqsRenderQuadEnd();
}

s32 ppgWriteQuadWithST_B(Vertex *pos, u32 col, PPGDataList *tb, s32 tix, s32 cix) {
    u16 texhan;
    u16 palhan = 0;

    if (tb == NULL) {
        tb = ppg_w.cur;

        if (tb == NULL) {
            return ppgWriteQuadWithST_A(pos, col);
        }
    }

    if (tix < 0) {
        texhan = ppg_w.hanTex;
    } else {
        texhan = tb->tex->handle[tix - tb->tex->ixNum1st].b16[0];

        if (texhan == 0) {
            return 0;
        }
    }

    if (tb->tex->handle[tix - tb->tex->ixNum1st].b16[1] & 0x4000) {
        if (cix < 0) {
            palhan = ppg_w.hanPal;
        } else {
            palhan = tb->pal->handle[cix];
        }
    }

    ppgWriteQuadOnly(pos, col, texhan | (palhan << 0x10));
    return 1;
}

s32 ppgWriteQuadWithST_B2(Vertex *pos, u32 col, PPGDataList *tb, s32 tix, s32 cix) {
    u16 texhan;
    u16 palhan = 0;

    if (tb == NULL) {
        tb = ppg_w.cur;

        if (tb == NULL) {
            return ppgWriteQuadWithST_A2(pos, col);
        }
    }

    if (tix < 0) {
        texhan = ppg_w.hanTex;
    } else {
        texhan = tb->tex->handle[tix - tb->tex->ixNum1st].b16[0];

        if (texhan == 0) {
            return 0;
        }
    }

    if (tb->tex->handle[tix - tb->tex->ixNum1st].b16[1] & 0x4000) {
        if (cix < 0) {
            palhan = ppg_w.hanPal;
        } else {
            palhan = tb->pal->handle[cix];
        }
    }

    ppgWriteQuadOnly2(pos, col, texhan | (palhan << 0x10));
    return 1;
}

s32 ppgWriteQuadUseTrans(Vertex *pos, u32 col, PPGDataList *tb, s32 tix, s32 cix, s32 flip, s32 pal) {
    Vertex qvtx[4];
    s32 i;
    u32 sx;
    u32 sy;
    u32 ppgw;
    u32 ppgh;
    u16 *phan;
    u16 palhan;
    u16 texhan;
    u8 *tran;
    u8 cofsXY;
    u8 xs;
    u8 ys;
    u16 transTotal;
    u16 iPoint;
    u16 ix_ofs;
    f32 pxs;
    f32 pys;
    f32 sadd;
    f32 tadd;
    f32 ppgwf;
    f32 ppghf;
    PPGFileHeader *ppg;

    if ((pos[0].x >= 384.0f) || (pos[3].x < 0.0f) || (pos[0].y >= 224.0f) || (pos[3].y < 0.0f)) {
        return 0;
    }

    if (tb == NULL) {
        tb = ppg_w.cur;

        if (tb == NULL) {
            return ppgWriteQuadWithST_A2(pos, col);
        }
    }

    texhan = tb->tex->handle[tix - tb->tex->ixNum1st].b16[0];
    ix_ofs = tb->tex->handle[tix - tb->tex->ixNum1st].b16[1];

    if (texhan == 0) {
        return 0;
    }

    palhan = 0;

    if (ix_ofs & 0x4000) {
        phan = tb->pal->handle;

        if (phan == NULL) {
            return 0;
        }
    }

    if (tb->tex->srcAdrs != NULL) {
        ppg = (PPGFileHeader *)(tb->tex->srcAdrs + tb->tex->offset[ix_ofs & 0xFFF]);
        transTotal = ((ppg->transNums >> 8) & 0xFF) | ((ppg->transNums & 0xFF) << 8);

        if (transTotal != 0) {
            tran = (u8 *)&ppg[1];
            ppgwf = ppg->width;
            ppgw = ppg->width;
            ppghf = ppg->height;
            ppgh = ppg->height;
            pxs = pos[3].x - pos[0].x;
            pys = pos[3].y - pos[0].y;
            sadd = 0.5f / pxs;
            tadd = 0.5f / pys;

            if (sadd >= (1.0f / (16.0f * ppgwf))) {
                sadd = 1.0f / (16.0f * ppgwf);
            }

            if (tadd >= (1.0f / (16.0f * ppghf))) {
                tadd = 1.0f / (16.0f * ppghf);
            }

            qvtx[0].z = pos[0].z;
            qvtx[3].z = pos[3].z;

            for (i = 0; i < transTotal; i++) {
                if (ix_ofs & 0x4000) {
                    palhan = phan[*tran + pal];
                }

                tran++;
                iPoint = *tran++;
                cofsXY = *tran++;
                xs = (cofsXY >> 4) + 1;
                ys = (cofsXY & 0xF) + 1;
                sx = iPoint % ppgw;
                sy = iPoint / ppgw;

                if (flip & 1) {
                    qvtx[3].x = pos->x + (pxs * (ppgw - sx) / ppgwf);
                    qvtx[0].x = pos->x + (pxs * (ppgw - (sx + xs)) / ppgwf);
                } else {
                    qvtx[0].x = pos->x + (sx * pxs / ppgwf);
                    qvtx[3].x = pos->x + (pxs * (sx + xs) / ppgwf);
                }

                if (flip & 2) {
                    qvtx[3].y = pos->y + (pys * (ppgw - sy) / ppghf);
                    qvtx[0].y = pos->y + (pys * (ppgw - (sy + ys)) / ppghf);
                } else {
                    qvtx[0].y = pos->y + (sy * pys / ppghf);
                    qvtx[3].y = pos->y + (pys * (sy + ys) / ppghf);
                }

                if ((qvtx[0].x < 384.0f) && (qvtx[3].x >= 0.0f) && (qvtx[0].y < 224.0f) && (qvtx[3].y >= 0.0f)) {
                    if (flip & 1) {
                        qvtx[3].s = (sx / ppgwf) - sadd;
                        qvtx[0].s = ((sx + xs) / ppgwf) - sadd;
                    } else {
                        qvtx[0].s = sadd + (sx / ppgwf);
                        qvtx[3].s = sadd + ((sx + xs) / ppgwf);
                    }

                    if (flip & 2) {
                        qvtx[3].t = (sy / ppghf) - tadd;
                        qvtx[0].t = ((sy + ys) / ppghf) - tadd;
                    } else {
                        qvtx[0].t = tadd + (sy / ppghf);
                        qvtx[3].t = tadd + ((sy + ys) / ppghf);
                    }

                    ppgWriteQuadOnly2(qvtx, col, texhan | (palhan << 0x10));
                }
            }

            return 1;
        }
    }

    if (ix_ofs & 0x4000) {
        if (cix < 0) {
            palhan = ppg_w.hanPal;
        } else {
            palhan = phan[cix];
        }
    }

    switch (flip) {
    case 0:
        pos[0].s = pos[0].t = 0.0f;
        pos[3].s = pos[3].t = 1.0f;
        break;

    case 1:
        pos[3].s = pos[0].t = 0.0f;
        pos[0].s = pos[3].t = 1.0f;
        break;

    case 2:
        pos[0].s = pos[3].t = 0.0f;
        pos[3].s = pos[0].t = 1.0f;
        break;

    default:
        pos[0].s = pos[0].t = 1.0f;
        pos[3].s = pos[3].t = 0.0f;
        break;
    }

    ppgWriteQuadOnly2(pos, col, texhan | (palhan << 0x10));
    return 1;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgDecompress);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgSetupCmpChunk);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgSetupPalChunk);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgSetupPalChunkDir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgChangeDataEndian);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgSetupTexChunkSeqs);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgRenewDotDataSeqs);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgMakeConvTableTexDC);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgRenewTexChunkSeqs);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgSetupTexChunk_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgSetupTexChunk_1st_Accnum);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgSetupTexChunk_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgSetupTexChunk_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgSetupContextFromPPL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgSetupContextFromPPG);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgReleasePaletteHandle);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgReleaseTextureHandle);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgCheckTextureDataBe);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgCheckPaletteDataBe);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgGetUsingTextureHandle);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgGetUsingPaletteHandle);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgCheckTextureNumber);

// INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_200_005595D8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_625_005595E8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_626_005595F0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_627_00559600);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_713_00559628);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_714_00559630);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_715_00559660);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_716_00559690);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_778_005596C0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_900_005596F0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_901_00559730);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_1100_00559768);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_1101_00559770);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_1102_005597A0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_1137_005597F0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_1138_00559850);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_1190_00559880);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_1191_005598C0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", literal_1192_005598F0);
