#ifndef FOUNDAPS2_H
#define FOUNDAPS2_H

#include "sf33rd/AcrSDK/common/plcommon.h"
#include "structs.h"
#include "types.h"

#define VRAM_CONTROL_SIZE 1344

extern s32 flDebugRTNum;                  // size: 0x4, address: 0x57AB3C
extern u32 flDebugTrueTime[4];            // size: 0x10, address: 0x57AB50
extern s32 flPS2FlipCancelFlag;           // size: 0x4, address: 0x57AB78
extern u32 flPs2FBA;                      // size: 0x4, address: 0x57AB84
extern s32 flClayNum;                     // size: 0x4, address: 0x57AB88
extern s32 flVramStaticNum;               // size: 0x4, address: 0x57AE1C
extern VRAMBlockHeader flVramStatic[3];   // size: 0x18, address: 0x57AE20
extern s32 flPTNum;                       // size: 0x4, address: 0x57AE38
extern s32 flVramNum;                     // size: 0x4, address: 0x57AE3C
extern LPVram *flVramList;                // size: 0x4, address: 0x57AE40
extern FLPS2VIF1Control flPs2VIF1Control; // size: 0x3C, address: 0x57AE50
extern FL_FMS flFMS;                      // size: 0x18, address: 0x57AEB0
extern u32 flSystemRenderOperation;       // size: 0x4, address: 0x57AEC8
extern u32 flSystemRenderState;           // size: 0x4, address: 0x57AECC
extern u32 flLoadCount;                   // size: 0x4, address: 0x57AED8
extern plContext flFrameBuf;              // size: 0x48, address: 0x57AEF0
extern s32 flFrame;                       // size: 0x4, address: 0x57AF38
extern s32 flHeight;                      // size: 0x4, address: 0x57AF3C
extern s32 flWidth;                       // size: 0x4, address: 0x57AF40
extern s32 flCTNum;                       // size: 0x4, address: 0x57AF44

extern FLTexture flPalette[1088];               // size: 0xFF00, address: 0x6C56D0
extern FLTexture flTexture[256];                // size: 0x3C00, address: 0x6D55D0
extern LPVram flVramControl[VRAM_CONTROL_SIZE]; // size: 0x9300, address: 0x6D91D0
extern FLPS2DrawStart flPs2DrawStart;           // size: 0x140, address: 0x6E24D0
extern FLPS2DB flPs2Db[2];                      // size: 0x140, address: 0x6E2610
extern FLPS2State flPs2State;                   // size: 0x470, address: 0x6E2750

s32 flInitialize();
u32 flPS2CheckDbChangeFlag();
s32 flFlip(u32 flag);
s32 flLogOut(s8 *format, ...);
void flInitPhaseStarted();
void flInitPhaseFinished();

#endif
