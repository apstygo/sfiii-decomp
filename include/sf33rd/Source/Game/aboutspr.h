#ifndef ABOUTSPR_H
#define ABOUTSPR_H

#include "structs.h"
#include "types.h"

extern MultiTexture mts[24]; // size: 0x960, address: 0x6B4070

void Init_load_on_memory_data();
void shadow_drawing(WORK *wk, s16 bsy);
void reset_dma_group(u16 num);
s32 sort_push_request4(WORK *wk);

#endif
