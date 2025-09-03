#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_timer_settime(timer_t timer_id, int flags, const struct itimerspec *new_setting, struct itimerspec *old_setting) {
    return __syscall(__sys_linux_timer_settime, timer_id, flags, new_setting, old_setting);
}
