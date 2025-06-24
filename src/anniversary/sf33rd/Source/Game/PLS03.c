#include "sf33rd/Source/Game/PLS03.h"
#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", hissatsu_setup_union);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", cmdixconv_table);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", cmdixconv);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_full_gauge_attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_full_gauge_attack2);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_super_arts_attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_super_arts_attack_dc);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", execute_super_arts);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_special_attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", chainex_spat_cancel_kidou);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_leap_attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_nm_attack);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", hikusugi_check);
#else
s16 hikusugi_check(WORK *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_chouhatsu);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_nagenuke_cmd);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", nml_catch_h2_ok);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_catch_attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", set_attack_routine_number);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", get_nearing_range);
#else
u16 get_nearing_range(s16 pnum, s16 kos) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", waza_select);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", decode_wst_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", get_em_body_range);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", cmd_ex_check);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", shot_prio);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", shot_data_convert);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", shot_refresh);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", shot_data_refresh);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", rc_shot_conv);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", renbanshot_conpaneshot);
#else
s16 renbanshot_conpaneshot(const s16 *dadr, s16 pow) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", datacmd_conpanecmd);
#else
s16 datacmd_conpanecmd(s16 dat) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", renda_status_table);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_renda_cancel);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", cnmc_conv_data);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", cnmc_Z_lever_data);
// TODO: rename to cnmc_z_lever_data
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", _cnmc_z_lever_data);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", check_meoshi_cancel);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", gml_real_lever_data);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", get_meoshi_lever);
#else
s16 get_meoshi_lever(s16 data) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", get_meoshi_shot);
#else
s16 get_meoshi_shot(s16 data) {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS03", cmdshot_conv_tbl);
