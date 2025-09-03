#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_timer_getoverrun(timer_t timer_id) {
    return __syscall(__sys_linux_timer_getoverrun, timer_id);
}
