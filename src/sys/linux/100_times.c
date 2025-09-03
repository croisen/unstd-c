#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_times(struct tms *tbuf) {
    return __syscall(__sys_linux_times, tbuf);
}
