#ifndef CHARID_H
#define CHARID_H

#include "structs.h"
#include "types.h"

extern UNK_Data *parabora_own_table[20]; // size: 0x50, address: 0x578CD0

extern CharInitData char_init_data[23]; // size: 0x8FC, address: 0x595C60

void set_char_base_data(WORK *wk);
void copy_char_base_data();

#endif
