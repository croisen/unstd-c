#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_symlinkat(const char *oldname, int newfd, const char *newname) {
    return __syscall(__sys_linux_symlinkat, oldname, newfd, newname);
}
