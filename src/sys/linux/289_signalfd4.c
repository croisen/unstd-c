#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_signalfd4(int ufd, sigset_t *user_mask, usize sizemask, int flags) {
    return __syscall(__sys_linux_signalfd4, ufd, user_mask, sizemask, flags);
}
