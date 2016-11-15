#include "stdint.h"
int sys_write(int fileno, const char* str, size_t length) {
  int ret = 0;
  asm volatile ("movl $4, %%eax;\n\t"
                "int $0x80;"
                : "=a" (ret)
                : "b" (fileno), "c" (str), "d" (length)
                : );
  return (ret);
}
int sys_read(int fileno, void* outbuf, size_t count) {
  int bytes = 0;
  asm volatile ("movl $3, %%eax;\n\t"
                "int $0x80;\n\t"
                : "=a" (bytes)
                : "b" (fileno), "c" (outbuf), "d" (count)
                :);
  return (bytes);
}
int sys_open(const char* pathname, size_t flags) {
  int file = 0;
  asm volatile ("movl $5, %%eax;\n\t"
                "movl $0, %%edx;\n\t"
                "int $0x80;"
                : "=a" (file)
                : "b" (pathname), "c" (flags)
                :"edx");
  return (file);
}
int sys_close(int file) {
  int ret = 0;
  asm volatile ("movl $6, %%eax;\n\t"
                "int $0x80;"
                : "=a" (ret)
                : "b" (file));
  return(ret);
}
void sys_exit(int status) {
  asm volatile ("movl $1, %%eax;\n\t"
                "int $0x80;"
                :
                : "b" (status)
                :);
}
void* sys_sbrk(ssize_t n) {
  void* reqBreak = 0;
  if (n != 0) {
    asm volatile ("movl $0x2d, %%eax;\n\t"
                  "int $0x80;"
                  : "=a" (reqBreak)
                  : "b" (0)
                  :
                );
    reqBreak += n;
  }
  void* curBreak;
  asm volatile ("movl $0x2d, %%eax;\n\t"
                "int $0x80;"
                : "=a" (curBreak)
                : "b" (reqBreak)
                :
              );
  return (curBreak);
}
