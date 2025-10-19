#include "common.h"
#include <cri/private/libadxe/adx_bahx.h>
#include <cri/private/libadxe/adx_baif.h>
#include <cri/private/libadxe/adx_bau.h>
#include <cri/private/libadxe/adx_bsc.h>
#include <cri/private/libadxe/adx_bsps.h>
#include <cri/private/libadxe/adx_bwav.h>
#include <cri/private/libadxe/adx_dcd.h>
#include <cri/private/libadxe/adx_errs.h>
#include <cri/private/libadxe/adx_xpnd.h>
#include <cri/private/libadxe/structs.h>

#include <stdio.h>
#include <string.h>

#define ADXB_MAX_OBJ 16
#define MIN(a, b) ((a) < (b) ? (a) : (b))

Char8* skg_build = "\nSKG/PS2EE Ver.0.64 Build:Sep 18 2003 09:59:56\n";

#include <cri/private/libadxe/adx_bsc_tbl.h>

static Sint32 skg_init_count = 0;
static void (*skg_err_func)(s32, s32) = 0;
static Sint32 skg_err_obj = 0;
void (*ahxsetextfunc)(Sint32, Sint16*) = NULL;
Sint32 pl2encodefunc = 0;
void (*pl2resetfunc)() = NULL;
static Uint16 adxb_def_k0 = 0;
Uint16 adxb_def_km = 0;
static Uint16 adxb_def_ka = 0;
ADXB_OBJ adxb_obj[ADXB_MAX_OBJ] = { 0 };

// forward decls
void ADXB_Destroy(ADXB adxb);
static Sint32 adxb_get_key(ADXB adxb, Uint8 arg1, Uint8 arg2, Sint32 arg3, Uint16* arg4, Uint16* arg5, Uint16* arg6);

static Sint32 SKG_NopFunc(void) {
    return 0;
}

static Sint32 SKG_EntryErrFunc(void (*arg0)(Sint32, Sint32), Sint32 arg1) {
    skg_err_func = arg0;
    skg_err_obj = arg1;
    return 0;
}

static Sint32 SKG_CallErrFunc(Sint32 arg0) {
    if (skg_err_func != NULL) {
        skg_err_func(skg_err_obj, arg0);
    }
    return 0;
}

static Sint32 SKG_Init() {
    skg_init_count += 1;
    return 0;
}

static Sint32 SKG_Finish(void) {
    skg_init_count -= 1;
    return 0;
}

static Sint32 SKG_GenerateKey(Sint8* arg0, Sint32 arg1, Uint16* arg2, Uint16* arg3, Uint16* arg4) {
    s16 var_a0;
    s16 var_t0;
    s16 var_t2;
    int i;

    if (skg_init_count == 0) {
        SKG_Init();
    }

    *arg2 = 0;
    *arg3 = 0;
    *arg4 = 0;

    if ((arg0 == 0) && (arg1 <= 0)) {
        return 0;
    }

    var_t2 = skg_prim_tbl[0x100];
    for (i = 0; i < arg1; i++) {
        var_t2 = skg_prim_tbl[(var_t2 * skg_prim_tbl[arg0[i] + 0x80]) % 0x400];
    }

    var_t0 = skg_prim_tbl[0x200];
    for (i = 0; i < arg1; i++) {
        var_t0 = skg_prim_tbl[(var_t0 * skg_prim_tbl[arg0[i] + 0x80]) % 0x400];
    }

    var_a0 = skg_prim_tbl[0x300];
    for (i = 0; i < arg1; i++) {
        var_a0 = skg_prim_tbl[(var_a0 * skg_prim_tbl[arg0[i] + 0x80]) % 0x400];
    }

    *arg2 = var_t2;
    *arg3 = var_t0;
    *arg4 = var_a0;
    return 0;
}

