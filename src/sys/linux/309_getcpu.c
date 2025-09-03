#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_getcpu(unsigned *cpup, unsigned *nodep, void* unused) {
    return __syscall(__sys_linux_getcpu, cpup, nodep, unused);
}
