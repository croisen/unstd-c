#include "../../misc/internal_syscall.h"
#include "sys/stat.h"
#include "syscall.h"

int lstat(const char *restrict filename, struct stat *restrict buf)
{
    return _syscall(SYS_lstat, filename, buf);
}
