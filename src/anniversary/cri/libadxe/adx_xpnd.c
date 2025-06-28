#include "common.h"
#include <cri/private/libadxe/adx_dcd.h>
#include <cri/private/libadxe/adx_dcd5.h>
#include <cri/private/libadxe/adx_xpnd.h>

#include <string.h>

#define ADXPD_MAX_OBJ 16

void ADX_GetCoefficient(Sint16 *, Sint32, Sint16 *, Sint16 *);
Sint32 adxpd_internal_error = 0;
ADXPD_OBJ adxpd_obj[ADXPD_MAX_OBJ] = { 0 };

void ADXPD_Init(void) {
    memset(&adxpd_obj, 0, sizeof(adxpd_obj));
}

void ADXPD_Finish() {
    memset(&adxpd_obj, 0, sizeof(adxpd_obj));
}

ADXPD ADXPD_Create() {
    ADXPD adxpd;
    ADXPD chk_adxpd;
    Sint32 i;

    chk_adxpd = &adxpd_obj;

    for (i = 0; i < ADXPD_MAX_OBJ; i++, chk_adxpd++) {
        if (chk_adxpd->unk0 == 0) {
            break;
        }
    }

    if (i == ADXPD_MAX_OBJ) {
        return NULL;
    }

    adxpd = &adxpd_obj[i];
    memset(adxpd, 0, sizeof(ADXPD_OBJ));
    adxpd->unk0 = 1;
    adxpd->unk4 = i;
    adxpd->mode = 0;
    adxpd->Stat = 0;
    ADX_GetCoefficient(0x1F4, 0xAC44, &adxpd->unk28[4], &adxpd->unk28[5]);
    memset(adxpd->unk28, 0, 8);

    return adxpd;
}

void ADXPD_SetCoef(ADXPD adxpd, Sint32 arg1, Sint16 *arg2) {
    ADX_GetCoefficient(arg2, arg1, &adxpd->unk28[4], &adxpd->unk28[5]);
}

void ADXPD_SetDly(ADXPD adxpd, Sint16 *arg1, Sint16 *arg2) {
    adxpd->unk28[0] = arg1[0];
    adxpd->unk28[1] = arg2[0];
    adxpd->unk28[2] = arg1[1];
    adxpd->unk28[3] = arg2[1];
}

void ADXPD_GetDly(ADXPD adxpd, Sint16 *arg1, Sint16 *arg2) {
    arg1[0] = adxpd->unk28[0];
    arg2[0] = adxpd->unk28[1];
    arg1[1] = adxpd->unk28[2];
    arg2[1] = adxpd->unk28[3];
}

void ADXPD_SetExtPrm(ADXPD adxpd, Sint16 arg1, Sint16 arg2, Sint16 arg3) {
    adxpd->unk28[6] = arg1;
    adxpd->unk28[7] = arg2;
    adxpd->unk28[8] = arg3;
}

void ADXPD_GetExtPrm(ADXPD adxpd, Sint16 *arg1, Sint16 *arg2, Sint16 *arg3) {
    *arg1 = adxpd->unk28[6];
    *arg2 = adxpd->unk28[7];
    *arg3 = adxpd->unk28[8];
}

void ADXPD_Destroy(ADXPD adxpd) {
    if (adxpd != NULL) {
        adxpd->unk0 = 0;
        memset(adxpd, 0, sizeof(ADXPD_OBJ));
    }
}

void ADXPD_SetMode(ADXPD adxpd, Sint32 mode) {
    adxpd->mode = mode;
}

Sint32 ADXPD_GetStat(ADXPD adxpd) {
    return adxpd->Stat;
}

Sint32 ADXPD_EntryMono(ADXPD adxpd, Sint32 arg1, Sint32 arg2, Sint32 arg3, Sint32 arg4) {
    if (adxpd->Stat == 0) {
        adxpd->unk18 = arg1;
        adxpd->unk1C = arg2;
        adxpd->unk14 = 1;
        adxpd->unk20 = arg3;
        adxpd->unk24 = arg4;
        return 1;
    }

    return 0;
}

Sint32 ADXPD_EntrySte(ADXPD adxpd, Sint32 arg1, Sint32 arg2, Sint32 arg3, Sint32 arg4) {
    if (adxpd->Stat == 0) {
        adxpd->unk18 = arg1;
        adxpd->unk1C = arg2;
        adxpd->unk14 = 2;
        adxpd->unk20 = arg3;
        adxpd->unk24 = arg4;
        return 1;
    }

    return 0;
}

Sint32 ADXPD_EntryPl2(ADXPD adxpd, Sint32 arg1, Sint32 arg2, Sint32 arg3, Sint32 arg4) {
    if (adxpd->Stat == 0) {
        adxpd->unk18 = arg1;
        adxpd->unk1C = arg2;
        adxpd->unk14 = 1;
        adxpd->unk20 = arg3;
        adxpd->unk24 = arg4;
        return 1;
    }

    return 0;
}

void ADXPD_Start(ADXPD adxpd) {
    if (adxpd->Stat == 0) {
        adxpd->NumBlk = 0;
        adxpd->Stat = 1;
    }
}

void ADXPD_Stop(ADXPD adxpd) {
    adxpd->Stat = 0;
    memset(&adxpd->unk28, 0, 8);
}

void ADXPD_Reset(ADXPD adxpd) {
    if (adxpd->Stat == 3) {
        adxpd->Stat = 0;
    }
}

Sint32 ADXPD_GetNumBlk(ADXPD adxpd) {
    return adxpd->NumBlk;
}

void adxpd_error() {
    adxpd_internal_error = 1;
}

void ADXPD_ExecHndl(ADXPD adxpd) {

    if (adxpd->Stat == 1) {
        adxpd->Stat = 2;
    }

    if (adxpd->Stat != 2) {
        return;
    }

    if (adxpd->unk14 == 1) {
        adxpd->NumBlk = ADX_DecodeMono4(adxpd->unk18,
                                        adxpd->unk1C,
                                        adxpd->unk20,
                                        &adxpd->unk28[0],
                                        adxpd->unk28[4],
                                        adxpd->unk28[5],
                                        &adxpd->unk28[6],
                                        adxpd->unk28[7],
                                        adxpd->unk28[8]);
    } else {
        adxpd->NumBlk = ADX_DecodeSte4(adxpd->unk18,
                                       adxpd->unk1C,
                                       adxpd->unk20,
                                       &adxpd->unk28[0],
                                       adxpd->unk24,
                                       &adxpd->unk28[2],
                                       adxpd->unk28[4],
                                       adxpd->unk28[5],
                                       &adxpd->unk28[6],
                                       adxpd->unk28[7],
                                       adxpd->unk28[8]);

        if ((adxpd->NumBlk % 2) == 1) {
            adxpd_error();
        }
    }

    adxpd->Stat = 3;
}

void ADXPD_ExecServer() {
    ADXPD adxpd = &adxpd_obj;
    Sint32 i = 0xF;

    do {

        if (adxpd->unk0 == 1) {
            ADXPD_ExecHndl(adxpd);
        }

        i -= 1;
        adxpd++;
    } while (i >= 0);
}
