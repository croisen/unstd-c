#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_readlink(const char *path, char *buf, int bufsiz) {
    return __syscall(__sys_linux_readlink, path, buf, bufsiz);
}
