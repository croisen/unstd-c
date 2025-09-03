#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_shmget(key_t key, usize size, int shmflg) {
    return __syscall(__sys_linux_shmget, key, size, shmflg);
}
