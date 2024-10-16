#include "common.h"
#include "unknown.h"
#include "gcc/memory.h"

void distributeScratchPadAddress();
void MaskScreenEdge();
int mppGetFavoritePlayerNumber();
void appCopyKeyData();
unsigned char *mppMalloc(unsigned int size);
void njUserInit();
int njUserMain();
void cpLoopTask();
void cpInitTask();
void cpReadyTask(unsigned short num, void *func_adrs);
void cpExitTask(unsigned short num);

void AcrMain() {
    unsigned short sw_buff;
    unsigned int sysinfodisp;

    flInitialize(flPs2State.DispWidth, flPs2State.DispHeight);
    flSetRenderState(FLRENDER_BACKCOLOR, 0);
    flSetDebugMode(0);
    system_init_level = 0;
    ppgWorkInitializeApprication();
    distributeScratchPadAddress();
    njdp2d_init();
    njUserInit();
    palCreateGhost();
    ppgMakeConvTableTexDC();
    appSetupBasePriority();
    MemcardInit();

    while (1) {
        initRenderState(0);
        mpp_w.ds_h[0] = mpp_w.ds_h[1];
        mpp_w.ds_v[0] = mpp_w.ds_v[1];
        mpp_w.ds_h[1] = 0x64;
        mpp_w.ds_v[1] = 0x64;
        mpp_w.vprm.x0 = 0.0f;
        mpp_w.vprm.y0 = 0.0f;
        mpp_w.vprm.x1 = (mpp_w.ds_h[0] * 0x180) / 100.0f;
        mpp_w.vprm.y1 = (mpp_w.ds_v[0] * 0xE0) / 100.0f;
        mpp_w.vprm.ne = -1.0f;
        mpp_w.vprm.fa = 1.0f;

        appViewSetItems(&mpp_w.vprm);
        appViewMatrix();
        flAdjustScreen(X_Adjust + Correct_X[0], Y_Adjust + Correct_Y[0]);
        setBackGroundColor(0xFF000000);

        if (Debug_w[0x43]) {
            setBackGroundColor(0xFF0000FF);
        }

        appSetupTempPriority();
        flPADGetALL();
        keyConvert();

        if (((Usage == 7) || (Usage == 2)) && !test_flag) {
            if (mpp_w.sysStop) {
                if (mpp_w.sysStop == 1) {
                    sysSLOW = 1;

                    switch (io_w.data[1].sw_new) {
                    case 0x2000:
                        mpp_w.sysStop = 0;
                        // fallthrough

                    case 0x80:
                        Slow_Timer = 1;
                        break;

                    default:
                        switch (io_w.data[1].sw & 0x880) {
                        case 0x880:
                            if ((sysFF = Debug_w[1]) == 0) {
                                sysFF = 1;
                            }

                            sysSLOW = 1;
                            Slow_Timer = 1;

                            break;

                        case 0x800:
                            if (Slow_Timer == 0) {
                                if ((Slow_Timer = Debug_w[0]) == 0) {
                                    Slow_Timer = 1;
                                }

                                sysFF = 1;
                            }

                            break;

                        default:
                            Slow_Timer = 2;

                            break;
                        }

                        break;
                    }
                }
            } else if (io_w.data[1].sw_new & 0x2000) {
                mpp_w.sysStop = 1;
            }
        }

        Interrupt_Flag = 0;

        if ((Play_Mode != 3 && Play_Mode != 1) || (Game_pause != 0x81)) {
            p1sw_1 = p1sw_0;
            p2sw_1 = p2sw_0;
            p3sw_1 = p3sw_0;
            p4sw_1 = p4sw_0;
            p1sw_0 = p1sw_buff;
            p2sw_0 = p2sw_buff;
            p3sw_0 = p3sw_buff;
            p4sw_0 = p4sw_buff;

            if ((task[3].condition == 1) && (Mode_Type == 4) && (Play_Mode == 1)) {
                sw_buff = p2sw_0;
                p2sw_0 = p1sw_0;
                p1sw_0 = sw_buff;
            }
        }

        appCopyKeyData();
        render_start();

        mpp_w.inGame = 0;

        njUserMain();
        MaskScreenEdge();
        seqsBeforeProcess();
        njdp2d_draw();
        seqsAfterProcess();

        if (Debug_w[6] == 0) {
            CP3toPS2Draw();
        }

        KnjFlush();
        render_end();

        sysinfodisp = 0;

        if (Debug_w[2] == 2) {
            sysinfodisp = 3;
        }

        if (Debug_w[2] == 1) {
            sysinfodisp = 2;
        }

        switch (mpp_w.sysStop) {
        case 2:
            sysinfodisp = 0;
            break;

        case 1:
            sysinfodisp &= ~2;
            break;
        }

        flSetDebugMode(sysinfodisp);
        disp_effect_work();
        flFlip(0);

        Interrupt_Flag = 1;
        Interrupt_Timer += 1;
        Record_Timer += 1;

        Scrn_Renew();
        Irl_Family();
        Irl_Scrn();
        BGM_Server();
    }
}

