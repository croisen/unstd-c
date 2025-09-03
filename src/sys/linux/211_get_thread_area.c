#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_get_thread_area(void) {
    return __syscall(__sys_linux_get_thread_area);
}
