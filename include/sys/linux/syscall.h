#ifndef INTERNAL_SYSCALL_H
#define INTERNAL_SYSCALL_H

#include "integer.h"
#include "sys/linux/types.h"

#define SC_CAT_(a, b)                          a##b
#define SC_CAT(a, b)                           SC_CAT_(a, b)
#define SC_NARGS_(a, b, c, d, e, f, g, n, ...) n
#define SC_NARGS(...)                          SC_NARGS_(__VA_ARGS__, 6, 5, 4, 3, 2, 1, 0)

#define __syscall0(no)                         _syscall0((usize)no)
#define __syscall1(no, a)                      _syscall1((usize)no, (usize)a)
#define __syscall2(no, a, b)                   _syscall2((usize)no, (usize)a, (usize)b)
#define __syscall3(no, a, b, c)                                                \
    _syscall3((usize)no, (usize)a, (usize)b, (usize)c)
#define __syscall4(no, a, b, c, d)                                             \
    _syscall4((usize)no, (usize)a, (usize)b, (usize)c, (usize)d)
#define __syscall5(no, a, b, c, d, e)                                          \
    _syscall5((usize)no, (usize)a, (usize)b, (usize)c, (usize)d, (usize)e)
#define __syscall6(no, a, b, c, d, e, f)                                       \
    _syscall6(                                                                 \
        (usize)no, (usize)a, (usize)b, (usize)c, (usize)d, (usize)e, (usize)f  \
    )

#define __syscall(...) SC_CAT(__syscall, SC_NARGS(__VA_ARGS__))(__VA_ARGS__)

long __syscall_return(long ret);

usize _syscall0(usize no);
usize _syscall1(usize no, usize a);
usize _syscall2(usize no, usize a, usize b);
usize _syscall3(usize no, usize a, usize b, usize c);
usize _syscall4(usize no, usize a, usize b, usize c, usize d);
usize _syscall5(usize no, usize a, usize b, usize c, usize d, usize e);
usize _syscall6(usize no, usize a, usize b, usize c, usize d, usize e, usize f);

