/*
 * src/stdlib/qsort.c
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
 * Defines qsort() as a heap sort
 */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#ifndef PAXICOITEMAT
#define PAXICOITEMAT(base, size, i) (base+(size*i))
#endif
#define PAXICOLEFTCHILD(i) ((2*i)+1)
#define PAXICORIGHTCHILD(i) ((2*i)+2)
#define PAXICO_LAST_PARENT(nitems) (((nitems)-2)/2)
size_t swap(void *a, void *b, size_t size);
static void repairheap(void *base, size_t nitems, size_t size, size_t start, int (*compar)(const void *, const void *))
{
	size_t toswap, child;
	while (PAXICOLEFTCHILD(start) < nitems) {
		child = PAXICOLEFTCHILD(start);
		toswap = start;
		if (compar(PAXICOITEMAT(base, size, start), PAXICOITEMAT(base, size, child)) < 0)
			toswap = child;
		if ((child+1) < nitems)
			if (compar(PAXICOITEMAT(base, size, toswap), PAXICOITEMAT(base, size, (child+1))) < 0)
				toswap = child+1;
		if (toswap == start) {
			return;
		} else {
			swap(PAXICOITEMAT(base, size, start), PAXICOITEMAT(base, size, toswap), size);
			start = toswap;
		}
	}
}
static void heapify(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *))
{
	size_t i = PAXICO_LAST_PARENT(nitems)+1;
	for (; i > 0; i--) {
		repairheap(base, nitems, size, i-1, compar);
	}
}
static void heapsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
{
	size_t i;
	for (i = 1; i < nitems; i++) {
		swap(PAXICOITEMAT(base, size, 0), PAXICOITEMAT(base, size, (nitems-i)), size);
		repairheap(base, nitems-i, size, 0, compar);
	}
}
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
{
	heapify(base, nitems, size, compar);
	heapsort(base, nitems, size, compar);
}
