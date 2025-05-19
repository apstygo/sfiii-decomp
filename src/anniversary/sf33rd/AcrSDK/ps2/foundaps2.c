#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "common.h"
#include "sf33rd/AcrSDK/MiddleWare/PS2/ADX/flADX.h"
#include "sf33rd/AcrSDK/MiddleWare/PS2/acrmw.h"
#include "sf33rd/AcrSDK/common/fbms.h"
#include "sf33rd/AcrSDK/common/memfound.h"
#include "sf33rd/AcrSDK/common/mlPAD.h"
#include "sf33rd/AcrSDK/common/prilay.h"
#include "sf33rd/AcrSDK/ps2/flps2asm.h"
#include "sf33rd/AcrSDK/ps2/flps2debug.h"
#include "sf33rd/AcrSDK/ps2/flps2dma.h"
#include "sf33rd/AcrSDK/ps2/flps2etc.h"
#include "sf33rd/AcrSDK/ps2/flps2render.h"
#include "sf33rd/AcrSDK/ps2/flps2vram.h"
#include "sf33rd/AcrSDK/ps2/ps2PAD.h"
#include "structs.h"

#include <eekernel.h>
#include <libcdvd.h>
#include <libdma.h>
#include <libgraph.h>
#include <libvu0.h>
#include <sifdev.h>
#include <sifprc.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if defined(TARGET_PS2)
#include "mw_stdarg.h"
#else
#include <stdarg.h>
#endif

static s32 system_work_init();
static s32 system_hard_init();
static void flPS2VramFullClear();
static void flPS2InitRenderBuff(u32 fbdepth, u32 zbdepth, u32 inter_mode, u32 video_mode, u32 dispw);
static void flPS2SwapDBuff(s32 dbi, s32 irq_type);
static void flPS2DrawPreparation();
void flPS2VSyncCallback();

// bss
FLPS2State flPs2State;
FLPS2DB flPs2Db[2];
FLPS2DrawStart flPs2DrawStart;
LPVram flVramControl[VRAM_CONTROL_SIZE];
FLTexture flTexture[256];
FLTexture flPalette[1088];
MTX flMATRIX[36];
s32 flDebugSysMem[4096];

// sbss
u32 flCTH;
s32 flCTNum;
s32 flWidth;
s32 flHeight;
s32 flFrame;
plContext flFrameBuf;
f64 flLoadAmount;
f32 flLoadReserve;
u32 flLoadCount;
f64 flLoadNow;
u32 flSystemRenderState;
u32 flSystemRenderOperation;
FL_FMS flFMS;
f32 flFogStart;
f32 flFogEnd;
u32 flFogColor;
u32 flAmbient;
u32 flFadeColor;
u32 flAlphaRefValue;
u32 flDebugFlag;
FLPS2VIF1Control flPs2VIF1Control;
s32 flPs2GsHandler;
LPVram *flVramList;
s32 flVramNum;
s32 flPTNum;
VRAMBlockHeader flVramStatic[3];
s32 flVramStaticNum;
u32 flMipmapL;
u32 flMipmapK;
u32 flTextureStage[1];
f32 flPS2Ambient[4];
f32 flPS2FadeColor[4];
MTX flPS2INITMATRIX;
MTX flACRVIEWPORT;
MTX flACRVIEWPROJ;
MTX flPS2VIEWPROJ;
MTX flPS2CLIPPROJ;
MTX flPS2VIEWPORT;
FLMaterial flMATERIAL[1];
FLLight flLIGHT[1];
f32 flPS2ATTENUATION1[1];
f32 flViewportDX;
f32 flViewportDY;
f32 flViewportDW;
f32 flViewportDH;
f32 flViewportCX;
f32 flViewportCY;
f32 flViewportLX;
f32 flViewportLY;
s32 flClayNum;
u32 flPs2FBA;
f32 flPS2FrameTexScaleX;
f32 flPS2FrameTexScaleY;
s32 flPS2FlipCancelFlag;
u32 flhDebugStr;
u32 flDebugStrHan;
s32 flDebugStrX;
s32 flDebugStrY;
u32 flDebugStrCol;
u32 flDebugStrCtr;
u32 flDebugTrueTime[DEBUG_TRUE_TIME_SIZE];
u32 flDebugEndRenderTime;
s32 flDebugECNum;
s32 flDebugErrECNum;
s32 flDebugUTNum;
s32 flDebugRTNum;
s32 flDebugMCNum;
s32 flDebugAQNum;
s32 flDebugDINum;
s32 flDebugVERTNum;
s32 flDebugPOLYNum;
s32 flDebugMATERIALNum;
u32 flDebugSysMemHandleNum;
u32 flDebugSysMemEtc;
u32 flDebugSysMemTexture;
u32 flDebugSysMemClay;
u32 flDebugSysMemMotion;
u32 flDebugTrueTimeFree[DEBUG_TRUE_TIME_SIZE];
s32 flLoadCheckCtr;
s32 flLoadCheckTimeOld;
u32 flLoadCheckTime[LOAD_CHECK_TIME_SIZE];
u32 flLoadCheckColor[20];

