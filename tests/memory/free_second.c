/*
 * tests/memory/free_second.c
 * Copyright 2016 Zane J Cersovsky
 * Freeing a second element should work
 */
#include <stdlib.h>
int main()
{
	void* one = malloc(20);
	void* two = malloc(20);
	free(two);
	free(one);
	return 0;
}
