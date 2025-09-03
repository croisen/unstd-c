#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getgroups(int gidsetsize, gid_t *grouplist) {
    return __syscall(__sys_linux_getgroups, gidsetsize, grouplist);
}
