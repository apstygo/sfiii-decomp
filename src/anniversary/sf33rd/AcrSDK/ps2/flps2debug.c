#include "sf33rd/AcrSDK/ps2/flps2debug.h"
#include "common.h"
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

void flGetSystemTime(void) {
    f32 sys_time;

    sys_time = ((u32)(*(s32 *)0x10000000));
    sys_time = ((1000.0f * sys_time) / 60.0f) / 240.0f;
    fptodp(sys_time);
}

void flPS2DebugInit(void) {
    s32 var_s0;
    s32 len;

    flSetDebugMode(3);
    flDebugSysMemHandleNum = 0;
    flDebugSysMemEtc = 0;
    flDebugSysMemTexture = 0;
    flDebugSysMemClay = 0;
    flDebugSysMemMotion = 0;

    for (var_s0 = 0; var_s0 < 0x1000; var_s0++) {
        flDebugSysMem[var_s0] = 0;
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

void flPS2DebugStrClear(void) {
    flDebugStrX = 0;
    flDebugStrY = 0;
    flDebugStrCtr = 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", flPS2DebugStrDisp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", flPrintL);

s32 flPrintColor(u32 color) {
    u8 a;
    u8 r;
    u8 g;
    u8 b;

    r = (color >> 16) & 0xFF;
    g = (color >> 8) & 0xFF;
    b = (color) & 0xFF;
    a = (color >> 24) & 0xFF;

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

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", flPS2DispSystemInfo);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", flPS2DrawProbar);

void flPS2LoadCheckFlush(void) {
    s32 var_s0;
    flLoadCheckCtr = 0;
    flLoadCheckTimeOld = 0;

    for (var_s0 = 0; var_s0 < 0x14; var_s0++) {
        flLoadCheckTime[var_s0] = 0;
    }
}

void flPS2SystemError(s32 error_level, s8 *format, ...) {
    s8 str[512];
    s32 len;
    va_list args;

    flFlip(0);
    va_start(args, format);
    vsprintf(str, format, args);
    len = strlen(str);

    while (1) {
        flPrintL(0xA, 0x14, "%s", str);

        if (error_level == 0) {
            flSetRenderState(FLRENDER_BACKCOLOR, 0xFF0000);
        } else {
            flSetRenderState(FLRENDER_BACKCOLOR, 0xFF);
            flPrintL(0xA, 0x28, "PRESS 1P START BUTTON TO EXIT");

            /*
            if (flpad_adr[0][0].sw_new & 0x8000) {
                break;
            }
            */
        }

        flFlip(0);
        flPADGetALL();
    }
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_220_0055F210);

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

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_460_0055F3C0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2debug", literal_461_0055F3D0);
