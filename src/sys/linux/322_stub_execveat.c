#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_stub_execveat(int dfd, const char *filename, const char *const *argv, const char *const *envp, int flags) {
    return __syscall(__sys_linux_stub_execveat, dfd, filename, argv, envp, flags);
}
