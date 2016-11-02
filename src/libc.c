#include "stdio.h"
#include "libc.h"
void __stack_chk_fail(void) {
  print("Stack overflow\n");
};
