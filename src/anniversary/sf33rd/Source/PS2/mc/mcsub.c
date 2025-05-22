#include "sf33rd/Source/PS2/mc/mcsub.h"
#include "common.h"

// used in sdata
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_192_0055FF20);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_193_0055FF40);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_194_0055FF50);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_195_0055FF60);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_196_0055FF70);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_197_0055FF90);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_198_0055FFA8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_199_0055FFC0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_200_0055FFD8);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_201_0055FFE0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_202_0055FFF0);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_203_00560000);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", D_00560018); // ???

#if defined(TARGET_PS2)
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_214_00560020);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", MemcardInit);
#else
void MemcardInit() {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_sync);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_check_card);

// Also used in mc_delete_dir and mc_get_dir
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_285_00560030);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_286_00560050);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_check_file);

// Also used in mc_create_file and mc_write_file
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_320_00560070);
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_321_00560090);
// Also used in mc_create_file and mc_write_file
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_322_005600B0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_read_file);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_343_005600D0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_mkdir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_create_file);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_403_005600F0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_write_file);

// Also used in mc_delete_dir
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_422_00560110);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_delete_file);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_441_00560130);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_format);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_460_00560150);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_unformat);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_497_00560168);
// Also used in McActExistSet, McActLoadSet, McActSave0Set and McActSaveSet
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_498_00560170);
// Also used in mc_act_save
INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_499_00560178);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_delete_dir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_get_dir);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_527_00560180);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActInit);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActMain);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActStopSet);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_act_stop);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_act_return);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActCheckSet);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_act_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActExistSet);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_act_exist);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActLoadSet);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_act_load);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActSave0Set);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_act_save0);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActSaveSet);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_740_00560188);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_act_save);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActFormatSet);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_act_format);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_act_unformat);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_act_delete);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_act_remove);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_act_list);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActResult);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActConChk);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActNewClr);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActNewChk);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_904_005601B0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActAvailSet);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActLastDate);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActZenNum);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", McActIconTexAdrs);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", day_of_week);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", literal_989_005601E0);
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/PS2/mc/mcsub", mc_icon_sys_set);
