#include "sf33rd/Source/Game/VM_SUB.h"
#include "common.h"
#include "sf33rd/Source/Game/vm.h"

u8 VM_Access_Request(u8 Request, u8 Drive) {
    vm_w.Request = Request;
    vm_w.Drive = Drive;
    return 1;
}

void Setup_File_Property(s16 file_type, u8 number) {
    switch (file_type) {
    case 0:
        vm_w.File_Name = SystemFileName;
        vm_w.File_Type = 0;
        vm_w.Save_Size = 0xC00;
        vm_w.Block_Size = 3;
        vm_w.Icon_Type = 0;
        break;

    case 3:
        break;

    case 1:
        vm_w.File_Name = Replay_File_Name[number];
        vm_w.File_Type = 1;
        vm_w.Save_Size = 0x3C00;
        vm_w.Block_Size = 0xF;
        vm_w.Icon_Type = 2;
        break;

    case 2:
        vm_w.File_Name = SysDir_File_Name[number];
        vm_w.File_Type = 2;
        vm_w.Save_Size = 0x400;
        vm_w.Block_Size = 1;
        vm_w.Icon_Type = 5;
        break;
    }
}

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_187_00555790);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_188_005557A0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_189_005557B0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_190_005557C0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_191_005557D0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_192_005557E0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_193_005557F0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_194_00555800);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_195_00555810);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_196_00555820);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_197_00555830);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_198_00555840);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_199_00555850);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_200_00555860);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_201_00555870);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_202_00555880);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_203_00555890);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_204_005558A0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_205_005558B0);

INCLUDE_RODATA("asm/anniversary/nonmatchings/sf33rd/Source/Game/VM_SUB", literal_206_005558C0);
