#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_time(time_t *tloc) {
    return __syscall(__sys_linux_time, tloc);
}
