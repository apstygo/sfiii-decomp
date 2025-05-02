#include "common.h"
#include <cri/private/libadxe/svm.h>

#include <cri/cri_adxt.h>
#include <cri/ee/cri_xpt.h>
#include <eekernel.h>

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", D_0055AA98);

// data
#if defined(TARGET_PS2)
extern Char8 *adxps2_build;
extern Sint32 adxm_init_level;
extern Sint32 adxm_init_ex;
extern Sint32 adxm_save_tprm[12];
extern Sint32 adxm_lock_level;
extern Sint32 adxm_goto_border_flag;
extern Sint32 adxm_vsyncproc_exec_flag;
extern Sint32 adxm_usrvsyncproc_exec_flag;
extern Sint32 adxm_fsproc_exec_flag;
extern Sint32 adxm_mwidleproc_exec_flag;
extern Sint32 adxm_usridleproc_exec_flag;
extern Sint32 adxm_waiting_main_th_flag;
extern Sint64 adxm_safe_cnt;
extern Sint64 adxm_usrvsync_cnt;
extern Sint64 adxm_vsync_cnt;
extern Sint64 adxm_fs_cnt;
extern Sint64 adxm_mwidle_cnt;
extern Sint64 adxm_usridle_cnt;
extern Sint64 adxm_vint_cnt;
extern Sint32 volatile adxm_id_safe;
extern Sint32 volatile adxm_id_usrvsync;
extern Sint32 volatile adxm_id_vsync;
extern Sint32 volatile adxm_id_fs;
extern Sint32 volatile adxm_id_main;
extern Sint32 volatile adxm_id_mwidle;
extern Sint32 volatile adxm_id_usridle;
extern Sint64 volatile adxm_safe_loop;
extern Sint64 volatile adxm_safe_exit;
extern Sint64 volatile adxm_usrvsync_loop;
extern Sint64 volatile adxm_usrvsync_exit;
extern Sint64 volatile adxm_vsync_loop;
extern Sint64 volatile adxm_vsync_exit;
extern Sint64 volatile adxm_fs_loop;
extern Sint64 volatile adxm_fs_exit;
extern Sint64 volatile adxm_mwidle_loop;
extern Sint64 volatile adxm_mwidle_exit;
extern Sint64 volatile adxm_usridle_loop;
extern Sint64 volatile adxm_usridle_exit;
extern Sint32 adxps2_exec_svr;
extern Sint32 adxps2_exec_vint;
extern Sint32 adxm_old_cbf;
extern Sint16 adxm_debug_bgcl;
extern Sint32 adxm_stack_safe[0x200];
extern Sint32 adxm_stack_usrvsync[0x400];
extern Sint32 adxm_stack_vsync[0x400];
extern Sint32 adxm_stack_fs[0x400];
extern Sint32 adxm_stack_mwidle[0x800];
extern Sint32 adxm_stack_usridle[0x800];
extern Sint32 adxm_cur_prio;
extern Sint32 adxm_cur_tid;
extern Sint32 adxm_main_prio_def;
#else
Char8 *adxps2_build = "\nADXPS2 Ver.2.46 Build:Sep 18 2003 10:00:02\n";
Sint32 adxm_init_level = 0;
Sint32 adxm_init_ex = 0;
Sint32 adxm_save_tprm[12] = { 0 };
Sint32 adxm_lock_level = 0;
Sint32 adxm_goto_border_flag = 0;
Sint32 adxm_vsyncproc_exec_flag = 0;
Sint32 adxm_usrvsyncproc_exec_flag = 0;
Sint32 adxm_fsproc_exec_flag = 0;
Sint32 adxm_mwidleproc_exec_flag = 0;
Sint32 adxm_usridleproc_exec_flag = 0;
Sint32 adxm_waiting_main_th_flag = 0;
Sint64 adxm_safe_cnt = 0;
Sint64 adxm_usrvsync_cnt = 0;
Sint64 adxm_vsync_cnt = 0;
Sint64 adxm_fs_cnt = 0;
Sint64 adxm_mwidle_cnt = 0;
Sint64 adxm_usridle_cnt = 0;
Sint64 adxm_vint_cnt = 0;
Sint32 volatile adxm_id_safe = 0;
Sint32 volatile adxm_id_usrvsync = 0;
Sint32 volatile adxm_id_vsync = 0;
Sint32 volatile adxm_id_fs = 0;
Sint32 volatile adxm_id_main = 0;
Sint32 volatile adxm_id_mwidle = 0;
Sint32 volatile adxm_id_usridle = 0;
Sint64 volatile adxm_safe_loop = 0;
Sint64 volatile adxm_safe_exit = 0;
Sint64 volatile adxm_usrvsync_loop = 0;
Sint64 volatile adxm_usrvsync_exit = 0;
Sint64 volatile adxm_vsync_loop = 0;
Sint64 volatile adxm_vsync_exit = 0;
Sint64 volatile adxm_fs_loop = 0;
Sint64 volatile adxm_fs_exit = 0;
Sint64 volatile adxm_mwidle_loop = 0;
Sint64 volatile adxm_mwidle_exit = 0;
Sint64 volatile adxm_usridle_loop = 0;
Sint64 volatile adxm_usridle_exit = 0;
Sint32 adxps2_exec_svr = 0;
Sint32 adxps2_exec_vint = 0;
Sint32 adxm_old_cbf = 0;
Sint16 adxm_debug_bgcl = 0;
Sint32 adxm_stack_safe[0x200] = { 0 };
Sint32 adxm_stack_usrvsync[0x400] = { 0 };
Sint32 adxm_stack_vsync[0x400] = { 0 };
Sint32 adxm_stack_fs[0x400] = { 0 };
Sint32 adxm_stack_mwidle[0x800] = { 0 };
Sint32 adxm_stack_usridle[0x800] = { 0 };
Sint32 adxm_cur_prio = 0;
Sint32 adxm_cur_tid = 0;
Sint32 adxm_main_prio_def = 0;
#endif

