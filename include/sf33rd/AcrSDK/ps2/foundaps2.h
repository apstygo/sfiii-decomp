#ifndef FOUNDAPS2_H
#define FOUNDAPS2_H

#include "sf33rd/AcrSDK/common/plcommon.h"
#include "structs.h"
#include "types.h"

#define VRAM_CONTROL_SIZE 1344
#define VRAM_BLOCK_HEADER_SIZE 3
#define LOAD_CHECK_TIME_SIZE 20
#define DEBUG_TRUE_TIME_SIZE 4
#define DEBUG_SYS_MEM_SIZE 4096
#define FL_PALETTE_MAX 1088
#define FL_TEXTURE_MAX 256

extern u32 flLoadCheckColor[20];                             // size: 0x50, address: 0x57AA50
extern u32 flLoadCheckTime[LOAD_CHECK_TIME_SIZE];            // size: 0x4, address: 0x57AAA0
extern s32 flLoadCheckTimeOld;                               // size: 0x4, address: 0x57AAF0
extern s32 flLoadCheckCtr;                                   // size: 0x4, address: 0x57AAF4
extern u32 flDebugTrueTimeFree[DEBUG_TRUE_TIME_SIZE];        // size: 0x10, address: 0x57AB00
extern u32 flDebugSysMemMotion;                              // size: 0x4, address: 0x57AB10
extern u32 flDebugSysMemClay;                                // size: 0x4, address: 0x57AB14
extern u32 flDebugSysMemTexture;                             // size: 0x4, address: 0x57AB18
extern u32 flDebugSysMemEtc;                                 // size: 0x4, address: 0x57AB1C
extern u32 flDebugSysMemHandleNum;                           // size: 0x4, address: 0x57AB20
extern s32 flDebugMATERIALNum;                               // size: 0x4, address: 0x57AB24
extern s32 flDebugPOLYNum;                                   // size: 0x4, address: 0x57AB28
extern s32 flDebugVERTNum;                                   // size: 0x4, address: 0x57AB2C
extern s32 flDebugDINum;                                     // size: 0x4, address: 0x57AB30
extern s32 flDebugAQNum;                                     // size: 0x4, address: 0x57AB34
extern s32 flDebugMCNum;                                     // size: 0x4, address: 0x57AB38
extern s32 flDebugRTNum;                                     // size: 0x4, address: 0x57AB3C
extern s32 flDebugUTNum;                                     // size: 0x4, address: 0x57AB40
extern s32 flDebugErrECNum;                                  // size: 0x4, address: 0x57AB44
extern s32 flDebugECNum;                                     // size: 0x4, address: 0x57AB48
extern u32 flDebugEndRenderTime;                             // size: 0x4, address: 0x57AB4C
extern u32 flDebugTrueTime[DEBUG_TRUE_TIME_SIZE];            // size: 0x10, address: 0x57AB50
extern u32 flDebugStrCtr;                                    // size: 0x4, address: 0x57AB60
extern u32 flDebugStrCol;                                    // size: 0x4, address: 0x57AB64
extern s32 flDebugStrX;                                      // size: 0x4, address: 0x57AB68
extern s32 flDebugStrY;                                      // size: 0x4, address: 0x57AB6C
extern u32 flDebugStrHan;                                    // size: 0x4, address: 0x57AB70
extern u32 flhDebugStr;                                      // size: 0x4, address: 0x57AB74
extern s32 flPS2FlipCancelFlag;                              // size: 0x4, address: 0x57AB78
extern f32 flPS2FrameTexScaleY;                              // size: 0x4 address: 0x57AB7C
extern f32 flPS2FrameTexScaleX;                              // size: 0x4, address: 0x57AB80
extern u32 flPs2FBA;                                         // size: 0x4, address: 0x57AB84
extern s32 flClayNum;                                        // size: 0x4, address: 0x57AB88
extern f32 flViewportLY;                                     // size: 0x4, address: 0x57AB8C
extern f32 flViewportLX;                                     // size: 0x4, address: 0x57AB90
extern f32 flViewportCY;                                     // size: 0x4, address: 0x57AB94
extern f32 flViewportCX;                                     // size: 0x4, address: 0x57AB98
extern f32 flViewportDH;                                     // size: 0x4, address: 0x57AB9C
extern f32 flViewportDW;                                     // size: 0x4, address: 0x57ABA0
extern f32 flViewportDY;                                     // size: 0x4, address: 0x57ABA4
extern f32 flViewportDX;                                     // size: 0x4, address: 0x57ABA8
extern f32 flPS2ATTENUATION1[1];                             // size: 0x4, address: 0x57ABAC
extern FLLight flLIGHT[1];                                   // size: 0x68, address: 0x57ABB0
extern FLMaterial flMATERIAL[1];                             // size: 0x4C, address: 0x57AC20
extern MTX flPS2VIEWPORT;                                    // size: 0x40, address: 0x57AC70
extern MTX flPS2CLIPPROJ;                                    // size: 0x40, address: 0x57ACB0
extern MTX flPS2VIEWPROJ;                                    // size: 0x40, address: 0x57ACF0
extern MTX flACRVIEWPROJ;                                    // size: 0x40, address: 0x57AD30
extern MTX flACRVIEWPORT;                                    // size: 0x40, address: 0x57AD70
extern MTX flPS2INITMATRIX;                                  // size: 0x40, address: 0x57ADB0
extern f32 flPS2FadeColor[4];                                // size: 0x10, address: 0x57ADF0
extern f32 flPS2Ambient[4];                                  // size: 0x10, address: 0x57AE00
extern u32 flTextureStage[1];                                // size: 0x4, address: 0x57AE10
extern u32 flMipmapK;                                        // size: 0x4, address: 0x57AE14
extern u32 flMipmapL;                                        // size: 0x4, address: 0x57AE18
extern s32 flVramStaticNum;                                  // size: 0x4, address: 0x57AE1C
extern VRAMBlockHeader flVramStatic[VRAM_BLOCK_HEADER_SIZE]; // size: 0x18, address: 0x57AE20
extern s32 flPTNum;                                          // size: 0x4, address: 0x57AE38
extern s32 flVramNum;                                        // size: 0x4, address: 0x57AE3C
extern LPVram *flVramList;                                   // size: 0x4, address: 0x57AE40
extern FLPS2VIF1Control flPs2VIF1Control;                    // size: 0x3C, address: 0x57AE50
extern u32 flDebugFlag;                                      // size: 0x4, address: 0x57AE8C
extern u32 flAlphaRefValue;                                  // size: 0x4, address: 0x57AE90
extern u32 flFadeColor;                                      // size: 0x4, address: 0x57AE94
extern u32 flAmbient;                                        // size: 0x4, address: 0x57AE98
extern u32 flFogColor;                                       // size: 0x4, address: 0x57AE9C
extern f32 flFogEnd;                                         // size: 0x4, address: 0x57AEA0
extern f32 flFogStart;                                       // size: 0x4, address: 0x57AEA4
extern FL_FMS flFMS;                                         // size: 0x18, address: 0x57AEB0
extern u32 flSystemRenderOperation;                          // size: 0x4, address: 0x57AEC8
extern u32 flSystemRenderState;                              // size: 0x4, address: 0x57AECC
extern u32 flLoadCount;                                      // size: 0x4, address: 0x57AED8
extern f32 flLoadReserve;                                    // size: 0x4, address: 0x57AEDC
extern f64 flLoadAmount;                                     // size: 0x8, address: 0x57AEE0
extern f64 flLoadNow;                                        // size: 0x8, address: 0x57AED0
extern plContext flFrameBuf;                                 // size: 0x48, address: 0x57AEF0
extern s32 flFrame;                                          // size: 0x4, address: 0x57AF38
extern s32 flHeight;                                         // size: 0x4, address: 0x57AF3C
extern s32 flWidth;                                          // size: 0x4, address: 0x57AF40
extern s32 flCTNum;                                          // size: 0x4, address: 0x57AF44
extern u32 flCTH;                                            // size: 0x4, address: 0x57AF48

extern s32 flDebugSysMem[DEBUG_SYS_MEM_SIZE];   // size: 0x4000, address: 0x6C0DD0
extern MTX flMATRIX[36];                        // size: 0x900, address: 0x6C4DD0
extern FLTexture flPalette[FL_PALETTE_MAX];     // size: 0xFF00, address: 0x6C56D0
extern FLTexture flTexture[FL_TEXTURE_MAX];     // size: 0x3C00, address: 0x6D55D0
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
