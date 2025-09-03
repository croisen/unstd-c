#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_open_by_handle_at(int dfd, const char *name, struct file_handle *handle, int *mnt_id, int flags) {
    return __syscall(__sys_linux_open_by_handle_at, dfd, name, handle, mnt_id, flags);
}
