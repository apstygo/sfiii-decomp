#include "common.h"

#if !defined(_WIN32)
#include <execinfo.h>
#endif
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define BACKTRACE_MAX 100

void fatal_error(const s8 *fmt, ...) __dead2 {
    va_list args;
    va_start(args, fmt);

    fprintf(stderr, "Fatal error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");

    va_end(args);
#if !defined(_WIN32)
    void *buffer[BACKTRACE_MAX];
    int nptrs = backtrace(buffer, BACKTRACE_MAX);
    fprintf(stderr, "Stack trace:\n");
    backtrace_symbols_fd(buffer, nptrs, fileno(stderr));
#else
	fprintf(stderr, "Stack trace not available on Windows currently\n"); //TODO: fix!!!
#endif
    abort();
}

void not_implemented(const s8 *func) __dead2 {
    fatal_error("Function not implemented: %s\n", func);
}

void debug_print(const char *fmt, ...) {
#if defined(DEBUG)
    va_list args;
    va_start(args, fmt);
    vfprintf(stdout, fmt, args);
    fprintf(stdout, "\n");
    va_end(args);
#endif
}