void distributeScratchPadAddress() {
    dctex_linear = (short *)0x70000800;
    texcash_melt_buffer = (unsigned char *)0x70001000;
    tpu_free = (TPU *)0x70002000;
}

void MaskScreenEdge() {
    VPRM prm;
    float pos[8];

    appViewGetItems(&prm);

    if (prm.x1 < 384.0f) {
        pos[0] = pos[4] = mpp_w.vprm.x1;
        pos[2] = pos[6] = 384.0f;
        pos[1] = pos[3] = mpp_w.vprm.y0;
        pos[5] = pos[7] = 224.0f;

        njdp2d_sort(pos, PrioBase[0], (0xFF << 24), 0);
    }

    if (prm.y1 < 224.0f) {
        pos[0] = pos[4] = mpp_w.vprm.x0;
        pos[2] = pos[6] = 384.0f;
        pos[1] = pos[3] = mpp_w.vprm.y1;
        pos[5] = pos[7] = 224.0f;

        njdp2d_sort(pos, PrioBase[0], (0xFF << 24), 0);
    }
}

int mppGetFavoritePlayerNumber() {
    int i;
    int max = 1;
    int num = 0;

    if (Debug_w[0x2D]) {
        return Debug_w[0x2D] - 1;
    }

    for (i = 0; i < 0x14; i++) {
        if (max <= mpp_w.useChar[i]) {
            max = mpp_w.useChar[i];
            num = i + 1;
        }
    }

    return num;
}

void appCopyKeyData() {
    PLsw[0][1] = PLsw[0][0];
    PLsw[1][1] = PLsw[1][0];
    PLsw[0][0] = p1sw_buff;
    PLsw[1][0] = p2sw_buff;
}

unsigned char *mppMalloc(unsigned int size) {
    return flAllocMemory(size);
}

void njUserInit() {
    int i;
    unsigned int size;

    sysFF = 1;
    mpp_w.sysStop = 0;
    mpp_w.inGame = 0;
    mpp_w.ctrDemo = 0;
    mpp_w.language = 0;
    mpp_w.langload = -1;
    mpp_w.pal50Hz = 0;
    mpp_w.vprm.x0 = 0.0f;
    mpp_w.vprm.y0 = 0.0f;
    mpp_w.vprm.x1 = 384.0f;
    mpp_w.vprm.y1 = 224.0f;
    mpp_w.vprm.ne = -1.0f;
    mpp_w.vprm.fa = 1.0f;
    appViewSetItems(&mpp_w.vprm);
    appViewMatrix();
    mmSystemInitialize();
    flGetFrame(&mpp_w.fmsFrame);
    seqsInitialize(mppMalloc(seqsGetUseMemorySize()));
    ppg_Initialize(mppMalloc(0x60000U), 0x60000);
    zlib_Initialize(mppMalloc(0x10000U), 0x10000);
    size = flGetSpace();
    mpp_w.ramcntBuff = mppMalloc(size);
    Init_ram_control_work(mpp_w.ramcntBuff, size);

    for (i = 0; i < 0x14; i++) {
        mpp_w.useChar[i] = 0;
    }

    Interrupt_Timer = 0;
    SA_Zoom_X = 0.0f;
    SA_Zoom_Y = 0.0f;
    Disp_Size_H = 0x64;
    Disp_Size_V = 0x64;
    mpp_w.ds_h[0] = mpp_w.ds_h[1] = Disp_Size_H;
    mpp_w.ds_v[0] = mpp_w.ds_v[1] = Disp_Size_V;
    Country = 0;
    Country = 4;
    Screen_PAL = 0;
    Turbo = 0;

    if (Country == 0) {
        while (1) {}
    }

    Turbo_Timer = 1;
    Screen_Zoom_X = 1.0f;
    Screen_Zoom_Y = 1.0f;
    Setup_Disp_Size(0);
    *Correct_X = 0;
    *Correct_Y = 0;
    Frame_Zoom_X = Screen_Zoom_X + SA_Zoom_X;
    Frame_Zoom_Y = Screen_Zoom_Y + SA_Zoom_Y;
    Zoom_Base_Position_X = 0;
    Zoom_Base_Position_Y = 0;
    Zoom_Base_Position_Z = 0;
    sys_w.disp.now = sys_w.disp.new = 1;
    sys_w.pause = 0;
    sys_w.reset = 0;

    Init_sound_system();
    Init_bgm_work();
    Setup_Directory_Record_Data();
    sndInitialLoad();
    cpInitTask();
    cpReadyTask(0, Init_Task);
}

