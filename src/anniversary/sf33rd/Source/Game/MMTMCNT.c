#include "sf33rd/Source/Game/MMTMCNT.h"
#include "common.h"

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/MMTMCNT", MM_num);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/MMTMCNT", TM_num);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/MMTMCNT", pmo_list);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/MMTMCNT", pto_list);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/MMTMCNT", mto_list);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MMTMCNT", Purge_com_player_from_mm);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MMTMCNT", Purge_mmtm_area);
#else
void Purge_mmtm_area(s16 ix) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MMTMCNT", Purge_memory_of_list);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MMTMCNT", Purge_texcash_of_list);
#else
void Purge_texcash_of_list(s16 ix) {
    not_implemented(__func__);
}
#endif

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/MMTMCNT", Make_texcash_of_list);
#else
void Make_texcash_of_list(s16 ix) {
    not_implemented(__func__);
}
#endif
