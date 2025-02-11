#include "../misc/internal_syscall.h"
#include "syscall.h"
#include "unistd.h"

void _exit(int status)
{
    _syscall(SYS_exit, status);
    __builtin_unreachable();
}
