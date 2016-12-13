/*
 * tests/stdlib/itoa_neg_base_10_255.c
 * Copyright 2016 Zane J Cersovsky
 * Tests itoa()
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main()
{
	char a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char *correct = "-255";
	itoa(-255, a, 10);
	puts(a);
	putchar('\n');
	if (strcmp(a, correct))
		return EXIT_SUCCESS;
	return EXIT_FAILURE;
}
