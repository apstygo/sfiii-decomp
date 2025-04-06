#ifndef VM_SUB_H
#define VM_SUB_H

#include "structs.h"
#include "types.h"

extern u8 *Replay_File_Name[]; // size: 0x28, 0x00574420
extern u8 *SysDir_File_Name[]; // size: 0x4, 00574450
extern u8 *SystemFileName;     // size: 0x4,  0x00574F10

extern struct _VM_W vm_w;

u8 VM_Access_Request(u8 Request, u8 Drive);
void Setup_File_Property(s16 file_type, u8 number);

#endif
