#include "../../misc/internal_syscall.h"
#include "errno.h"
#include "sys/types.h"
#include "syscall.h"
#include "unistd.h"

void *brk_current = NULL;

void *sbrk(off_t increment)
{
    if (increment != 0) {
        errno = ENOMEM;
        return NULL;
    }

    brk_current = (void *)_syscall(SYS_brk, 0);
    return brk_current;
}
