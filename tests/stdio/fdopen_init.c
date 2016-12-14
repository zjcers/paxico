/*
 * tests/stdio/fdopen_init.c
 * Copyright 2016 Zane J Cersovsky
 * Tests to make sure fdopen() allocated stdin, stdout, and stderr
 */
#include <stdlib.h>
#include <stdio.h>
int main()
{
	if (stdin != NULL)
		if (stderr != NULL)
			if (stdout != NULL)
				return EXIT_SUCCESS;
			else
				return 3;
		else
			return 2;
	else
		return 1;
}
