#ifndef MCSUB_H
#define MCSUB_H

#include "types.h"

typedef struct _file {
    // total size: 0x10
    s32 flag;      // offset 0x0, size 0x4
    s8 *name;      // offset 0x4, size 0x4
    intptr_t bufs; // offset 0x8, size 0x4
    s32 size;      // offset 0xC, size 0x4
} _file;

typedef struct _memcard_file {
    // total size: 0x74
    s8 *title1;           // offset 0x0, size 0x4
    s8 *title2;           // offset 0x4, size 0x4
    struct _file file[6]; // offset 0x8, size 0x60
    s32 fnum_flag;        // offset 0x68, size 0x4
    s32 copy_flag;        // offset 0x6C, size 0x4
    s32 req_clust;        // offset 0x70, size 0x4
} _memcard_file;

typedef struct memcard_work {
    // total size: 0xE4
    s32 r_no_0;      // offset 0x0, size 0x4
    s32 r_no_1;      // offset 0x4, size 0x4
    s32 cnt_0;       // offset 0x8, size 0x4
    s32 cnt_1;       // offset 0xC, size 0x4
    s32 max_port;    // offset 0x10, size 0x4
    s32 port;        // offset 0x14, size 0x4
    s32 cmds;        // offset 0x18, size 0x4
    s32 rslt;        // offset 0x1C, size 0x4
    s32 retry;       // offset 0x20, size 0x4
    s32 result;      // offset 0x24, size 0x4
    s32 info_type;   // offset 0x28, size 0x4
    s32 info_free;   // offset 0x2C, size 0x4
    s32 info_format; // offset 0x30, size 0x4
    s32 stat[3];     // offset 0x34, size 0xC
    s32 free[3];     // offset 0x40, size 0xC
    u32 new;         // offset 0x4C, size 0x4
    s8 dir[34];      // offset 0x50, size 0x22
    s8 path[66];     // offset 0x72, size 0x42
    s32 fd;          // offset 0xB4, size 0x4
    s32 flag;        // offset 0xB8, size 0x4
    s32 size;        // offset 0xBC, size 0x4
    s32 attr;        // offset 0xC0, size 0x4
    s32 mode;        // offset 0xC4, size 0x4
    s32 copy;        // offset 0xC8, size 0x4
    s32 act_no;      // offset 0xCC, size 0x4
    void *bufs;      // offset 0xD0, size 0x4
    s32 file_type;   // offset 0xD4, size 0x4
    s32 file_no;     // offset 0xD8, size 0x4
    void *icon;      // offset 0xDC, size 0x4
    s32 exe_flag;    // offset 0xE0, size 0x4
} memcard_work;

typedef struct memcard_date {
    // total size: 0x8
    u8 dayofweek; // offset 0x0, size 0x1
    u8 sec;       // offset 0x1, size 0x1
    u8 min;       // offset 0x2, size 0x1
    u8 hour;      // offset 0x3, size 0x1
    u8 day;       // offset 0x4, size 0x1
    u8 month;     // offset 0x5, size 0x1
    u16 year;     // offset 0x6, size 0x2
} memcard_date;

void MemcardInit();
void *McActIconTexAdrs(s32 file_type, s32 num);
s32 McActAvailSet(s32 *ico);
s32 McActResult();
void McActCheckSet();
void McActMain();
void McActInit(s32 file_type, s32 file_no);
void McActSave0Set(s32 port, void *bufs, s32 mode);
void McActExistSet(s32 port, void *bufs);
s32 McActConChk(s32 port);
void McActFormatSet(s32 port);
void McActSaveSet(s32 port, void *bufs);
void McActNewClr();
void McActLoadSet(s32 port, void *bufs);
void McActLastDate(memcard_date *date);
s32 McActNewChk(s32 port);
void McActZenNum(s32 num, s8 *buf, s32 mode, s32 max);

#endif
