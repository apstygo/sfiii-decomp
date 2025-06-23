#include "sf33rd/Source/PS2/mc/knjsub.h"
#include "common.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"

// sbss
static s32 knj_use_flag;
static u8 ascii_chr_tbl[1];

// forward declarations
static u32 *make_img_pkt(u32 *p, u32 *img, u32 dbp, u32 dbw, u32 dbsm, u32 dsax, u32 dsay, u32 rrw, u32 rrh);

#if defined(TARGET_PS2)
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", literal_225_005601F0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjInit);
#else
void KnjInit(u32 type, uintptr_t adrs, u32 disp_max, u32 top_dbp) {
    not_implemented(__func__);
}
#endif

void KnjFinish(void) {
    knj_use_flag = 0;
}

s32 KnjUseCheck() {
    return knj_use_flag;
}

void KnjSetSize(s32 dispw, s32 disph) {
    if (KnjUseCheck() != 0) {
        kanji_w.dispw = dispw;
        kanji_w.disph = disph;
    }
}

void KnjLocate(s32 x, s32 y) {

    if (KnjUseCheck() != 0) {
        kanji_w.x = x;
        kanji_w.y = y;
    }
}

void KnjSetColor(u32 color) {
    Kanji_W *kw = &kanji_w;

    if (KnjUseCheck() != 0) {
        kw->color = color;
        kw->bg_color = (kw->bg_color & 0xFFFFFF) | (color & 0xFF000000);
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjSetAlpha);
#else
void KnjSetAlpha(u32 alpha) {
    not_implemented(__func__);
}
#endif

void KnjSetRgb(u32 color) {
    Kanji_W *kw = &kanji_w;

    if (KnjUseCheck() != 0) {
        kw->color = kw->color & 0xFF000000 | (color & 0xFFFFFF);
    }
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjPuts);
#else
void KnjPuts(const s8 *str) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", get_img_adrs);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjPrintf);
#else
void KnjPrintf(const s8 *fmt, ...) {
    not_implemented(__func__);
}
#endif

void KnjFlush() {
    u32 *pp;
    u32 psize;
    u32 ptr;
    Kanji_W *kw = &kanji_w;

    if (KnjUseCheck() != 0) {
        pp = kw->pack_cur;
        *pp++ = 0xF0000000;
        *pp++ = 0;
        *pp++ = 0;
        *pp++ = 0;
        psize = (u32)pp - (u32)kw->pack_top[kw->pack_idx];

        if (kw->pack_size < psize) {
            printf("KnjFlush: packet over, 0x%X > 0x%X.\n", psize, kw->pack_size);

            while (1) {
                // Do Nothing
            }
        }

        if (kw->dcur != 0) {
            ptr = (u32)kw->pack_top[kw->pack_idx];
            flPS2DmaAddQueue2(0, (ptr & 0xFFFFFFF) | 0x40000000, ptr, &flPs2VIF1Control);
        }

        kw->pack_idx ^= 1;
        kw->pack_cur = kw->pack_fnt[kw->pack_idx];
        kw->dlast = kw->dcur;
        kw->dcur = 0;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", sjis2jis_sce);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", sjis2jis_nec);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", sjis2index);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", ascii2sjis);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", ascii2sjis_sce);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", ascii2sjis_nec);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", utf82unicode);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", unicode2index);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", get_uni_adrs);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", get_uni_adrs2);

static s32 is_unicode_han(Kanji_W *kw, u32 index) {
    return index < kw->uni_half ? 1 : 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", unicode_puts);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjStrLen);
#else
s32 KnjStrLen(const s8 *str) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjCheckCode);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", make_env_pkt);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", make_img_pkt);

static u32 *make_pal_pkt(Kanji_W *kw, u32 *p) {
    s32 i;
    u32 *img;

    for (i = 0; i < kw->pmax; i++) {
        img = (u32 *)(kw->rgba_adrs + (i * 16));
        p = make_img_pkt(p, img, kw->pdbp + i, 1, 0, 0, 0, 8, 2);
    }

    return p;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", make_fnt_pkt);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", make_fbg_pkt);
