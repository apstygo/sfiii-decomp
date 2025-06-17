#ifndef LIBADXE_STRUCTS_H
#define LIBADXE_STRUCTS_H

#include <cri/cri_xpts.h>
#include <cri/sj.h>

#include <libcdvd.h>
#include <sif.h>

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
    /* 0xB4 */ Sint32 unkB4;
    /* 0xB8 */ Sint32 unkB8;
    /* 0xBC */ Sint32 unkBC;
    /* 0xC0 */ Sint32 unkC0;
    /* 0xC4 */ Sint32 unkC4;
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
    SJ sji;
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

// PS2PSJ

typedef struct {
    Sint8 used;
    char pad1[3];
    Sint32 unk4;
    SJ unk8;
    Sint32 unkC;
    SJCK chunk;
} PS2PSJ_OBJ;

typedef PS2PSJ_OBJ *PS2PSJ;

// DTR

typedef struct {
    /* 0x00 */ Sint8 unk0;
    /* 0x01 */ Sint8 unk1;
    /* 0x02 */ Sint8 unk2;
    /* 0x04 */ SJ unk4;
    /* 0x08 */ SJ unk8;
    /* 0x0C */ SJCK unkC;
    /* 0x14 */ SJCK unk14;
    /* 0x1C */ sceSifDmaData dma_data;
    /* 0x2C */ Sint32 unk2C;
    /* 0x30 */ Sint32 unk30;
    /* 0x34 */ Sint32 unk34;
    /* 0x38 */ Sint32 unk38;
    /* 0x3C */ Sint32 unk3C;
} DTR_OBJ;

typedef DTR_OBJ *DTR;

// ADXRNA

typedef struct {
    Sint8 used;
    Sint32 maxnch;
    PS2PSJ psj[2];
    DTR dtr[2];
    SJ sjo[2];
    Sint32 unk20;
    Sint32 unk24;
    Sint32 unk28;
    Sint32 unk2C;
    Sint8 unk30;
    Sint8 unk31;
    Sint8 num_chan;
    Sint8 unk33;
    Sint32 sfreq;
    Sint32 unk38;
    Sint32 out_vol;
    Sint32 unk40;
    Sint32 pan[2];
    Sint32 unk4C[2];
    Sint32 unk54;
    Sint32 unk58;
    Sint8 unk5C;
    Sint8 unk5D;
    Sint8 unk5E;
    Sint8 unk5F;
    char pad60[4];
} ADXRNA_OBJ;

typedef ADXRNA_OBJ *ADXRNA;

#define ADXRNA_DEFINED

// DTX

typedef void (*RcvCbf)(void *, void *, Sint32);
typedef void (*SndCbf)(void *, void *, Sint32);

typedef struct {
    // total size: 0x44
    Sint8 unk0; // used or state
    Sint8 unk1;
    Sint8 unk2;
    Sint8 unk3;
    Sint32 unk4;
    Sint32 unk8;
    void *unkC;
    Sint32 unk10;
    Sint32 *unk14;
    void *unk18;
    Sint32 unk1C;
    RcvCbf rcvcbf;
    Sint32 unk24;
    SndCbf sndcbf;
    Sint32 unk2C;
    sceSifDmaData dma_data;
    Sint32 unk40;
} DTX_OBJ;

typedef DTX_OBJ *DTX;

// ADXSTM

typedef struct {
    Sint8 unk0;
    Sint8 stat;
    Sint8 read_flg;
    Sint8 unk3;
    SJ sj;
    Sint32 cvfs;
    Sint32 unkC; // some offset
    Sint32 file_len;
    Sint32 file_sct;
    Sint32 unk18;
    Sint32 unk1C;
    Sint32 unk20;
    SJCK unk24;
    Sint32 req_rd_size;
    Sint32 eos;
    Uint32 unk34;
    void (*eos_callback)(void *);
    void *eos_callback_context;
    Sint32 unk40;
    Sint8 pause;
    Sint8 unk45;
    Sint8 unk46;
    Sint8 unk47;
    Sint8 unk48;
    Sint8 unk49;
    char pad4A[6];
    const Char8 *fname;
    void *dir;
    Sint32 cur_ofst;
    Uint32 unk5C;
} ADXSTM_OBJ;

