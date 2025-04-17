#ifndef _FILE_H
#define _FILE_H

#include "stdbool.h"
#include "stddef.h"

struct _FILE
{
    bool eof;
    bool err;

    int fd;
    char buf[800];
    int  buf_used;

    size_t fpos;
};

#endif /* _FILE_H */
