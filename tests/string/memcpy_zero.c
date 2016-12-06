/*
 * tests/string/memcpy_zero.c
 * Copyright 2016 Zane J Cersovsky
 * Tests to make sure memcpy works when n = 0. Run this after memcmp() tests.
 */
#include <string.h>
int main () {
	char *str1 = "Hello World";
	char *str2 = "Hello Dave";
	char *str3 = "Hello World";
	return !memcmp(memcpy(str1, str2, 0), str3, 12);
}
