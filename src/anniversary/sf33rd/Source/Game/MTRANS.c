#include "sf33rd/Source/Game/MTRANS.h"
#include "common.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "sf33rd/Source/Common/PPGFile.h"
#include "sf33rd/Source/Game/DC_Ghost.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/chren3rd.h"
#include "sf33rd/Source/Game/debug/Debug.h"
#include "sf33rd/Source/Game/texgroup.h"
#include "structs.h"

extern s32 curr_bright;      // size: 0x4, address: 0x5792E0
extern SpriteChipSet seqs_w; // size: 0x20, address: 0x5792C0

static const u16 flptbl[4] = { 0x0000, 0x8000, 0x4000, 0xC000 };
static const u32 bright_type[4][16] = { { 0x00FFFFFF,
                                          0x00EEEEEE,
                                          0x00DDDDDD,
                                          0x00CCCCCC,
                                          0x00BBBBBB,
                                          0x00AAAAAA,
                                          0x00999999,
                                          0x00888888,
                                          0x00777777,
                                          0x00666666,
                                          0x00555555,
                                          0x00444444,
                                          0x00333333,
                                          0x00222222,
                                          0x00111111,
                                          0x00000000 },
                                        { 0x00FFFFFF,
                                          0x00FFEEEE,
                                          0x00FFDDDD,
                                          0x00FFCCCC,
                                          0x00FFBBBB,
                                          0x00FFAAAA,
                                          0x00FF9999,
                                          0x00FF8888,
                                          0x00FF7777,
                                          0x00FF6666,
                                          0x00FF5555,
                                          0x00FF4444,
                                          0x00FF3333,
                                          0x00FF2222,
                                          0x00FF1111,
                                          0x00FF0000 },
                                        { 0x00FFFFFF,
                                          0x00EEFFEE,
                                          0x00DDFFDD,
                                          0x00CCFFCC,
                                          0x00BBFFBB,
                                          0x00AAFFAA,
                                          0x0099FF99,
                                          0x0088FF88,
                                          0x0077FF77,
                                          0x0066FF66,
                                          0x0055FF55,
                                          0x0044FF44,
                                          0x0033FF33,
                                          0x0022FF22,
                                          0x0011FF11,
                                          0x0000FF00 },
                                        { 0x00FFFFFF,
                                          0x00EEEEFF,
                                          0x00DDDDFF,
                                          0x00CCCCFF,
                                          0x00BBBBFF,
                                          0x00AAAAFF,
                                          0x009999FF,
                                          0x008888FF,
                                          0x007777FF,
                                          0x006666FF,
                                          0x005555FF,
                                          0x004444FF,
                                          0x003333FF,
                                          0x002222FF,
                                          0x001111FF,
                                          0x000000FF } };

void mlt_obj_matrix(WORK *wk, s32 base_y);
static void DebugLine(f32 x, f32 y, f32 w, f32 h);
s32 seqsStoreChip(f32 x, f32 y, s32 w, s32 h, s32 gix, s32 code, s32 attr, s32 alpha, s32 id);
void appRenewTempPriority(s32 z);
static s16 check_patcash_ex_trans(PatternCollection *padr, u32 cg);
static s32 get_free_patcash_index(PatternCollection *padr);
static s32 get_mltbuf16_ext(MultiTexture *mt, u32 code, u32 palt);
static s32 get_mltbuf16_ext_2(MultiTexture *mt, u32 code, u32 palt, s32 *ret, PatternInstance *cp);
static s32 get_mltbuf32_ext(MultiTexture *mt, u32 code, u32 palt);
static s32 get_mltbuf32_ext_2(MultiTexture *mt, u32 code, u32 palt, s32 *ret, PatternInstance *cp);
void makeup_tpu_free(s32 x16, s32 x32, PatternMap *map);

