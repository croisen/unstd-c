#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_readlinkat(int dfd, const char *pathname, char *buf, int bufsiz) {
    return __syscall(__sys_linux_readlinkat, dfd, pathname, buf, bufsiz);
}
