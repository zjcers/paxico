/*
 * tests/stdio/printf_noformat.c
 * Copyright 2016 Zane J Cersovsky
 * Tests to make sure printf() acts normally when format = ""
 */
#include <stdio.h>
int main ()
{
	printf("%% Hel%%lo %%\n");
	return 0;
}