#define __sys_linux_read                   0
#define __sys_linux_write                  1
#define __sys_linux_open                   2
#define __sys_linux_close                  3
#define __sys_linux_stat                   4
#define __sys_linux_fstat                  5
#define __sys_linux_lstat                  6
#define __sys_linux_poll                   7
#define __sys_linux_lseek                  8
#define __sys_linux_mmap                   9
#define __sys_linux_mprotect               10
#define __sys_linux_munmap                 11
#define __sys_linux_brk                    12
#define __sys_linux_rt_sigaction           13
#define __sys_linux_rt_sigprocmask         14
#define __sys_linux_rt_sigreturn           15
#define __sys_linux_ioctl                  16
#define __sys_linux_pread64                17
#define __sys_linux_pwrite64               18
#define __sys_linux_readv                  19
#define __sys_linux_writev                 20
#define __sys_linux_access                 21
#define __sys_linux_pipe                   22
#define __sys_linux_select                 23
#define __sys_linux_sched_yield            24
#define __sys_linux_mremap                 25
#define __sys_linux_msync                  26
#define __sys_linux_mincore                27
#define __sys_linux_madvise                28
#define __sys_linux_shmget                 29
#define __sys_linux_shmat                  30
#define __sys_linux_shmctl                 31
#define __sys_linux_dup                    32
#define __sys_linux_dup2                   33
#define __sys_linux_pause                  34
#define __sys_linux_nanosleep              35
#define __sys_linux_getitimer              36
#define __sys_linux_alarm                  37
#define __sys_linux_setitimer              38
#define __sys_linux_getpid                 39
#define __sys_linux_sendfile               40
#define __sys_linux_socket                 41
#define __sys_linux_connect                42
#define __sys_linux_accept                 43
#define __sys_linux_sendto                 44
#define __sys_linux_recvfrom               45
#define __sys_linux_sendmsg                46
#define __sys_linux_recvmsg                47
#define __sys_linux_shutdown               48
#define __sys_linux_bind                   49
#define __sys_linux_listen                 50
#define __sys_linux_getsockname            51
#define __sys_linux_getpeername            52
#define __sys_linux_socketpair             53
#define __sys_linux_setsockopt             54
#define __sys_linux_getsockopt             55
#define __sys_linux_clone                  56
#define __sys_linux_fork                   57
#define __sys_linux_vfork                  58
#define __sys_linux_execve                 59
#define __sys_linux_exit                   60
#define __sys_linux_wait4                  61
#define __sys_linux_kill                   62
#define __sys_linux_uname                  63
#define __sys_linux_semget                 64
#define __sys_linux_semop                  65
#define __sys_linux_semctl                 66
#define __sys_linux_shmdt                  67
#define __sys_linux_msgget                 68
#define __sys_linux_msgsnd                 69
#define __sys_linux_msgrcv                 70
#define __sys_linux_msgctl                 71
#define __sys_linux_fcntl                  72
#define __sys_linux_flock                  73
#define __sys_linux_fsync                  74
#define __sys_linux_fdatasync              75
#define __sys_linux_truncate               76
#define __sys_linux_ftruncate              77
#define __sys_linux_getdents               78
#define __sys_linux_getcwd                 79
#define __sys_linux_chdir                  80
#define __sys_linux_fchdir                 81
#define __sys_linux_rename                 82
#define __sys_linux_mkdir                  83
#define __sys_linux_rmdir                  84
#define __sys_linux_creat                  85
#define __sys_linux_link                   86
#define __sys_linux_unlink                 87
#define __sys_linux_symlink                88
#define __sys_linux_readlink               89
#define __sys_linux_chmod                  90
#define __sys_linux_fchmod                 91
#define __sys_linux_chown                  92
#define __sys_linux_fchown                 93
#define __sys_linux_lchown                 94
#define __sys_linux_umask                  95
#define __sys_linux_gettimeofday           96
#define __sys_linux_getrlimit              97
#define __sys_linux_getrusage              98
#define __sys_linux_sysinfo                99
#define __sys_linux_times                  100
#define __sys_linux_ptrace                 101
#define __sys_linux_getuid                 102
#define __sys_linux_syslog                 103
#define __sys_linux_getgid                 104
#define __sys_linux_setuid                 105
#define __sys_linux_setgid                 106
#define __sys_linux_geteuid                107
#define __sys_linux_getegid                108
#define __sys_linux_setpgid                109
#define __sys_linux_getppid                110
#define __sys_linux_getpgrp                111
#define __sys_linux_setsid                 112
#define __sys_linux_setreuid               113
#define __sys_linux_setregid               114
#define __sys_linux_getgroups              115
#define __sys_linux_setgroups              116
#define __sys_linux_setresuid              117
#define __sys_linux_getresuid              118
#define __sys_linux_setresgid              119
#define __sys_linux_getresgid              120
#define __sys_linux_getpgid                121
#define __sys_linux_setfsuid               122
#define __sys_linux_setfsgid               123
#define __sys_linux_getsid                 124
#define __sys_linux_capget                 125
#define __sys_linux_capset                 126
#define __sys_linux_rt_sigpending          127
#define __sys_linux_rt_sigtimedwait        128
#define __sys_linux_rt_sigqueueinfo        129
#define __sys_linux_rt_sigsuspend          130
#define __sys_linux_sigaltstack            131
#define __sys_linux_utime                  132
#define __sys_linux_mknod                  133
#define __sys_linux_uselib                 134
#define __sys_linux_personality            135
#define __sys_linux_ustat                  136
#define __sys_linux_statfs                 137
#define __sys_linux_fstatfs                138
#define __sys_linux_sysfs                  139
#define __sys_linux_getpriority            140
#define __sys_linux_setpriority            141
#define __sys_linux_sched_setparam         142
#define __sys_linux_sched_getparam         143
#define __sys_linux_sched_setscheduler     144
#define __sys_linux_sched_getscheduler     145
#define __sys_linux_sched_get_priority_max 146
#define __sys_linux_sched_get_priority_min 147
#define __sys_linux_sched_rr_get_interval  148
#define __sys_linux_mlock                  149
#define __sys_linux_munlock                150
#define __sys_linux_mlockall               151
#define __sys_linux_munlockall             152
#define __sys_linux_vhangup                153
#define __sys_linux_modify_ldt             154
#define __sys_linux_pivot_root             155
#define __sys_linux__sysctl                156
#define __sys_linux_prctl                  157
#define __sys_linux_arch_prctl             158
#define __sys_linux_adjtimex               159
#define __sys_linux_setrlimit              160
#define __sys_linux_chroot                 161
#define __sys_linux_sync                   162
#define __sys_linux_acct                   163
#define __sys_linux_settimeofday           164
#define __sys_linux_mount                  165
#define __sys_linux_umount2                166
#define __sys_linux_swapon                 167
#define __sys_linux_swapoff                168
#define __sys_linux_reboot                 169
#define __sys_linux_sethostname            170
#define __sys_linux_setdomainname          171
#define __sys_linux_iopl                   172
#define __sys_linux_ioperm                 173
#define __sys_linux_create_module          174
#define __sys_linux_init_module            175
#define __sys_linux_delete_module          176
#define __sys_linux_get_kernel_syms        177
#define __sys_linux_query_module           178
#define __sys_linux_quotactl               179
#define __sys_linux_nfsservctl             180
#define __sys_linux_getpmsg                181
#define __sys_linux_putpmsg                182
#define __sys_linux_afs_syscall            183
#define __sys_linux_tuxcall                184
#define __sys_linux_security               185
#define __sys_linux_gettid                 186
#define __sys_linux_readahead              187
#define __sys_linux_setxattr               188
#define __sys_linux_lsetxattr              189
#define __sys_linux_fsetxattr              190
#define __sys_linux_getxattr               191
#define __sys_linux_lgetxattr              192
#define __sys_linux_fgetxattr              193
#define __sys_linux_listxattr              194
#define __sys_linux_llistxattr             195
#define __sys_linux_flistxattr             196
#define __sys_linux_removexattr            197
#define __sys_linux_lremovexattr           198
#define __sys_linux_fremovexattr           199
#define __sys_linux_tkill                  200
#define __sys_linux_time                   201
#define __sys_linux_futex                  202
#define __sys_linux_sched_setaffinity      203
#define __sys_linux_sched_getaffinity      204
#define __sys_linux_set_thread_area        205
#define __sys_linux_io_setup               206
#define __sys_linux_io_destroy             207
#define __sys_linux_io_getevents           208
#define __sys_linux_io_submit              209
#define __sys_linux_io_cancel              210
#define __sys_linux_get_thread_area        211
#define __sys_linux_lookup_dcookie         212
#define __sys_linux_epoll_create           213
#define __sys_linux_epoll_ctl_old          214
#define __sys_linux_epoll_wait_old         215
#define __sys_linux_remap_file_pages       216
#define __sys_linux_getdents64             217
#define __sys_linux_set_tid_address        218
#define __sys_linux_restart_syscall        219
#define __sys_linux_semtimedop             220
#define __sys_linux_fadvise64              221
#define __sys_linux_timer_create           222
#define __sys_linux_timer_settime          223
#define __sys_linux_timer_gettime          224
#define __sys_linux_timer_getoverrun       225
#define __sys_linux_timer_delete           226
#define __sys_linux_clock_settime          227
#define __sys_linux_clock_gettime          228
#define __sys_linux_clock_getres           229
#define __sys_linux_clock_nanosleep        230
#define __sys_linux_exit_group             231
#define __sys_linux_epoll_wait             232
#define __sys_linux_epoll_ctl              233
#define __sys_linux_tgkill                 234
#define __sys_linux_utimes                 235
#define __sys_linux_vserver                236
#define __sys_linux_mbind                  237
#define __sys_linux_set_mempolicy          238
#define __sys_linux_get_mempolicy          239
#define __sys_linux_mq_open                240
#define __sys_linux_mq_unlink              241
#define __sys_linux_mq_timedsend           242
#define __sys_linux_mq_timedreceive        243
#define __sys_linux_mq_notify              244
#define __sys_linux_mq_getsetattr          245
#define __sys_linux_kexec_load             246
#define __sys_linux_waitid                 247
#define __sys_linux_add_key                248
#define __sys_linux_request_key            249
#define __sys_linux_keyctl                 250
#define __sys_linux_ioprio_set             251
#define __sys_linux_ioprio_get             252
#define __sys_linux_inotify_init           253
#define __sys_linux_inotify_add_watch      254
#define __sys_linux_inotify_rm_watch       255
#define __sys_linux_migrate_pages          256
#define __sys_linux_openat                 257
#define __sys_linux_mkdirat                258
#define __sys_linux_mknodat                259
#define __sys_linux_fchownat               260
#define __sys_linux_futimesat              261
#define __sys_linux_newfstatat             262
#define __sys_linux_unlinkat               263
#define __sys_linux_renameat               264
#define __sys_linux_linkat                 265
#define __sys_linux_symlinkat              266
#define __sys_linux_readlinkat             267
#define __sys_linux_fchmodat               268
#define __sys_linux_faccessat              269
#define __sys_linux_pselect6               270
#define __sys_linux_ppoll                  271
#define __sys_linux_unshare                272
#define __sys_linux_set_robust_list        273
#define __sys_linux_get_robust_list        274
#define __sys_linux_splice                 275
#define __sys_linux_tee                    276
#define __sys_linux_sync_file_range        277
#define __sys_linux_vmsplice               278
#define __sys_linux_move_pages             279
#define __sys_linux_utimensat              280
#define __sys_linux_epoll_pwait            281
#define __sys_linux_signalfd               282
#define __sys_linux_timerfd_create         283
#define __sys_linux_eventfd                284
#define __sys_linux_fallocate              285
#define __sys_linux_timerfd_settime        286
#define __sys_linux_timerfd_gettime        287
#define __sys_linux_accept4                288
#define __sys_linux_signalfd4              289
#define __sys_linux_eventfd2               290
#define __sys_linux_epoll_create1          291
#define __sys_linux_dup3                   292
#define __sys_linux_pipe2                  293
#define __sys_linux_inotify_init1          294
#define __sys_linux_preadv                 295
#define __sys_linux_pwritev                296
#define __sys_linux_rt_tgsigqueueinfo      297
#define __sys_linux_perf_event_open        298
#define __sys_linux_recvmmsg               299
#define __sys_linux_fanotify_init          300
#define __sys_linux_fanotify_mark          301
#define __sys_linux_prlimit64              302
#define __sys_linux_name_to_handle_at      303
#define __sys_linux_open_by_handle_at      304
#define __sys_linux_clock_adjtime          305
#define __sys_linux_syncfs                 306
#define __sys_linux_sendmmsg               307
#define __sys_linux_setns                  308
#define __sys_linux_getcpu                 309
#define __sys_linux_process_vm_readv       310
#define __sys_linux_process_vm_writev      311
#define __sys_linux_kcmp                   312
#define __sys_linux_finit_module           313
#define __sys_linux_sched_setattr          314
#define __sys_linux_sched_getattr          315
#define __sys_linux_renameat2              316
#define __sys_linux_seccomp                317
#define __sys_linux_getrandom              318
#define __sys_linux_memfd_create           319
#define __sys_linux_kexec_file_load        320
#define __sys_linux_bpf                    321
#define __sys_linux_stub_execveat          322
#define __sys_linux_userfaultfd            323
#define __sys_linux_membarrier             324
#define __sys_linux_mlock2                 325
#define __sys_linux_copy_file_range        326
#define __sys_linux_preadv2                327
#define __sys_linux_pwritev2               328
#define __sys_linux_pkey_mprotect          329
#define __sys_linux_pkey_alloc             330
#define __sys_linux_pkey_free              331
#define __sys_linux_statx                  332
#define __sys_linux_io_pgetevents          333
#define __sys_linux_rseq                   334
#define __sys_linux_pkey_mprotect2         335

