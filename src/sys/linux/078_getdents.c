#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getdents(int fd, struct linux_dirent *dirent, unsigned int count) {
    return __syscall(__sys_linux_getdents, fd, dirent, count);
}
