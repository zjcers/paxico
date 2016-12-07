/*
 * tests/stdio/printf_plainformat.c
 * Copyright 2016 Zane J Cersovsky
 * Tests to make sure printf() acts normally when format doesn't contain special
 * characters.
 */
#include <stdio.h>
int main ()
{
	printf("Hello\n");
	return 0;
}
