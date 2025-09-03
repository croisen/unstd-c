#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_pkey_alloc(void) {
    return __syscall(__sys_linux_pkey_alloc);
}
