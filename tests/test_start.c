#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main (unsigned int argc, const char** argv) {
  print("Got ");
  static char str[256];
  memset(str, 0, 256);
  print(itoa(argc, str, 10));
  print(" arguments\n");
  memset(str, 0, 256);
  print("Address of argv: ");
  print(itoa(argv, str, 10));
  print("\n");
  int i;
  for (i=0; i<argc; i++) {
    print("Arg [");
    memset(str, 0, 256);
    print(itoa(i, str, 10));
    print("]: ");
    memset(str, 0, 256);
    print(itoa(argv[i], str, 10));
    print("\n");
  }
  return 0;
}
