#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_fchownat(int dfd, const char *filename, uid_t user, gid_t group, int flag) {
    return __syscall(__sys_linux_fchownat, dfd, filename, user, group, flag);
}
