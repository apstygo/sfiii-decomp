#include "common.h"
#include <cri/private/libadxe/structs.h>

#include <cri/private/libadxe/adx_crs.h>
#include <cri/private/libadxe/adx_errs.h>
#include <cri/private/libadxe/adx_fcch.h>
#include <cri/private/libadxe/adx_fini.h>
#include <cri/private/libadxe/adx_fs.h>
#include <cri/private/libadxe/adx_stmc.h>

#include <cri/cri_adxf.h>
#include <cri/sj.h>

#include <memory.h>
#if defined(_WIN32)
#include <string.h>
#endif

typedef struct {
    /* 0x000 */ struct _adxf_ptinfo* next;
    /* 0x004 */ Sint32 size;
    /* 0x008 */ Sint32 nfile;
    /* 0x00C */ Uint16 nentry;
    /* 0x00E */ Sint8 type;
    /* 0x00F */ Sint8 rev;
    /* 0x010 */ Sint8 fname[ADXF_FNAME_MAX];
    /* 0x110 */ void* curdir;
    /* 0x114 */ Sint32 ofst;
    /* 0x118 */ Uint16 top;
    Uint16 file_sizes[0];
} ADXF_PTINFO_SMALL; /* 0x11A */

// data
void* adxf_ldpt_buf = NULL;
Sint32 adxf_ldpt_rdsct = 0;
Sint32 adxf_tcnt[10] = { 0 };
Sint32 adxf_chkp_tcnt[10] = { 0 };
Sint8 adxf_ldpt_work[0x2100] = { 0 };

// forward decls
Sint32 adxf_LoadPtBothNw(Sint32 ptid, Sint32 arg1, Sint32 arg2, Char8* fname, void* dir, ADXF_PTINFO* ptinfo,
                         void* tmpbuf, Sint32 tbsize, Sint32 rev);

Sint32 ADXF_CALC_BYTE2SCT(Sint32 bytes) {
    Sint32 result = bytes / 2048;

    if (bytes % 2048 > 0) {
        result += 1;
    }

    return result;
}

void adxf_SetCmdHstry(Sint32 cmdid, Sint32 fg, intptr_t prm_0, intptr_t prm_1, intptr_t prm_2) {
    ADXF_CMD_HSTRY* cmd_hstry;

    adxf_hstry_no %= ADXF_CMD_HSTRY_MAX;
    cmd_hstry = &adxf_cmd_hstry[adxf_hstry_no];

    if (fg == 0) {
        adxf_cmd_ncall[cmdid] += 1;
    }

    adxf_hstry_no += 1;
    cmd_hstry->cmdid = cmdid;
    cmd_hstry->fg = fg;
    cmd_hstry->ncall = adxf_cmd_ncall[cmdid];
    cmd_hstry->prm[0] = prm_0;
    cmd_hstry->prm[1] = prm_1;
    cmd_hstry->prm[2] = prm_2;
}

void adxf_wait_1ms() {
    Sint32 i;

    for (i = 0; i < 50000; i++) {
        // Do nothing
    }
}

Sint32 adxf_ChkPrmPt(Uint32 ptid, void* ptinfo) {
    if (ptid >= ADXF_PART_MAX) {
        ADXERR_CallErrFunc1("E9040801:partition ID is range outside.(adxf_ChkPrmPt)");
        return ADXF_ERR_PRM;
    }

    if (ptinfo == NULL) {
        ADXERR_CallErrFunc1("E9040802:'ptinfo' is NULL.(adxf_ChkPrmPt)");
        return ADXF_ERR_PRM;
    }

    return ADXF_ERR_OK;
}

void ADXF_LoadPartition(Sint32 arg0, Sint32 arg1, Sint8* arg2) {
    ADXF_LoadPartitionEx(arg0, arg1, 0, arg2);
}

Sint32 ADXF_LoadPartitionEx(Sint32 arg0, Sint8* arg1, void* arg2, void* arg3) {
    s32 res;
    s32 ret;

    res = ADXF_LoadPartitionNw(arg0, arg1, arg2, arg3);
    if (res < 0) {
        return res;
    }

    while (1) {
        res = ADXF_GetPtStat(arg0);
        if (res == 3) {
            ret = 0;
            break;
        }
        if (res == 4) {
            ret = -1;
            break;
        }
        ADXM_ExecMain();
        adxf_wait_1ms();
    }

    return ret;
}

Sint32 ADXF_LoadPartitionNw(Sint32 ptid, Char8* fname, void* dir, void* ptinfo) {
    void* tmpbuf = (void*)(((uintptr_t)&adxf_ldpt_work + 0x40) & ~0x3F);
    return ADXF_LoadPtNwEx(ptid, fname, dir, ptinfo, tmpbuf, 0x800);
}

