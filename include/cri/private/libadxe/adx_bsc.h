#ifndef ADX_BSC_H
#define ADX_BSC_H

#include "types.h"
#include <cri/private/libadxe/adx_xpnd.h>

typedef struct {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x20];
    s32 unk3C;
    s32 unk40;
    char pad44[0x44];
    s32 unk88;
    s32 unk8C;
} ADXB_UNK_0;

typedef struct {
    char pad0[0x10];
} ADXB_UNK_1;

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ char pad2[2];
    /* 0x04 */ s32 unk4;
    /* 0x08 */ ADXPD adxpd;
    /* 0x0C */ char padC[8];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ char pad1C[0x1C];
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
    /* 0x48 */ char pad48[0x30];
    /* 0x78 */ s32 unk78;
    /* 0x7C */ s32 unk7C;
    /* 0x80 */ s32 unk80;
    /* 0x84 */ s32 unk84;
    /* 0x88 */ char pad88[0x10];
    /* 0x98 */ s16 unk98;
    /* 0x9A */ s16 unk9A;
    /* 0x9C */ char pad9C[0x12];
    /* 0xB0 */ s32 unkB0;
    /* 0xB4 */ char padB4[8];
    /* 0xBC */ s32 unkBC;
    /* 0xC0 */ char padC0[8];
    /* 0xC8 */ s32 unkC8;
    /* 0xCC */ ADXB_UNK_1 adxb_unk_1;
    /* 0xDC */ s16 unkDC;
    /* 0xDE */ s16 unkDE;
    /* 0xE0 */ s16 unkE0;
    /* 0xE2 */ char padE2[2];
    /* 0xE4 */ s32 unkE4;
    /* 0xE8 */ char padE8[8];
} ADXB_OBJ;

typedef ADXB_OBJ *ADXB;

#endif // ADX_BSC_H
