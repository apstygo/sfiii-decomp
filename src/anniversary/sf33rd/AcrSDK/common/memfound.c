#include "sf33rd/AcrSDK/common/memfound.h"
#include "common.h"
#include "sf33rd/AcrSDK/common/memmgr.h"

MEM_MGR sysmemmgr; // size: 0x28, address: 0x578980

void mflInit(void *mem_ptr, s32 memsize, s32 memalign) {
    plmemInit(&sysmemmgr, sysmemblock, 0x1000, mem_ptr, memsize, memalign, 1);
}

u32 mflGetSpace() {
    return plmemGetSpace(&sysmemmgr);
}

u32 mflGetFreeSpace() {
    return plmemGetFreeSpace(&sysmemmgr);
}

u32 mflRegisterS(s32 len) {
    return plmemRegisterS(&sysmemmgr, len);
}

u32 mflRegister(s32 len) {
    return plmemRegister(&sysmemmgr, len);
}

void *mflTemporaryUse(s32 len) {
    return plmemTemporaryUse(&sysmemmgr, len);
}

void *mflRetrieve(u32 handle) {
    return plmemRetrieve(&sysmemmgr, handle);
}

s32 mflRelease(u32 handle) {
    return plmemRelease(&sysmemmgr, handle);
}

void *mflCompact() {
    return plmemCompact(&sysmemmgr);
}
