#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_move_pages(pid_t pid, usize nr_pages, const void **pages, const int *nodes, int *status, int flags) {
    return __syscall(__sys_linux_move_pages, pid, nr_pages, pages, nodes, status, flags);
}
