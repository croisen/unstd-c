#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_uname(struct old_utsname *name) {
    return __syscall(__sys_linux_uname, name);
}