static Sint32 SKG_GetDefKey(Uint16* arg0, Uint16* arg1, Uint16* arg2) {
    if (skg_init_count == 0) {
        SKG_Init();
    }
    SKG_GenerateKey("CRI-MW", 6, arg0, arg1, arg2);
    return 0;
}

static Sint32 SKG_GetNextKey(Uint16* arg0, Uint16* arg1, Uint16* arg2) {
    *arg0 = *arg2 + (*arg0 * *arg1);
    return 0;
}

void ADXB_Init() {
    ADXPD_Init();
    SKG_Init();
    memset(&adxb_obj, 0, sizeof(adxb_obj));
}

void ADXB_Finish() {
    ADXPD_Finish();
    SKG_Finish();
    memset(&adxb_obj, 0, sizeof(adxb_obj));
}

void* adxb_DefGetWr(void* object, Sint32* arg1, Sint32* arg2, Sint32* arg3) {
    ADXB adxb = (ADXB)object;
    void* ret = adxb->unk3C;
    int temp;

    temp = adxb->unk8C;

    *arg1 = adxb->unk8C;
    *arg2 = adxb->unk40 - adxb->unk8C;
    *arg3 = adxb->total_samples - adxb->unk88;

    // fake
    if (adxb->unk8C) {
        u8 x = -x;
    }

    if (temp) {
        u8 x = -x;
    }

    return ret;
}

void adxb_DefAddWr(void* object, Sint32 arg1, Sint32 arg2) {
    ADXB adxb = (ADXB)object;

    adxb->unk8C += arg2;
    adxb->unk88 += arg2;
}

ADXB ADXB_Create(Sint32 arg0, void* arg1, Sint32 arg2, Sint32 arg3) {
    ADXB adxb;
    ADXB chk_adxb;
    ADXPD adxpd;
    Sint32 i;

    chk_adxb = &adxb_obj[0];

    for (i = 0; i < ADXB_MAX_OBJ; i++, chk_adxb++) {
        if (chk_adxb->unk0 == 0) {
            break;
        }
    }

    if (i == ADXB_MAX_OBJ) {
        return NULL;
    }

    adxb = &adxb_obj[i];
    memset(adxb, 0, sizeof(ADXB_OBJ));
    adxb->unk0 = 1;
    adxpd = ADXPD_Create();
    adxb->adxpd = adxpd;

    if (adxpd == NULL) {
        ADXB_Destroy(adxb);
        return NULL;
    }

    adxb->unk38 = arg0;
    adxb->unk3C = arg1;
    adxb->unk40 = arg2;
    adxb->unk44 = arg3;
    adxb->get_wr = adxb_DefGetWr;
    adxb->add_wr = adxb_DefAddWr;
    adxb->object = adxb;
    adxb->unk84 = adxb;
    adxb->unkC8 = 0;
    adxb->unkDC = 0;
    adxb->unkDE[0] = -0x80; // pan auto
    adxb->unkDE[1] = -0x80;
    memset(&adxb->unkCC, 0, sizeof(ADX_UNK));
    return adxb;
}

void ADXB_Destroy(ADXB adxb) {
    ADXPD adxpd;

    if (adxb != NULL) {
        adxpd = adxb->adxpd;
        adxb->adxpd = 0;
        ADXPD_Destroy(adxpd);
        memset(adxb, 0, sizeof(ADXB_OBJ));
        adxb->unk0 = 0;
    }
}

