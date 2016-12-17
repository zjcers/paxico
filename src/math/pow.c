/*
 * src/math/pow.c
 * Copyright 2016 Zane J Cersovsky
 * This file is part of Project Paxico.

 * Project Paxico is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Project Paxico is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with Project Paxico.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Defines pow()
 */
#include <math.h>
#ifdef PLATFORM_X86_64
double pow(double base, double power) {
	double output;
	/*This shim is necessary to avoid spitting out a NaN from the log2 operation
		in the following asm*/
	if (base == 0.0) {
		return 0.0;
	}
	__asm__ volatile (
		"fldl %2\n"
		"fldl %1\n"
		"fyl2x\n"
		"fld %%st(0)\n"
		"frndint\n"
		"fld %%st(0)\n"
		"fxch %%st(2)\n"
		"fsub %%st(2)\n"
		"f2xm1\n"
		"fld1\n"
		"faddp %%st(1)\n"
		"fscale\n"
		"fwait\n"
		"fstpl %0\n"
		: "=m" (output)
		: "m" (base), "m" (power)
		: "st"
	);
	return output;
}
#else
/*Not implemented*/
#endif