s32 flInitialize(s32 /* unused */, s32 /* unused */) {
    if (system_work_init() == 0) {
        return 0;
    }

    if (system_hard_init() == 0) {
        return 0;
    }

    flPS2SystemTmpBuffInit();
    flPs2State.FrameCount = 0;
    flPs2State.FrameCountNext = 0;
    flPs2State.Irq_count = 0;
    flPS2VramFullClear();
    flPS2InitRenderBuff(4, 2, 1, 0, 1);
    flPS2SwapDBuff(0, 1);
    flPADInitialize();
    flPS2DebugInit();

    while (1) {
        if ((flPs2State.Oddeven = sceGsSyncV(0)) == 0) {
            break;
        }
    }

    *T1_MODE = 0x80;
    *T1_COUNT = 0;

    return 1;
}

s32 system_work_init() {
    void *temp;

    flMemset(&flPs2State, 0, sizeof(FLPS2State));
    flPS2VramInit();
    temp = malloc(0x01800000);

    if (temp == NULL) {
        return 0;
    }

    fmsInitialize(&flFMS, temp, 0x01800000, 0x40);
    flPs2State.system_memory_size = 0xA00000;
    temp = flAllocMemoryS(flPs2State.system_memory_size);
    flPs2State.system_memory_start = (u32)temp;
    mflInit(temp, flPs2State.system_memory_size, 0x40);

    plmalloc = flAllocMemory;
    plfree = free;
    flLoadCount = 0x64;
    flPs2State.NowVu1Code = -1;
    flPs2State.NowVu1Size = 0;
    flSystemRenderState = 0x202;
    flSystemRenderOperation = 0x0138B032;
    flCTNum = 0;
    flPTNum = 0;
    flClayNum = 0;
    flPS2FlipCancelFlag = 0;

    return 1;
}

s32 system_hard_init() {
    s32 i;

    sceSifInitRpc(0);
    sceSifInitIopHeap();
    sceCdInit(SCECdINIT);
    sceCdMmode(SCECdDVD);

    while (1) {
        if (sceSifRebootIop("cdrom0:\\THIRD\\IOP\\IOPRP280.IMG;1") != 0) {
            break;
        }
    }

    while (1) {
        if (sceSifSyncIop() != 0) {
            break;
        }
    }

    sceSifInitRpc(0);
    sceSifInitIopHeap();
    sceCdInit(SCECdINIT);
    sceCdMmode(SCECdDVD);
    sceFsReset();
    flPS2IopModuleLoad("cdrom0:\\THIRD\\IOP\\MODULES\\SIO2MAN.IRX;1", 0, NULL, 0);
    flPS2PADModuleInit();
    flPS2IopModuleLoad("cdrom0:\\THIRD\\IOP\\MODULES\\MCMAN.IRX;1", 0, NULL, 0);
    flPS2IopModuleLoad("cdrom0:\\THIRD\\IOP\\MODULES\\MCSERV.IRX;1", 0, NULL, 0);
    flPS2IopModuleLoad("cdrom0:\\THIRD\\IOP\\MODULES\\LIBSD.IRX;1", 0, NULL, 0);
    flAdxModuleInit();
    flPS2IopModuleLoad("cdrom0:\\THIRD\\IOP\\MOD_MW\\CSELIB00.IRX;1", 0, NULL, 0);
    sceGsResetPath();
    sceDmaReset(1);

    for (i = 0; i < 10; i++) {
        flPs2State.DmaChan[i] = sceDmaGetChan(i);
    }

    sceVpu0Reset();
    flPs2VIF1Control.channel_id = 1;
    flPS2DmaInitControl(&flPs2VIF1Control, 0x1000, flPS2DmaInterrupt);

    return 1;
}

