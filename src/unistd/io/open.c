#include "../../misc/internal_syscall.h"
#include "syscall.h"
#include "unistd.h"

int open(const char *filename, int flags, int mode)
{
    return _syscall(SYS_open, filename, flags, mode);
}
