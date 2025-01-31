#include "sf33rd/Source/Game/menu.h"
#include "common.h"
#include "sf33rd/Source/Game/EX_DATA.h"
#include "sf33rd/Source/Game/Entry.h"
#include "sf33rd/Source/Game/SYS_sub.h"
#include "sf33rd/Source/Game/SYS_sub2.h"
#include "sf33rd/Source/Game/main.h"
#include "sf33rd/Source/Game/texgroup.h"
#include "unknown.h"

void After_Title(struct _TASK *task_ptr);
void In_Game(struct _TASK *task_ptr);
void Wait_Load_Save(struct _TASK *task_ptr);
void Wait_Replay_Check(struct _TASK *task_ptr);
void Disp_Auto_Save(struct _TASK *task_ptr);
void Suspend_Menu();
void Wait_Replay_Load();
void Training_Menu(struct _TASK *task_ptr);
void After_Replay(struct _TASK *task_ptr);
void Disp_Auto_Save2(struct _TASK *task_ptr);
void Wait_Pause_in_Tr(struct _TASK *task_ptr);
void Reset_Training(struct _TASK *task_ptr);
void Reset_Replay(struct _TASK *task_ptr);
void End_Replay_Menu(struct _TASK *task_ptr);
void Mode_Select(struct _TASK *task_ptr);
void Option_Select(struct _TASK *task_ptr);
void Training_Mode(struct _TASK *task_ptr);
void System_Direction(struct _TASK *task_ptr);
void Load_Replay(struct _TASK *task_ptr);
void toSelectGame(struct _TASK *task_ptr);
void Game_Option(struct _TASK *task_ptr);
void Button_Config(struct _TASK *task_ptr);
void Screen_Adjust(struct _TASK *task_ptr);
void Sound_Test(struct _TASK *task_ptr);
void Memory_Card(struct _TASK *task_ptr);
void Extra_Option(struct _TASK *task_ptr);
void VS_Result(struct _TASK *task_ptr);
void Save_Replay(struct _TASK *task_ptr);
void Direction_Menu(struct _TASK *task_ptr);
void Save_Direction(struct _TASK *task_ptr);
void Load_Direction(struct _TASK *task_ptr);
void Setup_VS_Mode(struct _TASK *task_ptr);
void Setup_Next_Page(struct _TASK *task_ptr, s32 /* unused */);
void Load_Replay_Sub(struct _TASK *task_ptr);
void Button_Exit_Check(struct _TASK *task_ptr, s16 PL_id);

void bg_etc_write_ex(s16 type);
void Decide_PL(s16 PL_id);
void imgSelectGameButton();
void jmpRebootProgram();

void Menu_in_Sub(struct _TASK *task_ptr);
s32 Exit_Sub(struct _TASK *task_ptr, s16 cursor_ix, s16 next_routine);
u16 MC_Move_Sub(u16 sw, s16 cursor_id, s16 menu_max, s16 cansel_menu);
s32 Menu_Sub_case1(struct _TASK *task_ptr);
void System_Dir_Move_Sub(s16 PL_id);
void System_Dir_Move_Sub_LR(u16 sw, s16 cursor_id);
void Dir_Move_Sub(struct _TASK *task_ptr, s16 PL_id);
u16 Dir_Move_Sub2(u16 sw);
void Dir_Move_Sub_LR(u16 sw, s16 /* unused */);
void Ex_Move_Sub_LR(u16 sw, s16 PL_id);
u16 Game_Option_Sub(s16 PL_id);
u16 GO_Move_Sub_LR(u16 sw, s16 cursor_id);
void Button_Config_Sub(s16 PL_id);
void Button_Move_Sub_LR(u16 sw, s16 cursor_id);
void Return_Option_Mode_Sub(struct _TASK *task_ptr);
void Screen_Adjust_Sub(s16 PL_id);
void Screen_Exit_Check(struct _TASK *task_ptr, s16 PL_id);
void Screen_Move_Sub_LR(u16 sw);
void Setup_Sound_Mode(u8 last_mode);
u16 Sound_Cursor_Sub(s16 PL_id);
u16 SD_Move_Sub_LR(u16 sw);
void Memory_Card_Sub(s16 PL_id);
void Save_Load_Menu(struct _TASK *task_ptr);
void Go_Back_MC(struct _TASK *task_ptr);
u16 Memory_Card_Move_Sub_LR(u16 sw, s16 cursor_id);

typedef void (*MenuFunc)(struct _TASK *);

typedef struct {
    // total size: 0x8
    s16 pos_x; // offset 0x0, size 0x2
    s8 *menu;  // offset 0x4, size 0x4
} LetterData;

const MenuFunc Menu_Jmp_Tbl[16] = {
    After_Title,   In_Game,      Wait_Load_Save,  Wait_Replay_Check, Disp_Auto_Save, Suspend_Menu, Wait_Replay_Load,
    Training_Menu, After_Replay, Disp_Auto_Save2, Wait_Pause_in_Tr,  Reset_Training, Reset_Replay, End_Replay_Menu,
};

void Menu_Task(struct _TASK *task_ptr) {
    if (nowSoftReset()) {
        return;
    }

    if (Interface_Type[0] == 0 || Interface_Type[1] == 0) {
        Connect_Status = 0;
    } else {
        Connect_Status = 1;
    }

    Setup_Pad_or_Stick();
    IO_Result = 0;
    Menu_Jmp_Tbl[task_ptr->r_no[0]](task_ptr);
}

void Setup_Pad_or_Stick() {
    ((u16 *)plsw_00)[0] = PLsw[0][0];
    ((u16 *)plsw_01)[0] = PLsw[0][1];
    ((u16 *)plsw_00)[1] = PLsw[1][0];
    ((u16 *)plsw_01)[1] = PLsw[1][1];
}

void After_Title(struct _TASK *task_ptr) {
    void (*AT_Jmp_Tbl[21])() = { Menu_Init,        Mode_Select,   Option_Select, Option_Select,  Training_Mode,
                                 System_Direction, Load_Replay,   Option_Select, toSelectGame,   Game_Option,
                                 Button_Config,    Screen_Adjust, Sound_Test,    Memory_Card,    Extra_Option,
                                 Option_Select,    VS_Result,     Save_Replay,   Direction_Menu, Save_Direction,
                                 Load_Direction };

    AT_Jmp_Tbl[task_ptr->r_no[1]](task_ptr);
}

void Menu_Init(struct _TASK *task_ptr) {
    s16 ix;
    s16 fade_on;

    if (Pause_Type == 2) {
        task_ptr->r_no[1] = 4;
    } else {
        task_ptr->r_no[1] = 1;
    }

    task_ptr->r_no[2] = 0;
    task_ptr->r_no[3] = 0;
    Menu_Cursor_Y[0] = 0;
    Menu_Cursor_Y[1] = 0;

    for (ix = 0; ix < 4; ix++) {
        Menu_Suicide[ix] = 0;
        Unsubstantial_BG[ix] = 0;
        Cursor_Y_Pos[0][ix] = 0;
    }

    All_Clear_Suicide();
    pulpul_stop();

    if (task_ptr->r_no[0] == 0) {
        FadeOut(1, 0xFF, 8);
        bg_etc_write_ex(2);
        Setup_Virtual_BG(0, 0x200, 0);
        Setup_BG(1, 0x200, 0);
        Setup_BG(2, 0x200, 0);
        base_y_pos = 0;

        if (task_ptr->r_no[1] != 0x12) {
            fade_on = 0;
        } else {
            fade_on = 1;
        }

        Order[0x4E] = 5;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x4E, 0, 0, 0x45, fade_on);
        load_any_texture_patnum(0x7F30, 0xC, 0);
        setup_pos_remake_key(0);
    }

    cpReadyTask(6, Saver_Task);
}

void Mode_Select(struct _TASK *task_ptr) {
    s16 ix;
    s16 PL_id;
    s16 loop_counter = 7;

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 8);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Mode_Type = 0;
        Present_Mode = 1;

        if (task[1].condition != 1) {
            E_No[0] = 1;
            E_No[1] = 2;
            E_No[2] = 2;
            E_No[3] = 0;
            cpReadyTask(1, Entry_Task);
        }

        Menu_Common_Init();

        for (ix = 0; ix < 4; ix++) {
            Menu_Suicide[ix] = 0;
        }

        Clear_Personal_Data(0);
        Clear_Personal_Data(1);
        Menu_Cursor_Y[0] = Cursor_Y_Pos[0][0];
        Cursor_Y_Pos[0][1] = 0;
        Cursor_Y_Pos[0][2] = 0;
        Cursor_Y_Pos[0][3] = 0;

        for (ix = 0; ix < 4; ix++) {
            Vital_Handicap[ix][0] = 7;
            Vital_Handicap[ix][1] = 7;
        }

        VS_Stage = 0x14;
        Order[0x8A] = 4;
        Order_Timer[0x8A] = 1;

        for (ix = 0; ix < 4; ix++) {
            Message_Data[ix].order = 3;
        }

        effect_57_init(0x64, 0, 0, 0x3F, 2);
        Order[0x64] = 1;
        Order_Dir[0x64] = 8;
        Order_Timer[0x64] = 1;
        Menu_Suicide[0] = 0;
        effect_04_init(0, 0, 0, 0x48);

        for (ix = 0; ix < loop_counter; ix++) {
            effect_61_init(0, ix + 0x50, 0, 0, (u32)ix, ix, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
        }

        Menu_Cursor_Move = loop_counter;
        break;

    case 1:
        if (Menu_Sub_case1(task_ptr) != 0) {
            Order[0x4E] = 2;
            Order_Dir[0x4E] = 0;
            Order_Timer[0x4E] = 1;
            checkAdxFileLoaded();
            checkSelObjFileLoaded();
        }

        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        if (Connect_Status == 0 && Menu_Cursor_Y[0] == 1) {
            Menu_Cursor_Y[0] = 2;
        } else {
            PL_id = 0;

            if (MC_Move_Sub(Check_Menu_Lever(0, 0), 0, loop_counter - 1, 1) == 0) {
                PL_id = 1;
                MC_Move_Sub(Check_Menu_Lever(1, 0), 0, loop_counter - 1, 1);
            }
        }

        switch (IO_Result) {
        case 0x100:
            switch (Menu_Cursor_Y[0]) {
            case 0:
                G_No[2] += 1;
                Mode_Type = 0;
                task_ptr->r_no[0] = 5;
                cpExitTask(6);
                Decide_PL(PL_id);
                break;

            case 1:
                Setup_VS_Mode(task_ptr);
                G_No[1] = 0xC;
                G_No[2] = 1;
                Mode_Type = 1;
                cpExitTask(3);
                break;

            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                task_ptr->r_no[2] += 1;
                task_ptr->free[0] = 0;
                task_ptr->free[1] = Menu_Cursor_Y[0] + 2;
                break;

            default:
                break;
            }

            SE_selected();
            break;
        }

        break;

    default:
        Exit_Sub(task_ptr, 0, task_ptr->free[1]);
        break;
    }
}

