#ifndef ADX_SJD_H
#define ADX_SJD_H

#include <cri/cri_xpts.h>
#include <cri/sj.h>

#define ADXSJD_MAX_OBJ 16

typedef struct {
    // total size: 0xA0
    Char8 pad0[3];
    Sint8 unk3;
    ADXB adxb;
    Char8 pad8[4];
    SJ sj[2];
    Char8 pad14[8];
    SJCK chunks[2];
    Sint32 unk2C;
    Sint32 unk30;
    Sint32 unk34;
    Sint32 unk38;
    Sint32 unk3C;
    Sint32 unk40;
    Sint32 unk44;
    Char8 pad48[80];
    Sint32 unk98;
    Char8 pad9C[4];
} ADXSJD_OBJ;

typedef ADXSJD_OBJ *ADXSJD;

#define ADXSJD_DEFINED

ADXSJD ADXSJD_Create(SJ, Sint32, SJ *);
void ADXSJD_Start(ADXSJD);
void ADXSJD_Stop(ADXSJD);
Sint32 ADXSJD_GetDecNumSmpl(ADXSJD);
Sint32 ADXSJD_GetOutBps(ADXSJD);
Sint32 ADXSJD_GetSfreq(ADXSJD);
Sint32 ADXSJD_GetTotalNumSmpl(ADXSJD);
Sint32 ADXSJD_GetOutBps(ADXSJD);
Sint32 ADXSJD_GetSfreq(ADXSJD);
Sint32 ADXSJD_GetTotalNumSmpl(ADXSJD);
Sint32 ADXSJD_GetDefOutVol(ADXSJD);
void ADXSJD_SetLnkSw(ADXSJD sjd, Sint32 sw);

#endif
