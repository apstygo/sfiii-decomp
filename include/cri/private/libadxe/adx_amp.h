#ifndef ADX_AMP_H
#define ADX_AMP_H

#include "types.h"
#include <cri/sj.h>

typedef struct {
    /* 0x00 */ char pad0[1];
    /* 0x01 */ s8 unk1;
    /* 0x02 */ s8 unk2;
    /* 0x03 */ char pad3[1];
    /* 0x04 */ SJ unk4[1];
    /* 0x08 */ char pad8[4];
    /* 0x0C */ SJ unkC[1];
    /* 0x10 */ char pad10[4];
    /* 0x14 */ s32 unk14[6];
    /* 0x2C */ s32 unk2C;
} ADXAMP; /* size = 0x30 */

#endif // ADX_AMP_H
