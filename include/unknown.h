#ifndef UNKNOWN_H
#define UNKNOWN_H

#include "sf33rd/AcrSDK/common/memmgr.h"
#include "sf33rd/AcrSDK/common/plcommon.h"
#include "structs.h"
#include "types.h"

// .text

void mflInit(void *mem_ptr, s32 memsize, s32 memalign);                     // Range: 0x115FB0 -> 0x115FFC
int fmsInitialize(FL_FMS *lp, void *memory_ptr, s32 memsize, s32 memalign); // Range: 0x115D90 -> 0x115E80

// bg.c
void Bg_TexInit();       // Range: 0x16BA90 -> 0x16BB34
void Pause_Family_On();  // Range: 0x170290 -> 0x170320
void Bg_On_R(u32 s_prm); // Range: 0x170B00 -> 0x170B2C

void Scrn_Renew(); // Range: 0x170BE0 -> 0x170BF0
void Irl_Family(); // Range: 0x170BF0 -> 0x170CD0
void Irl_Scrn();   // Range: 0x170CD0 -> 0x170E9C

void bg_etc_write(s16 type); // Range: 0x175920 -> 0x175FC0

// color3rd.c
void q_ldreq_color_data(REQ *curr);                // Range: 0x19D800 -> 0x19DD7C
void set_hitmark_color();                          // Range: 0x19DE70 -> 0x19E010
void init_color_trans_req();                       // Range: 0x19F600 -> 0x19F694
void palCopyGhostDC(s32 ofs, s32 cnt, void *data); // Range: 0x19F700 -> 0x19F7C0
void palCreateGhost();                             // Range: 0x19F8D0 -> 0x19FB50
void palUpdateGhostDC();                           // Range: 0x19FB70 -> 0x19FC6C

s32 effect_04_init(s16 Death_Type, s16 cg_type, s16 sync_bg, s16 priority); // Range: 0x1C56A0 -> 0x1C5818
// DWARF says disp_index and cursor_id are s16, but decompilation suggests otherwise
s32 effect_18_init(s32 disp_index, s32 cursor_id, s16 sync_bg, s16 master_player); // Range: 0x1D36B0 -> 0x1D37E0
s32 effect_23_init(s16 id, u8 dir_old, s16 sync_bg, s16 master_player, s16 letter_type, s16 cursor_index,
                   u16 char_offset, s16 pos_index, s16 type); // Range: 0x1D5230 -> 0x1D5390
s32 effect_35_init(s16 wait_timer, s16 c_type);               // Range: 0x1DBE80 -> 0x1DC170
s32 effect_38_init(s16 PL_id, s16 dir_old, s16 Your_Char, s16 Play_Status,
                   s16 Target_BG);                                                    // Range: 0x1DEC30 -> 0x1DF620
s32 effect_39_init(s16 PL_id, s16 dir_old, s16 Your_Char, s16 Target_BG, s16 Option); // Range: 0x1E04E0 -> 0x1E0718
s32 effect_40_init(s16 id, s16 type, s16 char_ix, s16 sync_bg, s16 master_player,
                   s16 master_priority);                                         // Range: 0x1E0B90 -> 0x1E0E78
s32 effect_43_init(s16 Time, s16 Target_BG);                                     // Range: 0x1E2720 -> 0x1E28A8
s32 effect_45_init(u8 id, s16 sync_bg, s16 master_player);                       // Range: 0x1E30D0 -> 0x1E3228
s32 effect_49_init(s16 vital_new);                                               // Range: 0x1E52B0 -> 0x1E54D8
s32 effect_51_init(s16 letter_type, s16 cursor_index, s16 master_player);        // Range: 0x1E5E80 -> 0x1E6040
s32 effect_57_init(s16 dir_old, s16 ID, s16 Target_BG, s16 char_ix, s16 option); // Range: 0x1E85B0 -> 0x1E8740
s32 effect_58_init(s16 id, s16 time0, s16 option);                               // Range: 0x1E97D0 -> 0x1E98A0
s32 effect_61_init(s16 master, u8 dir_old, s16 sync_bg, s16 master_player, s16 char_ix, s16 cursor_index,
                   u16 letter_type); // Range: 0x1EB350 -> 0x1EB68C
s32 effect_63_init(u8 dir_old, s16 sync_bg, s16 master_player, s16 letter_type,
                   s16 cursor_index); // Range: 0x1EBEC0 -> 0x1EC050
s32 effect_64_init(u8 dir_old, s16 sync_bg, s16 master_player, s16 letter_type, s16 cursor_index, u16 char_offset,
                   s16 pos_index, s16 convert_id, s16 convert_id2); // Range: 0x1EC830 -> 0x1EC990
s32 effect_66_init(s16 order_index, s16 id, s16 master_player, s16 target_bg, s16 char_ix, s16 char_ix2,
                   s16 option);                         // Range: 0x1EDB60 -> 0x1EDEA4
s32 effect_75_init(s16 dir_old, s16 ID, s16 Target_BG); // Range: 0x1F1910 -> 0x1F1A28
s32 effect_76_init(s16 dir_old);                        // Range: 0x1F2670 -> 0x1F27A0
s32 effect_95_init(s16 vital_new);                      // Range: 0x1FCFD0 -> 0x1FD218
s32 effect_A2_init(s16 /* unused */);                   // Range: 0x1FF350 -> 0x1FF408
s32 effect_A8_init(s16 id, u8 dir_old, s16 sync_bg, s16 master_player, s16 cursor_index, s16 char_ix,
                   s16 pos_index);                                          // Range: 0x2012C0 -> 0x201540
