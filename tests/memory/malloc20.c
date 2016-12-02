/*
 * tests/memory/malloc20.c
 * Copyright 2016 Zane J Cersovsky
 * This program should segfault if malloc doesn't allocate enough memory
 */
#include <stdlib.h>
int main() {
	char *str;
	int i;
	str = (char*)malloc(20);
	for (i = 0; i < 20; i++) {
		str[i] = 's';
	}
	return 0;
}
