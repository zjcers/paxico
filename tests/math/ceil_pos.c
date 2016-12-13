/*
 * tests/math/ceil_neg.c
 * Copyright 2016 Zane J Cersovsky
 * Tests if ceil() works as expected for x<0.0
 */
#include <math.h>
#include <stdlib.h>
int main()
{
	double x = ceil(2.4);
	if (fabs(x)-3.0 < 0.01)
		return EXIT_SUCCESS;
	return EXIT_FAILURE;
}
