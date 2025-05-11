#include "common.h"
#include <cri/private/libadxe/adx_crs.h>
#include <cri/private/libadxe/adx_errs.h>
#include <cri/private/libadxe/adx_stmc.h>
#include <cri/private/libadxe/cri_cvfs.h>
#include <cri/private/libadxe/svm.h>

#include <cri/cri_adxt.h>
#include <cri/sj.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

// data
extern Sint32 adxstmf_rtim_ofst;
extern Sint32 adxstmf_rtim_num;
extern Sint32 adxstmf_nrml_ofst;
extern Sint32 adxstmf_nrml_num;
extern Sint32 adxstmf_num_rtry;
extern Sint32 adxstm_sj_internal_error_cnt;
extern ADXSTM_OBJ adxstmf_obj[40];

// forward declarations
void ADXSTM_StopNw();

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXT_SetupRtimeNumStm);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXT_SetupNrmlNumStm);

Sint32 ADXSTM_Init() {
    memset(adxstmf_obj, 0, sizeof(adxstmf_obj));
    return 1;
}

void ADXSTM_Reset() {
    // Do nothing
}

void ADXSTM_Finish() {
    // Do nothing
}

void ADXSTMF_SetupHandleMember(ADXSTM arg0, Sint32 offset, Sint32 arg2, Sint32 arg3, SJ arg4) {
    Sint32 length;

    ADXCRS_Lock();

    length = arg3 / 2048;

    // This rounds length up
    if (arg3 - length * 2048 > 0) {
        length += 1;
    }

    arg0->stat = 1;
    arg0->unk2 = 0;
    arg0->unk4 = arg4;
    arg0->cvfs = offset;
    arg0->unkC = arg2;
    arg0->unk2C = 0x200;
    arg0->unk5C = 0xFFFFF;
    arg0->stream_length = length;
    arg0->eos = length;
    arg0->current_position = 0;
    arg0->unk10 = arg3;

    if (arg4 != NULL) {
        arg0->unk1C = arg0->unk18 = arg0->unk40 = SJ_GetNumData(arg4, 0) + SJ_GetNumData(arg4, 1);
    }

    arg0->unk0 = 1;
    arg0->unk44 = 0;
    ADXCRS_Unlock();
}

ADXSTM ADXSTMF_CreateCvfsRt(Sint32 arg0, Sint32 offset, Sint32 arg2, SJ arg3) {
    ADXSTM stm = NULL;
    Sint32 i;

    for (i = 0; i < adxstmf_rtim_num; i++) {
        stm = &adxstmf_obj[adxstmf_rtim_ofst + i];

        if (stm->unk0 == 0) {
            break;
        }
    }

    if (i == adxstmf_rtim_num) {
        return NULL;
    }

    ADXSTMF_SetupHandleMember(stm, arg0, offset, arg2, arg3);
    return stm;
}

ADXSTM ADXSTMF_CreateCvfs(Sint32 arg0, Sint32 offset, Sint32 arg2, SJ arg3) {
    ADXSTM stm = NULL;
    Sint32 i;

    for (i = 0; i < adxstmf_nrml_num; i++) {
        stm = &adxstmf_obj[adxstmf_nrml_ofst + i];

        if (stm->unk0 == 0) {
            break;
        }
    }

    if (i == adxstmf_nrml_num) {
        return NULL;
    }

    ADXSTMF_SetupHandleMember(stm, arg0, offset, arg2, arg3);
    return stm;
}

ADXSTM ADXSTM_Create(SJ sj, Sint32 offset) {
    ADXSTM stm;

    if (offset < 0x100) {
        stm = ADXSTMF_CreateCvfsRt(0, 0, 0, sj);
    } else {
        stm = ADXSTMF_CreateCvfs(0, 0, 0, sj);
    }

    return stm;
}

void ADXSTM_Destroy(ADXSTM stm) {
    if (stm != NULL) {
        ADXSTM_Stop(stm);
        ADXSTM_ReleaseFile(stm);
        stm->unk0 = 0;
        memset(stm, 0, sizeof(ADXSTM_OBJ));
    }
}

void ADXSTM_BindFileNw(ADXSTM stm, Char8 *fname, void *dir, Sint32 arg3, Sint32 arg4) {
    SVM_Lock();
    stm->unkC = arg3;
    stm->unk10 = arg4 << 11;
    stm->stream_length = arg4;
    stm->fname = fname;
    stm->dir = dir;
    stm->unk45 = 1;
    SVM_Unlock();
}

void ADXSTM_BindFile(ADXSTM stm, Char8 *fname, void *dir, Sint32 arg3, Sint32 arg4) {
    ADXSTM_BindFileNw(stm, fname, dir, arg3, arg4);

    do {
        ADXT_ExecFsSvr();
    } while (stm->unk45 != 0);
}

