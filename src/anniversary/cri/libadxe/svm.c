#include "common.h"
#include "mw_stdarg.h"
#include <cri/ee/cri_mw.h>
#include <cri/private/libadxe/svm.h>

typedef struct {
    void (*func)(void *);
    void *object;
} SVMLockCallback;

typedef struct {
    void (*func)(void *, Char8 *);
    void *object;
} SVMErrorCallback;

// data
Char8 *svm_build = "\nSVM/PS2EE Ver.1.51 Build:Sep 18 2003 09:59:52\n";
volatile Sint32 svm_init_level = 0;
volatile Sint32 svm_lock_level = 0;
volatile Sint32 svm_locking_type = 0;
Sint32 svm_exec_cnt[8] = { 0 };
Sint32 svm_svr_exec_flag[8] = { 0 };
Char8 svmerr_msg[128] = { 0 };

// bss
extern Sint32 (*svm_test_and_set_callback)();
extern SVMErrorCallback svm_error_callback;
extern SVMLockCallback svm_unlock_callback;
extern SVMLockCallback svm_lock_callback;
// extern Uint8 D_006C04E0[0x40];
// extern Uint8 D_006C0360[0x180];
// extern Uint8 D_006C0340[0x20];

void _svm_lock(Sint32 type) {
    if (svm_lock_callback.func == NULL) {
        return;
    }

    svm_lock_callback.func(svm_lock_callback.object);

    if (svm_lock_level == 0) {
        svm_locking_type = type;
    }

    svm_lock_level += 1;
}

void _svm_unlock(Sint32 type) {
    if (svm_unlock_callback.func == NULL) {
        return;
    }

    svm_lock_level -= 1;

    if (svm_lock_level == 0) {
        if (svm_locking_type != type) {
            SVM_CallErr(
                "2103102:SVM:svm_unlock:lock type miss match.(type org=%d, type now=%d)", svm_locking_type, type);
        }

        svm_locking_type = 0;
    }

    svm_unlock_callback.func(svm_unlock_callback.object);
}

void SVM_Lock() {
    _svm_lock(1);
}

void SVM_Unlock() {
    _svm_unlock(1);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_LockVar);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_LockSync);

void SVM_LockRsc() {
    _svm_lock(4);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_LockThrd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_LockEtc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_UnlockVar);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_UnlockSync);

void SVM_UnlockRsc() {
    _svm_unlock(4);
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_UnlockThrd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_UnlockEtc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_GetLockType);

void SVM_CallErr(const Char8 *format, ...) {
    va_list args;

    memset(svmerr_msg, 0, sizeof(svmerr_msg));
    va_start(args, format);
    vsprintf(&svmerr_msg, format, args);

    if (svm_error_callback.func != NULL) {
        svm_error_callback.func(svm_error_callback.object, svmerr_msg);
    }
}

void SVM_CallErr1(const Char8 *msg) {
    strncpy(svmerr_msg, msg, sizeof(svmerr_msg) - 1);

    if (svm_error_callback.func != NULL) {
        svm_error_callback.func(svm_error_callback.object, svmerr_msg);
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_CallErr2);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_ItoA);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/svm", D_0055E808);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_ItoA2);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/svm", D_0055E810);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_SetCbSvr);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/svm", D_0055E840);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_DelCbSvr);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/svm", D_0055E860);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/svm", D_0055E888);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/svm", D_0055E8B0);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_SetCbSvrId);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_SetCbBdr);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_GotoSvrBorder);

void SVM_SetCbErr(void (*func)(void *, Char8 *), void *object) {
    SVM_Lock();
    svm_error_callback.func = func;
    svm_error_callback.object = object;
    SVM_Unlock();
}

void SVM_SetCbLock(void (*func)(void *), void *object) {
    svm_lock_callback.func = func;
    svm_lock_callback.object = object;
}

void SVM_SetCbUnlock(void (*func)(void *), void *object) {
    svm_unlock_callback.func = func;
    svm_unlock_callback.object = object;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_ExecSvrFunc);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/svm", D_0055E8E8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/svm", D_0055E910);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_ExecSvrFuncId);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_ExecSvrVint);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_ExecSvrUsrVsync);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_ExecSvrVsync);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_ExecSvrUhigh);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_ExecSvrFs);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_ExecSvrMain);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_ExecSvrMwIdle);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_ExecSvrUsrIdle);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/svm", SVM_GetExecCount);

void svm_reset_variable() {
    Sint32 i;
    Sint32 *exec_cnt_ptr;

    memset(svm_svr_exec_flag, 0, sizeof(svm_svr_exec_flag));
    memset(&svm_lock_callback, 0, sizeof(SVMLockCallback));
    memset(&svm_unlock_callback, 0, sizeof(SVMLockCallback));

    exec_cnt_ptr = &svm_exec_cnt;

    for (i = 0; i < 6; i++) {
        *exec_cnt_ptr++ = 0;
    }

    svm_test_and_set_callback = NULL;
}

void SVM_Init() {
    if (svm_init_level == 0) {
        svm_reset_variable();
    }

    svm_init_level += 1;
}

void SVM_Finish() {
    svm_init_level -= 1;

    if (svm_init_level == 0) {
        svm_reset_variable();
        memset(&svm_error_callback, 0, sizeof(SVMErrorCallback));
    }
}

Sint32 SVM_TestAndSet(Sint32 *mem) {
    Sint32 temp;
    Sint32 result;

    if (svm_test_and_set_callback != NULL) {
        result = svm_test_and_set_callback();
    } else {
        SVM_Lock();
        temp = *mem;
        *mem = 1;
        result = temp != 1;
        SVM_Unlock();
    }

    return result;
}

Sint32 SVM_SetCbTestAndSet(Sint32 (*callback)()) {
    if (svm_test_and_set_callback != NULL) {
        return 0;
    }

    svm_test_and_set_callback = callback;
    return 1;
}

Sint32 SVM_DelCbTestAndSet() {
    return SVM_SetCbTestAndSet(NULL);
}