void Setup_VS_Mode(struct _TASK *task_ptr) {
    task_ptr->r_no[0] = 5;
    cpExitTask(6);
    plw->wu.operator= 1;
    plw[1].wu.operator= 1;
    Operator_Status[0] = 1;
    Operator_Status[1] = 1;
    grade_check_work_1st_init(0, 0);
    grade_check_work_1st_init(0, 1);
    grade_check_work_1st_init(1, 0);
    grade_check_work_1st_init(1, 1);
    Setup_Training_Difficulty();
}

void Menu_in_Sub(struct _TASK *task_ptr) {
    FadeOut(1, 0xFF, 8);
    task_ptr->r_no[2] += 1;
    task_ptr->timer = 5;
    Menu_Common_Init();
    Menu_Cursor_Y[0] = Cursor_Y_Pos[0][1];
    Menu_Suicide[0] = 1;
    Menu_Suicide[1] = 0;
    Order[0x64] = 4;
    Order_Timer[0x64] = 1;
}

void toSelectGame(struct _TASK *task_ptr) {
    u16 sw;

    switch (task_ptr->r_no[2]) {
    case 0:
        Forbid_Reset = 1;
        Menu_in_Sub(task_ptr);
        Setup_BG(1, 0x200, 0);
        effect_66_init(0x8A, 8, 1, 0, -1, -1, -0x7FF2);
        Order[0x8A] = 3;
        Order_Timer[0x8A] = 1;
        task_ptr->free[0] = 0;
        task_ptr->timer = 0x10;
        break;

    case 1:
        if (Menu_Sub_case1(task_ptr) != 0) {
            Message_Data->kind_req = 5;
            Message_Data->request = 0;
            Message_Data->order = 1;
            Message_Data->timer = 2;
            Message_Data->pos_x = 0;
            Message_Data->pos_y = 0xA0;
            Message_Data->pos_z = 0x18;
            effect_45_init(0, 0, 2);
        }

        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
        }

        imgSelectGameButton();
        break;

    case 3:
        imgSelectGameButton();
        sw = (~(*(u16 *)&plsw_01[0]) & (*(u16 *)&plsw_00[0])) |
             (~(*(u16 *)&plsw_01[2]) & (*(u16 *)&plsw_00[2])); // potential macro
        sw &= 0x300;

        if (sw != 0) {
            if (sw != 0x300) {
                if (sw & 0x100) {
                    task_ptr->free[0] = 1;
                }

                SE_selected();
                FadeInit();
                task_ptr->r_no[2] = 8;
                break;
            }
        }

        break;

    case 8:
        imgSelectGameButton();

        if (FadeOut(1, 0x19, 8) != 0) {
            if (task_ptr->free[0]) {
                task_ptr->r_no[2] = 0xA;
                sound_all_off();
                break;
            }

            task_ptr->r_no[2] = 9;
            break;
        }

        break;

    case 9:
        Menu_Suicide[0] = 0;
        Menu_Suicide[1] = 1;
        task_ptr->r_no[1] = 1;
        task_ptr->r_no[2] = 0;
        task_ptr->r_no[3] = 0;
        task_ptr->free[0] = 0;
        FadeOut(1, 0xFF, 8);
        Forbid_Reset = 0;
        break;

    case 10:
        Exit_sound_system();
        task_ptr->r_no[2] += 1;
        break;

    default:
        jmpRebootProgram();
        break;
    }
}

void jmpRebootProgram() {
    Reboot_Program("cdrom0:\\SLUS_209.49;1");
}

void imgSelectGameButton() {
    dispButtonImage2(0x74, 0x6B, 0x18, 0x20, 0x1A, 0, 4);
    dispButtonImage2(0xB2, 0x6B, 0x18, 0x20, 0x1A, 0, 5);
}

void Training_Mode(struct _TASK *task_ptr) {
    s16 ix;
    s16 char_index;
    s16 PL_id;

    s16 unused_s4;
    s16 unused_s3;

    switch (task_ptr->r_no[2]) {
    case 0:
        Menu_in_Sub(task_ptr);
        mpp_w.initTrainingData = 1;
        effect_57_init(0x6F, 0xB, 0, 0x3F, 2);
        Order[0x6F] = 1;
        Order_Dir[0x6F] = 8;
        Order_Timer[0x6F] = 1;
        effect_04_init(1, 5, 0, 0x48);

        ix = 0;
        unused_s4 = char_index = 0x35;

        while (ix < 3) {
            effect_61_init(0, ix + 0x50, 0, 1, char_index, ix, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
            ix++;
            unused_s3 = char_index++;
        }

        Menu_Cursor_Move = 3;
        system_dir[4] = system_dir[1];
        system_dir[5] = system_dir[1];
        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        PL_id = 0;

        if (MC_Move_Sub(Check_Menu_Lever(0, 0), 0, 2, 0xFF) == 0) {
            PL_id = 1;
            MC_Move_Sub(Check_Menu_Lever(1, 0), 0, 2, 0xFF);
        }

        switch (IO_Result) {
        case 0x100:
        case 0x200:
            break;

        default:
            return;
        }

        SE_selected();

        if (Menu_Cursor_Y[0] == 2 || IO_Result == 0x200) {
            Menu_Suicide[0] = 0;
            Menu_Suicide[1] = 1;
            task_ptr->r_no[1] = 1;
            task_ptr->r_no[2] = 0;
            task_ptr->r_no[3] = 0;
            task_ptr->free[0] = 0;
            Order[0x6F] = 4;
            Order_Timer[0x6F] = 4;
            break;
        }

        Decide_ID = PL_id;

        if (Menu_Cursor_Y[0] == 0) {
            Mode_Type = 3;
            Present_Mode = 4;
        } else {
            Mode_Type = 4;
            Present_Mode = 5;
        }

        Setup_VS_Mode(task_ptr);
        G_No[2] += 1;
        task_ptr->r_no[0] = 5;
        cpExitTask(6);
        Champion = PL_id;
        Pause_ID = PL_id;
        Training_ID = PL_id;
        New_Challenger = PL_id ^ 1;
        cpExitTask(1);

        break;
    }
}

void Option_Select(struct _TASK *task_ptr) {
    s16 ix;         // r16
    s16 char_index; // r17

    s16 unused_s5;
    s16 unused_s4;
    s16 unused_s3;
    s16 unused_s2;

    switch (task_ptr->r_no[2]) {
    case 0:
        Menu_in_Sub(task_ptr);
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 0;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x4F, 1, 0, 0x3F, 2);
        Order[0x4F] = 1;
        Order_Dir[0x4F] = 8;
        Order_Timer[0x4F] = 1;

        if (save_w[Present_Mode].Extra_Option == 0) {
            effect_04_init(1, 4, 0, 0x48);

            ix = 0;
            unused_s5 = char_index = 0x2F;

            while (ix < 6) {
                effect_61_init(0, ix + 0x50, 0, 1, char_index, ix, 0x7047);
                Order[ix + 0x50] = 1;
                Order_Dir[ix + 0x50] = 4;
                Order_Timer[ix + 0x50] = ix + 0x14;
                ix++;
                unused_s4 = char_index++;
            }

            Menu_Cursor_Move = 6;
            break;
        }

        effect_04_init(1, 1, 0, 0x48);

        ix = 0;
        unused_s3 = char_index = 7;

        while (ix < 7) {
            effect_61_init(0, ix + 0x50, 0, 1, char_index, ix, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
            ix++;
            unused_s2 = char_index++;
        }

        Menu_Cursor_Move = 7;
        break;

    case 1:
        if (Menu_Sub_case1(task_ptr) != 0) {
            checkSelObjFileLoaded();
        }

        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        if (save_w[Present_Mode].Extra_Option) {
            ix = 1;
        } else {
            ix = 0;
        }

        if (MC_Move_Sub(Check_Menu_Lever(0, 0), 0, ix + 5, 0xFF) == 0) {
            MC_Move_Sub(Check_Menu_Lever(1, 0), 0, ix + 5, 0xFF);
        }

        switch (IO_Result) {
        case 0x100:
        case 0x200:
            break;

        default:
            return;
        }

        SE_selected();

        if (Menu_Cursor_Y[0] == ix + 5 || IO_Result == 0x200) {
            Menu_Suicide[0] = 0;
            Menu_Suicide[1] = 1;
            task_ptr->r_no[1] = 1;
            task_ptr->r_no[2] = 0;
            task_ptr->r_no[3] = 0;
            task_ptr->free[0] = 0;
            Order[0x4F] = 4;
            Order_Timer[0x4F] = 4;

            if (Check_Change_Contents()) {
                if (save_w[Present_Mode].Auto_Save) {
                    task_ptr->r_no[0] = 4;
                    task_ptr->r_no[1] = 0;
                    Forbid_Reset = 1;
                    Copy_Check_w();
                    break;
                }
            }

            break;
        }

        task_ptr->r_no[2] += 1;
        task_ptr->free[0] = 0;
        X_Adjust_Buff[0] = X_Adjust;
        X_Adjust_Buff[1] = X_Adjust;
        X_Adjust_Buff[2] = X_Adjust;
        Y_Adjust_Buff[0] = Y_Adjust;
        Y_Adjust_Buff[1] = Y_Adjust;
        Y_Adjust_Buff[2] = Y_Adjust;
        Correct_X[1] = Correct_X[0];
        Correct_X[2] = Correct_X[0];
        Correct_X[3] = Correct_X[0];
        Correct_Y[1] = Correct_Y[0];
        Correct_Y[2] = Correct_Y[0];
        Correct_Y[3] = Correct_Y[0];
        break;

    default:
        Exit_Sub(task_ptr, 1, Menu_Cursor_Y[0] + 9);
        break;
    }
}

void System_Direction(struct _TASK *task_ptr) {
    s16 ix;
    s16 char_index;

    s16 unused_s3;
    s16 unused_s2;

    switch (task_ptr->r_no[2]) {
    case 0:
        Menu_in_Sub(task_ptr);
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 3;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x6D, 0xA, 0, 0x3F, 2);
        Order[0x6D] = 1;
        Order_Dir[0x6D] = 8;
        Order_Timer[0x6D] = 1;
        effect_04_init(1, 3, 0, 0x48);
        Convert_Buff[3][0][0] = Direction_Working[1];
        effect_64_init(0x61U, 0, 1, 0xA, 0, 0x7047, 0xB, 3, 0);
        Order[0x61] = 1;
        Order_Dir[0x61] = 4;
        Order_Timer[0x61] = 0x14;

        ix = 0;
        unused_s3 = char_index = 0x2B;

        while (ix < 4) {
            effect_61_init(0, ix + 0x50, 0, 1, char_index, ix + 1, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x15;
            ix++;
            unused_s2 = char_index++;
        }

        Menu_Cursor_Move = 4;
        Page_Max = Check_SysDir_Page();
        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        System_Dir_Move_Sub(0);

        if (IO_Result == 0) {
            System_Dir_Move_Sub(1);
        }

        switch (IO_Result) {
        case 0x100:
            if (Menu_Cursor_Y[0] == 0) {
                break;
            }

            // fallthrough

        case 0x200:
            SE_selected();
            Order[0x6D] = 4;
            Order_Timer[0x6D] = 4;

            if (Menu_Cursor_Y[0] == 4 || IO_Result == 0x200) {
                Menu_Suicide[0] = 0;
                Menu_Suicide[1] = 1;
                task_ptr->r_no[1] = 1;
                task_ptr->r_no[2] = 0;
                task_ptr->r_no[3] = 0;
                task_ptr->free[0] = 0;
                break;
            }

            task_ptr->r_no[2] += 1;
            task_ptr->free[0] = 0;

            break;
        }

        break;

    default:
        Exit_Sub(task_ptr, 1, Menu_Cursor_Y[0] + 0x11);
        break;
    }
}

void System_Dir_Move_Sub(s16 PL_id) {
    u16 sw = ~((u16 *)plsw_01)[PL_id] & ((u16 *)plsw_00)[PL_id]; // potential macro
    sw = Check_Menu_Lever(PL_id, 0);
    MC_Move_Sub(sw, 0, 4, 0xFF);
    System_Dir_Move_Sub_LR(sw, 0);
    Direction_Working[1] = Convert_Buff[3][0][0];
    Direction_Working[4] = Convert_Buff[3][0][0];
    Direction_Working[5] = Convert_Buff[3][0][0];
}

void System_Dir_Move_Sub_LR(u16 sw, s16 cursor_id) {
    if (Menu_Cursor_Y[cursor_id] != 0) {
        return;
    }

    switch (sw) {
    case 4:
        Convert_Buff[3][cursor_id][Menu_Cursor_Y[cursor_id]] -= 1;

        if (Convert_Buff[3][cursor_id][Menu_Cursor_Y[cursor_id]] < 0) {
            Convert_Buff[3][cursor_id][Menu_Cursor_Y[cursor_id]] = 1;
        }

        SE_dir_cursor_move();
        return;

    case 8:
        Convert_Buff[3][cursor_id][Menu_Cursor_Y[cursor_id]] += 1;

        if (Convert_Buff[3][cursor_id][Menu_Cursor_Y[cursor_id]] > 1) {
            Convert_Buff[3][cursor_id][Menu_Cursor_Y[cursor_id]] = 0;
        }

        SE_dir_cursor_move();
        return;
    }
}

void Direction_Menu(struct _TASK *task_ptr) {
    Menu_Cursor_Y[1] = Menu_Cursor_Y[0];

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 8);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Menu_Page = 0;
        Menu_Page_Buff = Menu_Page;
        Message_Data->kind_req = 3;
        break;

    case 1:
        FadeOut(1, 0xFF, 8);
        task_ptr->r_no[2] += 1;
        Setup_Next_Page(task_ptr, 0);
        /* fallthrough */

    case 2:
        FadeOut(1, 0xFF, 8);

        if (--task_ptr->timer == 0) {
            task_ptr->r_no[2] += 1;
            FadeInit();
        }

        break;

    case 3:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
        }

        break;

    case 4:
        Pause_ID = 0;

        Dir_Move_Sub(task_ptr, 0);

        if (IO_Result == 0) {
            Pause_ID = 1;
            Dir_Move_Sub(task_ptr, 1);
        }

        if (Menu_Cursor_Y[1] != Menu_Cursor_Y[0]) {
            SE_cursor_move();
            system_dir[1].contents[Menu_Page][Menu_Max] = 1;

            if (Menu_Cursor_Y[0] < Menu_Max) {
                Message_Data->order = 1;
                Message_Data->request = Menu_Page * 0xC + Menu_Cursor_Y[0] * 2 + 1;
                Message_Data->timer = 2;

                if (msgSysDirTbl[0]->msgNum[Menu_Page * 0xC + Menu_Cursor_Y[0] * 2 + 1] == 1) {
                    Message_Data->pos_y = 0x36;
                } else {
                    Message_Data->pos_y = 0x3E;
                }
            } else {
                Message_Data->order = 1;
                Message_Data->request = system_dir[1].contents[Menu_Page][Menu_Max] + 0x74;
                Message_Data->timer = 2;
                Message_Data->pos_y = 0x36;
            }
        }

        switch (IO_Result) {
        case 0x200:
            task_ptr->r_no[2] += 1;
            Menu_Suicide[0] = 0;
            Menu_Suicide[1] = 0;
            Menu_Suicide[2] = 1;
            SE_dir_selected();
            break;

        case 0x80:
        case 0x800:
            task_ptr->r_no[2] = 1;
            task_ptr->timer = 5;

            if (--Menu_Page < 0) {
                Menu_Page = (s8)Page_Max;
            }

            SE_dir_selected();
            break;

        case 0x40:
        case 0x400:
            task_ptr->r_no[2] = 1;
            task_ptr->timer = 5;

            if (++Menu_Page > Page_Max) {
                Menu_Page = 0;
            }

            SE_dir_selected();
            break;

        case 0x100:
            if (Menu_Cursor_Y[0] == Menu_Max) {
                switch (system_dir[1].contents[Menu_Page][Menu_Max]) {
                case 0:
                    task_ptr->r_no[2] = 1;
                    task_ptr->timer = 5;

                    if (--Menu_Page < 0) {
                        Menu_Page = (s8)Page_Max;
                    }

                    break;

                case 2:
                    task_ptr->r_no[2] = 1;
                    task_ptr->timer = 5;

                    if (++Menu_Page > Page_Max) {
                        Menu_Page = 0;
                    }

                    break;

                default:
                    task_ptr->r_no[2] += 1;
                    Menu_Suicide[0] = 0;
                    Menu_Suicide[1] = 0;
                    Menu_Suicide[2] = 1;
                    break;
                }

                SE_selected();
                break;
            }

            break;
        }

        break;

    default:
        Exit_Sub(task_ptr, 2, 5);
        break;
    }
}

