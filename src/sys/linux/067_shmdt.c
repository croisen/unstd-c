#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_shmdt(char *shmaddr) {
    return __syscall(__sys_linux_shmdt, shmaddr);
}
