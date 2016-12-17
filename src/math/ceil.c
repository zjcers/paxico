/*
 * src/math/ceil.c
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
