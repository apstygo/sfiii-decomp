#include "common.h"
#include <cri/private/libadxe/structs.h>

#include <cri/private/libadxe/lsc.h>
#include <cri/private/libadxe/lsc_crs.h>
#include <cri/private/libadxe/lsc_err.h>
#include <cri/private/libadxe/lsc_ini.h>

#include <cri/ee/cri_xpt.h>
#include <cri/sj.h>

#include <string.h>

LSC lsc_Alloc() {
    LSC lsc = NULL;
    Sint32 i;

    for (i = 0; i < LSC_MAX_OBJ; i++) {
        if (!lsc_obj[i].used) {
            lsc = &lsc_obj[i];
            break;
        }
    }

    return lsc;
}

LSC LSC_Create(SJ sj) {
    LSC lsc;
    Sint32 lock;
    Sint32 i;

    if (sj == NULL) {
        LSC_CallErrFunc("E0001: Illigal parameter=sj (LSC_Create)\n");
        return NULL;
    }

    LSC_LockCrs(&lock);
    lsc = lsc_Alloc();

    if (lsc == NULL) {
        LSC_CallErrFunc("E0002: Not enough instance (LSC_Create)\n\0\0\0\0");
    } else {
        lsc->unk1 = 0;
        lsc->sj = sj;

        lsc->unk18 = SJ_GetNumData(sj, 0) + SJ_GetNumData(sj, 1);
        lsc->unk14 = (lsc->unk18 * 8) / 10;

        for (i = 0; i < 16; i++) {
            lsc->unk38[i].unk18 = 0;
        }

        lsc->used = 1;
    }

    LSC_UnlockCrs(&lock);
    return lsc;
}

void LSC_Destroy(LSC lsc) {
    if (lsc != NULL) {
        LSC_Stop(lsc);
        lsc->used = 0;
        memset(lsc, 0, sizeof(LSC_OBJ));
    }
}

// Used all over the place
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc", D_0055D978);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_SetStmHndl);
#else
void LSC_SetStmHndl(LSC lsc, ADXSTM) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_EntryFname);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc", D_0055D9A0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_EntryFileRange);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_ResetEntry);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_Start);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_Stop);
#else
void LSC_Stop(LSC lsc) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_Pause);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_ExecServer);
#else
void LSC_ExecServer() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_GetStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_GetNumStm);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc", D_0055D9C8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_GetStmId);

// Also used in LSC_GetStmStat and LSC_GetStmRdSct
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc", D_0055D9E8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_GetStmFname);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_GetStmStat);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_GetStmRdSct);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/lsc", D_0055DA10);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_SetFlowLimit);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_GetFlowLimit);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_EntryChgStatFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_CallStatFunc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/lsc", LSC_SetLpFlg);
