/*
 * tests/memory/malloc0.c
 * Copyright 2016 Zane J Cersovsky
 * This program checks if malloc of 0 returns NULL
 */
#include <stdlib.h>
int main() {
	char *str;
	str = (char*)malloc(0);
	if (str == NULL) {
		return 0;
	}
	return 1;
}
