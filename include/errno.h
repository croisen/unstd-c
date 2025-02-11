#ifndef _ERRNO_H
#define _ERRNO_H

#include <asm-generic/errno.h>

int *__errno_loc(void);
#define errno *__errno_loc()

#endif /* _ERRNO_H */
