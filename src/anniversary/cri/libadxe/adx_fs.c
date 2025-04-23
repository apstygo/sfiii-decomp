#include "common.h"
#include <cri/cri_adxf.h>
#include <cri/private/libadxe/adx_crs.h>
#include <cri/private/libadxe/adx_errs.h>
#include <cri/private/libadxe/adx_fcch.h>
#include <cri/private/libadxe/adx_fini.h>
#include <cri/private/libadxe/adx_fs.h>
#include <cri/private/libadxe/adx_stmc.h>
#include <cri/sj.h>
#include <memory.h>

// TODO: Remove trailing null bytes from string literals

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_CALC_BYTE2SCT);

void adxf_SetCmdHstry(s32 ncall, s32 fg, s32 ptid, s32 flid, s32 type) {
    ADXF_CMD_HSTRY *cmd_hstry;

    adxf_hstry_no %= ADXF_CMD_HSTRY_MAX;
    cmd_hstry = &adxf_cmd_hstry[adxf_hstry_no];

    if (fg == 0) {
        adxf_cmd_ncall[ncall]++;
    }

    adxf_hstry_no++;
    cmd_hstry->cmdid = ncall;
    cmd_hstry->fg = fg;
    cmd_hstry->ncall = adxf_cmd_ncall[ncall];
    cmd_hstry->prm[0] = ptid;
    cmd_hstry->prm[1] = flid;
    cmd_hstry->prm[2] = type;
}

void adxf_wait_1ms() {
    s32 i;

    for (i = 0; i < 50000; i++)
        ;
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A278);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A2B0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_ChkPrmPt);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPartition);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPartitionEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPartitionNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPartitionFromAfsNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPartitionFmgLongNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPartitionFromAfsFmgLongNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPtNwEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPtFromAfsNwEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPtFmgLongNwEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_LoadPtFromAfsFmgLongNwEx);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A2E0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A310);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A338);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A368);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_LoadPtBothNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_CloseLdptnwHn);

void ADXF_StopPtLd() {
    if ((adxf_ldptnw_hn == NULL) || (adxf_ldptnw_ptid < 0)) {
        return;
    }

    if (ADXF_GetStat(adxf_ldptnw_hn) != ADXF_STAT_STOP) {
        ADXF_Stop(adxf_ldptnw_hn);
    }

    adxf_CloseLdptnwHn();
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetPtStat);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A398);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A3D0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A3D8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A410);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A448);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetPtStatEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetPtinfoSize);

ADXF adxf_AllocAdxFs() {
    s32 i;
    ADXF temp;
    ADXF start = NULL;

    for (i = 0; i < ADXF_OBJ_MAX; i++) {
        temp = &adxf_obj[i];

        if (!temp->used) {
            start = temp;
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

    stm = ADXSTM_Create(0, 0x100);
    adxf->stm = stm;

    if (stm == NULL) {
        ADXERR_CallErrFunc1("E02111001:can't create stm handle (adxf_CreateAdxFs)");
        return NULL;
    }

    adxf->stat = 1;
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

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A4C8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_SetFileInfoEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_Open);

s32 adxf_SetAfsFileInfo(ADX_FS *adxf, s32 ptid, s32 flid) {
    Char8 fname[256];
    void *dir;
    s32 ofst;
    s32 fnsct;

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

ADXF ADXF_OpenAfs(s32 ptid, s32 flid) {
    ADXF adxf;

    adxf_SetCmdHstry(2, 0, ptid, flid, -1);
    adxf = adxf_CreateAdxFs();

    if ((adxf != NULL) && (adxf_SetAfsFileInfo(adxf, ptid, flid) < 0)) {
        ADXF_Close(adxf);
        adxf = NULL;
    }

    adxf_SetCmdHstry(2, 1, ptid, flid, -1);
    return adxf;
}

void adxf_CloseSjStm(ADXF adxf) {
    if ((adxf->sj == NULL) || (adxf->sjflag != 0)) {
        return;
    }

    if (adxf_ocbi_fg == 1) {
        ADXF_Ocbi(adxf->buf, adxf->bsize);
    }

    SJ_Destroy(adxf->sj);
    adxf->sj = NULL;
}

void ADXF_Close(ADXF adxf) {
    ADXSTM stm;

    adxf_SetCmdHstry(3, 0, (Sint32)adxf, -1, -1);

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
    adxf_SetCmdHstry(3, 1, (Sint32)adxf, -1, -1);
}

void ADXF_CloseAll() {
    Sint32 i;

    for (i = 0; i < ADXF_OBJ_MAX; i++) {
        if (adxf_obj[i].used == 1) {
            ADXF_Close(&adxf_obj[i]);
        }
    }
}

Sint32 adxf_read_sj32(ADXF adxf, s32 nsct, SJ sj) {
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
        ADXSTM_SetEos(adxf->stm, -1);
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

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A500);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A528);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A558);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_ReadSj32);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_ReadSj);

