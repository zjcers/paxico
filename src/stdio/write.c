/*
 * src/stdio/write.c
 * Copyright 2016 Zane J Cersovsky
 * Provides fwrite()
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
