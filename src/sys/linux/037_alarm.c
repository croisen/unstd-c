#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_alarm(unsigned int seconds) {
    return __syscall(__sys_linux_alarm, seconds);
}
