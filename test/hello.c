#include "errno.h"
#include "unistd.h"

int main(int argc, char **argv) {
  syscall(1, 1, "Hello, World!\n", 14);
  return errno;
}