void Dir_Move_Sub(struct _TASK *task_ptr, s16 PL_id) {
    u16 sw;
    u16 ix;

    ((u16 *)plsw_00)[0] = PLsw[0][0];
    ((u16 *)plsw_01)[0] = PLsw[0][1];
    ((u16 *)plsw_00)[1] = PLsw[1][0];
    ((u16 *)plsw_01)[1] = PLsw[1][1];

    for (ix = 0; ix < 2; ix++) {
        ((u16 *)plsw_00)[ix] &= 0x4FFF;
        ((u16 *)plsw_01)[ix] &= 0x4FFF;
    }

    sw = Check_Menu_Lever(PL_id, 0);
    Dir_Move_Sub2(sw);

    if (task_ptr->r_no[1] == 0xE) {
        Ex_Move_Sub_LR(sw, PL_id);
        return;
    }

    Dir_Move_Sub_LR(sw, PL_id);
}

u16 Dir_Move_Sub2(u16 sw) {
    if (Menu_Cursor_Move > 0) {
        return 0;
    }

    switch (sw) {
    case 0x1:
        Menu_Cursor_Y[0] -= 1;

        if (Menu_Cursor_Y[0] < 0) {
            Menu_Cursor_Y[0] = Menu_Max;
        }

        SE_cursor_move();
        return IO_Result = 1;

    case 0x2:
        Menu_Cursor_Y[0] += 1;

        if (Menu_Cursor_Y[0] > Menu_Max) {
            Menu_Cursor_Y[0] = 0;
        }

        SE_cursor_move();
        return IO_Result = 2;

    case 0x10:
        return IO_Result = 0x10;

    case 0x20:
        return IO_Result = 0x20;

    case 0x40:
        return IO_Result = 0x40;

    case 0x80:
        return IO_Result = 0x80;

    case 0x100:
        return IO_Result = 0x100;

    case 0x200:
        return IO_Result = 0x200;

    case 0x400:
        return IO_Result = 0x400;

    case 0x800:
        return IO_Result = 0x800;

    case 0x4000:
        return IO_Result = 0x4000;

    default:
        return IO_Result = 0;
    }
}

void Dir_Move_Sub_LR(u16 sw, s16 /* unused */) {
    u8 last_pos = system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]];

    switch (sw) {
    case 0x4:
        SE_dir_cursor_move();
        system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] -= 1;

        if (Menu_Cursor_Y[0] == Menu_Max) {
            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] < 0) {
                system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] = 0;
                IO_Result = 0x80;
                return;
            }

            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] != last_pos) {
                Message_Data->order = 1;
                Message_Data->request = system_dir[1].contents[Menu_Page][Menu_Max] + 0x74;
                Message_Data->timer = 2;
            }
        } else {
            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] < 0) {
                system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] = Dir_Menu_Max_Data[Menu_Page][Menu_Cursor_Y[0]];
            }
        }

        return;

    case 0x8:
        SE_dir_cursor_move();
        system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] += 1;

        if (Menu_Cursor_Y[0] == Menu_Max) {
            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] > 2) {
                system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] = 2;
                IO_Result = 0x400;
                return;
            }

            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] > 2) {
                system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] = 2;
            }

            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] != last_pos) {
                Message_Data->order = 1;
                Message_Data->request = system_dir[1].contents[Menu_Page][Menu_Max] + 0x74;
                Message_Data->timer = 2;
            }
        } else {
            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] > Dir_Menu_Max_Data[Menu_Page][Menu_Cursor_Y[0]]) {
                system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] = 0;
            }
        }

        return;

    case 0x100:
        SE_dir_cursor_move();

        if (Menu_Cursor_Y[0] == Menu_Max) {
            return;
        } else {
            system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] += 1;

            if (system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] > Dir_Menu_Max_Data[Menu_Page][Menu_Cursor_Y[0]]) {
                system_dir[1].contents[Menu_Page][Menu_Cursor_Y[0]] = 0;
            }
        }

        return;
    }
}

