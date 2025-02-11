#include "../../misc/internal_syscall.h"
#include "syscall.h"
#include "unistd.h"

off_t lseek(int fd, off_t offset, unsigned int origin)
{
    return _syscall(SYS_lseek, fd, offset, origin);
}
