#ifndef MEMMGR_H
#define MEMMGR_H

#include "types.h"

#define MEM_NULL_HANDLE 0xFFFF

typedef struct {
    // total size: 0x10
    u8 *ptr;   // offset 0x0, size 0x4
    u32 len;   // offset 0x4, size 0x4
    u16 align; // offset 0x8, size 0x2
    u16 id;    // offset 0xA, size 0x2
    u16 prev;  // offset 0xC, size 0x2
    u16 next;  // offset 0xE, size 0x2
} MEM_BLOCK;

typedef struct {
    // total size: 0x28
    s32 cnt;          // offset 0x0, size 0x4
    s32 memsize;      // offset 0x4, size 0x4
    MEM_BLOCK *block; // offset 0x8, size 0x4
    s32 direction;    // offset 0xC, size 0x4
    u8 *memnow;       // offset 0x10, size 0x4
    u8 *memptr;       // offset 0x14, size 0x4
    s32 memalign;     // offset 0x18, size 0x4
    s32 used_size;    // offset 0x1C, size 0x4
    s32 tmemsize;     // offset 0x20, size 0x4
    u32 blocklist;    // offset 0x24, size 0x4
} MEM_MGR;

void plmemInit(MEM_MGR *memmgr, MEM_BLOCK *block, s32 count, void *mem_ptr, s32 memsize, s32 memalign,
               s32 direction);                               // Range: 0x116180 -> 0x11629C
u32 plmemRegister(MEM_MGR *memmgr, s32 len);                 // Range: 0x1162A0 -> 0x1162D8
u32 plmemRegisterAlign(MEM_MGR *memmgr, s32 len, s32 align); // Range: 0x1162E0 -> 0x1164B4
u32 plmemRegisterS(MEM_MGR *memmgr, s32 len);                // Range: 0x1164C0 -> 0x116980
void *plmemTemporaryUse(MEM_MGR *memmgr, s32 len);           // Range: 0x116980 -> 0x116AAC
void *plmemRetrieve(MEM_MGR *memmgr, u32 handle);            // Range: 0x116AB0 -> 0x116B20
s32 plmemRelease(MEM_MGR *memmgr, u32 handle);               // Range: 0x116B20 -> 0x116BFC
void *plmemCompact(MEM_MGR *memmgr);                         // Range: 0x116C00 -> 0x116E9C
u32 plmemGetSpace(MEM_MGR *memmgr);                          // Range: 0x116EA0 -> 0x116EC8
size_t plmemGetFreeSpace(MEM_MGR *memmgr);                   // Range: 0x116ED0 -> 0x116F5C

#endif
