#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

#include "_FILE.h"

FILE *fopen(const char *pathname, const char *mode)
{
    int fd = open(pathname, 0, O_RDONLY);
    if (fd < 0)
        return NULL;

    FILE *f = malloc(sizeof(*f));
    if (!f)
        return NULL;

    f->eof      = false;
    f->err      = false;
    f->fd       = fd;
    f->buf_used = 0;
    f->fpos     = 0;

    return f;
}
