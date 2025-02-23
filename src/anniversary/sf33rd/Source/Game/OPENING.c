#include "sf33rd/Source/Game/OPENING.h"
#include "common.h"
#include "sf33rd/AcrSDK/ps2/foundaps2.h"
#include "sf33rd/Source/Common/MemMan.h"
#include "sf33rd/Source/Common/PPGFile.h"
#include "sf33rd/Source/Common/PPGWork.h"
#include "sf33rd/Source/Game/AcrUtil.h"
#include "sf33rd/Source/Game/DEMO00.h"
#include "sf33rd/Source/Game/GD3rd.h"
#include "sf33rd/Source/Game/RAMCNT.h"
#include "sf33rd/Source/Game/SYS_sub.h"
#include "sf33rd/Source/Game/WORK_SYS.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/bg.h"
#include "sf33rd/Source/Game/op_sub.h"
#include "sf33rd/Source/Game/sc_sub.h"
#include "sf33rd/Source/Game/texcash.h"
#include "sf33rd/Source/Game/workuser.h"

typedef const f32 *ro_f32_ptr;

static const f32 title00[25] = { 0.0009765625f, 0.001953125f, 0.7509765625f, 0.751953125f, -192.0f, -96.0f, 384.0f,
                                 192.0f,        -1.0f,        0.0f,          0.0f,         0.0f,    0.0f,   0.0f,
                                 0.0f,          0.0f,         0.0f,          0.0f,         0.0f,    0.0f,   0.0f,
                                 0.0f,          0.0f,         0.0f,          0.0f };

static ro_f32_ptr title[2] = { title00, title00 };

const s16 optsr_tbl[59] = { 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53,
                            54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73,
                            74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, -1 };

s16 op_obj_disp;
s8 op_scrn_end;
s16 op_timer0;
s16 title_tex_flag;
s16 music_scene;
s16 music_time;
s16 op_plmove_timer;
OPBW *opw_ptr;
s16 op_end_flag;
s16 op_demo_index;
s16 op_sound_status;
MVXY op_bg_mvxy[3];
OP_W op_w;

void OPBG_Init();
s16 OPBG_Move();

s16 opening_demo() {
    switch (D_No[3]) {
    case 0:
        D_No[3] += 1;
        OPBG_Init();
        break;

    case 1:
        if (OPBG_Move(0)) {
            D_No[3] += 1;
            reset_dma_group(0x8C40);
            purge_texcash_work(9);
            TexRelease_OP();
            TITLE_Init();
            FadeInit();
        }

        break;

    case 2:
        TITLE_Move(0);

        if (FadeIn(0, 4, 8) != 0) {
            D_No[3] += 1;
            op_timer0 = 300;
        }

        break;

    case 3:
        if (!Game_pause) {
            if (--op_timer0 == 0) {
                D_No[3] = 0x63;
            }
        }

        TITLE_Move(1);
        Disp_Copyright();
        break;

    default:
        TITLE_Move(1);
        Disp_Copyright();
        return 1;
    }

    return 0;
}

void TITLE_Init() {
    void *loadAdrs;
    u32 loadSize;
    s16 key;

    mmDebWriteTag("\nMAIN TITLE\n\n");
    Opening_Now = 0;
    ppgTitleList.tex = &ppgTitleTex;
    ppgTitleList.pal = NULL;
    ppgSetupCurrentDataList(&ppgTitleList);
    loadSize = load_it_use_any_key2(0x4E, &loadAdrs, &key, 2, 1);

    if (loadSize == 0) {
        flLogOut("メインタイトルのテクスチャが読み込めませんでした。\n");
        while (1) {}
    }

    ppgSetupTexChunk_1st(NULL, loadAdrs, loadSize, 0x259, 1, 0, 0);
    ppgSetupTexChunk_2nd(NULL, 0x259);
    ppgSetupTexChunk_3rd(NULL, 0x259, 1);
    Push_ramcnt_key(key);
    ppgSourceDataReleased(NULL);
    title_tex_flag = 1;
    op_w.r_no_0 = 0;
}

s16 TITLE_Move(u16 type) {
    ppgSetupCurrentDataList(&ppgTitleList);
    setTexAdrsMode(0);
    setFilterMode(0);

    switch (type) {
    case 0:
        switch (op_w.r_no_0) {
        case 0:
            op_w.r_no_0 += 1;
            Zoom_Value_Set(0x40);
            Frame_Up(0xC0, 0x70, 0x13);
            op_timer0 = 10;
            break;

        case 1:
            op_timer0 -= 1;

            if (op_timer0 <= 0) {
                op_w.r_no_0 += 1;
                op_timer0 = 19;
            }

            break;

        case 2:
            if (!Game_pause) {
                if (op_timer0-- >= 0) {
                    Frame_Down(0xC0, 0x70, 1);
                } else {
                    op_w.r_no_0 += 1;
                }
            }

            break;

        default:
            Zoom_Value_Set(0x40);
            break;
        }

        Put_char(title[type], 0x259, 9, 0xC0, 0x60, scr_sc, scr_sc);
        return 0;

    case 1:
        Put_char(title[type], 0x259, 9, 0xC0, 0x60, 1.0f, 1.0f);
        return 0;

    default:
        return 0;
    }
}

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", OPBG_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", OPBG_Move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", sound_trg_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", sound_trg_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", OPBG_Trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", oh_tsr_ck);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", oh_reload_tex);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", oh_bg_blk_w);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", oh_bg_blk_wh);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", oh_bg_blk_wv);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", oh_bg_blk_whv);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", opening_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_work_clear);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", oh_opening_demo);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", opening_init2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", opning_init_00000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", opning_init_01000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", opning_init_02000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", opening_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_100_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_101_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_102_move);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", literal_264_005230B8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", literal_265_005230D0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", sound_time_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", sound_trg_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", literal_321_00523528);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", literal_322_00523530);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_change_sound_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_quake_y_tbl0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", literal_479_00523590);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_101_sound);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_102_sound);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_103_sound);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_103_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_104_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_105_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_106_move);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_106_sound);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_107_sound);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_107_move);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_108_sound);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_108_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_109_move);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_109_sound);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_110_sound);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_110_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_111_move);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_111_sound);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_112_sound);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_112_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_113_move);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_113_sound);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_114_sound);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_114_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_115_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_116_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_117_move);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_115_sound);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_118_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0001);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0002);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0003);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0004);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0005);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0006);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0007);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0008);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0010);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0011);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0012);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0013);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0014);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0015);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0016);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg1_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg1_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg1_0001);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg1_0002);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg1_0003);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg2_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg2_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg2_0001);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg2_0002);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg2_0003);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", opening_title);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", opening_title_00);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", opening_title_01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_scrn_pos_set2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", Bg_Family_Set_op);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", ot_bg0_0004_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", op_bg0_0005_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", ot_bg0_0015_tbl);