void ADXSTM_ReleaseFileNw(ADXSTM stm) {
    ADXSTM_StopNw(stm);
    SVM_Lock();

    if (stm->unk49 == 1) {
        stm->unk46 = 1;
    }

    stm->unk45 = 0;
    SVM_Unlock();
}

void ADXSTM_ReleaseFile(ADXSTM stm) {
    ADXSTM_Stop(stm);
    ADXSTM_ReleaseFileNw(stm);

    while (stm->unk49 != 0) {
        ADXT_ExecFsSvr();
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_IsOpenedFile);

Sint32 ADXSTM_GetStat(ADXSTM stm) {
    return stm->stat;
};

Sint32 ADXSTM_Seek(ADXSTM stm, Sint32 offset) {
    stm->current_position = offset;

    if (stm->stream_length < offset) {
        stm->current_position = stm->stream_length;
    }

    return stm->current_position;
}

Sint32 ADXSTM_Tell(ADXSTM stm) {
    if (stm->cvfs == NULL) {
        return 0;
    }

    return stm->current_position;
}

void adxstm_start_sub(ADXSTM stm) {
    stm->unk34 = 0;
    stm->unk3 = 0;

    if (stm->stream_length == 0) {
        stm->stat = 3;
    } else {
        stm->stat = 2;
    }

    stm->unk2 = 0;
    stm->unk24.data = NULL;
    stm->unk24.len = 0;
    stm->unk47 = 1;
}

Sint32 ADXSTM_Start(ADXSTM stm) {
    ADXCRS_Lock();
    adxstm_start_sub(stm);
    stm->unk5C = 0xFFFFF;
    ADXCRS_Unlock();
    return 1;
}

Sint32 ADXSTM_Start2(ADXSTM stm, Sint32 arg1) {
    ADXCRS_Lock();
    adxstm_start_sub(stm);
    stm->unk5C = arg1;
    ADXCRS_Unlock();
    return 1;
}

void ADXSTM_StopNw(ADXSTM stm) {
    SVM_Lock();

    if (stm->stat == 2 && stm->unk2 == 1) {
        stm->unk48 = 1;

        if (stm->unk47 == 1) {
            stm->unk47 = 0;
        }
    } else {
        stm->stat = 1;
    }

    SVM_Unlock();
}

void ADXSTM_Stop(ADXSTM stm) {
    ADXSTM_StopNw(stm);

    do {
        ADXT_ExecFsSvr();
    } while (stm->stat != 1 || stm->unk24.data != NULL);
}

void ADXSTM_EntryEosFunc(ADXSTM stm, void (*func)(void *), void *context) {
    stm->eos_callback = func;
    stm->eos_callback_context = context;
}

void ADXSTM_SetEos(ADXSTM stm, Sint32 eos) {
    if (eos >= 0) {
        stm->eos = eos;
    } else {
        stm->eos = stm->stream_length;
    }
}

void adxstm_sj_internal_error() {
    adxstm_sj_internal_error_cnt += 1;
}

void adxstmf_stat_exec(ADXSTM stm) {
    SJCK chunk_0;
    SJCK chunk_1;
    SJ sj;
    Sint32 len;
    Sint32 cvFs_stat;
    Sint32 temp_s0_5;
    Sint32 stream_len;

    sj = stm->unk4;
    cvFs_stat = cvFsGetStat(stm->cvfs);
    SVM_Lock();

    if (stm->unk2 == 1) {
        if (cvFs_stat == 1) {
            stm->unk2 = 0;
            SVM_Unlock();
            temp_s0_5 = stm->unk20 << 11;
            SJ_SplitChunk(&stm->unk24, temp_s0_5, &chunk_0, &chunk_1);
            SJ_PutChunk(sj, 1, &chunk_0);
            SJ_UngetChunk(sj, 0, &chunk_1);
            stm->current_position += stm->unk20;

            stm->unk34 += temp_s0_5;
            stm->unk24.len = 0;
            stm->unk24.data = NULL;
            stream_len = stm->stream_length;

            if (stm->current_position == stm->eos) {
                if (stm->eos_callback != NULL) {
                    stm->eos_callback(stm->eos_callback_context);
                }
            }

            if (stm->current_position >= stream_len || ((stm->unk34 >> 11) >= stm->unk5C && stm->unk5C <= 0xFFFFE)) {
                stm->stat = 3;
            }

            stm->unk3 = 0;
            return;
        } else if (cvFs_stat == 3) {
            stm->unk2 = 0;
            SVM_Unlock();
            SJ_UngetChunk(sj, 0, &stm->unk24);
            stm->unk24.data = NULL;
            stm->unk24.len = 0;
        } else {
            SVM_Unlock();
            return;
        }

    } else {
        stm->unk2 = 1;
        stm->unk24.data = NULL;
        stm->unk24.len = 0;

        SVM_Unlock();

        if (stm->unk44 == 1) {
            stm->unk2 = 0;
            return;
        }

        if (stm->unk48 == 1) {
            stm->unk2 = 0;
            return;
        }
        if (stm->stream_length == 0) {
            stm->stat = 3;
            stm->unk20 = 0;
            stm->unk2 = 0;
            return;
        }

        if (sj == NULL || sj->vtbl == NULL) {
            stm->unk2 = 0;
            adxstm_sj_internal_error();
            return;
        }

        if ((stm->unk40 - SJ_GetNumData(sj, 0)) >= stm->unk1C) {
            stm->unk2 = 0;
            return;
        }

        SJ_GetChunk(sj, 0, stm->unk18, &chunk_1);
        len = chunk_1.len / 2048;
        len = MIN(len, stm->eos - stm->current_position);
        len = MIN(len, stm->stream_length - stm->current_position);
        len = MIN(len, stm->unk2C);
        cvFsSeek(stm->cvfs, stm->unkC + stm->current_position, 0);
        stm->unk20 = cvFsReqRd(stm->cvfs, len, chunk_1.data);
        stm->unk24.data = chunk_1.data;
        stm->unk24.len = chunk_1.len;

        if (stm->unk20 > 0) {
            return;
        }

        SJ_UngetChunk(sj, 0, &stm->unk24);
        stm->unk24.data = NULL;
        stm->unk24.len = 0;
        stm->unk2 = 0;

        if (cvFsGetStat(stm->cvfs) != 3) {
            return;
        }
    }

    if (adxstmf_num_rtry >= 0) {
        if (stm->unk3 >= adxstmf_num_rtry) {
            stm->stat = 4;
        } else {
            stm->unk3 += 1;
        }
    }
}

void ADXSTMF_ExecHndl(ADXSTM stm) {
    Sint32 cvfs;
    Sint32 cur_pos;

    if (stm->unk2 == 0) {
        if (stm->unk48 == 1) {
            stm->unk48 = 0;

            if (stm->unk47 == 0) {
                stm->stat = 1;
            }
        }

        if (stm->unk46 == 1) {
            cvfs = stm->cvfs;

            if (cvfs != NULL) {
                stm->cvfs = NULL;
                cvFsClose(cvfs);
            }

            stm->unk46 = 0;
            stm->unk49 = 0;
        }

        SVM_Lock();

        if (stm->unk45 == 1) {
            stm->unk49 = 1;
            SVM_Unlock();

            if (stm->cvfs == NULL) {
                stm->cvfs = cvFsOpen(stm->fname, stm->dir, 0);

                if (stm->cvfs == NULL) {
                    ADXERR_CallErrFunc2("E02110501 adxstmf_stat_exec: can't open ", stm->fname);
                    stm->stat = 4;
                    stm->unk49 = 0;
                    stm->unk45 = 0;
                    return;
                }

                cvFsSeek(stm->cvfs, 0, 2);
                cur_pos = cvFsTell(stm->cvfs);
                cvFsSeek(stm->cvfs, 0, 0);

                if (stm->unk10 == 0x7FFFF800) {
                    stm->stream_length = cur_pos;
                    stm->unk10 = stm->stream_length << 11;
                } else {
                    if (stm->unkC > cur_pos) {
                        stm->unkC = cur_pos;
                    }

                    if ((stm->stream_length + stm->unkC) > cur_pos) {
                        stm->stream_length = cur_pos - stm->unkC;
                        stm->unk10 = stm->stream_length << 11;
                    }
                }

                ADXSTM_Seek(stm, 0);
                stm->unk45 = 0;
            }
        } else {
            SVM_Unlock();
        }

        if (stm->unk47 == 1) {
            stm->unk47 = 0;
        }
    }

    if ((stm->stat == 2) && (stm->unk49 == 1)) {
        adxstmf_stat_exec(stm);
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_ExecServer);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetCurOfst);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetBufSize);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetSj);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_SetBufSize);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_SetReqRdSize);

void ADXSTM_EntryErrFunc() {
    // Do nothing
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetFileLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetFileSct);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_SetPause);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetPause);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetCvdfsStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetFad);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetFsizeSct);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetFsizeByte);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_SetSj);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_SetRdSct);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_SetOfst);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXT_SetNumRetry);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_GetReadFlg);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_stmc", ADXSTM_OpenCvfs);
