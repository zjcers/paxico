/*
 * src/math/ceil.c
 * Copyright 2016 Zane J Cersovsky
 * Defines ceil()
 */
#include <stdint.h>
double ceil(double x)
{
	double output;
	uint16_t fpcw;
	__asm__ __volatile__ (
		"fstcw %0\n"
		"fwait\n"
		: "=m" (fpcw)
		:
		:
	);
	uint16_t fpcw_o = fpcw;
	/*set bits 11-10 to 10 for rounding mode*/
	fpcw |= 1 << 11;
	fpcw &= ~(0 << 10);
	__asm__ __volatile__ (
		"fclex\n"
		"fldcw %2\n"
		"fwait\n"
		"fldl %1\n"
		"frndint\n"
		"fwait\n"
		"fstpl %0\n"
		"fldcw %2\n"
		: "=m" (output)
		: "m" (x), "m" (fpcw), "m" (fpcw_o)
		:
	);
	return output;
}