Sint32 ADXF_LoadPartitionFromAfsNw(Sint32 set_ptid, Sint32 rd_ptid, Sint32 rd_flid, void* ptinfo) {
    void* tmpbuf = (void*)(((uintptr_t)&adxf_ldpt_work + 0x40) & ~0x3F);
    return ADXF_LoadPtFromAfsNwEx(set_ptid, rd_ptid, rd_flid, ptinfo, tmpbuf, 0x800);
}

void ADXF_LoadPartitionFmgLongNw(Sint32 arg0, Sint32 arg1, Sint32 arg2, void* arg3) {
    void* tmpbuf = (void*)(((uintptr_t)&adxf_ldpt_work + 0x40) & ~0x3F);
    ADXF_LoadPtFmgLongNwEx(arg0, arg1, arg2, arg3, tmpbuf, 0x800);
}

void ADXF_LoadPartitionFromAfsFmgLongNw(Sint32 arg0, Sint32 arg1, Sint32 arg2, void* arg3) {
    void* tmpbuf = (void*)(((uintptr_t)&adxf_ldpt_work + 0x40) & ~0x3F);
    ADXF_LoadPtFromAfsFmgLongNwEx(arg0, arg1, arg2, arg3, tmpbuf, 0x800);
}

Sint32 ADXF_LoadPtNwEx(Sint32 ptid, Char8* fname, void* dir, void* ptinfo, void* tmpbuf, Sint32 tbsize) {
    return adxf_LoadPtBothNw(ptid, 0, 0, fname, dir, (ADXF_PTINFO*)ptinfo, tmpbuf, tbsize, 0);
}

Sint32 ADXF_LoadPtFromAfsNwEx(Sint32 set_ptid, Sint32 rd_ptid, Sint32 rd_flid, void* ptinfo, void* tmpbuf,
                              Sint32 tbsize) {
    return adxf_LoadPtBothNw(set_ptid, rd_ptid, rd_flid, 0, 0, ptinfo, tmpbuf, tbsize, 0);
}

void ADXF_LoadPtFmgLongNwEx(Sint32 arg0, Char8* arg1, void* arg2, void* arg3, void* arg4, Sint32 arg5) {
    adxf_LoadPtBothNw(arg0, 0, 0, arg1, arg2, (ADXF_PTINFO*)arg3, arg4, arg5, 1);
}

void ADXF_LoadPtFromAfsFmgLongNwEx(Sint32 arg0, Char8* arg1, void* arg2, void* arg3, void* arg4, Sint32 arg5) {
    adxf_LoadPtBothNw(arg0, arg1, arg2, 0, 0, (ADXF_PTINFO*)arg3, arg4, arg5, 1);
}

Sint32 adxf_LoadPtBothNw(Sint32 ptid, Sint32 arg1, Sint32 arg2, Char8* fname, void* dir, ADXF_PTINFO* ptinfo,
                         void* tmpbuf, Sint32 tbsize, Sint32 rev) {
    Sint32 ofst;
    Sint32 fnsct;
    Sint32 err;

    if (tmpbuf == NULL) {
        ADXERR_CallErrFunc1("E1110701:'tmpbuf' is null.(load partition)");
        return ADXF_ERR_PRM;
    }

    if (tbsize <= 0) {
        ADXERR_CallErrFunc1("E1110702:'tbsize' <= 0.(load partition)");
        return ADXF_ERR_PRM;
    }

    err = adxf_ChkPrmPt(ptid, ptinfo);

    if (err < 0) {
        return err;
    }

    if (adxf_ldptnw_ptid >= 0) {
        ADXERR_CallErrFunc1("E0042401:multi-load partition.(load partition)");
        return ADXF_ERR_FATAL;
    }

    adxf_ldptnw_ptid = ptid;
    adxf_flno = 0;
    memset(ptinfo, 0, sizeof(ADXF_PTINFO));
    adxf_ptinfo[ptid] = ptinfo;
    ptinfo->next = NULL;

    if (fname == NULL) {
        adxf_ldptnw_hn = ADXF_OpenAfs(arg1, arg2);

        if (adxf_ldptnw_hn == NULL) {
            ADXERR_CallErrFunc1("E9040804:can't open file.(load partition)");
            return ADXF_ERR_FATAL;
        }

        err = ADXF_GetFnameRangeEx(arg1, arg2, ptinfo->fname, &dir, &ofst, &fnsct);

        if (err < 0) {
            return err;
        }

        ptinfo->ofst = ofst;
    } else {
        adxf_ldptnw_hn = ADXF_Open(fname, dir);

        if (adxf_ldptnw_hn == NULL) {
            ADXERR_CallErrFunc1("E9040804:can't open file.(load partition)");
            return ADXF_ERR_FATAL;
        }

        strncpy(ptinfo->fname, fname, ADXF_FNAME_MAX);
    }

    ptinfo->type = 0;
    ptinfo->rev = rev;
    ptinfo->curdir = dir;
    adxf_ldpt_buf = tmpbuf;
    adxf_ldpt_rdsct = tbsize / 2048;
    err = ADXF_ReadNw(adxf_ldptnw_hn, adxf_ldpt_rdsct, adxf_ldpt_buf);

    if (err < 0) {
        ADXF_Close(adxf_ldptnw_hn);
        return err;
    }

    ptinfo->nfile = 0;
    return ADXF_ERR_OK;
}

