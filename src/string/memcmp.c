/*
 * src/string/memcmp.c
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
 * Defines memcmp()
 */
#include <stdbool.h>
#include <string.h>
/*
 * Compares n bytes of str1 and str2, byte by byte
 */
int memcmp(const void *str1, const void *str2, size_t n)
{
	int i = 0;
	for (; i < n; i++) {
		if ((*(char*)str1++) != (*(char*)str2++))
			return false;
	}
	return true;
}
