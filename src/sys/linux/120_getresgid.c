#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid) {
    return __syscall(__sys_linux_getresgid, rgid, egid, sgid);
}