void flPS2VSyncCallback() {
    flPs2State.Irq_count += 1;

    if ((flPs2State.Irq_count > flPs2State.FrameCount) && (flPs2State.Db_change_enable == 1)) {
        flPs2State.FrameCount = flPs2State.FrameCountNext;
        flPs2State.Db_change_enable = 0;
        flPs2State.Dbi ^= 1;
        flPS2SwapDBuff(flPs2State.Dbi, 0);
    }

    flmwVSyncCallback();

#if defined(TARGET_PS2)
    ExitHandler();
#endif
}

u32 flPS2CheckDbChangeFlag() {
    return flPs2State.Db_change_enable != 0;
}

s32 flFlip(u32 flag) {
    flDebugTrueTime[2] = *T0_COUNT;

    if (flag == 0) {
        flPS2DispSystemInfo(2, 0);
    }

    flPS2DebugStrDisp();
    flDebugTrueTime[3] = *T0_COUNT;
    flPS2DmaWait();
    flmwFlip(flag);
    *T0_MODE = 0x83;
    *T0_COUNT = 0;
    flPs2State.Irq_count = 0;
    flFrame += 1;
    flPS2DmaSend();
    flPS2SystemTmpBuffFlush();
    flPS2DrawPreparation();
    flPs2State.NowVu1Code = -1;
    flPs2State.NowVu1Size = 0;

    return 1;
}

void flPS2VramFullClear() {
    u32 handle;
    u8 *lpBuff;
    u32 i;
    sceGsLoadImage Loadimage;

    i = 0;
    handle = flPS2GetSystemMemoryHandle(0x40000, 0);
    lpBuff = flPS2GetSystemBuffAdrs(handle);
    memzero_1q(lpBuff, 0x4000);

    do {
        sceGsSetDefLoadImage(&Loadimage, 0, 16, 0, 0, i * 64, 0x400, 0x40);

        FlushCache(0);
        sceGsExecLoadImage(&Loadimage, (u32 *)lpBuff);
        sceGsSyncPath(0, 0);

        i += 1;
    } while (i < 16);

    flPS2ReleaseSystemMemory(handle);
}

