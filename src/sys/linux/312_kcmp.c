#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_kcmp(pid_t pid1, pid_t pid2, int type, usize idx1, usize idx2) {
    return __syscall(__sys_linux_kcmp, pid1, pid2, type, idx1, idx2);
}
