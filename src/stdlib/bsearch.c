/*
 * src/stdlib/bsearch.c
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
 * Defines bsearch()
 */
#include <stdint.h>
#ifndef PAXICOITEMAT
#define PAXICOITEMAT(base, size, i) (base+(size*i))
#endif
void* bsearch(const void* key, const void* base, size_t nitems, size_t size, int (*compar)(const void*, const void*))
{
	int i = nitems/2;
	int step = nitems;
	int cval;
	do {
		step /= 2;
		cval = compar(key, PAXICOITEMAT(base, size, i));
		if (cval == 0) {
			return (void*)PAXICOITEMAT(base, size, i);
		} else if (cval < 0) {
			switch (i) {
				case 0:
					goto bsearch_end;
					break;
				default:
					i = i-step;
					break;
			}
		} else {
			if (i == (nitems-1)) {
				goto bsearch_end;
			} else {
				i = i+step;
			}
		}
	} while (step > 0);

	bsearch_end:
		return NULL;
}
