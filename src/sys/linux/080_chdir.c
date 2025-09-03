#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_chdir(const char *filename) {
    return __syscall(__sys_linux_chdir, filename);
}
