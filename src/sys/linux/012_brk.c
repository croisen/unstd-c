#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_brk(usize brk) {
    return __syscall(__sys_linux_brk, brk);
}
