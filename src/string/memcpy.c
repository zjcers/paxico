/*
 * src/string/memcpy.c
 * Copyright 2016 Zane J Cersovsky
 * Defines memcpy()
 */
#include <string.h>
/*
 * Copies n bytes from src to dest
 */
void *memcpy(void *dest, const void *src, size_t n)
{
	void *orig_dest = dest;
	size_t i = 0;
	for (; i < n; i++) {
		*((char*)(dest++)) = *((char*)(src++));
	}
	return orig_dest;
}