void adxf_CloseLdptnwHn() {
    ADXF_Close(adxf_ldptnw_hn);
    adxf_ldptnw_hn = NULL;
    adxf_ldptnw_ptid = -1;
    adxf_flno = 0;
    adxf_ldpt_rdsct = 0;
}

void ADXF_StopPtLd() {
    if ((adxf_ldptnw_hn == NULL) || (adxf_ldptnw_ptid < 0)) {
        return;
    }

    if (ADXF_GetStat(adxf_ldptnw_hn) != ADXF_STAT_STOP) {
        ADXF_Stop(adxf_ldptnw_hn);
    }

    adxf_CloseLdptnwHn();
}

Sint32 ADXF_GetPtStat(Sint32 ptid) {
    return ADXF_GetPtStatEx(ptid);
}

#define READ_BUF_INT32(i)                                                                                              \
    ((((Uint8*)adxf_ldpt_buf)[((i) * 4) + 0] << 0) | (((Uint8*)adxf_ldpt_buf)[((i) * 4) + 1] << 8) |                   \
     (((Uint8*)adxf_ldpt_buf)[((i) * 4) + 2] << 16) | (((Uint8*)adxf_ldpt_buf)[((i) * 4) + 3] << 24))
Sint32 ADXF_GetPtStatEx(Sint32 ptid) {
    ADXF_PTINFO* ptinfo;
    ADXF_PTINFO_SMALL* ptinfo_small;
    Sint32 temp_s4;
    Sint32 var_a0_2;
    Sint32 var_s1;
    Uint32 nfile;
    Sint32* top_rev1;
    Sint16* top_rev0;
    Sint32* fsizes_rev1;
    Uint16* fsizes_rev0;
    Sint32 stat;

    top_rev0 = NULL;
    top_rev1 = NULL;
    fsizes_rev0 = NULL;
    fsizes_rev1 = NULL;

    if (ptid != adxf_ldptnw_ptid) {
        ADXERR_CallErrFunc1("E0041303:illigal parameter 'ptid'.(ADXF_GetPtStat)");
        return ADXF_ERR_PRM;
    }

    stat = ADXF_GetStat(adxf_ldptnw_hn);

    if (stat != ADXF_STAT_READEND) {
        return stat;
    }

    ptinfo = adxf_ptinfo[ptid];
    ptinfo_small = (ADXF_PTINFO_SMALL*)ptinfo;

    if (ptinfo->rev == 1) {
        top_rev1 = &ptinfo->top;
        fsizes_rev1 = &ptinfo->file_sizes;
    } else {
        top_rev0 = &ptinfo_small->top;
        fsizes_rev0 = &ptinfo_small->file_sizes;
    }

    var_s1 = 0;
    if (ptinfo->nfile == 0) {
        if (memcmp(&adxf_ldpt_buf[var_s1], "AFS", sizeof("AFS") - 1) != 0) {
            ADXERR_CallErrFunc1("E0040701:Illigal format(not AFS).(ADXF_GetPtStat)");
            adxf_CloseLdptnwHn();
            return ADXF_STAT_ERROR;
        }

        var_s1++;
        if (READ_BUF_INT32(var_s1) > 65536) {
            ADXERR_CallErrFunc1("E0040702:Illigal number of file.(ADXF_GetPtStat)");
            adxf_CloseLdptnwHn();
            return ADXF_STAT_ERROR;
        }

        nfile = ptinfo->nfile = ptinfo->nentry = READ_BUF_INT32(var_s1);

        if (ptinfo->rev == 1) {
            ptinfo->size = nfile * 4 + 0x120;
        } else {
            ptinfo->size = ((nfile * 2 + 0x11C) / 4) * 4;
        }

        var_s1++;

        if (ptinfo->rev == 1) {
            *top_rev1 = READ_BUF_INT32(var_s1) / 2048;
        } else {
            *top_rev0 = READ_BUF_INT32(var_s1) / 2048;
        }

        var_s1++;
    } else {
        var_s1++;
    }

    temp_s4 = adxf_ldpt_rdsct * 512;

    while (var_s1 < temp_s4) {
        if (ptinfo->rev == 1) {
            fsizes_rev1[adxf_flno++] = ADXF_CALC_BYTE2SCT(READ_BUF_INT32(var_s1));
        } else {
            var_a0_2 = ADXF_CALC_BYTE2SCT(READ_BUF_INT32(var_s1));

            if (var_a0_2 & 0xFFFF0000) {
                ADXERR_CallErrFunc1("E2122501:AFS file has 128MB or more of inside file.(ADXF_GetPtStat)");
                adxf_CloseLdptnwHn();
                return ADXF_STAT_ERROR;
            }

            fsizes_rev0[adxf_flno++] = var_a0_2;
        }

        if (adxf_flno >= ptinfo->nfile) {
            adxf_CloseLdptnwHn();
            stat = ADXF_STAT_READEND;
            break;
        }

        var_s1 += 2;
    }

    if (var_s1 >= temp_s4) {
        if (ADXF_ReadNw(adxf_ldptnw_hn, adxf_ldpt_rdsct, adxf_ldpt_buf) < 0) {
            adxf_CloseLdptnwHn();
            stat = ADXF_STAT_ERROR;
        } else {
            stat = adxf_ldptnw_hn->stat;
        }
    }

    return stat;
}