isize sys_linux_read(int fd, char *buf, usize count);
isize sys_linux_write(int fd, const char *buf, usize count);
isize sys_linux_open(const char *filename, int flags, int mode);
isize sys_linux_close(int fd);
isize sys_linux_stat(const char *filename, struct stat *statbuf);
isize sys_linux_fstat(int fd, struct stat *statbuf);
isize sys_linux_lstat(const char *filename, struct stat *statbuf);
isize sys_linux_poll(
    struct pollfd *ufds, unsigned int nfds, long timeout_msecs
);
isize sys_linux_lseek(int fd, off_t offset, unsigned int origin);
isize sys_linux_mmap(
    void *addr, usize len, usize prot, usize flags, int fd, usize off
);
isize sys_linux_mprotect(void *addr, usize len, usize prot);
isize sys_linux_munmap(void *addr, usize len);
isize sys_linux_brk(usize brk);
isize sys_linux_rt_sigaction(
    int sig, const struct sigaction *act, struct sigaction *oact,
    usize sigsetsize
);
isize sys_linux_rt_sigprocmask(
    int how, sigset_t *nset, sigset_t *oset, usize sigsetsize
);

/// TODO: Check this out
isize sys_linux_rt_sigreturn(usize __unused);

isize sys_linux_ioctl(int fd, unsigned int cmd, usize arg);
isize sys_linux_pread64(int fd, char *buf, usize count, loff_t pos);
isize sys_linux_pwrite64(int fd, const char *buf, usize count, loff_t pos);
isize sys_linux_readv(int fd, const struct iovec *vec, usize vlen);
isize sys_linux_writev(int fd, const struct iovec *vec, usize vlen);
isize sys_linux_access(const char *filename, int mode);
isize sys_linux_pipe(int *filedes);
isize sys_linux_select(
    int n, fd_set *inp, fd_set *outp, fd_set *exp, struct timeval *tvp
);
isize sys_linux_sched_yield(void);
isize sys_linux_mremap(
    void *addr, usize old_len, usize new_len, usize flags, void *new_addr
);
isize sys_linux_msync(void *addr, usize len, int flags);
isize sys_linux_mincore(void *addr, usize len, unsigned char *vec);
isize sys_linux_madvise(void *addr, usize size, int advice);
isize sys_linux_shmget(key_t key, usize size, int shmflg);
isize sys_linux_shmat(int shmid, char *shmaddr, int shmflg);
isize sys_linux_shmctl(int shmid, int cmd, struct shmid_ds *buf);
isize sys_linux_dup(unsigned int fildes);
isize sys_linux_dup2(unsigned int oldfd, unsigned int newfd);
isize sys_linux_pause(void);
isize sys_linux_nanosleep(struct timespec *rqtp, struct timespec *rmtp);
isize sys_linux_getitimer(int which, struct itimerval *value);
isize sys_linux_alarm(unsigned int seconds);
isize sys_linux_setitimer(
    int which, struct itimerval *value, struct itimerval *ovalue
);
isize sys_linux_getpid(void);
isize sys_linux_sendfile(int out_fd, int in_fd, off_t *offset, usize count);
isize sys_linux_socket(int family, int type, int protocol);

