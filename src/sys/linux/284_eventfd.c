#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_eventfd(unsigned int count) {
    return __syscall(__sys_linux_eventfd, count);
}
