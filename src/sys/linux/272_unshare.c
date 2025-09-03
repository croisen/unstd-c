#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_unshare(usize unshare_flags) {
    return __syscall(__sys_linux_unshare, unshare_flags);
}
