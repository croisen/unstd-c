#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fanotify_mark(long fanotify_fd, long flags, __u64 mask, long dfd, long pathname) {
    return __syscall(__sys_linux_fanotify_mark, fanotify_fd, flags, mask, dfd, pathname);
}
