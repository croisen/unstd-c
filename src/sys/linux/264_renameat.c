#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_renameat(int oldfd, const char *oldname, int newfd, const char *newname) {
    return __syscall(__sys_linux_renameat, oldfd, oldname, newfd, newname);
}
