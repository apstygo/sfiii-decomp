#include "sf33rd/Source/Game/DEMO00.h"
#include "common.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "sf33rd/Source/Game/AcrUtil.h"
#include "sf33rd/Source/Game/GD3rd.h"
#include "sf33rd/Source/Game/SYS_sub2.h"
#include "sf33rd/Source/Game/op_sub.h"
#include "sf33rd/Source/Game/texgroup.h"
#include "unknown.h"

void CAPLOGO_Init();
s16 CAPLOGO_Move(u16 type);

static const f32 caplogo00[17] = { 0.25f, 0.25f, 1.0f,  0.5f,   0.0f, 0.0f,   192.0f, 64.0f, 0.0f,
                                   0.5f,  1.0f,  0.75f, 192.0f, 0.0f, 256.0f, 64.0f,  -1.0f };

static const f32 caplogo01[17] = { 0.0f,  0.0f,  1.0f, 0.25f,  0.0f, 0.0f,  256.0f, 64.0f, 0.0f,
                                   0.25f, 0.25f, 0.5f, 256.0f, 0.0f, 64.0f, 64.0f,  -1.0f };

static const float *caplogo[2] = { caplogo00, caplogo01 };

s32 Warning() {
    setTexAdrsMode(0);
    setFilterMode(1);
    Next_Demo = 0;

    switch (D_No[1]) {
    case 0:
        D_No[1] = 5;
        D_No[1] = 9;
        D_Timer = 120;
        FadeInit();
        Next_Demo = 0;
        break;

    case 5:
        Put_Warning(1);
        Next_Demo = 0;

        if (FadeIn(1, 8, 8) != 0) {
            D_No[1] += 1;
            D_Timer = 120;
        }

        break;

    case 6:
        if ((Usage == 7) && (((p1sw_0 & 0x4FF0) | (p2sw_0 & 0x4FF0)) != 0)) {
            D_Timer = 2;
            D_No[1] = 7;
            FadeInit();
        }

        Put_Warning(1);
        Next_Demo = 0;

        if (!--D_Timer) {
            D_No[1] += 1;
            D_Timer = 180;
        }

        break;

    case 7:
        if (((p1sw_0 & 0x4FF0) | (p2sw_0 & 0x4FF0)) != 0) {
            D_Timer = 1;
        }

        if (!--D_Timer) {
            D_No[1] += 1;
            FadeInit();
        }

        Put_Warning(1);
        Next_Demo = 0;
        break;

    case 8:
        Put_Warning(1);
        Next_Demo = 0;

        if (FadeOut(1, 8, 8) != 0) {
            D_No[1] += 1;
        }

        break;

    default:
        D_No[1] = 0;
        TexRelease(0x24E);
        Next_Demo = 1;
        break;
    }

    return Next_Demo;
}

s32 CAPCOM_Logo() {
    setTexAdrsMode(0);
    setFilterMode(0);
    ppgSetupCurrentDataList(&ppgCapLogoList);
    Next_Demo = 0;

    switch (D_No[1]) {
    case 0:
        D_No[1] += 1;
        checkAdxFileLoaded();
        checkSelObjFileLoaded();
        break;

    case 1:
        D_No[1] += 1;
        setup_pos_remake_key(1);
        Standby_BGM(0x43);
        CAPLOGO_Init();
        Push_LDREQ_Queue_Direct(0x16, 2);
        FadeInit();
        break;

    case 2:
        if (Check_LDREQ_Clear() != 0) {
            D_No[1] += 1;
            D_Timer = 10;
        }

        break;

    case 3:
        if (--D_Timer == 0) {
            D_No[1] += 1;
            op_timer0 = 0;
            Go_BGM();
        }

        break;

    case 4:
        if (!CAPLOGO_Move(0)) {
            D_No[1] += 1;
            Push_LDREQ_Queue_Direct(0x17, 2);
            FadeInit();
        }

        break;

    case 5:
        CAPLOGO_Move(1);

        if (FadeIn(1, 6, 8) != 0) {
            D_No[1] += 1;
            D_Timer = 256;
            Push_LDREQ_Queue_Direct(0x18, 2);
        }

        break;

    case 6:
        CAPLOGO_Move(1);

        if (--D_Timer == 0) {
            D_No[1] += 1;
            FadeInit();
        }

        break;

    case 7:
        CAPLOGO_Move(1);

        if (FadeOut(1, 6, 8) != 0) {
            D_No[1] += 1;
        }

        break;

    default:
        TexRelease(0x258);
        Next_Demo = 1;
        break;
    }

    return Next_Demo;
}

void CAPLOGO_Init() {
    void *loadAdrs;
    u32 loadSize;
    s16 key;

    mmDebWriteTag("\nCAPCOM LOGO\n\n");
    ppgCapLogoList.tex = &ppgCapLogoTex;
    ppgCapLogoList.pal = &ppgCapLogoPal;
    ppgSetupCurrentDataList(&ppgCapLogoList);
    loadSize = load_it_use_any_key2(0x4B, &loadAdrs, &key, 2, 1);

    if (loadSize == 0) {
        flLogOut("カプロゴのテクスチャが読み込めませんでした。\n");
        while (1) {}
    }

    ppgSetupPalChunk(0, loadAdrs, loadSize, 0, 0, 1);
    ppgSetupTexChunk_1st(0, loadAdrs, loadSize, 0x258, 1, 0, 0);
    ppgSetupTexChunk_2nd(0, 0x258);
    ppgSetupTexChunk_3rd(0, 0x258, 1);
    Push_ramcnt_key(key);
    ppgSourceDataReleased(0);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", CAPLOGO_Move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", Put_char);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", Warning_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", Put_Warning);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", Pal_Cursor_Put);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", literal_315_00504F10);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/DEMO00", literal_316_00504F20);
