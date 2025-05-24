#include "sf33rd/Source/Game/color3rd.h"
#include "common.h"
#include "sf33rd/AcrSDK/common/plcommon.h"
#include "sf33rd/AcrSDK/ps2/flps2vram.h"
#include "structs.h"

typedef struct {
    // total size: 0x1C00
    u16 col[2][28][64]; // offset 0x0, size 0x1C00
} COL;

// bss
u16 colPalBuffDC[1024];
u16 ColorRAM[512][64];
Col3rd_W col3rd_w;

// sbss
COL *plcol[2];
PixelFormat palFormRam;
PixelFormat palFormSrc;
s32 palFormConv;

// forward decls
void palConvRowTim2CI8Clut(u16 *src, u16 *dst, s32 size);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", q_ldreq_color_data);
#else
void q_ldreq_color_data(REQ *curr) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", cseTsbSetBankAddr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", cseMemMapSetPhdAddr);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", load_any_color);
#else
void load_any_color(u16 ix, u8 kokey) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", set_hitmark_color);
#else
void set_hitmark_color() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", init_trans_color_ram);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", init_color_trans_req);
#else
void init_color_trans_req() {
    not_implemented(__func__);
}
#endif

void push_color_trans_req(s16 from_col, s16 to_col) {
    palCopyGhostDC(to_col << 6, 64, ColorRAM[from_col]);
    palUpdateGhostDC();
}

void palCopyGhostDC(s32 ofs, s32 cnt, void *data) {
    s32 i;
    u16 *srcAdrs = data;
    u16 *dstAdrs = &colPalBuffDC[ofs];

    for (i = 0; i < cnt; i++) {
        *dstAdrs++ = *srcAdrs++;
    }

    col3rd_w.upBits = col3rd_w.upBits | (1 << (ofs / 64));
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", palConvSrcToRam);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", palCreateGhost);
#else
void palCreateGhost() {
    not_implemented(__func__);
}
#endif

Palette *palGetChunkGhostDC() {
    return &col3rd_w.palDC;
}

Palette *palGetChunkGhostCP3() {
    return &col3rd_w.palCP3;
}

void palUpdateGhostDC() {
    plContext bits;
    s32 i;
    u16 *srcAdrs;
    u16 *dstAdrs;

    for (i = 0; i < col3rd_w.palDC.total; i++) {
        if (col3rd_w.upBits & (1 << i)) {
            flLockPalette(NULL, col3rd_w.palDC.handle[i], &bits, 2);
            dstAdrs = bits.ptr;
            srcAdrs = &colPalBuffDC[i << 6];
            palConvRowTim2CI8Clut(srcAdrs, dstAdrs, 0x40);
            flUnlockPalette(col3rd_w.palDC.handle[i]);
        }
    }

    col3rd_w.upBits = 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", palUpdateGhostCP3);

void palConvRowTim2CI8Clut(u16 *src, u16 *dst, s32 size) {
    s32 i;
    static u8 clut_tbl[32] = { 0, 1, 2,  3,  4,  5,  6,  7,  16, 17, 18, 19, 20, 21, 22, 23,
                               8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30, 31 };

    for (i = 0; i < size; i++) {
        dst[(i & 0xE0) + clut_tbl[i & 0x1F]] = src[i];
    }
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", hitmark_color);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/color3rd", color_file);