Sint32 ADXB_DecodeHeaderAdx(ADXB adxb, void* header, Sint32 len) {
    Sint16 sp10[2];
    Sint16 sp20[2];
    Sint16 sp30[4];
    Sint16 audio_offset;
    Sint8 version;
    Sint8 flags;
    Sint16 sp44;
    Sint16 sp46;
    Sint16 sp48;

    adxb->unk2 = 1;

    if (ADX_DecodeInfo(header,
                       len,
                       &audio_offset,
                       &adxb->encoding_type,
                       &adxb->sample_bitdepth,
                       &adxb->block_size,
                       &adxb->channel_count,
                       &adxb->sample_rate,
                       &adxb->total_samples,
                       &adxb->samples_per_block) < 0) {
        return 0;
    }

    if (adxb->encoding_type >= 5) {
        if (adxb->unkB0 == 0) {
            ADXERR_CallErrFunc2("E1060101 ADXB_DecodeHeaderAdx: ", "can't play AHX data by this handle");
            return -1;
        }

        adxb->sample_bitdepth = 8;
        adxb->block_size = adxb->channel_count * 0xC0;
        adxb->samples_per_block = 0x60;
        adxb->format = 0xA;
        adxb->unk1C = 0;
        adxb->unk24 = 0;
        adxb->unk26 = 0;
        adxb->unk20 = 0;
        adxb->unk28 = 0;
        adxb->unk2C = 0;
        adxb->unk30 = 0;
        adxb->unk34 = 0;
        adxb->unk88 = 0;

        if (ADX_DecodeInfoExVer(header, len, &version, &flags) < 0) {
            return 0;
        }

        sp30[0] = 0;

        if (adxb_get_key(adxb, version, flags, adxb->total_samples, &sp30[1], &sp30[2], &sp30[3]) < 0) {
            return -1;
        }

        if (ahxsetextfunc != NULL) {
            ahxsetextfunc(adxb->unkB0, &sp30);
        }
    } else {
        if (ADX_DecodeInfoExVer(header, len, &version, &flags) < 0) {
            return 0;
        }

        if (adxb_get_key(adxb, version, flags, adxb->total_samples, &sp44, &sp46, &sp48) < 0) {
            return -1;
        }

        ADXPD_SetExtPrm(adxb->adxpd, sp44, sp46, sp48);

        if (ADX_DecodeInfoExADPCM2(header, len, &adxb->unk1C) < 0) {
            return 0;
        }

        if (ADX_DecodeInfoExIdly(header, len, &sp10, &sp20) < 0) {
            return 0;
        }

        ADXPD_SetCoef(adxb->adxpd, adxb->sample_rate, adxb->unk1C);
        ADXPD_SetDly(adxb->adxpd, &sp10, &sp20);
        ADX_DecodeInfoExLoop(header,
                             len,
                             &adxb->unk20,
                             &adxb->unk24,
                             &adxb->unk26,
                             &adxb->unk28,
                             &adxb->unk2C,
                             &adxb->unk30,
                             &adxb->unk34);
        ADX_DecodeInfoAinf(header, len, &adxb->unkC8, &adxb->unkCC, &adxb->unkDC, &adxb->unkDE);
        adxb->format = 0;
    }

    adxb->unk48.unk8 = adxb->channel_count;
    adxb->unk48.unkC = adxb->block_size;
    adxb->unk48.unk10 = adxb->samples_per_block;
    adxb->unk48.unk14 = adxb->unk3C;
    adxb->unk48.unk18 = adxb->unk40;
    adxb->unk48.unk1C = adxb->unk44;
    adxb->unk8C = 0;

    return audio_offset;
}

Sint32 ADXB_DecodeHeader(ADXB adxb, void* header, Sint32 len) {
    Uint32 magic = *(Uint16*)header;

    if ((Uint16)((magic >> 8) | (magic << 8)) == 0x8000) {
        return ADXB_DecodeHeaderAdx(adxb, header, len);
    }

    if (ADXB_CheckSpsd(header) != 0) {
        return ADXB_DecodeHeaderSpsd(adxb, header, len);
    }

    if (ADXB_CheckWav(header) != 0) {
        return ADXB_DecodeHeaderWav(adxb, header, len);
    }

    if (ADXB_CheckAiff(header) != 0) {
        return ADXB_DecodeHeaderAiff(adxb, header, len);
    }

    if (ADXB_CheckAu(header) != 0) {
        return ADXB_DecodeHeaderAu(adxb, header, len);
    }

    if (ADXB_CheckAc3(header) != 0) {
        return ADXB_DecodeHeaderAc3(adxb, header, len);
    }

    return -1;
}

