#ifndef PPGFILE_H
#define PPGFILE_H

#include "types.h"
#include "unknown.h"

void ppg_Initialize(void *lcmAdrs, s32 lcmSize);
void ppgSourceDataReleased(UNK_15 *dlist);
void ppgSetupCurrentDataList(UNK_15 *dlist);
void ppgSetupCurrentPaletteNumber(UNK_16 *pal, s32 num);
s32 ppgWriteQuadWithST_B(Vertex *pos, u32 col, UNK_15 *tb, s32 tix, s32 cix);
s32 ppgWriteQuadWithST_B2(Vertex *pos, u32 col, UNK_15 *tb, s32 tix, s32 cix);
s32 ppgSetupPalChunk(UNK_16 *pch, u8 *adrs, s32 size, s32 ixNum1st, s32 num, s32 /* unused */);
void ppgRenewDotDataSeqs(UNK_18 *tch, u32 gix, u32 *srcRam, u32 code, u32 size);
void ppgMakeConvTableTexDC();
s32 ppgSetupTexChunk_1st(UNK_18 *tch, u8 *adrs, s32 size, s32 ixNum1st, s32 ixNums, s32 ar, s32 arcnt);
s32 ppgSetupTexChunk_2nd(UNK_18 *tch, s32 ixNum);
s32 ppgSetupTexChunk_3rd(UNK_18 *tch, s32 ixNum, u32 attribute);

#endif // PPGFILE_H
