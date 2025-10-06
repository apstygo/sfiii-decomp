#ifndef EMLSHIM_H_
#define EMLSHIM_H_

#include "sf33rd/AcrSDK/MiddleWare/PS2/CapSndEng/emlSndDrv.h"

void emlShimInit();
void emlShimStartSound(CSE_SYS_PARAM_SNDSTART* param);
void emlShimSeKeyOff(CSE_REQP* pReqp);
void emlShimSeStop(CSE_REQP* pReqp);
void emlShimSeStopAll();

#endif // EMLSHIM_H_
