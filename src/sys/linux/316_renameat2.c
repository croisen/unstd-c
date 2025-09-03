#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_renameat2(int olddfd, const char *oldname, int newdfd, const char *newname, unsigned int flags) {
    return __syscall(__sys_linux_renameat2, olddfd, oldname, newdfd, newname, flags);
}
