struct internal_state {
    int dummy;
};

#include "common.h"
#include "unknown.h"
#include "zlib.h"

typedef struct {
    // total size: 0x78
    struct z_stream_s info; // offset 0x0, size 0x48
    int state;              // offset 0x48, size 0x4
    _MEMMAN_OBJ mobj;       // offset 0x4C, size 0x2C
} ZLIB;

ZLIB zlib; // size: 0x78, address: 0x57A780

void *zlib_Malloc(void *, unsigned int, unsigned int);
void zlib_Free(void *, void *); // size: 0x0, address: 0x3B77C0

void zlib_Initialize(void* tempAdrs, int tempSize) {
    if (tempAdrs == NULL) {
        while (1) {}
    }
    
    mmHeapInitialize(
        &zlib.mobj, 
        tempAdrs, 
        tempSize, 
        0x10, 
        "- for zlib -"
    );
    
    zlib.info.zalloc = zlib_Malloc;
    zlib.info.zfree = zlib_Free;
    zlib.info.opaque = NULL;
}

void* zlib_Malloc(void* opaque, unsigned int items, unsigned int size) {
    opaque = opaque;
    return mmAlloc(&zlib.mobj, size * items, 0);
}

void zlib_Free(void* opaque, void* adrs) {
    opaque = opaque;
    mmFree(&zlib.mobj, (unsigned char*)adrs);
}

int zlib_Decompress(void* srcBuff, int srcSize, void* dstBuff, int dstSize) {
    zlib.info.next_in = srcBuff;
    zlib.info.avail_in = srcSize;
    zlib.info.next_out = dstBuff;
    zlib.info.avail_out = dstSize;
    zlib.state = 0;
    
    if (inflateInit_(&zlib.info, ZLIB_VERSION, 0x48) != 0) {
        return 0;
    }

    while (1) {
        zlib.state = inflate(&zlib.info, 0);

        if (zlib.state == 1) {
            break;
        }

        if (zlib.state == 0) {
            continue;
        } else {
            return 0;
        }
    }

    if (inflateEnd(&zlib.info) != 0) {
        return 0;
    }

    return zlib.info.total_out;
}