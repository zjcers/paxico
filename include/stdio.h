#ifndef _Z_STDIO_H
#define _Z_STDIO_H
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#define EOF -1001
int puts(const char* str);
int putchar(int str);
#endif