s32 effect_A9_init(s16 Char_Index, s16 Option, s16 Pos_Index, s16 Option2); // Range: 0x201A80 -> 0x201C78
// DWARF says WIN_PL_NO is s8, but decompilation suggests it's at least s16
s32 effect_B8_init(s16 WIN_PL_NO, s16 timer);                                     // Range: 0x205500 -> 0x2056B8
s32 effect_C4_init(s16 id, s16 letter_type, s16 cursor_index, s16 master_player); // Range: 0x209D40 -> 0x209F4C

// EFFECT.c
void move_effect_work(s16 index);  // Range: 0x21ABC0 -> 0x21AD24
void disp_effect_work();           // Range: 0x21AD30 -> 0x21AED8
void effect_work_init();           // Range: 0x21AEE0 -> 0x21B05C
void effect_work_quick_init();     // Range: 0x21B060 -> 0x21B0C0
void effect_work_kill_mod_plcol(); // Range: 0x21C560 -> 0x21C588

s32 effect_J2_init(s16 delay);                                           // Range: 0x227340 -> 0x227478
s32 effect_K6_init(s16 PL_id, s16 dir_old, s16 dm_vital, s16 Target_BG); // Range: 0x22EEC0 -> 0x22F020
s32 effect_L1_init(s16 flag);                                            // Range: 0x232820 -> 0x2328E8

// Game.c
void Game_Task(struct _TASK *task_ptr); // Range: 0x250190 -> 0x250378
void Game01_Sub();                      // Range: 0x2514F0 -> 0x2515C0

// GD3rd.c
s32 Setup_Directory_Record_Data();            // Range: 0x254330 -> 0x2543CC
void Push_LDREQ_Queue_Player(s16 id, s16 ix); // Range: 0x254CC0 -> 0x254EB0
void Push_LDREQ_Queue_BG(s16 ix);             // Range: 0x254EB0 -> 0x254EEC
s32 Check_LDREQ_Queue_BG(s16 ix);             // Range: 0x255960 -> 0x255994

// init3rd.c
void Init_Task(struct _TASK *task_ptr); // Range: 0x266080 -> 0x2660D4

// IOConv.c
void keyConvert(); // Range: 0x266A90 -> 0x267118

// MMTMCNT.c
void Purge_mmtm_area(s16 ix);       // Range: 0x280BE0 -> 0x280C24
void Purge_texcash_of_list(s16 ix); // Range: 0x280CE0 -> 0x280D88
void Make_texcash_of_list(s16 ix);  // Range: 0x280D90 -> 0x280E48

// MTRANS.c
void appSetupBasePriority();     // Range: 0x286180 -> 0x2861F4
void appSetupTempPriority();     // Range: 0x286200 -> 0x286264
void seqsInitialize(void *adrs); // Range: 0x286300 -> 0x286350
void seqsBeforeProcess();        // Range: 0x286370 -> 0x2863B4
void seqsAfterProcess();         // Range: 0x2863C0 -> 0x2865E4

// PulPul.c
void init_pulpul_work();            // Range: 0x37A560 -> 0x37A590
void pulpul_stop();                 // Range: 0x37A760 -> 0x37A790
void pulpul_stop2(s32 ix);          // Range: 0x37A790 -> 0x37A890
void pp_vib_on(s32 id);             // Range: 0x37AB30 -> 0x37AB74
void pp_operator_check_flag(u8 fl); // Range: 0x37ABD0 -> 0x37ABF0
void move_pulpul_work();            // Range: 0x37ABF0 -> 0x37AC30

// RAMCNT.c
void disp_ramcnt_free_area();                                 // Range: 0x37BB90 -> 0x37BC58
void Init_ram_control_work(u8 *adrs, s32 size);               // Range: 0x37BC60 -> 0x37BDF8
void Push_ramcnt_key(s16 key);                                // Range: 0x37BE00 -> 0x37BEC4
void Purge_memory_of_kind_of_key(u8 kokey);                   // Range: 0x37C060 -> 0x37C10C
void Set_size_data_ramcnt_key(s16 key, u32 size);             // Range: 0x37C110 -> 0x37C1A4
u32 Get_ramcnt_address(s16 key);                              // Range: 0x37C240 -> 0x37C2C8
s16 Search_ramcnt_type(u8 kokey);                             // Range: 0x37C2D0 -> 0x37C398
s16 Pull_ramcnt_key(u32 memreq, u8 kokey, u8 group, u8 frre); // Range: 0x37C460 -> 0x37C62C

// Saver.c
void Saver_Task(struct _TASK *task_ptr); // Range: 0x37F1B0 -> 0x37F210

// sc_sub.c
void Scrscreen_Init();                         // Range: 0x37F4A0 -> 0x37F6E4
void Sa_frame_Write();                         // Range: 0x37F970 -> 0x37FC88
void SSPutStr(u16 x, u16 y, u8 atr, s8 *str);  // Range: 0x380020 -> 0x380180
void SSPutStr2(u16 x, u16 y, u8 atr, s8 *str); // Range: 0x3806E0 -> 0x380800
void FadeInit();                               // Range: 0x3834D0 -> 0x3834E0
s32 FadeOut(u8 type, u8 step, u8 priority);    // Range: 0x3834E0 -> 0x3836D4
s32 FadeIn(u8 type, u8 step, u8 priority);     // Range: 0x3836E0 -> 0x3838DC
void ToneDown(u8 tone, u8 priority);           // Range: 0x3838E0 -> 0x383A24
void player_name();                            // Range: 0x383A30 -> 0x383B80
void player_face_init();                       // Range: 0x384A30 -> 0x384A38
void player_face();                            // Range: 0x384E10 -> 0x385204

// sc_sub.c
void dispButtonImage2(s32 px, s32 py, s32 pz, s32 sx, s32 sy, s32 cl, s32 ix); // Range: 0x388AA0 -> 0x388D94

