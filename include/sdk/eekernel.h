#ifndef _eekernel_h_
#define _eekernel_h_

#if defined(TARGET_PS2)
#include "mw_stdarg.h"
#else
#include <stdarg.h>
#include <stddef.h>
#endif

#if defined(TARGET_PS2)
#define ExitHandler() asm("sync.l; ei")
#else
void ExitHandler();
#endif

struct ThreadParam {
    int status;
    void (*entry)(void *);
    void *stack;
    int stackSize;
    void *gpReg;
    int initPriority;
    int currentPriority;
    u_int attr;
    u_int option;
    int waitType;
    int waitId;
    int wakeupCount;
};

/*
 * COP0
 */

void FlushCache(int);
void iFlushCache(int);
void SyncDCache(void *, void *);
void iSyncDCache(void *, void *);
void InvalidDCache(void *, void *);
void iInvalidDCache(void *, void *);
unsigned int GetCop0(int);
unsigned int iGetCop0(int);

/*
 * Multi Thread
 */

#define TH_SELF 0

// Thread status
#define THS_RUN 0x01
#define THS_READY 0x02
#define THS_WAIT 0x04
#define THS_SUSPEND 0x08
#define THS_WAITSUSPEND 0x0c
#define THS_DORMANT 0x10

int CreateThread(struct ThreadParam *);
int DeleteThread(int);
int StartThread(int, void *arg);
void ExitThread(void);
void ExitDeleteThread(void);
int TerminateThread(int);
int iTerminateThread(int);
int ChangeThreadPriority(int, int);
int iChangeThreadPriority(int, int);
int RotateThreadReadyQueue(int);
int iRotateThreadReadyQueue(int);
int ReleaseWaitThread(int);
int iReleaseWaitThread(int);
int GetThreadId(void);
int ReferThreadStatus(int, struct ThreadParam *);
int iReferThreadStatus(int, struct ThreadParam *);
int SleepThread(void);
int WakeupThread(int);
int iWakeupThread(int);
int CancelWakeupThread(int);
int iCancelWakeupThread(int);
int SuspendThread(int);
int iSuspendThread(int);
int ResumeThread(int);
int iResumeThread(int);
int DelayThread(u_int);

/*
 * Interrupt
 */

int EnableIntc(int);
int iEnableIntc(int);
int iDisableIntc(int);
int EnableDmac(int);

int AddIntcHandler(int, int (*)(int), int);
int AddDmacHandler(int, int (*)(int), int);

void scePrintf(const char *fmt, ...);
void sceVprintf(const char *fmt, va_list ap);
int sceSnprintf(char *buffer, size_t count, const char *fmt, ...);
int sceVsnprintf(char *buffer, size_t count, const char *fmt, va_list ap);

#endif
