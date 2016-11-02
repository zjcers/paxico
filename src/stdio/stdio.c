#include "stdint.h"
#include "string.h"
#include "fcntl.h"
#include "syscalls.h"
#include "stdio.h"

void print(const char* str) {
  size_t length = strlen(str);
  sys_write(1, str, length);
}
void printc(char str) {
  sys_write(1, &str, 1);
}