/// TODO: SUS struct def
isize sys_linux_connect(int fd, struct sockaddr *uservaddr, int addrlen);
isize sys_linux_accept(
    int fd, struct sockaddr *upeer_sockaddr, int *upeer_addrlen
);
isize sys_linux_sendto(
    int fd, void *buff, usize len, unsigned flags, struct sockaddr *addr,
    int addr_len
);
isize sys_linux_recvfrom(
    int fd, void *ubuf, usize size, unsigned flags, struct sockaddr *addr,
    int *addr_len
);
isize sys_linux_sendmsg(int fd, struct msghdr *msg, unsigned flags);
isize sys_linux_recvmsg(int fd, struct msghdr *msg, unsigned int flags);
isize sys_linux_shutdown(int fd, int how);
isize sys_linux_bind(int fd, struct sockaddr *umyaddr, int addrlen);
isize sys_linux_listen(int fd, int backlog);
isize sys_linux_getsockname(
    int fd, struct sockaddr *usockaddr, int *usockaddr_len
);
isize sys_linux_getpeername(
    int fd, struct sockaddr *usockaddr, int *usockaddr_len
);

isize sys_linux_socketpair(int family, int type, int protocol, int *usockvec);
isize sys_linux_setsockopt(
    int fd, int level, int optname, char *optval, int optlen
);
isize sys_linux_getsockopt(
    int fd, int level, int optname, char *optval, int *optlen
);
isize sys_linux_clone(
    usize clone_flags, usize newsp, void *parent_tid, void *child_tid,
    unsigned int tid
);
isize sys_linux_fork(void);
isize sys_linux_vfork(void);
isize sys_linux_execve(
    const char *filename, const char *const argv[], const char *const envp[]
);
isize sys_linux_exit(int error_code);
isize sys_linux_wait4(
    pid_t upid, int *stat_addr, int options, struct rusage *ru
);
isize sys_linux_kill(pid_t pid, int sig);
isize sys_linux_uname(struct old_utsname *name);
isize sys_linux_semget(key_t key, int nsems, int semflg);
isize sys_linux_semop(int semid, struct sembuf *tsops, unsigned nsops);

/// TODO: Possible bug when casting union into usize
isize sys_linux_semctl(int semid, int semnum, int cmd, union semun arg);

isize sys_linux_shmdt(char *shmaddr);
isize sys_linux_msgget(key_t key, int msgflg);
isize sys_linux_msgsnd(int msqid, struct msgbuf *msgp, usize msgsz, int msgflg);
isize sys_linux_msgrcv(
    int msqid, struct msgbuf *msgp, usize msgsz, long msgtyp, int msgflg
);
isize sys_linux_msgctl(int msqid, int cmd, struct msqid_ds *buf);
isize sys_linux_fcntl(int fd, unsigned int cmd, usize arg);
isize sys_linux_flock(int fd, unsigned int cmd);
isize sys_linux_fsync(int fd);
isize sys_linux_fdatasync(int fd);
isize sys_linux_truncate(const char *path, long length);
isize sys_linux_ftruncate(int fd, usize length);

/// TODO: SUS struct def
isize sys_linux_getdents(
    int fd, struct linux_dirent *dirent, unsigned int count
);

