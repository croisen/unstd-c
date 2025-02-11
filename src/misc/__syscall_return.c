#include "errno.h"
#include "internal_syscall.h"

long __syscall_return(long ret)
{
    if (ret < 0) {
        errno = -ret;
        return -1;
    }

    return ret;
}
