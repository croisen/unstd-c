#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_set_robust_list(struct robust_list_head *head, usize len) {
    return __syscall(__sys_linux_set_robust_list, head, len);
}
