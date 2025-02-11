int errno = 0;

int *__errno_loc(void)
{
    return &errno;
}
