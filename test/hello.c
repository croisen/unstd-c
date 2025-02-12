#include "sys/mman.h"
#include "unistd.h"

int main(int argc, char **argv)
{
    char *a = mmap(
        NULL, 100, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0
    );
    if (a != MAP_FAILED) {
        a[0] = 'C';
        a[1] = 'r';
        a[2] = 'o';
        a[3] = 'i';
        a[4] = 's';
        a[5] = 'e';
        a[6] = 'n';
        a[7] = '\n';
        a[8] = '0';
        write(1, a, 8);
        munmap(a, 100);
    } else {
        write(1, "Map failed...\n", 14);
    }

    write(1, "Hello, World!\n", 14);
    return 0;
}
