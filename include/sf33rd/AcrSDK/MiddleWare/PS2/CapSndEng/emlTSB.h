#ifndef EML_TSB_H
#define EML_TSB_H

#include "structs.h"
#include "types.h"

#define TSB_MAX 16
#define ECHOWORK_MAX 16

extern SoundEvent* gpTsb[TSB_MAX];          // size: 0x40, address: 0x57B2C0
extern CSE_ECHOWORK EchoWork[ECHOWORK_MAX]; // size: 0x380, address: 0x6EABC0

s32 mlTsbInit();
s32 mlTsbExecServer();
s32 mlTsbStopAll();
s32 mlTsbSetBankAddr(u32 bank, SoundEvent* addr);
SoundEvent* mlTsbGetDataAdrs(u32 bank, u32 code);
static s32 mlTsbKeyOn(SoundEvent* pTSB, CSE_REQP* pReqp, u32 bank, u32 prog);
s32 mlTsbRequest(u16 bank, u16 code, s32* aRtpc);
static void mlTsbSetToReqp(CSE_REQP* pReqp, SoundEvent* pTSB, u16 bank);
static s32 mlTsbInitEchoWork();
static s32 mlTsbMoveEchoWork();
static CSE_ECHOWORK* mlTsbPickupEchoWork(u32 index);
static s32 mlTsbCreateEcho(u32 bank, u32 code, s32* pRtpc);
static s32 mlTsbStopEcho(u32 bank, u32 code);
static s32 mlTsbStopEchoAll();

#endif
