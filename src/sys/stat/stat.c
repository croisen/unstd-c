#include "sys/stat.h"
#include "../../misc/internal_syscall.h"
#include "syscall.h"

int stat(const char *restrict file, struct stat *restrict buf)
{
    return _syscall(SYS_stat, file, buf);
}
