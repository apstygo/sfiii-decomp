#include "common.h"

s16 bcdext;

u8 sbcd(u8 a, u8 b) {
    s16 c, d;

    if ((d = (b & 0xf) - (a & 0xf) - (bcdext & 1)) < 0) {
        d += 10;
        d |= 16;
    }

    c = (b & 0xf0) - (a & 0xf0) - (d & 0xf0);
    d &= 0xF;

    if ((d |= c) < 0) {
        d += 160;
        bcdext = 1;
    } else {
        bcdext = 0;
    }

    return d;
}
