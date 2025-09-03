#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_migrate_pages(pid_t pid, usize maxnode, const usize *old_nodes, const usize *new_nodes) {
    return __syscall(__sys_linux_migrate_pages, pid, maxnode, old_nodes, new_nodes);
}
