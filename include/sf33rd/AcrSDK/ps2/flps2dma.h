#ifndef FLPS2DMA_H
#define FLPS2DMA_H

#include "structs.h"
#include "types.h"

// DMA code
#define DMArefe (0 << 28)
#define DMAcnt (1 << 28)
#define DMAnext (2 << 28)
#define DMAref (3 << 28)
#define DMArefs (4 << 28)
#define DMAcall (5 << 28)
#define DMAret (6 << 28)
#define DMAend (7 << 28)

uintptr_t flPS2DmaAddEndTag(uintptr_t tag, s32 qwc, s32 irq, s32 /* unused */);
void flPS2DmaInitControl(FLPS2VIF1Control* dma_ptr, u32 queue_size, void* handler);
s32 flPS2DmaAddQueue2(s32 type, uintptr_t data_adrs, uintptr_t endtag_adrs, FLPS2VIF1Control* dma_ptr);
s32 flPS2DmaInterrupt(s32 ch);
void flPS2DmaSend();
s32 flPS2DmaWait();
s32 flPS2DmaTerminate();
u32 flPS2VIF1CalcEndLoadImageSize();
void flPS2VIF1MakeEndLoadImage(uintptr_t buff_ptr, u32 irq);
u32 flPS2VIF1CalcLoadImageSize(u32 size);
uintptr_t flPS2VIF1MakeLoadImage(uintptr_t buff_ptr, u32 irq, uintptr_t data_ptr, u32 size, s16 dbp, s16 dbw, s16 dpsm,
                                 s16 x, s16 y, s16 w, s16 h);
void flPS2StoreImageB(uintptr_t load_ptr, u32 size, s16 dbp, s16 dbw, s16 dpsm, s16 x, s16 y, s16 w, s16 h);
uintptr_t flPS2DmaAddRefTag(uintptr_t tag, s32 qwc, uintptr_t data_adrs, s32 irq, s32 /* unused */);
uintptr_t flPS2DmaAddRefeTag(uintptr_t tag, s32 qwc, uintptr_t data_adrs, s32 irq, s32 /* unused */);

#endif