// SE.c
void Sound_SE(s16 Code);               // Range: 0x389170 -> 0x38919C
void BGM_Request(s16 Code);            // Range: 0x3891A0 -> 0x3891CC
void BGM_Request_Code_Check(u16 Code); // Range: 0x3891D0 -> 0x3891FC
void BGM_Stop();                       // Range: 0x389200 -> 0x389220
void SE_All_Off();                     // Range: 0x389220 -> 0x389240
void Disp_Sound_Code();                // Range: 0x389E00 -> 0x38A00C

// Sound3rd.c
void Init_sound_system();               // Range: 0x3963A0 -> 0x396438
s32 sndCheckVTransStatus(s32 type);     // Range: 0x396440 -> 0x3964C8
void sndInitialLoad();                  // Range: 0x3964D0 -> 0x396524
void checkAdxFileLoaded();              // Range: 0x396560 -> 0x396654
void Exit_sound_system();               // Range: 0x396660 -> 0x3966D8
void Init_bgm_work();                   // Range: 0x3966E0 -> 0x396718
void sound_all_off();                   // Range: 0x396720 -> 0x396748
void setSeVolume(u8 /* unused */);      // Range: 0x3967F0 -> 0x396850
void setupSoundMode();                  // Range: 0x396880 -> 0x3968C8
void BGM_Server();                      // Range: 0x396B30 -> 0x3977D8
void setupAlwaysSeamlessFlag(s16 flag); // Range: 0x397820 -> 0x39783C
s32 adx_now_playend();                  // Range: 0x397AF0 -> 0x397B50
s32 bgmSkipCheck(s32 code);             // Range: 0x397BC0 -> 0x397C08
void SsAllNoteOff();                    // Range: 0x397C10 -> 0x397C30
void SsRequest(u16 ReqNumber);          // Range: 0x398030 -> 0x398088
void Standby_BGM(s16 num);              // Range: 0x3980F0 -> 0x398150
void Go_BGM();                          // Range: 0x398150 -> 0x398190
void SsBgmFadeOut(u16 time);            // Range: 0x398290 -> 0x398304
void SsBgmHalfVolume(s16 flag);         // Range: 0x3983A0 -> 0x3983EC
void SE_cursor_move();                  // Range: 0x3983F0 -> 0x398414
void SE_selected();                     // Range: 0x398420 -> 0x398444
void SE_dir_cursor_move();              // Range: 0x398450 -> 0x398474
void SE_dir_selected();                 // Range: 0x398480 -> 0x3984A4

// aboutspr.c
void Init_load_on_memory_data();          // Range: 0x3A8710 -> 0x3A87CC
void shadow_drawing(UNK_12 *wk, s16 bsy); // Range: 0x3AAD20 -> 0x3AAEAC

// texcash.c
void init_texcash_1st();            // Range: 0x3AE390 -> 0x3AE4EC
void init_texcash_before_process(); // Range: 0x3AE4F0 -> 0x3AE5B8
void texture_cash_update();         // Range: 0x3AE960 -> 0x3AEDE4
void make_texcash_work(s16 ix);     // Range: 0x3AF190 -> 0x3AFEC0
void Clear_texcash_work();          // Range: 0x3AFEC0 -> 0x3AFF28

// VM_SUB.c
u8 VM_Access_Request(u8 Request, u8 Drive);         // Range: 0x3B1B80 -> 0x3B1BAC
void Setup_File_Property(s16 file_type, u8 number); // Range: 0x3B1BB0 -> 0x3B1CBC

// Lz77Dec.c
s32 decLZ77withSizeCheck(u8 *src, u8 *dst, s32 size); // Range: 0x3B78F0 -> 0x3B7F3C

// MemMan.c
void mmSystemInitialize(); // Range: 0x3C0080 -> 0x3C008C
void mmHeapInitialize(_MEMMAN_OBJ *mmobj, u8 *adrs, s32 size, s32 unit,
                      s8 *format);                   // Range: 0x3C0090 -> 0x3C020C
void mmDebWriteTag();                                // Range: 0x3C0280 -> 0x3C0290
u8 *mmAlloc(_MEMMAN_OBJ *mmobj, s32 size, s32 flag); // Range: 0x3C02D0 -> 0x3C037C
void mmFree(_MEMMAN_OBJ *mmobj, u8 *adrs);           // Range: 0x3C0560 -> 0x3C05D8

// ps2Quad.c
void ps2SeqsRenderQuadInit_B();               // Range: 0x3C5580 -> 0x3C5588
void ps2SeqsRenderQuad_B(Quad *spr, u32 col); // Range: 0x3C6090 -> 0x3C6158
void ps2SeqsRenderQuadEnd();                  // Range: 0x3C6490 -> 0x3C6498
s32 getCP3toFullScreenDrawFlag();             // Range: 0x3C64A0 -> 0x3C64AC
void CP3toPS2DrawOn();                        // Range: 0x3C64B0 -> 0x3C64C0
void CP3toPS2DrawOff();                       // Range: 0x3C64C0 -> 0x3C64CC
void CP3toPS2Draw();                          // Range: 0x3C64D0 -> 0x3C6D8C
void flmwVSyncCallback();                     // Range: 0x3C6D90 -> 0x3C6DB4
void flmwFlip();                              // Range: 0x3C6E00 -> 0x3C6ED8
void njUserInit();                            // Range: 0x3E5BA0 -> 0x3E5E64

// flps2render.c
s32 flBeginRender();                                          // Range: 0x3EE930 -> 0x3EE9B0
s32 flEndRender();                                            // Range: 0x3EE9B0 -> 0x3EEA14
s32 flPS2InitRenderState();                                   // Range: 0x3EEA20 -> 0x3EEC4C
s32 flSetRenderState(enum _FLSETRENDERSTATE func, u32 value); // Range: 0x3EEC50 -> 0x3EFDD8
void flAdjustScreen(s32 x, s32 y);                            // Range: 0x3F2230 -> 0x3F2268

