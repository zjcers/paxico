/*
 * tests/stdlib/itoa_base_10_0.c
 * Copyright 2016 Zane J Cersovsky
 * Tests itoa() at 0
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main()
{
	char a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char *correct = "0";
	itoa(0, a, 10);
	puts(a);
	putchar('\n');
	if (strcmp(a, correct))
		return EXIT_SUCCESS;
	return EXIT_FAILURE;
}
