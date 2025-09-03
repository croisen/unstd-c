#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_setfsuid(uid_t uid) {
    return __syscall(__sys_linux_setfsuid, uid);
}