// flps2debug.c
s32 flSetDebugMode(u32 flag);                          // Range: 0x3F2280 -> 0x3F22A0
void flPS2DebugInit();                                 // Range: 0x3F2340 -> 0x3F242C
void flPS2DebugStrDisp();                              // Range: 0x3F2450 -> 0x3F2B40
s32 flPrintL(s32 posi_x, s32 posi_y, s8 *format, ...); // Range: 0x3F2B40 -> 0x3F2D08
s32 flPrintColor(u32 col);                             // Range: 0x3F2D10 -> 0x3F2E04
void flPS2DispSystemInfo(s32 x, s32 y);                // Range: 0x3F2E10 -> 0x3F34B8

// flps2math.c
void flmatMakeViewport(MTX *lpmat, s32 dwx, s32 dwy, s32 dwWidth, s32 dwHeight, f32 dvMinz,
                       f32 dvMaxz);   // Range: 0x3F7CE0 -> 0x3F811C
u16 flPS2GetStaticVramArea(u32 size); // Range: 0x3F8450 -> 0x3F8564
void flPS2VramInit();                 // Range: 0x3FCFB0 -> 0x3FD068
s32 flInitialize();                   // Range: 0x3FE0B0 -> 0x3FE1A8
s32 flFlip(u32 flag);                 // Range: 0x3FE580 -> 0x3FE648

s32 flPS2PADModuleInit();                                    // Range: 0x4000B0 -> 0x400120
s32 tarPADInit();                                            // Range: 0x400120 -> 0x40041C
void tarPADDestroy();                                        // Range: 0x400420 -> 0x400448
void flPADConfigSetACRtoXX(s32 padnum, s16 a, s16 b, s16 c); // Range: 0x400450 -> 0x4004B8
void tarPADRead();                                           // Range: 0x4004C0 -> 0x400624

// mcsub.c
void MemcardInit(); // Range: 0x403EC0 -> 0x403F38

// knjsub.c
void KnjFlush(); // Range: 0x407E90 -> 0x407FE8

// savesub.c
void SaveInit(s32 file_type, s32 save_mode); // Range: 0x40A210 -> 0x40A3D8
s32 SaveMove();                              // Range: 0x40A3E0 -> 0x40A464

// cse.c
s32 cseExecServer(); // Range: 0x4116A0 -> 0x411730

// reboot.c
void Reboot_Program(s8 *args); // Range: 0x413F40 -> 0x414030

// .rodata

extern const u8 stage_bgw_number[22][3];       // size: 0x42, address: 0x4E6FD0
extern const u8 Dir_Menu_Max_Data[10][7];      // size: 0x46, address: 0x504FB0
extern const SystemDir Dir_Default_Data;       // size: 0x48, address: 0x505000
extern const u8 Page_Data[10];                 // size: 0xA, address: 0x505048
extern const Permission Permission_PL_Data;    // size: 0x18, address: 0x5224C0
extern const s8 plid_data[20];                 // size: 0x14, address: 0x54B230
extern const u8 PL_Color_Data[20];             // size: 0x14, address: 0x552050
extern const struct _SAVE_W Game_Default_Data; // size: 0x208, address: 0x5544C0
extern const FLPAD_CONFIG fltpad_config_basic; // size: 0x2C, address: 0x55F530
extern const u32 flpad_io_map[25];             // size: 0x64, address: 0x55F560

// .sbss