void Setup_Next_Page(struct _TASK *task_ptr, s32 /* unused */) {
    s16 ix;
    s16 disp_index;
    s16 mode_type;

    s16 unused_s3;

    Menu_Page_Buff = Menu_Page;
    effect_work_init();
    Menu_Common_Init();
    Menu_Cursor_Y[0] = 0;
    Order[0x4E] = 5;
    Order_Timer[0x4E] = 1;

    if (task_ptr->r_no[1] == 0xE) {
        mode_type = 1;
        Menu_Max = Ex_Page_Data[Menu_Page];
        save_w[1].extra_option.contents[Menu_Page][Menu_Max] = 1;
        Order_Dir[0x4E] = 1;
        effect_57_init(0x4E, 1, 0, 0x45, 0);
        Order[0x73] = 3;
        Order_Dir[0x73] = 8;
        Order_Timer[0x73] = 1;
        effect_57_init(0x73, 6, 0, 0x3F, 2);
        effect_66_init(0x5C, 0x27, 2, 0, 0x47, 0xB, 0);
        Order[0x5C] = 3;
        Order_Timer[0x5C] = 1;
        effect_66_init(0x5D, 0x28, 2, 0, 0x40, (s16)Menu_Page + 1, 0);
        Order[0x5D] = 3;
        Order_Timer[0x5D] = 1;

        if ((msgExtraTbl[0]->msgNum[Menu_Cursor_Y[0] + Menu_Page * 8]) == 1) {
            Message_Data->pos_y = 0x36;
        } else {
            Message_Data->pos_y = 0x3E;
        }

        Message_Data->request = Ex_Account_Data[Menu_Page] + Menu_Cursor_Y[0];
    } else {
        mode_type = 0;
        Menu_Max = Page_Data[Menu_Page];
        system_dir[1].contents[Menu_Page][Menu_Max] = 1;
        effect_66_init(0x5B, 0x14, 2, 0, 0x47, 0xA, 0);
        Order[0x5B] = 3;
        Order_Timer[0x5B] = 1;
        Order[0x4E] = 5;
        Order_Dir[0x4E] = 3;
        effect_57_init(0x4E, 0, 0, 0x45, 0);
        effect_66_init(0x5C, 0x15, 2, 0, 0x47, 0xB, 0);
        Order[0x5C] = 3;
        Order_Timer[0x5C] = 1;
        effect_66_init(0x5D, 0x16, 2, 0, 0x40, (s16)Menu_Page + 1, 0);
        Order[0x5D] = 3;
        Order_Timer[0x5D] = 1;

        if ((msgSysDirTbl[0]->msgNum[Menu_Page * 0xC + Menu_Cursor_Y[0] * 2 + 1]) == 1) {
            Message_Data->pos_y = 0x36;
        } else {
            Message_Data->pos_y = 0x3E;
        }

        disp_index = Menu_Page * 0xC;
        Message_Data->request = disp_index + 1;
    }

    Menu_Cursor_Y[0] = 0;
    effect_66_init(0x8A, 0x13, 2, 0, -1, -1, -0x8000);
    Order[0x8A] = 3;
    Order_Timer[0x8A] = 1;
    Message_Data->order = 0;
    Message_Data->timer = 1;
    Message_Data->pos_x = 0;
    Message_Data->pos_z = 0x45;
    effect_45_init(0, 0, 2);

    for (ix = 0; ix < Menu_Max; ix++, unused_s3 = disp_index += 2) {
        if (mode_type == 0) {
            effect_18_init(disp_index, ix, 0, 2);
            effect_51_init(ix, ix, 2);
        } else {
            effect_C4_init(0, ix, ix, 2);

            if (Menu_Page != 0 || ix != (Menu_Max - 1)) {
                effect_C4_init(1, ix, ix, 2);
            }
        }
    }

    effect_40_init(mode_type, 0, 0x48, 0, 2, 1);
    effect_40_init(mode_type, 1, 0x49, 0, 2, 1);
    effect_40_init(mode_type, 2, 0x4A, 0, 2, 0);
    effect_40_init(mode_type, 3, 0x4B, 0, 2, 2);
}

void Save_Direction(struct _TASK *task_ptr) {
    Menu_Cursor_X[1] = Menu_Cursor_X[0];
    Clear_Flash_Sub();

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 8);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Menu_Cursor_X[0] = 0;
        Setup_BG(1, 0x200, 0);
        Setup_Replay_Sub(1, 0x70, 0xA, 2);
        Setup_File_Property(2, 0);
        Clear_Flash_Init(4);
        Message_Data->kind_req = 5;
        break;

    case 1:
        if (Menu_Sub_case1(task_ptr) != 0) {
            SaveInit(1, 1);
        }

        break;

    case 2:
        Setup_Save_Replay_2nd(task_ptr, 2);
        break;

    case 3:
        if (SaveMove() <= 0) {
            IO_Result = 0x200;
            Load_Replay_MC_Sub(task_ptr, 0);
        }

        break;
    }
}

void Load_Direction(struct _TASK *task_ptr) {
    Menu_Cursor_X[1] = Menu_Cursor_X[0];
    Clear_Flash_Sub();

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 8);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Menu_Cursor_X[0] = 0;
        Setup_BG(1, 0x200, 0);
        Setup_Replay_Sub(1, 0x70, 0xA, 2);
        Setup_File_Property(2, 0);
        Clear_Flash_Init(4);
        Message_Data->kind_req = 5;
        break;

    case 1:
        if (Menu_Sub_case1(task_ptr) != 0) {
            SaveInit(1, 0);
        }

        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            task_ptr->free[3] = 0;
            Menu_Cursor_X[0] = Setup_Final_Cursor_Pos(0, 8);
        }

        break;

    case 3:
        if (SaveMove() <= 0) {
            IO_Result = 0x200;
            Load_Replay_MC_Sub(task_ptr, 0);
        }

        break;
    }
}

void Load_Replay(struct _TASK *task_ptr) {
    Menu_Cursor_X[1] = Menu_Cursor_X[0];
    Clear_Flash_Sub();

    switch (task_ptr->r_no[2]) {
    case 0:
        Menu_in_Sub(task_ptr);
        Menu_Cursor_X[0] = 0;
        Setup_BG(1, 0x200, 0);
        Setup_Replay_Sub(1, 0x6E, 9, 1);
        Clear_Flash_Init(4);
        Message_Data->kind_req = 5;
        break;

    case 1:
        if (Menu_Sub_case1(task_ptr) != 0) {
            SaveInit(2, 0);
        }

        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            task_ptr->free[3] = 0;
            Menu_Cursor_X[0] = Setup_Final_Cursor_Pos(0, 8);
        }

        break;

    case 3:
        switch (SaveMove()) {
        case 0:
            Decide_ID = 0;

            if (Interface_Type[0] == 0) {
                Decide_ID = 1;
            }

            task_ptr->r_no[2] += 1;
            task_ptr->r_no[3] = 0;
            break;

        case -1:
            IO_Result = 0x200;
            Load_Replay_MC_Sub(task_ptr, 0);
            break;
        }

        break;

    case 4:
        Load_Replay_Sub(task_ptr);
        break;
    }
}

void Load_Replay_Sub(struct _TASK *task_ptr) {
    s32 ix;

    switch (task_ptr->r_no[3]) {
    case 0:
        task_ptr->r_no[3] += 1;
        Rep_Game_Infor[0xA] = Replay_w.game_infor;
        cpExitTask(1);
        Play_Mode = 3;
        break;

    case 1:
        task_ptr->r_no[3] += 1;
        FadeInit();
        FadeOut(0, 0xFF, 8);
        setup_pos_remake_key(5);
        Play_Type = 1;
        Mode_Type = 5;
        Present_Mode = 3;
        Bonus_Game_Flag = 0;

        for (ix = 0; ix < 2; ix++) {
            plw[ix].wu.operator= Replay_w.game_infor.player_infor[ix].player_type;
            Operator_Status[ix] = Replay_w.game_infor.player_infor[ix].player_type;
            My_char[ix] = Replay_w.game_infor.player_infor[ix].my_char;
            Super_Arts[ix] = Replay_w.game_infor.player_infor[ix].sa;
            Player_Color[ix] = Replay_w.game_infor.player_infor[ix].color;
            Vital_Handicap[3][ix] = Replay_w.game_infor.Vital_Handicap[ix];
        }

        Direction_Working[3] = Replay_w.game_infor.Direction_Working;
        bg_w.stage = Replay_w.game_infor.stage;
        bg_w.area = 0;
        save_w[3].Time_Limit = Replay_w.mini_save_w.Time_Limit;
        save_w[3].Battle_Number[0] = Replay_w.mini_save_w.Battle_Number[0];
        save_w[3].Battle_Number[1] = Replay_w.mini_save_w.Battle_Number[1];
        save_w[3].Damage_Level = Replay_w.mini_save_w.Damage_Level;
        save_w[3].extra_option = Replay_w.mini_save_w.extra_option;
        system_dir[3] = Replay_w.system_dir;
        save_w[3].extra_option = Replay_w.mini_save_w.extra_option;
        save_w[3].Pad_Infor[0] = Replay_w.mini_save_w.Pad_Infor[0];
        save_w[3].Pad_Infor[1] = Replay_w.mini_save_w.Pad_Infor[1];
        save_w[3].Pad_Infor[0].Vibration = 0;
        save_w[3].Pad_Infor[1].Vibration = 0;
        cpExitTask(6);
        break;

    case 2:
        FadeOut(0, 0xFF, 8);
        task_ptr->r_no[3] += 1;
        task_ptr->timer = 0xA;
        System_all_clear_Level_B();
        pulpul_stop();
        init_pulpul_work();
        bg_etc_write(2);
        bg_w.bgw[0].wxy[0].disp.pos += 0x200;
        Setup_BG(0, bg_w.bgw[0].wxy[0].disp.pos, bg_w.bgw[0].wxy[1].disp.pos);
        effect_38_init(0, 0xB, My_char[0], 1, 0);
        Order[0xB] = 3;
        Order_Timer[0xB] = 1;
        effect_38_init(1, 0xC, My_char[1], 1, 0);
        Order[0xC] = 3;
        Order_Timer[0xC] = 1;
        effect_K6_init(0, 0x23, 0x23, 0);
        Order[0x23] = 3;
        Order_Timer[0x23] = 1;
        effect_K6_init(1, 0x24, 0x23, 0);
        Order[0x24] = 3;
        Order_Timer[0x24] = 1;
        effect_39_init(0, 0x11, My_char[0], 0, 0);
        Order[0x11] = 3;
        Order_Timer[0x11] = 1;
        effect_39_init(1, 0x12, My_char[1], 0, 0);
        Order[0x12] = 3;
        Order_Timer[0x12] = 1;
        effect_K6_init(0, 0x1D, 0x1D, 0);
        Order[0x1D] = 3;
        Order_Timer[0x1D] = 1;
        effect_K6_init(1, 0x1E, 0x1D, 0);
        Order[0x1E] = 3;
        Order_Timer[0x1E] = 1;
        effect_43_init(2, 0);
        effect_75_init(0x2A, 3, 0);
        Order[0x2A] = 3;
        Order_Timer[0x2A] = 1;
        Order_Dir[0x2A] = 5;
        break;

    case 3:
        FadeOut(0, 0xFF, 8);

        if (--task_ptr->timer <= 0) {
            task_ptr->r_no[3] += 1;
            bgPalCodeOffset[0] = 0x90;
            BGM_Request(51);
            Purge_memory_of_kind_of_key(0xCU);
            Push_LDREQ_Queue_Player(0, My_char[0]);
            Push_LDREQ_Queue_Player(1, My_char[1]);
            Push_LDREQ_Queue_BG((u16)bg_w.stage);
        }

        break;

    case 4:
        if (FadeIn(0, 4, 8) != 0) {
            task_ptr->r_no[3] += 1;
        }

        break;

    case 5:
        if ((Check_PL_Load() != 0) && (Check_LDREQ_Queue_BG((u16)bg_w.stage) != 0) && (adx_now_playend() != 0) &&
            (sndCheckVTransStatus(0) != 0)) {
            task_ptr->r_no[3] += 1;
            Switch_Screen_Init(0);
            init_omop();
        }

        break;

    case 6:
        if (Switch_Screen(0) != 0) {
            Game01_Sub();
            Cover_Timer = 5;
            appear_type = 1;
            set_hitmark_color();
            Purge_texcash_of_list(3);
            Make_texcash_of_list(3);
            G_No[1] = 2;
            G_No[2] = 0;
            G_No[3] = 0;
            E_No[0] = 4;
            E_No[1] = 0;
            E_No[2] = 0;
            E_No[3] = 0;

            if (plw->wu.operator!= 0) {
                Sel_Arts_Complete[0] = -1;
            }

            if (plw[1].wu.operator!= 0) {
                Sel_Arts_Complete[1] = -1;
            }

            task_ptr->r_no[2] = 0;
            cpExitTask(3);
        }

        break;

    default:
        break;
    }
}

