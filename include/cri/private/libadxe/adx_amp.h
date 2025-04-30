#ifndef ADX_AMP_H
#define ADX_AMP_H

#include "types.h"
#include <cri/cri_xpts.h>
#include <cri/sj.h>

typedef struct {
    /* 0x00 */ Char8 pad0[1];
    /* 0x01 */ Sint8 unk1;
    /* 0x02 */ Sint8 unk2;
    /* 0x03 */ Char8 pad3[1];
    /* 0x04 */ SJ unk4[1];
    /* 0x08 */ Char8 pad8[4];
    /* 0x0C */ SJ unkC[1];
    /* 0x10 */ Char8 pad10[4];
    /* 0x14 */ Sint32 unk14[6];
    /* 0x2C */ Sint32 unk2C;
} ADXAMP_OBJ; /* size = 0x30 */

typedef ADXAMP_OBJ *ADXAMP;

void ADXAMP_Start(ADXAMP);

#endif // ADX_AMP_H
