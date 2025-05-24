#include "sf33rd/Source/PS2/mc/savesub.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", load_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", load_busy_ck);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", SaveInit);
#else
void SaveInit(s32 file_type, s32 save_mode) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", SaveMove);
#else
s32 SaveMove() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_sw_get);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_move_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", mc_msg_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sels_result_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_slot_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_slot_start);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_slot_main);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_slot_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_slot_check2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_slot_yesno);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_slot_format);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_slot_save);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_slot_result);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_slot_exit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_move_sels);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sels_return_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", self_result_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_file_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_file_start);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_file_main);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_file_load);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_file_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_file_yesno);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_file_save);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_file_result);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", sel_file_exit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_move_self);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", aload_buf_adrs);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", auto_load_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", auto_load_load);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", auto_load_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", auto_load_yesno);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", auto_load_result);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", auto_load_exit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_move_aload);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", asave_result_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", auto_save_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", auto_save_load);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", auto_save_save);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", auto_save_result);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", auto_save_exit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_move_asave);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_move_exit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_move_test);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", decide_ck);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", cancel_ck);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", shotall_ck);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", decide_se);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", cancel_se);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", select_se);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", nogood_se);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", last_slot_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", auto_slot_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", push_any_key);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", yes_no_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", yes_no_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", self_order_get);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_data_store);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_data_store_system);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_data_store_sysdir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_data_store_replay);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_data_decode);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_data_decode_system);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_data_decode_sysdir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_data_decode_replay);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", load_data_set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", load_data_set_system);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", load_data_set_sysdir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", load_data_set_replay);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", info_data_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", icon_tex_chg);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", encode_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", decode_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_slot_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_file_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", save_msg_trans);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_198_00560238);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_199_00560240);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_200_00560248);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_201_00560250);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_202_00560258);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_203_00560260);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_204_00560268);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_205_00560270);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_206_00560278);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_207_00560280);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_208_00560288);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_209_00560290);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_210_00560298);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_211_005602A0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_212_005602A8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_213_005602B0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_214_005602B8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_215_005602C0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_216_005602C8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_217_005602D0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_234_005602E0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_235_00560300);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_864_00560330);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1476_00560350);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1477_00560358);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1478_00560360);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1479_00560368);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1480_00560370);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1481_00560378);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1482_00560380);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1520_00560388);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1521_005603A0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1522_005603C8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1523_005603D8);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1524_005603F0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1525_00560428);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1526_00560430);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1527_00560438);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1528_00560440);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1622_00560448);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1623_00560458);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1624_00560460);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1625_00560468);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/savesub", literal_1626_00560470);
