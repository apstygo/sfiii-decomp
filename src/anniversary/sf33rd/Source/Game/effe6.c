#include "sf33rd/Source/Game/effe6.h"
#include "common.h"

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effect_E6_move);
#else
void effect_E6_move(WORK_Other *ewk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0001);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0002);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0003);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0004);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0005);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0006);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0007);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0009);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0010);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0010_sub);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0011);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0012);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0013);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0014);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0015);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_data_tbl);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0010_col_tbl);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0016);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0017);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0018);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0019);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0020);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0021);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0022);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0023);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0024);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0025);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0026);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0027);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0028);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0029);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0030);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0031);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", gill_range);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0032);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_0033);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effe6_init_common);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", effect_E6_init);
#else
s32 effect_E6_init(u8 char_num) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", ending_obj_load);
#else
void ending_obj_load() {
    not_implemented(__func__);
}
#endif

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", END_BCB);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/effe6", END_COL);
