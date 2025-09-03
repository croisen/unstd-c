#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_remap_file_pages(usize start, usize size, usize prot, usize pgoff, usize flags) {
    return __syscall(__sys_linux_remap_file_pages, start, size, prot, pgoff, flags);
}
