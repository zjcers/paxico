/*
 * tests/memory/free_nonsense.c
 * Copyright 2016 Zane J Cersovsky
 * Freeing garbage shouldn't hang
 */
#include <stdlib.h>
int main()
{
	free((void*)0x10000);
	return 0;
}