extern MessageTable *msgSysDirTbl[];      // size: 0x4, address: 0x575620
extern MessageTable *msgExtraTbl[];       // size: 0x4, address: 0x575624
extern s32 bgPalCodeOffset[8];            // size: 0x20, address: 0x578AA0
extern s8 seraph_flag;                    // size: 0x1, address: 0x578C6C
extern MVXY bg_mvxy;                      // size: 0x18, address: 0x578C80
extern s16 base_y_pos;                    // size: 0x2, address: 0x578CC4
extern UNK_Data *parabora_own_table[20];  // size: 0x50, address: 0x578CD0
extern MessageData Message_Data[4];       // size: 0x30, address: 0x578ED0
extern s8 ca_check_flag;                  // size: 0x1, address: 0x5790F4
extern IO io_w;                           // size: 0x6C, address: 0x579230
extern u8 r_no_plus;                      // size: 0x1, address: 0x5792B8
extern UNK_14 rank_name_w[2];             // size: 0x8, address: 0x5792E8
extern s16 Name_00[2];                    // size: 0x4, address: 0x579374
extern NAME_WK name_wk[2];                // size: 0x64, address: 0x579390
extern s16 title_tex_flag;                // size: 0x2, address: 0x579464
extern s16 op_timer0;                     // size: 0x2, address: 0x579468
extern s16 appear_type;                   // size: 0x2, address: 0x5795C8
extern s16 pcon_rno[4];                   // size: 0x8, address: 0x5795D0
extern PPWORK ppwork[2];                  // size: 0x68, address: 0x579610
extern s16 EXE_flag;                      // size: 0x2, address: 0x579870
extern s16 bgm_level;                     // size: 0x2, address: 0x5798D0
extern s16 se_level;                      // size: 0x2, address: 0x5798D4
extern TPU *tpu_free;                     // size: 0x4, address: 0x579A8C
extern u8 *texcash_melt_buffer;           // size: 0x4, address: 0x579A90
extern s32 Zoom_Base_Position_Z;          // size: 0x4, address: 0x579AC4
extern s32 Zoom_Base_Position_Y;          // size: 0x4, address: 0x579AC8
extern s32 Zoom_Base_Position_X;          // size: 0x4, address: 0x579ACC
extern f32 Frame_Zoom_Y;                  // size: 0x4, address: 0x579AD0
extern f32 Frame_Zoom_X;                  // size: 0x4, address: 0x579AD4
extern f32 SA_Zoom_Y;                     // size: 0x4, address: 0x579AD8
extern f32 SA_Zoom_X;                     // size: 0x4, address: 0x579ADC
extern f32 Screen_Zoom_Y;                 // size: 0x4, address: 0x579AE0
extern f32 Screen_Zoom_X;                 // size: 0x4, address: 0x579AE4
extern u8 Screen_PAL;                     // size: 0x1, address: 0x579C20
extern u16 PLsw[2][2];                    // size: 0x8, address: 0x579C28
extern u32 Interrupt_Timer;               // size: 0x4, address: 0x579C34
extern u16 p4sw_buff;                     // size: 0x2, address: 0x579C38
extern u16 p3sw_buff;                     // size: 0x2, address: 0x579C3C
extern u16 p2sw_buff;                     // size: 0x2, address: 0x579C40
extern u16 p1sw_buff;                     // size: 0x2, address: 0x579C44
extern u8 Interrupt_Flag;                 // size: 0x1, address: 0x579C48
extern s16 Correct_Y[4];                  // size: 0x8, address: 0x579C50
extern s16 Correct_X[4];                  // size: 0x8, address: 0x579C58
extern u8 Turbo_Timer;                    // size: 0x1, address: 0x579C60
extern u8 Turbo;                          // size: 0x1, address: 0x579C64
extern u8 No_Trans;                       // size: 0x1, address: 0x579C68
extern u8 Disp_Size_V;                    // size: 0x1, address: 0x579C6C
extern u8 Disp_Size_H;                    // size: 0x1, address: 0x579C70
extern s32 Y_Adjust_Buff[3];              // size: 0xC, address: 0x579C78
extern s32 X_Adjust_Buff[3];              // size: 0xC, address: 0x579C88
extern s32 Y_Adjust;                      // size: 0x4, address: 0x579C94
extern s32 X_Adjust;                      // size: 0x4, address: 0x579C98
extern u8 Interface_Type[2];              // size: 0x2, address: 0x579C9C
extern u32 system_timer;                  // size: 0x4, address: 0x579CA0
extern u8 Process_Counter;                // size: 0x1, address: 0x579CA4
extern u16 p4sw_1;                        // size: 0x2, address: 0x579CA8
extern u16 p4sw_0;                        // size: 0x2, address: 0x579CAC
extern u16 p3sw_1;                        // size: 0x2, address: 0x579CB0
extern u16 p3sw_0;                        // size: 0x2, address: 0x579CB4
extern u16 p2sw_1;                        // size: 0x2, address: 0x579CB8
extern u16 p2sw_0;                        // size: 0x2, address: 0x579CBC
extern u16 p1sw_1;                        // size: 0x2, address: 0x579CC0
extern u16 p1sw_0;                        // size: 0x2, address: 0x579CC4
extern struct _VM_W vm_w;                 // size: 0x6C, address: 0x579D20
extern struct _SYSTEM_W sys_w;            // size: 0x1C, address: 0x579D90
extern u32 current_task_num;              // size: 0x4, address: 0x579DAC
extern u8 plsw_01[2];                     // size: 0x4, address: 0x579DD0
extern u8 plsw_00[2];                     // size: 0x4, address: 0x579DD4
extern u16 VS_Win_Record[2];              // size: 0x4, address: 0x579DD8
extern u16 IO_Result;                     // size: 0x2, address: 0x579DDC
extern u16 Keep_Grade[2];                 // size: 0x4, address: 0x579DE0
extern s16 Cont_Timer;                    // size: 0x2, address: 0x579E18
extern u16 Result_Timer[2];               // size: 0x4, address: 0x579E30
extern s16 Offset_BG_X[6];                // size: 0xC, address: 0x579E38
extern s16 Target_BG_X[6];                // size: 0xC, address: 0x579E48
extern u16 WGJ_Win;                       // size: 0x2, address: 0x579E54
extern u16 Win_Record[2];                 // size: 0x4, address: 0x579E5C
extern s16 Stock_Com_Color[2];            // size: 0x4, address: 0x579E78
extern s16 Bonus_Game_ex_result;          // size: 0x2, address: 0x579E7C
extern s16 Bonus_Game_result;             // size: 0x2, address: 0x579E9C
extern s16 Bonus_Game_Work;               // size: 0x2, address: 0x579EA0
extern s16 Bonus_Game_Flag;               // size: 0x2, address: 0x579EA4
extern s16 Max_vitality;                  // size: 0x2, address: 0x579EA8
extern s16 DE_X[2];                       // size: 0x4, address: 0x579EB0
extern s16 Random_ix32_ex;                // size: 0x2, address: 0x579EB4
extern s16 Limit_Time;                    // size: 0x2, address: 0x579EC0
extern s16 Insert_Y;                      // size: 0x2, address: 0x579F90
extern s16 M_Timer;                       // size: 0x2, address: 0x579FBC
extern s16 Random_ix32;                   // size: 0x2, address: 0x579FC0
extern s16 Random_ix16;                   // size: 0x2, address: 0x579FC4
extern s16 Unit_Of_Timer;                 // size: 0x2, address: 0x579FEC
extern s16 Sel_Arts_Complete[2];          // size: 0x4, address: 0x57A000
extern s16 ENTRY_X;                       // size: 0x2, address: 0x57A014
extern s16 F_Timer[2];                    // size: 0x4, address: 0x57A018
extern s16 E_Timer;                       // size: 0x2, address: 0x57A01C
extern s16 D_Timer;                       // size: 0x2, address: 0x57A028
extern s16 G_Timer;                       // size: 0x2, address: 0x57A02C
extern s16 Round_Level;                   // size: 0x2, address: 0x57A038
extern s16 Time_in_Time;                  // size: 0x2, address: 0x57A03C
extern s16 Control_Time;                  // size: 0x2, address: 0x57A040
extern u16 Game_timer;                    // size: 0x2, address: 0x57A044
extern u8 Pause_Type;                     // size: 0x1, address: 0x57A048
extern u8 CPU_Rec[2];                     // size: 0x2, address: 0x57A04C
extern u8 Forbid_Reset;                   // size: 0x1, address: 0x57A050
extern u8 CPU_Time_Lag[2];                // size: 0x2, address: 0x57A054
extern u8 Decide_ID;                      // size: 0x1, address: 0x57A064
extern u8 Reset_Bootrom;                  // size: 0x1, address: 0x57A068
extern s8 Menu_Page_Buff;                 // size: 0x1, address: 0x57A06C
extern u8 End_Training;                   // size: 0x1, address: 0x57A070
extern u8 Disp_Attack_Data;               // size: 0x1, address: 0x57A078
extern u8 Training_ID;                    // size: 0x1, address: 0x57A07C
extern u8 Pause_Down;                     // size: 0x1, address: 0x57A080
extern s8 Vital_Handicap[6][2];           // size: 0xC, address: 0x57A090
extern u8 Direction_Working[6];           // size: 0x6, address: 0x57A0A0
extern u8 Page_Max;                       // size: 0x1, address: 0x57A0A8
extern u8 Play_Mode;                      // size: 0x1, address: 0x57A0AC
extern u8 Present_Mode;                   // size: 0x1, address: 0x57A0B0
extern s8 VS_Stage;                       // size: 0x1, address: 0x57A0B4
extern u8 reset_NG_flag;                  // size: 0x1, address: 0x57A0B8
extern s8 Menu_Max;                       // size: 0x1, address: 0x57A0BC
extern s8 Menu_Page;                      // size: 0x1, address: 0x57A0C0
extern u8 Mode_Type;                      // size: 0x1, address: 0x57A0C4
extern s8 Menu_Cursor_Move;               // size: 0x1, address: 0x57A0D8
extern u8 Play_Game;                      // size: 0x1, address: 0x57A0DC
extern u8 Disappear_LOGO;                 // size: 0x1, address: 0x57A0E4
extern u8 Replay_Status[2];               // size: 0x2, address: 0x57A0E8
extern s8 Menu_Cursor_Y[2];               // size: 0x2, address: 0x57A0EC
extern s8 Menu_Cursor_X[2];               // size: 0x2, address: 0x57A0F0
extern u8 Unsubstantial_BG[4];            // size: 0x4, address: 0x57A0F4
extern s8 Convert_Buff[4][2][12];         // size: 0x60, address: 0x57A100
extern u8 F_No3[2];                       // size: 0x2, address: 0x57A1CC
extern u8 F_No2[2];                       // size: 0x2, address: 0x57A1D0
extern u8 F_No1[2];                       // size: 0x2, address: 0x57A1D4
extern u8 F_No0[2];                       // size: 0x2, address: 0x57A1D8
extern u8 PL_Wins[2];                     // size: 0x2, address: 0x57A1F4
extern u8 Cont_No[4];                     // size: 0x4, address: 0x57A1F8
extern u8 ixbfw_cut;                      // size: 0x1, address: 0x57A1FC
extern u8 test_flag;                      // size: 0x1, address: 0x57A200
extern u8 Stop_Update_Score;              // size: 0x1, address: 0x57A204
extern u8 Lamp_No;                        // size: 0x1, address: 0x57A210
extern u8 Disp_Cockpit;                   // size: 0x1, address: 0x57A218
extern u8 Conclusion_Flag;                // size: 0x1, address: 0x57A248
extern u8 Exit_Menu;                      // size: 0x1, address: 0x57A24C
extern u8 Play_Type;                      // size: 0x1, address: 0x57A250
extern u8 Pause_ID;                       // size: 0x1, address: 0x57A254
extern u8 Pause;                          // size: 0x1, address: 0x57A258
extern u8 Game_difficulty;                // size: 0x1, address: 0x57A25C
extern u8 Game_pause;                     // size: 0x1, address: 0x57A260
extern u8 Menu_Suicide[4];                // size: 0x4, address: 0x57A264
extern u8 Connect_Status;                 // size: 0x1, address: 0x57A268
extern s8 Cursor_Y_Pos[2][4];             // size: 0x8, address: 0x57A278
extern u8 M_No[4];                        // size: 0x4, address: 0x57A29C
extern u8 D_No[4];                        // size: 0x4, address: 0x57A2A0
extern u8 G_No[4];                        // size: 0x4, address: 0x57A2A4
extern u8 S_No[4];                        // size: 0x4, address: 0x57A2A8
extern u8 C_No[4];                        // size: 0x4, address: 0x57A2AC
extern u8 E_No[4];                        // size: 0x4, address: 0x57A2B0
extern u8 E_Number[2][4];                 // size: 0x8, address: 0x57A2B8
extern s8 Request_Disp_Rank[2][4];        // size: 0x8, address: 0x57A2E0
extern s8 Rank_In[2][4];                  // size: 0x8, address: 0x57A2E8
extern s8 Suicide[8];                     // size: 0x8, address: 0x57A2F8
extern u8 Continue_Cut[2];                // size: 0x2, address: 0x57A304
extern s8 Last_Selected_EM[2];            // size: 0x2, address: 0x57A30C
extern u8 WGJ_Target;                     // size: 0x1, address: 0x57A338
extern u8 Continue_Count_Down[2];         // size: 0x2, address: 0x57A33C
extern u8 GO_No[4];                       // size: 0x4, address: 0x57A344
extern u8 Scene_Cut;                      // size: 0x1, address: 0x57A348
extern u8 Battle_Q[2];                    // size: 0x2, address: 0x57A364
extern u8 SC_No[4];                       // size: 0x4, address: 0x57A388
extern u8 Bonus_Type;                     // size: 0x1, address: 0x57A3B4
extern s8 Stock_Com_Arts[2];              // size: 0x2, address: 0x57A3C4
extern u8 End_PL;                         // size: 0x1, address: 0x57A3C8
extern s8 Stage_Cheap_Finish[2];          // size: 0x2, address: 0x57A3D0
extern s8 Stage_Perfect_Finish[2];        // size: 0x2, address: 0x57A3D4
extern s8 Stage_Lost_Round[2];            // size: 0x2, address: 0x57A3D8
extern u8 Extra_Break;                    // size: 0x1, address: 0x57A3E0
extern u8 Combo_Demo_Flag;                // size: 0x1, address: 0x57A3EC
extern u8 Get_Demo_Index;                 // size: 0x1, address: 0x57A3F0
extern s8 Bonus_Game_Complete;            // size: 0x1, address: 0x57A3F4
extern s8 Cheap_Finish[2];                // size: 0x2, address: 0x57A400
extern s8 Perfect_Finish[2];              // size: 0x2, address: 0x57A404
extern s8 Stage_SA_Finish[2];             // size: 0x2, address: 0x57A408
extern s8 Super_Arts_Finish[2];           // size: 0x2, address: 0x57A40C
extern s8 Lost_Round[2];                  // size: 0x2, address: 0x57A410
extern s8 Deley_Shot_Timer[2];            // size: 0x2, address: 0x57A414
extern s8 Deley_Shot_No[2];               // size: 0x2, address: 0x57A418
extern u8 Final_Result_id;                // size: 0x1, address: 0x57A480
extern u8 Weak_PL;                        // size: 0x1, address: 0x57A48C
extern u8 CC_Value[2];                    // size: 0x2, address: 0x57A494
extern u8 paring_bonus_r[2];              // size: 0x2, address: 0x57A4B0
extern u8 paring_counter[2];              // size: 0x2, address: 0x57A4B4
extern s8 Break_Com[2][20];               // size: 0x28, address: 0x57A4C0
extern s8 No_Death;                       // size: 0x1, address: 0x57A51C
extern s8 PB_Music_Off;                   // size: 0x1, address: 0x57A520
extern s8 Round_Operator[2];              // size: 0x2, address: 0x57A54C
extern s8 Operator_Status[2];             // size: 0x2, address: 0x57A550
extern s8 Stop_SG;                        // size: 0x1, address: 0x57A554
extern u8 Usage;                          // size: 0x1, address: 0x57A55C
extern s8 Player_Color[2];                // size: 0x2, address: 0x57A578
extern s8 Naming_Cut[2];                  // size: 0x2, address: 0x57A580
extern s8 Ignore_Entry[2];                // size: 0x2, address: 0x57A58C
extern u8 Continue_Coin[2];               // size: 0x2, address: 0x57A590
extern s8 Stop_Combo;                     // size: 0x1, address: 0x57A59C
extern s8 Exec_Wipe;                      // size: 0x1, address: 0x57A5D8
extern s8 Demo_Time_Stop;                 // size: 0x1, address: 0x57A5E0
extern u8 Country;                        // size: 0x1, address: 0x57A5E4
extern s8 Select_Demo_Index;              // size: 0x1, address: 0x57A5E8
extern s8 COM_id;                         // size: 0x1, address: 0x57A5F4
extern s8 Player_Number;                  // size: 0x1, address: 0x57A604
extern s8 Last_Player_id;                 // size: 0x1, address: 0x57A608
extern s8 Player_id;                      // size: 0x1, address: 0x57A60C
extern s8 Select_Timer;                   // size: 0x1, address: 0x57A618
extern s8 Demo_Stage_Index;               // size: 0x1, address: 0x57A628
extern s8 Demo_PL_Index;                  // size: 0x1, address: 0x57A62C
extern s32 Next_Demo;                     // size: 0x4, address: 0x57A630
extern s8 Demo_Flag;                      // size: 0x1, address: 0x57A634
extern s8 E_07_Flag[2];                   // size: 0x2, address: 0x57A63C
extern s8 Rank_Type;                      // size: 0x1, address: 0x57A658
extern s8 Demo_Type;                      // size: 0x1, address: 0x57A65C
extern u8 Present_Rank[2];                // size: 0x2, address: 0x57A668
extern s8 Request_G_No;                   // size: 0x1, address: 0x57A66C
extern s8 Request_E_No;                   // size: 0x1, address: 0x57A670
extern s8 Personal_Timer[2];              // size: 0x2, address: 0x57A674
extern s8 Cover_Timer;                    // size: 0x1, address: 0x57A678
extern s8 Switch_Type;                    // size: 0x1, address: 0x57A67C
extern s8 Next_Step;                      // size: 0x1, address: 0x57A680
extern s8 Champion;                       // size: 0x1, address: 0x57A690
extern s8 New_Challenger;                 // size: 0x1, address: 0x57A694
extern s8 LOSER;                          // size: 0x1, address: 0x57A698
extern s8 WINNER;                         // size: 0x1, address: 0x57A69C
extern s8 judge_flag;                     // size: 0x1, address: 0x57A6A0
extern s8 Continue_Count[2];              // size: 0x2, address: 0x57A6B4
extern s8 Request_Break[2];               // size: 0x2, address: 0x57A6B8
extern s8 Forbid_Break;                   // size: 0x1, address: 0x57A6BC
extern s8 Super_Arts[2];                  // size: 0x2, address: 0x57A6C0
extern s8 Fade_Flag;                      // size: 0x1, address: 0x57A6C4
extern u8 Round_num;                      // size: 0x1, address: 0x57A6CC
extern u8 Allow_a_battle_f;               // size: 0x1, address: 0x57A6D0
extern u8 My_char[2];                     // size: 0x2, address: 0x57A6D4
extern s8 Break_Into;                     // size: 0x1, address: 0x57A6D8
extern s8 Loser_id;                       // size: 0x1, address: 0x57A6E4
extern s8 Winner_id;                      // size: 0x1, address: 0x57A6E8
extern u32 WGJ_Score;                     // size: 0x4, address: 0x57A70C
extern u32 Stage_Stock_Score[2];          // size: 0x8, address: 0x57A728
extern u32 Score[2][3];                   // size: 0x18, address: 0x57A760
extern u32 Record_Timer;                  // size: 0x4, address: 0x57A810
extern u8 check_screen_L;                 // size: 0x1, address: 0x57A828
extern u8 check_screen_S;                 // size: 0x1, address: 0x57A82C
extern s8 Slow_Timer;                     // size: 0x1, address: 0x57A830
extern u8 sysSLOW;                        // size: 0x1, address: 0x57A834
extern u8 sysFF;                          // size: 0x1, address: 0x57A838
extern s8 Debug_w[72];                    // size: 0x48, address: 0x57A860
extern s16 *dctex_linear;                 // size: 0x4, address: 0x57A950
extern MPP mpp_w;                         // size: 0x4C, address: 0x57A9F0
extern s32 system_init_level;             // size: 0x4, address: 0x57AA3C
extern u32 flDebugTrueTime[4];            // size: 0x10, address: 0x57AB50
extern s32 flPS2FlipCancelFlag;           // size: 0x4, address: 0x57AB78
extern u32 flPs2FBA;                      // size: 0x4, address: 0x57AB84
extern s32 flClayNum;                     // size: 0x4, address: 0x57AB88
extern s32 flPTNum;                       // size: 0x4, address: 0x57AE38
extern FLPS2VIF1Control flPs2VIF1Control; // size: 0x3C, address: 0x57AE50
extern FL_FMS flFMS;                      // size: 0x18, address: 0x57AEB0
extern u32 flSystemRenderOperation;       // size: 0x4, address: 0x57AEC8
extern u32 flSystemRenderState;           // size: 0x4, address: 0x57AECC
extern u32 flLoadCount;                   // size: 0x4, address: 0x57AED8
extern plContext flFrameBuf;              // size: 0x48, address: 0x57AEF0
extern s32 flFrame;                       // size: 0x4, address: 0x57AF38
extern s32 flHeight;                      // size: 0x4, address: 0x57AF3C
extern s32 flWidth;                       // size: 0x4, address: 0x57AF40
extern s32 flCTNum;                       // size: 0x4, address: 0x57AF44
extern TARPAD tarpad_root[2];             // size: 0x68, address: 0x57B040
extern PPGDataList ppgCapLogoList;        // size: 0x8, address: 0x57B308
extern Palette ppgCapLogoPal;             // size: 0x14, address: 0x57B310
extern Texture ppgCapLogoTex;             // size: 0x20, address: 0x57B330
extern PPGDataList ppgAdxList;            // size: 0x8, address: 0x57B350
extern PPGDataList ppgWarList;            // size: 0x8, address: 0x57B358
extern Palette ppgAdxPal;                 // size: 0x14, address: 0x57B360
extern Palette ppgWarPal;                 // size: 0x14, address: 0x57B380
extern Texture ppgWarTex;                 // size: 0x20, address: 0x57B3A0

