#ifndef COMMON_H
#define COMMON_H

#include "types.h"

#define NULL 0
#define REINTERPRET_AS_U32(_num) (*(u32 *)&(_num))

// Compilation with GNU C Compilier means we are compiling CRI
#if defined(__GNUC__) && !defined(M2CTX) && !defined(TARGET_SDL2)
#define INCLUDE_ASM(FOLDER, NAME)                                                                                      \
    __asm__("\t.text\n"                                                                                                \
            "\t.align\t3\n"                                                                                            \
            "\t.globl\t" #NAME "\n"                                                                                    \
            "\t.ent\t" #NAME "\n" #NAME ":\n"                                                                          \
            ".include \"" FOLDER "/" #NAME ".s\"\n"                                                                    \
            "\t.set reorder\n"                                                                                         \
            "\t.set at\n"                                                                                              \
            "\t.end\t" #NAME "\n")

#define INCLUDE_RODATA(FOLDER, NAME) __asm__("    .include \"" FOLDER "/" #NAME ".s\"\n")

__asm__(".include \"include/cri_macro.inc\"\n");
#else
#define INCLUDE_ASM(FOLDER, NAME)
#define INCLUDE_RODATA(FOLDER, NAME)
#endif

#if defined(M2CTX)

#define ATTR_ALIGNED(value)

#else

#define ATTR_ALIGNED(value) __attribute__((aligned(value)))

#endif

#if !defined(TARGET_PS2)

#include <stdio.h>
#include <stdlib.h>

void not_implemented(const s8* func) __dead2 {
    fprintf(stderr, "Function not implemented: %s\n", func);
    abort();
}

#endif

#define LO_16_BITS(val) (val & 0xFFFF)
#define HI_16_BITS(val) ((val & 0xFFFF0000) >> 16)

#endif
