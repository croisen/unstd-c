#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_mincore(void *addr, usize len, unsigned char *vec) {
    return __syscall(__sys_linux_mincore, addr, len, vec);
}