void flPS2InitRenderBuff(u32 fbdepth, u32 zbdepth, u32 inter_mode, u32 video_mode, u32 dispw) {
    FLPS2DB *db0;
    FLPS2DB *db1;
    FLPS2DrawStart *ds;
    u32 qwc;
    u32 size;
    s32 width;
    s32 height;
    s32 disp_height;

    flPs2State.VideoMode = video_mode;
    flPs2State.InterlaceMode = inter_mode;
    flPs2State.FrameBitDepth = fbdepth;
    flPs2State.ZBuffBitDepth = zbdepth;
    flPs2State.ScreenAdjustX = 0;
    flPs2State.ScreenAdjustY = 0;

    switch (dispw) {
    default:
    case 0:
        width = 0x280;
        flPs2State.MAGH = 3;
        break;
    case 1:
        width = 0x200;
        flPs2State.MAGH = 4;
        break;
    case 2:
        width = 0x180;
        flPs2State.MAGH = 6;
        break;
    }

    if (inter_mode == 0) {
        switch (video_mode) {
        default:
        case 0:
            sceGsResetGraph(0, 1, 2, 1);
            height = 0xE0;
            disp_height = 0x1C0;
            flPs2State.ScreenDispX = 0x27C;
            flPs2State.ScreenDispY = 0x32;
            break;
        case 1:
            sceGsResetGraph(0, 1, 3, 1);
            height = 0xE0;
            disp_height = 0x1C0;
            flPs2State.ScreenDispX = 0x290;
            flPs2State.ScreenDispY = 0x62;
            break;
        case 2:
            sceGsResetGraph(0, 1, 3, 1);
            height = 0x100;
            disp_height = 0x200;
            flPs2State.ScreenDispX = 0x290;
            flPs2State.ScreenDispY = 0x48;
            break;
        }
    } else {
        switch (video_mode) {
        default:
        case 0:
            sceGsResetGraph(0, 1, 2, 0);
            height = 0x1C0;
            disp_height = 0x1C0;
            flPs2State.ScreenDispX = 0x27C;
            flPs2State.ScreenDispY = 0x32;
            break;
        case 1:
            sceGsResetGraph(0, 1, 3, 0);
            height = 0x1C0;
            disp_height = 0x1C0;
            flPs2State.ScreenDispX = 0x290;
            flPs2State.ScreenDispY = 0x62;
            break;
        case 2:
            sceGsResetGraph(0, 1, 3, 0);
            height = 0x200;
            disp_height = 0x200;
            flPs2State.ScreenDispX = 0x290;
            flPs2State.ScreenDispY = 0x48;
            break;
        }
    }

    flWidth = width;
    flHeight = height;
    flPs2State.DispWidth = width;
    flPs2State.DispHeight = disp_height;

    switch (flPs2State.FrameBitDepth) {
    case 2:
        flPs2State.FrameBuffForm = 2;
        flPs2State.FrameBuffPageX = 0x40;
        flPs2State.FrameBuffPageY = 0x40;
        break;
    case 3:
        flPs2State.FrameBuffForm = 1;
        flPs2State.FrameBuffPageX = 0x40;
        flPs2State.FrameBuffPageY = 0x20;
        break;
    default:
    case 4:
        flPs2State.FrameBuffForm = 0;
        flPs2State.FrameBuffPageX = 0x40;
        flPs2State.FrameBuffPageY = 0x20;
        break;
    }

    size = fbdepth *
           (flPs2State.FrameBuffPageY *
            ((((height + flPs2State.FrameBuffPageY) - 1) / flPs2State.FrameBuffPageY) *
             (flPs2State.FrameBuffPageX * (((width + flPs2State.FrameBuffPageX) - 1) / flPs2State.FrameBuffPageX))));
    flPs2State.FrameBuffAdrs0 = flPS2GetStaticVramArea(size);
    flPs2State.FrameBuffAdrs1 = flPS2GetStaticVramArea(size);

    switch (flPs2State.ZBuffBitDepth) {
    case 2:
        if (flPs2State.FrameBitDepth == 2) {
            flPs2State.ZBuffForm = 0x32;
        } else {
            flPs2State.ZBuffForm = 0x3A;
        }

        flPs2State.ZBuffPageX = 0x40;
        flPs2State.ZBuffPageY = 0x40;
        flPs2State.ZBuffMax = (f32)65535;
        break;

    case 3:
        flPs2State.ZBuffForm = 0x31;
        flPs2State.ZBuffPageX = 0x40;
        flPs2State.ZBuffPageY = 0x20;
        flPs2State.ZBuffMax = 1.6777e7f;
        break;

    default:
    case 4:
        if (flPs2State.FrameBitDepth == 2) {
            flPs2State.FrameBuffForm = 0xA;
        }

        flPs2State.ZBuffForm = 0x30;
        flPs2State.ZBuffPageX = 0x40;
        flPs2State.ZBuffPageY = 0x20;
        flPs2State.ZBuffMax = 1.6777e7f;
        break;
    }

    size = zbdepth * (flPs2State.ZBuffPageX * (((width + flPs2State.ZBuffPageX) - 1) / flPs2State.ZBuffPageX) *
                      (flPs2State.ZBuffPageY * (((height + flPs2State.ZBuffPageY) - 1) / flPs2State.ZBuffPageY)));
    flPs2State.ZBuffAdrs = flPS2GetStaticVramArea(size);
    flPs2State.D2dOffsetX = 0x800 - (width >> 1);
    flPs2State.D2dOffsetY = 0x800 - (height >> 1);
    flPs2State.ScreenOffsetX = 0;
    flPs2State.ScreenOffsetY = 0;
    flFrameBuf.width = width;
    flFrameBuf.height = height;
    flFrameBuf.ptr = NULL;
    flFrameBuf.bitdepth = flPs2State.FrameBitDepth;
    qwc = width * flPs2State.FrameBitDepth;
    flFrameBuf.pitch = qwc;
    flFrameBuf.desc = 0;

    switch (flPs2State.FrameBitDepth) {
    case 2:
        flFrameBuf.pixelformat.rl = 5;
        flFrameBuf.pixelformat.rs = qwc = 0xA;
        flFrameBuf.pixelformat.rm = 0x1F;
        flFrameBuf.pixelformat.gl = 5;
        flFrameBuf.pixelformat.gs = 5;
        flFrameBuf.pixelformat.gm = 0x1F;
        flFrameBuf.pixelformat.bl = 5;
        flFrameBuf.pixelformat.bs = 0;
        flFrameBuf.pixelformat.bm = 0x1F;
        flFrameBuf.pixelformat.al = 1;
        flFrameBuf.pixelformat.as = 0xF;
        flFrameBuf.pixelformat.am = 1;
        flFrameBuf.pixelformat.rs = 0;
        flFrameBuf.pixelformat.bs = 0xA;
        flFrameBuf.pixelformat.gl = 5;
        flFrameBuf.pixelformat.gm = 0x1F;
        break;

    case 3:
        flFrameBuf.pixelformat.rl = 8;
        flFrameBuf.pixelformat.rs = 0x10;
        flFrameBuf.pixelformat.rm = 0xFF;
        flFrameBuf.pixelformat.gl = 8;
        flFrameBuf.pixelformat.gs = 8;
        flFrameBuf.pixelformat.gm = 0xFF;
        flFrameBuf.pixelformat.bl = 8;
        flFrameBuf.pixelformat.bs = 0;
        flFrameBuf.pixelformat.bm = 0xFF;
        flFrameBuf.pixelformat.al = 0;
        flFrameBuf.pixelformat.as = 0;
        flFrameBuf.pixelformat.am = 0;
        flFrameBuf.pixelformat.rs = 0;
        flFrameBuf.pixelformat.bs = 0x10;
        break;

    case 4:
        flFrameBuf.pixelformat.rl = 8;
        flFrameBuf.pixelformat.rs = 0x10;
        flFrameBuf.pixelformat.rm = 0xFF;
        flFrameBuf.pixelformat.gl = 8;
        flFrameBuf.pixelformat.gs = 8;
        flFrameBuf.pixelformat.gm = 0xFF;
        flFrameBuf.pixelformat.bl = 8;
        flFrameBuf.pixelformat.bs = 0;
        flFrameBuf.pixelformat.bm = 0xFF;
        flFrameBuf.pixelformat.al = 8;
        flFrameBuf.pixelformat.as = 0x18;
        flFrameBuf.pixelformat.am = 0xFF;
        flFrameBuf.pixelformat.rs = 0;
        flFrameBuf.pixelformat.bs = 0x10;
        break;
    }

    flPS2InitRenderState();
    flPs2State.Dbi = 0;
    flPs2State.Oddeven = 1;

    db0 = &flPs2Db[0];
    db1 = &flPs2Db[1];
    qwc = 9;

    flPS2DmaAddEndTag((u32)db0, qwc, 0, 0);
    flPS2DmaAddEndTag((u32)db1, qwc, 0, 0);

    qwc -= 1;
    db0->giftag.I64[0] = SCE_GIF_SET_TAG(qwc, 1, 0, 0, 0, 1);
    db0->giftag.I64[1] = SCE_GIF_PACKED_AD;
    db1->giftag.I64[0] = SCE_GIF_SET_TAG(qwc, 1, 0, 0, 0, 1);
    db1->giftag.I64[1] = SCE_GIF_PACKED_AD;
    db0->frame_1.I64[0] = SCE_GS_SET_FRAME_1(flPs2State.FrameBuffAdrs1 / 32, flWidth / 64, flPs2State.FrameBuffForm, 1);
    db0->frame_2.I64[0] = SCE_GS_SET_FRAME_2(flPs2State.FrameBuffAdrs1 / 32, flWidth / 64, flPs2State.FrameBuffForm, 1);
    db0->frame_1.I64[1] = SCE_GS_FRAME_1;
    db0->frame_2.I64[1] = SCE_GS_FRAME_2;
    db1->frame_1.I64[0] = SCE_GS_SET_FRAME_1(flPs2State.FrameBuffAdrs0 / 32, flWidth / 64, flPs2State.FrameBuffForm, 1);
    db1->frame_2.I64[0] = SCE_GS_SET_FRAME_2(flPs2State.FrameBuffAdrs0 / 32, flWidth / 64, flPs2State.FrameBuffForm, 1);
    db1->frame_1.I64[1] = SCE_GS_FRAME_1;
    db1->frame_2.I64[1] = SCE_GS_FRAME_2;
    db0->zbuf_1.I64[0] = SCE_GS_SET_ZBUF_1(flPs2State.ZBuffAdrs / 32, flPs2State.ZBuffForm, 0);
    db0->zbuf_2.I64[0] = SCE_GS_SET_ZBUF_2(flPs2State.ZBuffAdrs / 32, flPs2State.ZBuffForm, 0);
    db0->zbuf_1.I64[1] = SCE_GS_ZBUF_1;
    db0->zbuf_2.I64[1] = SCE_GS_ZBUF_2;
    db1->zbuf_1.I64[0] = SCE_GS_SET_ZBUF_1(flPs2State.ZBuffAdrs / 32, flPs2State.ZBuffForm, 0);
    db1->zbuf_2.I64[0] = SCE_GS_SET_ZBUF_2(flPs2State.ZBuffAdrs / 32, flPs2State.ZBuffForm, 0);
    db1->zbuf_1.I64[1] = SCE_GS_ZBUF_1;
    db1->zbuf_2.I64[1] = SCE_GS_ZBUF_2;
    db0->xyoffset_1.I64[0] = SCE_GS_SET_XYOFFSET_1(flPs2State.D2dOffsetX * 16, flPs2State.D2dOffsetY * 16);
    db0->xyoffset_2.I64[0] = SCE_GS_SET_XYOFFSET_2(flPs2State.D2dOffsetX * 16, flPs2State.D2dOffsetY * 16);
    db0->xyoffset_1.I64[1] = SCE_GS_XYOFFSET_1;
    db0->xyoffset_2.I64[1] = SCE_GS_XYOFFSET_2;
    db1->xyoffset_1.I64[0] = SCE_GS_SET_XYOFFSET_1(flPs2State.D2dOffsetX * 16, flPs2State.D2dOffsetY * 16);
    db1->xyoffset_2.I64[0] = SCE_GS_SET_XYOFFSET_2(flPs2State.D2dOffsetX * 16, flPs2State.D2dOffsetY * 16);
    db1->xyoffset_1.I64[1] = SCE_GS_XYOFFSET_1;
    db1->xyoffset_2.I64[1] = SCE_GS_XYOFFSET_2;

    if (flPs2State.FrameBitDepth == 2) {
        db0->dthe.I64[0] = 1;
        db1->dthe.I64[0] = 1;
    } else {
        db0->dthe.I64[0] = 0;
        db1->dthe.I64[0] = 0;
    }

    db0->dthe.I64[1] = SCE_GS_DTHE;
    db1->dthe.I64[1] = SCE_GS_DTHE;
    db0->colclamp.I64[0] = SCE_GS_SET_COLCLAMP(1);
    db1->colclamp.I64[0] = SCE_GS_SET_COLCLAMP(1);
    db0->colclamp.I64[1] = SCE_GS_COLCLAMP;
    db1->colclamp.I64[1] = SCE_GS_COLCLAMP;

    ds = &flPs2DrawStart;
    qwc = 19;
    flPS2DmaAddEndTag((u32)ds, qwc, 1, 0);

    ds->dmatag.I32[2] = 0x13000000;
    ds->dmatag.I32[3] = qwc | 0x51000000;

    qwc -= 1;
    ds->giftag.I64[0] = SCE_GIF_SET_TAG(qwc, 1, 0, 0, 0, 1);
    ds->giftag.I64[1] = SCE_GIF_PACKED_AD;
    ds->clr_fba.I64[0] = SCE_GS_SET_FBA_1(0);
    ds->clr_fba.I64[1] = SCE_GS_FBA_1;
    ds->clr_scissor.I64[0] = SCE_GS_SET_SCISSOR_1(0, 0, 0, 0);
    ds->clr_scissor.I64[1] = SCE_GS_SCISSOR_1;
    ds->clr_test.I64[0] = SCE_GS_SET_TEST_1(1, 1, 0, 0, 0, 0, 3, 0);
    ds->clr_test.I64[1] = SCE_GS_TEST_1;
    ds->clr_prim.I64[0] = SCE_GS_SET_PRIM(6, 0, 0, 0, 0, 0, 0, 0, 0);
    ds->clr_prim.I64[1] = SCE_GS_PRIM;
    ds->clr_rgbaq.I64[0] = SCE_GS_SET_RGBAQ(0, 0, 0, 0, 0);
    ds->clr_rgbaq.I64[1] = SCE_GS_RGBAQ;
    ds->clr_xyz2_0.I64[0] = SCE_GS_SET_XYZ2(0, 0, 0);
    ds->clr_xyz2_0.I64[1] = SCE_GS_XYZ2;
    ds->clr_xyz2_1.I64[0] = SCE_GS_SET_XYZ2(0, 0, 0);
    ds->clr_xyz2_1.I64[1] = SCE_GS_XYZ2;
    ds->acr_scissor_1.I64[0] = 0;
    ds->acr_scissor_1.I64[1] = SCE_GS_SCISSOR_1;
    ds->acr_scissor_2.I64[0] = 0;
    ds->acr_scissor_2.I64[1] = SCE_GS_SCISSOR_2;
    ds->acr_test_1.I64[0] = 0;
    ds->acr_test_1.I64[1] = SCE_GS_TEST_1;
    ds->acr_test_2.I64[0] = 0;
    ds->acr_test_2.I64[1] = SCE_GS_TEST_2;
    ds->acr_zbuf_1.I64[0] = 0;
    ds->acr_zbuf_1.I64[1] = SCE_GS_ZBUF_1;
    ds->acr_zbuf_2.I64[0] = 0;
    ds->acr_zbuf_2.I64[1] = SCE_GS_ZBUF_2;
    ds->acr_fba_1.I64[0] = 0;
    ds->acr_fba_1.I64[1] = SCE_GS_FBA_1;
    ds->acr_fba_2.I64[0] = 0;
    ds->acr_fba_2.I64[1] = SCE_GS_FBA_2;
    ds->acr_pabe.I64[0] = 0;
    ds->acr_pabe.I64[1] = SCE_GS_PABE;
    ds->acr_prmodecont.I64[0] = 1;
    ds->acr_prmodecont.I64[1] = SCE_GS_PRMODECONT;
    ds->acr_dimx.I64[0] = SCE_GS_SET_DIMX(4, 2, 5, 3, 0, 6, 1, 7, 5, 3, 4, 2, 1, 7, 0, 6);
    ds->acr_dimx.I64[1] = SCE_GS_DIMX;
    sceGsSyncVCallback((s32 (*)(s32))flPS2VSyncCallback);
}

