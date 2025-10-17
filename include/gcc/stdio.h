#ifndef _STDIO_H
#define _STDIO_H

#include "reent.h"

typedef struct __sFILE FILE;

#ifndef NULL
#define	NULL	0L
#endif

#define	EOF	(-1)

#define	stdin	(_impure_ptr->_stdin)
#define	stdout	(_impure_ptr->_stdout)
#define	stderr	(_impure_ptr->_stderr)

#define _stdin_r(x)	((x)->_stdin)
#define _stdout_r(x)	((x)->_stdout)
#define _stderr_r(x)	((x)->_stderr)

extern int printf(const char* format, ...);
extern int vsprintf(char* buf, const char* fmt, ...);

#endif
