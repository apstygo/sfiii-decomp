#include "common.h"
#include "structs.h"

const FLPAD_CONFIG fltpad_config_basic = {
    .conf_sw = { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15,
                 16, 17, 18, 19, 20, 21, 22, 23, 24, 24, 24, 24, 24, 24, 24, 24 },
    .flip_lever = 0,
    .flip_ast1 = 0,
    .flip_ast2 = 0,
    .free = 0,
    .abut_on = 8,
    .ast1_on = 48,
    .ast2_on = 48,
    .free2 = 0
};

const u32 flpad_io_map[25] = { 0x1,     0x2,     0x4,      0x8,      0x10,     0x20,     0x40,   0x80,    0x100,
                               0x200,   0x400,   0x800,    0x1000,   0x2000,   0x4000,   0x8000, 0x10000, 0x20000,
                               0x40000, 0x80000, 0x100000, 0x200000, 0x400000, 0x800000, 0x0 };
