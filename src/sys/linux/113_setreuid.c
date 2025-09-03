#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_setreuid(uid_t ruid, uid_t euid) {
    return __syscall(__sys_linux_setreuid, ruid, euid);
}
