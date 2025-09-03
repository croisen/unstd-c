#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_linkat(int oldfd, const char *oldname, int newfd, const char *newname, int flags) {
    return __syscall(__sys_linux_linkat, oldfd, oldname, newfd, newname, flags);
}
