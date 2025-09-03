#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mlockall(int flags) {
    return __syscall(__sys_linux_mlockall, flags);
}
