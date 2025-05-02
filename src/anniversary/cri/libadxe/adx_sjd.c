#include "common.h"
#include <cri/private/libadxe/adx_bsc.h>
#include <cri/private/libadxe/adx_sjd.h>
#include <cri/private/libadxe/sj_rbf.h>

#include <cri/cri_xpts.h>

// data
extern ADXSJD_OBJ adxsjd_obj[ADXSJD_MAX_OBJ];

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

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_Create);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_Destroy);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_SetInSj);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_SetOutSj);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_SetMaxDecSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_TermSupply);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_Start);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_Stop);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", adxsjd_decode_prep);

Sint32 adxsjd_get_wr(ADXSJD sjd, Sint32 *arg1, Sint32 *arg2, Sint32 *arg3) {
    Sint32 temp_v0_3;
    Sint32 i;
    Sint32 var_v0;
    SJ first_sj;
    SJ *sj;
    SJCK *chunk_p;
    Sint32 a0;

    first_sj = sjd->sj[0];
    sj = sjd->sj;
    chunk_p = sjd->chunks;

    for (i = 0; i < ADXB_GetNumChan(sjd->adxb); i++) {
        SJ_GetChunk(sj[i], 0, 0x4000, &chunk_p[i]);
    }

    *arg1 = (Sint32)(sjd->chunks[0].data - SJRBF_GetBufPtr(first_sj)) / 2;

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

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_ExecServer);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetDecDtLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetDecNumSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_SetDecPos);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetDecPos);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_SetLnkSw);

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

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetSfreq);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetNumChan);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetOutBps);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetBlkSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetBlkLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetTotalNumSmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetCof);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetNumLoop);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetLpInsNsmpl);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetLpStartPos);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetLpStartOfst);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetLpEndPos);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetLpEndOfst);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetAinfLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetDefOutVol);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetDefPan);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetDataId);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetHdrLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetFmtBps);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_GetSpsdInfo);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_TakeSnapshot);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", ADXSJD_RestoreSnapshot);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", D_0055B3D8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_sjd", D_0055B3F8);
