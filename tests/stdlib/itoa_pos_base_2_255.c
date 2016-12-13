/*
 * tests/stdlib/itoa_pos_base_2_255.c
 * Copyright 2016 Zane J Cersovsky
 * Tests itoa()
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main()
{
	char a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	char *correct = "11111111";
	itoa(255, a, 2);
	puts(a);
	putchar('\n');
	if (strcmp(a, correct))
		return EXIT_SUCCESS;
	return EXIT_FAILURE;
}
