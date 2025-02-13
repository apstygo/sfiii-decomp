#ifndef COMMON_H
#define COMMON_H

#include "types.h"

#define NULL 0

// Compilation with GNU C Compilier means we are compiling CRI
#if defined(__GNUC__) && !defined(M2CTX)
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

#endif