void ADXB_EntryGetWrFunc(ADXB adxb, void* (*get_wr)(void*, ptrdiff_t*, Sint32*, Sint32*), void* object) {
    adxb->get_wr = get_wr;
    adxb->object = object;
}

void ADXB_EntryAddWrFunc(ADXB adxb, void* arg1, Sint32 arg2) {
    adxb->add_wr = arg1;
    adxb->unk84 = arg2;
}

void* ADXB_GetPcmBuf(ADXB adxb) {
    return adxb->unk3C;
}

Sint32 ADXB_GetFormat(ADXB adxb) {
    return adxb->format;
}

Sint32 ADXB_GetSfreq(ADXB adxb) {
    return adxb->sample_rate;
}

Sint32 ADXB_GetNumChan(ADXB adxb) {
    if (adxb->channel_count == 1 && adxb->unkE4 != 0) {
        return 2;
    }

    return adxb->channel_count;
}

Sint8 ADXB_GetFmtBps(ADXB adxb) {
    return adxb->sample_bitdepth;
}

Sint32 ADXB_GetOutBps(ADXB adxb) {
    Sint16 format;
    Sint16 temp_v1;

    format = adxb->format;

    if (format == 0) {
        return 16;
    }

    if (format == 2) {
        temp_v1 = adxb->unk9A;

        if (temp_v1 == format) {
            return 4;
        }

        return (temp_v1 == 1) ? 8 : 16;
    }

    if (format == 1) {
        temp_v1 = adxb->unk9A;
        return (temp_v1 == 2) ? 4 : 16;
    }

    return 16;
}

Sint32 ADXB_GetBlkSmpl(ADXB adxb) {
    return adxb->samples_per_block;
}

Sint8 ADXB_GetBlkLen(ADXB adxb) {
    return adxb->block_size;
}

Sint32 ADXB_GetTotalNumSmpl(ADXB adxb) {
    return adxb->total_samples;
}

Sint16 ADXB_GetCof(ADXB adxb) {
    return adxb->unk1C;
}

Sint32 ADXB_GetLpInsNsmpl(ADXB adxb) {
    return adxb->unk20;
}

Sint32 ADXB_GetNumLoop(ADXB adxb) {
    return adxb->unk24;
}

Sint32 ADXB_GetLpStartPos(ADXB adxb) {
    return adxb->unk28;
}

Sint32 ADXB_GetLpStartOfst(ADXB adxb) {
    Sint32 var_v0;

    var_v0 = 0;
    if (adxb != NULL) {
        var_v0 = adxb->unk2C;
    }

    return var_v0;
}

Sint32 ADXB_GetLpEndPos(ADXB adxb) {
    return adxb->unk30;
}

Sint32 ADXB_GetLpEndOfst(ADXB adxb) {
    return adxb->unk34;
}

Sint32 ADXB_GetAinfLen(ADXB adxb) {
    return adxb->unkC8;
}

Sint16 ADXB_GetDefOutVol(ADXB adxb) {
    return adxb->unkDC;
}

Sint16 ADXB_GetDefPan(ADXB adxb, Sint32 arg1) {
    return adxb->unkDE[arg1];
}

ADX_UNK* ADXB_GetDataId(ADXB adxb) {
    return &adxb->unkCC;
}

void ADXB_TakeSnapshot(ADXB adxb) {
    ADXPD_GetDly(adxb->adxpd, &adxb->unkA8, &adxb->unkAC);
    ADXPD_GetExtPrm(adxb->adxpd, &adxb->unkA2, &adxb->unkA4, &adxb->unkA6);
}

