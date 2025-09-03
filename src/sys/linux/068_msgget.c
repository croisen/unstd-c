#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_msgget(key_t key, int msgflg) {
    return __syscall(__sys_linux_msgget, key, msgflg);
}
