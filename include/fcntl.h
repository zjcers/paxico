#ifndef _Z_FCNTL_H
#define _Z_FCNTL_H
#include <sys/types.h>
#include <bits/fcntl.h>
int open(const char* pathname, int flags, ...);
#define open(pathname, flags) open(pathname, flags, 00660)
#define creat(filename, mode) open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode)
int fcntl(int fd, int cmd, ...);
#endif
