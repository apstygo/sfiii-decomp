#ifndef BCD_H
#define BCD_H

#include "types.h"

extern s16 bcdext; // size: 0x2, address: 0x578A9C

u8 sbcd(u8 a, u8 b);

#endif
