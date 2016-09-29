#ifndef _Z_SYSCALLS_H
#define _Z_SYSCALLS_H
#include "stdint.h"
int sys_write(int fileno, const char* str, size_t length);
int sys_read(int fileno, void* outbuf, size_t count);
int sys_open(const char* pathname, size_t flags);
int sys_close(int file);
void sys_exit(int status);
void* sys_sbrk(size_t size);
#endif
