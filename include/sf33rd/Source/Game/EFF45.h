#ifndef EFF45_H
#define EFF45_H

#include "structs.h"
#include "types.h"

extern MessageData Message_Data[4]; // size: 0x30, address: 0x578ED0

s32 effect_45_init(u8 id, s16 sync_bg, s16 master_player);

#endif
