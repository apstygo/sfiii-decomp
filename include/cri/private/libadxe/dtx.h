#ifndef DTX_H
#define DTX_H

#include <cri/private/libadxe/structs.h>

#include <cri/cri_xpts.h>

extern Sint32 dtx_send_sw;

void DTX_Init();
ADXDTX DTX_Create(Sint32, Sint32, Sint32, Sint32);
void DTX_Destroy(ADXDTX);
void DTX_SetRcvCbf(ADXDTX, void (*)(), void *);
void DTX_SetSndCbf(ADXDTX, void (*)(), void *);
Sint32 DTX_CallUrpc(Sint32, Sint32 *, Sint32, Sint32, Sint32);
void DTX_Finish();

#endif
