#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sysinfo(struct sysinfo *info) {
    return __syscall(__sys_linux_sysinfo, info);
}
