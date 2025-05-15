#include "common.h"
#include <cri/private/libadxe/dtx.h>

#include <cri/cri_xpts.h>
#include <cri/sj.h>
#include <eekernel.h>
#include <sifdev.h>

typedef struct {
    Sint32 unk0;
    SJ sj;
} SJX_UNK_0;

typedef struct {
    Sint8 unk0;
    Sint8 id;
    Sint16 unk2;
    SJX_UNK_0 *unk4;
    SJCK chunk;
} SJX_UNK_1;

typedef struct {
    Sint32 count;
    Sint32 reserved4;
    Sint32 reserved8;
    Sint32 reservedC;
    SJX_UNK_1 items[0];
} SJX_UNK_2;

typedef struct {
    Sint8 used;
    Sint8 unk1;
    Sint16 unk2;
    SJ sj;
    Sint32 unk8;
    Sint32 unkC;
    SJX_UNK_0 *unk10;
} SJX_OBJ;

typedef SJX_OBJ *SJX;

#define SJX_MAX_OBJ 32

extern Sint32 sjx_init_cnt;          // 11
extern void *sjx_eewk;               // 15
extern void *sjx_iopwk0;             // 19
extern void *sjx_iopwk;              // 23
extern SJX_OBJ sjx_obj[SJX_MAX_OBJ]; // 32
extern DTX sjx_dtx;                  // 195
extern Sint32 sjx_wklen;             // 199
extern Sint8 sjx_ee_work[0x8D0];     // 203

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/sjx", D_0055E6E0);

void sjx_rcvcbf(void *obj, void *arg1, Sint32 arg2) {
    SJX_UNK_2 *head = arg1;
    SJX_UNK_1 *cur;
    Sint32 count;
    Sint32 i;

    if (head == NULL) {
        while (1) {}
    }

    count = head->count;
    SJCRS_Lock();

    for (i = 0; i < count; i++) {
        cur = &head->items[i];

        if (cur->unk0 == 0) {
            SJ_PutChunk(cur->unk4->sj, cur->id, &cur->chunk);
        }
    }

    SJCRS_Unlock();
}

void sjx_sndcbf(void *object, void *arg1, Sint32 arg2) {
    SJCK chunk;
    SJX sjx;
    Sint32 j;
    Sint32 i;
    SJX_UNK_2 *head = arg1;
    SJX_UNK_1 *items = head->items;
    SJX_UNK_1 *item;

    j = 0;

    SJCRS_Lock();

    for (i = 0; i < SJX_MAX_OBJ; i++) {
        sjx = &sjx_obj[i];

        if (sjx->used != 1) {
            continue;
        }

        while (1) {
            if (j == 0x80) {
                goto end;
            }

            SJ_GetChunk(sjx->sj, sjx->unkC, SJCK_LEN_MAX, &chunk);

            if (chunk.len == 0) {
                break;
            }

            items[j].unk0 = 0;
            items[j].unk4 = sjx->unk10;
            items[j].id = sjx->unkC;
            items[j].chunk = chunk;
            items[j].unk2 = sjx->unk2;
            j++;
        }
    }

end:
    SJCRS_Unlock();
    head->count = j;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/sjx", sjx_rcvcbf_iop);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/sjx", sjx_sndcbf_iop);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/sjx", SJX_ExecServer);

void SJX_Init() {
    if (sjx_init_cnt == 0) {
        memset(sjx_ee_work, 0, sizeof(sjx_ee_work));
        DTX_Init();
        sjx_wklen = 0x880;
        sjx_eewk = (void *)(((Uint32)sjx_ee_work + 0x40) & ~0x3F);

        if (sjx_iopwk0 == NULL) {
            sjx_iopwk0 = sceSifAllocIopHeap(0x8D0);

            if (sjx_iopwk0 == NULL) {
                scePrintf("E0100301: SJX_Init can't allocate IOP Heap\n");
                while (1) {}
            }
        }

        sjx_iopwk = (void *)(((Uint32)sjx_iopwk0 + 0x40) & ~0x3F);
        sjx_dtx = DTX_Create(0, sjx_eewk, sjx_iopwk, sjx_wklen);

        if (sjx_dtx == NULL) {
            scePrintf("E0100302: SJX_Init can't create DTX\n");
            while (1) {}
        }

        DTX_SetRcvCbf(sjx_dtx, sjx_rcvcbf, NULL);
        DTX_SetSndCbf(sjx_dtx, sjx_sndcbf, NULL);
        DTX_CallUrpc(3, NULL, 0, NULL, 0);
    }

    sjx_init_cnt += 1;
}

void SJX_Finish() {
    if (--sjx_init_cnt == 0) {
        DTX_Destroy(sjx_dtx);
        sjx_dtx = NULL;

        if (sjx_iopwk0 != NULL) {
            sceSifFreeIopHeap(sjx_iopwk0);
            sjx_iopwk0 = NULL;
        }

        DTX_Finish();
    }
}

SJX SJX_Create(SJ sj, Sint32 arg1, Sint32 arg2) {
    Sint32 rpc_buf[4];
    SJX sjx;
    Sint32 i;

    for (i = 0; i < SJX_MAX_OBJ; i++) {
        sjx = &sjx_obj[i];

        if (sjx->used == 0) {
            break;
        }
    }

    if (i == SJX_MAX_OBJ) {
        return NULL;
    }

    memset(sjx, 0, sizeof(SJX_OBJ));
    sjx->sj = sj;
    sjx->unkC = arg2;
    sjx->unk8 = arg1;
    rpc_buf[0] = (Sint32)sj;
    rpc_buf[1] = arg1;
    rpc_buf[2] = arg2;
    rpc_buf[3] = (Sint32)sjx;
    sjx->unk10 = DTX_CallUrpc(0, rpc_buf, 4, rpc_buf, 1);

    if (sjx->unk10 == NULL) {
        scePrintf("E0100401: can't create SJX of IOP\n");
        return NULL;
    }

    sjx->used = 1;
    return sjx;
}

void SJX_Destroy(SJX sjx) {
    Sint32 rpc_buf[1];

    rpc_buf[0] = sjx->unk10;
    DTX_CallUrpc(1, rpc_buf, 1, NULL, 0);
    sjx->used = 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/sjx", SJX_Reset);
