#include "common.h"
#include <cri/private/libadxe/sj_err.h>
#include <cri/private/libadxe/sj_rbf.h>

#include <cri/cri_xpts.h>

typedef struct {
    SJ_OBJ sj;
    Sint32 used;
    UUID *uuid;
    Sint32 unkC;
    Sint32 unk10;
    Sint32 unk14;
    Sint32 unk18;
    Sint8 *buf;
    Sint32 bsize;
    Sint32 xsize;
    Sint32 unk28;
    Sint32 unk2C;
    Sint32 unk30;
    Sint32 unk34;
    void (*err_func)(void *obj, Sint32 ecode);
    void *err_obj;
} SJRBF_OBJ;

typedef SJRBF_OBJ *SJRBF;

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

#define SJRBF_MAX_OBJ 256

// forward decls
void SJRBF_Reset(SJRBF sjrbf);

// data
extern Char8 *volatile sj_build;
extern SJ_IF sjrbf_vtbl;
extern Sint32 sjrbf_init_cnt;
extern SJRBF_OBJ sjrbf_obj[SJRBF_MAX_OBJ];

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/sj_rbf", D_0055E640);

const UUID sjrbf_uuid = {
    .Data1 = 0x3B9A9E81, .Data2 = 0x0DBB, .Data3 = 0x11D2, .Data4 = { 0xA6, 0xBF, 0x44, 0x45, 0x53, 0x54, 0x00, 0x00 }
};

void SJRBF_Error(void *obj, Sint32 ecode) {
    SJERR_CallErr("SJRBF Error");
}

void SJRBF_Init() {
    sj_build;

    SJCRS_Lock();

    if (sjrbf_init_cnt == 0) {
        memset(sjrbf_obj, 0, sizeof(sjrbf_obj));
    }

    sjrbf_init_cnt += 1;
    SJCRS_Unlock();
}

void SJRBF_Finish() {
    SJCRS_Lock();

    if (--sjrbf_init_cnt == 0) {
        memset(sjrbf_obj, 0, sizeof(sjrbf_obj));
    }

    SJCRS_Unlock();
}

SJ SJRBF_Create(Sint8 *buf, Sint32 bsize, Sint32 xsize) {
    SJRBF sjrbf;
    Sint32 i;

    SJCRS_Lock();

    for (i = 0; i < SJRBF_MAX_OBJ; i++) {
        if (sjrbf_obj[i].used == 0) {
            break;
        }
    }

    sjrbf = NULL;

    if (i != SJRBF_MAX_OBJ) {
        sjrbf = &sjrbf_obj[i];
        sjrbf->used = 1;
        sjrbf->sj.vtbl = &sjrbf_vtbl;
        sjrbf->buf = buf;
        sjrbf->bsize = bsize;
        sjrbf->xsize = xsize;
        sjrbf->uuid = &sjrbf_uuid;
        sjrbf->err_func = SJRBF_Error;
        sjrbf->err_obj = sjrbf;
        SJRBF_Reset(sjrbf);
    }

    SJCRS_Unlock();
    return sjrbf;
}

void SJRBF_Destroy(SJRBF sjrbf) {
    SJCRS_Lock();

    if (sjrbf != NULL) {
        memset(sjrbf, 0, sizeof(SJRBF_OBJ));
        sjrbf->used = 0;
    }

    SJCRS_Unlock();
}

UUID *SJRBF_GetUuid(SJRBF sjrbf) {
    return sjrbf->uuid;
}

void SJRBF_EntryErrFunc(SJRBF sjrbf, void (*func)(void *obj, Sint32 ecode), void *obj) {
    sjrbf->err_func = func;
    sjrbf->err_obj = obj;
}

void SJRBF_Reset(SJRBF sjrbf) {
    SJCRS_Lock();
    sjrbf->unk34 = 0;
    sjrbf->unkC = 0;
    sjrbf->unk14 = 0;
    sjrbf->unk18 = 0;
    sjrbf->unk28 = 0;
    sjrbf->unk2C = 0;
    sjrbf->unk30 = 0;
    sjrbf->unk10 = sjrbf->bsize;
    SJCRS_Unlock();
}

Sint32 SJRBF_GetNumData(SJRBF sjrbf, Sint32 id) {
    if (id == 1) {
        return sjrbf->unkC;
    } else if (id == 0) {
        return sjrbf->unk10;
    } else {
        if (sjrbf->err_func != NULL) {
            sjrbf->err_func(sjrbf->err_obj, SJ_ERR_PRM);
        }

        return 0;
    }
}

void SJRBF_GetChunk(SJRBF sjrbf, Sint32 id, Sint32 nbyte, SJCK *ck) {
    SJCRS_Lock();

    if (id == 0) {
        ck->len = MIN(MIN(sjrbf->unk10, sjrbf->bsize - sjrbf->unk14 + sjrbf->xsize), nbyte);
        ck->data = sjrbf->buf + sjrbf->unk14;
        sjrbf->unk14 = (sjrbf->unk14 + ck->len) % sjrbf->bsize;
        sjrbf->unk10 -= ck->len;
        sjrbf->unk28 += ck->len;
    } else if (id == 1) {
        ck->len = MIN(MIN(sjrbf->unkC, sjrbf->bsize - sjrbf->unk18 + sjrbf->xsize), nbyte);
        ck->data = sjrbf->buf + sjrbf->unk18;
        sjrbf->unk18 = (sjrbf->unk18 + ck->len) % sjrbf->bsize;
        sjrbf->unkC -= ck->len;
        sjrbf->unk30 += ck->len;
    } else {
        ck->len = 0;
        ck->data = NULL;

        if (sjrbf->err_func != NULL) {
            sjrbf->err_func(sjrbf->err_obj, SJ_ERR_PRM);
        }
    }

    SJCRS_Unlock();
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/sj_rbf", SJRBF_PutChunk);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/sj_rbf", SJRBF_UngetChunk);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/sj_rbf", SJRBF_IsGetChunk);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/sj_rbf", SJRBF_GetBufPtr);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/sj_rbf", SJRBF_GetBufSize);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/sj_rbf", SJRBF_GetXtrSize);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/sj_rbf", SJRBF_SetFlowCnt);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/sj_rbf", SJRBF_GetFlowCnt);
