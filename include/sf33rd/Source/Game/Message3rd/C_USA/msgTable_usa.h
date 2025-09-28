#ifndef MSGTABLE_USA_H
#define MSGTABLE_USA_H

#include "structs.h"

extern MessageTable *pl_mes_tbl[20]; // size: 0x50, address: 0x575530
extern MessageTable *pl_tlk_tbl[20]; // size: 0x50, address: 0x575580
extern MessageTable *pl_end_tbl[20]; // size: 0x50, address: 0x5755D0
extern MessageTable *msgSysDirTbl[]; // size: 0x4, address: 0x575620
extern MessageTable *msgExtraTbl[];  // size: 0x4, address: 0x575624
extern MessageTable *msgMenuTbl[];   // size: 0x4, address: 0x575628

#endif
