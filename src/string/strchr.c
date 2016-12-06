/*
 * src/string/strchr.c
 * Copyright 2016 Zane J Cersovsky
 * Defines strchr()
 */
#include <string.h>
/*
 * Returns a pointer to the first occurence of c in str or NULL if not found.
 */
char *strchr(const char *str, int c)
{
	for (; *str; str++)
		if ((*str) == c)
			return (char*)(str);
	return NULL;
}
