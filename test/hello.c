#include "stdlib.h"
#include "string.h"
#include "unistd.h"

int main(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
    {
        write(1, argv[i], strlen(argv[i]));
        write(1, "\n", 1);
    }

    char *a = malloc(9);
    char *c = malloc(99);
    char *b = malloc(8192);
    if (a != NULL) {
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
    } else {
        write(1, "Map failed...\n", 14);
    }

    if (b != NULL) {
        b[0] = 'H';
        b[1] = 'e';
        b[2] = 'l';
        b[3] = 'l';
        b[4] = 'o';
        b[5] = ' ';
        b[6] = '1';
        b[7] = '1';
        b[8] = '\n';
        b[9] = '0';
        write(1, b, 9);
    } else {
        write(1, "Map failed...\n", 14);
    }

    if (a != NULL)
        write(1, a, 8);

    write(1, "Hello, World!\n", 14);
    free(a);
    free(c);
    free(b);
    return 0;
}
