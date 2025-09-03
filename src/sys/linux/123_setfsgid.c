#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_setfsgid(gid_t gid) {
    return __syscall(__sys_linux_setfsgid, gid);
}
