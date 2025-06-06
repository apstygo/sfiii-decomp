#include "common.h"

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

#define BACKTRACE_MAX 100

void not_implemented(const s8 *func) __dead2 {
    fprintf(stderr, "Function not implemented: %s\n", func);

    void *buffer[BACKTRACE_MAX];
    int nptrs = backtrace(buffer, BACKTRACE_MAX);
    fprintf(stderr, "Stack trace:\n");
    backtrace_symbols_fd(buffer, nptrs, fileno(stderr));

    abort();
}
