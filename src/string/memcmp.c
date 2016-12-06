/*
 * src/string/memcmp.c
 * Copyright 2016 Zane J Cersovsky
 * Defines memcmp()
 */
#include <stdbool.h>
#include <string.h>
/*
 * Compares n bytes of str1 and str2, byte by byte
 */
int memcmp(const void *str1, const void *str2, size_t n)
{
	int i = 0;
	for (; i < n; i++) {
		if ((*(char*)str1++) != (*(char*)str2++))
			return false;
	}
	return true;
}
