#include "sf33rd/Source/Game/PulPul.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", comm_quay_pulpul);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_dm_shock);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_guard_shock);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_hit_shock);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", dokidoki_ix_change_table);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_01);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_02);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_03);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_04);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_05);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_06);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_07);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_08);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_09);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_10);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_11);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_20);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_21);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_22);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_23);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_24);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_25);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_26);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_27);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_28);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_29);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_30);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_31);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_32);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_33);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_34);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_35);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_36);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_37);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_38);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_39);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_40);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_41);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_42);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_43);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_44);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_xx);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulreq_x2);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", init_pulpul_work);
#else
void init_pulpul_work() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", init_pulpul_work2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", init_pulpul_round2);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulpul_stop);
#else
void pulpul_stop() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulpul_stop2);
#else
void pulpul_stop2(s32 ix) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulpul_request);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulpul_req_copy);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_vib_on);
#else
void pp_vib_on(s32 id) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulpul_request_again);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_operator_check_flag);
#else
void pp_operator_check_flag(u8 fl) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", move_pulpul_work);
#else
void move_pulpul_work() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", chkVibUnit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", move_pulpul);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pulpul_pdVibMxStart);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", vibParamTrans);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_screen_quake);
#else
void pp_screen_quake(s16 ix) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_conv_kow);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_pulpara_remake_at_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_pulpara_remake_at_init2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_pulpara_remake_at_hit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_pulpara_remake_at);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_pulpara_remake_dm_all);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_pulpara_guard);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_pulpara_hit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_pulpara_blocking);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_pulpara_catch);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_pulpara_caught);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_pulpara_remake_nm_move);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PulPul", pp_pulpara_shungokusatsu);
