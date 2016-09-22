#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main (int argc, char const *argv[]) {
  print("Got ");
  char* str = (char*)malloc(256);
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
    printc(*argv[i]);
    print("\n");
  }
  free(str);
  return 0;
}