static void search_trsptr(u32 trstbl, s32 i, s32 n, s32 cods, s32 atrs, s32 codd, s32 atrd) {
    s32 j;
    u16 *tmpbas;
    s32 ctemp;
    TileMapEntry *tmpptr;
    TileMapEntry *unused_s4;

    atrd &= 0x3FFF;

    for (j = i; j < n; j++) {
        tmpbas = (u16 *)(trstbl + ((u32 *)trstbl)[j]);
        ctemp = *tmpbas;
        tmpbas++;
        tmpptr = (TileMapEntry *)tmpbas;

        while (ctemp != 0) {
            if (!(tmpptr->attr & 0x1000) && (tmpptr->code == cods) && ((tmpptr->attr & 0xF) == atrs)) {
                tmpptr->code = codd;
                tmpptr->attr = (tmpptr->attr & 0xC000) | atrd;
            }

            ctemp--;
            unused_s4 = tmpptr;
            tmpptr = unused_s4 + 1;
        }
    }
}

void mlt_obj_disp(MultiTexture *mt, WORK *wk, s32 base_y) {
    u16 *trsbas;
    TileMapEntry *trsptr;
    s32 rnum;
    s32 attr;
    s32 palo;
    s32 count;
    s32 n;
    s32 i;
    f32 x;
    f32 y;
    s32 dw;
    s32 dh;

    s32 spA8;
    s32 spA4;
    s32 unused_s8;
    s32 unused_s7;

    ppgSetupCurrentDataList(&mt->texList);
    n = wk->cg_number;
    i = obj_group_table[n];

    if (i == 0) {
        return;
    }

    if (texgrplds[i].ok == 0) {
        // The trans data is not valid. Group number: %d\n
        flLogOut("トランスデータが有効ではありません。グループ番号：%d\n", i);
        while (1) {}
    }

    n -= texgrpdat[i].num_of_1st;
    trsbas = (u16 *)(texgrplds[i].trans_table + ((u32 *)texgrplds[i].trans_table)[n]);
    count = *trsbas;
    trsbas++;
    trsptr = (TileMapEntry *)trsbas;
    x = y = 0.0f;
    attr = flptbl[wk->cg_flip ^ wk->rl_flag];
    palo = wk->colcd & 0xF;

    if (wk->my_bright_type) {
        curr_bright = bright_type[wk->my_bright_type - 1][wk->my_bright_level];
    } else {
        curr_bright = 0xFFFFFF;
    }

    mlt_obj_matrix(wk, base_y);

    while (count--) {
        if (attr & 0x8000) {
            x += trsptr->x;
        } else {
            x -= trsptr->x;
        }

        if (attr & 0x4000) {
            y -= trsptr->y;
        } else {
            y += trsptr->y;
        }

        dw = ((trsptr->attr & 0xC00) >> 7) + 8;
        dh = ((trsptr->attr & 0x300) >> 5) + 8;

        if (!(trsptr->attr & 0x2000)) {
            if (Debug_w[0x10]) {
                DebugLine(x - (dw & ((s16)attr >> 0x10)), y + (dh & ((s16)(attr * 2) >> 16)), dw, dh);
            }

            if (attr & 0x4000) {
                spA8 = 1;
            } else {
                spA8 = 0;
            }

            if (attr & 0x8000) {
                spA4 = 1;
            } else {
                spA4 = 0;
            }

            rnum = seqsStoreChip(x - (dw * spA4),
                                 y + (dh * spA8),
                                 dw,
                                 dh,
                                 mt->mltgidx16,
                                 trsptr->code,
                                 palo + ((trsptr->attr ^ attr) & 0xE00F),
                                 wk->my_clear_level,
                                 mt->id);
        } else {
            if (Debug_w[0x10]) {
                DebugLine(x - (dw & ((s16)attr >> 0x10)), y + (dh & ((s16)(attr * 2) >> 16)), dw, dh);
            }

            if (attr & 0x4000) {
                unused_s8 = 1;
            } else {
                unused_s8 = 0;
            }

            if (attr & 0x8000) {
                unused_s7 = 1;
            } else {
                unused_s7 = 0;
            }

            rnum = seqsStoreChip(x - dw * unused_s7,
                                 y + dh * unused_s8,
                                 dw,
                                 dh,
                                 mt->mltgidx32,
                                 trsptr->code,
                                 palo + ((trsptr->attr ^ attr) & 0xE00F),
                                 wk->my_clear_level,
                                 mt->id);
        }

        if (rnum == 0) {
            break;
        }

        trsptr += 1;
    }

    seqs_w.up[mt->id] = 1;
    appRenewTempPriority(wk->position_z);
}