s32 Load_Replay_MC_Sub(struct _TASK *task_ptr, s16 PL_id) {
    u16 sw = IO_Result;

    switch (sw) {
    case 0x100:
        if ((Menu_Cursor_X[0] == -1) || (vm_w.Connect[Menu_Cursor_X[0]] == 0)) {
            break;
        }

        Pause_ID = PL_id;
        vm_w.Drive = (u8)Menu_Cursor_X[0];

        if (VM_Access_Request(6, Menu_Cursor_X[0]) == 0) {
            break;
        }

        SE_selected();
        task_ptr->free[1] = 0;
        task_ptr->free[2] = 0;
        task_ptr->r_no[0] = 3;
        return 1;

    case 0x200:
        if (task_ptr->r_no[1] == 6) {
            Menu_Suicide[0] = 0;
            Menu_Suicide[1] = 1;
            task_ptr->r_no[1] = 1;
            task_ptr->r_no[2] = 0;
            task_ptr->r_no[3] = 0;
            task_ptr->free[0] = 0;
            Order[0x6E] = 4;
            Order_Timer[0x6E] = 4;
        } else {
            Menu_Suicide[0] = 0;
            Menu_Suicide[1] = 0;
            Menu_Suicide[2] = 1;
            task_ptr->r_no[1] = 5;
            task_ptr->r_no[2] = 0;
            task_ptr->r_no[3] = 0;
            task_ptr->free[0] = 0;
            Order[0x70] = 4;
            Order_Timer[0x70] = 4;
        }

        break;
    }

    return 0;
}

const u8 Setup_Index_64[10] = { 1, 2, 3, 3, 4, 5, 6, 7, 8, 8 };

void Game_Option(struct _TASK *task_ptr) {
    s16 char_index;
    s16 ix;

    s16 unused_s3;
    s16 unused_s2;

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 8);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Menu_Common_Init();
        Menu_Cursor_Y[0] = 0;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Menu_Cursor_Y[0] = 0;
        Menu_Cursor_Y[1] = 0;
        Order[0x4F] = 4;
        Order_Timer[0x4F] = 1;
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 2;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x6A, 7, 0, 0x3F, 2);
        Order[0x6A] = 1;
        Order_Dir[0x6A] = 8;
        Order_Timer[0x6A] = 1;

        for (ix = 0, unused_s3 = char_index = 0x19; ix < 0xC; ix++, unused_s2 = char_index++) {
            effect_61_init(0, ix + 0x50, 0, 2, char_index, ix, 0x70A7);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
        }

        Menu_Cursor_Move = 0xA;

        for (ix = 0; ix < 0xA; ix++) {
            effect_64_init(ix + 0x5D, 0, 2, Setup_Index_64[ix], ix, 0x70A7, ix + 1, 0, 0);
            Order[ix + 0x5D] = 1;
            Order_Dir[ix + 0x5D] = 4;
            Order_Timer[ix + 0x5D] = ix + 0x14;
        }

        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        Game_Option_Sub(0);
        Button_Exit_Check(task_ptr, 0);
        Game_Option_Sub(1);
        Button_Exit_Check(task_ptr, 1);
        Save_Game_Data();
        break;

    default:
        Exit_Sub(task_ptr, 2, 5);
        break;
    }
}

u16 Game_Option_Sub(s16 PL_id) {
    u16 sw;
    u16 ret;

    sw = ~((u16 *)plsw_01)[PL_id] & ((u16 *)plsw_00)[PL_id];
    sw = Check_Menu_Lever(PL_id, 0);
    ret = MC_Move_Sub(sw, 0, 0xB, 0xFF);
    ret |= GO_Move_Sub_LR(sw, 0);
    ret &= 0x20F;
    return ret;
}

const u8 Game_Option_Index_Data[10] = { 7, 3, 3, 3, 3, 1, 1, 1, 1, 1 };

u16 GO_Move_Sub_LR(u16 sw, s16 cursor_id) {
    if (Menu_Cursor_Y[cursor_id] > 9) {
        return 0;
    }

    switch (sw) {
    case 4:
        Convert_Buff[0][cursor_id][Menu_Cursor_Y[cursor_id]] -= 1;

        if (Convert_Buff[0][cursor_id][Menu_Cursor_Y[cursor_id]] < 0) {
            Convert_Buff[0][cursor_id][Menu_Cursor_Y[cursor_id]] = Game_Option_Index_Data[Menu_Cursor_Y[cursor_id]];
        }

        SE_dir_cursor_move();
        return 4;

    case 8:
        Convert_Buff[0][cursor_id][Menu_Cursor_Y[cursor_id]] += 1;

        if (Convert_Buff[0][cursor_id][Menu_Cursor_Y[cursor_id]] > Game_Option_Index_Data[Menu_Cursor_Y[cursor_id]]) {
            Convert_Buff[0][cursor_id][Menu_Cursor_Y[cursor_id]] = 0;
        }

        SE_dir_cursor_move();
        return 8;

    default:
        return 0;
    }
}

void Button_Config(struct _TASK *task_ptr) {
    s16 ix;
    s16 disp_index;

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 8);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Menu_Common_Init();
        pp_operator_check_flag(0);
        Menu_Cursor_Y[0] = 0;
        Menu_Cursor_Y[1] = 0;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Copy_Key_Disp_Work();
        Order[0x4F] = 4;
        Order_Timer[0x4F] = 1;
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 2;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x6B, 2, 0, 0x3F, 2);
        Order[0x6B] = 1;
        Order_Dir[0x6B] = 8;
        Order_Timer[0x6B] = 1;

        for (ix = 0; ix < 12; ix++) {
            effect_23_init(0, ix + 0x50, 0, 2, 2, ix, 0x70A7, ix + 9, 1);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
            effect_23_init(1, ix + 0x5C, 0, 2, 3, ix, 0x70A7, ix + 9, 1);
            Order[ix + 0x5C] = 1;
            Order_Dir[ix + 0x5C] = 4;
            Order_Timer[ix + 0x5C] = ix + 0x14;
        }

        for (ix = 0; ix < 9; ix++) {
            if (ix == 8) {
                disp_index = 1;
            } else {
                disp_index = 0;
            }

            effect_23_init(0, ix + 0x78, 0, 2, disp_index, ix, 0x70A7, ix, 0);
            Order[ix + 0x78] = 1;
            Order_Dir[ix + 0x78] = 4;
            Order_Timer[ix + 0x78] = ix + 0x14;
            effect_23_init(1, ix + 0x81, 0, 2, disp_index, ix, 0x70A7, ix, 0);
            Order[ix + 0x81] = 1;
            Order_Dir[ix + 0x81] = 4;
            Order_Timer[ix + 0x81] = ix + 0x14;
        }

        Menu_Cursor_Move = 0x22;
        effect_66_init(0x8A, 7, 2, 0, -1, -1, -0x7FFF);
        Order[0x8A] = 1;
        Order_Dir[0x8A] = 4;
        Order_Timer[0x8A] = 0x14;
        effect_66_init(0x8B, 8, 2, 0, -1, -1, -0x7FFF);
        Order[0x8B] = 1;
        Order_Dir[0x8B] = 4;
        Order_Timer[0x8B] = 0x14;
        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        Button_Config_Sub(0);
        Button_Exit_Check(task_ptr, 0);
        Button_Config_Sub(1);
        Button_Exit_Check(task_ptr, 1);
        Save_Game_Data();
        break;
    }
}

void Button_Config_Sub(s16 PL_id) {
    u16 sw = ~((u16 *)plsw_01)[PL_id] & ((u16 *)plsw_00)[PL_id];
    sw = Check_Menu_Lever(PL_id, 0);
    MC_Move_Sub(sw, PL_id, 0xA, 0xFF);
    Button_Move_Sub_LR(sw, PL_id);

    if (ppwork[0].ok_dev == 0) {
        Convert_Buff[1][0][8] = 0;
    }

    if (ppwork[1].ok_dev == 0) {
        Convert_Buff[1][1][8] = 0;
    }
}

void Button_Move_Sub_LR(u16 sw, s16 cursor_id) {
    s16 max;

    switch (Menu_Cursor_Y[cursor_id]) {
    case 8:
        max = 1;
        break;

    case 9:
    case 10:
        max = 0;
        break;

    default:
        max = 11;
        break;
    }

    if (max == 0) {
        return;
    }

    switch (sw) {
    case 4:
        Convert_Buff[1][cursor_id][Menu_Cursor_Y[cursor_id]] -= 1;

        if (Convert_Buff[1][cursor_id][Menu_Cursor_Y[cursor_id]] < 0) {
            Convert_Buff[1][cursor_id][Menu_Cursor_Y[cursor_id]] = max;
        }

        if (Menu_Cursor_Y[cursor_id] == 8) {
            if (Convert_Buff[1][cursor_id][8]) {
                pp_vib_on(cursor_id);
            } else {
                pulpul_stop2(cursor_id);
            }
        }

        SE_dir_cursor_move();
        break;

    case 8:
        Convert_Buff[1][cursor_id][Menu_Cursor_Y[cursor_id]] += 1;

        if (Convert_Buff[1][cursor_id][Menu_Cursor_Y[cursor_id]] > max) {
            Convert_Buff[1][cursor_id][Menu_Cursor_Y[cursor_id]] = 0;
        }

        if ((Menu_Cursor_Y[cursor_id] == 8) && (Convert_Buff[1][cursor_id][Menu_Cursor_Y[cursor_id]] == 1)) {
            pp_vib_on(cursor_id);
        }

        SE_dir_cursor_move();
        break;
    }
}

