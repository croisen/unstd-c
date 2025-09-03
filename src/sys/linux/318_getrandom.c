#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getrandom(char *buf, usize count, unsigned int flags) {
    return __syscall(__sys_linux_getrandom, buf, count, flags);
}
