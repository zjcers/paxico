/*
 * include/unistd.h
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
 * Declares a bunch of standard system calls
 */
#ifndef _PAXICO_UNISTD_H
#define _PAXICO_UNISTD_H
/*Set the branding macro*/
#ifndef _PAXICO_LIBC_
#define _PAXICO_LIBC_
#endif
#include <stdint.h>
#include <sys/types.h>
#define SEEK_SET	0
#define SEEK_CUR	1
#define SEEK_END	2
/*System calls are defined in plaform directories*/
ssize_t write(int fileno, const char* str, size_t length);
ssize_t read(int fileno, void* outbuf, size_t count);
int close(int fileno);
void _exit(int status);
int brk(void* addr);
void* sbrk(intptr_t incr);
off_t lseek(int fd, off_t offset, int whence);
#endif
