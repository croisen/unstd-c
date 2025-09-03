#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_io_pgetevents(void) {
    return __syscall(__sys_linux_io_pgetevents);
}
