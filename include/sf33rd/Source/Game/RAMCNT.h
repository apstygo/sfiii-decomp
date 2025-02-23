#ifndef RAMCNT_H
#define RAMCNT_H

#include "structs.h"
#include "types.h"

extern RCKeyWork rckey_work[64]; // size: 0x300, address: 0x5E5600

void disp_ramcnt_free_area();
void Init_ram_control_work(u8 *adrs, s32 size);
void Push_ramcnt_key(s16 key);
void Purge_memory_of_kind_of_key(u8 kokey);
void Set_size_data_ramcnt_key(s16 key, u32 size);
u32 Get_ramcnt_address(s16 key);
s16 Search_ramcnt_type(u8 kokey);
s16 Pull_ramcnt_key(u32 memreq, u8 kokey, u8 group, u8 frre);
u32 Get_size_data_ramcnt_key(s16 key);

#endif
