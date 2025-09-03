#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_bpf(int cmd, union bpf_attr *attr, unsigned int size) {
    return __syscall(__sys_linux_bpf, cmd, attr, size);
}
