#ifndef EFL_SPU_MAP_H
#define EFL_SPU_MAP_H

#include "structs.h"
#include "types.h"

#define SPUBANK_MAX 16

typedef struct {
    // total size: 0x40
    u32 BankSize[SPUBANK_MAX]; // offset 0x0, size 0x40
} PSPUMAP_PAGE;

typedef struct {
    // total size: 0x10
    struct {
        // total size: 0x10
        union {
            s8 TagStrings[8]; // offset 0x0, size 0x8
            u64 Tag;          // offset 0x0, size 0x4
        };
        u32 NumPages;    // offset 0x8, size 0x4
        u32 ___dummy___; // offset 0xC, size 0x4
    } Head;              // offset 0x0, size 0x10
    PSPUMAP_PAGE Page[]; // offset 0x10, size 0x0
} PSPUMAP;

typedef struct {
    // total size: 0x88
    u32 BankAddr[SPUBANK_MAX]; // offset 0x0, size 0x40
    u32 BankSize[SPUBANK_MAX]; // offset 0x40, size 0x40
    u32 EEA_Addr[2];           // offset 0x80, size 0x8
} CURRMAP;

extern CURRMAP CurrMap;  // size: 0x88, address: 0x6EA200
extern PSPUMAP *pSpuMap; // size: 0x4, address: 0x57B250
extern u32 SpuTopAddr;   // size: 0x4, address: 0x57B248
extern u32 CurrPage;     // size: 0x4, address: 0x57B24C

s32 flSpuMapInit(PSPUMAP *pMap);
s32 flSpuMapChgPage(u32 page);
u32 flSpuMapGetBankAddr(u32 bank);

#endif
