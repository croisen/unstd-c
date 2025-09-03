#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_swapon(const char *specialfile, int swap_flags) {
    return __syscall(__sys_linux_swapon, specialfile, swap_flags);
}
