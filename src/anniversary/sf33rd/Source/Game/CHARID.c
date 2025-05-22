#include "sf33rd/Source/Game/CHARID.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARID", char_init_data2);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARID", char_init_data_ex);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARID", set_char_base_data);
#else
void set_char_base_data(WORK *wk) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/CHARID", copy_char_base_data);
#else
void copy_char_base_data() {
    not_implemented(__func__);
}
#endif
