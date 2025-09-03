#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_delete_module(const char *name_user, unsigned int flags) {
    return __syscall(__sys_linux_delete_module, name_user, flags);
}
