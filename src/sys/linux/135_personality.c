#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_personality(unsigned int personality) {
    return __syscall(__sys_linux_personality, personality);
}
