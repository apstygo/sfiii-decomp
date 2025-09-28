#ifndef _MEMORY_H
#define _MEMORY_H

// #ifndef _TYPES_H
// #include <sys/types.h>
// #endif

#include "types.h"

extern void* memchr(const void* p, int c, size_t n);
extern int memcmp(const void* s1, const void* s2, size_t n);
extern void* memcpy(void* dest, const void* src, size_t n);
extern void* memmove(void* dest, const void* src, size_t n);
extern void* memset(void* s, int c, size_t n);

// extern int  bcmp(const void *s1, const void *s2, size_t n);
// extern void bcopy(const void *src, void *dest, size_t n);
// extern void bzero(void *s, size_t n);

/* IOP orignal functions -- word(32bit) operation */
// extern void  *wmemcopy(u_long *dst, const u_long *src, u_long bytes);
// extern void  *wmemset(u_long *dst, u_long c, u_long bytes);

#endif /* _MEMORY_H */
