/*
 * tests/stdlib/bsearch_high.c
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
 * makes sure bsearch() works if the element should be beyond where array ends
 */
#include <stdlib.h>
int compare(const void* a, const void* b)
{
	return (*(int*)a-*(int*)b);
}
int main(int argc, const char** argv)
{
	int arr[] = {0, 1, 2, 3, 4};
	int a = 5;
	int* b = (int*)bsearch(&a, arr, 5, sizeof(int), compare);
	if (b == 0)
		return EXIT_SUCCESS;
	return EXIT_FAILURE;
}