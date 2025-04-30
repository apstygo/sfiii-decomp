#include "common.h"
#include <cri/private/libadxe/adx_crs.h>
#include <cri/private/libadxe/adx_errs.h>
#include <cri/private/libadxe/adx_fs.h>
#include <cri_adxt.h>

// These should go in their own headers

s32 LSC_GetNumStm(void *);
s32 LSC_EntryFname(void *);
void LSC_EntryFileRange(void *, s8 *, s32, s32, s32);
void LSC_SetFlowLimit(void *, s32);
void LSC_Start(void *);
void LSC_Stop(void *);
void LSC_SetLpFlg(void *, s32);
void LSC_ResetEntry(void *);

void ADXT_StopWithoutLsc();
void adxt_start_sj(ADXT, SJ_OBJ *);

void ADXT_EntryFname(ADXT adxt, s8 *fname) {
    void *lsc = adxt->lsc;

    if (adxt == NULL) {
        ADXERR_CallErrFunc1("E02080848 ADXT_EntryFname: parameter error");
        return;
    }

    if (LSC_EntryFname(lsc) < 0) {
        ADXERR_CallErrFunc2("E0010601:Can't entry file ", fname);
    }
}

void ADXT_EntryAfs(ADXT adxt, s32 patid, s32 fid) {
    typedef struct {
        s8 sp;
        char pad[12];
        s32 sp10;
        s32 sp14;
        s32 sp18;
    } Stack;

    Stack st;
    void *lsc = adxt->lsc;

    if (adxt == NULL) {
        ADXERR_CallErrFunc1("E02080855 ADXT_EntryAfs: parameter error");
        return;
    }

    if (ADXF_GetFnameRangeEx(patid, fid, adxt->unkB0, &st.sp10, &st.sp14, &st.sp18) == 0) {
        LSC_EntryFileRange(lsc, ADXF_GetFnameFromPt(patid), st.sp10, st.sp14, st.sp18);
        return;
    }

    ADXERR_ItoA2(patid, fid, &st.sp, 0x10);
    ADXERR_CallErrFunc2("E0071301 ADXT_EntryAfs: can't entry ", &st.sp);
}

void ADXT_StartSeamless(ADXT adxt) {
    SJ sj;
    void *lsc = adxt->lsc;

    if (adxt == NULL) {
        ADXERR_CallErrFunc1("E02080850 ADXT_StartSeamless: parameter error");
        return;
    }

    ADXT_StopWithoutLsc();
    ADXCRS_Lock();
    adxt_start_sj(adxt, adxt->sjf);
    sj = adxt->sji;
    SJ_Reset(sj);
    adxt->pmode = 4;
    LSC_SetFlowLimit(lsc, adxt->minsct << 11);
    ADXCRS_Unlock();
    LSC_Start(lsc);
    ADXT_SetLnkSw(adxt, 1);
}

void ADXT_SetSeamlessLp(ADXT adxt, s32 flg) {
    if (adxt == NULL) {
        ADXERR_CallErrFunc1("E02080851 ADXT_SetSeamlessLp: parameter error");
        return;
    }

    LSC_SetLpFlg(adxt->lsc, flg);
}

void ADXT_StartFnameLp(ADX_TALK *adxt, s8 *fname) {
    void *lsc;

    if (adxt == NULL || fname == NULL) {
        ADXERR_CallErrFunc1("E02080852 ADXT_StartFnameLp: parameter error");
        return;
    }

    lsc = adxt->lsc;
    LSC_Stop(lsc);
    ADXT_EntryFname(adxt, fname);
    LSC_SetLpFlg(lsc, 1);
    ADXT_StartSeamless(adxt);
}

void ADXT_ReleaseSeamless(ADXT adxt) {
    // Do nothing
}

s32 ADXT_GetNumFiles(ADXT adxt) {
    if (adxt == NULL) {
        ADXERR_CallErrFunc1("E02080854 ADXT_GetNumFiles: parameter error");
        return -1;
    }

    return LSC_GetNumStm(adxt->lsc);
}

void ADXT_ResetEntry(ADXT adxt) {
    if (adxt == NULL) {
        ADXERR_CallErrFunc1("E02080849 ADXT_ResetEntry: parameter error");
        return;
    }

    if (adxt->stat != 0) {
        return;
    }

    LSC_ResetEntry(adxt->lsc);
}