typedef ADXSTM_OBJ *ADXSTM;

#define ADXSTM_DEFINED

// LSC

#define LSC_MAX_OBJ 16
#define LSC_MAX_STM 16

typedef struct {
    Sint32 id;
    const Char8 *fname;
    Sint32 unk8;
    void *dir;
    Sint32 unk10;
    Sint32 unk14;
    Sint32 stat;
    Sint32 rd_sct; // maybe void*?
} LSC_STM;

typedef struct {
    Sint8 used;
    Sint8 stat;
    Sint8 unk2;
    Sint8 lp_flg;
    Sint8 unk4;
    SJ sj;
    Sint32 unkC;
    Sint32 unk10;
    Sint32 flow_limit;
    Sint32 unk18;
    Sint32 last_stm_index;
    Sint32 unk20;
    Sint32 num_stm;
    ADXSTM stm_hndl;
    Sint32 unk2C;
    char pad30[4];
    Sint32 unk34;
    LSC_STM stm[LSC_MAX_STM];
} LSC_OBJ;

typedef LSC_OBJ *LSC;

// SRD

typedef void *SRD;

// cvfs

typedef struct {
    /* 0x00 */ void (*ExecServer)();
    /* 0x04 */ void (*EntryErrFunc)();
    /* 0x08 */ Sint32 (*GetFileSize)();
    /* 0x0C */ void (*unkC)();
    /* 0x10 */ void *(*Open)(Char8 *device_name, void *, Sint32);
    /* 0x14 */ void (*Close)(void *fd);
    /* 0x18 */ Sint32 (*Seek)(void *fd, Sint32 offset, Sint32 whence);
    /* 0x1C */ Sint32 (*Tell)(void *fd);
    /* 0x20 */ Sint32 (*ReqRd)(void *fd);
    /* 0x24 */ void (*unk24)();
    /* 0x28 */ void (*StopTr)();
    /* 0x2C */ Sint32 (*GetStat)(void *fd);
    /* 0x30 */ void (*GetSctLen)();
    /* 0x34 */ void (*unk34)();
    /* 0x38 */ void (*GetNumTr)();
    /* 0x3C */ void (*unk3C)();
    /* 0x40 */ void (*IsExistFile)();
    /* 0x44 */ void (*unk44)();
    /* 0x48 */ void (*unk48)();
    /* 0x4C */ void (*unk4C)();
    /* 0x50 */ void (*unk50)();
    /* 0x54 */ void (*unk54)();
    /* 0x58 */ void (*unk58)();
    /* 0x5C */ void (*unk5C)();
    /* 0x60 */ Sint32 (*OptFn1)();
    /* 0x64 */ void (*unk64)();
} CVFSDevice;

// DVG_CI

#define DVG_CI_MAX_OBJ 40

typedef struct {
    /* 0x00 */ Sint8 used;
    /* 0x01 */ Sint8 unk1;
    /* 0x02 */ Sint8 stat;
    /* 0x03 */ Sint8 unk3;
    /* 0x04 */ Sint32 unk4;
    /* 0x08 */ Sint32 unk8;
    /* 0x0C */ Sint32 unkC;
    /* 0x10 */ Sint32 unk10;
    /* 0x14 */ Sint32 unk14;
    /* 0x18 */ void *unk18;
    /* 0x1C */ SRD srd;
    /* 0x20 */ sceCdlFILE unk20;
    /* 0x44 */ sceCdRMode unk44;
} DVG_CI_OBJ; /* total size: 0x48 */

typedef DVG_CI_OBJ *DVG_CI;

typedef struct {
    Uint32 lsn;
    Uint32 size;
} DVG_FLIST_SUB;

typedef struct {
    Sint32 unk0;
    Sint32 unk4;
    Sint32 unk8;
    Sint32 unkC;
} DVG_FLIST_TBL;

#endif
