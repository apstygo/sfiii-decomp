#ifndef _STRING_H
#define _STRING_H

#include "types.h"

void *memset(void *s, int c, size_t n);
size_t strlen(const char *s);
char *strcpy(char *dest, const char *src);
char *strcat(char *dest, const char *src);
char *strupr(char *str);
char *strchr(const char *, int);

#endif
