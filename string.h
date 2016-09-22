#ifndef _Z_STRING_H
#define _Z_STRING_H
#include "stdint.h"
size_t strlen(const char* str);
size_t strcpy(const char* src, char* dest);
void* memset (void* ptr, int value, size_t num);
size_t strncpy(const char* src, char* dest, size_t n);
int strcmp(const char* src, const char* dest);
#endif
