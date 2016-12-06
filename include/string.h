#ifndef _Z_STRING_H
#define _Z_STRING_H
#include "stdint.h"
/*
 * String handling functions
 */
size_t strlen(const char* str);
size_t strcpy(const char* src, char* dest);
size_t strncpy(const char* src, char* dest, size_t n);
int strcmp(const char* src, const char* dest);
char *strchr(const char *str, int c);
/*
 * Memory handling functions
 */
void *memset (void* ptr, int value, size_t num);
void *memcpy(void *dest, const void *src, size_t n);
int memcmp(const void *str1, const void *str2, size_t n);
#endif
