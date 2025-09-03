#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_memfd_create(const char *uname_ptr, unsigned int flags) {
    return __syscall(__sys_linux_memfd_create, uname_ptr, flags);
}
