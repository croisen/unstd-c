#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

// #include <asm-generic/fcntl.h>
//
// #include <asm-generic/hugetlb_encode.h>
//
// #include <asm-generic/ioctl.h>
// #include <asm-generic/ioctls.h>
//
// #include <asm-generic/param.h>
// #include <asm-generic/resource.h>
// #include <asm-generic/setup.h>
//
// #include <asm-generic/signal.h>
// #include <asm-generic/siginfo.h>
// #include <asm-generic/signal-defs.h>
//
// #include <asm-generic/socket.h>
// #include <asm-generic/sockios.h>
//
// #include <asm-generic/swab.h>

#include <asm-generic/bitsperlong.h>
#include <asm-generic/bpf_perf_event.h>
#include <asm-generic/ipcbuf.h>
#include <asm-generic/msgbuf.h>
#include <asm-generic/poll.h>
#include <asm-generic/posix_types.h>
#include <asm-generic/sembuf.h>
#include <asm-generic/shmbuf.h>
#include <asm-generic/stat.h>
#include <asm-generic/statfs.h>
#include <asm-generic/termbits-common.h>
#include <asm-generic/termbits.h>
#include <asm-generic/termios.h>
#include <asm-generic/types.h>

typedef __kernel_off_t off_t;
typedef __kernel_old_dev_t dev_t;
typedef __kernel_ino_t ino_t;
typedef unsigned long nlink_t;
typedef signed long blkcnt_t;
typedef signed long blksize_t;
typedef __kernel_mode_t mode_t;
typedef __kernel_pid_t pid_t;
typedef __kernel_uid_t uid_t;
typedef __kernel_gid_t gid_t;

#endif /* _SYS_TYPES_H */
