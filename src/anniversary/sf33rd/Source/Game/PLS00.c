#include "common.h"
#include "structs.h"

void process_normal(PLW *wk);
void nm_00000(PLW *wk);
void nm_01000(PLW *wk);
void nm_02000(PLW *wk);
void nm_03000(PLW *wk);
void nm_05000(PLW *wk);
void nm_07000(PLW *wk);
void nm_08000(PLW *wk);
void nm_09000(PLW *wk);
void nm_10000(PLW *wk);
void nm_16000(PLW *wk);
void nm_17000(PLW *wk);
void nm_18000(PLW *wk);
void nm_27000(PLW *wk);
void nm_29000(PLW *wk);
void nm_31000(PLW *wk);
void nm_34000(PLW *wk);
void nm_36000(PLW *wk);
void nm_37000(PLW *wk);
void nm_38000(PLW *wk);
void nm_39000(PLW *wk);
void nm_40000(PLW *wk);
void nm_42000(PLW *wk);
void nm_45000(PLW *wk);
void nm_47000(PLW *wk);
void nm_48000(PLW *wk);
void nm_49000(PLW *wk);
void nm_51000(PLW *wk);
void nm_52000(PLW *wk);
void nm_55000(PLW *wk);
void nm_57000(PLW *wk);
void process_damage(PLW *wk);
void dm_00000(PLW *wk);
void dm_04000(PLW *wk);
void dm_08000(PLW *wk);
void dm_17000(PLW *wk);
void dm_18000(PLW *wk);
void dm_25000(PLW *wk);
void process_catch(PLW *wk);
void process_caught(PLW *wk);
void process_attack(PLW *wk);

#if defined(TARGET_PS2)
INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", check_lever_data);
#else
void check_lever_data(PLW *wk) {
    not_implemented(__func__);
}
#endif

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", process_normal);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", TO_nm_01000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", TO_nm_36000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", TO_nm_09000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", TO_nm_37000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", TO_nm_38000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", TO_nm_18000_01);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_00000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_01000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_02000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_03000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_05000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_07000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_08000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_09000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_10000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_16000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_17000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", check_jump_rl_dir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", set_new_jpdir);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_18000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", jumping_cg_type_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", jumping_guard_type_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_27000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_27_cg_type_check);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_29000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_31000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_34000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_36000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_37000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_38000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_39000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_40000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_42000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_45000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_47000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_48000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_49000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_51000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_52000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_55000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", nm_57000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", process_damage);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", dm_00000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", dm_04000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", dm_08000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", dm_17000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", dm_18000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", dm_25000);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", process_catch);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", process_caught);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", process_attack);

INCLUDE_ASM("asm/anniversary/nonmatchings/sf33rd/Source/Game/PLS00", check_cg_cancel_data);

const s8 lvdir_conv[4] = { 0, 2, 1, 0 };

void (*const process_ndcca[5])(PLW *wk) = {
    process_normal, process_damage, process_catch, process_caught, process_attack
};

void (*const plpnm_xxxxx[59])(PLW *wk) = {
    nm_00000, nm_01000, nm_02000, nm_03000, nm_03000, nm_05000, nm_05000, nm_07000, nm_08000, nm_09000,
    nm_10000, nm_03000, nm_03000, nm_03000, nm_03000, nm_03000, nm_16000, nm_17000, nm_18000, nm_18000,
    nm_18000, nm_18000, nm_18000, nm_18000, nm_18000, nm_18000, nm_18000, nm_27000, nm_27000, nm_29000,
    nm_27000, nm_31000, nm_31000, nm_31000, nm_34000, nm_34000, nm_36000, nm_37000, nm_38000, nm_39000,
    nm_40000, nm_40000, nm_42000, nm_42000, nm_42000, nm_45000, nm_45000, nm_47000, nm_48000, nm_49000,
    nm_49000, nm_51000, nm_52000, nm_52000, nm_51000, nm_55000, nm_55000, nm_57000, nm_55000
};

void (*const plpdm_xxxxx[32])(PLW *wk) = { dm_00000, dm_04000, dm_04000, dm_04000, dm_04000, dm_04000, dm_04000,
                                           dm_04000, dm_08000, dm_08000, dm_08000, dm_08000, dm_04000, dm_04000,
                                           dm_18000, dm_18000, dm_04000, dm_17000, dm_18000, dm_18000, dm_18000,
                                           dm_18000, dm_18000, dm_18000, dm_00000, dm_25000, dm_18000, dm_18000,
                                           dm_18000, dm_18000, dm_18000, dm_18000 };
