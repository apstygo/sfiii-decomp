#include "common.h"
#include <cri/cri_adxt.h>
#include <cri/private/libadxe/adx_crs.h>
#include <cri/private/libadxe/adx_errs.h>
#include <cri/private/libadxe/adx_inis.h>
#include <cri/private/libadxe/adx_rnap.h>
#include <cri/private/libadxe/adx_sjd.h>
#include <cri/private/libadxe/adx_stmc.h>
#include <cri/private/libadxe/lsc.h>
#include <cri/sj.h>

// data
extern Sint32 adxt_def_svrfreq;

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B460);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B480);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B4A0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", adxt_disp_rna_stat);

ADXT ADXT_Create(s32 maxnch, void *work, s32 worksize) {
    ADXT adxt;
    s32 _maxnch;
    s32 i;
    s32 ix;
    s32 aligned_work;
    s32 size;
    s32 ibuf_len;

    aligned_work = ((u32)work + 0x40 - 1) & ~(0x40 - 1);
    size = worksize - (aligned_work - (u32)work);

    if ((maxnch < 0) || (work == NULL) || (worksize < 0)) {
        ADXERR_CallErrFunc1("E02080804 ADXT_Create: parameter error");
        return NULL;
    }

    _maxnch = (maxnch != 4) ? maxnch : 1;

    for (ix = 0; ix < ADXT_MAX_OBJ; ix++) {
        if (!adxt_obj[ix].used) {
            break;
        }
    }

    if (ix == ADXT_MAX_OBJ) {
        return NULL;
    }

    adxt = &adxt_obj[ix];
    memset(adxt, 0, sizeof(ADX_TALK));

    adxt->maxnch = _maxnch;
    adxt->ibuf = (Sint8 *)(aligned_work + ADXT_CALC_OBUFSIZE(_maxnch));
    adxt->obuf = (s16 *)aligned_work;
    adxt->obufsize = ADXT_OBUF_SIZE;
    adxt->obufdist = ADXT_OBUF_DIST;
    adxt->ibufxlen = ADXT_IBUF_XLEN;
    ibuf_len = size - ADXT_CALC_OBUFSIZE(_maxnch) - 0x124;
    adxt->ibuflen = ibuf_len / 0x800 * 0x800;

    adxt->sji = NULL;
    adxt->unkB0 = adxt->ibuf + (adxt->ibuflen + adxt->ibufxlen);
    adxt->sjf = SJRBF_Create(adxt->ibuf, adxt->ibuflen, adxt->ibufxlen);

    if (adxt->sjf == NULL) {
        ADXT_Destroy(adxt);
        return NULL;
    }

    adxt->stm = ADXSTM_Create((s32)adxt->sjf, 0);

    if (adxt->stm == NULL) {
        ADXT_Destroy(adxt);
        return NULL;
    }

    for (i = 0; i < _maxnch; i++) {
        adxt->sjo[i] = SJRBF_Create(
            (s8 *)(adxt->obuf + adxt->obufdist * i), adxt->obufsize * 2, (adxt->obufdist - adxt->obufsize) * 2);

        if (adxt->sjo[i] == NULL) {
            ADXT_Destroy(adxt);
            return NULL;
        }
    }

    adxt->sjd = ADXSJD_Create(adxt->sjf, _maxnch, adxt->sjo);

    if (adxt->sjd == NULL) {
        ADXT_Destroy(adxt);
        return NULL;
    }

    adxt->rna = ADXRNA_Create(adxt->sjo, _maxnch);

    if (adxt->rna == NULL) {
        ADXT_Destroy(adxt);
        return NULL;
    }

    adxt->lsc = LSC_Create(adxt->sjf);

    if (adxt->lsc == NULL) {
        ADXT_Destroy(adxt);
        return NULL;
    }

    LSC_SetStmHndl(adxt->lsc, adxt->stm);
    ADXCRS_Lock();

    adxt->outvol = 0;
    adxt->maxsct = adxt->ibuflen / 0x800;
    adxt->svrfreq = adxt_def_svrfreq;
    adxt->minsct = (adxt->maxsct << 16 >> 16) * 0.85f;

    for (i = 0; i < _maxnch; i++) {
        adxt->outpan[i] = ADXT_PAN_AUTO;
    }

    adxt->unk46 = 0;
    adxt->lpflg = 1;
    adxt->trp = 0;
    adxt->wpos = 0;
    adxt->mofst = 0;
    adxt->ercode = 0;
    adxt->edecpos = 0;
    adxt->edeccnt = 0;
    adxt->eshrtcnt = 0;
    adxt->autorcvr = 1;
    adxt->pause_flag = 0;
    adxt->time_ofst = 0;
    ADXT_SetLnkSw(adxt, 0);
    adxt->used = 1;
    ADXCRS_Unlock();
    return adxt;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_Create3D);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", adxt_detach_ahx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", adxt_detach_ac3);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", adxt_detach_pl2);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_Destroy);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_DestroyAll);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_CloseAllHandles);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", adxt_start_sj);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", adxt_start_stm);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_StartSj);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_StopWithoutLsc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_Stop);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetTimeMode);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetTimeSfreq);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetTimeSfreq2);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", adxt_time_adjust_trap);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetTime);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetTimeReal);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetNumSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetSfreq);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetNumChan);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetHdrLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetFmtBps);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetOutPan);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetOutPan);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetOutBalance);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetOutBalance);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetOutVol);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetOutVol);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetDefOutVol);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetDefOutPan);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetDataId);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetDefSvrFreq);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetSvrFreq);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetReloadTime);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetReloadSct);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetNumSctIbuf);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetNumSmplObuf);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetIbufRemainTime);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_IsIbufSafety);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetAutoRcvr);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_IsCompleted);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_ExecServer);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_ExecDecServer);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetErrCode);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_ClearErrCode);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetLpCnt);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetLpFlg);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetInputSj);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetWaitPlayStart);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_IsReadyPlayStart);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_Pause);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetStatPause);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_PauseAll);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetStatPauseAll);

void ADXT_SetTranspose(ADXT adxt, Sint32 transps, Sint32 detune) {
    // Do nothing
}

void ADXT_GetTranspose(ADXT adxt, Sint32 *transps, Sint32 *detune) {
    // Do nothing
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetStm);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_TermSupply);

void ADXT_SetDrctLvl(ADXT adxt, Sint32 drctlvl) {
    // Do nothing
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetDrctLvl);

void ADXT_SetFx(ADXT adxt, Sint32 fxch, Sint32 fxlvl) {
    // Do nothing
}

void ADXT_GetFx(ADXT adxt, Sint32 *fxch, Sint32 *fxlvl) {
    // Do nothing
}

void ADXT_SetFilter(ADXT adxt, Sint32 coff, Sint32 q) {
    // Do nothing
}

void ADXT_GetFilter(ADXT adxt, Sint32 *coff, Sint32 *q) {
    // Do nothing
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_EntryErrFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_DiscardSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetTimeOfst);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetLnkSw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetLnkSw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_EntryFltFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetDecNumSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_IsHeader);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_IsEndcode);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_InsertSilence);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetOutputMono);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetKeyString);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_SetDefKeyString);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", ADXT_GetRna);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B4E0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B508);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B530);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B558);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B580);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B5A8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B5D8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B608);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B638);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B668);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B698);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B6C8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B6F8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B728);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B758);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B788);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B7B8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B7E8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B818);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B848);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B878);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B8A8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B8D8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B910);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B940);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B970);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B9A0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055B9D0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055BA00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055BA30);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055BA60);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055BA98);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055BAD0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055BAF8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055BB28);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_tlk", D_0055BB58);
