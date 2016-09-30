#include "stdlib.h"
#include "stdio.h"
#include "syscalls.h"
int main(int argc, char const *argv[]) {
  static char str[20];
  print("Calling itoa with (467): ");
  itoa(467, str, 10);
  print(str);
  print("\n");
  print("Calling uitoa with (467): ");
  memset(str, 0, 256);
  uitoa(-467, str, 10);
  print(str);
  print("\n");
  return 0;
}
