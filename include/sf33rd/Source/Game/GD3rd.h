#ifndef GD3RD_H
#define GD3RD_H

#include "types.h"
#include "unknown.h"

extern s16 plt_req[2];
extern const u8 lpr_wrdata[3];
extern const u8 lpt_seldat[4];

s32 Setup_Directory_Record_Data();
s32 fsOpen(REQ *req);
void fsClose(REQ * /* unused */);
u32 fsGetFileSize(u16 fnum);
u32 fsCalSectorSize(u32 size);
s32 fsCheckCommandExecuting();
s32 fsRequestFileRead(REQ * /* unused */, u32 sec, void *buff);
s32 fsCheckFileReaded(REQ * /* unused */);
void waitVsyncDummy();
s16 load_it_use_any_key(u16 fnum, u8 kokey, u8 group);
s32 load_it_use_this_key(u16 fnum, s16 key);
void Init_Load_Request_Queue_1st();
void Request_LDREQ_Break();
u8 Check_LDREQ_Break();
void Push_LDREQ_Queue_Player(s16 id, s16 ix);

#endif