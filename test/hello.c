#include "stdint.h"
#include "unistd.h"

int main(int argc, char **argv) {
  write(1, "Hello, World!\n", 14);
  return argc;
}
