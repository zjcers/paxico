/*
 * tests/string/memcpy_ten.c
 * Copyright 2016 Zane J Cersovsky
 * Tests to make sure memcpy works when n = 10. Run this after memcmp() tests.
 */
#include <string.h>
#include <stdbool.h>
int main () {
	char *str1 = "Hello World";
	char *str3 = "Hello World";
	char str4[10];
	return memcmp(memcpy(str4, str1, 10), str3, 10) != true;
}