isize sys_linux_getcwd(char *buf, usize size);
isize sys_linux_chdir(const char *filename);
isize sys_linux_fchdir(int fd);
isize sys_linux_rename(const char *oldname, const char *newname);
isize sys_linux_mkdir(const char *pathname, int mode);
isize sys_linux_rmdir(const char *pathname);
isize sys_linux_creat(const char *pathname, int mode);
isize sys_linux_link(const char *oldname, const char *newname);
isize sys_linux_unlink(const char *pathname);
isize sys_linux_symlink(const char *oldname, const char *newname);
isize sys_linux_readlink(const char *path, char *buf, int bufsiz);
isize sys_linux_chmod(const char *filename, mode_t mode);
isize sys_linux_fchmod(int fd, mode_t mode);
isize sys_linux_chown(const char *filename, uid_t user, gid_t group);
isize sys_linux_fchown(int fd, uid_t user, gid_t group);
isize sys_linux_lchown(const char *filename, uid_t user, gid_t group);
isize sys_linux_umask(int mask);
isize sys_linux_gettimeofday(struct timeval *tv, struct timezone *tz);
isize sys_linux_getrlimit(unsigned int resource, struct rlimit *rlim);
isize sys_linux_getrusage(int who, struct rusage *ru);
isize sys_linux_sysinfo(struct sysinfo *info);
isize sys_linux_times(struct tms *tbuf);
isize sys_linux_ptrace(long request, long pid, usize addr, usize data);
isize sys_linux_getuid(void);
isize sys_linux_syslog(int type, char *buf, int len);
isize sys_linux_getgid(void);
isize sys_linux_setuid(uid_t uid);
isize sys_linux_setgid(gid_t gid);
isize sys_linux_geteuid(void);
isize sys_linux_getegid(void);
isize sys_linux_setpgid(pid_t pid, pid_t pgid);
isize sys_linux_getppid(void);
isize sys_linux_getpgrp(void);
isize sys_linux_setsid(void);
isize sys_linux_setreuid(uid_t ruid, uid_t euid);
isize sys_linux_setregid(gid_t rgid, gid_t egid);
isize sys_linux_getgroups(int gidsetsize, gid_t *grouplist);
isize sys_linux_setgroups(int gidsetsize, gid_t *grouplist);
isize sys_linux_setresuid(uid_t *ruid, uid_t *euid, uid_t *suid);
isize sys_linux_getresuid(uid_t *ruid, uid_t *euid, uid_t *suid);
isize sys_linux_setresgid(gid_t rgid, gid_t egid, gid_t sgid);
isize sys_linux_getresgid(gid_t *rgid, gid_t *egid, gid_t *sgid);
isize sys_linux_getpgid(pid_t pid);
isize sys_linux_setfsuid(uid_t uid);
isize sys_linux_setfsgid(gid_t gid);
isize sys_linux_getsid(pid_t pid);
isize sys_linux_capget(cap_user_header_t header, cap_user_data_t dataptr);
isize sys_linux_capset(cap_user_header_t header, const cap_user_data_t data);
isize sys_linux_rt_sigpending(sigset_t *set, usize sigsetsize);
isize sys_linux_rt_sigtimedwait(
    const sigset_t *uthese, siginfo_t *uinfo, const struct timespec *uts,
    usize sigsetsize
);
isize sys_linux_rt_sigqueueinfo(pid_t pid, int sig, siginfo_t *uinfo);
isize sys_linux_rt_sigsuspend(sigset_t *unewset, usize sigsetsize);
isize sys_linux_sigaltstack(const stack_t *uss, stack_t *uoss);
isize sys_linux_utime(char *filename, struct utimbuf *times);
isize sys_linux_mknod(const char *filename, mode_t mode, unsigned dev);
/// isize sys_linux_uselib(NOT IMPLEMENTED);
isize sys_linux_personality(unsigned int personality);

/// TODO: Deprecated?
/// isize sys_linux_ustat(unsigned dev, struct ustat *ubuf);

isize sys_linux_statfs(const char *pathname, struct statfs *buf);
isize sys_linux_fstatfs(int fd, struct statfs *buf);
isize sys_linux_sysfs(int option, usize arg1, usize arg2);
isize sys_linux_getpriority(int which, int who);
isize sys_linux_setpriority(int which, int who, int niceval);
isize sys_linux_sched_setparam(pid_t pid, struct sched_param *param);
isize sys_linux_sched_getparam(pid_t pid, struct sched_param *param);
isize sys_linux_sched_setscheduler(
    pid_t pid, int policy, struct sched_param *param
);
isize sys_linux_sched_getscheduler(pid_t pid);
isize sys_linux_sched_get_priority_max(int policy);
isize sys_linux_sched_get_priority_min(int policy);
isize sys_linux_sched_rr_get_interval(pid_t pid, struct timespec *interval);
isize sys_linux_mlock(usize start, usize len);
isize sys_linux_munlock(usize start, usize len);
isize sys_linux_mlockall(int flags);
isize sys_linux_munlockall(void);
isize sys_linux_vhangup(void);
isize sys_linux_modify_ldt(int func, void *ptr, usize bytecount);
isize sys_linux_pivot_root(const char *new_root, const char *put_old);
isize sys_linux__sysctl(struct __sysctl_args *args);
isize sys_linux_prctl(
    int option, usize arg2, usize arg3, usize arg4, usize arg5
);

/// TODO: Differing definition from syscall list?
/// isize sys_linux_arch_prctl(struct task_struct *task, int code, usize
/// *addr);
isize sys_linux_arch_prctl(int code, usize *addr);

