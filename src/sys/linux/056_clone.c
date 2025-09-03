#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_clone(usize clone_flags, usize newsp, void *parent_tid, void *child_tid, unsigned int tid) {
    return __syscall(__sys_linux_clone, clone_flags, newsp, parent_tid, child_tid, tid);
}
