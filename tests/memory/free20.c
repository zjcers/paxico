/*
 * tests/memory/free20.c
 * Copyright 2016 Zane J Cersovsky
 * This program checks if free works correctly so we don't leak memory
 */
#include <stdlib.h>
#include "memory.h"
int main() {
	char *str;
	str = (char*)malloc(20);
	free(str);
	return !(_PAXICO_check_leaks());
}