void ADXB_RestoreSnapshot(ADXB adxb) {
    ADXPD_SetDly(adxb->adxpd, &adxb->unkA8, &adxb->unkAC);
    ADXPD_SetExtPrm(adxb->adxpd, adxb->unkA2, adxb->unkA4, adxb->unkA6);
}

void ADXB_SetExtString(ADXB adxb, Sint8* arg1) {
    u16 sp;
    u16 sp2;
    u16 sp4;

    SKG_GenerateKey(arg1, strlen(arg1), &sp, &sp2, &sp4);
    adxb->unk9C = sp;
    adxb->unk9E = sp2;
    adxb->unkA0 = sp4;
}

void ADXB_SetDefExtString(Sint8* arg0) {
    SKG_GenerateKey(arg0, strlen(arg0), &adxb_def_k0, &adxb_def_km, &adxb_def_ka);
}

static Sint32 adxb_get_key(ADXB adxb, Uint8 arg1, Uint8 arg2, Sint32 arg3, Uint16* arg4, Uint16* arg5, Uint16* arg6) {
    Char8 sp[9];

    if (arg1 >= 4) {
        if (arg2 >= 0x10) {
            sprintf(sp, "%08X", arg3);
            SKG_GenerateKey(sp, 8, arg4, arg5, arg6);
        } else if (arg2 >= 8) {
            if ((adxb->unk9C == 0) && (adxb->unk9E == 0) && (adxb->unkA0 == 0)) {
                adxb->unk9C = adxb_def_k0;
                adxb->unk9E = adxb_def_km;
                adxb->unkA0 = adxb_def_ka;
            }

            *arg4 = adxb->unk9C;
            *arg5 = adxb->unk9E;
            *arg6 = adxb->unkA0;
        } else {
            *arg4 = 0;
            *arg5 = 0;
            *arg6 = 0;
        }
    } else {
        *arg4 = 0;
        *arg5 = 0;
        *arg6 = 0;
    }

    return 0;
}

Sint32 ADXB_GetStat(ADXB adxb) {
    return adxb->stat;
}

void ADXB_EntryData(ADXB adxb, Sint32 arg1, Sint32 arg2) {
    if (adxb->format == 0) {
        adxb->unk48.unk0 = arg1;
        adxb->unk48.unk4 = arg2 / adxb->block_size;
        adxb->unk74 = 0;
        adxb->dec_num_sample = 0;
        adxb->dec_data_len = 0;
    } else {
        adxb->unk48.unk0 = arg1;
        adxb->unk48.unk4 = arg2 / ((adxb->sample_bitdepth / 8) * adxb->channel_count);
        adxb->unk74 = 0;
        adxb->dec_num_sample = 0;
        adxb->dec_data_len = 0;
    }
}

void ADXB_Start(ADXB adxb) {
    if (adxb->stat == 0) {
        adxb->stat = 1;
    }
}

void ADXB_Stop(ADXB adxb) {
    if (adxb->unkE4 != 0) {
        pl2resetfunc();
    }

    ADXPD_Stop(adxb->adxpd);
    adxb->stat = 0;
}

void ADXB_Reset(ADXB adxb) {
    if (adxb->stat == 3) {
        ADXPD_Reset(adxb->adxpd);
        adxb->unk8C = 0;
        adxb->stat = 0;
    }
}

Sint32 ADXB_GetDecDtLen(ADXB adxb) {
    return adxb->dec_data_len;
}

Sint32 ADXB_GetDecNumSmpl(ADXB adxb) {
    return adxb->dec_num_sample;
}

ADXPD ADXB_GetAdxpd(ADXB adxb) {
    return adxb->adxpd;
}

void ADXB_EvokeExpandMono(ADXB adxb, Sint32 arg1) {
    ADXB_UNK* unk = &adxb->unk48;
    ADXPD pd = adxb->adxpd;
    int arg = unk->unk14 + (unk->unk20 * 2);

    ADXPD_EntryMono(pd, unk->unk0, arg1, arg, 0);
    ADXPD_Start(pd);
}

