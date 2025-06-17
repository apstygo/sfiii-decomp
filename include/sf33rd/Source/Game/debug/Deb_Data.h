#ifndef DEB_DATA_H
#define DEB_DATA_H

#include "types.h"

typedef struct /* @anon0 */ {
    // total size: 0x8
    u8 max; // offset 0x0, size 0x1
    char * name; // offset 0x4, size 0x4
} DEBUG_STR_DAT;

extern u8 * debug_name_data[5]; // size: 0x14, address: 0x5745B0
extern const DEBUG_STR_DAT debug_string_data[72]; // size: 0x240, address: 0x5592D0

#endif