void Button_Exit_Check(struct _TASK *task_ptr, s16 PL_id) {
    switch (IO_Result) {
    case 0x200:
    case 0x100:
        break;

    default:
        return;
    }

    switch (task_ptr->r_no[1]) {
    case 9:
        if (Menu_Cursor_Y[0] == 11 || IO_Result == 0x200) {
            SE_selected();
            Return_Option_Mode_Sub(task_ptr);
            Order[0x6A] = 4;
            Order_Timer[0x6A] = 4;
            return;
        }

        if (Menu_Cursor_Y[0] == 10) {
            SE_selected();
            save_w[1].Difficulty = Game_Default_Data.Difficulty;
            save_w[1].Time_Limit = Game_Default_Data.Time_Limit;
            save_w[1].Battle_Number[0] = Game_Default_Data.Battle_Number[0];
            save_w[1].Battle_Number[1] = Game_Default_Data.Battle_Number[1];
            save_w[1].Damage_Level = Game_Default_Data.Damage_Level;
            save_w[1].GuardCheck = Game_Default_Data.GuardCheck;
            save_w[1].AnalogStick = Game_Default_Data.AnalogStick;
            save_w[1].Handicap = Game_Default_Data.Handicap;
            save_w[1].Partner_Type[0] = Game_Default_Data.Partner_Type[0];
            save_w[1].Partner_Type[1] = Game_Default_Data.Partner_Type[1];
            Copy_Save_w();
            return;
        }

        break;

    case 10:
        if ((Menu_Cursor_Y[PL_id] == 10) || (IO_Result == 0x200)) {
            SE_selected();
            Return_Option_Mode_Sub(task_ptr);
            Order[0x6B] = 4;
            Order_Timer[0x6B] = 4;
            return;
        }

        if (Menu_Cursor_Y[PL_id] == 9) {
            SE_selected();
            Setup_IO_ConvDataDefault(PL_id);
            Save_Game_Data();
            return;
        }

        break;

    case 13:
        if (IO_Result == 0x200) {
            SE_selected();
            Return_Option_Mode_Sub(task_ptr);
            Order[0x69] = 4;
            Order_Timer[0x69] = 4;
            return;
        }

        switch (Menu_Cursor_Y[0]) {
        case 3:
            SE_selected();
            Return_Option_Mode_Sub(task_ptr);
            Order[0x69] = 4;
            Order_Timer[0x69] = 4;
            break;

        case 0:
            SE_selected();
            task_ptr->r_no[2] = 4;
            task_ptr->r_no[3] = 0;
            break;

        case 1:
            SE_selected();
            task_ptr->r_no[2] = 5;
            task_ptr->r_no[3] = 0;
            break;

        case 2:
            task_ptr->r_no[2] = 6;
            task_ptr->r_no[3] = 0;
            break;
        }

        break;
    }
}

void Return_Option_Mode_Sub(struct _TASK *task_ptr) {
    Menu_Suicide[1] = 0;
    Menu_Suicide[2] = 1;
    task_ptr->r_no[1] = 7;
    task_ptr->r_no[2] = 0;
    task_ptr->r_no[3] = 0;
    task_ptr->free[0] = 0;
    Cursor_Y_Pos[0][2] = Menu_Cursor_Y[0];
    Cursor_Y_Pos[1][2] = Menu_Cursor_Y[1];
}

void Screen_Adjust(struct _TASK *task_ptr) {
    s16 char_index;
    s16 ix;

    s16 unused_s3;
    s16 unused_s2;

    X_Adjust = X_Adjust_Buff[0];
    X_Adjust_Buff[0] = X_Adjust_Buff[1];
    X_Adjust_Buff[1] = X_Adjust_Buff[2];
    Y_Adjust = Y_Adjust_Buff[0];
    Y_Adjust_Buff[0] = Y_Adjust_Buff[1];
    Y_Adjust_Buff[1] = Y_Adjust_Buff[2];
    Correct_X[0] = Correct_X[1];
    Correct_X[1] = Correct_X[2];
    Correct_X[2] = Correct_X[3];
    Correct_Y[0] = Correct_Y[1];
    Correct_Y[1] = Correct_Y[2];
    Correct_Y[2] = Correct_Y[3];

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 8);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Menu_Common_Init();
        Menu_Cursor_Y[0] = 0;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Order[0x4F] = 4;
        Order_Timer[0x4F] = 1;
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 2;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x65, 3, 0, 0x3F, 2);
        Order[0x65] = 1;
        Order_Dir[0x65] = 8;
        Order_Timer[0x65] = 1;

        for (ix = 0; ix < 5; ix++) {
            effect_63_init(ix + 0x66, 0, 2, ix, ix);
            Order[ix + 0x66] = 1;
            Order_Dir[ix + 0x66] = 4;
            Order_Timer[ix + 0x66] = ix + 0x14;
        }

        for (ix = 0, unused_s3 = char_index = 0xE; ix < 7; ix++, unused_s2 = char_index++) {
            effect_61_init(0, ix + 0x50, 0, 2, char_index, ix, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
        }

        Menu_Cursor_Move = 5;
        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        Screen_Adjust_Sub(0);
        Screen_Exit_Check(task_ptr, 0);

        if (IO_Result == 0) {
            Screen_Adjust_Sub(1);
            Screen_Exit_Check(task_ptr, 0);
        }

        Save_Game_Data();
        break;
    }
}

void Screen_Adjust_Sub(s16 PL_id) {
    u16 sw;
    sw = ~((u16 *)plsw_01)[PL_id] & ((u16 *)plsw_00)[PL_id];
    sw = Check_Menu_Lever(PL_id, 0);
    MC_Move_Sub(sw, 0, 6, 0xFF);
    Screen_Move_Sub_LR(sw);
    Convert_Buff[2][0][0] = X_Adjust_Buff[2] & 0xFF;
    Convert_Buff[2][0][1] = Y_Adjust_Buff[2] & 0xFF;
    Convert_Buff[2][0][2] = dspwhPack(Disp_Size_H, Disp_Size_V);
    save_w[1].Screen_Size = dspwhPack(Disp_Size_H, Disp_Size_V);
    Convert_Buff[2][0][3] = sys_w.screen_mode;
    save_w[1].Screen_Mode = sys_w.screen_mode;
}

void Screen_Exit_Check(struct _TASK *task_ptr, s16 PL_id) {
    switch (IO_Result) {
    case 0x200:
    case 0x100:
        break;

    default:
        return;
    }

    if (Menu_Cursor_Y[0] == 6 || IO_Result == 0x200) {
        SE_selected();
        Menu_Suicide[1] = 0;
        Menu_Suicide[2] = 1;
        Correct_X[0] = Correct_X[3];
        Correct_X[1] = Correct_X[3];
        Correct_X[2] = Correct_X[3];
        Correct_Y[0] = Correct_Y[3];
        Correct_Y[1] = Correct_Y[3];
        Correct_Y[2] = Correct_Y[3];
        X_Adjust = X_Adjust_Buff[2];
        Y_Adjust = Y_Adjust_Buff[2];
        Return_Option_Mode_Sub(task_ptr);

        if (task_ptr->r_no[0] == 1) {
            task_ptr->r_no[1] = 1;
        } else {
            task_ptr->r_no[1] = 7;
            Order[0x65] = 4;
            Order_Timer[0x65] = 4;
        }

        task_ptr->r_no[2] = 0;
        task_ptr->r_no[3] = 0;
        task_ptr->free[0] = 0;
        return;
    }

    if (Menu_Cursor_Y[PL_id] == 5) {
        SE_selected();
        X_Adjust_Buff[2] = 0;
        Y_Adjust_Buff[2] = 0;
        Disp_Size_H = 0x64;
        Disp_Size_V = 0x64;
        Setup_Disp_Size(0);
        sys_w.screen_mode = 1;
    }
}

void Screen_Move_Sub_LR(u16 sw) {
    s16 flag = 0;

    if (sw == 4) {
        switch (Menu_Cursor_Y[0]) {
        case 0:
            X_Adjust_Buff[2] -= 2;

            if (X_Adjust_Buff[2] < -10) {
                X_Adjust_Buff[2] = -10;
            } else {
                flag = 1;
            }

            break;

        case 1:
            Y_Adjust_Buff[2] -= 2;

            if (Y_Adjust_Buff[2] < -10) {
                Y_Adjust_Buff[2] = -10;
            } else {
                flag = 1;
            }

            break;

        case 2:
            Disp_Size_H -= 2;

            if (Disp_Size_H < 94) {
                Disp_Size_H = 94;
            } else {
                flag = 1;
            }

            Setup_Disp_Size(1);
            break;

        case 3:
            Disp_Size_V -= 2;

            if (Disp_Size_V < 94) {
                Disp_Size_V = 94;
            } else {
                flag = 1;
            }

            Setup_Disp_Size(1);
            break;

        case 4:
            sys_w.screen_mode = (sys_w.screen_mode + 1) & 1;
            flag = 1;
            break;
        }
    } else if (sw == 8) {
        switch (Menu_Cursor_Y[0]) {
        case 0:
            X_Adjust_Buff[2] += 2;

            if (X_Adjust_Buff[2] > 10) {
                X_Adjust_Buff[2] = 10;
            } else {
                flag = 1;
            }

            break;

        case 1:
            Y_Adjust_Buff[2] += 2;

            if (Y_Adjust_Buff[2] > 10) {
                Y_Adjust_Buff[2] = 10;
            } else {
                flag = 1;
            }

            break;

        case 2:
            Disp_Size_H += 2;

            if (Disp_Size_H > 100) {
                Disp_Size_H = 100;
            } else {
                flag = 1;
            }

            Setup_Disp_Size(1);
            break;

        case 3:
            Disp_Size_V += 2;

            if (Disp_Size_V > 100) {
                Disp_Size_V = 100;
            } else {
                flag = 1;
            }

            Setup_Disp_Size(1);
            break;

        case 4:
            sys_w.screen_mode = (sys_w.screen_mode + 1) & 1;
            flag = 1;
            break;
        }
    }

    if (flag) {
        SE_dir_cursor_move();
    }

    X_Adjust = X_Adjust_Buff[0] = X_Adjust_Buff[1] = X_Adjust_Buff[2];
    Y_Adjust = Y_Adjust_Buff[0] = Y_Adjust_Buff[1] = Y_Adjust_Buff[2];
}

