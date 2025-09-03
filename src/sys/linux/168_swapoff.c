#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_swapoff(const char *specialfile) {
    return __syscall(__sys_linux_swapoff, specialfile);
}