Sint32 ADXF_GetPtinfoSize(Sint32 ptid) {
    return adxf_ptinfo[ptid]->size;
}

ADXF adxf_AllocAdxFs() {
    Sint32 i;
    ADXF start = NULL;

    for (i = 0; i < ADXF_OBJ_MAX; i++) {
        if (!adxf_obj[i].used) {
            start = &adxf_obj[i];
            break;
        }
    }

    return start;
}

ADXF adxf_CreateAdxFs() {
    ADXF adxf;
    ADXSTM stm;

    adxf = adxf_AllocAdxFs();

    if (adxf == NULL) {
        return NULL;
    }

    stm = ADXSTM_Create(NULL, 0x100);
    adxf->stm = stm;

    if (stm == NULL) {
        ADXERR_CallErrFunc1("E02111001:can't create stm handle (adxf_CreateAdxFs)");
        return NULL;
    }

    adxf->stat = ADXF_STAT_STOP;
    adxf->rqrdsct = 0x200;
    adxf->used = 1;
    adxf->rdstpos = 0;
    adxf->rqsct = 0;
    adxf->rdsct = 0;
    adxf->sjflag = 0;
    adxf->sj = NULL;
    adxf->stopnw_flg = 0;

    return adxf;
}

Sint32 adxf_SetFileInfoEx(ADXF adxf, Char8* fname, void* dir) {
    if (fname == NULL) {
        ADXERR_CallErrFunc1("E9081901:illigal parameter fname=null.(ADXF_Open)");
        return ADXF_ERR_FATAL;
    }

    adxf->dir = dir;
    adxf->unk38 = fname;
    adxf->skpos = 0;
    ADXSTM_BindFile(adxf->stm, fname, dir, 0, 0xFFFFF);

    if (ADXSTM_GetStat(adxf->stm) == 4) {
        ADXSTM_ReleaseFile(adxf->stm);
        return ADXF_ERR_FATAL;
    }

    adxf->fsize = ADXSTM_GetFileLen(adxf->stm);
    adxf->unk40 = adxf->fnsct = ADXSTM_GetFileSct(adxf->stm);
    adxf->unk3C = 0;
    return ADXF_ERR_OK;
}

ADXF ADXF_Open(Char8* fname, void* atr) {
    ADXF adxf;

    adxf_SetCmdHstry(ADXF_CMD_OPEN, 0, (intptr_t)fname, (intptr_t)atr, -1);
    adxf = adxf_CreateAdxFs();

    if (adxf != NULL) {
        if (adxf_SetFileInfoEx(adxf, fname, atr) < 0) {
            ADXF_Close(adxf);
            adxf = NULL;
        }
    }

    adxf_SetCmdHstry(ADXF_CMD_OPEN, 1, (intptr_t)fname, (intptr_t)atr, -1);
    return adxf;
}

