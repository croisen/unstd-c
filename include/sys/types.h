#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

typedef long off_t;
typedef long dev_t;
typedef long ino_t;
typedef unsigned int mode_t;
typedef long uid_t;
typedef long gid_t;
typedef long nlink_t;
typedef long blksize_t;
typedef long blkcnt_t;

struct pollfd {
    int fd;
    short events;
    short revents;
};

struct stat {
    dev_t st_dev;         /* ID of device containing file */
    ino_t st_ino;         /* Inode number */
    mode_t st_mode;       /* File type and mode */
    nlink_t st_nlink;     /* Number of hard links */
    uid_t st_uid;         /* User ID of owner */
    gid_t st_gid;         /* Group ID of owner */
    dev_t st_rdev;        /* Device ID (if special file) */
    off_t st_size;        /* Total size, in bytes */
    blksize_t st_blksize; /* Block size for filesystem I/O */
    blkcnt_t st_blocks;   /* Number of 512 B blocks allocated */
};

#endif /* _SYS_TYPES_H */