// forward decls
void adxm_ShutdownFsThrd();
void adxm_ShutdownMwIdleThrd();
void adxm_ShutdownPreProcedure();
void adxm_ShutdownSafeThrd();
void adxm_ShutdownVsyncThrd();

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", _adxm_lock);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", _adxm_unlock);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", D_0055AAC8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_goto_svr_border);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_goto_mwidle_border);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_goto_usridle_border);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_safe_trap);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_safe_proc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_usrvsync_proc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_vsync_proc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_fs_proc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_mwidle_proc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_usridle_proc);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_iWakeupThread);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_WakeupThread);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_SleepThread);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_ResumeThread);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_SuspendThread);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_SetupSafeThrd);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", D_0055AAF8);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_SetupUsrVsyncThrd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_SetupVsyncThrd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_SetupFsThrd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_SetupMwIdleThrd);

INCLUDE_RODATA("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", D_0055AB38);
INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_SetupUsrIdleThrd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_IsSetupThrdEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_ExecSvrUsrVsync);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_ExecSvrVsync);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_ExecSvrFs);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_ExecSvrMain);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_ExecSvrMwIdle);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_ExecSvrUsrIdle);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_ExecSvrAll);

Sint32 ADXM_IsSetupThrd() {
    return adxm_init_level != 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_SetCbErr);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_SetupThrd);

void adxm_ShutdownPreProcedure() {
    adxm_safe_loop = 1;
    adxm_usrvsync_loop = 1;
    adxm_vsync_loop = 1;
    adxm_fs_loop = 1;
    adxm_mwidle_loop = 1;
    adxm_usridle_loop = 1;
}

void ADXM_ShutdownThrd() {
    if (--adxm_init_level == 0) {
        adxm_ShutdownPreProcedure();
        adxm_ShutdownMwIdleThrd();
        adxm_ShutdownFsThrd();
        adxm_ShutdownVsyncThrd();
        adxm_ShutdownSafeThrd();
        ChangeThreadPriority(adxm_id_main, adxm_main_prio_def);
        SVM_SetCbLock(NULL, NULL);
        SVM_SetCbUnlock(NULL, NULL);
        SVM_Finish();
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_ShutdownUsrIdleThrd);

void adxm_ShutdownMwIdleThrd() {
    if (adxm_mwidle_exit == 0) {
        do {
            adxm_mwidle_loop = 1;
            ChangeThreadPriority(adxm_id_mwidle, 1);
            WakeupThread(adxm_id_mwidle);
            ResumeThread(adxm_id_mwidle);
        } while (adxm_mwidle_exit == 0);
    }

    adxm_mwidle_exit = 0;
    adxm_mwidle_loop = 0;
    adxm_id_mwidle = 0;
}

void adxm_ShutdownVsyncThrd() {
    if (adxm_vsync_exit == 0) {
        do {
            adxm_vsync_loop = 1;
            ChangeThreadPriority(adxm_id_vsync, 1);
            WakeupThread(adxm_id_vsync);
            ResumeThread(adxm_id_vsync);
        } while (adxm_vsync_exit == 0);
    }

    adxm_vsync_exit = 0;
    adxm_vsync_loop = 0;
    adxm_id_vsync = 0;
}

void adxm_ShutdownFsThrd() {
    if (adxm_fs_exit == 0) {
        do {
            adxm_fs_loop = 1;
            ChangeThreadPriority(adxm_id_fs, 1);
            WakeupThread(adxm_id_fs);
            ResumeThread(adxm_id_fs);
        } while (adxm_fs_exit == 0);
    }

    adxm_fs_exit = 0;
    adxm_fs_loop = 0;
    adxm_id_fs = 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", adxm_ShutdownUsrVsyncThrd);

void adxm_ShutdownSafeThrd() {
    if (adxm_safe_exit == 0) {
        do {
            adxm_safe_loop = 1;
            ChangeThreadPriority(adxm_id_safe, 1);
            WakeupThread(adxm_id_safe);
            ResumeThread(adxm_id_safe);
        } while (adxm_safe_exit == 0);
    }

    adxm_safe_exit = 0;
    adxm_safe_loop = 0;
    adxm_id_safe = 0;
}

void ADXM_Lock() {
    SVM_Lock();
}

void ADXM_Unlock() {
    SVM_Unlock();
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_GetLockLevel);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXPS2_ExecVint);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_ExecVint);

Sint32 ADXM_ExecMain() {
    return SVM_ExecSvrMain();
}

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXPS2_ResumeIdleThrd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXPS2_WakeupMainThrd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXPS2_SleepMainThrd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_WaitVsync);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXPS2_WaitVsync);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXPS2_ExecServerEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXPS2_SetupThrd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXPS2_ShutdownThrd);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXPS2_ExecServer);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXPS2_Lock);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXPS2_Unlock);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_SetupThrdEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_ShutdownThrdEx);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_SetCbUsrVsync);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_SetCbUsrIdle);

INCLUDE_ASM("asm/anniversary/nonmatchings/cri/libadxe/adx_mps2", ADXM_GotoUsrIdleBdr);
