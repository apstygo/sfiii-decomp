#include "common.h"
#include <cri/private/libadxe/dtr.h>
#include <cri/private/libadxe/dtx.h>
#include <cri/private/libadxe/ps2_rna.h>
#include <cri/private/libadxe/sjr_clt.h>
#include <cri/private/libadxe/sjx.h>
#include <cri/private/libadxe/structs.h>

#include <eekernel.h>
#include <sifdev.h>

#define PS2PSJ_MAX_OBJ 32
#define PS2RNA_WORK_SIZE 0x8D0
#define PS2RNA_MAX_OBJ 16

// data
extern Char8 *volatile ps2rna_build;                 // 7
extern Sint32 ps2rna_max_voice;                      // 1019
extern Sint32 ps2psj_iop_wksize;                     // 1023
extern Sint32 ps2rna_setupvoice_flag;                // 1027
extern void *ps2psj_iop_work0;                       // 1031
extern void *ps2psj_iop_work;                        // 1035
extern Sint8 ps2psj_alloc_flag;                      // 1039
extern Sint32 ps2rna_psm_wksize;                     // 1050
extern void *ps2rna_psm_wk0;                         // 1054
extern Sint32 ps2rna_psm_wk;                         // 1058
extern Sint32 ps2rna_psm_max_voice;                  // 1062
extern Sint32 ps2rna_ee_allpause;                    // 1078
extern Sint32 ps2rna_iop_allpause;                   // 1082
extern Sint32 ps2rna_init_cnt;                       // 1086
extern Sint8 *ps2rna_eewk;                           // 1090
extern void *ps2rna_iopwk0;                          // 1094
extern Sint32 ps2rna_iopwk;                          // 1098
extern PS2PSJ_OBJ ps2psj_obj[PS2PSJ_MAX_OBJ];        // 1107
extern Sint8 ps2psj_sjuni_eewk[PS2PSJ_MAX_OBJ][256]; // 1302
extern ADXRNA_OBJ ps2rna_obj[PS2RNA_MAX_OBJ];        // 3423
extern ADXDTX ps2rna_dtx;                            // 5026
extern Sint32 ps2rna_wklen;                          // 5030
extern Sint8 ps2rna_ee_work[PS2RNA_WORK_SIZE];       // 5034

// forward decls
void PS2RNA_InitIopSnd();

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E0C8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E0F8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E128);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E158);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_SetupVoice);

void ps2rna_init_psj() {
    Sint8 *wk;
    Sint32 i;
    Sint32 j;
    PS2PSJ psj;

    if (ps2rna_setupvoice_flag == 0) {
        ps2rna_max_voice = 16;
        ps2psj_iop_wksize = 0x41000;
    }

    if (ps2psj_iop_work0 == NULL) {
        ps2psj_iop_work0 = sceSifAllocIopHeap(ps2psj_iop_wksize + 0x40);

        if (ps2psj_iop_work0 == NULL) {
            scePrintf("PS2RNA: E01112903: Failed, sceSifAllocIopHeap(%d) in ps2rna_init_psj\n",
                      ps2psj_iop_wksize + 0x40);
            while (1) {}
        }

        scePrintf("PS2RNA: sceSifAllocIopHeap(%d) ret=0x%08x\n", ps2psj_iop_wksize + 0x40, ps2psj_iop_work0);
        ps2psj_iop_work = (Sint32)(ps2psj_iop_work0 + 0x40) & ~(0x40 - 1);
        ps2psj_alloc_flag = 1;
    }

    memset(ps2psj_obj, 0, sizeof(ps2psj_obj));
    wk = ps2psj_iop_work;

    for (i = 0, j = 0; i < ps2rna_max_voice; i++, j++) {
        psj = &ps2psj_obj[j];
        psj->unk0 = 0;

        if ((Uint32)wk & 0x3F) {
            scePrintf("E0110101: ps2rna_init_psj wk size error\n");
            while (1) {}
        }

        psj->unk4 = SJUNI_CreateRmt(1, wk, 0x100);
        wk += 0x100;

        if (psj->unk4 == NULL) {
            scePrintf("E0110102: ps2rna_init_psj: can't creat SJUNI_CreaetRmt\n");
            while (1) {}
        }

        if ((Uint32)wk & 0x3F) {
            scePrintf("E0110103: ps2rna_init_psj: wk size error\n");
            while (1) {}
        }

        psj->unk8 = SJUNI_Create(1, ps2psj_sjuni_eewk[i], 0x100);

        if (psj->unk8 == NULL) {
            scePrintf("E0110104: ps2rna_init_psj: can't creat SJUNI_Creaet\n");
            while (1) {}
        }

        psj->chunk.len = 0x4000;
        psj->chunk.data = wk;
        wk += 0x4000;
        SJ_PutChunk(psj->unk8, 0, &psj->chunk);
        psj->unkC = SJX_Create(psj->unk8, psj->unk4, 1);

        if (psj->unkC == NULL) {
            scePrintf("E0110105: ps2rna_init_psj: can't creat SJX_Create\n");
            while (1) {}
        }
    }
}