void Sound_Test(struct _TASK *task_ptr) {
    s16 char_index; // r17
    s16 ix;         // r16
    u8 last_mode;   // r20

    Clear_Flash_Sub();

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 8);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        setupAlwaysSeamlessFlag(((((u16 *)plsw_00)[0] | ((u16 *)plsw_00)[1]) & 0x4000) != 0);
        Clear_Flash_Init(4);
        Menu_Common_Init();
        Menu_Cursor_Y[0] = 0;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Convert_Buff[3][1][5] = 0;

        if (sys_w.sound_mode == 0) {
            Convert_Buff[3][1][0] = 0;
        } else {
            Convert_Buff[3][1][0] = 1;
        }

        if (sys_w.bgm_type == 0) {
            Convert_Buff[3][1][3] = 0;
        } else {
            Convert_Buff[3][1][3] = 1;
        }

        Convert_Buff[3][1][7] = 1;
        Order[0x4F] = 4;
        Order_Timer[0x4F] = 1;
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 2;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x72, 4, 0, 0x3F, 2);
        Order[0x72] = 1;
        Order_Dir[0x72] = 8;
        Order_Timer[0x72] = 1;
        effect_04_init(2, 6, 2, 0x48);

        {
            s32 ixSoundMenuItem[4] = { 10, 11, 11, 12 }; // r29+0x70

            for (ix = 0; ix < 4; ix++) {
                Order[ix + 0x57] = 1;
                Order_Dir[ix + 0x57] = 4;
                Order_Timer[ix + 0x57] = ix + 0x14;
                effect_64_init(ix + 0x57, 0, 2, ixSoundMenuItem[ix] + 1, ix, 0x7047, ix + 0xC, 3, 1);
            }
        }

        Order_Dir[0x78] = 0;
        effect_A8_init(0, 0x78, 0, 2, 5, 0x70A7, 0);
        Order_Dir[0x79] = 1;
        effect_A8_init(0, 0x79, 0, 2, 5, 0x70A7, 1);
        effect_A8_init(3, 0x7A, 0, 2, 5, 0x70A7, 3);
        Convert_Buff[3][1][5] = 0;
        Order_Dir[0x7B] = 0;
        effect_A8_init(2, 0x7B, 0, 2, 5, 0x70A7, 2);

        {
            s16 unused_s2;
            s16 unused_s3;

            for (ix = 0, unused_s3 = char_index = 0x3B; ix < 7; ix++, unused_s2 = char_index++) {
                effect_61_init(0, ix + 0x50, 0, 2, char_index, ix, 0x7047);
                Order[ix + 0x50] = 1;
                Order_Dir[ix + 0x50] = 4;
                Order_Timer[ix + 0x50] = ix + 0x14;
            }
        }

        Menu_Cursor_Move = 5;
        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        last_mode = Convert_Buff[3][1][0];
        Sound_Cursor_Sub(0);

        if (IO_Result == 0) {
            Sound_Cursor_Sub(1);
        }

        if ((Menu_Cursor_Y[0] == 4) && (IO_Result == 0x100)) {
            SE_selected();
            Convert_Buff[3][1][0] = 0;
            Convert_Buff[3][1][1] = 0xF;
            Convert_Buff[3][1][2] = 0xF;
            Convert_Buff[3][1][3] = 0;
        }

        if (bgm_level != (s16)Convert_Buff[3][1][1]) {
            bgm_level = Convert_Buff[3][1][1];
            save_w[Present_Mode].BGM_Level = Convert_Buff[3][1][1];
            SsBgmHalfVolume(0);
        }

        if (se_level != (s16)Convert_Buff[3][1][2]) {
            se_level = Convert_Buff[3][1][2];
            setSeVolume(save_w[Present_Mode].SE_Level = Convert_Buff[3][1][2]);
        }

        save_w[Present_Mode].BgmType = Convert_Buff[3][1][3];

        if (sys_w.bgm_type != Convert_Buff[3][1][3]) {
            sys_w.bgm_type = Convert_Buff[3][1][3];
            Convert_Buff[3][1][5] = 0;
            BGM_Request_Code_Check(0x41);
        }

        Order_Dir[0x7B] = Convert_Buff[3][1][5];
        Setup_Sound_Mode(last_mode);
        Save_Game_Data();

        if (Menu_Cursor_Y[0] == 5) {
            if (IO_Result == 0x100) {
                SsRequest((u16)Order_Dir[0x7B] + 1);
                Convert_Buff[3][1][7] = 1;
                return;
            }

            if ((IO_Result == 0x200) && Convert_Buff[3][1][7]) {
                Convert_Buff[3][1][7] = 0;
                BGM_Stop();
                return;
            }
        }

        if (IO_Result == 0x200 || (Menu_Cursor_Y[0] == 6) && (IO_Result == 0x100 || IO_Result == 0x4000)) {
            SE_selected();
            Return_Option_Mode_Sub(task_ptr);
            setupAlwaysSeamlessFlag(0);
            Order[0x72] = 4;
            Order_Timer[0x72] = 4;
            BGM_Request_Code_Check(0x41);
        }

        break;
    }
}

void Setup_Sound_Mode(u8 last_mode) {
    if (last_mode == Convert_Buff[3][1][0]) {
        return;
    }

    sys_w.sound_mode = Convert_Buff[3][1][0];
    setupSoundMode();
    SsBgmHalfVolume(0);
}

u16 Sound_Cursor_Sub(s16 PL_id) {
    u16 sw;
    u16 ret;

    sw = ~((u16 *)plsw_01)[PL_id] & ((u16 *)plsw_00)[PL_id];
    sw = Check_Menu_Lever(PL_id, 0);
    ret = MC_Move_Sub(sw, 0, 6, 0xFF);
    ret |= SD_Move_Sub_LR(sw);
    ret &= 0x20F;
    return ret;
}

const u8 Sound_Data_Max[3][6] = { { 1, 0, 0, 1, 0, 66 }, { 1, 15, 15, 1, 0, 66 }, { 0, 15, 15, 0, 0, 0 } };

u16 SD_Move_Sub_LR(u16 sw) {
    u16 rnum;
    s16 max;
    s8 last_cursor;

    rnum = 0;

    if (Menu_Cursor_Y[0] == 4 || Menu_Cursor_Y[0] == 6) {
        return 0;
    }

    last_cursor = Convert_Buff[3][1][Menu_Cursor_Y[0]];

    switch (sw) {
    case 4:
        max = Sound_Data_Max[0][Menu_Cursor_Y[0]];

        while (1) {
            Convert_Buff[3][1][Menu_Cursor_Y[0]] -= 1;

            if (Convert_Buff[3][1][Menu_Cursor_Y[0]] < 0) {
                Convert_Buff[3][1][Menu_Cursor_Y[0]] = max;
            }

            if ((Menu_Cursor_Y[0] != 5) || (bgmSkipCheck(Convert_Buff[3][1][5] + 1) == 0)) {
                break;
            }
        }

        if (last_cursor != Convert_Buff[3][1][Menu_Cursor_Y[0]]) {
            rnum = 4;
        }

        break;

    case 8:
        max = Sound_Data_Max[1][Menu_Cursor_Y[0]];

        while (1) {
            Convert_Buff[3][1][Menu_Cursor_Y[0]] += 1;

            if (Convert_Buff[3][1][Menu_Cursor_Y[0]] > max) {
                Convert_Buff[3][1][Menu_Cursor_Y[0]] = Sound_Data_Max[2][Menu_Cursor_Y[0]];
            }

            if ((Menu_Cursor_Y[0] != 5) || (bgmSkipCheck(Convert_Buff[3][1][5] + 1) == 0)) {
                break;
            }
        }

        if (last_cursor != Convert_Buff[3][1][Menu_Cursor_Y[0]]) {
            rnum = 8;
        }

        break;
    }

    if (rnum) {
        SE_dir_cursor_move();
    }

    return rnum;
}

void Memory_Card(struct _TASK *task_ptr) {
    s16 ix;
    s16 char_index;

    s16 unused_s3;
    s16 unused_s2;

    switch (task_ptr->r_no[2]) {
    case 0:
        FadeOut(1, 0xFF, 8);
        task_ptr->r_no[2] += 1;
        task_ptr->timer = 5;
        Menu_Common_Init();
        Menu_Cursor_Y[0] = 0;
        Menu_Suicide[1] = 1;
        Menu_Suicide[2] = 0;
        Order[0x4F] = 4;
        Order_Timer[0x4F] = 1;
        Order[0x4E] = 2;
        Order_Dir[0x4E] = 4;
        Order_Timer[0x4E] = 1;
        effect_57_init(0x69, 5, 0, 0x3F, 2);
        Order[0x69] = 1;
        Order_Dir[0x69] = 8;
        Order_Timer[0x69] = 1;

        for (ix = 0, unused_s3 = char_index = 0x15; ix < 4; ix++, unused_s2 = char_index++) {
            effect_61_init(0, ix + 0x50, 1, 2, char_index, ix, 0x7047);
            Order[ix + 0x50] = 1;
            Order_Dir[ix + 0x50] = 4;
            Order_Timer[ix + 0x50] = ix + 0x14;
        }

        Menu_Cursor_Move = 4;
        effect_64_init(0x61, 1, 2, 0, 2, 0x7047, 0, 3, 0);
        Order[0x61] = 1;
        Order_Dir[0x61] = 4;
        Order_Timer[0x61] = 0x18;
        effect_66_init(0x8A, 8, 2, 1, -1, -1, -0x7FF5);
        Order[0x8A] = 3;
        Order_Timer[0x8A] = 1;
        effect_04_init(2, 2, 2, 0x48);
        Setup_File_Property(0, 0xFF);
        break;

    case 1:
        Menu_Sub_case1(task_ptr);
        break;

    case 2:
        if (FadeIn(1, 0x19, 8) != 0) {
            task_ptr->r_no[2] += 1;
            Suicide[3] = 0;
        }

        break;

    case 3:
        Memory_Card_Sub(0);
        Button_Exit_Check(task_ptr, 0);

        if (IO_Result == 0) {
            Memory_Card_Sub(1);
            Button_Exit_Check(task_ptr, 0);
        }

        break;

    case 4:
    case 5:
    case 6:
        Save_Load_Menu(task_ptr);
        break;
    }
}

void Save_Load_Menu(struct _TASK *task_ptr) {
    s16 ix;

    Menu_Cursor_X[1] = Menu_Cursor_X[0];

    switch (task_ptr->r_no[3]) {
    case 0:
        task_ptr->r_no[3] += 1;
        task_ptr->timer = 5;

        if (task_ptr->r_no[2] == 5) {
            SaveInit(0, 0);
        } else {
            SaveInit(0, 1);
        }

        Menu_Common_Init();
        Menu_Suicide[3] = 0;
        Target_BG_X[1] = bg_w.bgw[1].wxy[0].disp.pos + 0x180;
        Offset_BG_X[1] = 0;
        Target_BG_X[2] = bg_w.bgw[2].wxy[0].disp.pos + 0x200;
        Offset_BG_X[2] = 0;
        bg_w.bgw[2].speed_x = 0x333333;
        Next_Step = 0;
        bg_mvxy.a[0].sp = 0x266666;
        bg_mvxy.d[0].sp = 0;
        effect_58_init(0xE, 1, 1);
        effect_58_init(0, 1, 2);
        Menu_Cursor_X[0] = Setup_Final_Cursor_Pos(0, 8);
        Message_Data->kind_req = 5;
        break;

    case 1:
        if (Next_Step) {
            task_ptr->r_no[3] += 1;
            task_ptr->free[3] = 0;
        }

        break;

    case 2:
        task_ptr->r_no[3] += 1;
        Menu_Cursor_X[1] = Menu_Cursor_X[0] + 8;
        /* fallthrough */

    case 3:
        if (SaveMove() <= 0) {
            Go_Back_MC(task_ptr);
        }

        break;

    case 4:
        if (Next_Step) {
            task_ptr->r_no[2] = 3;
            task_ptr->r_no[3] = 0;

            for (ix = 0; ix < 4; ix++) {
                Message_Data[ix].order = 3;
            }

            Order[0x78] = 3;
            Order_Timer[0x78] = 1;
        }

        break;

    default:
        Exit_Sub(task_ptr, 1, Menu_Cursor_Y[0] + 7);
        break;
    }
}

void Go_Back_MC(struct _TASK *task_ptr) {
    task_ptr->r_no[3] = 4;
    Menu_Cursor_Y[0] = task_ptr->r_no[2] - 4;
    Target_BG_X[1] = bg_w.bgw[1].wxy[0].disp.pos - 0x180;
    Offset_BG_X[1] = 0;
    Target_BG_X[2] = bg_w.bgw[2].wxy[0].disp.pos - 0x200;
    Offset_BG_X[2] = 0;
    bg_w.bgw[2].speed_x = -0x333333;
    Next_Step = 0;
    bg_mvxy.a[0].sp = 0xFFD9999A;
    bg_mvxy.d[0].sp = 0;
    effect_58_init(0xE, 1, 1);
    effect_58_init(0, 1, 2);
}

