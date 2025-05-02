#ifndef LIBADXE_STRUCTS_H
#define LIBADXE_STRUCTS_H

#include <cri/cri_xpts.h>
#include <cri/sj.h>

// ADXPD

typedef struct {
    char pad0[0x3C];
} ADXPD_OBJ;

typedef ADXPD_OBJ *ADXPD;

// ADXB

typedef struct {
    char pad0[0x10];
} ADXB_UNK_1;

typedef struct {
    /* 0x00 */ Sint16 unk0;
    /* 0x02 */ char pad2[2];
    /* 0x04 */ Sint32 unk4;
    /* 0x08 */ ADXPD adxpd;
    /* 0x0C */ char padC[2];
    /* 0x0E */ Sint8 unkE;
    /* 0x0F */ char padF[5];
    /* 0x14 */ Sint32 unk14;
    /* 0x18 */ Sint32 unk18;
    /* 0x1C */ char pad1C[0x1C];
    /* 0x38 */ Sint32 unk38;
    /* 0x3C */ Sint32 unk3C;
    /* 0x40 */ Sint32 unk40;
    /* 0x44 */ Sint32 unk44;
    /* 0x48 */ char pad48[0x30];
    /* 0x78 */ Sint32 (*get_wr)(void *, Sint32 *, Sint32 *, Sint32 *);
    /* 0x7C */ void *object;
    /* 0x80 */ Sint32 unk80;
    /* 0x84 */ Sint32 unk84;
    /* 0x88 */ Sint32 unk88;
    /* 0x8C */ Sint32 unk8C;
    /* 0x90 */ char pad90[8];
    /* 0x98 */ Sint16 unk98;
    /* 0x9A */ Sint16 unk9A;
    /* 0x9C */ char pad9C[0x12];
    /* 0xB0 */ Sint32 unkB0;
    /* 0xB4 */ char padB4[8];
    /* 0xBC */ Sint32 unkBC;
    /* 0xC0 */ char padC0[8];
    /* 0xC8 */ Sint32 unkC8;
    /* 0xCC */ ADXB_UNK_1 adxb_unk_1;
    /* 0xDC */ Sint16 unkDC;
    /* 0xDE */ Sint16 unkDE;
    /* 0xE0 */ Sint16 unkE0;
    /* 0xE2 */ char padE2[2];
    /* 0xE4 */ Sint32 unkE4;
    /* 0xE8 */ char padE8[8];
} ADXB_OBJ;

typedef ADXB_OBJ *ADXB;

// ADXSJD

typedef struct {
    // total size: 0xA0
    Sint8 used;
    Sint8 state;
    Sint8 maxnch;
    Sint8 unk3;
    ADXB adxb;
    SJ unk8;
    SJ sjo[2];
    Char8 pad14[8];
    SJCK chunks[2];
    Sint32 unk2C;
    Sint32 unk30;
    Sint32 unk34;
    Sint32 unk38;
    Sint32 unk3C;
    Sint32 unk40;
    Sint32 unk44;
    Sint32 unk48;
    Sint32 unk4C;
    Sint32 unk50;
    Sint32 unk54;
    Char8 pad58[64];
    Sint32 unk98;
    Sint32 lnkflg;
} ADXSJD_OBJ;

typedef ADXSJD_OBJ *ADXSJD;

#define ADXSJD_DEFINED

// ADXAMP

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

#endif
