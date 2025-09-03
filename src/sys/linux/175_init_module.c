#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_init_module(void *umod, usize len, const char *uargs) {
    return __syscall(__sys_linux_init_module, umod, len, uargs);
}
