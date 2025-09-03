#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_symlink(const char *oldname, const char *newname) {
    return __syscall(__sys_linux_symlink, oldname, newname);
}
