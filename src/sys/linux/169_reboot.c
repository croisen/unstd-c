#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_reboot(int magic1, int magic2, unsigned int cmd, void *arg) {
    return __syscall(__sys_linux_reboot, magic1, magic2, cmd, arg);
}
