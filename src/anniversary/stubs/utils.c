#include "common.h"

#include <stdio.h>
#include <stdlib.h>

void not_implemented(const s8 *func) __dead2 {
    fprintf(stderr, "Function not implemented: %s\n", func);
    abort();
}
