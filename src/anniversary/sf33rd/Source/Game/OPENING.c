#include "sf33rd/Source/Game/OPENING.h"
#include "common.h"
#include "sf33rd/Source/Game/SYS_sub.h"
#include "sf33rd/Source/Game/aboutspr.h"
#include "sf33rd/Source/Game/op_sub.h"
#include "sf33rd/Source/Game/sc_sub.h"
#include "sf33rd/Source/Game/texcash.h"
#include "sf33rd/Source/Game/workuser.h"

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

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", TITLE_Init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", TITLE_Move);

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

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", title00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", optsr_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", literal_220_00523068);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/OPENING", literal_221_00523080);

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
