#include "sf33rd/Source/Game/SysDir.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", omop_guard_type);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", sysdir_base_move);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", use_ex_gauge);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", guard_distance);

const s16 sa_gauge_omake[4] = { 0x0, 0x18, 0x20, 0x2C };

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", stun_gauge_omake);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", stun_gauge_r_omake);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", stun_gauge_len_omake);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", blok_b_omake);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", blok_r_omake);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", sag_stock_omake);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", sag_length_omake);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", base_vital_omake);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", sag_ikinari_max);
#else
u32 sag_ikinari_max() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", check_use_all_SA);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", check_without_SA);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", init_omop);
#else
void init_omop() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", get_extra_option_parameter);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/SysDir", get_system_direction_parameter);
