#ifndef FLPS2ASM_H
#define FLPS2ASM_H

#include "types.h"

void memcpy_1w(const void *src, void *dst, u32 len);
void memcpy_4w(const void *src, void *dst, u32 len);
void memcpy_2d(const void *src, void *dst, u32 len);
void memcpy_1q(const void *src, void *dst, u32 len);
void memcpy_8w(const void *src, void *dst, u32 len);
void memcpy_4d(const void *src, void *dst, u32 len);
void memcpy_2q(const void *src, void *dst, u32 len);
void memcpy_4q(const void *src, void *dst, u32 len);
void memzero_1w(void *str, u32 len);
void memzero_1q(void *str, u32 len);
void memset_1w(void *str, s32 c, u32 len);
void memset_1q(void *str, s64 c, u32 len);

#endif
