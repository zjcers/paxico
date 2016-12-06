/*
 * tests/string/memcmp_false.c
 * Copyright 2016 Zane J Cersovsky
 * Tests to make sure memcmp() returns false given n = 9
 */
#include <string.h>
#include <stdbool.h>
int main () {
	char *str1 = "Hello World";
	char *str2 = "Hello Dave";
	return !(memcmp(str1, str2, 9) == false);
}
