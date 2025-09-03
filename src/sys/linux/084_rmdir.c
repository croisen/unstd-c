#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_rmdir(const char *pathname) {
    return __syscall(__sys_linux_rmdir, pathname);
}
