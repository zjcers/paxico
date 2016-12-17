/*
 * src/stdio/write.c
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
 * Defines fwrite()
 */
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#define MIN(a, b) (a < b ? a : b)
#define FREESPACE(s) ((s->bsize)-(s->level))
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
{
	size_t i = 0;
	size_t copied = 0;
	size_t tocopy;
	size_t donecopy;
	for(; i < nmemb; i++) {
		tocopy = size;
		while (tocopy > 0) {
			donecopy = MIN(FREESPACE(stream), tocopy);
			memcpy(stream->buffer, ptr, donecopy);
			ptr += donecopy;
			copied += donecopy;
			tocopy -= donecopy;
			if (tocopy > 0)
				fflush(stream);
		}
	}
	return donecopy;
 }
