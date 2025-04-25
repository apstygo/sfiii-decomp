#include "sf33rd/Source/Game/Sound3rd.h"
#include "common.h"
#include "sf33rd/AcrSDK/MiddleWare/PS2/ADX/flADX.h"
#include "sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse.h"
#include "sf33rd/Source/Common/PPGFile.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/GD3rd.h"
#include "sf33rd/Source/Game/RAMCNT.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/color3rd.h"
#include "sf33rd/Source/Game/main.h"
#include "sf33rd/Source/PS2/CapSndEng/emlMemMap.h"
#include "sf33rd/Source/PS2/cseDataFiles/SpuMap.h"
#include "structs.h"
#include <cri/ee/cri_mw.h>

#define ADX_STM_WORK_SIZE 252388

// sbss
extern s16 se_level;
extern s16 bgm_level;
extern s16 bgm_half_down;
extern s16 current_bgm;
extern s16 bgm_seamless_always;
extern ADXT adxt;
extern BGMExecution bgm_exe;
extern BGMRequest bgm_req;

// bss
extern u8 adx_VS[198954];
extern u8 adx_EmSel[391168];
extern s8 adx_stm_work[ADX_STM_WORK_SIZE];

// sdata
extern SoundEvent *cseTSBDataTable[21]; // has no size in .h
extern s8 *csePHDDataTable[21];         // has no size in .h
extern u8 adx_NowOnMemoryType;

s32 cseMemMapInit(void *pSpuMemMap);
s32 adx_now_playing();

void Init_sound_system() {
    se_level = 15;
    bgm_level = 15;
    bgm_half_down = 0;
    current_bgm = 0;
    bgm_seamless_always = 0;
    sys_w.sound_mode = 0;
    sys_w.bgm_type = 0;
    flAdxInitialize(NULL, "\\THIRD\\");
    ADXT_Init();
    adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
    system_init_level |= 2;
    cseInitSndDrv();
    system_init_level |= 1;
}

s32 sndCheckVTransStatus(s32 type) {
    s32 rnum = 0;

    switch (type) {
    case 0:
        if (cseCheckVTransStatus(0) >= 0) {
            rnum = 1;
        }

        break;

    case 1:
        if (cseCheckVTransStatus(1) >= 0) {
            rnum = 1;
        }

        break;
    }

    return rnum;
}

void sndInitialLoad() {
    cseMemMapInit(SpuMap);
    cseMemMapSetPhdAddr(0, *csePHDDataTable);
    cseTsbSetBankAddr(0, *cseTSBDataTable);
    load_any_color(109, 20);
}

s32 cseMemMapInit(void *pSpuMemMap) {
    return mlMemMapInit(pSpuMemMap);
}

void checkAdxFileLoaded() {
    u8 *adr;
    s16 key;
    u16 fnum;

    if (adx_NowOnMemoryType == sys_w.bgm_type) {
        return;
    }

    if (sys_w.bgm_type == 0) {
        fnum = 89;
    } else {
        fnum = 90;
    }

    do {
        key = load_it_use_any_key(fnum, 21, 0);
    } while (key == 0);

    adr = (u8 *)Get_ramcnt_address(key);
    ppgSetupCmpChunk(adr, 0, adx_VS);
    ppgSetupCmpChunk(adr, 1, adx_EmSel);
    Push_ramcnt_key(key);
    adx_NowOnMemoryType = sys_w.bgm_type;
}

void Exit_sound_system() {
    if (system_init_level & 2) {
        ADXT_Destroy(adxt);
        ADXT_Finish();
        system_init_level &= ~2;
    }

    if (system_init_level & 1) {
        spu_all_off();
        system_init_level &= ~1;
    }
}

void Init_bgm_work() {
    work_init_zero((s32 *)&bgm_exe, 22);
    work_init_zero((s32 *)&bgm_req, 8);
}

void sound_all_off() {
    sound_bgm_off();
    spu_all_off();
}

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

    if ((bgm_exe.state == ADXT_STAT_PLAYING) || (bgm_exe.state == ADXT_STAT_DECEND)) {
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
