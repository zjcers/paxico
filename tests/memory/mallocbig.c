/*
 * tests/memory/mallocbig.c
 * Copyright 2016 Zane J Cersovsky
 * This program should segfault if malloc doesn't allocate enough memory
 */
#include <stdlib.h>
int main() {
	char *str;
	int i;
	str = (char*)malloc(40000);
	for (i = 0; i < 40000; i++) {
		str[i] = 's';
	}
	return 0;
}
