#include "stdint.h"
#include "stdbool.h"
#include "string.h"
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
