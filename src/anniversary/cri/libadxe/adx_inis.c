#include "common.h"
#include <cri/cri_adxt.h>
#include <cri/ee/cri_mw.h>
#include <cri/private/libadxe/adx_crs.h>
#include <cri/private/libadxe/adx_errs.h>
#include <cri/private/libadxe/adx_rnap.h>
#include <cri/private/libadxe/adx_tlk.h>
#include <cri/private/libadxe/dtx.h>
#include <cri/private/libadxe/lsc_err.h>
#include <cri/private/libadxe/svm.h>

// data
extern Char8 *volatile adxt_build;
extern Sint32 adxt_init_cnt;
extern Sint32 adxt_vsync_svr_flag;
extern Sint32 adxt_vsync_cnt;
extern Sint32 adxt_svr_main_id;
extern Sint32 adxt_svr_fs_id;
extern Sint32 volatile adxt_vsync_cnt;
extern ADX_TALK adxt_obj; // Should be an array of ADX_TALK

void ADXT_ConfigVsyncSvr(Sint32 flag) {
    adxt_vsync_svr_flag = flag;
}

void adxini_rnaerr_cbfn(void *object, Char8 *msg) {
    ADXERR_CallErrFunc1(msg);
}

void adxini_lscerr_cbfn(void *object, Char8 *msg) {
    ADXERR_CallErrFunc1(msg);
}

void ADXT_VsyncProc() {
    adxt_vsync_cnt += 1;
    ADXT_ExecServer();
}

Sint32 adxt_exec_main_thrd() {
    LSC_ExecServer();
    return 0;
}

Sint32 adxt_exec_main_nothrd() {
    adxt_exec_tsvr(0);
    adxt_exec_fssvr(0);
    adxt_exec_main_thrd(0);
    return 0;
}

Sint32 adxt_exec_tsvr() {
    ADXT_ExecServer();
    return 0;
}

Sint32 adxt_exec_fssvr() {
    ADXT_ExecFsSvr();
    return 0;
}

void ADXT_Init() {
    Bool is_thread_setup;
    adxt_build;

    if (adxt_init_cnt == 0) {
        ADXCRS_Init();
        ADXCRS_Lock();
        SJUNI_Init();
        SJRBF_Init();
        SJMEM_Init();
        ADXERR_Init();
        ADXSTM_Init();
        ADXSJD_Init();
        ADXF_Init();
        ADXRNA_Init();
        LSC_Init();
        SVM_Init();
        ADXRNA_EntryErrFunc(adxini_rnaerr_cbfn, NULL);
        LSC_EntryErrFunc(adxini_lscerr_cbfn, NULL);
        memset(&adxt_obj, 0, 0xC40);
        is_thread_setup = ADXM_IsSetupThrd();

        if ((is_thread_setup == 1) && (adxt_vsync_svr_flag == is_thread_setup)) {
            SVM_SetCbSvrId(2, 1, &adxt_exec_tsvr, 0);
            adxt_svr_fs_id = SVM_SetCbSvr(4, &adxt_exec_fssvr, 0);
            adxt_svr_main_id = SVM_SetCbSvr(5, adxt_exec_main_thrd, 0);
        } else {
            adxt_svr_main_id = SVM_SetCbSvr(5, adxt_exec_main_nothrd, 0);
        }

        adxt_vsync_cnt = 0;
        ADXT_SetDefSvrFreq(60);
        ADXCRS_Unlock();
    }

    adxt_init_cnt += 1;
}

void ADXT_ResetLibrary() {
    adxt_init_cnt = 0;
    ADXT_Init();
}

void ADXT_Finish() {
    if (--adxt_init_cnt == 0) {
        dtx_send_sw = 0;
        ADXRNA_Finish();
        ADXF_Finish();
        ADXSTM_Finish();
        LSC_Finish();
        ADXCRS_Lock();
        SVM_DelCbSvr(2, 1);
        SVM_DelCbSvr(4, adxt_svr_fs_id);
        SVM_DelCbSvr(5, adxt_svr_main_id);
        SVM_Finish();
        ADXSJD_Finish();
        ADXERR_Finish();
        SJMEM_Finish();
        SJRBF_Finish();
        SJUNI_Finish();
        ADXCRS_Unlock();
        dtx_send_sw = 1;
    }
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_inis", D_0055A8C8);
