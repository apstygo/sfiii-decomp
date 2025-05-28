#include "sf33rd/Source/PS2/mc/knjsub.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", literal_225_005601F0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjInit);
#else
void KnjInit(u32 type, u32 adrs, u32 disp_max, u32 top_dbp) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjFinish);
#else
void KnjFinish() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjUseCheck);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjSetSize);
#else
void KnjSetSize(s32 dispw, s32 disph) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjLocate);
#else
void KnjLocate(s32 x, s32 y) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjSetColor);
#else
void KnjSetColor(u32 color) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjSetAlpha);
#else
void KnjSetAlpha(u32 alpha) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjSetRgb);
#else
void KnjSetRgb(u32 color) {
    not_implemented(__func__);
}
#endif

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

#if defined(TARGET_PS2)
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", literal_423_00560210);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", KnjFlush);
#else
void KnjFlush() {
    not_implemented(__func__);
}
#endif

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

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", is_unicode_han);

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

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", make_pal_pkt);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", make_fnt_pkt);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/knjsub", make_fbg_pkt);
