#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_get_robust_list(int pid, struct robust_list_head **head_ptr, usize *len_ptr) {
    return __syscall(__sys_linux_get_robust_list, pid, head_ptr, len_ptr);
}
