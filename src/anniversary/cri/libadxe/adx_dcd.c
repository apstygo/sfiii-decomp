#include "common.h"
#include <cri/private/libadxe/adx_dcd.h>

#include <cri/ee/cri_xpt.h>

#define READ16(_p, _off) (((Uint8 *)_p)[_off * 2 + 1] | ((((Uint16 *)_p)[_off] << 8) & ~0xFF))
#define REORDER32(_val) ((Uint32)_val >> 24) | (_val << 24) | (((_val << 8) & 0xFF0000) | ((_val >> 8) & 0xFF00))

// data
Sint32 adx_decode_output_mono_flag = 0;

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_GetCoefficient);
#else
void ADX_GetCoefficient(Sint16 *, Sint32, Sint16 *, Sint16 *) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_ScanInfoCode);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", D_0055A1F0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_IsAdxFmt);

Sint32 ADX_DecodeInfo(ADXHeader *hdr, Sint32 arg1, Sint16 *audio_offset, Sint8 *encoding_type, Sint8 *sample_bitdepth,
                      Sint8 *block_size, Sint8 *channel_count, Sint32 *sample_rate, Sint32 *total_samples,
                      Sint32 *samples_per_block) {
    if (arg1 < 16) {
        return -1;
    }

    if ((hdr->magic_1 | (hdr->magic_0 << 8)) != 0x8000) {
        return -2;
    }

    *audio_offset = ((hdr->copyright_offset_0 << 8) | hdr->copyright_offset_1) + 4;
    *encoding_type = hdr->encoding_type;
    *block_size = hdr->block_size;
    *sample_bitdepth = hdr->sample_bitdepth;
    *channel_count = hdr->channel_count;
    *sample_rate =
        (hdr->sample_rate_0 << 24) | (hdr->sample_rate_1 << 16) | (hdr->sample_rate_2 << 8) | hdr->sample_rate_3;
    *total_samples = (hdr->total_samples_0 << 24) | (hdr->total_samples_1 << 16) | (hdr->total_samples_2 << 8) |
                     hdr->total_samples_3;

    if (*sample_bitdepth == 0) {
        *samples_per_block = 0;
    } else {
        *samples_per_block = (*block_size - 2) * 8 / *sample_bitdepth;
    }

    return 0;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoExADPCM2);
