/*
 * include/string.h
 * Copyright 2016 Zane J Cersovsky
 * This file is part of Project Paxico.

 * Project Paxico is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Project Paxico is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Project Paxico.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Declares string-handling
 */
#ifndef _PAXICO_STRING_H
#define _PAXICO_STRING_H
/*Set the branding macro*/
#ifndef _PAXICO_LIBC_
#define _PAXICO_LIBC_
#endif
#include <stdint.h>
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