// .bss

extern MEM_BLOCK sysmemblock[4096]; // size: 0x10000, address: 0x584C80

extern BG bg_w;                                   // size: 0x428, address: 0x595830
extern CharInitData char_init_data[23];           // size: 0x8FC, address: 0x595C60
extern f32 PrioBase[128];                         // size: 0x200, address: 0x5E3F50
extern PLW plw[2];                                // size: 0x8D8, address: 0x5E4D20
extern RCKeyWork rckey_work[64];                  // size: 0x300, address: 0x5E5600
extern RANK_DATA Ranking_Data[20];                // size: 0x190, address: 0x5E5900
extern struct _SAVE_W save_w[6];                  // size: 0xC30, address: 0x6B4E80
extern Permission permission_player[6];           // size: 0x90, address: 0x6B5AB0
extern SystemDir system_dir[6];                   // size: 0x1B0, address: 0x6B5B40
extern _REPLAY_W Replay_w;                        // size: 0x7448, address: 0x6B5CF0
extern struct _REP_GAME_INFOR Rep_Game_Infor[11]; // size: 0x18C, address: 0x6BD140
extern struct _TASK task[11];                     // size: 0xDC, address: 0x6BD2D0
extern u8 Order_Dir[148];                         // size: 0x94, address: 0x6BD5F0
extern u8 Order_Timer[148];                       // size: 0x94, address: 0x6BD690
extern u8 Order[148];                             // size: 0x94, address: 0x6BD730
extern FLTexture flPalette[1088];                 // size: 0xFF00, address: 0x6C56D0
extern FLTexture flTexture[256];                  // size: 0x3C00, address: 0x6D55D0
extern FLPS2DrawStart flPs2DrawStart;             // size: 0x140, address: 0x6E24D0
extern FLPS2DB flPs2Db[2];                        // size: 0x140, address: 0x6E2610
extern FLPS2State flPs2State;                     // size: 0x470, address: 0x6E2750

#endif
