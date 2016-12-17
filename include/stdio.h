/*
 * include/stdio.h
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
 * Declares stream I/O support
 */
#ifndef _PAXICO_STDIO_H
#define _PAXICO_STDIO_H
/*Set the branding macro*/
#ifndef _PAXICO_LIBC_
#define _PAXICO_LIBC_
#endif
#include <stdint.h>
#include <sys/types.h>
#include <stdbool.h>
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
#define EOF -1001
#define BUFF_NONE 0
#define BUFF_ALL 1
#define BUFF_LINE 2
#define BUFSIZ 512
typedef struct
{
	size_t level;
	size_t bsize;
	off_t pos;
	unsigned int fd;
	mode_t mode;
	short buff_mode;
	char *buffer;
	bool istemp;
} FILE;
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

int puts(const char* str);
int putchar(int str);
int printf(const char *format, ...);
int sprintf(char* buffer, const char* format, ...);
FILE *fdopen(int fd, const char *mode);
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
int fflush(FILE *stream);

#endif