void ps2rna_finish_psj() {
    PS2PSJ psj;
    Sint32 i;

    for (i = 0; i < ps2rna_max_voice; i++) {
        psj = &ps2psj_obj[i];

        if (psj->unk4 != NULL) {
            SJRMT_Destroy(psj->unk4);
        }

        if (psj->unk8 != NULL) {
            SJ_Destroy(psj->unk8);
        }

        if (psj->unkC != NULL) {
            SJX_Destroy(psj->unkC);
        }

        memset(psj, 0, sizeof(PS2PSJ_OBJ));
    }

    if (ps2psj_alloc_flag == 1) {
        sceSifFreeIopHeap(ps2psj_iop_work0);
        ps2psj_iop_work0 = NULL;
        ps2psj_alloc_flag = 0;
    }
}

PS2PSJ ps2rna_get_psj() {
    PS2PSJ psj = NULL;
    Sint32 i;

    for (i = 0; i < ps2rna_max_voice; i++) {
        psj = &ps2psj_obj[i];

        if (psj->unk0 == 0) {
            break;
        }
    }

    if (i == ps2rna_max_voice) {
        return NULL;
    }

    psj->unk0 = 1;
    return psj;
}

void ps2rna_release_psj(PS2PSJ psj) {
    psj->unk0 = 0;
};

void ps2rna_rcvcbf(Sint32 arg0, Sint32 *arg1) {
    Sint32 i;
    Sint32 ticks;

    if (arg1 == NULL) {
        while (1) {}
    }

    ticks = arg1[0];

    for (i = 0; i < ticks; i++) {
        // Do nothing
    }
}

void ps2rna_sndcbf();
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", ps2rna_sndcbf);

