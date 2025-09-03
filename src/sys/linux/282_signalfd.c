#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_signalfd(int ufd, sigset_t *user_mask, usize sizemask) {
    return __syscall(__sys_linux_signalfd, ufd, user_mask, sizemask);
}
