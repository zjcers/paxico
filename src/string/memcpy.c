/*
 * src/string/memcpy.c
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
 * Defines memcpy()
 */
#include <string.h>
/*
 * Copies n bytes from src to dest
 */
void *memcpy(void *dest, const void *src, size_t n)
{
	void *orig_dest = dest;
	size_t i = 0;
	for (; i < n; i++) {
		*((char*)(dest++)) = *((char*)(src++));
	}
	return orig_dest;
}
