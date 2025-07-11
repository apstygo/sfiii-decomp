#include "common.h"

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Player_normal);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", setup_normal_process_flags);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_00000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_01000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_02000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_03000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_04000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_05000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nm_05_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nm_05_0100);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_06000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nm_06_0000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nm_06_0100);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nm_06_0200);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_07000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_08000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_09000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_10000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_16000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_17000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_18000);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_18000_init_unit);
#else
void Normal_18000_init_unit(PLW *wk, u8 ps) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_27000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_31000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_35000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_36000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_37000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_38000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_39000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_40000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_41000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_42000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_47000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_48000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_50000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_51000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_52000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_53000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_54000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_55000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", make_nm55_init_sp);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_56000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nm56_char_select);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_57000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nm57_dir_select);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", Normal_58000);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nmPB_data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", nmCE_data);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", plpnm_lv_00);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", normal_05);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", normal_06);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLPNM", jpdat_tbl);
