#ifndef WORK_SYS_H
#define WORK_SYS_H

#include "structs.h"
#include "types.h"

extern s32 Zoom_Base_Position_Z;       // size: 0x4, address: 0x579AC4
extern s32 Zoom_Base_Position_Y;       // size: 0x4, address: 0x579AC8
extern s32 Zoom_Base_Position_X;       // size: 0x4, address: 0x579ACC
extern f32 Frame_Zoom_Y;               // size: 0x4, address: 0x579AD0
extern f32 Frame_Zoom_X;               // size: 0x4, address: 0x579AD4
extern f32 SA_Zoom_Y;                  // size: 0x4, address: 0x579AD8
extern f32 SA_Zoom_X;                  // size: 0x4, address: 0x579ADC
extern f32 Screen_Zoom_Y;              // size: 0x4, address: 0x579AE0
extern f32 Screen_Zoom_X;              // size: 0x4, address: 0x579AE4
extern f32 scr_sc;                     // size: 0x4, address: 0x579AE8
extern s32 sca_y;                      // size: 0x4, address: 0x579AEC
extern s32 sca_x;                      // size: 0x4, address: 0x579AF0
extern BackgroundParameters bg_prm[8]; // size: 0x20, address: 0x579B00
extern BG_POS fm_pos[8];               // size: 0x80, address: 0x579B20
extern BG_POS bg_pos[8];               // size: 0x80, address: 0x579BA0
extern u8 Screen_PAL;                  // size: 0x1, address: 0x579C20
extern u16 PLsw[2][2];                 // size: 0x8, address: 0x579C28
extern s8 Gill_Appear_Flag;            // size: 0x1, address: 0x579C30
extern u32 Interrupt_Timer;            // size: 0x4, address: 0x579C34
extern u16 p4sw_buff;                  // size: 0x2, address: 0x579C38
extern u16 p3sw_buff;                  // size: 0x2, address: 0x579C3C
extern u16 p2sw_buff;                  // size: 0x2, address: 0x579C40
extern u16 p1sw_buff;                  // size: 0x2, address: 0x579C44
extern u8 Interrupt_Flag;              // size: 0x1, address: 0x579C48
extern s16 Correct_Y[4];               // size: 0x8, address: 0x579C50
extern s16 Correct_X[4];               // size: 0x8, address: 0x579C58
extern u8 Turbo_Timer;                 // size: 0x1, address: 0x579C60
extern u8 Turbo;                       // size: 0x1, address: 0x579C64
extern u8 No_Trans;                    // size: 0x1, address: 0x579C68
extern u8 Disp_Size_V;                 // size: 0x1, address: 0x579C6C
extern u8 Disp_Size_H;                 // size: 0x1, address: 0x579C70
extern s32 Y_Adjust_Buff[3];           // size: 0xC, address: 0x579C78
extern s32 X_Adjust_Buff[3];           // size: 0xC, address: 0x579C88
extern s32 Y_Adjust;                   // size: 0x4, address: 0x579C94
extern s32 X_Adjust;                   // size: 0x4, address: 0x579C98
extern u8 Interface_Type[2];           // size: 0x2, address: 0x579C9C
extern u32 system_timer;               // size: 0x4, address: 0x579CA0
extern u8 Process_Counter;             // size: 0x1, address: 0x579CA4
extern u16 p4sw_1;                     // size: 0x2, address: 0x579CA8
extern u16 p4sw_0;                     // size: 0x2, address: 0x579CAC
extern u16 p3sw_1;                     // size: 0x2, address: 0x579CB0
extern u16 p3sw_0;                     // size: 0x2, address: 0x579CB4
extern u16 p2sw_1;                     // size: 0x2, address: 0x579CB8
extern u16 p2sw_0;                     // size: 0x2, address: 0x579CBC
extern u16 p1sw_1;                     // size: 0x2, address: 0x579CC0
extern u16 p1sw_0;                     // size: 0x2, address: 0x579CC4
extern struct _VM_W vm_w;              // size: 0x6C, address: 0x579D20
extern struct _SYSTEM_W sys_w;         // size: 0x1C, address: 0x579D90
extern u32 current_task_num;           // size: 0x4, address: 0x579DAC

extern struct _SAVE_W save_w[6];                  // size: 0xC30, address: 0x6B4E80
extern Permission permission_player[6];           // size: 0x90, address: 0x6B5AB0
extern SystemDir system_dir[6];                   // size: 0x1B0, address: 0x6B5B40
extern _REPLAY_W Replay_w;                        // size: 0x7448, address: 0x6B5CF0
extern struct _REP_GAME_INFOR Rep_Game_Infor[11]; // size: 0x18C, address: 0x6BD140
extern struct _TASK task[11];                     // size: 0xDC, address: 0x6BD2D0
extern MTX BgMATRIX[9];                           // size: 0x240, address: 0x6BD3B0

#endif
