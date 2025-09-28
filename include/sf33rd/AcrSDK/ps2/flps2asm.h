#ifndef FLPS2ASM_H
#define FLPS2ASM_H

#include "types.h"

void flPS2_Mem_move(const void* src, void* dst, size_t len);
void flPS2_Mem_move16(const void* src, void* dst, size_t len);
void flPS2_Mem_move16_8A(const void* src, void* dst, size_t len);
void flPS2_Mem_move16_16A(const void* src, void* dst, size_t len);
void flPS2_Mem_move32(const void* src, void* dst, size_t len);
void flPS2_Mem_move32_8A(const void* src, void* dst, size_t len);
void flPS2_Mem_move32_16A(const void* src, void* dst, size_t len);
void flPS2_Mem_move64(const void* src, void* dst, size_t len);
void flPS2_Clear_Mem(void* str, size_t len);
void flPS2_Clear_Mem16_16A(void* str, size_t len);
void flPS2_Fill_Mem(void* str, s32 c, size_t len);
void flPS2_Fill_Mem16_16A(void* str, s64 c, size_t len);

#endif
