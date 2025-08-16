#include "sf33rd/Source/Game/spgauge.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", spgauge_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", spg1p_npos_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", spg2p_npos_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", sa_time_data_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", sa_color_data2_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", sagauge_colchg_tbl);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", spgauge_cont_init);
#else
void spgauge_cont_init() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", spgauge_cont_demo_init);
#else
void spgauge_cont_demo_init() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", spgauge_cont_main);
#else
void spgauge_cont_main() {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", sag_bug_fix);
#else
void sag_bug_fix(s32 side) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", spgauge_control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", wipe_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", satime_ko_after_clear);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", sa_time_moji_send);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", samoji_control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", sast_control);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", sast_color_chenge);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", sa_color_chenge);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", sagauge_color_chenge);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", sa_moji_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", sa_gauge_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", spgauge_sound_request);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", spgauge_work_clear);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", spgauge_wipe_write);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", sa_waku_trans);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", tr_spgauge_cont_init);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/spgauge", tr_spgauge_cont_init2);
