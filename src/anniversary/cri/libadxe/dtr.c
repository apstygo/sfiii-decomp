#include "common.h"
#include <cri/private/libadxe/dtr.h>
#include <cri/private/libadxe/structs.h>

#include <cri/cri_xpts.h>
#include <cri/sj.h>
#include <eekernel.h>
#include <sif.h>

#include <string.h>

#define DTR_MAX_OBJ 32

// data
Char8 *dtr_build = "\nDTR Ver.1.03 Build:Sep 18 2003 10:00:10\n\0\0\0\0";
Sint32 dtr_init_cnt = 0;
DTR_OBJ dtr_obj[DTR_MAX_OBJ] = { 0 };

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dtr", D_0055CE00);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dtr", D_0055CE20);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dtr", D_0055CE48);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dtr", D_0055CE78);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dtr", D_0055CEA0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dtr", D_0055CEC8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dtr", DTR_ExecHndl);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dtr", DTR_GetStat);
#else
Sint32 DTR_GetStat(DTR dtr) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dtr", DTR_ExecServer);
#else
void DTR_ExecServer() {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dtr", D_0055CEF0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/dtr", D_0055CF08);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dtr", DTR_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dtr", DTR_Finish);

DTR DTR_Create(SJ sj, Sint32 arg1) {
    DTR dtr;
    Sint32 i;

    SJCRS_Lock();

    for (i = 0; i < DTR_MAX_OBJ; i++) {
        dtr = &dtr_obj[i];

        if (dtr->unk0 == 0) {
            break;
        }
    }

    if (i == DTR_MAX_OBJ) {
        scePrintf("i:%d DTR_MAX_OBJ:%d\n", i, DTR_MAX_OBJ);
        dtr = NULL;
    } else {
        memset(dtr, 0, sizeof(DTR_OBJ));
        dtr->unk1 = 0;
        dtr->unk38 = 0x40;
        dtr->unk4 = sj;
        dtr->unk8 = arg1;
        dtr->unk2 = 0;
        dtr->unk30 = 1;
        dtr->unk0 = 1;
        dtr->unk34 = 0;
    }

    SJCRS_Unlock();
    return dtr;
}

void DTR_Destroy(DTR dtr) {
    SJCRS_Lock();
    dtr->unk0 = 0;
    SJCRS_Unlock();
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/dtr", DTR_Start);
#else
void DTR_Start(DTR dtr) {
    not_implemented(__func__);
}
#endif

void DTR_Stop(DTR dtr) {
    dtr->unk1 = 0;

    if (dtr->unk2 != 1) {
        return;
    }

    while (sceSifDmaStat(dtr->unk2C) >= 0) {
        // Do nothing
    }

    SJ_PutChunk(dtr->unk4, 0, &dtr->unkC);
    dtr->unkC.data = NULL;
    dtr->unkC.len = 0;
    SJ_PutChunk(dtr->unk8, 1, &dtr->unk14);
    dtr->unk14.data = NULL;
    dtr->unk2 = 0;
    dtr->unk14.len = 0;
    dtr->unk3C += dtr->unkC.len;
}
