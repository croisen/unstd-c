#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_inotify_rm_watch(int fd, __s32 wd) {
    return __syscall(__sys_linux_inotify_rm_watch, fd, wd);
}