#else
Sint32 ADX_DecodeInfoExADPCM2(ADXHeader *hdr, Sint32 arg1, Sint16 *high_pass_frequency) {
    Uint32 magic;

    if (arg1 < 0x12) {
        return -1;
    }

    magic = hdr->magic;

    if ((Uint16)((magic >> 8) | (magic << 8)) != 0x8000) {
        return -2;
    }

    if ((Sint16)((hdr->copyright_offset << 8) | hdr->copyright_offset_1) < 0xE) {
        return -1;
    }

    *high_pass_frequency = (hdr->high_pass_frequency << 8) | (hdr->high_pass_frequency >> 8);

    return 0;
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoExVer);
#else
Sint32 ADX_DecodeInfoExVer(ADXHeader *hdr, Sint32 arg1, Sint8 *version, Sint8 *flags) {
    Uint32 magic;

    if (arg1 < 0x14) {
        return -1;
    }

    magic = hdr->magic;

    if ((Uint16)((magic >> 8) | (magic << 8)) != 0x8000) {
        return -2;
    }

    if ((Sint16)((hdr->copyright_offset << 8) | hdr->copyright_offset_1) < 0x10) {
        return -1;
    }

    *version = hdr->version;
    *flags = hdr->flags;

    return 0;
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoExIdly);
#else
Sint32 ADX_DecodeInfoExIdly(ADXHeader *hdr, Sint32 arg1, Sint16 *arg2, Sint16 *arg3) {
    Uint8 version;
    Sint8 flags;
    Uint32 magic;

    if (ADX_DecodeInfoExVer(hdr, arg1, &version, &flags) != 0) {
        return -1;
    }

    if (version >= 4) {
        if (arg1 < 0x20) {
            return -1;
        }

        magic = hdr->magic;

        if ((Uint16)((magic >> 8) | (magic << 8)) != 0x8000) {
            return -2;
        }

        if ((Sint16)(((hdr->copyright_offset << 8) & ~0xFF) | hdr->copyright_offset_1) < 0x1C) {
            return -1;
        }

        arg2[0] = ((hdr->unk18 >> 8) | ((hdr->unk18 << 8) & ~0xFF));
        arg3[0] = ((hdr->unk1A >> 8) | ((hdr->unk1A << 8) & ~0xFF));
        arg2[1] = ((hdr->unk1C >> 8) | ((hdr->unk1C << 8) & ~0xFF));
        arg3[1] = ((hdr->unk1E >> 8) | ((hdr->unk1E << 8) & ~0xFF));
    } else {
        arg3[1] = 0;
        arg2[1] = 0;
        arg3[0] = 0;
        arg2[0] = 0;
    }

    return 0;
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoExLoop);
#else
// TODO: This function needs thorough testing
Sint32 ADX_DecodeInfoExLoop(Uint8 *hdr, Sint32 arg1, Sint32 *arg2, Sint16 *arg3, Sint16 *arg4, Sint32 *arg5,
                            Sint32 *arg6, Sint32 *arg7, Sint32 *arg8) {
    Uint8 version;
    Sint8 flags;
    Sint32 err;
    Uint32 magic;
    Uint8 *p;

    Sint32 raw_arg5;
    Sint32 raw_arg6;
    Sint32 raw_arg7;
    Sint32 raw_arg8;

    Sint32 temp_t5;
    Sint32 temp_a2;

    *arg3 = 0;
    err = ADX_DecodeInfoExVer(hdr, arg1, &version, &flags);

    if (err != 0) {
        return err;
    }

    temp_a2 = 0x30;

    if (version == 4) {
        temp_a2 = 0x3C;
    }

    if (arg1 < temp_a2) {
        return -1;
    }

    magic = ((Uint16 *)hdr)[0];

    if ((Uint16)((magic >> 8) | (magic << 8)) != 0x8000) {
        return -2;
    }

    if ((Sint16)READ16(hdr, 1) < (temp_a2 - 4)) {
        return -1;
    }

    temp_t5 = 0x14;

    if (version == 4) {
        temp_t5 = 0x20;
    }

    p = (Uint8 *)(hdr + temp_t5);

    *arg2 = READ16(p, 0);
    p += 2;

    *arg3 = READ16(p, 0);
    p += 2;

    if (*arg3 != 1) {
        return -2;
    }

    p += 2;

    *arg4 = READ16(p, 0);
    p += 2;

    raw_arg5 = *(Uint32 *)p;
    *arg5 = REORDER32(raw_arg5);
    p += 4;

    raw_arg6 = *(Uint32 *)p;
    *arg6 = REORDER32(raw_arg6);
    p += 4;

    raw_arg7 = *(Uint32 *)p;
    *arg7 = REORDER32(raw_arg7);
    p += 4;

    raw_arg8 = *(Uint32 *)p;
    *arg8 = REORDER32(raw_arg8);

    return 0;
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeInfoAinf);
#else
// TODO: This function needs thorough testing
Sint32 ADX_DecodeInfoAinf(Uint8 *hdr, Sint32 arg1, Sint32 *arg2, ADX_UNK *arg3, Sint16 *arg4, Sint16 *arg5) {
    Uint8 version;
    Sint8 flags;
    Sint32 raw_arg2;
    Sint32 temp_a2;
    Sint32 temp_t1;
    Sint32 err;
    Uint32 magic;

    Uint8 *p;

    *arg2 = 0;
    err = ADX_DecodeInfoExVer(hdr, arg1, &version, &flags);

    if (err != 0) {
        return err;
    }

    temp_a2 = 0x3C;

    if (version == 4) {
        temp_a2 = 0x48;
    }

    if (arg1 < temp_a2) {
        return -1;
    }

    magic = ((Uint16 *)hdr)[0];

    if ((Uint16)((magic >> 8) | (magic << 8)) != 0x8000) {
        return -2;
    }

    if ((Sint16)READ16(hdr, 1) < (temp_a2 - 4)) {
        return -1;
    }

    temp_t1 = 0x14;

    if (version == 4) {
        temp_t1 = 0x20;
    }

    temp_t1 += 4;
    p = hdr + temp_t1;

    // 'AINF' magic
    if (((p[0] << 0x18) | p[3] | ((p[2] << 8) | (p[1] << 0x10))) != 0x41494E46) {
        return -2;
    }

    p += 4;

    raw_arg2 = *(Uint32 *)p;
    *arg2 = REORDER32(raw_arg2);
    p += 4;

    *arg3 = *(ADX_UNK *)p;
    p += 0x10;

    *arg4 = READ16(p, 0);
    p += 4;

    arg5[0] = READ16(p, 0);
    arg5[1] = READ16(p, 1);

    return 0;
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_DecodeFooter);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_dcd", ADX_CalcHdrInfoLen);
