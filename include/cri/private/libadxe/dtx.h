#ifndef DTX_H
#define DTX_H

#include <cri/private/libadxe/structs.h>

#include <cri/cri_xpts.h>

extern Sint32 dtx_send_sw;

void DTX_Init();
DTX DTX_Create(Sint32 id, void *eewk, void *iopwk, Sint32 wklen);
void DTX_Destroy(DTX dtx);
void DTX_SetRcvCbf(DTX dtx, void (*func)(), void *object);
void DTX_SetSndCbf(DTX dtx, void (*func)(), void *object);
Sint32 DTX_CallUrpc(Sint32 arg0, Sint32 *args, Sint32 arg_num, Sint32 *arg3, Sint32 arg4);
void DTX_Finish();
void DTX_ExecServer();

#endif
