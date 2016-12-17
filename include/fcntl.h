/*
 * include/fcntl.h
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
 * Declares misc filesystem functions
 */
#ifndef _PAXICO_FCNTL_H
#define _PAXICO_FCNTL_H
/*Set the branding macro*/
#ifndef _PAXICO_LIBC_
#define _PAXICO_LIBC_
#endif
#include <sys/types.h>
#include <bits/fcntl.h>
int open(const char* pathname, int flags, ...);
#define open(pathname, flags) open(pathname, flags, 00660)
#define creat(filename, mode) open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode)
int fcntl(int fd, int cmd, ...);
#endif
