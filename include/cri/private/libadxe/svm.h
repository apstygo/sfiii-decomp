#ifndef SVM_H
#define SVM_H

#include <cri/cri_xpts.h>

void SVM_Init();
void SVM_Lock();
void SVM_Unlock();
void SVM_LockRsc();
void SVM_UnlockRsc();
void SVM_LockVar();
void SVM_UnlockVar();
void SVM_CallErr(const Char8 *format, ...);
void SVM_SetCbErr(void (*callback)(void *, Char8 *), void *object);
Sint32 SVM_SetCbSvr(Sint32, Sint32 (*)(void *), void *);
void SVM_SetCbSvrId(Sint32, Sint32, Sint32 (*)(void *), void *);
void SVM_DelCbSvr(Sint32 svtype, Sint32 id);
void SVM_SetCbLock(void (*func)(void *), void *object);
void SVM_SetCbUnlock(void (*func)(void *), void *object);
void SVM_Finish();
Sint32 SVM_ExecSvrMain();
Sint32 SVM_TestAndSet(Sint32 *mem);
void SVM_CallErr1(const Char8 *msg);

#endif
