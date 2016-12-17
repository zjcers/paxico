/*
 * src/math/fabs.c
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
 * Defines fabs()
 */
#include <math.h>
#ifdef PLATFORM_X86_64
/*Computes floating point absolute value*/
double fabs(double x) {
	__asm__ volatile (
		"fldl %0\n"
		"fabs\n"
		"fstpl %0\n"
		: "=m" (x)
		: "0" (x)
		: "st"
	);
	return x;
}
#else
double fabs(double x) {
	if (x < 0.0) {
		x *= -1.0;
	}
	return x;
}
#endif