void ADXB_EvokeExpandSte(ADXB adxb, Sint32 arg1) {
    ADXPD adxpd = adxb->adxpd;
    ADXB_UNK* unk = &adxb->unk48;
    Sint32 a3;
    Sint32 t0;

    a3 = unk->unk14 + (unk->unk20 * 2);
    t0 = a3 + (unk->unk1C * 2);

    ADXPD_EntrySte(adxpd, unk->unk0, arg1 * 2, a3, t0);
    ADXPD_Start(adxpd);
}

void ADXB_EvokeExpandPl2(ADXB adxb, Sint32 arg1) {
    ADXB_UNK* unk = &adxb->unk48;
    ADXPD pd = adxb->adxpd;
    int arg = unk->unk14 + (unk->unk20 * 2);

    ADXPD_EntryPl2(pd, unk->unk0, arg1, arg, arg + (unk->unk1C * 2));
    ADXPD_Start(pd);
}

void ADXB_EvokeDecode(ADXB adxb) {
    ADXB_UNK* unk = &adxb->unk48;
    Sint32 temp_a1_2;
    Sint32 temp_lo;
    Sint32 temp_lo_2;
    Sint32 temp_lo_3;
    Sint32 temp_t0;
    Sint32 temp_t2;
    Sint32 temp_t7;
    Sint32 var_t3;
    Sint32 var_t1;
    Sint32 var_t4;
    Sint32 var_a3;

    temp_lo = unk->unk4 / unk->unk8;
    temp_t7 = unk->unk18;
    var_t1 = unk->unk10;
    temp_t0 = unk->unk20;
    var_a3 = unk->unk28;

    temp_lo_2 = (var_a3 + var_t1 - 1) / var_t1;
    var_t3 = (temp_t7 - temp_t0 + var_t1 - 1) / var_t1;
    temp_a1_2 = var_t1 - (var_a3 + var_t1 - 1) % var_t1 - 1;

    var_t4 = unk->unk24;
    temp_lo_3 = var_t3 * var_t1;

    if (temp_lo_2 < var_t3) {
        if ((temp_t0 + temp_lo_3 - temp_a1_2) < temp_t7) {
            var_t3 += 1;
        }
    }

    if (var_a3 < var_t4) {
        var_t4 += temp_a1_2;
    }

    temp_t2 = MIN(var_t4 / var_t1, temp_lo);
    temp_t2 = MIN(temp_lo_2, temp_t2);
    temp_t2 = MIN(var_t3, temp_t2);

    if (unk->unk8 == 2) {
        ADXB_EvokeExpandSte(adxb, temp_t2);
    } else if (adxb->unkE4 != 0) {
        ADXB_EvokeExpandPl2(adxb, temp_t2);
    } else {
        ADXB_EvokeExpandMono(adxb, temp_t2);
    }
}

void memcpy2(void* dest, const void* src, Sint32 count) {
    Uint16* _dest = dest;
    const Uint16* _src = src;

    while (count > 0) {
        *_dest++ = *_src++;
        count -= 1;
    }
}

void ADXB_CopyExtraBufSte(void* arg0, Sint32 arg1, Sint32 arg2, Sint32 arg3) {
    memcpy2(arg0, arg0 + (arg1 * 2), arg3);
    memcpy2(arg0 + (arg2 * 2), arg0 + ((arg2 + arg1) * 2), arg3);
}

void ADXB_CopyExtraBufMono(void* arg0, Sint32 arg1, Sint32 arg2, Sint32 arg3) {
    memcpy2(arg0, arg0 + (arg1 * 2), arg3);
}

