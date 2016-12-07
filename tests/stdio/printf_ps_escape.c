/*
 * tests/stdio/printf_format.c
 * Copyright 2016 Zane J Cersovsky
 * Tests to make sure printf() acts normally when format contains escaped %
 */
#include <stdio.h>
int main ()
{
	printf("%% Hel%%lo %%\n");
	return 0;
}
