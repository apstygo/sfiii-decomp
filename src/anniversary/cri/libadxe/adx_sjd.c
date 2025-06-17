#include "common.h"
#include <cri/private/libadxe/adx_bahx.h>
#include <cri/private/libadxe/adx_bsc.h>
#include <cri/private/libadxe/adx_crs.h>
#include <cri/private/libadxe/adx_sjd.h>
#include <cri/private/libadxe/sj_rbf.h>

#include <cri/cri_xpts.h>

#include <string.h>

// data
Sint32 pl2setsfreqfunc = 0;
ADXSJD_OBJ adxsjd_obj[ADXSJD_MAX_OBJ] = { 0 };

// forward decls
Sint32 adxsjd_get_wr(ADXSJD sjd, Sint32 *arg1, Sint32 *arg2, Sint32 *arg3);

void ADXSJD_Init() {
    ADXB_Init();
    memset(adxsjd_obj, 0, sizeof(adxsjd_obj));
}

void ADXSJD_Finish() {
    memset(adxsjd_obj, 0, sizeof(adxsjd_obj));
}

void adxsjd_clear(ADXSJD sjd) {
    sjd->unk3C = -1;
    sjd->unk38 = SJCK_LEN_MAX;
    sjd->unk98 = 0;
    sjd->unk2C = 0;
    sjd->unk30 = 0;
    sjd->unk34 = 0;
    sjd->unk40 = 0;
    sjd->unk44 = 0;
    sjd->unk3 = 0;
}

ADXSJD ADXSJD_Create(SJ sj, Sint32 maxnch, SJ *sjo) {
    ADXSJD sjd;
    SJ out;
    Sint32 buf_ptr;
    Sint32 i;
    Sint32 y;
    Sint32 buf_size;
    Sint32 xtr_size;

    out = sjo[0];

    for (i = 0; i < ADXSJD_MAX_OBJ; i++) {
        if (!adxsjd_obj[i].used) {
            break;
        }
    }

    if (i == ADXSJD_MAX_OBJ) {
        return NULL;
    }

    sjd = &adxsjd_obj[i];
    buf_ptr = SJRBF_GetBufPtr(out);
    buf_size = SJRBF_GetBufSize(out) / 2;
    xtr_size = SJRBF_GetXtrSize(out) / 2;
    sjd->adxb = ADXB_Create(maxnch, buf_ptr, buf_size, buf_size + xtr_size);

    if (sjd->adxb == NULL) {
        return NULL;
    }

    ADXB_EntryGetWrFunc(sjd->adxb, adxsjd_get_wr, sjd);
    sjd->sji = sj;
    sjd->maxnch = maxnch;

    for (y = 0; y < maxnch; y++) {
        sjd->sjo[y] = sjo[y];
    }

    sjd->state = 0;
    adxsjd_clear(sjd);
    sjd->unk48 = 0;
    sjd->unk4C = 0;
    sjd->unk50 = 0;
    sjd->unk54 = 0;
    sjd->used = 1;
    return sjd;
}

void ADXSJD_Destroy(ADXSJD sjd) {
    ADXB adxb;

    if (sjd == NULL) {
        return;
    }

    adxb = sjd->adxb;

    if (adxb != NULL) {
        sjd->adxb = NULL;
        ADXB_Destroy(adxb);
    }

    ADXCRS_Lock();
    memset(sjd, 0, sizeof(ADXSJD_OBJ));
    ADXCRS_Unlock();
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetStat);

void ADXSJD_SetInSj(ADXSJD sjd, SJ sj) {
    sjd->sji = sj;
    ADXB_SetAhxInSj(sjd->adxb, sj);
    ADXB_SetAc3InSj(sjd->adxb, sj);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_SetOutSj);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_SetMaxDecSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_TermSupply);

void ADXSJD_Start(ADXSJD sjd) {
    adxsjd_clear(sjd);
    sjd->state = 1;
}

void ADXSJD_Stop(ADXSJD sjd) {
    ADXB_Stop(sjd->adxb);
    sjd->state = 0;
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", D_0055B3D8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", D_0055B3F8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", adxsjd_decode_prep);

Sint32 adxsjd_get_wr(ADXSJD sjd, Sint32 *arg1, Sint32 *arg2, Sint32 *arg3) {
    Sint32 temp_v0_3;
    Sint32 i;
    Sint32 var_v0;
    SJ first_out;
    SJ *sjo;
    SJCK *chunk_p;
    Sint32 a0;

    first_out = sjd->sjo[0];
    sjo = sjd->sjo;
    chunk_p = sjd->chunks;

    for (i = 0; i < ADXB_GetNumChan(sjd->adxb); i++) {
        SJ_GetChunk(sjo[i], 0, 0x4000, &chunk_p[i]);
    }

    *arg1 = (Sint32)(sjd->chunks[0].data - SJRBF_GetBufPtr(first_out)) / 2;

    a0 = sjd->unk38;
    temp_v0_3 = sjd->chunks[0].len / 2;

    if (temp_v0_3 < a0) {
        a0 = temp_v0_3;
    }

    *arg2 = a0;

    if (sjd->unk3C >= 0) {
        var_v0 = sjd->unk3C - sjd->unk40;
    } else {
        var_v0 = 0x1FFFFFFF;
    }

    *arg3 = var_v0;
    return ADXB_GetPcmBuf(sjd->adxb);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", adxsjd_decexec_start);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", adxsjd_decexec_end);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", adxsjd_decexec_extra);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", adxsjd_decode_exec);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_ExecHndl);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_ExecServer);
#else
void ADXSJD_ExecServer() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetDecDtLen);

Sint32 ADXSJD_GetDecNumSmpl(ADXSJD sjd) {
    return sjd->unk2C;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_SetDecPos);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetDecPos);

void ADXSJD_SetLnkSw(ADXSJD sjd, Sint32 sw) {
    sjd->lnkflg = sw;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetLnkSw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_SetExtString);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_SetDefExtString);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_EntryFltFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_EntryTrapFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_SetTrapNumSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetTrapNumSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_SetTrapCnt);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetTrapCnt);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_SetTrapDtLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetTrapDtLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetFormat);

Sint32 ADXSJD_GetSfreq(ADXSJD sjd) {
    return ADXB_GetSfreq(sjd->adxb);
};

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetNumChan);

Sint32 ADXSJD_GetOutBps(ADXSJD sjd) {
    return ADXB_GetOutBps(sjd->adxb);
};

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetBlkSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetBlkLen);

Sint32 ADXSJD_GetTotalNumSmpl(ADXSJD sjd) {
    return ADXB_GetTotalNumSmpl(sjd->adxb);
};

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetCof);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetNumLoop);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetLpInsNsmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetLpStartPos);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetLpStartOfst);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetLpEndPos);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetLpEndOfst);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetAinfLen);

Sint32 ADXSJD_GetDefOutVol(ADXSJD sjd) {
    if (ADXB_GetAinfLen(sjd->adxb) > 0 && ((Uint8)sjd->state - 2) < 2U) {
        return ADXB_GetDefOutVol(sjd->adxb);
    }

    return 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetDefPan);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetDataId);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetHdrLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetFmtBps);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetSpsdInfo);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_TakeSnapshot);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_RestoreSnapshot);
