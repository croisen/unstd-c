#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fchown(int fd, uid_t user, gid_t group) {
    return __syscall(__sys_linux_fchown, fd, user, group);
}