Sint32 adxf_SetAfsFileInfo(ADXF adxf, Sint32 ptid, Sint32 flid) {
    Char8 fname[256];
    void* dir;
    Sint32 ofst;
    Sint32 fnsct;

    if (ADXF_GetFnameRangeEx(ptid, flid, fname, &dir, &ofst, &fnsct) < 0) {
        return ADXF_ERR_PRM;
    }

    adxf->ofst = ofst;
    adxf->dir = dir;
    adxf->unk38 = ADXF_GetFnameFromPt(ptid);
    adxf->skpos = 0;
    adxf->unk40 = fnsct;
    adxf->unk3C = ofst;

    ADXSTM_BindFile(adxf->stm, adxf->unk38, adxf->dir, adxf->unk3C, adxf->unk40);

    if (ADXSTM_GetStat(adxf->stm) == 4) {
        ADXSTM_ReleaseFile(adxf->stm);
        return ADXF_ERR_FATAL;
    }

    adxf->fnsct = fnsct;
    adxf->fsize = fnsct << 11;
    return ADXF_ERR_OK;
}

ADXF ADXF_OpenAfs(Sint32 ptid, Sint32 flid) {
    ADXF adxf;

    adxf_SetCmdHstry(ADXF_CMD_OPEN_AFS, 0, (intptr_t)ptid, (intptr_t)flid, -1);
    adxf = adxf_CreateAdxFs();

    if ((adxf != NULL) && (adxf_SetAfsFileInfo(adxf, ptid, flid) < 0)) {
        ADXF_Close(adxf);
        adxf = NULL;
    }

    adxf_SetCmdHstry(ADXF_CMD_OPEN_AFS, 1, (intptr_t)ptid, (intptr_t)flid, -1);
    return adxf;
}

void adxf_CloseSjStm(ADXF adxf) {
    SJ sj;

    if ((adxf->sj == NULL) || (adxf->sjflag != 0)) {
        return;
    }

    if (adxf_ocbi_fg == 1) {
        ADXF_Ocbi(adxf->buf, adxf->bsize);
    }

    sj = adxf->sj;
    adxf->sj = NULL;
    SJ_Destroy(sj);
}

void ADXF_Close(ADXF adxf) {
    ADXSTM stm;

    adxf_SetCmdHstry(ADXF_CMD_CLOSE, 0, (intptr_t)adxf, -1, -1);

    if (adxf == NULL) {
        return;
    }

    if (adxf->stat == 2) {
        ADXF_Stop(adxf);
    }

    stm = adxf->stm;

    if (stm != NULL) {
        adxf->used = 0;
        adxf->stm = NULL;
        ADXSTM_ReleaseFile(stm);
        ADXSTM_Destroy(stm);
    }

    memset(adxf, 0, sizeof(ADX_FS));
    adxf_SetCmdHstry(ADXF_CMD_CLOSE, 1, (intptr_t)adxf, -1, -1);
}

void ADXF_CloseAll() {
    Sint32 i;

    for (i = 0; i < ADXF_OBJ_MAX; i++) {
        if (adxf_obj[i].used == 1) {
            ADXF_Close(&adxf_obj[i]);
        }
    }
}

Sint32 adxf_read_sj32(ADXF adxf, Sint32 nsct, SJ sj) {
    Sint32 rqsct;

    if (ADXSTM_GetStat(adxf->stm) != 1) {
        ADXSTM_Stop(adxf->stm);
    }

    ADXCRS_Lock();

    adxf->rdsct = 0;
    adxf->rdstpos = adxf->ofst + adxf->skpos;
    adxf->rqsct = (nsct < (adxf->fnsct - adxf->skpos)) ? nsct : adxf->fnsct - adxf->skpos;

    if (adxf->rqsct == 0) {
        adxf->stat = ADXF_STAT_READEND;
        rqsct = 0;
    } else {
        ADXSTM_SetEos(adxf->stm, -1); // Read to the end
        ADXSTM_SetSj(adxf->stm, sj);
        ADXSTM_SetReqRdSize(adxf->stm, adxf->rqrdsct);
        adxf->stat = ADXF_STAT_READING;
        adxf->stopnw_flg = 0;
        ADXSTM_SetPause(adxf->stm, 0);
        ADXSTM_Seek(adxf->stm, adxf->skpos);
        ADXSTM_Start2(adxf->stm, adxf->rqsct);
        rqsct = adxf->rqsct;
    }

    ADXCRS_Unlock();
    return rqsct;
}

