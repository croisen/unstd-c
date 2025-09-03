#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_nanosleep(struct timespec *rqtp, struct timespec *rmtp) {
    return __syscall(__sys_linux_nanosleep, rqtp, rmtp);
}
