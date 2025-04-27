#include "sf33rd/AcrSDK/ps2/flps2debug.h"
#include "common.h"
#include "sf33rd/AcrSDK/common/mlPAD.h"
#include "sf33rd/AcrSDK/ps2/flps2dma.h"
#include "sf33rd/AcrSDK/ps2/flps2etc.h"
#include "sf33rd/AcrSDK/ps2/flps2render.h"
#include "sf33rd/AcrSDK/ps2/flps2vram.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "structs.h"
#include <eestruct.h>

#if defined(TARGET_PS2)
#include "mw_stdarg.h"
#else
#include <stdarg.h>
#endif

void flPS2DebugStrClear();

s32 flSetDebugMode(u32 flag) {
    flDebugFlag = flag;
    return 1;
}

f64 flGetSystemTime() {
    f32 sys_time = *T0_COUNT;
    sys_time = ((1000.0f * sys_time) / 60.0f) / 240.0f;
    return sys_time;
}

void flPS2DebugInit() {
    s32 len;
    s32 i;

    flSetDebugMode(3);
    flDebugSysMemHandleNum = 0;
    flDebugSysMemEtc = 0;
    flDebugSysMemTexture = 0;
    flDebugSysMemClay = 0;
    flDebugSysMemMotion = 0;

    for (i = 0; i < DEBUG_SYS_MEM_SIZE; i++) {
        flDebugSysMem[i] = 0;
    }

    len = 0xE100;
    flDebugStrHan = flPS2GetSystemMemoryHandle(len, 1);
    flhDebugStr = flCreateTextureFromFile("IOP\\FONT8_8.TM2", 4);

    if (flhDebugStr == 0) {
        while (1) {}
    }

    flPrintColor(-1);
    flPS2DebugStrClear();
}

void flPS2DebugStrClear() {
    flDebugStrX = 0;
    flDebugStrY = 0;
    flDebugStrCtr = 0;
}

void flPS2DebugStrDisp() {
    RenderBuffer *buff_ptr;
    u64 *work_ptr;
    u64 *keep_ptr;
    u64 *buff_end_ptr;
    u64 *giftag_keep_ptr;
    u32 code;
    u32 disp_ctr;
    s32 length;
    s32 lp0;
    u32 col;
    u32 colold;
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    s16 u1;
    s16 v1;
    s16 u2;
    s16 v2;
    u64 texA;
    u64 tex1;
    u64 miptbp1;
    u64 miptbp2;
    u64 rgbaq;

    buff_ptr = flPS2GetSystemBuffAdrs(flDebugStrHan);
    colold = 0;
    flReloadTexture(1, &flhDebugStr);
    flPS2SendRenderState_TEX1(0x10000, 1);
    work_ptr = (u64 *)((flPs2State.SystemTmpBuffNow + 0xF) & ~0xF);
    keep_ptr = work_ptr;
    buff_end_ptr = (u64 *)flPs2State.SystemTmpBuffEndAdrs;
    length = buff_end_ptr - work_ptr;

    if (length >= 16) {
        work_ptr += 2;
        *work_ptr++ = SCE_GIF_SET_TAG(6, 1, 0, 0, SCE_GIF_PACKED, 1);
        *work_ptr++ = SCE_GIF_PACKED_AD;
        *work_ptr++ = SCE_GS_SET_TEX1_2(0, 0, 0, 0, 0, 0, 0);
        *work_ptr++ = SCE_GS_TEX1_2;
        *work_ptr++ = SCE_GS_SET_TEST_2(1, 7, 0, 0, 0, 0, 1, 1);
        *work_ptr++ = SCE_GS_TEST_2;
        *work_ptr++ = SCE_GS_SET_SCISSOR_2(0, flWidth - 1, 0, flHeight - 1);
        *work_ptr++ = SCE_GS_SCISSOR_2;

        flPS2SetTextureRegister(flhDebugStr, &texA, &tex1, work_ptr, work_ptr + 2, &miptbp1, &miptbp2, 0x20000);

        *(work_ptr + 1) = 7;
        *(work_ptr + 3) = 9;
        work_ptr += 4;
        *work_ptr++ = 0x316;
        *work_ptr++ = 0;
        giftag_keep_ptr = work_ptr;
        disp_ctr = 0;
        work_ptr += 2;
        length = buff_end_ptr - work_ptr;

        for (lp0 = 0; lp0 < flDebugStrCtr; lp0++) {
            length -= 6;

            if (length < 0) {
                break;
            }

            disp_ctr += 1;
            code = buff_ptr->code;
            col = buff_ptr->col;
            buff_ptr->code = 0;

            if (colold != col) {
                rgbaq = SCE_GS_SET_RGBAQ((col >> 16) & 0xFF, (col >> 8) & 0xFF, col & 0xFF, (col >> 0x18) & 0xFF, 1);
                colold = col;
            }

            x1 = buff_ptr->x;
            y1 = buff_ptr->y;
            x2 = x1 + 8;
            y2 = y1 + 8;

            if (flPs2State.InterlaceMode == 0) {
                y1 >>= 1;
                y2 >>= 1;
            }

            u1 = (code % 16) * 8;
            v1 = (code / 16) * 8;
            u2 = u1 + 8;
            v2 = v1 + 8;

            *work_ptr++ = rgbaq;
            *work_ptr++ = SCE_GS_SET_UV(u1 * 16, v1 * 16);
            *work_ptr++ = SCE_GS_SET_XYZ2(
                (flPs2State.D2dOffsetX + x1) * 16, (flPs2State.D2dOffsetY + y1) * 16, (u32)flPs2State.ZBuffMax);
            *work_ptr++ = SCE_GS_SET_UV(u2 * 16, v2 * 16);
            *work_ptr++ = SCE_GS_SET_XYZ2(
                (flPs2State.D2dOffsetX + x2) * 16, (flPs2State.D2dOffsetY + y2) * 16, (u32)flPs2State.ZBuffMax);

            *work_ptr++ = 0;
            buff_ptr++;
        }

        flPs2State.SystemTmpBuffNow = (u32)work_ptr;

        if (disp_ctr != 0) {
            *giftag_keep_ptr++ = SCE_GIF_SET_TAG(disp_ctr, 1, 0, 0, SCE_GIF_REGLIST, 6);
            *giftag_keep_ptr++ =
                SCE_GS_RGBAQ | SCE_GS_UV << 4 | SCE_GS_XYZ2 << 8 | SCE_GS_UV << 12 | SCE_GS_XYZ2 << 16 | 0xE << 20;
        } else {
            work_ptr = giftag_keep_ptr;
        }

        length = (work_ptr - keep_ptr) >> 1;
        work_ptr = keep_ptr;

        *work_ptr = length + 0x6FFFFFFF;
        ((u32 *)work_ptr)[0] |= 0x80000000;
        ((u32 *)work_ptr)[2] = 0x13000000;
        ((u32 *)work_ptr)[3] = (length - 1) | 0x51000000;
        flPS2DmaAddQueue2(0, ((u32)keep_ptr & 0xFFFFFFF) | 0x40000000, (u32)keep_ptr, &flPs2VIF1Control);
    }

    flPS2DebugStrClear();
}

