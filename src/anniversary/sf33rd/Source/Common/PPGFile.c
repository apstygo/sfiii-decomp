#include "sf33rd/Source/Common/PPGFile.h"
#include "common.h"

typedef struct {
    // total size: 0x34
    UNK_15 *cur;    // offset 0x0, size 0x4
    u16 hanPal;     // offset 0x4, size 0x2
    u16 hanTex;     // offset 0x6, size 0x2
    _MEMMAN_OBJ mm; // offset 0x8, size 0x2C
} PPG_W;

const u8 pplColorModeWidth[4] = { 0xF, 0x3F, 0xFF, 0 };

PPG_W ppg_w;
s16 *dctex_linear;

void ppg_Initialize(void *lcmAdrs, s32 lcmSize) {
    if (lcmAdrs == NULL) {
        while (1) {}
    }

    mmHeapInitialize(&ppg_w.mm, lcmAdrs, lcmSize, 0x10, "- for PPG -");
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgMallocF);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgMallocR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgFree);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgPullDecBuff);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgPushDecBuff);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgTexSrcDataReleased);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgPalSrcDataReleased);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgSourceDataReleased);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgSetupCurrentDataList);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgSetupCurrentPaletteNumber);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgWriteQuadWithST_A);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgWriteQuadWithST_A2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgWriteQuadOnly);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgWriteQuadOnly2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgWriteQuadWithST_B);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgWriteQuadWithST_B2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Common/PPGFile", ppgWriteQuadUseTrans);

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
