#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mlock2(usize start, usize len, int flags) {
    return __syscall(__sys_linux_mlock2, start, len, flags);
}
