#include "sf33rd/Source/Game/texcash.h"
#include "common.h"
#include "sf33rd/AcrSDK/ps2/flps2debug.h"
#include "sf33rd/Source/Common/PPGFile.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/MTRANS.h"
#include "sf33rd/Source/Game/RAMCNT.h"
#include "sf33rd/Source/Game/SYS_sub.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/debug/Debug.h"
#include "structs.h"

typedef struct {
    // total size: 0x18
    s32 p16;       // offset 0x0, size 0x4
    s32 p32;       // offset 0x4, size 0x4
    s32 gix;       // offset 0x8, size 0x4
    s16 life16;    // offset 0xC, size 0x2
    s16 life32;    // offset 0xE, size 0x2
    s16 type;      // offset 0x10, size 0x2
    u16 mode;      // offset 0x12, size 0x2
    u32 attribute; // offset 0x14, size 0x4
} MTSBase;

// sdata
s8 *texcash_name[29] = { "    16x16 (tm)  32x32 (tm) GIX      (mn.nw)",
                         "QA",
                         "HT",
                         "1P",
                         "2P",
                         "CA",
                         "SW",
                         "OB",
                         "ED",
                         "DM",
                         "OT",
                         "MJ",
                         "MS",
                         "SL",
                         "EU",
                         "RR",
                         "GI",
                         "xx",
                         "xx",
                         "xx",
                         "xx",
                         "xx",
                         "xx",
                         "xx",
                         "   /   (  )    /   (  )     +    (  .  )",
                         "--- --- --  --- --- --  ---   --  -- --",
                         "--- --- --",
                         "--",
                         "--.--" };

// sbss
u8 *texcash_melt_buffer;
TexturePoolUsed *tpu_free;
s16 mts_ob_curr_stage;

// forward decls
extern const s16 mts_OB_page[22][2];
extern const MTSBase mts_base[24];

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_250_00554C48);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_251_00554C50);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_252_00554C58);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_253_00554C60);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", disp_texcash_free_area);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", search_texcash_free_area);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", init_texcash_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", init_texcash_before_process);

void init_texcash_2nd(s16 ix) {
    PatternState *mc;
    PatternCollection *cp;
    TexturePoolFree *tf;
    TexturePoolUsed *tu;
    s16 i;

    tf = mts[ix].tpf;
    tu = mts[ix].tpu;
    cp = mts[ix].cpat;
    tf->x32 = 0;
    tf->x16 = 0;
    tu->x32 = 0;
    tu->x16 = 0;
    mc = mts[ix].mltcsh16;

    for (i = mts[ix].mltnum16 - 1; i >= 0; i--) {
        if (mc[i].cs.code == -1) {
            tf->x16_free[tf->x16] = i;
            tf->x16 += 1;
        } else {
            tu->x16_used[tu->x16] = i;
            tu->x16 += 1;
        }
    }

    mc = mts[ix].mltcsh32;

    for (i = mts[ix].mltnum32 - 1; i >= 0; i--) {
        if (mc[i].cs.code == -1) {
            tf->x32_free[tf->x32] = i;
            tf->x32 += 1;
        } else {
            tu->x32_used[tu->x32] = i;
            tu->x32 += 1;
        }
    }

    cp->kazu = 0;

    for (i = 0; i < 0x40; i++) {
        if (cp->patt[i].time) {
            cp->adr[cp->kazu] = &cp->patt[i];
            cp->kazu += 1;
        }
    }
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_379_00554C70);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", texture_cash_update);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_413_00554C90);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_414_00554CB0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", update_with_tpu_free);

s16 get_my_trans_mode(s16 curr) {
    if (mts_ok[curr].be == 0) {
        return -1;
    }

    return mts[curr].mode;
}