isize sys_linux_adjtimex(struct timex *txc_p);
isize sys_linux_setrlimit(unsigned int resource, struct rlimit *rlim);
isize sys_linux_chroot(const char *filename);
isize sys_linux_sync(void);
isize sys_linux_acct(const char *name);
isize sys_linux_settimeofday(struct timeval *tv, struct timezone *tz);
isize sys_linux_mount(
    char *dev_name, char *dir_name, char *type, usize flags, void *data
);
isize sys_linux_umount2(const char *target, int flags);
isize sys_linux_swapon(const char *specialfile, int swap_flags);
isize sys_linux_swapoff(const char *specialfile);
isize sys_linux_reboot(int magic1, int magic2, unsigned int cmd, void *arg);
isize sys_linux_sethostname(char *name, int len);
isize sys_linux_setdomainname(char *name, int len);
isize sys_linux_iopl(unsigned int level, struct pt_regs *regs);
isize sys_linux_ioperm(usize from, usize num, int turn_on);

/// isize sys_linux_create_module(REMOVED IN Linux 2.6);

isize sys_linux_init_module(void *umod, usize len, const char *uargs);

/// TODO: Differing definition?
/// isize sys_linux_delete_module(const chat *name_user, unsigned int flags);
isize sys_linux_delete_module(const char *name_user, unsigned int flags);

/// isize sys_linux_get_kernel_syms(REMOVED IN Linux 2.6);
/// isize sys_linux_query_module(REMOVED IN Linux 2.6);

/// TODO: Differing definition?
/// isize sys_linux_quotactl(unsigned int cmd, const char *special, qid_t id,
/// void *addr);
isize sys_linux_quotactl(
    unsigned int cmd, const char *special, int id, void *addr
);

/// isize sys_linux_nfsservctl(NOT IMPLEMENTED);
/// isize sys_linux_getpmsg(NOT IMPLEMENTED);
/// isize sys_linux_putpmsg(NOT IMPLEMENTED);
/// isize sys_linux_afs_syscall(NOT IMPLEMENTED);
/// isize sys_linux_tuxcall(NOT IMPLEMENTED);
/// isize sys_linux_security(NOT IMPLEMENTED);

isize sys_linux_gettid(void);
isize sys_linux_readahead(int fd, loff_t offset, usize count);
isize sys_linux_setxattr(
    const char *pathname, const char *name, const void *value, usize size,
    int flags
);
isize sys_linux_lsetxattr(
    const char *pathname, const char *name, const void *value, usize size,
    int flags
);
isize sys_linux_fsetxattr(
    int fd, const char *name, const void *value, usize size, int flags
);
isize sys_linux_getxattr(
    const char *pathname, const char *name, void *value, usize size
);
isize sys_linux_lgetxattr(
    const char *pathname, const char *name, void *value, usize size
);
isize sys_linux_fgetxattr(int fd, const char *name, void *value, usize size);
isize sys_linux_listxattr(const char *pathname, char *list, usize size);
isize sys_linux_llistxattr(const char *pathname, char *list, usize size);
isize sys_linux_flistxattr(int fd, char *list, usize size);
isize sys_linux_removexattr(const char *pathname, const char *name);
isize sys_linux_lremovexattr(const char *pathname, const char *name);
isize sys_linux_fremovexattr(int fd, const char *name);
isize sys_linux_tkill(pid_t pid, int sig);
isize sys_linux_time(time_t *tloc);
isize sys_linux_futex(
    u32 *uaddr, int op, u32 val, struct timespec *utime, u32 *uaddr2, u32 val3
);
isize sys_linux_sched_setaffinity(
    pid_t pid, unsigned int len, usize *user_mask_ptr
);
isize sys_linux_sched_getaffinity(
    pid_t pid, unsigned int len, usize *user_mask_ptr
);

/// isize sys_linux_set_thread_area(NOT IMPLEMENTED.Use arch_prctl);

isize sys_linux_io_setup(unsigned nr_events, aio_context_t *ctxp);
isize sys_linux_io_destroy(aio_context_t ctx);
isize sys_linux_io_getevents(
    aio_context_t ctx_id, long min_nr, long nr, struct io_event *events
);
isize sys_linux_io_submit(aio_context_t ctx_id, long nr, struct iocb **iocbpp);
isize sys_linux_io_cancel(
    aio_context_t ctx_id, struct iocb *iocb, struct io_event *result
);

/// isize sys_linux_get_thread_area(NOT IMPLEMENTED.Use arch_prctl);

isize sys_linux_lookup_dcookie(u64 cookie64, long buf, long len);
isize sys_linux_epoll_create(int size);

/// isize sys_linux_epoll_ctl_old(NOT IMPLEMENTED);
/// isize sys_linux_epoll_wait_old(NOT IMPLEMENTED);

isize sys_linux_remap_file_pages(
    usize start, usize size, usize prot, usize pgoff, usize flags
);

/// TODO: Sus struct def
isize sys_linux_getdents64(
    int fd, struct linux_dirent64 *dirent, unsigned int count
);

