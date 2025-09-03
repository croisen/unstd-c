#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_timer_gettime(timer_t timer_id, struct itimerspec *setting) {
    return __syscall(__sys_linux_timer_gettime, timer_id, setting);
}
