/*
 * src/misc/swap.c
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
 * Defines swap(), a private helper to swap two equally-sized buffers
 */
#include <stdint.h>
size_t swap(void *a, void *b, size_t size)
{
	/*This shim makes sure GCC doesn't do anything stupid (or wicket smaht)*/
	__asm__ __volatile__ (
	""
	:
	: "r" (a), "r" (b)
	: );
	uint8_t tmp;
	for (; size > 0; size--) {
		tmp = *(uint8_t*)a;
		*(uint8_t*)a = *(uint8_t*)b;
		*(uint8_t*)b = tmp;
		a++;
		b++;
	}
	return size;
}
