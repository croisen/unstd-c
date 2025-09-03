#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_ptrace(long request, long pid, usize addr, usize data) {
    return __syscall(__sys_linux_ptrace, request, pid, addr, data);
}
