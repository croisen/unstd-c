#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_timer_create(const clockid_t which_clock, struct sigevent *timer_event_spec, timer_t *created_timer_id) {
    return __syscall(__sys_linux_timer_create, which_clock, timer_event_spec, created_timer_id);
}
