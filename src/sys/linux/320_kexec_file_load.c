#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_kexec_file_load(int kernel_fd, int initrd_fd, usize cmdline_len, const char *cmdline_ptr, usize flags) {
    return __syscall(__sys_linux_kexec_file_load, kernel_fd, initrd_fd, cmdline_len, cmdline_ptr, flags);
}
