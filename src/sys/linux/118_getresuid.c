#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getresuid(uid_t *ruid, uid_t *euid, uid_t *suid) {
    return __syscall(__sys_linux_getresuid, ruid, euid, suid);
}
