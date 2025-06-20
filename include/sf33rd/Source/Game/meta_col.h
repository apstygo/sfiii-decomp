#ifndef META_COL_H
#define META_COL_H

#include "types.h"

extern u16 hi_meta[2][2][64]; // size: 0x200, address: 0x5E3B50
extern u16 metamor_original[2][5][64]; // size: 0x500, address: 0x5E3650

void metamor_color_trans(s16 wkid);
void metamor_color_copy(s16 wkid);
void metamor_color_store(s16 wkid);
void metamor_color_restore(s16 wkid);

#endif
