#include "../../misc/internal_syscall.h"
#include "syscall.h"
#include "unistd.h"

ssize_t write(int fd, const char *buf, size_t count)
{
    return _syscall(SYS_write, fd, buf, count);
}
