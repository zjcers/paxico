/*
 * src/math/log10.c
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
 * Defines log10()
 */
#include <math.h>
#ifdef PLATFORM_X86_64
/*Computes the base-10 log of x*/
double log10(double x) {
	double output;
	__asm__ __volatile__ (
		"fld1\n"
		"fldl %1\n"
		"fyl2x\n"
		"fldl2t\n"
		"fdivrp\n"
		"fstpl %0\n"
		: "=m" (output)
		: "m" (x)
		: "st"
	);
	return output;
}
#else
	/*Not implemented*/
#endif
