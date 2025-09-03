#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_setregid(gid_t rgid, gid_t egid) {
    return __syscall(__sys_linux_setregid, rgid, egid);
}
