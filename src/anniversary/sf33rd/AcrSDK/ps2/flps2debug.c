#include "sf33rd/AcrSDK/ps2/flps2debug.h"
#include "common.h"
#include "sf33rd/AcrSDK/common/mlPAD.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "structs.h"

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

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", flPS2DebugStrDisp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", flPrintL);

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
