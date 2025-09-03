#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_semget(key_t key, int nsems, int semflg) {
    return __syscall(__sys_linux_semget, key, nsems, semflg);
}
