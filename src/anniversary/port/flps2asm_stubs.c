#include "common.h"
#include "sf33rd/AcrSDK/ps2/flps2asm.h"

#include <string.h>

void flPS2_Mem_move(const void *src, void *dst, size_t len) {
    // len is in bytes
    memmove(dst, src, len);
}

void flPS2_Mem_move16(const void *src, void *dst, size_t len) {
    // len is the number of 16-bit values
    memmove(dst, src, len * 2);
}

void flPS2_Mem_move16_8A(const void *src, void *dst, size_t len) {
    // len is the number of 16-bit values
    memmove(dst, src, len * 2);
}

void flPS2_Mem_move16_16A(const void *src, void *dst, size_t len) {
    // The original stub used `len * 16`, but based on the naming convention (`move16`)
    // and consistency with other functions, `len` should be the number of 16-bit values.
    memmove(dst, src, len * 2);
}

void flPS2_Mem_move32(const void *src, void *dst, size_t len) {
    // len is the number of 32-bit values
    memmove(dst, src, len * 4);
}

void flPS2_Mem_move32_8A(const void *src, void *dst, size_t len) {
    // len is the number of 32-bit values
    memmove(dst, src, len * 4);
}

void flPS2_Mem_move32_16A(const void *src, void *dst, size_t len) {
    // len is the number of 32-bit values
    memmove(dst, src, len * 4);
}

void flPS2_Mem_move64(const void *src, void *dst, size_t len) {
    // len is the number of 64-bit values
    memmove(dst, src, len * 8);
}

void flPS2_Clear_Mem(void *str, size_t len) {
    // len is in bytes
    memset(str, 0, len);
}

void flPS2_Clear_Mem16_16A(void *str, size_t len) {
    // len is the number of 16-bit values
    memset(str, 0, len * 2);
}

void flPS2_Fill_Mem(void *str, s32 c, size_t len) {
    // len is in bytes
    memset(str, c, len);
}

void flPS2_Fill_Mem16_16A(void *str, s64 c, size_t len) {
    // The name `Mem16` suggests operating on 16-bit chunks.
    // The `s64 c` parameter is likely for ABI compatibility, so we cast it to u16.
    u16 *ptr = (u16 *)str;
    u16 pattern = (u16)c;
    for (size_t i = 0; i < len; i++) {
        ptr[i] = pattern;
    }
}