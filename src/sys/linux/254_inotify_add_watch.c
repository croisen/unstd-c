#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_inotify_add_watch(int fd, const char *pathname, u32 mask) {
    return __syscall(__sys_linux_inotify_add_watch, fd, pathname, mask);
}
