#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getdents64(int fd, struct linux_dirent64 *dirent, unsigned int count) {
    return __syscall(__sys_linux_getdents64, fd, dirent, count);
}