Sint32 ADXF_ReadSj32(ADXF adxf, Sint32 nsct, SJ sj) {
    Sint32 ret;

    if (adxf == NULL) {
        ADXERR_CallErrFunc1("E9040811:'adxf' is NULL.(ADXF_ReadSj32)");
        return ADXF_ERR_PRM;
    }
    if (nsct < 0) {
        ADXERR_CallErrFunc1("E9040812:'nsct'is negative.(ADXF_ReadSj32)");
        return ADXF_ERR_PRM;
    }
    if (sj == NULL) {
        ADXERR_CallErrFunc1("E9040813:'sj'is NULL.(ADXF_ReadSj32)");
        return ADXF_ERR_PRM;
    }

    if (adxf->stat == 2) {
        return 0;
    }

    ret = adxf_read_sj32(adxf, nsct, sj);
    adxf->sjflag = 1;
    return ret;
}

Sint32 ADXF_ReadSj(ADXF adxf, Sint32 nsct, SJ sj) {
    return ADXF_ReadSj32(adxf, nsct, sj);
}

Sint32 ADXF_ReadNw32(ADXF adxf, Sint32 nsct, void* buf) {
    SJ sj;
    SJ sjrbf;
    Sint32 bsize;
    Sint32 temp_v0_2;

    adxf_SetCmdHstry(ADXF_CMD_READ_NW32, 0, (intptr_t)adxf, (intptr_t)nsct, (intptr_t)buf);

    if (adxf == NULL) {
        ADXERR_CallErrFunc1("E9040816:'adxf' is NULL.(ADXF_ReadNw32)");
        return ADXF_ERR_PRM;
    }

    if (nsct < 0) {
        ADXERR_CallErrFunc1("E9040817:'nsct' is negative.(ADXF_ReadNw32)");
        return ADXF_ERR_PRM;
    }

    if (buf == NULL) {
        ADXERR_CallErrFunc1("E9040818:'buf' is NULL.(ADXF_ReadNw32)");
        return ADXF_ERR_PRM;
    }

    if (adxf->stat == ADXF_STAT_READING) {
        return ADXF_ERR_OK;
    }

    if (adxf->sj != NULL) {
        ADXERR_CallErrFunc1("E9040821:'sj' must be NULL.(ADXF_ReadNw32)");
        return ADXF_ERR_FATAL;
    }

    bsize = nsct << 11;
    sjrbf = SJRBF_Create(buf, bsize, 0);

    if (sjrbf == NULL) {
        return ADXF_ERR_INTERNAL;
    }

    ADXCRS_Lock();
    adxf->buf = buf;
    adxf->sj = sjrbf;
    adxf->bsize = bsize;

    if (adxf_ocbi_fg == 1) {
        ADXF_Ocbi(buf, bsize);
    }

    ADXCRS_Unlock();
    temp_v0_2 = adxf_read_sj32(adxf, nsct, adxf->sj);

    if (temp_v0_2 <= 0) {
        ADXCRS_Lock();
        sj = adxf->sj;

        if (sj != NULL) {
            SJ_Destroy(sj);
            adxf->sj = NULL;
        }

        ADXCRS_Unlock();
    }

    adxf->sjflag = 0;
    adxf_SetCmdHstry(ADXF_CMD_READ_NW32, 1, (intptr_t)adxf, (intptr_t)nsct, (intptr_t)buf);
    return temp_v0_2;
}

Sint32 ADXF_ReadNw(ADXF adxf, Sint32 nsct, void* buf) {
    if ((uintptr_t)buf & 0x3F) {
        ADXERR_CallErrFunc1("E0120401:'buf' isn't 64byte alignment.(ADXF_ReadNw)");
        return ADXF_ERR_PRM;
    }

    return ADXF_ReadNw32(adxf, nsct, buf);
}

Sint32 ADXF_Stop(ADXF adxf) {
    ADXSTM stm;

    adxf_SetCmdHstry(ADXF_CMD_STOP, 0, (intptr_t)adxf, -1, -1);

    if (adxf == NULL) {
        ADXERR_CallErrFunc1("E9040822:'adxf' is NULL.(ADXF_Stop)");
        return ADXF_ERR_PRM;
    }

    switch (adxf->stat) {
    case 3:
        adxf->stat = ADXF_STAT_STOP;
        /* fallthrough */

    case 1:
        break;

    default:
        stm = adxf->stm;

        if (stm == NULL) {
            ADXERR_CallErrFunc1("E9040823:'adxf->stm' is NULL.(ADXF_Stop)");
            return -1;
        }

        ADXSTM_Stop(stm);
        ADXCRS_Lock();
        adxf->rdsct = ADXSTM_Tell(adxf->stm) - adxf->skpos;
        adxf_CloseSjStm(adxf);
        adxf->stat = ADXF_STAT_STOP;
        ADXCRS_Unlock();
        adxf_SetCmdHstry(ADXF_CMD_STOP, 1, (intptr_t)adxf, -1, -1);
        break;
    }

    return adxf->skpos;
}

