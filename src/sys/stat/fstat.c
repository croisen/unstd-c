#include "../../misc/internal_syscall.h"
#include "sys/stat.h"
#include "syscall.h"

int fstat(int fd, struct stat *restrict buf)
{
    return _syscall(SYS_fstat, fd, buf);
}