s32 Setup_Final_Cursor_Pos(s8 cursor_x, s16 dir) {
    s16 ix;
    s16 check_x[2];
    s16 next_dir;

    if (cursor_x == -1) {
        cursor_x = 0;
    }

    if (vm_w.Connect[cursor_x]) {
        return cursor_x;
    }

    check_x[0] = cursor_x ^ 1;

    if (vm_w.Connect[check_x[0]]) {
        return check_x[0];
    }

    if (dir == 4) {
        next_dir = -2;
    } else {
        next_dir = 2;
    }

    check_x[0] = cursor_x;

    for (ix = 0; ix < 4; ix++) {
        check_x[0] += next_dir;

        if (check_x[0] < 0) {
            if (IO_Result == 0) {
                check_x[0] += 8;
            } else {
                return Menu_Cursor_X[1];
            }
        }

        if (check_x[0] > 7) {
            if (IO_Result == 0) {
                check_x[0] -= 8;
            } else {
                return Menu_Cursor_X[1];
            }
        }

        if (vm_w.Connect[check_x[0]]) {
            return check_x[0];
        }

        check_x[1] = check_x[0] ^ 1;

        if (vm_w.Connect[check_x[1]]) {
            return check_x[1];
        }
    }

    return -1;
}

void Memory_Card_Sub(s16 PL_id) {
    u16 sw;

    sw = ~((u16 *)plsw_01)[PL_id] & ((u16 *)plsw_00)[PL_id];
    sw = Check_Menu_Lever(PL_id, 0);
    MC_Move_Sub(sw, 0, 3, 0xFF);

    if ((Menu_Cursor_Y[0] == 2) && !(IO_Result & 0x200)) {
        IO_Result = 0;
    }

    Memory_Card_Move_Sub_LR(sw, 0);

    if (Convert_Buff[3][0][2] == 0) {
        save_w[Present_Mode].Auto_Save = 0;
    }
}

u16 Memory_Card_Move_Sub_LR(u16 sw, s16 cursor_id) {
    s32 ret;
    s32 idx;
    s32 val;

    idx = Menu_Cursor_Y[cursor_id];

    if (idx != 2) {
        return 0;
    }

    val = Convert_Buff[3][cursor_id][idx];

    switch (sw) {
    case 4:
        val -= 1;

        if (val < 0) {
            val = 1;
        }

        SE_dir_cursor_move();
        ret = 4;
        break;

    case 8:
        val += 1;

        if (val > 1) {
            val = 0;
        }

        SE_dir_cursor_move();
        ret = 8;
        break;

    default:
        ret = 0;
        break;
    }

    Convert_Buff[3][cursor_id][idx] = val;

    if ((ret != 0) && (val == 1)) {
        IO_Result = 0x100;
        Forbid_Reset = 1;
    }

    return ret;
}

u16 MC_Move_Sub(u16 sw, s16 cursor_id, s16 menu_max, s16 cansel_menu) {
    if (Menu_Cursor_Move > 0) {
        return 0;
    }

    switch (sw) {
    case 0x1:
        Menu_Cursor_Y[cursor_id] -= 1;

        if (Menu_Cursor_Y[cursor_id] < 0) {
            Menu_Cursor_Y[cursor_id] = menu_max;
        }

        if ((cansel_menu == Menu_Cursor_Y[cursor_id]) && (Connect_Status == 0)) {
            Menu_Cursor_Y[cursor_id] -= 1;
        }

        SE_cursor_move();
        return IO_Result = 1;

    case 0x2:
        Menu_Cursor_Y[cursor_id] += 1;

        if (Menu_Cursor_Y[cursor_id] > menu_max) {
            Menu_Cursor_Y[cursor_id] = 0;
        }

        if ((cansel_menu == Menu_Cursor_Y[cursor_id]) && (Connect_Status == 0)) {
            Menu_Cursor_Y[cursor_id] += 1;
        }

        SE_cursor_move();
        return IO_Result = 2;

    case 0x10:
        return IO_Result = 0x10;

    case 0x100:
        return IO_Result = 0x100;

    case 0x200:
        return IO_Result = 0x200;

    case 0x400:
        return IO_Result = 0x400;

    case 0x4000:
        return IO_Result = 0x4000;

    default:
        return IO_Result = 0;

    case 0x20:
        return IO_Result = 0x20;

    case 0x40:
        return IO_Result = 0x40;

    case 0x80:
        return IO_Result = 0x80;

    case 0x800:
        return IO_Result = 0x800;
    }
}

s32 Exit_Sub(struct _TASK *task_ptr, s16 cursor_ix, s16 next_routine) {
    switch (task_ptr->free[0]) {
    case 0:
        task_ptr->free[0] += 1;
        FadeInit();
        /* fallthrough */

    case 1:
        if (FadeOut(1, 0x19, 8) != 0) {
            task_ptr->r_no[1] = next_routine;
            task_ptr->r_no[2] = 0;
            task_ptr->r_no[3] = 0;
            task_ptr->free[0] = 0;
            Cursor_Y_Pos[0][cursor_ix] = Menu_Cursor_Y[0];
            Cursor_Y_Pos[1][cursor_ix] = Menu_Cursor_Y[1];
            pulpul_stop();
            return 1;
        }

    default:
        return 0;
    }
}

const u8 Menu_Deley_Time[6] = { 15, 10, 6, 15, 15, 15 };

void Menu_Common_Init() {
    s16 ix;

    for (ix = 0; ix < 2; ix++) {
        Deley_Shot_No[ix] = 0;
        Deley_Shot_Timer[ix] = Menu_Deley_Time[Deley_Shot_No[ix]];
    }

    Menu_Cursor_Move = 0;
    r_no_plus = 0;
}

u16 Check_Menu_Lever(u8 PL_id, s16 type) {
    u16 sw;
    u16 lever;
    u16 ix;

    sw = ~((u16 *)plsw_01)[PL_id] & ((u16 *)plsw_00)[PL_id];

    if (type) {
        sw = ~PLsw[PL_id][1] & PLsw[PL_id][0];
    }

    lever = ((u16 *)plsw_00)[PL_id] & 0xF;

    if (sw & 0x4FF0) {
        return sw;
    }

    sw &= 0xF;

    if (sw) {
        return sw;
    }

    if (lever == 0) {
        Deley_Shot_No[PL_id] = 0;
        Deley_Shot_Timer[PL_id] = Menu_Deley_Time[Deley_Shot_No[PL_id]];
        return 0;
    }

    if (--Deley_Shot_Timer[PL_id] == 0) {
        if (++Deley_Shot_No[PL_id] > 2) {
            Deley_Shot_No[PL_id] = 2;
        }

        if (lever & 3) {
            ix = 0;
        } else {
            ix = 3;
        }

        Deley_Shot_Timer[PL_id] = Menu_Deley_Time[Deley_Shot_No[PL_id] + ix];
        return lever;
    }

    return 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Suspend_Menu);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", In_Game);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Menu_Select);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Yes_No_Cursor_Move_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Button_Config_in_Game);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Button_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Button_Exit_Check_in_Game);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Return_Pause_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Check_Pad_in_Pause);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Pad_Come_Out);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", bg_etc_write_ex);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Wait_Load_Save);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Disp_Auto_Save);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", DAS_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", DAS_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", DAS_3rd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", DAS_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Disp_Auto_Save2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", DAS2_4th);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Wait_Replay_Check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", VS_Result);
// VS_Result contains literal_1803

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Win_Lose_OBJ);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", VS_Result_Select_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", After_VS_Move_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", VS_Result_Move_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Save_Replay);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Save_Replay_1st);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Save_Replay_2nd);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Replay_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Return_VS_Result_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Save_Replay_MC_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Exit_Replay_Save);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Decide_PL);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Wait_Pause_in_Tr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Control_Player_Tr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Next_Be_Tr_Menu);

s32 Check_Pause_Term_Tr(s16 PL_id);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Check_Pause_Term_Tr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Pause_Check_Tr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_Tr_Pause);

void Flash_1P_or_2P(struct _TASK *task_ptr) {
    switch (task_ptr->r_no[3]) {
    case 0:
        if (--task_ptr->free[0]) {
            if (Pause_ID == 0) {
                SSPutStr2(20, 9, 9, "1P PAUSE");
                break;
            } else {
                SSPutStr2(20, 9, 9, "2P PAUSE");
                break;
            }
        }

        task_ptr->r_no[3] = 1;
        task_ptr->free[0] = 0x1E;
        break;

    case 1:
        if (--task_ptr->free[0] == 0) {
            task_ptr->r_no[3] = 0;
            task_ptr->free[0] = 0x3C;
        }

        break;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Pause_in_Normal_Tr);

s32 Pause_1st_Sub(struct _TASK *task_ptr) {
    u16 sw = ~((u16 *)plsw_01)[Pause_ID] & ((u16 *)plsw_00)[Pause_ID];

    if (Pause_Down) {
        SSPutStr2(17, 12, 9, "PRESS   BUTTON");
        dispButtonImage2(0xB2, 0x5B, 1, 0x13, 0xF, 0, 4);
        SSPutStr2(18, 14, 9, "TO PAUSE MENU");
    }

    if (sw & 0x4000) {
        if (((Mode_Type == 3) || (Mode_Type == 4)) && (Check_Pause_Term_Tr(Pause_ID ^ 1) != 0) &&
            plw[Pause_ID ^ 1].wu.operator&&(Interface_Type[Pause_ID ^ 1] == 0)) {
            Pause_ID = Pause_ID ^ 1;
            return 0;
        }

        task_ptr->r_no[2] = 0x63;
        Exit_Menu = 1;
        SE_selected();
        return 1;
    }

    if (sw & 0x100) {
        task_ptr->r_no[2] += 1;
        Cursor_Y_Pos[0][0] = 0;
        SE_selected();
    }

    return 0;
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Reset_Training);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Reset_Replay);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Training_Menu);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Training_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Normal_Training);
// Normal_Training contains literal_2331

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Setup_NTr_Data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Check_Skip_Replay);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Check_Skip_Recording);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Yes_No_Cursor_Exit_Training);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Button_Config_Tr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Button_Exit_Check_in_Tr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Dummy_Setting);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Training_Option);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Training_Disp_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Dummy_Move_Sub);

const u8 Menu_Max_Data_Tr[2][2][6] = { { { 4, 6, 2, 1, 0, 0 }, { 3, 1, 3, 7, 0, 0 } },
                                       { { 2, 3, 1, 3, 0, 0 }, { 0, 0, 0, 0, 0, 0 } } };

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Dummy_Move_Sub_LR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Blocking_Training);
// Blocking_Training contains literal_2592

const LetterData training_letter_data[6] = { { 0x68, "NORMAL TRAINING" },   { 0x5C, "PARRYING TRAINING" },
                                             { 0x7C, "DUMMY SETTING" },     { 0x6C, "TRAINING OPTION" },
                                             { 0x64, "RECORDING SETTING" }, { 0x72, "BUTTON CONFIG." } };

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Blocking_Tr_Option);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Training_Init_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Training_Exit_Sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Character_Change);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Default_Training_Data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Default_Training_Option);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Wait_Replay_Load);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", After_Replay);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Menu_Sub_case1);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Back_to_Mode_Select);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Extra_Option);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", Ex_Move_Sub_LR);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/menu", End_Replay_Menu);
