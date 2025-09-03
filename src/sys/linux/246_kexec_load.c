#include "integer.h"
#include "sys/linux/syscall.h"

isize sys_linux_kexec_load(usize entry, usize nr_segments, struct kexec_segment *segments, usize flags) {
    return __syscall(__sys_linux_kexec_load, entry, nr_segments, segments, flags);
}
