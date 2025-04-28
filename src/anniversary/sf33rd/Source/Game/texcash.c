#include "common.h"

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

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_250_00554C48);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_251_00554C50);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_252_00554C58);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_253_00554C60);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", disp_texcash_free_area);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", search_texcash_free_area);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", init_texcash_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", init_texcash_before_process);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", init_texcash_2nd);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_379_00554C70);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", texture_cash_update);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_413_00554C90);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_414_00554CB0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", update_with_tpu_free);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", get_my_trans_mode);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", make_texcash_work);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", Clear_texcash_work);

// Should be called clear_texcash_work
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", _clear_texcash_work);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", literal_447_00554CD0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/texcash", purge_texcash_work);

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
