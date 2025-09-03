#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mlock(usize start, usize len) {
    return __syscall(__sys_linux_mlock, start, len);
}
