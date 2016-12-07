/*
 * tests/stdio/printf_bad_ps.c
 * Copyright 2016 Zane J Cersovsky
 * Tests to make sure printf() acts normally when given something nasty
 */
#include <stdio.h>
int main ()
{
	printf("%%%\n");
	return 0;
}