int njUserMain() {
    CPU_Time_Lag[0] = 0;
    CPU_Time_Lag[1] = 0;
    CPU_Rec[0] = 0;
    CPU_Rec[1] = 0;

    Check_Replay_Status(0, Replay_Status[0]);
    Check_Replay_Status(1, Replay_Status[1]);

    Frame_Zoom_X = Screen_Zoom_X + SA_Zoom_X;
    Frame_Zoom_Y = Screen_Zoom_Y + SA_Zoom_Y;

    if (sys_w.disp.now == sys_w.disp.new) {
        cpLoopTask();

        if ((Game_pause != 0x81) && (Mode_Type == 1) && (Play_Mode == 1)) {
            if ((plw->wu.operator== 0) && (CPU_Rec[0] == 0) && (Replay_Status[0] == 1)) {
                p1sw_0 = 0;

                Check_Replay_Status(0, 1);

                if (Debug_w[0x21]) {
                    flPrintColor(0xFFFFFFFF);
                    flPrintL(0x10, 0xA, "FAKE REC! PL1");
                }
            }

            if ((plw[1].wu.operator== 0) && (CPU_Rec[1] == 0) && ((Replay_Status[1]) == 1)) {
                p2sw_0 = 0;

                Check_Replay_Status(1, 1);

                if (Debug_w[0x21]) {
                    flPrintColor(0xFFFFFFFF);
                    flPrintL(0x10, 0xA, "FAKE REC! PL2");
                }
            }
        }
    } else {
        sys_w.disp.now = sys_w.disp.new;
    }

    return sys_w.gd_error;
}

void cpLoopTask() {
    int temp_a0;
    struct _TASK *task_ptr = task;

    disp_ramcnt_free_area();

    if (sysSLOW) {
        if (--Slow_Timer == 0) {
            sysSLOW = 0;
            Game_pause &= 0x7F;
        } else {
            Game_pause |= 0x80;
        }
    }

    Process_Counter = 1;

    if (Turbo && (Game_pause != 0x81)) {
        if (--Turbo_Timer == 0) {
            Turbo_Timer = Turbo;
            Process_Counter = 2;
        }
    }

    for (current_task_num = 0; current_task_num < 0xB; current_task_num++) {
        switch (task_ptr->condition) {
        case 1:
            task_ptr->func_adrs(task_ptr);
            break;

        case 2:
            task_ptr->condition = 1;
            break;

        case 3:
            break;
        }

        task_ptr += 1;
    }
}

void cpInitTask() {
    memset(&task, 0, sizeof(task));
}

void cpReadyTask(unsigned short num, void *func_adrs) {
    struct _TASK *task_ptr = task + num;

    memset(task_ptr, 0, sizeof(struct _TASK));

    task_ptr->func_adrs = func_adrs;
    task_ptr->condition = 2;
}

void cpExitTask(unsigned short num) {
    struct _TASK *task_ptr = task + num;

    task_ptr->condition = 0;

    if (task_ptr->callback_adrs != NULL) {
        task_ptr->callback_adrs();
    }
}