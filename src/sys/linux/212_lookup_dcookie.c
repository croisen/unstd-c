#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_lookup_dcookie(u64 cookie64, long buf, long len) {
    return __syscall(__sys_linux_lookup_dcookie, cookie64, buf, len);
}
