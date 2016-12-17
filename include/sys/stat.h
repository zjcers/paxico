/*
 * include/sys/stat.h
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
 * Declares macros and functions related to administrative fs tasks
 */
#ifndef _PAXICO_STAT_H
#define _PAXICO_STAT_H
/*Set the branding macro*/
#ifndef _PAXICO_LIBC_
#define _PAXICO_LIBC_
#endif

#include <sys/types.h>

/*Constants for file types*/
#define S_IFMT	0170000
#define S_IFBLK	0060000
#define S_IFCHR	0020000
#define S_IFIFO	0010000
#define S_IFREG	0100000
#define S_IFDIR	0040000
#define S_IFLNK	0120000

/*Constants for file mode bits*/
/*r by owner*/
#define S_IRUSR 00400
/*w by owner*/
#define S_IWUSR 00200
/*x by owner*/
#define S_IXUSR 00100
/*rwx by owner*/
#define S_IRWXU (S_IRUSR|S_IWUSR|S_IXUSR)
/*r with group*/
#define S_IRGRP 00040
/*w with group*/
#define S_IWGRP 00020
/*x with group*/
#define S_IXGRP 00010
/*rwx with group*/
#define S_IRWXG (S_IRGRP|S_IWGRP|S_IXGRP)
/*r with others*/
#define S_IROTH 00004
/*w with others*/
#define S_IWOTH 00002
/*x with others*/
#define S_IXOTH 00001
/*rwx with others*/
#define S_IRWXO (S_IROTH|S_IWOTH|S_IXOTH)
/*set user id*/
#define S_ISUID 04000
/*set group id*/
#define S_ISGID 02000
/*sticky bit*/
#define S_ISVTX 01000

/*Macros for checking file type*/
/*return non-zero if m represents a directory*/
#define S_ISDIR(m) (m & S_IFMT)
/*return non-zero if m represents a character device*/
#define S_ISCHR(m) (m & S_IFCHR)
/*return non-zero if m represents a block device*/
#define S_ISBLK(m) (m & S_IFBLK)
/*return non-zero if m represents a regular file*/
#define S_ISREG(m) (m & S_ISREG)
/*return non-zero if m represents a fifo*/
#define S_ISFIFO(m) (m & S_IFIFO)
/*return non-zero if m represents a symbolic links*/
#define S_ISLNK(m) (m & S_IFLNK)
#endif
/* functions */
mode_t umask(mode_t cmask);
