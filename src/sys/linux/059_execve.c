#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_execve(
    const char *filename, const char *const argv[], const char *const envp[]
)
{
    return __syscall(__sys_linux_execve, filename, argv, envp);
}