Sint32 ADXF_StopNw(ADXF adxf) {
    adxf_SetCmdHstry(ADXF_CMD_STOP_NW, 0, (intptr_t)adxf, -1, -1);

    if (adxf == NULL) {
        ADXERR_CallErrFunc1("E2092301:'adxf' is NULL.(ADXF_StopNw)");
        return ADXF_ERR_PRM;
    }

    switch (adxf->stat) {
    case ADXF_STAT_STOP:
        // Do nothing
        break;

    case ADXF_STAT_READEND:
        adxf->stat = ADXF_STAT_STOP;
        break;

    default:
        if (adxf->stm == NULL) {
            ADXERR_CallErrFunc1("E2092302:'adxf->stm' is NULL.(ADXF_StopNw)");
            return ADXF_ERR_FATAL;
        }

        ADXSTM_StopNw(adxf->stm);
        adxf->stopnw_flg = 1;
        adxf_SetCmdHstry(ADXF_CMD_STOP_NW, 1, (intptr_t)adxf, -1, -1);
        break;
    }

    return adxf->skpos;
}

void adxf_ExecOne(ADXF adxf) {
    Sint32 stat;
    Sint8 stopnw_flg;

    if (adxf->stat == ADXF_STAT_READING) {
        adxf->stat = ADXSTM_GetStat(adxf->stm);
        adxf->rdsct = ADXSTM_Tell(adxf->stm) - adxf->skpos;

        if ((Uint32)((u8)adxf->stat - 3) < 2) {
            adxf->skpos = adxf->skpos + adxf->rdsct;
            adxf_CloseSjStm(adxf);
        }
    }

    stopnw_flg = adxf->stopnw_flg;

    if (adxf->stopnw_flg == 1) {
        stat = ADXSTM_GetStat(adxf->stm);

        if (stat == 1) {
            adxf->rdsct = ADXSTM_Tell(adxf->stm) - adxf->skpos;
            adxf_CloseSjStm(adxf);
            adxf->stat = stat;
            adxf->stopnw_flg = 0;
        }
    }
}

void ADXF_ExecServer() {
    Sint32 i;

    ADXCRS_Lock();

    for (i = 0; i < ADXF_OBJ_MAX; i++) {
        if (adxf_obj[i].used == 1) {
            adxf_ExecOne(&adxf_obj[i]);
        }
    }

    ADXCRS_Unlock();
}

Sint32 ADXF_Seek(ADXF adxf, Sint32 pos, Sint32 type) {
    adxf_SetCmdHstry(6, 0, (intptr_t)adxf, pos, type);
    if (adxf == NULL) {
        ADXERR_CallErrFunc1("E9040825:'adxf' is NULL.(ADXF_Seek)");
        return ADXF_ERR_PRM;
    }

    if (adxf->stat == 2) {
        ADXF_Stop(adxf);
    }

    if (type == 0) {
        adxf->skpos = pos;
    } else if (type == 1) {
        adxf->skpos = adxf->skpos + pos;
    } else if (type == 2) {
        adxf->skpos = adxf->fnsct + pos;
    } else {
        ADXERR_CallErrFunc1("E9040826:'type' is illigal.(ADXF_Seek)");
        return ADXF_ERR_PRM;
    }

    if (adxf->skpos < 0) {
        adxf->skpos = 0;
    } else if (adxf->fnsct < adxf->skpos) {
        adxf->skpos = adxf->fnsct;
    }

    adxf_SetCmdHstry(6, 1, (intptr_t)adxf, pos, type);
    return adxf->skpos;
}

Sint32 ADXF_Tell(ADXF adxf) {
    if (adxf == NULL) {
        ADXERR_CallErrFunc1("E9040827:'adxf' is NULL.(ADXF_Tell)");
        return ADXF_ERR_PRM;
    }

    return adxf->skpos;
}

Sint32 ADXF_GetFsizeSct(ADXF adxf) {
    if (adxf == NULL) {
        ADXERR_CallErrFunc1("E9040828:'adxf' is NULL.(ADXF_GetFsizeSct)");
        return ADXF_ERR_PRM;
    }

    if (adxf->fnsct > 0xFFFFE) {
        ADXSTM_OpenCvfs(adxf->stm);

        if (ADXSTM_GetStat(adxf->stm) == 4) {
            return ADXF_ERR_FSIZE;
        }
    }

    return adxf->fnsct = ADXSTM_GetFileSct(adxf->stm);
}