s32 flPrintL(s32 posi_x, s32 posi_y, const s8 *format, ...) {
    s8 *va_ptr;
    s8 code;
    s8 str[512];
    s32 len;
    s32 i;
    RenderBuffer *buff_ptr;

    va_list args;

    buff_ptr = flPS2GetSystemBuffAdrs(flDebugStrHan);
    buff_ptr += flDebugStrCtr;

    va_start(args, format);
    vsprintf(str, format, args);
    len = strlen(str);

    if (flDebugStrCtr + len >= 0x12C0) {
        len = 0x12C0 - flDebugStrCtr;
    }

    for (i = 0; i < len; i++) {
        code = str[i];

        // code != 0x20 skips spaces
        if ((code >= 0x10) && (code < 0x80) && (code != 0x20)) {
            buff_ptr->x = posi_x * 8;
            buff_ptr->y = posi_y * 8;
            buff_ptr->code = code;
            buff_ptr->col = flDebugStrCol;
            buff_ptr++;
            flDebugStrCtr += 1;
        }

        posi_x += 1;
    }

    return 1;
}

s32 flPrintColor(u32 color) {
    u8 r = (color >> 16) & 0xFF;
    u8 g = (color >> 8) & 0xFF;
    u8 b = (color) & 0xFF;
    u8 a = (color >> 24) & 0xFF;

    r >>= 1;
    g >>= 1;
    b >>= 1;

    if (a == 0xFF) {
        a = 0x80;
    } else {
        a >>= 1;
    }

    flDebugStrCol = (a << 24) | (r << 16) | (g << 8) | b;
    return 1;
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_376_0055F220);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_377_0055F230);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_378_0055F250);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_379_0055F270);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_380_0055F298);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_381_0055F2A8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_382_0055F2B0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_383_0055F2C0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_384_0055F2D0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_385_0055F2D8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_386_0055F2E0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_387_0055F2E8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_388_0055F2F8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_389_0055F308);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_390_0055F320);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_391_0055F340);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_392_0055F360);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_393_0055F380);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_394_0055F3A0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_395_0055F3B8);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", flPS2DispSystemInfo);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", flPS2DrawProbar);

void flPS2LoadCheckFlush() {
    s32 i;
    flLoadCheckCtr = 0;
    flLoadCheckTimeOld = 0;

    for (i = 0; i < LOAD_CHECK_TIME_SIZE; i++) {
        flLoadCheckTime[i] = 0;
    }
}

void flPS2SystemError(s32 error_level, s8 *format, ...) {
    va_list args;
    s8 str[512];
    s32 len;

    flFlip(0);
    va_start(args, format);
    vsprintf(str, format, args);
    len = strlen(str);

    while (1) {
        flPrintL(10, 20, "%s", str);

        if (error_level == 0) {
            flSetRenderState(FLRENDER_BACKCOLOR, 0xFF0000);
        } else {
            flSetRenderState(FLRENDER_BACKCOLOR, 0xFF);
            flPrintL(10, 40, "PRESS 1P START BUTTON TO EXIT");

            if (flpad_adr[0][0].sw_new & 0x8000) {
                break;
            }
        }

        flFlip(0);
        flPADGetALL();
    }
}
