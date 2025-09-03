#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_sethostname(char *name, int len) {
    return __syscall(__sys_linux_sethostname, name, len);
}
