#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_lchown(const char *filename, uid_t user, gid_t group) {
    return __syscall(__sys_linux_lchown, filename, user, group);
}
