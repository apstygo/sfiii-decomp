#include "sf33rd/AcrSDK/ps2/flps2render.h"
#include "common.h"
#include "sf33rd/AcrSDK/ps2/flps2debug.h"
#include "sf33rd/AcrSDK/ps2/flps2dma.h"
#include "sf33rd/AcrSDK/ps2/flps2etc.h"
#include "sf33rd/AcrSDK/ps2/flps2ps.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"

s32 flBeginRender() {
    flDebugTrueTime[0] = *T0_COUNT;
    flLoadNow = flGetSystemTime();

    if (flLoadCount-- == 0) {
        flLoadCount = 100;
        flLoadReserve = (f32)flLoadAmount / 100.0f;
        flLoadAmount = 0;
    }

    flPs2State.SystemStatus = 1;
    return 1;
}

s32 flEndRender() {
    flDebugTrueTime[1] = *T0_COUNT;
    flLoadNow = flGetSystemTime() - flLoadNow;
    flLoadAmount = flLoadAmount + flLoadNow;
    flPs2State.SystemStatus = 2;

    return 1;
}

s32 flPS2InitRenderState() {
    s32 wk0;

    flInitPhaseStarted();
    flPS2SendRenderState_ALPHA(flSystemRenderOperation, 2);
    flPS2SendRenderState_TEST(flSystemRenderOperation, 2);
    flPS2SendRenderState_ZBUF(flSystemRenderOperation, 2);
    flPS2SendRenderState_SCISSOR(0, 0, flWidth, flHeight, 2);
    flPS2SendRenderState_FOGCOL(flFogColor);
    flPS2SendRenderState_TEX1(flSystemRenderOperation, 0U);
    flPs2FBA = 0;
    flInitPhaseFinished();

    for (wk0 = 0; flWidth > (1 << wk0); wk0++) {}
    flPS2FrameTexScaleX = (f32)flWidth / (f32)(1 << wk0);
    for (wk0 = 0; flHeight > (1 << wk0); wk0++) {}
    flPS2FrameTexScaleY = (f32)flHeight / (1 << wk0);
    flPS2INITMATRIX.m._11 = 1.0f;
    flPS2INITMATRIX.m._12 = 0.0f;
    flPS2INITMATRIX.m._13 = 0.0f;
    flPS2INITMATRIX.m._14 = 0.0f;
    flPS2INITMATRIX.m._21 = 0.0f;
    flPS2INITMATRIX.m._22 = 1.0f;
    flPS2INITMATRIX.m._23 = 0.0f;
    flPS2INITMATRIX.m._24 = 0.0f;
    flPS2INITMATRIX.m._31 = 0.0f;
    flPS2INITMATRIX.m._32 = 0.0f;
    flPS2INITMATRIX.m._33 = 1.0f;
    flPS2INITMATRIX.m._34 = 0.0f;
    flPS2INITMATRIX.m._41 = 0.0f;
    flPS2INITMATRIX.m._42 = 0.0f;
    flPS2INITMATRIX.m._43 = 0.0f;
    flPS2INITMATRIX.m._44 = 1.0f;

    return 1;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2render", flSetRenderState);
#else
s32 flSetRenderState(enum _FLSETRENDERSTATE func, u32 value) {
    not_implemented(__func__);
}
#endif

void flPS2SetClearColor(u32 col) {
    flPs2State.FrameClearColor = col;
}

s32 flPS2SendRenderState_SCISSOR(s32 dx, s32 dy, s32 dw, s32 dh, u32 flag) {
    s32 dx2;
    s32 dy2;
    u32 qwc;
    u32 keep_ptr;
    QWORD *lpWork;

    if (dx < 0) {
        dx = 0;
    }

    if ((dx + dw) > flWidth) {
        dw = flWidth - dx;
    }

    dx2 = (dx + dw) - 1;
    if (dy < 0) {
        dy = 0;
    }

    if ((dy + dh) > flHeight) {
        dh = flHeight - dy;
    }

    dy2 = (dy + dh) - 1;
    if (flag != 2) {
        lpWork = (QWORD *)flPS2GetSystemTmpBuff(0x30, 0x10);
        qwc = 2;
    } else {
        lpWork = (QWORD *)flPS2GetSystemTmpBuff(0x40, 0x10);
        qwc = 3;
    }

    keep_ptr = (u32)lpWork;
    lpWork->UI64[0] = (qwc + 0x70000000) | 0x80000000;
    lpWork->UI32[2] = 0x13000000;
    lpWork->UI32[3] = (qwc | 0x50000000);

    lpWork++;
    lpWork->UI64[0] = SCE_GIF_SET_TAG(qwc - 1, 1, 0, 0, SCE_GIF_PACKED, 1);
    lpWork->UI64[1] = SCE_GIF_PACKED_AD;

    lpWork++;
    switch (flag) {
    case 0:
        flPs2State.RenderSCISSORValue1[0] = dx;
        flPs2State.RenderSCISSORValue1[1] = dy;
        flPs2State.RenderSCISSORValue1[2] = dx2;
        flPs2State.RenderSCISSORValue1[3] = dy2;
        flPs2State.RenderSCISSORStatus1 = SCE_GS_SET_SCISSOR(dx, dx2, dy, dy2);

        lpWork->UI64[0] = SCE_GS_SET_SCISSOR(dx, dx2, dy, dy2);
        lpWork->UI64[1] = SCE_GS_SCISSOR_1;
        break;

    case 1:
        flPs2State.RenderSCISSORValue2[0] = dx;
        flPs2State.RenderSCISSORValue2[1] = dy;
        flPs2State.RenderSCISSORValue2[2] = dx2;
        flPs2State.RenderSCISSORValue2[3] = dy2;
        flPs2State.RenderSCISSORStatus2 = SCE_GS_SET_SCISSOR(dx, dx2, dy, dy2);

        lpWork->UI64[0] = SCE_GS_SET_SCISSOR(dx, dx2, dy, dy2);
        lpWork->UI64[1] = SCE_GS_SCISSOR_2;
        break;

    case 2:
        flPs2State.RenderSCISSORValue1[0] = dx;
        flPs2State.RenderSCISSORValue1[1] = dy;
        flPs2State.RenderSCISSORValue1[2] = dx2;
        flPs2State.RenderSCISSORValue1[3] = dy2;
        flPs2State.RenderSCISSORStatus1 = SCE_GS_SET_SCISSOR(dx, dx2, dy, dy2);

        flPs2State.RenderSCISSORValue2[0] = dx;
        flPs2State.RenderSCISSORValue2[1] = dy;
        flPs2State.RenderSCISSORValue2[2] = dx2;
        flPs2State.RenderSCISSORValue2[3] = dy2;
        flPs2State.RenderSCISSORStatus2 = SCE_GS_SET_SCISSOR(dx, dx2, dy, dy2);

        lpWork->UI64[0] = SCE_GS_SET_SCISSOR(dx, dx2, dy, dy2);
        lpWork->UI64[1] = SCE_GS_SCISSOR_1;

        lpWork++;
        lpWork->UI64[0] = SCE_GS_SET_SCISSOR(dx, dx2, dy, dy2);
        lpWork->UI64[1] = SCE_GS_SCISSOR_2;
        break;
    }

    flPS2DmaAddQueue2(0, (keep_ptr & 0xFFFFFFF), keep_ptr, &flPs2VIF1Control);
    return 1;
}

s32 flPS2SendRenderState_ZBUF(u32 render_state, u32 flag) {
    u32 qwc;
    u32 keep_ptr;
    s32 zbp;
    s32 psm;
    s32 zmsk;
    u_long zbuf;
    QWORD *lpWork;

    if ((render_state & 0x8000) == 0x8000) {
        zmsk = 0;
    } else {
        zmsk = 1;
    }

    zbp = flPs2State.ZBuffAdrs >> 5;
    psm = flPs2State.ZBuffForm;
    zbuf = SCE_GS_SET_ZBUF(zbp, psm, zmsk);

    if (flag != 2) {
        lpWork = (QWORD *)flPS2GetSystemTmpBuff(0x30, 0x10);
        qwc = 2;
    } else {
        lpWork = (QWORD *)flPS2GetSystemTmpBuff(0x40, 0x10);
        qwc = 3;
    }

    keep_ptr = (u32)lpWork;
    lpWork->UI64[0] = (qwc + 0x70000000) | 0x80000000;
    lpWork->UI32[2] = 0x13000000;
    lpWork->UI32[3] = (qwc | 0x50000000);

    lpWork++;
    lpWork->UI64[0] = SCE_GIF_SET_TAG(qwc - 1, 1, 0, 0, SCE_GIF_PACKED, 1);
    lpWork->UI64[1] = SCE_GIF_PACKED_AD;

    lpWork++;
    switch (flag) {
    case 0:
        lpWork->UI64[0] = flPs2State.RenderZBUFStatus1 = zbuf;
        lpWork->UI64[1] = SCE_GS_ZBUF_1;
        break;

    case 1:
        lpWork->UI64[0] = flPs2State.RenderZBUFStatus2 = zbuf;
        lpWork->UI64[1] = SCE_GS_ZBUF_2;
        break;

    case 2:
        lpWork->UI64[0] = flPs2State.RenderZBUFStatus2 = flPs2State.RenderZBUFStatus1 = zbuf;
        lpWork->UI64[1] = SCE_GS_ZBUF_1;

        lpWork++;
        lpWork->UI64[0] = zbuf;
        lpWork->UI64[1] = SCE_GS_ZBUF_2;
        break;
    }

    flPS2DmaAddQueue2(0, (keep_ptr & 0xFFFFFFF), keep_ptr, &flPs2VIF1Control);
    return 1;
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2render", flPS2SendRenderState_TEST);
#else
s32 flPS2SendRenderState_TEST(u32 render_state, u32 flag) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2render", flPS2SendRenderState_ALPHA);
#else
s32 flPS2SendRenderState_ALPHA(u32 render_state, u32 flag) {
    not_implemented(__func__);
}
#endif

s32 flPS2SendRenderState_FOGCOL(u32 fogcol) {
    u32 qwc;
    u32 keep_ptr;
    QWORD *lpWork;

    lpWork = (QWORD *)flPS2GetSystemTmpBuff(0x30, 0x10);
    qwc = 2;
    keep_ptr = (u32)lpWork;

    lpWork->UI64[0] = (qwc + 0x70000000) | 0x80000000;
    lpWork->UI32[2] = 0x13000000;
    lpWork->UI32[3] = qwc | 0x51000000;

    lpWork++;
    lpWork->UI64[0] = SCE_GIF_SET_TAG(qwc - 1, 1, 0, 0, SCE_GIF_PACKED, 1);
    lpWork->UI64[1] = SCE_GIF_PACKED_AD;

    lpWork++;
    lpWork->UI64[0] = SCE_GS_SET_FOGCOL((fogcol >> 16) & 0xFF, (fogcol >> 8) & 0xFF, fogcol & 0xFF);
    lpWork->UI64[1] = SCE_GS_FOGCOL;

    flPS2DmaAddQueue2(0, (keep_ptr & 0xFFFFFFF), keep_ptr, &flPs2VIF1Control);
    return 1;
}

s32 flPS2SendRenderState_TEX1(u32 render_state, u32 flag) {
    u32 qwc;
    u32 keep_ptr;
    QWORD *lpWork;

    lpWork = (QWORD *)flPS2GetSystemTmpBuff(0x30, 0x10);
    qwc = 2;
    keep_ptr = (u32)lpWork;

    lpWork->UI64[0] = (qwc + 0x70000000) | 0x80000000;
    lpWork->UI32[2] = 0x13000000;
    lpWork->UI32[3] = qwc | 0x50000000;

    lpWork++;
    lpWork->UI64[0] = (u_long)(qwc - 1) | 0x8000 | 0x1000000000000000;
    lpWork->UI64[1] = 0xE;

    lpWork++;
    if ((render_state & 0x10000) == 0x10000) {
        lpWork->UI64[0] = 0;
    } else {
        lpWork->UI64[0] = 0x60;
    }

    if (flag == 0) {
        lpWork->UI64[1] = 0x14;
    } else {
        lpWork->UI64[1] = 0x15;
    }

    flPS2DmaAddQueue2(0, (keep_ptr & 0xFFFFFFF), keep_ptr, &flPs2VIF1Control);
    return 1;
}

s32 flPS2SendTextureRegister(u32 th) {
    static u64 psTexture_data[16] = {
        0x0000000070000007, 0x0000000000000000, 0x1000000000008006, 0x000000000000000E,
        0x0000000000000000, 0x000000000000003B, 0x0000000000000000, 0x0000000000000014,
        0x0000000000000000, 0x0000000000000006, 0x0000000000000000, 0x0000000000000008,
        0x0000000000000000, 0x0000000000000034, 0x0000000000000000, 0x0000000000000036,
    };

    if (!flPS2SetTextureRegister(th,
                                 &psTexture_data[4],
                                 &psTexture_data[6],
                                 &psTexture_data[8],
                                 &psTexture_data[10],
                                 &psTexture_data[12],
                                 &psTexture_data[14],
                                 flSystemRenderOperation)) {
        return 0;
    }

    flPS2psAddQueue((QWORD *)psTexture_data);
    return 1;
}

#if defined(TARGET_PS2)
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2render", literal_876_0055F1B0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2render", literal_877_0055F1E0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2render", flPS2SetTextureRegister);
#else
s32 flPS2SetTextureRegister(u32 th, u64 *texA, u64 *tex1, u64 *tex0, u64 *clamp, u64 *miptbp1, u64 *miptbp2,
                            u32 render_ope) {
    not_implemented(__func__);
}
#endif

s16 flPS2ConvScreenX(s16 x) {
    x -= flPs2State.ScreenOffsetX;

    return x;
}

s16 flPS2ConvScreenY(s16 y) {
    y -= flPs2State.ScreenOffsetY;

    if (flPs2State.InterlaceMode == 0) {
        y >>= 1;
    }

    return y;
}

f32 flPS2ConvScreenFX(f32 x) {
    x -= flPs2State.ScreenOffsetX;

    return x;
}

f32 flPS2ConvScreenFY(f32 y) {
    y -= flPs2State.ScreenOffsetY;

    if (flPs2State.InterlaceMode == 0) {
        y = y * 0.5f;
    }

    return y;
}

f32 flPS2ConvScreenFZ(f32 z) {
    z -= 1.0f;
    z = z * -0.5f;
    z *= flPs2State.ZBuffMax;

    return z;
}

u32 flPS2ConvColor(u32 c, s32 type) {
    s32 lp0;
    u16 col[4];

    col[0] = (c >> 16) & 0xFF;
    col[1] = (c >> 8) & 0xFF;
    col[2] = c & 0xFF;
    col[3] = (c >> 24) & 0xFF;

    if (type == 0) {
        for (lp0 = 0; lp0 < 4; lp0++) {
            col[lp0] = (col[lp0] + 1) >> 1;
        }
    } else {
        col[3] = (col[3] + 1) >> 1;
    }

    return (col[3] << 24) | (col[0] << 16) | (col[1] << 8) | (col[2]);
}

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2render", flAdjustScreen);
#else
void flAdjustScreen(s32 x, s32 y) {
    not_implemented(__func__);
}
#endif
void flAdjustScreen(s32 x, s32 y) {
    flPs2State.ScreenAdjustX = x;
    flPs2State.ScreenAdjustY = y & -2;
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2render", literal_876_0055F1B0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/AcrSDK/ps2/flps2render", literal_877_0055F1E0);