void PS2RNA_Init() {
    Sint32 unk[3];

    *ps2rna_build;

    if (ps2rna_init_cnt == 0) {
        SJRMT_Init();
        SJX_Init();
        DTX_Init();
        PS2RNA_InitIopSnd();
        ps2rna_init_psj();
        memset(ps2rna_ee_work, 0, sizeof(ps2rna_ee_work));
        ps2rna_wklen = 0x880;
        ps2rna_eewk = (Sint32)(ps2rna_ee_work + 0x40) & ~0x3F;

        if (ps2rna_iopwk0 == NULL) {
            ps2rna_iopwk0 = sceSifAllocIopHeap(PS2RNA_WORK_SIZE);

            if (ps2rna_iopwk0 == NULL) {
                scePrintf("PS2RNA: E01112902: Failed, sceSifAllocIopHeap(%d) in PS2RNA_Init.", PS2RNA_WORK_SIZE);
                while (1) {}
            }
        }

        scePrintf("PS2RNA: sceSifAllocIopHeap(%d) ret=0x%08x\n", PS2RNA_WORK_SIZE, ps2rna_iopwk0);
        ps2rna_iopwk = (Sint32)(ps2rna_iopwk0 + 0x40) & ~0x3F;
        ps2rna_dtx = DTX_Create(1, ps2rna_eewk, ps2rna_iopwk, ps2rna_wklen);

        if (ps2rna_dtx == NULL) {
            scePrintf("E0100302: PS2RNA_Init can't create DTX\n");
            while (1) {}
        }

        DTX_SetRcvCbf(ps2rna_dtx, ps2rna_rcvcbf, NULL);
        DTX_SetSndCbf(ps2rna_dtx, ps2rna_sndcbf, NULL);

        if (ps2rna_psm_wk0 == NULL) {
            ps2rna_psm_max_voice = ps2rna_max_voice;
            ps2rna_psm_wksize = (ps2rna_max_voice * 1024) + 0x40;
            ps2rna_psm_wk0 = sceSifAllocIopHeap(ps2rna_psm_wksize);

            if (ps2rna_psm_wk0 == NULL) {
                scePrintf("E02041101: Failed, sceSifAllocIopHeap(%d) in PS2RNA_Init.\0\0\0\0", ps2rna_psm_wksize);
                while (1) {}
            }

            scePrintf("PS2RNA: sceSifAllocIopHeap(%d) ret=0x%08x\n", ps2rna_psm_wksize, ps2rna_psm_wk0);
        }

        unk[0] = ps2rna_psm_max_voice;
        ps2rna_psm_wk = unk[1] = (Sint32)(ps2rna_psm_wk0 + 0x3F) & ~0x3F;
        unk[2] = ps2rna_psm_wksize;
        DTX_CallUrpc(10, unk, 3, 0, 0);
    }

    ps2rna_init_cnt += 1;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_RestoreIopSnd);

void PS2RNA_InitIopSnd() {
    DTX_CallUrpc(12, NULL, 0, 0, 0);
    ps2rna_ee_allpause = 0;
    ps2rna_iop_allpause = 0;
}

void PS2RNA_FinishIopSnd() {
    DTX_CallUrpc(13, NULL, 0, 0, 0);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_SetupDolby);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_ShutdownDolby);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_SetStmType);

void PS2RNA_Finish() {
    if (--ps2rna_init_cnt == 0) {
        sceSifFreeIopHeap(ps2rna_psm_wk0);
        ps2rna_psm_wk0 = NULL;
        DTX_Destroy(ps2rna_dtx);
        ps2rna_dtx = NULL;
        sceSifFreeIopHeap(ps2rna_iopwk0);
        ps2rna_iopwk0 = NULL;
        ps2rna_finish_psj();
        PS2RNA_FinishIopSnd();
        DTX_Finish();
        SJX_Finish();
        SJRMT_Finish();
    }
}

ADXRNA PS2RNA_Create(SJ *sjo, Sint32 maxnch) {
    Sint32 sp0[4];
    Sint32 sp10;
    PS2PSJ psj;
    Sint32 i;
    Sint32 j;
    Sint32 k;
    ADXRNA rna;

    for (i = 0; i < PS2RNA_MAX_OBJ; i++) {
        rna = &ps2rna_obj[i];

        if (rna->unk0 == 0) {
            break;
        }
    }

    if (i == PS2RNA_MAX_OBJ) {
        return NULL;
    }

    memset(rna, 0, sizeof(ADXRNA_OBJ));
    rna->maxnch = maxnch;

    for (i = 0; i < maxnch; i++) {
        psj = ps2rna_get_psj();
        rna->psj[i] = psj;

        if (psj == NULL) {
            scePrintf("E1072601: not enough PSJ handle\n");

            for (j = 0; j < maxnch; j++) {
                psj = rna->psj[j];

                if (psj != NULL) {
                    ps2rna_release_psj(psj);
                }
            }

            return NULL;
        }
    }

    sp0[0] = maxnch;
    sp0[1] = 0;

    for (i = 0; i < maxnch; i++) {
        sp0[2 + i] = rna->psj[i]->unk4;
    }

    rna->unk20 = DTX_CallUrpc(8, sp0, 4, (Sint32)&sp10, 1);

    if (rna->unk20 == 0) {
        scePrintf("E0100401: can't create PS2RNA of IOP\n");
        return NULL;
    }

    for (i = 0; i < maxnch; i++) {
        rna->dtr[i] = DTR_Create(sjo[i], rna->psj[i]->unk8);

        if (rna->dtr[i] == 0) {
            scePrintf("E1072602: can't create DTR handle\n\0\0\0\0");

            for (k = 0; k < maxnch; k++) {
                if (rna->dtr[k] != 0) {
                    DTR_Destroy(rna->dtr[k]);
                }

                if (rna->unk20 != 0) {
                    sp0[0] = rna->unk20;
                    DTX_CallUrpc(9, sp0, 1, 0, 0);
                }

                if (rna->psj[k] != 0) {
                    ps2rna_release_psj(rna->psj[k]);
                }
            }

            return NULL;
        }
    }

    for (i = 0; i < maxnch; i++) {
        rna->sjo[i] = sjo[i];
    }

    rna->unk30 = 0;
    rna->unk31 = 0;
    rna->unk32 = maxnch;
    rna->unk33 = maxnch;
    rna->unk3C = 0;
    rna->unk40 = 0;
    rna->unk54 = 0;
    rna->unk58 = 0;
    rna->unk5F = 0;
    rna->unk5E = 0;

    for (i = 0; i < maxnch; i++) {
        rna->unk44[i] = 0;
        rna->unk4C[i] = 0;
    }

    rna->unk5C = 0;
    rna->unk5D = 1;
    rna->unk24 = 0;
    rna->unk28 = SJ_GetNumData(sjo[0], 1) + SJ_GetNumData(sjo[0], 0);
    rna->unk2C = 0x4000;
    rna->unk0 = 1;
    return rna;
}