void flPS2SwapDBuff(s32 dbi, s32 irq_type) {
    FLPS2DB *db;
    s32 disp_x;
    s32 disp_y;

    db = &flPs2Db[dbi];

    if (flPs2State.InterlaceMode != 1) {
        if (flPs2State.Oddeven == 1) {
            db->xyoffset_1.I64[0] = SCE_GS_SET_XYOFFSET_1(flPs2State.D2dOffsetX * 0x10, flPs2State.D2dOffsetY * 0x10);
            db->xyoffset_2.I64[0] = SCE_GS_SET_XYOFFSET_2(flPs2State.D2dOffsetX * 0x10, flPs2State.D2dOffsetY * 0x10);
        } else {
            db->xyoffset_1.I64[0] =
                SCE_GS_SET_XYOFFSET_1(flPs2State.D2dOffsetX * 0x10, flPs2State.D2dOffsetY * 0x10 + 8);
            db->xyoffset_2.I64[0] =
                SCE_GS_SET_XYOFFSET_2(flPs2State.D2dOffsetX * 0x10, flPs2State.D2dOffsetY * 0x10 + 8);
        }
    }

    if (irq_type == 0) {
        iFlushCache(0);
    } else {
        FlushCache(0);
    }

    sceDmaSend(flPs2State.DmaChan[2], db);

    while (1) {
        if (sceDmaSync(flPs2State.DmaChan[2], 1, 0) == 0) {
            break;
        }
    }

    disp_x = flPs2State.ScreenDispX + flPs2State.ScreenAdjustX * flPs2State.MAGH;
    disp_y = flPs2State.ScreenDispY + flPs2State.ScreenAdjustY;

    if (flPs2State.InterlaceMode == 0) {
        *GS_SMODE2 = SCE_GS_SET_SMODE2(1, 1, 0);
        *GS_PMODE = SCE_GS_SET_PMODE(0, 1, 1, 1, 1, 0, 0);

        if (dbi == 0) {
            *GS_DISPFB2 =
                SCE_GS_SET_DISPFB2(flPs2State.FrameBuffAdrs0 / 32, flWidth / 64, flPs2State.FrameBuffForm, 0, 0);
        } else {
            *GS_DISPFB2 =
                SCE_GS_SET_DISPFB2(flPs2State.FrameBuffAdrs1 / 32, flWidth / 64, flPs2State.FrameBuffForm, 0, 0);
        }

        *GS_DISPLAY2 = SCE_GS_SET_DISPLAY1(disp_x, disp_y, flPs2State.MAGH, 0, 0x9FF, (flPs2State.DispHeight - 1));
    } else if (flPs2State.DisplayMode == 0) {
        *GS_SMODE2 = SCE_GS_SET_SMODE2(1, 0, 0);
        *GS_PMODE = SCE_GS_SET_PMODE(1, 1, 1, 1, 0, 0, 0x7F);

        if (dbi == 0) {
            *GS_DISPFB1 =
                SCE_GS_SET_DISPFB1(flPs2State.FrameBuffAdrs0 / 32, flWidth / 64, flPs2State.FrameBuffForm, 0, 0);
            *GS_DISPFB2 =
                SCE_GS_SET_DISPFB2(flPs2State.FrameBuffAdrs0 / 32, flWidth / 64, flPs2State.FrameBuffForm, 0, 0);
        } else {
            *GS_DISPFB1 =
                SCE_GS_SET_DISPFB1(flPs2State.FrameBuffAdrs1 / 32, flWidth / 64, flPs2State.FrameBuffForm, 0, 0);
            *GS_DISPFB2 =
                SCE_GS_SET_DISPFB2(flPs2State.FrameBuffAdrs1 / 32, flWidth / 64, flPs2State.FrameBuffForm, 0, 0);
            ;
        }

        *GS_DISPLAY1 = SCE_GS_SET_DISPLAY1(disp_x, disp_y + 1, flPs2State.MAGH, 0, 0x9FF, (flPs2State.DispHeight - 1));
        *GS_DISPLAY2 = SCE_GS_SET_DISPLAY2(disp_x, disp_y, flPs2State.MAGH, 0, 0x9FF, (flPs2State.DispHeight - 1));
    } else {
        *GS_SMODE2 = SCE_GS_SET_SMODE2(1, 0, 0);
        *GS_PMODE = SCE_GS_SET_PMODE(0, 1, 1, 1, 1, 0, 0);

        if (dbi == 0) {
            *GS_DISPFB2 =
                SCE_GS_SET_DISPFB2(flPs2State.FrameBuffAdrs0 / 32, flWidth / 64, flPs2State.FrameBuffForm, 0, 0);
        } else {
            *GS_DISPFB2 =
                SCE_GS_SET_DISPFB2(flPs2State.FrameBuffAdrs1 / 32, flWidth / 64, flPs2State.FrameBuffForm, 0, 0);
        }

        *GS_DISPLAY2 = SCE_GS_SET_DISPLAY2(disp_x, disp_y, flPs2State.MAGH, 0, 0x9FF, (flPs2State.DispHeight - 1));
    }

    *GS_EXTWRITE = SCE_GS_SET_EXTWRITE(0);
}