Sint32 ADXF_ReadNw32(ADXF adxf, Sint32 nsct, void *buf) {
    SJ sj;
    SJ sjrbf;
    Sint32 bsize;
    Sint32 temp_v0_2;

    adxf_SetCmdHstry(4, 0, adxf, nsct, buf);

    if (adxf == 0) {
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
    adxf_SetCmdHstry(4, 1, adxf, nsct, buf);
    return temp_v0_2;
}

Sint32 ADXF_ReadNw(ADXF adxf, Sint32 nsct, void *buf) {
    if ((Sint32)buf & 0x3F) {
        ADXERR_CallErrFunc1("E0120401:'buf' isn't 64byte alignment.(ADXF_ReadNw)");
        return ADXF_ERR_PRM;
    }

    return ADXF_ReadNw32(adxf, nsct, buf);
}

Sint32 ADXF_Stop(ADXF adxf) {
    ADXSTM stm;

    adxf_SetCmdHstry(5, 0, adxf, -1, -1);

    if (adxf == NULL) {
        ADXERR_CallErrFunc1("E9040822:'adxf' is NULL.(ADXF_Stop)");
        return ADXF_ERR_PRM;
    }

    switch (adxf->stat) {
    case 3:
        adxf->stat = 1;
        /* fallthrough */

    case 1:
        break;

    default:
        stm = adxf->stm;

        if (stm == NULL) {
            ADXERR_CallErrFunc1("E9040823:'adxf->stm' is NULL.(ADXF_Stop)\0\0\0\0");
            return -1;
        }

        ADXSTM_Stop(stm);
        ADXCRS_Lock();
        adxf->rdsct = ADXSTM_Tell(adxf->stm) - adxf->skpos;
        adxf_CloseSjStm(adxf);
        adxf->stat = 1;
        ADXCRS_Unlock();
        adxf_SetCmdHstry(5, 1, adxf, -1, -1);
        break;
    }

    return adxf->skpos;
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A6C0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A6E8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_StopNw);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_ExecOne);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_ExecServer);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A718);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A740);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_Seek);

s32 ADXF_Tell(ADXF adxf) {
    if (adxf == NULL) {
        ADXERR_CallErrFunc1("E9040827:'adxf' is NULL.(ADXF_Tell)");
        return ADXF_ERR_PRM;
    }

    return adxf->skpos;
}

s32 ADXF_GetFsizeSct(ADXF adxf) {
    if (adxf == NULL) {
        ADXERR_CallErrFunc1("E9040828:'adxf' is NULL.(ADXF_GetFsizeSct)\0\0");
        return -3;
    }

    if (adxf->fnsct > 0xFFFFE) {
        ADXSTM_OpenCvfs(adxf->stm);

        if (ADXSTM_GetStat(adxf->stm) == 4) {
            return -5;
        }
    }

    return adxf->fnsct = ADXSTM_GetFileSct(adxf->stm);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetFsizeByte);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A7C0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetNumReqSct);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A7F0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetNumReadSct);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A820);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetStat);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A848);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A870);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", adxf_ChkPrmGfr);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetFnameRange);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetFnameRangeEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetFnameFromPt);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_SetOcbiSw);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", D_0055A898);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_SetReqRdSct);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetStatRead);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_fs", ADXF_GetFileSize);
