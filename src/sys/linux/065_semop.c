#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_semop(int semid, struct sembuf *tsops, unsigned nsops) {
    return __syscall(__sys_linux_semop, semid, tsops, nsops);
}