void flPS2DrawPreparation() {
    FLPS2DrawStart *ds;
    u32 *dst;

    ds = &flPs2DrawStart;

    ds->clr_scissor.I64[0] = SCE_GS_SET_SCISSOR(0, flWidth - 1, 0, flHeight - 1);
    ds->clr_rgbaq.I64[0] = SCE_GS_SET_RGBAQ((flPs2State.FrameClearColor >> 16) & 0xFF,
                                            (flPs2State.FrameClearColor >> 8) & 0xFF,
                                            flPs2State.FrameClearColor & 0xFF,
                                            (flPs2State.FrameClearColor >> 24) & 0xFF,
                                            1);
    ds->clr_xyz2_0.I64[0] = SCE_GS_SET_XYZ(flPs2State.D2dOffsetX * 16, flPs2State.D2dOffsetY * 16, 0);
    ds->clr_xyz2_1.I64[0] =
        SCE_GS_SET_XYZ((flPs2State.D2dOffsetX + flWidth) * 16, (flPs2State.D2dOffsetY + flHeight) * 16, 0);
    ds->acr_scissor_1.I64[0] = flPs2State.RenderSCISSORStatus1;
    ds->acr_scissor_2.I64[0] = flPs2State.RenderSCISSORStatus2;
    ds->acr_test_1.I64[0] = flPs2State.RenderTESTStatus1;
    ds->acr_test_2.I64[0] = flPs2State.RenderTESTStatus2;
    ds->acr_zbuf_1.I64[0] = flPs2State.RenderZBUFStatus1;
    ds->acr_zbuf_2.I64[0] = flPs2State.RenderZBUFStatus2;
    ds->acr_fba_1.I64[0] = flPs2FBA;
    ds->acr_fba_2.I64[0] = flPs2FBA;

    dst = (u32 *)flPS2GetSystemTmpBuff(sizeof(FLPS2DrawStart), 0x10);
    memcpy_1q(ds, dst, 0x14);
    flPS2DmaAddQueue2(0, (u32)dst & 0xFFFFFFF, (u32)dst, &flPs2VIF1Control);
}

s32 flLogOut(s8 *format, ...) {
    s8 *va_ptr;
    s8 str[2048];
    s8 *lp;
    static s32 bflLogOutFirst = 1;

    va_list args;
    va_start(args, format);

    vsprintf(str, format, args);
    lp = strlen(str) + str;
    *(lp++) = 0xD;
    *(lp++) = 0xA;
    *lp = 0;

    if (bflLogOutFirst != 0) {
        flFileWrite("../acrout.txt", "Debug Message Output for PS2\r\n", strlen("Debug Message Output for PS2\r\n"));
        bflLogOutFirst = 0;
    }

    flFileAppend("../acrout.txt", str, strlen(str));
    va_end(args);

    return 1;
}

void flInitPhaseStarted() {
    flPs2State.SystemStatus = 0;
}

void flInitPhaseFinished() {
    flPs2State.SystemStatus = 2;
}
