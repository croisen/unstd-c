#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_inotify_init1(int flags) {
    return __syscall(__sys_linux_inotify_init1, flags);
}
