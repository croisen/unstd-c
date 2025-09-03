#include "integer.h"
#include "sys/linux/syscall.h"

usize strlen(const char *str)
{
    usize ret = 0;
    for (; *str; str++)
        ret++;

    return ret;
}

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++) {
        sys_linux_write(1, argv[i], strlen(argv[i]));
        sys_linux_write(1, "\n", 1);
    }

    return 0;
}
