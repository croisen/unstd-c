#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_eventfd2(unsigned int count, int flags) {
    return __syscall(__sys_linux_eventfd2, count, flags);
}
