#ifndef _eekernel_h_
#define _eekernel_h_

#define ExitHandler() asm("sync.l; ei")

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

#endif
