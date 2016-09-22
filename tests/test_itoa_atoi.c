#include "stdlib.h"
#include "stdio.h"
#include "syscalls.h"
int main(int argc, char const *argv[]) {
  char* str = (char*)malloc(20);
  print("Calling itoa with (467): ");
  itoa(467, str, 10);
  print(str);
  print("\n");
  free(str);
  return 0;
}