void mlt_obj_disp_rgb(MultiTexture *mt, WORK *wk, s32 base_y) {
    u16 *trsbas;
    TileMapEntry *trsptr;
    s32 rnum;
    s32 attr;
    s32 count;
    s32 n;
    s32 i;
    f32 x;
    f32 y;
    s32 dw;
    s32 dh;

    s32 spAC;
    s32 spA8;
    s32 unused_s8;
    s32 unused_s7;

    ppgSetupCurrentDataList(&mt->texList);
    n = wk->cg_number;
    i = obj_group_table[n];

    if (i == 0) {
        return;
    }

    if (texgrplds[i].ok == 0) {
        // The trans data is not valid. Group number: %d\n
        flLogOut("トランスデータが有効ではありません。グループ番号：%d\n", i);
        while (1) {}
    }

    n -= texgrpdat[i].num_of_1st;
    trsbas = (u16 *)(texgrplds[i].trans_table + ((u32 *)texgrplds[i].trans_table)[n]);
    count = *trsbas;
    trsbas++;
    trsptr = (TileMapEntry *)trsbas;
    x = y = 0.0f;
    attr = flptbl[wk->cg_flip ^ wk->rl_flag];

    if (wk->my_bright_type) {
        curr_bright = bright_type[wk->my_bright_type - 1][wk->my_bright_level];
    } else {
        curr_bright = 0xFFFFFF;
    }

    mlt_obj_matrix(wk, base_y);

    while (count--) {
        if (attr & 0x8000) {
            x += trsptr->x;
        } else {
            x -= trsptr->x;
        }

        if (attr & 0x4000) {
            y -= trsptr->y;
        } else {
            y += trsptr->y;
        }

        dw = ((trsptr->attr & 0xC00) >> 7) + 8;
        dh = ((trsptr->attr & 0x300) >> 5) + 8;

        if (!(trsptr->attr & 0x2000)) {
            if (Debug_w[0x10]) {
                DebugLine(x - (dw & ((s16)attr >> 0x10)), y + (dh & ((s16)(attr * 2) >> 16)), dw, dh);
            }

            if (attr & 0x4000) {
                spAC = 1;
            } else {
                spAC = 0;
            }

            if (attr & 0x8000) {
                spA8 = 1;
            } else {
                spA8 = 0;
            }

            rnum = seqsStoreChip(x - (dw * spA8),
                                 y + (dh * spAC),
                                 dw,
                                 dh,
                                 mt->mltgidx16,
                                 trsptr->code,
                                 (trsptr->attr ^ attr) & 0xE000,
                                 wk->my_clear_level,
                                 mt->id);
        } else {
            if (Debug_w[0x10]) {
                DebugLine(x - (dw & ((s16)attr >> 0x10)), y + (dh & ((s16)(attr * 2) >> 16)), dw, dh);
            }

            if (attr & 0x4000) {
                unused_s8 = 1;
            } else {
                unused_s8 = 0;
            }

            if (attr & 0x8000) {
                unused_s7 = 1;
            } else {
                unused_s7 = 0;
            }

            rnum = seqsStoreChip(x - (dw * unused_s7),
                                 y + (dh * unused_s8),
                                 dw,
                                 dh,
                                 mt->mltgidx32,
                                 trsptr->code,
                                 (trsptr->attr ^ attr) & 0xE000,
                                 wk->my_clear_level,
                                 mt->id);
        }

        if (rnum == 0) {
            break;
        }

        trsptr++;
    }

    seqs_w.up[mt->id] = 1;
    appRenewTempPriority(wk->position_z);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", getObjectHeight);

// ❌
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", mlt_obj_trans_ext);

// ❌
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", mlt_obj_trans);

// ❌
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", mlt_obj_trans_cp3_ext);

// ❌
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", mlt_obj_trans_cp3);

// ❌
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", mlt_obj_trans_rgb_ext);

// ❌
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", mlt_obj_trans_rgb);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", mlt_obj_matrix);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", appSetupBasePriority);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", appSetupTempPriority);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", appRenewTempPriority_1_Chip);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", appRenewTempPriority);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", seqsInitialize);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", seqsGetSprMax);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", seqsGetUseMemorySize);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", seqsBeforeProcess);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", seqsAfterProcess);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", literal_1272_00522CD0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", seqsStoreChip);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", literal_1302_00522D00);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", get_mltbuf16);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", literal_1332_00522D40);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", get_mltbuf32);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", literal_1366_00522D80);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", get_mltbuf16_ext_2);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", literal_1400_00522DC0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", get_mltbuf32_ext_2);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", literal_1423_00522E00);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", get_mltbuf16_ext);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", literal_1446_00522E20);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", get_mltbuf32_ext);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", x16_mapping_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", x32_mapping_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", makeup_tpu_free);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", check_patcash_ex_trans);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", literal_1560_00522E40);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", get_free_patcash_index);