Sint32 ADXF_GetFsizeByte(ADXF adxf) {
    return ADXF_GetFsizeSct(adxf) << 0xB;
}

Sint32 ADXF_GetNumReqSct(ADXF adxf, Sint32* seekpos) {
    if (adxf == NULL) {
        ADXERR_CallErrFunc1("E9040830:'adxf' is NULL.(ADXF_GetNumReqSct)");
        *seekpos = 0;
        return ADXF_ERR_PRM;
    }

    *seekpos = adxf->rdstpos;
    return adxf->rqsct;
}

Sint32 ADXF_GetNumReadSct(ADXF adxf) {
    if (adxf == NULL) {
        ADXERR_CallErrFunc1("E9040831:'adxf' is NULL.(ADXF_GetNumReadSct)");
        return ADXF_ERR_PRM;
    }

    return adxf->rdsct;
}

Sint32 ADXF_GetStat(ADXF adxf) {
    if (adxf == NULL) {
        ADXERR_CallErrFunc1("E9040832:'adxf' is NULL.(ADXF_GetStat)");
        return ADXF_ERR_PRM;
    }

    return adxf->stat;
}

Sint32 adxf_ChkPrmGfr(Uint32 ptid, Sint32 flid) {
    ADXF_PTINFO* ptinfo;

    if (ptid >= ADXF_PART_MAX) {
        ADXERR_CallErrFunc1("E9040828:'ptid' is range outside.");
        return ADXF_ERR_PRM;
    }

    ptinfo = adxf_ptinfo[ptid];

    if (ptinfo == NULL) {
        ADXERR_CallErrFunc1("E9040828:'ptid' is range outside.");
        return ADXF_ERR_PRM;
    }

    if ((flid < 0) || (flid >= ptinfo->nfile)) {
        ADXERR_CallErrFunc1("E9040828:'flid' is range outside.");
        return ADXF_ERR_PRM;
    }

    return ADXF_ERR_OK;
}

Sint32 ADXF_GetFnameRange(Sint32 ptid, Sint32 flid, Char8* fname, Sint32* ofst, Sint32* fnsct) {
    void* dir;
    return ADXF_GetFnameRangeEx(ptid, flid, fname, &dir, ofst, fnsct);
}

Sint32 ADXF_GetFnameRangeEx(Sint32 ptid, Sint32 flid, Char8* fname, void** dir, Sint32* ofst, Sint32* fnsct) {
    ADXF_PTINFO* ptinfo;
    Sint32 ret;
    Sint32 i;
    Uint32 offset;
    Uint16* p2;
    Uint32* p4;

    ADXF_PTINFO_SMALL* small_ptinfo;

    ret = adxf_ChkPrmGfr(ptid, flid);

    if (ret < 0) {
        *ofst = -1;
        *fnsct = -1;
        *dir = NULL;
        return ret;
    }

    ptinfo = adxf_ptinfo[ptid];
    small_ptinfo = (ADXF_PTINFO_SMALL*)ptinfo;

    if (ptinfo->rev == 1) {
        offset = ptinfo->top;
        p4 = (Uint32*)(ptinfo + 1);

        for (i = 0; i < flid; i++) {
            offset += p4[i];
        }

        *fnsct = p4[flid];
    } else {
        offset = small_ptinfo->top;
        p2 = small_ptinfo->file_sizes;

        for (i = 0; i < flid; i++) {
            offset += p2[i];
        }

        *fnsct = p2[flid];
    }

    strncpy(fname, ptinfo->fname, ADXF_FNAME_MAX);
    *dir = ptinfo->curdir;
    *ofst = ptinfo->ofst + offset;

    return ret;
}

Char8* ADXF_GetFnameFromPt(Sint32 ptid) {
    return adxf_ptinfo[ptid]->fname;
}

void ADXF_SetOcbiSw(Sint32 arg0) {
    adxf_ocbi_fg = arg0;
}

void ADXF_SetReqRdSct(ADXF adxf, Sint32 nsct) {
    if (adxf->stat == 2) {
        ADXERR_CallErrFunc1("E0041201:state is reading(ADXF_SetReqRdSct)");
        return;
    }

    adxf->rqrdsct = nsct;
}

Sint32 ADXF_GetStatRead(ADXF adxf) {
    if (adxf == NULL) {
        return 0;
    }

    if (adxf->stm == NULL) {
        return 0;
    }

    return ADXSTM_GetReadFlg(adxf->stm);
}

void ADXF_GetFileSize(void) {
    cvFsGetFileSize();
}
