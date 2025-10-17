#ifndef _ERRNO_H
#define _ERRNO_H

#define errno (*__errno())
extern int *__errno (void);

#endif