isize sys_linux_set_tid_address(int *tidptr);
isize sys_linux_restart_syscall(void);
isize sys_linux_semtimedop(
    int semid, struct sembuf *tsops, unsigned nsops,
    const struct timespec *timeout
);
isize sys_linux_fadvise64(int fd, loff_t offset, usize len, int advice);
isize sys_linux_timer_create(
    const clockid_t which_clock, struct sigevent *timer_event_spec,
    timer_t *created_timer_id
);
isize sys_linux_timer_settime(
    timer_t timer_id, int flags, const struct itimerspec *new_setting,
    struct itimerspec *old_setting
);
isize sys_linux_timer_gettime(timer_t timer_id, struct itimerspec *setting);
isize sys_linux_timer_getoverrun(timer_t timer_id);
isize sys_linux_timer_delete(timer_t timer_id);
isize sys_linux_clock_settime(
    const clockid_t which_clock, const struct timespec *tp
);
isize sys_linux_clock_gettime(const clockid_t which_clock, struct timespec *tp);
isize sys_linux_clock_getres(const clockid_t which_clock, struct timespec *tp);
isize sys_linux_clock_nanosleep(
    const clockid_t which_clock, int flags, const struct timespec *rqtp,
    struct timespec *rmtp
);
isize sys_linux_exit_group(int error_code);
isize sys_linux_epoll_wait(
    int epfd, struct epoll_event *events, int maxevents, int timeout
);
isize sys_linux_epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
isize sys_linux_tgkill(pid_t tgid, pid_t pid, int sig);
isize sys_linux_utimes(char *filename, struct timeval *utimes);

/// isize sys_linux_vserver(NOT IMPLEMENTED);

isize sys_linux_mbind(
    usize start, usize len, usize mode, usize *nmask, usize maxnode,
    unsigned flags
);
isize sys_linux_set_mempolicy(int mode, usize *nmask, usize maxnode);
isize sys_linux_get_mempolicy(
    int *policy, usize *nmask, usize maxnode, usize addr, usize flags
);
isize sys_linux_mq_open(
    const char *u_name, int oflag, mode_t mode, struct mq_attr *u_attr
);
isize sys_linux_mq_unlink(const char *u_name);
isize sys_linux_mq_timedsend(
    mqd_t mqdes, const char *u_msg_ptr, usize msg_len, unsigned int msg_prio,
    const struct timespec *u_abs_timeout
);
isize sys_linux_mq_timedreceive(
    mqd_t mqdes, char *u_msg_ptr, usize msg_len, unsigned int *u_msg_prio,
    const struct timespec *u_abs_timeout
);
isize sys_linux_mq_notify(mqd_t mqdes, const struct sigevent *u_notification);
isize sys_linux_mq_getsetattr(
    mqd_t mqdes, const struct mq_attr *u_mqstat, struct mq_attr *u_omqstat
);
isize sys_linux_kexec_load(
    usize entry, usize nr_segments, struct kexec_segment *segments, usize flags
);
isize sys_linux_waitid(
    int which, pid_t upid, struct siginfo *infop, int options, struct rusage *ru
);
isize sys_linux_add_key(
    const char *_type, const char *_description, const void *_payload,
    usize plen
);
isize sys_linux_request_key(
    const char *_type, const char *_description, const char *_callout_info,
    key_serial_t destringid
);
isize sys_linux_keyctl(
    int option, usize arg2, usize arg3, usize arg4, usize arg5
);
isize sys_linux_ioprio_set(int which, int who, int ioprio);
isize sys_linux_ioprio_get(int which, int who);
isize sys_linux_inotify_init(void);
isize sys_linux_inotify_add_watch(int fd, const char *pathname, u32 mask);
isize sys_linux_inotify_rm_watch(int fd, __s32 wd);
isize sys_linux_migrate_pages(
    pid_t pid, usize maxnode, const usize *old_nodes, const usize *new_nodes
);
isize sys_linux_openat(int dfd, const char *filename, int flags, int mode);
isize sys_linux_mkdirat(int dfd, const char *pathname, int mode);
isize sys_linux_mknodat(int dfd, const char *filename, int mode, unsigned dev);
isize sys_linux_fchownat(
    int dfd, const char *filename, uid_t user, gid_t group, int flag
);
isize sys_linux_futimesat(
    int dfd, const char *filename, struct timeval *utimes
);
isize sys_linux_newfstatat(
    int dfd, const char *filename, struct stat *statbuf, int flag
);
isize sys_linux_unlinkat(int dfd, const char *pathname, int flag);
isize sys_linux_renameat(
    int oldfd, const char *oldname, int newfd, const char *newname
);
isize sys_linux_linkat(
    int oldfd, const char *oldname, int newfd, const char *newname, int flags
);
isize sys_linux_symlinkat(const char *oldname, int newfd, const char *newname);
isize sys_linux_readlinkat(
    int dfd, const char *pathname, char *buf, int bufsiz
);
isize sys_linux_fchmodat(int dfd, const char *filename, mode_t mode);
isize sys_linux_faccessat(int dfd, const char *filename, int mode);
isize sys_linux_pselect6(
    int n, fd_set *inp, fd_set *outp, fd_set *exp, struct timespec *tsp,
    void *sig
);
isize sys_linux_ppoll(
    struct pollfd *ufds, unsigned int nfds, struct timespec *tsp,
    const sigset_t *sigmask, usize sigsetsize
);
isize sys_linux_unshare(usize unshare_flags);
isize sys_linux_set_robust_list(struct robust_list_head *head, usize len);
isize sys_linux_get_robust_list(
    int pid, struct robust_list_head **head_ptr, usize *len_ptr
);
isize sys_linux_splice(
    int fd_in, loff_t *off_in, int fd_out, loff_t *off_out, usize len,
    unsigned int flags
);
isize sys_linux_tee(int fdin, int fdout, usize len, unsigned int flags);
isize sys_linux_sync_file_range(
    long fd, loff_t offset, loff_t bytes, long flags
);
isize sys_linux_vmsplice(
    int fd, const struct iovec *iov, usize nr_segs, unsigned int flags
);
isize sys_linux_move_pages(
    pid_t pid, usize nr_pages, const void **pages, const int *nodes,
    int *status, int flags
);
isize sys_linux_utimensat(
    int dfd, const char *filename, struct timespec *utimes, int flags
);
isize sys_linux_epoll_pwait(
    int epfd, struct epoll_event *events, int maxevents, int timeout,
    const sigset_t *sigmask, usize sigsetsize
);
isize sys_linux_signalfd(int ufd, sigset_t *user_mask, usize sizemask);
isize sys_linux_timerfd_create(int clockid, int flags);
isize sys_linux_eventfd(unsigned int count);
isize sys_linux_fallocate(long fd, long mode, loff_t offset, loff_t len);
isize sys_linux_timerfd_settime(
    int ufd, int flags, const struct itimerspec *utmr, struct itimerspec *otmr
);
isize sys_linux_timerfd_gettime(int ufd, struct itimerspec *otmr);
isize sys_linux_accept4(
    int fd, struct sockaddr *upeer_sockaddr, int *upeer_addrlen, int flags
);
isize sys_linux_signalfd4(
    int ufd, sigset_t *user_mask, usize sizemask, int flags
);
isize sys_linux_eventfd2(unsigned int count, int flags);
isize sys_linux_epoll_create1(int flags);
isize sys_linux_dup3(unsigned int oldfd, unsigned int newfd, int flags);
isize sys_linux_pipe2(int *filedes, int flags);
isize sys_linux_inotify_init1(int flags);
isize sys_linux_preadv(
    int fd, const struct iovec *vec, usize vlen, usize pos_l, usize pos_h
);
isize sys_linux_pwritev(
    int fd, const struct iovec *vec, usize vlen, usize pos_l, usize pos_h
);
isize sys_linux_rt_tgsigqueueinfo(
    pid_t tgid, pid_t pid, int sig, siginfo_t *uinfo
);
isize sys_linux_perf_event_open(
    struct perf_event_attr *attr_uptr, pid_t pid, int cpu, int group_fd,
    usize flags
);
isize sys_linux_recvmmsg(
    int fd, struct msghdr *mmsg, unsigned int vlen, unsigned int flags,
    struct timespec *timeout
);
isize sys_linux_fanotify_init(unsigned int flags, unsigned int event_f_flags);
isize sys_linux_fanotify_mark(
    long fanotify_fd, long flags, __u64 mask, long dfd, long pathname
);
isize sys_linux_prlimit64(
    pid_t pid, unsigned int resource, const struct rlimit64 *new_rlim,
    struct rlimit64 *old_rlim
);

