/*
 * tests/string/strchr_false.c
 * Copyright 2016 Zane J Cersovsky
 * Tests to make sure strchr() returns false if the character is not in the string
 */
#include <string.h>
#include <stdbool.h>
int main () {
	char *str1 = "Hello World";
	return !(strchr(str1, '!') == NULL);
}
