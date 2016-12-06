/*
 * tests/string/memcmp_true.c
 * Copyright 2016 Zane J Cersovsky
 * Tests to make sure memcmp() returns true given n = 5
 */
#include <string.h>
int main () {
	char *str1 = "Hello World";
	char *str2 = "Hello Dave";
	return !memcmp(str1, str2, 5);
}