static void lz_ext_p6_fx(u8 *srcptr, u8 *dstptr, u32 len);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", lz_ext_p6_fx);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", lz_ext_p6_cx);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", mlt_obj_trans_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", mlt_obj_trans_update);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", draw_box);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MTRANS", DebugLine);

void mlt_obj_melt2(MultiTexture *mt, u16 cg_number) {
    u32 *textbl;
    u16 *trsbas;
    TileMapEntry *trsptr;
    TEX *texptr;
    TEX_GRP_LD *grplds;
    s32 count;
    s32 n;
    s32 i;
    s32 cd16;
    s32 cd32;
    s32 size;
    s32 attr;
    s32 palt;
    s32 wh;
    s32 dd;

    u16 *spA4;

    ppgSetupCurrentDataList(&mt->texList);
    grplds = &texgrplds[obj_group_table[cg_number]];

    if (grplds->ok == 0) {
        // The trans data is not valid. Group number: %d\n
        flLogOut("トランスデータが有効ではありません。グループ番号：%d\n", obj_group_table[cg_number]);
        while (1) {}
    }

    n = *(u32 *)grplds->trans_table / 4;
    textbl = (u32 *)grplds->texture_table;
    cd16 = 0;
    cd32 = 0;

    for (i = 0; i < n; i++) {
        trsbas = (u16 *)(grplds->trans_table + ((u32 *)grplds->trans_table)[i]);
        count = *trsbas;
        trsbas++;
        trsptr = (TileMapEntry *)trsbas;

        while (count != 0) {
            attr = trsptr->attr;

            if (!(attr & 0x1000)) {
                texptr = (TEX *)((u32)textbl + ((u32 *)textbl)[trsptr->code]);
                dd = (((texptr->wh & 0xE0) << 5) - 0x400) | (((texptr->wh & 0x1C) << 6) - 0x100);
                wh = (texptr->wh & 3) + 1;
                size = (wh * wh) << 6;
                palt = attr & 3;

                switch (wh) {
                case 1:
                case 2:
                    lz_ext_p6_fx(&((u8 *)texptr)[1], mt->mltbuf, size);
                    njReLoadTexturePartNumG(mt->mltgidx16 + (cd16 >> 8), (s8 *)mt->mltbuf, cd16 & 0xFF, size);
                    attr = (attr & 0xC000) | 0x1000 | dd;
                    trsptr->attr |= 0x1000;
                    attr |= palt;
                    search_trsptr(grplds->trans_table, i, n, trsptr->code, palt, cd16, attr);
                    trsptr->code = cd16;
                    trsptr->attr = attr;
                    cd16 += 1;
                    break;

                case 4:
                    lz_ext_p6_fx(&((u8 *)texptr)[1], mt->mltbuf, size);
                    njReLoadTexturePartNumG(mt->mltgidx32 + (cd32 >> 6), (s8 *)mt->mltbuf, cd32 & 0x3F, size);
                    attr = (attr & 0xC000) | 0x3000 | dd;
                    trsptr->attr |= 0x1000;
                    attr |= palt;
                    search_trsptr(grplds->trans_table, i, n, trsptr->code, palt, cd32, attr);
                    trsptr->code = cd32;
                    trsptr->attr = attr;
                    cd32 += 1;
                    break;
                }
            }

            count -= 1;
            spA4 = (u16 *)trsptr++;
        }
    }

    ppgRenewTexChunkSeqs(NULL);
}