void ADXB_EndDecode(ADXB adxb) {
    Sint32 s1, s2, sp0, s3, s0, _s0, v0, temp_div;
    Sint32 s7;
    ADXB_UNK* s5 = &adxb->unk48;
    void* s8 = s5->unk14;
    Sint32 s4;
    Sint32 tmp1, tmp3;

    s3 = s5->unkC;
    s1 = s5->unk10;
    s4 = s5->unk20;
    sp0 = adxb->unk44;
    s7 = adxb->unk40;

    temp_div = s5->unk28 + s1 - 1;
    s0 = temp_div % s1;
    _s0 = s1 - s0 - 1;
    s2 = temp_div / s1;

    v0 = ADXPD_GetNumBlk(adxb->adxpd);

    tmp1 = v0 * s1;
    s1 = tmp1;
    s2 = s2 * s5->unk8;
    tmp3 = v0 * s3;
    s3 = tmp3;
    s1 = s1 / s5->unk8;
    adxb->dec_num_sample = (v0 < s2) ? s1 : s1 - _s0;
    s4 += adxb->dec_num_sample;
    adxb->dec_data_len = s3;

    if (s4 >= s7) {
        s4 -= s7;

        if ((s5->unk8 == 2) || (adxb->unkE4 != 0)) {
            ADXB_CopyExtraBufSte(s8, s7, sp0, s4);
        } else {
            ADXB_CopyExtraBufMono(s8, s7, sp0, s4);
        }
    }
}

void ADXB_ExecOneAdx(ADXB adxb) {
    ADXPD adxpd;
    Sint16 temp_a1;
    Sint16* temp_a2;
    Sint32 temp_a3;
    Sint32 temp_a3_2;
    Sint32 i;

    if (adxb->stat == 1) {
        if (ADXPD_GetStat(adxb->adxpd) == 0) {
            adxb->get_wr(adxb->object, &adxb->unk48.unk20, &adxb->unk48.unk24, &adxb->unk48.unk28);
            ADXB_EvokeDecode(adxb);
            adxb->stat = 2;
        }
    }

    if (adxb->stat == 2) {
        ADXPD_ExecHndl(adxb->adxpd);

        if (ADXPD_GetStat(adxb->adxpd) == 3) {
            if (adxb->unkE4 != 0) {
                adxpd = adxb->adxpd;

                // This code path is never taken, so we can leave it dirty for now
                for (i = 0; i < (adxpd->num_blk << 5); i++) {
                    temp_a3 = i * 2;
                    temp_a2 = temp_a3 + adxpd->unk20;
                    temp_a1 = *temp_a2;
                    temp_a3_2 = adxpd->unk24 + temp_a3;
                    ((void (*)(ADXB_OBJ*, Sint16, Sint16*, Sint32))pl2encodefunc)(adxb, temp_a1, temp_a2, temp_a3_2);
                }
            }

            ADXB_EndDecode(adxb);
            ADXPD_Reset(adxb->adxpd);
            adxb->add_wr(adxb->unk84, adxb->dec_data_len, adxb->dec_num_sample);
            adxb->stat = 3;
        }
    }
}

void ADXB_ExecHndl(ADXB adxb) {
    if (adxb->format == 0) {
        ADXB_ExecOneAdx(adxb);
    } else if (adxb->format == 10) {
        ADXB_ExecOneAhx(adxb);
    } else if (adxb->format == 2) {
        ADXB_ExecOneSpsd(adxb);
    } else if (adxb->format == 3) {
        ADXB_ExecOneAiff(adxb);
    } else if (adxb->format == 4) {
        ADXB_ExecOneAu(adxb);
    } else if (adxb->format == 1) {
        ADXB_ExecOneWav(adxb);
    } else if (adxb->format == 15) {
        ADXB_ExecOneAc3(adxb);
    }
}

void ADXB_ExecServer(void) {
    Sint32 i;

    for (i = 0; i < ADXB_MAX_OBJ; i++) {
        if (adxb_obj[i].unk0 == 1) {
            ADXB_ExecHndl(&adxb_obj[i]);
        }
    }
}
