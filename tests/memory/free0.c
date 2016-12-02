/*
 * tests/memory/free0.c
 * Copyright 2016 Zane J Cersovsky
 * Freeing a NULL pointer shouldn't segfault
 */
#include <stdlib.h>
int main() {
	free(NULL);
	return 0;
}
