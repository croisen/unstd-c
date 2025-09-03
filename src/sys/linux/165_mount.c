#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mount(char *dev_name, char *dir_name, char *type, usize flags, void *data) {
    return __syscall(__sys_linux_mount, dev_name, dir_name, type, flags, data);
}