void make_texcash_work(s16 ix) {
#if defined(TARGET_PS2)
    void init_texcash_2nd(s32 ix);
#endif

    u32 memreq;
    u8 *adrs;
    u32 page16;
    u32 page32;

    if (mts_ok[ix].be) {
        if ((Test_ramcnt_key(mts_ok[ix].key0) != 0) && (Test_ramcnt_key(mts_ok[ix].key1) != 0)) {
            return;
        }

        Debug_w[10] = 2;

        while (1) {
            disp_ramcnt_free_area();
            flPrintL(5, 30, "TEXCASH KEY ERROR");
            njWaitVSync_with_N();
        }
    } else {
        if (ix == 7) {
            page16 = mts_OB_page[bg_w.stage][0];
            page32 = mts_OB_page[bg_w.stage][1];
            mts_ob_curr_stage = bg_w.stage;
        } else {
            page16 = mts_base[ix].p16;
            page32 = mts_base[ix].p32;
        }

        mts[ix].mltnum16 = page16 << 8;
        mts[ix].mltnum32 = page32 << 6;
        mts[ix].mltnum = page16 + page32;
        mts[ix].mltgidx16 = mts_base[ix].gix;
        mts[ix].mltgidx32 = page16 + mts_base[ix].gix;
        mts[ix].mltcshtime16 = mts_base[ix].life16;
        mts[ix].mltcshtime32 = mts_base[ix].life32;

        if (mts[ix].ext = (mts_base[ix].mode & 0x2000) != 0) {
            memreq = (mts[ix].mltnum16 * 8) + (mts[ix].mltnum32 * 8) + sizeof(PatternCollection) +
                     sizeof(TexturePoolFree) + sizeof(TexturePoolUsed);
            mts_ok[ix].key0 = Pull_ramcnt_key(memreq, mts_base[ix].type, 0, 0);
            adrs = (u8 *)Get_ramcnt_address(mts_ok[ix].key0);
            mts[ix].mltcsh16 = (PatternState *)adrs;
            adrs += mts[ix].mltnum16 * 8;
            mts[ix].mltcsh32 = (PatternState *)adrs;
            adrs += mts[ix].mltnum32 * 8;
            mts[ix].cpat = (PatternCollection *)adrs;
            adrs += sizeof(PatternCollection);
            mts[ix].tpf = (TexturePoolFree *)adrs;
            adrs += sizeof(TexturePoolFree);
            mts[ix].tpu = (TexturePoolUsed *)adrs;
            work_init_zero((s32 *)mts[ix].cpat, sizeof(PatternCollection));
            work_init_zero(&mts[ix].tpf->x16, sizeof(TexturePoolFree));
            work_init_zero(&mts[ix].tpu->x16, sizeof(TexturePoolUsed));
            init_texcash_2nd(ix);
        } else {
            memreq = mts[ix].mltnum16 * 8 + mts[ix].mltnum32 * 8;
            mts_ok[ix].key0 = Pull_ramcnt_key(memreq, mts_base[ix].type, 0, 0);
            adrs = (u8 *)Get_ramcnt_address(mts_ok[ix].key0);
            mts[ix].mltcsh16 = (PatternState *)adrs;
            adrs += mts[ix].mltnum16 * 8;
            mts[ix].mltcsh32 = (PatternState *)adrs;
        }

        mts[ix].mltbuf = texcash_melt_buffer;
        memreq = ((mts_base[ix].mode & 4) != 0) + 1;
        memreq *= (mts[ix].mltnum << 0x10);
        mts_ok[ix].key1 = Pull_ramcnt_key(memreq, mts_base[ix].type, 0, 0);
        mts[ix].attribute = mts_base[ix].attribute;
        page16 = Get_ramcnt_address(mts_ok[ix].key1);
        mlt_obj_trans_init(&mts[ix], mts_base[ix].mode, (u8 *)page16);

        if (mts[ix].ext) {
            init_texcash_2nd(ix);
        }

        mts[ix].id = ix;
        mts[ix].mode = mts_base[ix].mode & 0xFF;
        mts_ok[ix].be = 1;
        mts_ok[ix].mincg = 0;
        mts_ok[ix].min16 = 0x7FFF;
        mts_ok[ix].min32 = 0x7FFF;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", Clear_texcash_work);

// Should be called clear_texcash_work
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", _clear_texcash_work);

void purge_texcash_work(s16 ix) {
    if (mts_ok[ix].be == 0) {
        return;
    }

    if ((Test_ramcnt_key(mts_ok[ix].key0) != 0) && (Test_ramcnt_key(mts_ok[ix].key1) != 0)) {
        Push_ramcnt_key_original(mts_ok[ix].key0);
        Push_ramcnt_key_original(mts_ok[ix].key1);
    } else {
        Debug_w[10] = 2;

        while (1) {
            disp_ramcnt_free_area();
            flPrintL(5, 30, "TEXCASH KEY ERROR");
            njWaitVSync_with_N();
        }
    }

    ppgReleaseTextureHandle(&mts[ix].tex, -1);
    mts_ok[ix].be = 0;
    mts_ok[ix].key0 = 0;
    mts_ok[ix].key1 = 0;
}

const MTSBase mts_base[24] = {
    { .p16 = 0, .p32 = 0, .gix = 0, .life16 = 0, .life32 = 0, .type = 0, .mode = 0, .attribute = 0 },
    { .p16 = 1, .p32 = 1, .gix = 20, .life16 = 0, .life32 = 0, .type = 8, .mode = 4114, .attribute = 1 },
    { .p16 = 2, .p32 = 4, .gix = 30, .life16 = 8, .life32 = 8, .type = 8, .mode = 4113, .attribute = 1 },
    { .p16 = 3, .p32 = 6, .gix = 40, .life16 = 20, .life32 = 20, .type = 9, .mode = 8209, .attribute = 1 },
    { .p16 = 3, .p32 = 6, .gix = 50, .life16 = 20, .life32 = 20, .type = 9, .mode = 8209, .attribute = 1 },
    { .p16 = 1, .p32 = 4, .gix = 60, .life16 = 2, .life32 = 2, .type = 9, .mode = 8210, .attribute = 1 },
    { .p16 = 1, .p32 = 5, .gix = 70, .life16 = 0, .life32 = 0, .type = 8, .mode = 4113, .attribute = 1 },
    { .p16 = 1, .p32 = 1, .gix = 80, .life16 = 12, .life32 = 12, .type = 9, .mode = 8210, .attribute = 1 },
    { .p16 = 2, .p32 = 8, .gix = 1200, .life16 = 16, .life32 = 16, .type = 9, .mode = 4114, .attribute = 1 },
    { .p16 = 4, .p32 = 34, .gix = 500, .life16 = 20, .life32 = 20, .type = 9, .mode = 4129, .attribute = 1 },
    { .p16 = 4, .p32 = 8, .gix = 80, .life16 = 4, .life32 = 4, .type = 9, .mode = 4113, .attribute = 1 },
    { .p16 = 1, .p32 = 2, .gix = 1000, .life16 = 0, .life32 = 0, .type = 8, .mode = 4113, .attribute = 1 },
    { .p16 = 1, .p32 = 0, .gix = 1020, .life16 = 10, .life32 = 10, .type = 9, .mode = 4114, .attribute = 1 },
    { .p16 = 1, .p32 = 6, .gix = 1030, .life16 = 2, .life32 = 2, .type = 8, .mode = 8210, .attribute = 1 },
    { .p16 = 2, .p32 = 6, .gix = 1100, .life16 = 4, .life32 = 4, .type = 8, .mode = 8210, .attribute = 1 },
    { .p16 = 1, .p32 = 2, .gix = 1120, .life16 = 2, .life32 = 2, .type = 8, .mode = 4113, .attribute = 1 },
    { .p16 = 1, .p32 = 2, .gix = 960, .life16 = 2, .life32 = 2, .type = 8, .mode = 4113, .attribute = 1 },
    { .p16 = 1, .p32 = 1, .gix = 1140, .life16 = 2, .life32 = 2, .type = 8, .mode = 4114, .attribute = 1 },
    { .p16 = 1, .p32 = 1, .gix = 1100, .life16 = 0, .life32 = 0, .type = 8, .mode = 4116, .attribute = 1 },
    { .p16 = 1, .p32 = 1, .gix = 1100, .life16 = 0, .life32 = 0, .type = 8, .mode = 4116, .attribute = 1 },
    { .p16 = 1, .p32 = 1, .gix = 1100, .life16 = 0, .life32 = 0, .type = 8, .mode = 4116, .attribute = 1 },
    { .p16 = 1, .p32 = 1, .gix = 1100, .life16 = 0, .life32 = 0, .type = 8, .mode = 4116, .attribute = 1 },
    { .p16 = 1, .p32 = 1, .gix = 1100, .life16 = 0, .life32 = 0, .type = 8, .mode = 4116, .attribute = 1 },
    { .p16 = 1, .p32 = 1, .gix = 1100, .life16 = 0, .life32 = 0, .type = 8, .mode = 4116, .attribute = 1 }
};

const s16 mts_OB_page[22][2] = { { 1, 1 }, { 1, 3 }, { 1, 2 }, { 1, 1 }, { 1, 2 }, { 1, 1 }, { 1, 2 }, { 1, 2 },
                                 { 1, 2 }, { 1, 1 }, { 1, 1 }, { 1, 2 }, { 1, 1 }, { 1, 1 }, { 1, 1 }, { 1, 2 },
                                 { 1, 2 }, { 1, 4 }, { 1, 2 }, { 1, 4 }, { 1, 1 }, { 1, 2 } };