/// TODO: Sus struct def
isize sys_linux_name_to_handle_at(
    int dfd, const char *name, struct file_handle *handle, int *mnt_id, int flag
);
isize sys_linux_open_by_handle_at(
    int dfd, const char *name, struct file_handle *handle, int *mnt_id,
    int flags
);
isize sys_linux_clock_adjtime(clockid_t which_clock, struct timex *tx);
isize sys_linux_syncfs(int fd);
isize sys_linux_sendmmsg(
    int fd, struct mmsghdr *mmsg, unsigned int vlen, unsigned int flags
);
isize sys_linux_setns(int fd, int nstype);

isize sys_linux_getcpu(unsigned *cpup, unsigned *nodep, void *unused_null);

isize sys_linux_process_vm_readv(
    pid_t pid, const struct iovec *lvec, usize liovcnt,
    const struct iovec *rvec, usize riovcnt, usize flags
);
isize sys_linux_process_vm_writev(
    pid_t pid, const struct iovec *lvec, usize liovcnt,
    const struct iovec *rvec, usize riovcnt, usize flags
);
isize sys_linux_kcmp(pid_t pid1, pid_t pid2, int type, usize idx1, usize idx2);
isize sys_linux_finit_module(int fd, const char *uargs, int flags);
isize sys_linux_sched_setattr(
    pid_t pid, struct sched_attr *attr, unsigned int flags
);
isize sys_linux_sched_getattr(
    pid_t pid, struct sched_attr *attr, unsigned int size, unsigned int flags
);
isize sys_linux_renameat2(
    int olddfd, const char *oldname, int newdfd, const char *newname,
    unsigned int flags
);
isize sys_linux_seccomp(unsigned int op, unsigned int flags, const char *uargs);
isize sys_linux_getrandom(char *buf, usize count, unsigned int flags);
isize sys_linux_memfd_create(const char *uname_ptr, unsigned int flags);
isize sys_linux_kexec_file_load(
    int kernel_fd, int initrd_fd, usize cmdline_len, const char *cmdline_ptr,
    usize flags
);
isize sys_linux_bpf(int cmd, union bpf_attr *attr, unsigned int size);
isize sys_linux_stub_execveat(
    int dfd, const char *filename, const char *const *argv,
    const char *const *envp, int flags
);
isize sys_linux_userfaultfd(int flags);
isize sys_linux_membarrier(int cmd, int flags);
isize sys_linux_mlock2(usize start, usize len, int flags);
isize sys_linux_copy_file_range(
    int fd_in, loff_t *off_in, int fd_out, loff_t *off_out, usize len,
    unsigned int flags
);
isize sys_linux_preadv2(
    int fd, const struct iovec *vec, usize vlen, usize pos_l, usize pos_h,
    int flags
);
isize sys_linux_pwritev2(
    int fd, const struct iovec *vec, usize vlen, usize pos_l, usize pos_h,
    int flags
);
isize sys_linux_pkey_mprotect(void);
isize sys_linux_pkey_alloc(void);
isize sys_linux_pkey_free(void);
isize sys_linux_statx(void);
isize sys_linux_io_pgetevents(void);
isize sys_linux_rseq(void);
isize sys_linux_pkey_mprotect2(void);

#endif /* INTERNAL_SYSCALL_H */
