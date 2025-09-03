#ifndef SYS_LINUX_TYPES_H
#define SYS_LINUX_TYPES_H

#include "integer.h"

#include <asm/prctl.h>
#include <asm/socket.h>
#include <asm/stat.h>
#include <asm/statfs.h>
#include <linux/aio_abi.h>
#include <linux/bpf.h>
#include <linux/capability.h>
#include <linux/eventpoll.h>
#include <linux/fanotify.h>
#include <linux/futex.h>
#include <linux/in.h>
#include <linux/in6.h>
#include <linux/kexec.h>
#include <linux/mqueue.h>
#include <linux/msg.h>
#include <linux/perf_event.h>
#include <linux/poll.h>
#include <linux/posix_types.h>
#include <linux/ptrace.h>
#include <linux/resource.h>
#include <linux/sched.h>
#include <linux/sched/types.h>
#include <linux/sem.h>
#include <linux/shm.h>
#include <linux/signal.h>
#include <linux/socket.h>
#include <linux/stat.h>
#include <linux/sysctl.h>
#include <linux/sysinfo.h>
#include <linux/time.h>
#include <linux/time_types.h>
#include <linux/times.h>
#include <linux/timex.h>
#include <linux/types.h>
#include <linux/un.h>
#include <linux/utime.h>
#include <linux/utsname.h>

typedef __kernel_clockid_t clockid_t;
typedef __kernel_fd_set fd_set;
typedef struct iovec iovec;
typedef i32 key_t;
typedef i32 key_serial_t;
typedef usize loff_t;
typedef isize off_t;
typedef isize ino_t;
typedef usize mode_t;
typedef __kernel_sa_family_t sa_family_t;
typedef __kernel_mqd_t mqd_t;
typedef __kernel_old_time_t time_t;
typedef __kernel_timer_t timer_t;

/// TODO: Sus
struct linux_dirent {
    unsigned long d_ino;     /* Inode number */
    unsigned long d_off;     /* Not an offset; see below */
    unsigned short d_reclen; /* Length of this linux_dirent */
    char d_name[];           /* Filename (null-terminated) */
                             /* length is actually (d_reclen - 2 -
                                offsetof(struct linux_dirent, d_name)) */
    /*
    char           pad;       // Zero padding byte
    char           d_type;    // File type (only since Linux
                              // 2.6.4); offset is (d_reclen - 1)
    */
};

/// TODO: Sus
struct linux_dirent64 {
    ino_t d_ino;             /* 64-bit inode number */
    off_t d_off;             /* Not an offset; see getdents() */
    unsigned short d_reclen; /* Size of this dirent */
    unsigned char d_type;    /* File type */
    char d_name[];           /* Filename (null-terminated) */
};

/// TODO: Sus
struct file_handle {
    unsigned int handle_bytes; /* Size of f_handle [in, out] */
    int handle_type;           /* Handle type [out] */
    unsigned char f_handle[0]; /* File identifier (sized by
                                  caller) [out] */
};

/* TODO: Deprecated?
 * struct ustat {
 *     daddr_t f_tfree;
 *     ino_t   f_tinode;
 *     char    f_fname[6];
 *     char    f_fpack[6];
 * };
 */

/// TODO: Sus
struct sched_param {
    int sched_priority;
};

/// TODO: Sus
struct msghdr {
    void *msg_name;        /* Address to send to/receive from.  */
    socklen_t msg_namelen; /* Length of address data.  */

    struct iovec *msg_iov; /* Vector of data to send/receive into.  */
    size_t msg_iovlen;     /* Number of elements in the vector.  */

    void *msg_control;     /* Ancillary data (eg BSD filedesc passing). */
    size_t msg_controllen; /* Ancillary data buffer length.
                              !! The type should be socklen_t but the
                              definition of the kernel is incompatible
                              with this.  */

    int msg_flags; /* Flags on received message.  */
};

/// TODO: Sus
struct mmsghdr {
    struct msghdr msg_hdr; /* Actual message header.  */
    unsigned int msg_len;  /* Number of received or sent bytes for the
                              entry.  */
};

/// TODO: Sus
struct sockaddr {
    sa_family_t sa_family; /* Address family */
    char sa_data[];        /* Socket address */
};

#endif /* SYS_LINUX_TYPES_H */