void PS2RNA_Destroy(ADXRNA rna) {
    Sint32 sp0[1];
    Sint32 i;

    for (i = 0; i < rna->maxnch; i++) {
        if (rna->dtr[i] != 0) {
            DTR_Destroy(rna->dtr[i]);
        }
    }

    sp0[0] = rna->unk20;
    DTX_CallUrpc(9, sp0, 1, 0, 0);

    for (i = 0; i < rna->maxnch; i++) {
        if (rna->psj[i] != 0) {
            ps2rna_release_psj(rna->psj[i]);
        }
    }

    rna->unk0 = 0;
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E440);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_Start);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_Stop);

void PS2RNA_SetTransSw(ADXRNA rna, Sint32 sw) {
    Sint32 i;
    Sint32 v1;

    rna->unk5C = sw;
    v1 = rna->unk32;

    if (sw == 1) {
        return;
    }

    for (i = 0; i < v1; i++) {
        DTR_Stop(rna->dtr[i]);
        rna->unk5D = 1;
        rna->unk5C = 0;
    }
}

void PS2RNA_SetPlaySw(ADXRNA rna, Sint32 sw) {
    rna->unk30 = sw;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_PauseAll);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_GetStatPauseAll);

void PS2RNA_SetDiscardSw(ADXRNA rna, Sint32 sw) {
    rna->unk5F = sw;
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E460);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_ClearBuf);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E488);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_SetPcmType);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_GetTime);

Sint32 PS2RNA_GetNumData(ADXRNA rna) {
    return (0x4000 - SJ_GetNumData(rna->psj[0]->unk8, 0)) / 2;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_GetNumRoom);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_ExecHndl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_ExecServer);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E4B0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_SetStartSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_SetNumChan);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E4D8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_SetSfreq);

void PS2RNA_SetOutVol(ADXRNA rna, Sint32 vol) {
    if (vol > 0) {
        vol = 0;
    }

    if (vol < -999) {
        vol = -999;
    }

    rna->unk3C = vol;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_SetOutPan);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_SetOutBalance);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E4F8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_SetBitPerSmpl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E528);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_GetStartSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_GetSfreq);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_GetOutVol);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_GetOutPan);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_GetOutBalance);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_GetBitPerSmpl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E550);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_IsOverflow);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E578);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_ClearOverflow);

void PS2RNA_Flush() {
    // Do nothing
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E5A0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_DiscardData);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E5C8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_SetTotalNumSmpl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", D_0055E5F8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_SetStmHdInfo);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_GetSjtmp);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/ps2_rna", PS2RNA_GetSjiop);
