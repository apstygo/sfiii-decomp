#ifndef DEB_DATA_H
#define DEB_DATA_H

#include "types.h"

typedef struct {
    // total size: 0x8
    u8 max;   // offset 0x0, size 0x1
    s8* name; // offset 0x4, size 0x4
} DEBUG_STR_DAT;

extern u8* debug_name_data[5];
extern const DEBUG_STR_DAT debug_string_data[72];

#endif
