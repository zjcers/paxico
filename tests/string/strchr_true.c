/*
 * tests/string/strchr_true.c
 * Copyright 2016 Zane J Cersovsky
 * Tests to make sure strchr() returns true if the character is in the string
 */
#include <string.h>
#include <stdbool.h>
int main () {
	char *str1 = "Hello World!";
	return !(strchr(str1, '!') != NULL);
}
