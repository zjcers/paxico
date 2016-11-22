#ifndef _Z_STDLIB_H
#define _Z_STDLIB_H
#include <stdint.h>
#include <unistd.h>
int atoi(const char* src);
char* itoa(int value, char* str, size_t base);
char* uitoa(int value, char* str, size_t base);
void* malloc(size_t n);
int free(void* addr);
/*Dirty shim until
void exit(int status);
is implemented:*/
#define exit(status) _exit(status)
#endif
