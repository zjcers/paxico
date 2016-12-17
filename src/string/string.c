/*
 * src/string/string.c
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
 * Defines strlen(), strcpy(), strncpy(), strcmp(), memset()
 */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
size_t strlen(const char* str) {
  const char* s;
  for(s = str; *s; ++s) {}
  return (s-str);
}
size_t strcpy(const char* src, char* dest) {
  size_t count = 0;
  while (*src) {
    *(dest++) = *(src++);
    count++;
  }
  return(count);
}
size_t strncpy(const char* src, char* dest, size_t n) {
  size_t count = 0;
  while (*src && count < n) {
    *(dest) = *(src++);
    count++;
  }
  return(count);
}
int strcmp(const char* src, const char* dest) {
  while (*src) {
    if (*(dest++) != *(src++)) {
      return (false);
    }
  }
	if (*dest == NULL) {
  	return (true);
	}
	return (false);
}
void* memset (void* ptr, int value, size_t num) {
  size_t i;
  for (i=0; i<num; i++) {
    ((char*)ptr)[i] = (unsigned char)value;
  }
  return ptr;
}
