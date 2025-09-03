#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_setdomainname(char *name, int len) {
    return __syscall(__sys_linux_setdomainname, name, len);
}
