/*
 * tests/misc/swap_simple.c
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
 * Tests swap(), a private helper to swap two equally-sized buffers
 */
#include <stdint.h>
#include <stdlib.h>
size_t swap(void *a, void *b, size_t size);
int main(int argc, const char** argv)
{
	size_t a = 42;
	size_t b = 89;
	swap(&a, &b, sizeof(size_t));
	if (b == 42 && a == 89) {
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}
