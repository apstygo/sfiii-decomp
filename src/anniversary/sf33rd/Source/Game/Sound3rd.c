#include "sf33rd/Source/Game/Sound3rd.h"
#include "common.h"
#include "sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse.h"
#include "structs.h"
#include <cri/ee/cri_mw.h>

extern ADXT adxt;
extern BGMExecution bgm_exe;
extern BGMRequest bgm_req;

s32 adx_now_playing();

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", literal_398_00552610);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", Init_sound_system);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", sndCheckVTransStatus);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", sndInitialLoad);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", cseMemMapInit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", checkAdxFileLoaded);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", Exit_sound_system);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", Init_bgm_work);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", sound_all_off);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", spu_all_off);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", cseSeStopAll);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", sound_bgm_off);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", setSeVolume);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", cseSysSetMasterVolume);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", setupSoundMode);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", cseSysSetMono);

void sound_request_for_dc(SoundPatchConfig *rmc, s16 pan) {
    if (rmc->ptix != 0x7F) {
        if (pan < -0x20) {
            pan = -0x20;
        }

        if (pan > 0x20) {
            pan = 0x20;
        }

        if (rmc->code > 0x7F) {
            rmc->port = 0;
        }

        cseTsbRequest(rmc->ptix, rmc->code, 2, 6, pan, 2, rmc->port);
        return;
    }

    bgm_req.req = 1;

    switch (bgm_req.kind = rmc->bank) {
    case 5:
        if (bgm_exe.kind == 5) {
            bgm_req.req = 0;
            break;
        }

    case 7:
        bgm_req.data = rmc->port;
        bgm_req.code = -1;
        break;

    case 9:
        if ((adx_now_playing() != 0) && (bgm_exe.code == rmc->code)) {
            bgm_req.kind = 7;
            bgm_req.data = 0;
            bgm_req.code = -1;
            return;
        }

        bgm_req.kind = 4;
        /* fallthrough */

    case 2:
    case 4:
        bgm_req.data = 0;
        bgm_req.code = rmc->code;
        break;

    case 6:
        bgm_req.data = rmc->port;
        bgm_req.code = rmc->code;
        break;

    case 0:
    case 1:
    case 3:
    case 8:
        bgm_req.data = 0;
        bgm_req.code = -1;
        /* fallthrough */

    default:
        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", BGM_Server);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", bgm_separate_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", setupAlwaysSeamlessFlag);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", bgm_play_request);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", bgm_seamless_clear);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", bgm_volume_setup);

s32 adx_now_playing() {
    bgm_exe.state = ADXT_GetStat(adxt);

    if ((bgm_exe.state == 3) || (bgm_exe.state == 4)) {
        return 1;
    }

    return 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", adx_now_playend);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", bgm_play_status);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", bgmSkipCheck);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", SsAllNoteOff);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", SsRequestPan);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", literal_741_00552678);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", remake_sound_code_for_DC);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", SsRequest);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", SsRequest_CC);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", Standby_BGM);

void Go_BGM() {
    SoundPatchConfig rmcode;

    rmcode.ptix = 0x7F;
    rmcode.bank = 3;
    rmcode.port = 0;
    rmcode.code = 0;
    sound_request_for_dc(&rmcode, 0);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", SsBgmOff);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", SsBgmFadeIn);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", SsBgmFadeOut);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", SsBgmControl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", SsBgmHalfVolume);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", SE_cursor_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", SE_selected);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", SE_dir_cursor_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", SE_dir_selected);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", adx_volume);
