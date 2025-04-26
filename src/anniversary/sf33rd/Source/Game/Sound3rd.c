#define SET_SE_VOLUME_DEFINED

#include "sf33rd/Source/Game/Sound3rd.h"
#include "common.h"
#include "sf33rd/AcrSDK/MiddleWare/PS2/ADX/flADX.h"
#include "sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/cse.h"
#include "sf33rd/AcrSDK/ps2/flps2debug.h"
#include "sf33rd/Source/Common/PPGFile.h"
#include "sf33rd/Source/Game/EFFECT.h"
#include "sf33rd/Source/Game/GD3rd.h"
#include "sf33rd/Source/Game/RAMCNT.h"
#include "sf33rd/Source/Game/SE.h"
#include "sf33rd/Source/Game/SYS_sub.h"
#include "sf33rd/Source/Game/Se_Data.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/color3rd.h"
#include "sf33rd/Source/Game/debug/Debug.h"
#include "sf33rd/Source/Game/main.h"
#include "sf33rd/Source/Game/workuser.h"
#include "sf33rd/Source/PS2/CapSndEng/emlMemMap.h"
#include "sf33rd/Source/PS2/CapSndEng/emlSndDrv.h"
#include "sf33rd/Source/PS2/CapSndEng/emlTSB.h"
#include "sf33rd/Source/PS2/cseDataFiles/SpuMap.h"
#include "structs.h"
#include <cri/ee/cri_mw.h>

#define ADX_STM_WORK_SIZE 252388

// sbss
extern s16 se_level;
extern s16 bgm_level;
extern s16 bgm_vol_mix;
extern s16 bgm_vol_now;
extern s16 bgm_fade_ix;
extern s16 bgm_half_down;
extern s16 current_bgm;
extern s16 bgm_seamless_always;
extern BGMFade bgm_fade;
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
extern BGMTableEntry *bgm_table[2];
extern BGMExecutionData *bgm_exdata[2];

s32 cseMemMapInit(void *pSpuMemMap);
s32 adx_now_playing();
void spu_all_off();
void sound_bgm_off();
void SsBgmOff();
void bgm_play_request(s32 filenum, s32 flag);
void bgm_seamless_clear();
s32 bgm_separate_check();
// u16 remake_sound_code_for_DC(u32 code, SoundPatchConfig *rmcode);

extern const s16 adx_volume[128];

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

void spu_all_off() {
    if (system_init_level & 1) {
        cseSeStopAll();
    }
}

s32 cseSeStopAll() {
    mlTsbStopAll();
    mlSeStopAll();
    return 0;
}

void sound_bgm_off() {
    if ((system_init_level & 2) && (adx_now_playing() != 0)) {
        SsBgmOff();
    }
}

void setSeVolume() {
    f32 vol;

    if (system_init_level & 2) {
        vol = (127.0f / 15.0f) * se_level;
        cseSysSetMasterVolume(vol);
    }
}

s32 cseSysSetMasterVolume(s32 vol) {
    return mlSysSetMasterVolume(vol);
}

void setupSoundMode() {
    if (system_init_level & 2) {
        cseSysSetMono(sys_w.sound_mode);
        ADXT_SetOutputMono(sys_w.sound_mode);
    }
}

