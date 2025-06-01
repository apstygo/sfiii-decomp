#include "common.h"
#include <cri/private/libadxe/cri_srd.h>
#include <cri/private/libadxe/dvci_sub.h>
#include <cri/private/libadxe/structs.h>
#include <cri/private/libadxe/svm.h>

#include <cri/ee/cri_xpt.h>

#include <eekernel.h>
#include <libcdvd.h>

#include <string.h>

// data
extern Char8 *volatile dvg_ci_build;
extern Sint32 dvg_ci_dvd_layer;
extern Sint32 dvci_execserver_enter_flg;
extern CVFSDevice dvg_ci_vtbl;
extern DVG_CI_OBJ dvg_ci_obj[DVG_CI_MAX_OBJ];

// forward decls
void dvCiSetRootDir(Char8 *);
void dvCiExecHndl(DVG_CI dvg_ci);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci", D_0055D030);

CVFSDevice *dvCiGetInterface() {
    dvg_ci_build;
    dvCiSetRootDir(NULL);
    return &dvg_ci_vtbl;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvci_call_errfn);

Sint32 dvCiCdSearchFile(sceCdlFILE *fp, const Char8 *fname) {
    Sint32 err;

    SRD_SetHistory(0x8000);
    err = sceCdLayerSearchFile(fp, fname, dvg_ci_dvd_layer);
    SRD_SetHistory(0x8001);
    return err;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvci_is_exec_hn);

void dvCiExecHndl(DVG_CI dvg_ci) {
    if (dvg_ci->srd == NULL) {
        return;
    }

    SVM_LockVar();

    switch (SRD_GetStat(dvg_ci->srd)) {
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        // Do nothing
        break;

    case 9:
        dvg_ci->unk2 = 3;
        SRD_Destroy(dvg_ci->srd);
        dvg_ci->srd = NULL;
        break;

    case 3:
        dvg_ci->unk14 = dvg_ci->unk10;
        dvg_ci->unk2 = 1;
        dvg_ci->unkC += dvg_ci->unk10;
        SRD_Destroy(dvg_ci->srd);
        dvg_ci->srd = NULL;
        break;

    case 0:
        dvg_ci->unk2 = 0;
        SRD_Destroy(dvg_ci->srd);
        dvg_ci->srd = NULL;
        break;
    }

    SVM_UnlockVar();
}

void dvCiExecServer() {
    DVG_CI dvg_ci;
    Sint32 i;

    if (SVM_TestAndSet(&dvci_execserver_enter_flg) == 0) {
        return;
    }

    for (i = 0; i < DVG_CI_MAX_OBJ; i++) {
        dvg_ci = &dvg_ci_obj[i];

        if (dvg_ci->used == 1) {
            dvCiExecHndl(dvg_ci);
        }
    }

    dvci_execserver_enter_flg = 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiEntryErrFunc);

void dvci_to_large_to_yen(Char8 *path) {
    Uint32 len = strlen(path);
    Sint32 i;

    for (i = 0; i < len; i++) {
        if (path[i] == '/') {
            path[i] = '\\';
        }

        if (path[i] >= 'a' && path[i] <= 'z') {
            path[i] -= 'a' - 'A';
        }
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiIsExistFile);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci", D_0055D098);
// Also used in dvci_getfilesize32
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci", D_0055D0C8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci", D_0055D0F0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiGetFileSize);

DVG_CI dvci_alloc() {
    DVG_CI dvg_ci = NULL;
    Sint32 i;

    for (i = 0; i < DVG_CI_MAX_OBJ; i++) {
        if (dvg_ci_obj[i].used == 0) {
            dvg_ci = &dvg_ci_obj[i];
        }
    }

    return dvg_ci;
}

void dvci_free(DVG_CI dvg_ci) {
    memset(dvg_ci, 0, sizeof(DVG_CI_OBJ));
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci", D_0055D120);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci", D_0055D148);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci", D_0055D170);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci", D_0055D1A0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci", D_0055D1C8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiOpen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiClose);

// Also used in dvCiTell, dvCiReqRd, dvCiStopTr, dvCiGetStat and dvCiGetNumTr
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci", D_0055D1F8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiSeek);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiTell);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci", D_0055D210);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci", D_0055D230);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiReqRd);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dvci", D_0055D258);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiStopTr);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiGetStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiGetSctLen);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiGetNumTr);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiSetOutputDebugLevel);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiGetOutputDebugLevel);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiSetDvdLayer);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiGetDvdLayer);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvci_getfilesize32);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvci_getnumtr_upper);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvci_getnumtr_lower);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvci_filesize_upper);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvci_filesize_lower);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dvci", dvCiOptFn1);
