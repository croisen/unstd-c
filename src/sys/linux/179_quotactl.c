#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_quotactl(unsigned int cmd, const char *special, int id, void *addr) {
    return __syscall(__sys_linux_quotactl, cmd, special, id, addr);
}