s32 cseSysSetMono(u32 mono_sw) {
    return mlSysSetMono(mono_sw);
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", sound_request_for_dc);
#else
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
#endif

void BGM_Server() {
    if (!(system_init_level & 2)) {
        return;
    }

    if (bgm_req.req) {
        bgm_req.req = 0;
        bgm_exe.kind = bgm_req.kind;
        bgm_exe.data = bgm_req.data;

        if (bgm_req.code != -1) {
            bgm_exe.code = bgm_req.code;
        }

        bgm_exe.rno = 0;

        if (bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0x8000) {
            bgm_exe.kind = 0;
        }
    }

    if (bgm_exe.code != 0) {
        bgm_vol_mix = bgm_level * bgm_table[sys_w.bgm_type][bgm_exe.code].vol / 15;
    }

    switch (bgm_exe.kind) {
    case 1:
        ADXT_Stop(adxt);
        bgm_seamless_clear();
        current_bgm = 0;
        bgm_exe.kind = 0;
        break;

    case 2:
        ADXT_Stop(adxt);

        if ((bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0x4000) && (bgm_separate_check() != 0)) {
            bgm_exe.exIndex = bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0xFF;
            bgm_exe.exEntry = bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numStart;
            ADXT_Destroy(adxt);
            adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
            bgm_volume_setup(0);
            ADXT_Pause(adxt, 1);
            bgm_play_request(bgm_exe.exEntry, 0);
            bgm_exe.nowSeamless = 1;
            ADXT_StartSeamless(adxt);
        } else {
            bgm_seamless_clear();
            bgm_volume_setup(0);
            ADXT_Pause(adxt, 1);

            if (adx_NowOnMemoryType == sys_w.bgm_type) {
                switch (bgm_exe.code) {
                case 0x33:
                    ADXT_StartMem(adxt, adx_VS);
                    break;

                case 0x39:
                    ADXT_StartMem(adxt, adx_EmSel);
                    break;

                default:
                    bgm_play_request(bgm_exe.code, 1);
                    break;
                }
            } else {
                bgm_play_request(bgm_exe.code, 1);
            }
        }

        current_bgm = bgm_exe.code;
        bgm_exe.kind = 0;
        break;

    case 3:
        ADXT_Pause(adxt, 0);
        bgm_exe.kind = 0;
        break;

    case 4:
        if ((bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0x4000) && (bgm_separate_check() != 0)) {
            if ((bgm_exe.nowSeamless == 0) || (bgm_exe.code != current_bgm)) {
                bgm_exe.exIndex = bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0xFF;
                bgm_exe.exEntry = bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numStart;

                if (bgm_exe.nowSeamless == 0) {
                    ADXT_Destroy(adxt);
                    adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
                    bgm_volume_setup(0);
                }

                bgm_play_request(bgm_exe.exEntry, 0);

                if (bgm_exe.nowSeamless == 0) {
                    bgm_exe.nowSeamless = 1;
                    ADXT_StartSeamless(adxt);
                }
            }
        } else {
            bgm_seamless_clear();
            bgm_volume_setup(0);

            if (adx_NowOnMemoryType == sys_w.bgm_type) {
                switch (bgm_exe.code) {
                case 0x33:
                    ADXT_StartMem(adxt, adx_VS);
                    break;

                case 0x39:
                    ADXT_StartMem(adxt, adx_EmSel);
                    break;

                default:
                    bgm_play_request(bgm_exe.code, 1);
                    break;
                }
            } else {
                bgm_play_request(bgm_exe.code, 1);
            }
        }

        if (ADXT_GetStatPause(adxt) != 0) {
            ADXT_Pause(adxt, 0);
        }

        current_bgm = bgm_exe.code;
        bgm_exe.kind = 0;
        break;

    case 5:
        switch (bgm_exe.rno) {
        case 0:
            bgm_fade.in.dex.hi = bgm_vol_now;
            bgm_fade.in.dex.low = -0x8000;
            bgm_fade.speed = -(bgm_fade.in.cal / bgm_exe.data);
            bgm_fade.in.cal = 0;
            bgm_exe.rno = 1;
            /* fallthrough */

        case 1:
            if (adx_now_playing() == 0) {
                bgm_exe.rno = 3;
                break;
            } else {
                bgm_exe.rno = 2;
                bgm_exe.volume = 0;
            }

            /* fallthrough */

        case 2:
            bgm_fade.in.cal += bgm_fade.speed;
            bgm_volume_setup(bgm_fade.in.dex.hi);

            if (bgm_vol_now) {
                break;
            }

            /* fallthrough */

        default:
            bgm_exe.kind = 1;
            break;
        }

        break;

    case 6:
        switch (bgm_exe.rno) {
        case 0:
            bgm_fade.in.dex.hi = bgm_vol_mix;
            bgm_fade.in.dex.low = -0x8000;
            bgm_fade.speed = bgm_fade.in.cal / bgm_exe.data;

            if ((bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0x4000) && (bgm_separate_check() != 0)) {
                if ((bgm_exe.nowSeamless == 0) || (bgm_exe.code != current_bgm)) {
                    bgm_exe.exIndex = bgm_table[sys_w.bgm_type][bgm_exe.code].data & 0xFF;
                    bgm_exe.exEntry = bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numStart;

                    if (bgm_exe.nowSeamless == 0) {
                        ADXT_Destroy(adxt);
                        adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
                    }

                    bgm_play_request(bgm_exe.exEntry, 0);

                    if (bgm_exe.nowSeamless == 0) {
                        bgm_exe.nowSeamless = 1;
                        ADXT_StartSeamless(adxt);
                    }
                }
            } else {
                bgm_seamless_clear();

                if (adx_NowOnMemoryType == sys_w.bgm_type) {
                    switch (bgm_exe.code) {
                    case 0x33:
                        ADXT_StartMem(adxt, adx_VS);
                        break;

                    case 0x39:
                        ADXT_StartMem(adxt, adx_EmSel);
                        break;

                    default:
                        bgm_play_request(bgm_exe.code, 1);
                        break;
                    }
                } else {
                    bgm_play_request(bgm_exe.code, 1);
                }
            }

            if (ADXT_GetStatPause(adxt) != 0) {
                ADXT_Pause(adxt, 0);
            }

            bgm_volume_setup(-0x7F);
            current_bgm = bgm_exe.code;
            bgm_exe.rno = 1;
            bgm_fade.in.dex.hi = -bgm_vol_mix;
            bgm_fade.in.dex.low = -0x8000;
            /* fallthrough */

        case 1:
            if (adx_now_playing() != 0) {
                bgm_exe.rno = 2;
                bgm_exe.volume = 0;
            } else {
                break;
            }

            /* fallthrough */

        case 2:
            bgm_fade.in.cal += bgm_fade.speed;
            bgm_volume_setup(bgm_fade.in.dex.hi);

            if (bgm_vol_now < bgm_vol_mix) {
                break;
            }

            /* fallthrough */

        default:
            bgm_exe.kind = 0;
            break;
        }

        break;

    case 7:
        bgm_vol_mix = bgm_level * bgm_table[sys_w.bgm_type][current_bgm].vol / 15;
        bgm_volume_setup(bgm_exe.data);
        bgm_exe.kind = 0;
        break;

    case 8:
        bgm_exe.kind = 0;
        break;
    }

    if (bgm_exe.nowSeamless && (ADXT_GetNumFiles(adxt) <= 0)) {
        bgm_exe.exEntry += 1;

        if (bgm_exe.exEntry > bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numEnd) {
            bgm_exe.exEntry = bgm_exdata[sys_w.bgm_type][bgm_exe.exIndex].numLoop;
        }

        bgm_play_request(bgm_exe.exEntry, 0);
    }
}

s32 bgm_separate_check() {
    if (Debug_w[5]) {
        return 1;
    }

    return (mpp_w.inGame | bgm_seamless_always) != 0;
}

void setupAlwaysSeamlessFlag(s16 flag) {
    bgm_seamless_always = flag;
}

void bgm_play_request(s32 filenum, s32 flag) {
    if (flag == 0) {
        ADXT_EntryAfs(adxt, 0, filenum);
        return;
    }

    ADXT_StartAfs(adxt, 0, bgm_table[sys_w.bgm_type][filenum].fnum);
}

void bgm_seamless_clear() {
    if (!bgm_exe.nowSeamless) {
        return;
    }

    bgm_exe.nowSeamless = 0;
    ADXT_Stop(adxt);
    ADXT_ResetEntry(adxt);
    ADXT_Destroy(adxt);
    adxt = ADXT_Create(2, adx_stm_work, ADX_STM_WORK_SIZE);
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", bgm_volume_setup);
#else
void bgm_volume_setup(s16 data) {
    s16 bhd;

    bgm_fade_ix = data;
    bhd = bgm_fade_ix;
    bgm_vol_now = bhd + bgm_vol_mix;

    if (bgm_half_down) {
        if (Country == 1) {
            bgm_vol_now /= 3;
        } else {
            bgm_vol_now = 0;
        }
    }

    if (bgm_vol_now > bgm_vol_mix) {
        bgm_vol_now = bgm_vol_mix;
    }

    if (bgm_vol_now < 0) {
        bgm_vol_now = 0;
    }

    if (Debug_w[44]) {
        bgm_vol_now = 0;
    }

    ADXT_SetOutVol(adxt, adx_volume[bgm_vol_now]);
}
#endif

s32 adx_now_playing() {
    bgm_exe.state = ADXT_GetStat(adxt);

    if ((bgm_exe.state == ADXT_STAT_PLAYING) || (bgm_exe.state == ADXT_STAT_DECEND)) {
        return 1;
    }

    return 0;
}

s32 adx_now_playend() {
    bgm_exe.state = ADXT_GetStat(adxt);

    if (bgm_exe.state == ADXT_STAT_PLAYEND) {
        return 1;
    }

    return 0;
}

s32 bgm_play_status() {
    if (bgm_exe.kind == 5) {
        return 1;
    }

    if (adx_now_playing() != 0) {
        return 2;
    }

    return 0;
}

s32 bgmSkipCheck(s32 code) {
    return (bgm_table[sys_w.bgm_type][code].data & 0x8000) != 0;
}

void SsAllNoteOff() {
    sound_all_off();
}

void SsRequestPan(u16 reqNum, s16 start, s32 /* unused */, s32 /* unused */, s32 /* unused */) {
    SoundPatchConfig rmcode;

    start -= 0x40;

    if (start < -0x3F) {
        start = -0x3F;
    }

    if (start > 0x3F) {
        start = 0x3F;
    }

    if (remake_sound_code_for_DC(reqNum, &rmcode)) {
        return;
    }

    Store_Sound_Code(reqNum, &rmcode);
    sound_request_for_dc(&rmcode, start);
}

#if defined(TARGET_PS2)
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", literal_741_00552678);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/Sound3rd", remake_sound_code_for_DC);
#else
u16 remake_sound_code_for_DC(u16 code, SoundPatchConfig *rmcode) {
    u16 cd;
    u16 mtf;
    u16 p2s;
    u16 rnum;

    rnum = mtf = p2s = 0;

    if (code >= 0x760) {
        code -= 0x600;
        mtf = 1;
    }

    if (code >= 0x400) {
        code -= 0x300;
        p2s = 1;
    }

    rmcode->code = (cd = sdcode_conv[code]) & 0xFFF;

    switch (cd & 0xF000) {
    case 0x0:
        switch (p2s + mtf * 2) {
        case 0:
            rmcode->ptix = 1;
            rmcode->bank = 0;
            rmcode->port = 0;
            break;

        case 1:
            rmcode->ptix = 2;
            rmcode->bank = 1;
            rmcode->port = 3;
            break;

        case 2:
            rmcode->ptix = 2;
            rmcode->bank = 1;
            rmcode->port = 0;
            rmcode->code += 32;
            break;

        case 3:
            rmcode->ptix = 1;
            rmcode->bank = 0;
            rmcode->port = 3;
            rmcode->code += 32;
            break;
        }

        break;

    case 0x2000:
        rmcode->ptix = 0;
        rmcode->bank = 0;

        if (p2s) {
            rmcode->port = 3;
        } else {
            rmcode->port = 0;
        }

        break;

    case 0x3000:
        rmcode->ptix = 0;
        rmcode->bank = 0;

        if (p2s) {
            rmcode->port = -3;
        } else {
            rmcode->port = 0;
        }

        break;

    case 0x8000:
        rmcode->ptix = 0x7F;
        rmcode->bank = 4;
        rmcode->port = 0;
        break;

    default:
    case 0x7000:
        rmcode->ptix = 0x7FFF;
        rmcode->bank = 0;
        rmcode->port = 0;
        rnum = 1;

        while (1) {
            flPrintL(3, 5, "BAD SE CODE %X", code);
            njWaitVSync_with_N();
        }

        break;
    }

    return rnum;
}
#endif

void SsRequest(u16 ReqNumber) {
    SoundPatchConfig rmcode;

    if (remake_sound_code_for_DC(ReqNumber, &rmcode)) {
        return;
    }

    Store_Sound_Code(ReqNumber, &rmcode);
    sound_request_for_dc(&rmcode, 0);
}

void SsRequest_CC(u16 num) {
    SoundPatchConfig rmcode;

    if (remake_sound_code_for_DC(num, &rmcode)) {
        return;
    }

    Store_Sound_Code(num, &rmcode);
    rmcode.bank = 9;
    sound_request_for_dc(&rmcode, 0);
}

void Standby_BGM(u16 num) {
    SoundPatchConfig rmcode;

    if (remake_sound_code_for_DC(num, &rmcode)) {
        return;
    }

    Store_Sound_Code(num, &rmcode);
    rmcode.bank = 2;
    sound_request_for_dc(&rmcode, 0);
}

void Go_BGM() {
    SoundPatchConfig rmcode;

    rmcode.ptix = 0x7F;
    rmcode.bank = 3;
    rmcode.port = 0;
    rmcode.code = 0;
    sound_request_for_dc(&rmcode, 0);
}

void SsBgmOff() {
    SoundPatchConfig rmcode;

    rmcode.ptix = 0x7F;
    rmcode.bank = 1;
    rmcode.port = 0;
    rmcode.code = 0;
    sound_request_for_dc(&rmcode, 0);
}

void SsBgmFadeIn(u16 ReqNumber, u16 FadeSpeed) {
    SoundPatchConfig rmcode;
    s32 fade_time = 0x8000 / FadeSpeed;

    if (!(remake_sound_code_for_DC(ReqNumber, &rmcode)) && (rmcode.ptix == 0x7F)) {
        Store_Sound_Code(ReqNumber, &rmcode);
        rmcode.bank = 6;
        rmcode.port = fade_time;
        sound_request_for_dc(&rmcode, 0);
    }
}

void SsBgmFadeOut(u16 time) {
    SoundPatchConfig rmcode;
    s32 fade_time = 0x8000 / time;

    rmcode.ptix = 0x7F;
    rmcode.bank = 5;
    rmcode.code = 0;
    rmcode.port = fade_time;

    sound_request_for_dc(&rmcode, 0);
}

void SsBgmControl(s8 /* unused */, s8 VOLUME) {
    SoundPatchConfig rmcode;

    rmcode.ptix = 0x7F;
    rmcode.bank = 7;
    rmcode.code = 0;
    rmcode.port = VOLUME;

    if (rmcode.port < -0x7F) {
        rmcode.port = -0x7F;
    }

    if (rmcode.port > 0) {
        rmcode.port = 0;
    }

    sound_request_for_dc(&rmcode, 0);
}

void SsBgmHalfVolume(s16 flag) {
    SoundPatchConfig rmcode;

    bgm_half_down = flag;
    rmcode.ptix = 0x7F;
    rmcode.bank = 7;
    rmcode.code = 0;
    rmcode.port = 0;

    sound_request_for_dc(&rmcode, 0);
}

void SE_cursor_move() {
    SsRequest(96);
}

void SE_selected() {
    SsRequest(98);
}

void SE_dir_cursor_move() {
    SsRequest(343);
}

void SE_dir_selected() {
    SsRequest(98);
}

const s16 adx_volume[128] = { -999, -608, -576, -544, -512, -480, -448, -416, -400, -384, -368, -352, -336, -320, -304,
                              -288, -280, -272, -264, -256, -248, -240, -232, -224, -216, -208, -200, -192, -184, -176,
                              -168, -160, -156, -152, -148, -144, -140, -136, -132, -128, -124, -120, -116, -112, -108,
                              -104, -100, -96,  -94,  -92,  -90,  -88,  -86,  -84,  -82,  -80,  -78,  -76,  -74,  -72,
                              -70,  -68,  -66,  -64,  -63,  -62,  -61,  -60,  -59,  -58,  -57,  -56,  -55,  -54,  -53,
                              -52,  -51,  -50,  -49,  -48,  -47,  -46,  -45,  -44,  -43,  -42,  -41,  -40,  -39,  -38,
                              -37,  -36,  -35,  -34,  -33,  -32,  -31,  -30,  -29,  -28,  -27,  -26,  -25,  -24,  -23,
                              -22,  -21,  -20,  -19,  -18,  -17,  -16,  -15,  -14,  -13,  -12,  -11,  -10,  -9,   -8,
                              -7,   -6,   -5,   -4,   -3,   -2,   -1,   0 };
