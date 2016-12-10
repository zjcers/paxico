#ifndef _UNISTD_H
#define _UNISTD_H
#include <stdint.h>
#include <sys/types.h>
#define SEEK_SET	0
#define SEEK_CUR	1
#define SEEK_END	2
/*System calls are defined in plaform directories*/
ssize_t write(int fileno, const char* str, size_t length);
ssize_t read(int fileno, void* outbuf, size_t count);
int close(int fileno);
void _exit(int status);
int brk(void* addr);
void* sbrk(intptr_t incr);
off_t lseek(int fd, off_t offset, int whence);
#endif
