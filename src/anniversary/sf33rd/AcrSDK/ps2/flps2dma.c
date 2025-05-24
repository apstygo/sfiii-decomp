#include "sf33rd/AcrSDK/ps2/flps2dma.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2DmaAddCntTag);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2DmaAddRefTag);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2DmaAddRefeTag);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2DmaAddEndTag);
#else
u32 flPS2DmaAddEndTag(u32 tag, s32 qwc, s32 irq, s32 /* unused */) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2VIF1CodeAddDirectHL);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2VIF1CalcLoadImageSize);
#else
u32 flPS2VIF1CalcLoadImageSize(u32 size) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2VIF1CalcEndLoadImageSize);
#else
u32 flPS2VIF1CalcEndLoadImageSize() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2VIF1MakeLoadImage);
#else
u32 flPS2VIF1MakeLoadImage(u32 buff_ptr, u32 irq, u32 data_ptr, u32 size, s16 dbp, s16 dbw, s16 dpsm, s16 x, s16 y,
                           s16 w, s16 h) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2VIF1MakeEndLoadImage);
#else
void flPS2VIF1MakeEndLoadImage(u32 buff_ptr, u32 irq) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2StoreImageB);
#else
void flPS2StoreImageB(u32 load_ptr, u32 size, s16 dbp, s16 dbw, s16 dpsm, s16 x, s16 y, s16 w, s16 h) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", IntGsStoreImageHandler);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2DmaInitControl);
#else
void flPS2DmaInitControl(FLPS2VIF1Control *dma_ptr, u32 queue_size, void *handler) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", literal_676_0055F3F0);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2DmaAddQueue2);
#else
s32 flPS2DmaAddQueue2(s32 type, u32 data_adrs, u32 endtag_adrs, FLPS2VIF1Control *dma_ptr) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2DmaInterrupt);
#else
s32 flPS2DmaInterrupt(s32 ch) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2DmaSend);
#else
void flPS2DmaSend() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2DmaWait);
#else
s32 flPS2DmaWait() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2dma", flPS2DmaTerminate);
#else
s32 flPS2DmaTerminate() {
    not_implemented(__func__);
}
#endif
